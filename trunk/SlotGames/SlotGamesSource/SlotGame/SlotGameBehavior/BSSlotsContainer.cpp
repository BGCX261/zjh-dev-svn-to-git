
#include "BSSlotsContainer.h"
#include "GTBehaviour.h"
#include "GTGameObject.h"
#include "GTLog\GTLogManager.h"
#include "GTGameObjectManager.h"

#ifdef GT_DEBUG
#include <GTNew.h>
#endif // GT_DEBUG
#include "BSRespin.h"
#include <GTGameObjectManager.h>
#include "GTUtil.h"
#include "TimeManager.h"
#include "BSWinlineLoader.h"
#include <GameObjectCreation.h>
#include "..\UI\UIDef.h"
#include "..\UI\UIInfoPanelManager.h"
#include "..\SlotGameManager.h"


#define FONT_NAME						CTEXT("SlotGame/fonts/BitmapFontBlue.fnt")

#define PROPERTY_TAG_ICONLOADER				CTEXT("IconLoader")
#define PROPERTY_TAG_RESPIN_GAMEOBJECT				CTEXT("respinGameObject")
#define PROPERTY_TAG_REELCOLUMN_COUNT	CTEXT("ReelColumnCount")
#define PROPERTY_TAG_REELCOLUMN_KEY		CTEXT("ReelColumn")


GTBEHAVIOUR_IMP(BSSlotsContainer, GTBehaviour);

BSSlotsContainer::BSSlotsContainer()
{
	m_status = Status_NONE;
	m_reelColumnCount = 0;

	m_pTicketGenerator = NULL;

	m_needRespinProcess = false;
	m_lockReelsDict.Clear();

	m_isShowingWinline = false;
	m_pWinTextLabel = NULL;
	m_curWinlineIDForWinTextToshow = -1;

	m_delayDuration = 0;

	m_debugTestTicket = 0;
}

BSSlotsContainer::~BSSlotsContainer()
{
	m_reelColumns.Clear();

	if(m_pTicketGenerator)
		delete m_pTicketGenerator;

	ReleaseWinlineReelSlotsDict();
	ReleaseRespinReelsDict();

	if(m_pWinTextLabel)
	{
		m_pWinTextLabel->Release();
		m_pWinTextLabel = NULL;
	}
}

//clean winline reel slots dictionary;
void BSSlotsContainer::ReleaseWinlineReelSlotsDict() 
{
	m_curWinlineIDForWinTextToshow = -1;
	for(GTDictionary<int, GTArray<GTVector2>* >::ObjectTypeIterator it = m_winlineReelSlotsDict.Begin(); it != m_winlineReelSlotsDict.End(); it++)
	{
		GTArray<GTVector2>* pValue = it->second;
		if(pValue != NULL)
			delete pValue;
	}
	m_winlineReelSlotsDict.Clear();
}

// This method is called when GTBehaviour object is created.
int32 BSSlotsContainer::OnCreate(void)
{
	GTBehaviour::OnCreate();

	return 1;
}


// This method is called when GTBehaviour object is initialized.
int32 BSSlotsContainer::OnInitialize(GTBehaviourInitParam* param)
{
	GTBehaviour::OnInitialize(param);

	if(NULL == param || NULL == param->pParam2)
	{
		return 0;
	}

	return CreateFromPropertyTreeNode((GTTreeNode*)param->pParam2) ? 1 : 0;
}


// This method is called before first OnUpdate
int32 BSSlotsContainer::OnStart(void)
{
	GTBehaviour::OnStart();
	
	bool res = false;
	GTString errorCode("");

	for(int id = 0; id < m_reelColumnCount; id++)
	{
		GTString reelColumName = PROPERTY_TAG_REELCOLUMN_KEY;
		reelColumName.Append(GTString::From(id));// + GTString::FormatFrom(id);
		//reelColumName += GTString::FormatFrom(id);

		GTGameObject * childGO = m_pGameObject->FindChild(reelColumName.ToCharString(), true);
		if(childGO != NULL)
		{			
			BSReelColumn* reelColum = dynamic_cast<BSReelColumn* >(childGO->GetComponent("BSReelColumn"));
			if(reelColum)
			{
				res = true;
				m_reelColumns.AddToTail(reelColum);
				//m_reelColumnsStatus.AddToTail(reelColum->GetStatus());
			}
			else
			{
				res = false;
				errorCode = reelColumName;
				break;
			}
		}		
		else
		{
			res = false;
			errorCode = reelColumName;
			break;
		}
	}

	if(!res)
		GTLogManager::SLogFormatError(CTEXT("Error!!! BSSlotsContainer can not find BSReelColumn: %s "), errorCode.ToCharString());
	
	return 1;
}

void BSSlotsContainer::SetDelay(int sec)
{
	m_delayDuration = sec * 1000;
}

// This method is called when GTBehaviour object is updated.
int32 BSSlotsContainer::OnUpdate(void)
{
	GTBehaviour::OnUpdate();

	//if have delay duration, then do nothing and delay;
	if(m_delayDuration > 0)		
	{
		m_delayDuration -= TimeManager::GetInstance()->GetDeltaTime();
		return 1;
	}
	else
		m_delayDuration = 0;

	if (m_pTicketGenerator == NULL)
		return 1;

	bool allReelStopped = AreAllReelsStopped();
	

	//---------------winline part--------------------//
	CheckShowWinline();	//check show winline
	if(m_isShowingWinline)	//check finish to show winline 
	{
		//show winline sprite;
		if( m_reelColumns[0]->m_bPlayingWinAnimation)
		{
			int winlineID = m_reelColumns[0]->m_curWinlineID;
			ShowWinlineSprite(winlineID, true);

			if(m_curWinlineIDForWinTextToshow != winlineID)		
			{
				GTLogManager::SLogFormatComment("---> show winline prize in winline[%d]", winlineID );
				ShowWinPrize(winlineID);	//show Winprize;
			}
		}

		if(allReelStopped)
		{
			//finished to play winline;
			OnFinishShowWinline();
		}
	}
	//----------------------------------------------//

	//step2: if need, do respin process after all reels spin
	if(m_needRespinProcess)
	{
		if(allReelStopped && (m_lockReelsDict.Count() <= 0))
		{
			m_status = Status_Spin_End;
			//step2.1: check respin and do respin process if necessary
			StartRespinProcess();
		}
		else if(m_lockReelsDict.Count() > 0)
		{
			if(allReelStopped)
			{
				m_status = Status_Respin_ReelStop;

				//step2.2: check bonus again after respin stop, if get anyone more , freespin;
				bool hasNewLockReels = CheckBonusSymbolsAndLock(true);		//in this time, some reels had been lock;
				m_status = Status_Respin_NewLock;

				if(hasNewLockReels)	//no bonus symbol, no need respin!
				{
				}
			}
		}

		if(m_status == Status_Respin_NewLock)
		{
			int finishedLockCount = 0;
			//step2.3: check new lock reel had been finished animation;
			for(GTDictionary<int, GTGameObject* >::ObjectTypeIterator it = m_lockReelsDict.Begin(); it != m_lockReelsDict.End(); it++)
			{
				//set respin to there and play animation
				BSRespin* pRespin = (BSRespin*) it->second->GetBehaviour("BSRespin");
				if(pRespin) 
				{
					if(pRespin->GetStatus() == BSRespin::Status_Lock_Highligh)
						++finishedLockCount;
				}
			}
			
			if(finishedLockCount == m_lockReelsDict.Count())	//all locked reel had been finished lock animation;
			{
				//step2.4:  1st showwinline  for respin;
				//ShowWinline(0, 4000);
				SetupAllWinlines(4000);

				if(allReelStopped)
				{
					//step2.5: all reels have been stopped (finished show winline or other actions);
					FinishRespinProcess();
				}				
			}
		}
	}
	else if(m_status == Status_Respin_Unlock)
	{
		if(m_lockReelsDict.Count() > 0)
		{
			ReleaseRespinReelsDict();
		}

		if(m_lockReelsDict.Count() <= 0)
			m_status = Status_Respin_End;
		else
			m_status= Status_Respin_Unlock;
	}

	//step3: check freespin;
	if(m_status == Status_Respin_End)
	{
		//step3.1  start free spin
		StartFreeSpinProcess();
	}

	//step4: check ready for freespin
	if(m_status == Status_FreeSpin_Start)
	{
		if( (allReelStopped) && (m_freespin.m_freespinCount > 0))	//is ready for a freespin
		{
			//do a freespin process;	
			GTLogManager::SLogFormatComment("Freespin total %d --> now, free respin", m_freespin.m_freespinCount);
			
			SetDelay(8);	//set 5 secs delay
			m_freespin.CloseCongrationMsg();	//close congration msg;

			(m_freespin.m_freespinCount)--;
			StartSpinProcess();
		}
	}

	//step5: finished freespin, and set to NONE
	if(m_status == Status_FreeSpin_End)
	{
		//m_status = Status_FreeSpin_End;
		GTLogManager::SLogFormatComment("Finish Freespin! --> set status to nono");
	}
	
	//GTLogManager::SLogFormatComment("--- m_stauts = %d --", m_status);
	return 1;
}

//release respin reels dictionary;
void BSSlotsContainer::ReleaseRespinReelsDict()
{
	if(m_pTicketGenerator == NULL)
		return;
	
	if(m_lockReelsDict.Count() > 0)
	{
		//when finish to play unlock animation, then begin to remove all respin behavior;
		GTList<int> removeList;
		for(GTDictionary<int, GTGameObject* >::ObjectTypeIterator it = m_lockReelsDict.Begin(); it != m_lockReelsDict.End(); it++ )
		{
			if(it->second == NULL)
				continue;

			BSRespin* pRespin = (BSRespin*) it->second->GetBehaviour("BSRespin");

			//check status, if respin reel had been finished to play unlock animation, then push to remove list;
			if((pRespin) && (pRespin->GetStatus() == BSRespin::Status_None))
			{
				GTLogManager::SLogFormatTrace(" Lock reel %d : had finished unlock animation! ready to delete respin behavior", it->first);
				removeList.AddToHead(it->first);
			}
			else
			{
				//GTLogManager::SLogFormatWarning(" Lock reel %d : status = %d. it had not ready finished unlock animation! !!", it->first, pRespin->GetStatus());
			}
		}

		//remove all respin behavior;
		for(int i= 0; i < removeList.Count(); i++)
		{
			int removeID = removeList[i];

			GTGameObject* pGO = NULL; 
			m_lockReelsDict.GetValueByKey(removeID, pGO);

			if(pGO != NULL)
			{
				pGO->Release();
			}

			m_lockReelsDict.Remove(removeID);
		}
	}
}


// This method is called when GTBehaviour object is destroyed.
int32 BSSlotsContainer::OnDestroy(void)
{
	ReleaseRespinReelsDict();

	GTBehaviour::OnDestroy();
	return 1;
}

// Create the sprite from the property tree node
bool BSSlotsContainer::CreateFromPropertyTreeNode(GTTreeNode *pTreeNode)
{
	if(NULL == pTreeNode)
	{
		return false;
	}

	GTTreeNode* pReelcolumnCountNode = pTreeNode->GetChild(PROPERTY_TAG_REELCOLUMN_COUNT);
	if(NULL == pReelcolumnCountNode)
	{
		return false;
	}
	m_reelColumnCount = pReelcolumnCountNode->GetValue().ToInt();

	return true;
}

void BSSlotsContainer::Test()
{
	if(Status_NONE == m_status)
	{
		UIInfoPanelManager::Inst()->ResetWinLabel();
		StartSpinProcess();
	}
	/*
	float startRollingTimeScale = 3000;
	float endRollingTimeScale = 6000;
	float deltaTimegap = 300;
	float totalEndTime = 18000;
	
	while()
	{
		m_test_updateDeltaTime +=  TimeManager::GetInstance()->GetDeltaTime();
		if((m_test_updateDeltaTime > startRollingTimeScale) && (m_test_updateDeltaTime < endRollingTimeScale))
		{

			//begin to rolling;
			for (int i = 0; i < m_reelColumnCount; i++)
			{
				BSReelColumn::ColumnStatus status = m_reelColumns[i]->GetColumnStatus();
				if(status == BSReelColumn::Status_Stopped)
				{
					int deltaStartTime = i * deltaTimegap + startRollingTimeScale;
					if(m_test_updateDeltaTime > deltaStartTime)
						m_reelColumns[i]->StartSpin();
				}			
			}
		}
		else if((m_test_updateDeltaTime > endRollingTimeScale) && (m_test_updateDeltaTime < totalEndTime))
		{
			stop rolling;
			for (int i = 0; i < m_reelColumnCount; i++)
			{
				BSReelColumn::ColumnStatus status = m_reelColumns[i]->GetColumnStatus();
				if(status == BSReelColumn::Status_Begin_Rolling)
				{
					int delatEndTime = i * deltaTimegap + endRollingTimeScale;
					if(m_test_updateDeltaTime > delatEndTime)
						m_reelColumns[i]->StopSpin();
				}			
			}		

		}
		else if(m_test_updateDeltaTime >= totalEndTime)
			m_test_updateDeltaTime = 0;
	}
	*/
}

//check all reels status;
GTArray<BSReelColumn::ColumnStatus> BSSlotsContainer::CheckAllReelsStatus()
{
	GTArray<BSReelColumn::ColumnStatus> reelColumnsStatus;
	for(int i = 0; i < m_reelColumnCount; i++)
	{
		BSReelColumn::ColumnStatus status = m_reelColumns[i]->GetStatus();
		reelColumnsStatus.Add(status);
	}
	return reelColumnsStatus;
}

//check whether is ready to spin
bool BSSlotsContainer::AreAllReelsStopped()
{
	for(int i = 0; i < m_reelColumnCount; i++)
	{
		BSReelColumn::ColumnStatus status = m_reelColumns[i]->GetStatus();
		if(status != BSReelColumn::Status_Stopped)
			return false;
	}

	return true;
}

//get current slots symbols;
GTArray<int> * BSSlotsContainer::GetCurrentSlotsSymbol()
{
	return &m_slotsSymbols;
}

//************************************
// Method:    StartSpin
// FullName:  BSSlotsContainer::StartSpinProcess
// Access:    public 
// Returns:   void
// Qualifier: start spin process
//************************************
void BSSlotsContainer::StartSpinProcess()
{
	//check all reels status, make sure all reels had been stopped
	if(!AreAllReelsStopped())
	{		
		GTLogManager::SLogWarning("One or some reels had not been stopped!! Try later");
		return;
	}

	//initializaton;
	m_status = Status_StartProcess;
	ReleaseWinlineReelSlotsDict();
	ReleaseRespinReelsDict();

	//step1: create new ticket generator;
	//then, create slot arrays
	if(m_pTicketGenerator)
	{
		delete m_pTicketGenerator;
		m_pTicketGenerator = NULL;
	}
	m_pTicketGenerator = new TicketGenerator(m_reelColumns.Count(), m_debugTestTicket++);//test to get data

	//Way 1:  use data to build ticket;	
	BuildTicket(m_pTicketGenerator->GetSlotSymbols());	//create ticket for all reels;
	//Way 2:  use string to build ticket
	//GTString simpleTicketStr = m_pTicketGenerator->CreateSimpleTicketString()；
	//BuildTicket(simpleTicketStr);	//based on ticket to build ;

	int totalWin = m_pTicketGenerator->GetTotalWin();	//get total win in this process;
	
	if(totalWin > 0)
	{
		//step2: get reel winslots for winlines;
		m_pFinalWinlineRes = m_pTicketGenerator->GetNormalFinalWinRes();
		GetReelWinSlotsForWinlines(m_pFinalWinlineRes);

		//step3: 1st showwinline 
		//ShowWinline(0, 5000);
		SetupAllWinlines(5000);

		m_needRespinProcess = true;
	}
	else
		m_needRespinProcess = false;
	
	//final step: physical start spin all reels and do all process(like show winline, lock, respin);
	SpinAllReels();
}

//physical spin all reels;
void BSSlotsContainer::SpinAllReels()
{
	if(m_freespin.m_freespinCount > 0)
		m_status = Status_FreeSpin_Start;
	else
		m_status = Status_Spin_Start;

	for (int i = 0; i < m_reelColumnCount; i++)
	{
		m_reelColumns[i]->StartSpin();
	}
}


//************************************
// Method:    CreateTicket
// FullName:  BSSlotsContainer::BuildTicket
// Access:    public 
// Returns:   void
// Qualifier: based on real slot symbols to build fake tickets to all reels; Fake reels(top & bottom invisible)
// Parameter: GTArray<int> slotSymbols   :
//************************************
void BSSlotsContainer::BuildTicket(GTArray<int> slotSymbols)
{
#ifdef GT_DEBUG
	GTLogManager::SLogFormatComment("<------------- slot symbols (visible part current 3X5 reels)----------->");	
	GTLogManager::SLogFormatComment(slotSymbols.ToString());
#endif

	//based on real slot symbols to create fake tickets to all reels; 
	//make Fake reels(top & bottom invisible)

	//for exmaple:
	//	2, 3, 5, 6, 5,
	//	5, 5, 5, 8, 1,
	//	4, 3, 3, 3, 3
	//  make 5 reels
	//  reel1: 0, 2, 5, 4, 0
	//  reel2: 0, 3, 5, 3, 0
	// and so on
	GTDictionary<int, GTArray<int>* > reeltickets;

	//initialize
	for(int reelIndex = 0; reelIndex < m_reelColumns.Count(); reelIndex++)
	{
		GTArray<int>* pTickets = new GTArray<int>();
		pTickets->AddToTail(0);	//make fake symbols for top invisible symbols
		reeltickets.Add(reelIndex, pTickets);
	}

	//add reel symbols;
	for(int i = 0; i < slotSymbols.Length(); i++)
	{
		int reelID = i % m_reelColumns.Count();
		int slotSymbolValue = slotSymbols[i];

		GTArray<int>* pTickets = NULL;
		reeltickets.GetValueByKey(reelID, pTickets);		
		pTickets->AddToTail(slotSymbolValue);
	}

	//make fake symbols for top and bottom invisible symbols;
	for(int reelIndex = 0; reelIndex < m_reelColumns.Count(); reelIndex++)
	{
		GTArray<int>* pTickets;
		reeltickets.GetValueByKey(reelIndex, pTickets);
		pTickets->AddToTail(0);		//make fake symbols for bottom invisible symbols

		m_reelColumns[reelIndex]->SetTicket(*pTickets);	//send it to every reel;

		delete pTickets;
	}
	m_slotsSymbols = slotSymbols;
}
//create tickets;
void BSSlotsContainer::BuildTicket(GTString slotSymbolsStr)
{
	GTArray<int> slotSymbols;
	GTUtil::StringToArrayInt(slotSymbols, slotSymbolsStr);

	BuildTicket(slotSymbols);
}

 //************************************
 // Method:    GetReelWinSlotsForWinlines
 // FullName:  BSSlotsContainer::GetReelWinSlotsForWinlines
 // Access:    protected 
 // Returns:   GTDictionary<int, GTArray<GTVector2>* >   key = winlineID,  value = (reelID, slotID)
 // Qualifier: based on finalWinlineRes and winline define, match to every win slot position in every reel; and get (reel and win slots in this reel) for all winline
 // Parameter: GTDictionary<int, WinlineValue> finalWinlineRes   :  key = winlineID,  value = winlineValue;
 //************************************
void BSSlotsContainer::GetReelWinSlotsForWinlines(GTDictionary<int, WinlineValue>* pFinalWinlineRes)
{
	
	 //get winline define;
	 GTDictionary<int, GTArray<int> >* pSourceWinlines = WinlineAlgorithm::GetWinlines();
	 // based on finalWinlineRes and winline define, match to every win slot position in every slot;
	for(GTDictionary<int,WinlineValue>::ObjectTypeIterator it= pFinalWinlineRes->Begin(); it != pFinalWinlineRes->End(); it++)
	{
		int winlineID = it->first;
		WinlineValue value = it->second;
		int winCount = value.WinCount;
		
		GTArray<int> winline;
		pSourceWinlines->GetValueByKey(winlineID, winline);	//get winline;

		for(int i = 0; i < winCount; i++)
		{
			int winSlot = winline[i];
			int reelID = winSlot % m_reelColumnCount;	//get reelID;
			int realSlotPosInReel = winSlot / m_reelColumnCount;	//realSlotPostion
			int slotPosInReel = realSlotPosInReel + 1;	// because we had one fake slot (invisible)
			GTVector2 reelWinSlotValue(reelID, slotPosInReel);	//value = (reelID, slotPosInReel) in reel;

			GTArray<GTVector2>* winReelSlots = NULL;
			//add winline slot into reelWinSlotsDict;
			if(m_winlineReelSlotsDict.KeyExists(winlineID))
			{
				m_winlineReelSlotsDict.GetValueByKey(winlineID, winReelSlots);
			}
			else
			{
				winReelSlots = new GTArray<GTVector2>();
			}
			winReelSlots->AddToTail(reelWinSlotValue);
			m_winlineReelSlotsDict.Add(winlineID, winReelSlots);	//save winlineid as key, value is reel slot value to dict
		}
	}
}

//check whether to show winline;
void BSSlotsContainer::CheckShowWinline()
{	
	if(m_isShowingWinline)
		return;

	//check anyone reel status is Status_ShowWinline;
	for(int i = 0; i < m_reelColumnCount; i++)
	{
		BSReelColumn::ColumnStatus status = m_reelColumns[i]->GetStatus();
		if(status == BSReelColumn::Status_ShowWinline)
		{
			m_isShowingWinline = true;
			break;
		}
		else
		{
			m_isShowingWinline = false;
			m_curWinlineIDForWinTextToshow = -1;
		}
	}

// 	if(!m_isShowingWinline)
// 		return;

}

//finish show winline
void BSSlotsContainer::OnFinishShowWinline()
{
	//hide winline sprite;
	int winlineID = m_reelColumns[0]->m_curWinlineID;
	ShowWinlineSprite(winlineID, false);
	m_isShowingWinline = false;
}

//show all winlines;
bool BSSlotsContainer::SetupAllWinlines(const int timeToShowPerWinline)
{
	if(m_pTicketGenerator == NULL)
		return false;

	if(m_winlineReelSlotsDict.Count() <= 0)
	{
		GTLogManager::SLogFormatWarning("Warning! there is no winline");
		return true;
	}

	bool res = false;

	for(GTDictionary<int, GTArray<GTVector2>* >::ObjectTypeIterator it= m_winlineReelSlotsDict.Begin(); it != m_winlineReelSlotsDict.End(); it++)
	{
		int winlineID = it->first;
		res = (res & SetupWinline(winlineID, timeToShowPerWinline));
	}
	return res;
}

//************************************
// Method:    ShowWinline
// FullName:  BSSlotsContainer::ShowWinline
// Access:    protected 
// Returns:   bool
// Qualifier: show winline
// Parameter: const int id   :  winlinID
//************************************
bool BSSlotsContainer::SetupWinline(const int winlineID, const int timeToShowPerWinline)
{
	if(m_pTicketGenerator == NULL)
		return false;
	
	//show winline slot animations;
	if(!m_winlineReelSlotsDict.KeyExists(winlineID))
	{
		GTLogManager::SLogFormatWarning("Warning! Can not find  winline%d!", winlineID);
		return false;
	}
	
	GTArray<GTVector2>*  pWinSlotsInReel = NULL;
	m_winlineReelSlotsDict.GetValueByKey(winlineID, pWinSlotsInReel);
	if(pWinSlotsInReel != NULL)
	{
		for(int i=0; i < pWinSlotsInReel->Length(); i++)
		{
			GTVector2 value = (*pWinSlotsInReel)[i];
			int reelID = value.x;
			int slotPos = value.y; 
			m_reelColumns[reelID]->ShowWinline(winlineID, slotPos, timeToShowPerWinline);

			//GTLogManager::SLogFormatComment("-----  show winline %d    ------- reel %d  : status = %d --> slot[%d] win!!!", 
			//								it->first, reelID, m_reelColumns[reelID]->GetStatus(), slotPos);
		}
		return true;
	}

	return false;
}

//show winline sprite
void BSSlotsContainer::ShowWinlineSprite(int winlineID, bool visibility)
{	
	//show win text in 1st reel;
	GTArray<GTVector2>* pWinSlotsInReel = m_winlineReelSlotsDict[winlineID];
	if( (pWinSlotsInReel!= NULL) && (m_pFinalWinlineRes!= NULL))
	{
		if(m_pWinTextLabel == NULL)
		{
			m_pWinTextLabel = GameObjectCreation::CreateUILabelBMFont();
			m_pWinTextLabel->Initialize(FONT_NAME, 99);
		}
			//get win count;
		WinlineValue winlineValue= (*m_pFinalWinlineRes)[winlineID];
		GTString res = GTString::From(winlineValue.WinPrize);
		m_pWinTextLabel->SetText(res.ToCharString());

		//value = (reelId, slotPosInReel) in reel;
		GTPoint2 value = (*pWinSlotsInReel)[0];
		int slotPosInReel = (int)value.y;
		GTPoint2 slotPos = m_reelColumns[0]->m_slotItemsList[slotPosInReel]->GetPosition();
		slotPos.y -= 30;
		m_pWinTextLabel->SetPosition(slotPos);

		m_pWinTextLabel->SetZOrder(UI_ZOrder::WINTEXT);
	}

	if(m_pWinTextLabel)
		m_pWinTextLabel->SetVisible(visibility);
	
	//show winline and winframe;
	BSWinlineLoader::GetInstance()->ShowWinlineSprite(winlineID, visibility);
}

//show win prize
bool BSSlotsContainer::ShowWinPrize( const int winlineID ) 
{

	//show winprize on UILabel for this winline;
	if(!m_pFinalWinlineRes->KeyExists(winlineID))
	{
		GTLogManager::SLogFormatWarning("Warning! Can not find  winline count%d in m_pFinalWinlineRes!", winlineID);
		return false;
	}

	WinlineValue winlineValue; 
	m_pFinalWinlineRes->GetValueByKey(winlineID, winlineValue);
	int winPrize = winlineValue.WinPrize;
	// Add win within 2 seconds
	UIInfoPanelManager::Inst()->AddWin(winPrize, 2000);
	m_curWinlineIDForWinTextToshow = winlineID;

	SlotGameManager::GetInstance()->GetPlayer()->AddWinPoints(winPrize);
	return true;
}

//************************************
// Method:    RespinProcess
// FullName:  BSSlotsContainer::RespinProcess
// Access:    protected 
// Returns:   void
// Qualifier: check respin and do respin process if necessary
// Parameter: GTArray<int> slotSymbols   : symbols of slots;
//************************************
void BSSlotsContainer::StartRespinProcess()
{
	if(m_pTicketGenerator == NULL)
		return;
	
	if(!m_needRespinProcess)
		return;

	//before do respin, need clean all previous values;
	ReleaseWinlineReelSlotsDict();	

	m_status = Status_Respin_Start;
	/*
	//slotSymbols - for exmaple:
	2, 2, 10, 6, 5,
	5, 10, 5, 8, 1,
	9, 3, 3, 8, 3
	*/
	
	bool hasNewLockReels = CheckBonusSymbolsAndLock(false);	//first time to check, no any reels had been locked;

	//if no respin, then finish this spin; 
	if(!hasNewLockReels)	//no bonus symbol, no need respin!	//if(m_lockReelsDict.Count() < 1)	//no bonus symbol, no need respin!
	{
		m_needRespinProcess = false;

		
		if(m_freespin.m_freespinCount > 0)		
			m_status = Status_FreeSpin_Start;			//if has freespin, then we need continue to freespin (OnUpdate), 
		else
			m_status = Status_NONE;						//otherwise, we set default status;
		return;
	}
	

	//add all respin reels into dictionary
	GTDictionary<int, BSReelColumn::ColumnStatus> respinReelsDict;	//key is reelID, value isColumnStatus(useless)
	for(int j = 0; j < m_reelColumns.Count(); j++)
	{
		if(!m_lockReelsDict.KeyExists(j))
		{
			respinReelsDict.Add(j, m_reelColumns[j]->GetStatus());
		}
	}	
	
	BuildTicket(m_pTicketGenerator->GetRespinSlotSymbols());	//create ticket for all respin reels;

	//step2: get reel winslots for winlines;
	if(m_pFinalWinlineRes!= NULL)
	{
		m_pFinalWinlineRes->Clear();
		m_pFinalWinlineRes = NULL;
	}
	m_pFinalWinlineRes = m_pTicketGenerator->GetRespinFinalWinRes();
	if(m_pFinalWinlineRes->Count() > 0)
	{
		GetReelWinSlotsForWinlines(m_pFinalWinlineRes);
	}


	//DebugFinalSymbol(1);

	for(GTDictionary<int, BSReelColumn::ColumnStatus>::ObjectTypeIterator respinIT = respinReelsDict.Begin(); respinIT != respinReelsDict.End(); respinIT++)
	{
		int respinReelID = respinIT->first;
		m_reelColumns[respinReelID]->StartSpin();
	}

	//DebugFinalSymbol(3);
}

void BSSlotsContainer::FinishRespinProcess()
{
	if(m_pTicketGenerator == NULL)
		return;
	
	//DebugFinalSymbol(4);
	
	//unlock all reels(have bonus)
	for(GTDictionary<int, GTGameObject* >::ObjectTypeIterator it = m_lockReelsDict.Begin(); it != m_lockReelsDict.End(); it++)
	{		

		//set respin to there and play animation
		BSRespin* pRespin = (BSRespin*) it->second->GetBehaviour("BSRespin");
		if(pRespin)
		{
			pRespin->PlayUnLockAnimation();
			m_status = Status_Respin_Unlock;
		}		
	}
	m_needRespinProcess = false;
}

//************************************
// Method:    CheckBonusAndLock
// FullName:  BSSlotsContainer::CheckBonusAndLock
// Access:    protected 
// Returns:   bool
// Qualifier: depends on locked(2rd round) or not lock(1st round), to check bonus symbols and play respin or freespin
// Parameter: bool haveReelsLocked   :
//************************************
bool BSSlotsContainer::CheckBonusSymbolsAndLock(bool haveReelsLocked)
{
	int bonusMiniCount = 0;

	if(haveReelsLocked)	
	{
		//means to get final locked reels, this is 2rd round, which some reels had been locked 
		//in this round, even 1 reel should be lock and play;
		bonusMiniCount = 0;	
	}
	else
	{
		//this is 1st round, only bonus count larger than bonusMiniCount, 
		//then lock and play respin;
		 bonusMiniCount = 2;
	}

	bool haveNewLockReel = false;
	GTArray<int> newLockReelIDs;	//store all new lock reels
	
	//check bonus symbol;
	int bonusSymbolID = m_pTicketGenerator->GetBonusSymbolID();
	//GTArray<int> slotSymbols = m_pTicketGenerator->GetSlotSymbols();

	for(int i = 0; i < m_slotsSymbols.Length(); i++)
	{
		int reelID = i % m_reelColumnCount;
		int slotSymbolValue = m_slotsSymbols[i];

		//find bonus symbol, then add this reelID into dictionary for later lock;
		if(slotSymbolValue == bonusSymbolID)
		{
			if(!m_lockReelsDict.KeyExists(reelID))	
			{
				newLockReelIDs.Add(reelID);
			}
		}
	}

	if(newLockReelIDs.Length() < bonusMiniCount)
		return false;

	//initialize all new lock reels
	for(int i = 0; i < newLockReelIDs.Length(); i++)
	{
		m_lockReelsDict.Add(newLockReelIDs[i], NULL);
	}

	//build new respin for every one new lock reels
	for(int i = 0; i < newLockReelIDs.Length(); i++)
	{
		int reelID = newLockReelIDs[i];
		GTGameObject* pGameObject = GTGameObjectManager::Inst()->CreateGameObject(NULL, CTEXT("respin1"), CTEXT("SlotGame/Respin.property"));
		if(pGameObject)
		{
			//add new lock reel into dictionary;
			m_lockReelsDict.Remove(reelID);
			m_lockReelsDict.Add(reelID, pGameObject);

			//get every reel position
			BSReelColumn* reelColum = m_reelColumns[reelID];
			GTPoint2 reelPos = reelColum->GetGameObjectPosition();		

			//set respin to there and play animation
			BSRespin* pRespin = (BSRespin*)(pGameObject->GetBehaviour(CTEXT("BSRespin")));
			if(pRespin)
			{			
				pRespin->SetGameObjectPosition(reelPos);

				GTLogManager::SLogFormatTrace("repsin lock: (%f, %f)  -> playing lock animtion", reelPos.x, reelPos.y);
				pRespin->PlayLockAnimation();
				haveNewLockReel = true;
			}
		}
	}
	return haveNewLockReel;
}

//************************************
// Method:    StartFreeSpinProcess
// FullName:  BSSlotsContainer::StartFreeSpinProcess
// Access:    protected 
// Returns:   void
// Qualifier: check freespin count and ready for freespin
//************************************
void BSSlotsContainer::StartFreeSpinProcess()
{
 	m_status = Status_FreeSpin_Start;
	m_freespin.StartFreeSpinProcess(m_pTicketGenerator, &m_slotsSymbols);
// 
// 	if(m_pTicketGenerator == NULL)
// 	{
// 		m_status = Status_FreeSpin_End;
// 		return;
// 	}
// 
// 	//step1: check bonus symbols we have;
// 	int bonusSymbolID = m_pTicketGenerator->GetBonusSymbolID();
// 	int newFreespinCount =  m_pTicketGenerator->GetFreeSpinCount(&m_slotsSymbols, FREESPIN_NUMBER_FOR_EVERY_BONUS_REEL);	//get new freespin count;
// 	m_freespinCount += newFreespinCount;
// 	GTLogManager::SLogFormatTrace("Freespin ----> win %d freespin! totoal = %d ", newFreespinCount, m_freespinCount);
// 
// 	if(m_freespinCount <= 0)
// 	{
// 		m_status = Status_FreeSpin_End;
// 		GTLogManager::SLogFormatComment("Freespin ---> Finished Freespin!!");
// 		return;
// 	}
}
