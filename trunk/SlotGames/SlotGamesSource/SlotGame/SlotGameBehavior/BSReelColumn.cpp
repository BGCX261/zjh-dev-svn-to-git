#include "BSReelColumn.h"
#include "TimeManager.h"
#include <GTTweener2D.h>

#ifdef GT_DEBUG
#include <GTNew.h>
#endif // GT_DEBUG
#include "..\UI\UIDef.h"
#include "GTGameObjectManager.h"

#define PROPERTY_TAG_SLOTITEM_KEY		CTEXT("SlotItem")
#define TIMER_UPDATE_DELTA_SCALE			10		//every 10ms to update


// This comp function must be static
//************************************
// Method:    SortSlotItemByYPos
// FullName:  SortSlotItemByYPos
// Access:    public static 
// Returns:   bool
// Qualifier: comparator for sort function;
//************************************
static bool SortSlotItemByYPos(SlotItem* lhs, SlotItem* rhs)
{
	if(lhs->GetPosition().y > rhs->GetPosition().y)
		return true;

	return false;
}

GTBEHAVIOUR_IMP(BSReelColumn, GTBehaviour);

BSReelColumn::BSReelColumn()
{
	m_reelRollingDuration = 0;
	m_reelRollingSteps = 0;
	m_bChangeToFinalSymbol = false;

	m_rowCount = 0;
	m_rowDirection = true;
	m_updateDeltaTime = 0;

	m_slotBottomY = 0;
	m_slotTopY = 0;

	m_pWinframeSprite = NULL;
		
	m_columnStatus = Status_Stopped;
	m_oldYPos = 0;

	m_curWinSlotPos = -1;
	m_bPlayingWinAnimation = false;
	m_curWinlineID = -1;

	m_finalSymbolIDQueue.empty();
}


BSReelColumn::~BSReelColumn()
{
	m_finalSymbolIDQueue.empty();
}


// This method is called when GTBehaviour object is created.
int32 BSReelColumn::OnCreate(void)
{
	GTBehaviour::OnCreate();
	
	return 1;
}


// This method is called when GTBehaviour object is initialized.
int32 BSReelColumn::OnInitialize(GTBehaviourInitParam* param)
{
	GTBehaviour::OnInitialize(param);

	if(NULL == param || NULL == param->pParam2)
	{
		return 0;
	}

	return CreateFromPropertyTreeNode((GTTreeNode*)param->pParam2) ? 1 : 0;
}


// This method is called before first OnUpdate
int32 BSReelColumn::OnStart(void)
{
	GTBehaviour::OnStart();

	
	bool res = false;
	GTString errorCode("");

	for(int id = 0; id < m_rowCount; id++)
	{
		GTString reelRowName = PROPERTY_TAG_SLOTITEM_KEY;
		reelRowName.Append(GTString::From(id));// + GTString::FormatFrom(id);
		//reelColumName += GTString::FormatFrom(id);

		//GTGameObject * childGO = m_pGameObject->FindChild("SlotItem0", true);
		GTGameObject * childGO = m_pGameObject->FindChild(reelRowName.ToCharString(), true);
		if(childGO != NULL)
		{
			SlotItem* item = new SlotItem(id, childGO);	
			m_slotItemsList.AddToTail(item);
				

			res = true;

			GTPoint2 pos = item->GetPosition();
			//GTLogManager::SLogFormatComment(" pSlotItem %d , position = %f, %f", id, pos.x, pos.y);

			//get column top and bottom
			if(m_slotTopY < pos.y)
				m_slotTopY = pos.y;	

		}		
		else
		{
			res = false;
			errorCode = reelRowName;
			break;
		}
	}

	//calculate bottomY
	m_rowHeight = abs(m_slotItemsList[0]->GetPosition().y - m_slotItemsList[1]->GetPosition().y);
	float totalHeight = m_rowHeight * m_rowCount ;//abs(m_slotsList[0]->GetGameObjectPosition().y - m_slotsList[m_rowCount - 1]->GetGameObjectPosition().y);
	
	//m_slotTopY -= 65;
	//m_slotTopY -= m_rowHeight/2;	//because sprite's position is center of sprite. 	
	m_slotBottomY = m_slotTopY - totalHeight;


	//sort slotitems
	SortSlotItems();

	GTLogManager::SLogFormatComment("top = %f, bottom = %f", m_slotTopY, m_slotBottomY);
	
	if(!res)
		GTLogManager::SLogFormatError(CTEXT("Error!!! BSSlotsContainer can not find BSReelColumn: %s "), errorCode.ToCharString());

	return 1;
}


// This method is called when GTBehaviour object is updated.
int32 BSReelColumn::OnUpdate(void)
{
	GTBehaviour::OnUpdate();

	//update based on delta time;
	m_updateDeltaTime +=  TimeManager::GetInstance()->GetDeltaTime();
	if( m_updateDeltaTime >= TIMER_UPDATE_DELTA_SCALE )	//m_reelspeed is sec;	
	{
		switch(m_columnStatus)
		{
		case Status_Stopped:
			onTimerStopped();
			break;

		case Status_StartSpin:
			onTimerStartSpin();
			break;

		case Status_Windup:
			onTimerWindupColumn();
			break;

		case Status_Begin_Rolling:
			onTimerRolling(); 
			break;

		case Status_Stop_Rolling:
			onTimerStopRolling();
			break;

		case Status_SlowDownToStop:
			onTimerSlowDownToStop();
			break;

		case Status_ShowWinline:
			onTimeShowWinline();
			break;

		default:
			break;
		}

		m_updateDeltaTime = 0;
	}	
	return 1;
}

void BSReelColumn::onTimerStopped()
{
	if(m_winSlotPosQueue.size() > 0)
	{
		m_columnStatus = Status_ShowWinline;	//show winline;
	}
}

//timer: start spin;
void BSReelColumn::onTimerStartSpin()
{
	//check tickets and initial all final values;
	if(m_finalSymbolIDQueue.size() <= 0)
	{
		GTLogManager::SLogError("don't have symbols. queue is empty, setup ticket first!!");

		m_columnStatus = Status_Stopped;
		return; 
	}
	
	//start to windup
	m_columnStatus = Status_Windup;
	m_updateDeltaTime = 0;	//reset update Delta time;
	m_updateTotalDuration = 0;	//reset update total time;
	//onTimerWindupColumn();
	/*
	//create new tween for Windup Column;
	GTVector2 srcPos(0,0);// = GetGameObjectPosition();
	GTVector2 toPos(0, -m_windupValue.pixel);// = GTVector2(srcPos.x, srcPos.y + m_windupValue.length);
	m_oldYPos = 0;
	m_tween2d.Tween(srcPos, toPos, m_windupValue.duration, TweenInterpolation::GetFunctionByType(TweenInterpolation::TweenType_BackEaseInOut));
	GTLogManager::SLogFormatTrace("Windup  -->  m_tween2d ||  srcPos.y = %f,   toPos.y = %f    duration: %f", srcPos.y, toPos.y,  m_windupValue.duration);
	*/
}

//windup column;
void BSReelColumn::onTimerWindupColumn()
{	
	/*
	m_updateTotalDuration += m_updateDeltaTime;

	if(m_updateTotalDuration <= m_windupValue.duration)
	{
		//do windup column;	
		MoveColumnByTween2D(m_updateDeltaTime, m_tween2d, false);
	}
	else */
	{
		//go to next step and reset value;
		m_columnStatus = Status_Begin_Rolling;
		m_updateDeltaTime = 0;	//reset update Delta time;
		m_updateTotalDuration = 0;	//reset update total time;
	}
	
}

//timer: rolling;
void BSReelColumn::onTimerRolling() 
{	
	/*
	m_updateTotalDuration += m_updateDeltaTime;

	float stopRollingDuration = 5000;

	if(m_updateTotalDuration <= stopRollingDuration)
		MoveColumByTime(m_updateDeltaTime, true);	//move slots
	else  */
	{
		m_columnStatus = Status_Stop_Rolling;
	}

}

//timer stop rolling;
void BSReelColumn::onTimerStopRolling()
{		
	//need slow down and move all slots to next slots	
	m_columnStatus = Status_SlowDownToStop;
	m_updateDeltaTime = 0;	//reset update Delta time;
	m_updateTotalDuration = 0;	//reset update total time;

	//create new tween for slow down;
	// y is length, from 0 to length( m_slowdownValue.pixel )  //must be n * slot_Length
	
	float totalDistance = m_rowHeight * m_reelRollingSteps;	//move steps to final position
	GTVector2 src(0, 0);
	
	GTVector2 to(0, totalDistance);

	m_tween2d.Tween(src, to, m_reelRollingDuration, GTTweenInterpolation::GetFunctionByType(GTTweenInterpolation::TweenType_BackEaseInOut));
	//GTLogManager::SLogFormatTrace("Slowdown  -->  m_tween2d ||  srcPos.y = %f,   toPos.y = %f    duration: %f", srcPos.y, toPos.y,  m_windupValue.duration);
}

// Timer: slow down rolling to stop
void BSReelColumn::onTimerSlowDownToStop()
{
	int updateDeltaTime = m_reelRollingDuration - m_updateTotalDuration;
	m_updateTotalDuration += m_updateDeltaTime;

	if(m_updateTotalDuration <= m_reelRollingDuration)
	{
		MoveColumnByTween2D(m_updateDeltaTime, m_tween2d, true, true);
	}
	else
	{
		if((updateDeltaTime > 0) && (updateDeltaTime < m_updateDeltaTime))
			MoveColumnByTween2D(updateDeltaTime, m_tween2d, true, true);

		//sort slotitems
		SortSlotItems();

		if(m_winSlotPosQueue.size() > 0)
		{
			m_columnStatus = Status_ShowWinline;	//show winline;
		}
		else
		{
			//totally stopped.	
			m_columnStatus = Status_Stopped;		//do not show winline;
		}		
		m_updateDeltaTime = 0;	//reset update Delta time;
		m_updateTotalDuration = 0;	//reset update total time;
		m_oldYPos = 0;
	}
}

// Timer: show winline
void BSReelColumn::onTimeShowWinline()
{	
	m_updateTotalDuration += m_updateDeltaTime;
	
	if(!m_bPlayingWinAnimation)
	{
		//case1: in the begining, no one is playing, then pop one and play
		if(m_winSlotPosQueue.size() > 0)
		{
			GTVector2 winlineValue = m_winSlotPosQueue.front(); 
			m_winSlotPosQueue.pop();

			m_curWinlineID = (int)winlineValue.x;
			m_curWinSlotPos = (int)winlineValue.y;

			//play a new one win slot;
			if(!m_slotItemsList[m_curWinSlotPos]->IsAnimationPlaying())
			{
				m_slotItemsList[m_curWinSlotPos]->PlayAnimation("win", GSpriteAnimation::PlayMode_Loop);
				//GTLogManager::SLogFormatComment("slot[%d] ( &%d ) play ---> animation win", m_curWinSlotPos, m_slotItemsList[m_curWinSlotPos]);

				m_slotItemsList[m_curWinSlotPos]->SetZOrder(UI_ZOrder::WIN_SLOT);
				ShowWinFrame(true);
				m_bPlayingWinAnimation = true;
				m_updateTotalDuration = 0;
			}
		}
		//case2: finish to play all winlines, then set the status and exit this process;
		else
		{
			//totally stopped.
			m_columnStatus = Status_Stopped;
			m_updateDeltaTime = 0;	//reset update Delta time;
			m_updateTotalDuration = 0;	//reset update total time;
			m_bPlayingWinAnimation = false;
			m_curWinSlotPos = -1;
			m_curWinlineID = -1;
		}
		
	}
	//case3: one winline slot is playing, 
	else if (m_bPlayingWinAnimation)
	{
		//if show winline time is up(per winline), 
		if((m_updateTotalDuration >= m_timeToShowPerWinline))
		{
			//then stop to play and ready to play next one;
			if(m_slotItemsList[m_curWinSlotPos]->IsAnimationPlaying())
			{
				m_slotItemsList[m_curWinSlotPos]->StopAnimation();
				//GTLogManager::SLogFormatComment("slot[%d] ( &%d ) stop ---> animation win", m_curWinSlotPos, m_slotItemsList[m_curWinSlotPos]);
				
				m_slotItemsList[m_curWinSlotPos]->SetZOrder(UI_ZOrder::NORMAL_SLOT);
				ShowWinFrame(false);
				m_bPlayingWinAnimation = false;
				m_updateTotalDuration = 0;
				m_curWinSlotPos = -1;
			}
		}
	}
}

// This method is called when GTBehaviour object is destroyed.
int32 BSReelColumn::OnDestroy(void)
{
	GTBehaviour::OnDestroy();

	// Delete slot item object created before
	for(int32 i=0; i<m_slotItemsList.Count(); i++)
	{
		delete m_slotItemsList[i];
	}

	/*
	// Fixed by Carmack:
	// m_pWinframeSprite cannot be released here because it's obtained by
	// calling GTGameObject::GetBehaviour.
	if(m_pWinframeSprite)
		m_pWinframeSprite->Release();
		*/

	return 1;
}


// Create the sprite from the property tree node
bool BSReelColumn::CreateFromPropertyTreeNode(GTTreeNode *pTreeNode)
{
	if(NULL == pTreeNode)
	{
		return false;
	}
	
	//row count
	GTTreeNode* pRowCountNode = pTreeNode->GetChild(CTEXT("rowCount"));
	if(NULL == pRowCountNode)
	{
		return false;
	}
	m_rowCount = pRowCountNode->GetValue().ToInt();
		
	//row direction
	GTTreeNode* pRowDirection = pTreeNode->GetChild(CTEXT("rowDirection"));
	if(NULL == pRowDirection)
	{
		return false;
	}
	m_rowDirection = pRowDirection->GetValue().ToBool();
	
	//reel rolling duration ;
	GTTreeNode* pReelRollingDurationNode = pTreeNode->GetChild(CTEXT("reelRollingDuration"));
	if(NULL == pReelRollingDurationNode)
	{
		return false;
	}
	m_reelRollingDuration = pReelRollingDurationNode->GetValue().ToInt() * 1000;

	//reel rolling steps ;
	GTTreeNode* pReelRollingStepsNode = pTreeNode->GetChild(CTEXT("reelRollingSteps"));
	if(NULL == pReelRollingStepsNode)
	{
		return false;
	}
	m_reelRollingSteps = pReelRollingStepsNode->GetValue().ToInt();
	if(m_reelRollingSteps < m_rowCount)
	{
		GTLogManager::SLogFormatError("Error!!! row count = %, reel rolling steps = %d, it must be larger than row count", m_rowCount, m_reelRollingSteps);
		assert(m_reelRollingSteps < m_rowCount);
	}	

	//winframe 
	GTTreeNode* pWinframeNode = pTreeNode->GetChild(CTEXT("Winframe"));
	if(NULL == pWinframeNode)
	{
		return false;
	}
	GTString winframePath = pWinframeNode->GetValue();
	GTGameObject* pGameObject1 = GTGameObjectManager::Inst()->CreateGameObject(NULL, CTEXT("winframeSprite"), winframePath);
	m_pWinframeSprite = pGameObject1->GetBehaviour<BSSprite>();
	if(m_pWinframeSprite == NULL)
	{
		GTLogManager::SLogFormatError("Error!!! Can not find winframe!");
		assert(m_pWinframeSprite);
	}	
	m_pWinframeSprite->SetZOrder(UI_ZOrder::WINFRAME);
	ShowWinFrame(false);
	
	return true;
}

//************************************
// Method:    setTicket
// FullName:  BSReelColumn::getTicket
// Access:    protected 
// Returns:   void
// Qualifier: set tickets and parser all values;
//************************************
void BSReelColumn::SetTicket(GTArray<int> ticket)
{
	//Todo: parser all values;



// 	if(m_finalSymbolIDQueue.size() > 0)
// 	{
// 		GTLogManager::SLogFormatComment("-----> setTicket -->before  -> m_finalSymbolIDQueue =  %d ! ", m_finalSymbolIDQueue.size());
// 
// 		GTString res;
// 		for(int i = 0; i < m_slotItemsList.Count(); i++)
// 		{
// 			SlotItem* pSlotItem = m_slotItemsList[i];
// 			int symbolID = pSlotItem->GetSymbolID();
// 			res.Append(GTString::ToString(symbolID));
// 			res.Append(GTString(", "));
// 		}
// 
// 		GTLogManager::SLogFormatCommentGT("-----> setTicket -->symbol : %s ! ", res.ToCharString());
// 
// 		GTString ticketRes = ticket.ToString();
// 		GTLogManager::SLogFormatComment("-----> setTicket -->ticketRes : %s ! ", ticketRes.ToCharString());		
//	}
	

	//everytime, set new ticket, we dump all old final slots icon;
	std::queue<int> empty;
	std::swap(m_finalSymbolIDQueue, empty);

	//Make final slots icon id	
	for(int i =  ticket.Length() - 1; i >= 0; i--)
	{
		m_finalSymbolIDQueue.push(ticket[i]);
	}
}

//************************************
// Method:    ChangeSlotItem
// FullName:  BSReelColumn::ChangeSlotItem
// Access:    protected 
// Returns:   bool
// Qualifier: change slot item's symbol; Noraml: to random symbol. Final: change to symbols(based on ticket)
// Parameter: int slotItemID   : slotItem ID
//************************************
bool BSReelColumn::ChangeSymbol(int slotItemID)
{
	if(m_finalSymbolIDQueue.size() <= 0)
	{
		//GTLogManager::SLogWarning("don't have symbols. queue is empty. Do not need change symbol!!");
		return false;
	}

	SlotItem* pSlotItem = m_slotItemsList[slotItemID];

	if(pSlotItem == NULL)
	{
		GTLogManager::SLogError("Error!! slotItme is NULL!");
		assert(pSlotItem);
	}

	int symbolID;
	if(!m_bChangeToFinalSymbol)	
	{
		int symbolCount = BSIconLoader::GetIconsCount();
		//normal time: change slotItem to random symbol
		symbolID = rand() % symbolCount;
	}
	else
	{
		//final steps for stop, make sure all slots must be changed to final ticket symbol;
		symbolID = m_finalSymbolIDQueue.front();
		m_finalSymbolIDQueue.pop();

		//GTLogManager::SLogFormatComment("Final : slot[%d]  symbol -->  %d", slotItemID, symbolID);
	}

	return pSlotItem->ChangeSymbol(symbolID);
}

//************************************
// Method:    BackToStartPosition
// FullName:  BSReelColumn::BackToStartPosition
// Access:    protected 
// Returns:   float
// Qualifier: based on current Ypos, get new YPos like reel (top->bottom, or bottom->top)
// Parameter: float srcY   :
//************************************
bool BSReelColumn::BackToStartPosition(float srcY, float& destY)
{
	bool res = false;
	//need get new position which are always responsed to be on the container;
	destY = srcY;

	float ignoreMargin = m_rowHeight / 4;	//ignore for up&down in the border;

	//if new position is higher than top, then roll to bottom 
	while(destY > (m_slotTopY + ignoreMargin) )
	{
		float scaleY = destY - m_slotTopY;
		destY = m_slotBottomY + scaleY;
		res = true;
	}

	//if new position is lower than bottom, then roll to top 
	while(destY < (m_slotBottomY - ignoreMargin) )
	{
		float scaleY= destY - m_slotBottomY;
		destY = m_slotTopY + scaleY;
		res = true;
	}	
	return res;
}

//************************************
// Method:    MoveColumnByTween2D
// FullName:  BSReelColumn::MoveColumnByTween2D
// Access:    protected 
// Returns:   void
// Qualifier: Using Tween2d to move column. Moreover, based on current Ypos, get new YPos like reel (top->bottom, or bottom->top)
// Parameter: const float deltaTime   :
// Parameter: Tweener2D & tween2D   : tween2d;
// Parameter: bool bReelModel   :		reel model;
// Parameter: bool bChangeSymbolWhenBackToStartPos   :		change symbol when slot is back to startPos(like reel model, move from bottom to top
//************************************
void BSReelColumn::MoveColumnByTween2D(const float deltaTime, GTTweener2D& tween2D, bool bReelModel, bool bChangeSymbolWhenBackToStartPos)
{
	//do windup column;	
	float curYPos = tween2D.Update(deltaTime).y;
	float deltaYPos = curYPos - m_oldYPos;		//float targetYPos = m_windupValue.speed * m_updateDeltaTime * (-1);

	//GTLogManager::SLogFormatTrace("MoveColumnByTweenFunction ||  m_updateTotalTime %f ms        deltaTime= %f ----- m_oldYPos = %f,   curYPos = %f    deltaYPos: %f", m_updateTotalDuration, deltaTime, m_oldYPos, curYPos, deltaYPos);

	if(abs(deltaYPos) >= 1)	//if need move more than 1 pixel, we move ;
	{
		int posForFinalSymbols = (m_reelRollingSteps - (m_rowCount -1)) * m_rowHeight;	//position where begin to change final all symbols for final stop;		

		if(m_oldYPos > posForFinalSymbols)	//the last reel position, need set all solts to final symbol for stop
		{
			m_bChangeToFinalSymbol = true;
			//GTLogManager::SLogFormatTrace("final:  total = %d   ||  finalSymbol = %d  ||   curPos = %d ", m_rowCount* m_rowCount, posForFinalSymbols,  m_oldYPos); 
		}
		else
			m_bChangeToFinalSymbol = false;

		MoveColumByDeltaPos(deltaYPos, bReelModel, bChangeSymbolWhenBackToStartPos);
		m_oldYPos = curYPos;
	}
}

/*
//based on time, to move slots to different position;
//bStayOnContainer: make sure whether this movement to stay on the container, or not
void BSReelColumn::MoveColumByTime(float deltaTime, bool bReelModel)
{
	float deltaY = m_reelSpeed * deltaTime;	//delta Y position should be moved
	MoveColumByDeltaPos(deltaY, bReelModel);
}
*/

//************************************
// Method:    MoveColumByDeltaPos
// FullName:  BSReelColumn::MoveColumByDeltaPos
// Access:    protected 
// Returns:   void
// Qualifier: based on delta y Pos, to move slots to different position; Moreover, based on current Ypos, get new YPos like reel (top->bottom, or bottom->top)
// Parameter: float yDeltaPos   :reel model;
// Parameter: bool bChangeSymbolWhenBackToStartPos   :		change symbol when slot is back to startPos(like reel model, move from bottom to top
//************************************
void BSReelColumn::MoveColumByDeltaPos(float yDeltaPos, bool bReelModel,  bool bChangeSymbolWhenBackToStartPos)
{
	float deltaY(0);
	if(m_rowDirection)
		deltaY = 0 - yDeltaPos ;	//up to down
	else
		deltaY = yDeltaPos;			//down to up

	if(!bReelModel)
	{
		//normal:  just move position;

		for(int i = 0; i < m_rowCount; i++)
		{
			GTPoint2 pos = m_slotItemsList[i]->GetPosition();
			GTPoint2 newPos = GTPoint2(pos.x, pos.y + deltaY);

			m_slotItemsList[i]->SetPosition(newPos);
			//GTLogManager::SLogFormatComment("move sprite(%d)   %f  -> %f", i, pos.y, newPos.y);
		}
	}
	else
	{
		//Reel: make column like reel , slots move to bottom, then go back top;
		for(int i = 0; i < m_rowCount; i++)
		{
			GTPoint2 pos = m_slotItemsList[i]->GetPosition();
			float newY = pos.y + deltaY;
			bool bBackToStart  = BackToStartPosition(pos.y + deltaY, newY);

			GTPoint2 newPos = GTPoint2(pos.x, newY);
			m_slotItemsList[i]->SetPosition(newPos);

			//when slot is back to startPos
			if(bChangeSymbolWhenBackToStartPos && bBackToStart)
			{
				//GTLogManager::SLogFormatComment("ChangeSymbol(%d)   %f  -> %f", i, pos.y + deltaY, newPos.y);
				ChangeSymbol(i);	//chang slotItem symbol when it is on the start Pos;
			}
			//GTLogManager::SLogFormatComment("move sprite(%d)   %f  -> %f", i, pos.y, newPos.y);
		}
	}	
}

//************************************
// Method:    MoveColumToPos
// FullName:  BSReelColumn::MoveColumToPos
// Access:    protected 
// Returns:   void
// Qualifier: based on y Pos, to move slots to different position; Moreover, based on current Ypos, get new YPos like reel (top->bottom, or bottom->top)
// Parameter: float yDeltaPos   :reel model;
// Parameter: bool bChangeSymbolWhenBackToStartPos   :		change symbol when slot is back to startPos(like reel model, move from bottom to top
//************************************
void BSReelColumn::MoveColumToPos(float yNewPos, bool bReelModel,  bool bChangeSymbolWhenBackToStartPos)
{
	//normal:  just move position;
	if(!bReelModel)
	{
		for(int i = 0; i < m_rowCount; i++)
		{
			GTPoint2 pos = m_slotItemsList[i]->GetPosition();
			GTPoint2 newPos = GTPoint2(pos.x, yNewPos);
			m_slotItemsList[i]->SetPosition(newPos);
		}		
	}
	else
	{
		//Reel: make column like reel , slots move to bottom, then go back top;
		for(int i = 0; i < m_rowCount; i++)
		{
			GTPoint2 pos = m_slotItemsList[i]->GetPosition();
			float newY = yNewPos;
			bool bBackToStart  = BackToStartPosition(yNewPos, newY);

			GTPoint2 newPos = GTPoint2(pos.x, newY);
			m_slotItemsList[i]->SetPosition(newPos);


			//when slot is back to startPos
			if(bChangeSymbolWhenBackToStartPos && bBackToStart)
			{
				ChangeSymbol(i);	//chang slotItem symbol when it is on the start Pos;
			}
			//GTLogManager::SLogFormatComment("move sprite(%d)   %f  -> %f", i, pos.y, newPos.y);
		}
	}
	
}

//get StopRolling flag;
BSReelColumn::ColumnStatus BSReelColumn::GetStatus()
{
	return m_columnStatus;
}

//stop rolling slot items
void BSReelColumn::StopSpin()
{
	//set up start spin flag, then update the whole process;
	m_columnStatus = Status_Stop_Rolling;
}

//start rolling slot items
void BSReelColumn::StartSpin()
{
	//set up start spin flag, then update the whole process;
	m_columnStatus = Status_StartSpin;
}

//show winline;
void BSReelColumn::ShowWinline(int winlineID, int slotPos, const int timeToShowPerWinline)
{
	//set up ShowWinline flag, then update the whole process;
	//m_columnStatus = Status_ShowWinline;
	//m_curWinlineID = winlineID;
	//m_bShowWinline = true;
	GTVector2 winlineValue = GTVector2(winlineID, slotPos);
	m_winSlotPosQueue.push(winlineValue);
	m_timeToShowPerWinline = timeToShowPerWinline;
}

//show winframe animation
void BSReelColumn::ShowWinFrame(bool visibility)
{	
	if(m_pWinframeSprite == NULL)
		return;

	m_pWinframeSprite->SetVisible(visibility);

	if(visibility)
	{
		//show winframe animation;
		GTPoint2 pos = m_slotItemsList[m_curWinSlotPos]->GetPosition();
		m_pWinframeSprite->SetGameObjectPosition(pos);
		m_pWinframeSprite->PlayAnimationByIndex(0, GSpriteAnimation::PlayMode_Loop);
	}
	else
		m_pWinframeSprite->StopAnimation();
}

//sort slotitems;
void BSReelColumn::SortSlotItems()
{
	PrintSlotItemList();	

	//m_slotItemsList.Sort();
	m_slotItemsList.Sort(SortSlotItemByYPos);

	//GTLogManager::SLogComment("Sort--------------->");
	PrintSlotItemList();

}

//************************************
// Method:    PrintSlotItemList
// FullName:  BSReelColumn::PrintSlotItemList
// Access:    protected 
// Returns:   void
// Qualifier: Print slotItem list;
//************************************
void BSReelColumn::PrintSlotItemList()
{
// 	for(int i = 0; i < m_slotItemsList.Count(); i++)
// 	{
// 		GTLogManager::SLogFormatTrace("slot[%d] ( &%d ) =  %f , %f", i, m_slotItemsList[i], m_slotItemsList[i]->GetPosition().x, m_slotItemsList[i]->GetPosition().y);
// 	}	
}