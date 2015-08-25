#ifndef _BS_REEL_COLUMN_COCOS2DX_H_
#define _BS_REEL_COLUMN_COCOS2DX_H_

#include <GTBehaviour.h>
#include <GTTreeNode.h>
#include "BehaviourScript\BSSprite.h"
#include <GTTweener2D.h>
#include "..\SlotItem.h"
#include <queue>

//Reel Column;
class BSReelColumn : public GTBehaviour
{
public:
	GTBEHAVIOUR_DEF(BSReelColumn, GTBehaviour);

	//column status;
	enum ColumnStatus {
		Status_Stopped				= -1,
		Status_StartSpin		= 0,
		Status_Windup,
		Status_Begin_Rolling,
		Status_Stop_Rolling,
		Status_SlowDownToStop,
		Status_ShowWinline,
	};

public:
	BSReelColumn();
	virtual ~BSReelColumn();

	// This method is called when GTBehaviour object is created.
	virtual int32 OnCreate(void);
	// This method is called when GTBehaviour object is initialized.
	virtual int32 OnInitialize(GTBehaviourInitParam* param);
	// This method is called before first OnUpdate
	virtual int32 OnStart(void);
	// This method is called when GTBehaviour object is updated.
	virtual int32 OnUpdate(void);

	// This method is called when GTBehaviour object is destroyed.
	virtual int32 OnDestroy(void);

	// Create the sprite from the property tree node
	bool CreateFromPropertyTreeNode(GTTreeNode *pTreeNode);

public:
	int m_rowCount;			//row count;
	bool m_rowDirection;	//row direction, true is up to down; false : reverse;

	int m_rowHeight;		//slot height
	int m_reelRollingDuration;		//reel rolling duration
	int m_reelRollingSteps;		//reel rolling steps * m_rowHeight = total distances;
	bool m_bChangeToFinalSymbol;	//change final symbols for final stop;(based on ticket);

	//for swap algorithm
	float m_slotBottomY;	
	float m_slotTopY;	
	
	GTList<SlotItem*> m_slotItemsList;	//reel slot list;
	BSReelColumn::ColumnStatus m_columnStatus;		//column status;
	BSSprite* m_pWinframeSprite;		//win frame sprite

	GTTweener2D m_tween2d;	//for math;
	float m_oldYPos;

	float m_updateDeltaTime;	//delta update time for OnUpdate
	float m_updateTotalDuration;	//total time for OnUpdate;

	std::queue<int> m_finalSymbolIDQueue;	//store final slot icon ID;

	bool m_bPlayingWinAnimation;	//show winline or not;
	int m_curWinSlotPos;	//current win slot postion;
	std::queue<GTVector2> m_winSlotPosQueue;	//save all win slot position for different winline
	int m_curWinlineID;		//current winline id;
	int m_timeToShowPerWinline;//time to show winline;

protected:	
	void onTimerStopped();
	void onTimerStartSpin();		//start spin timer;
	void onTimerRolling();			//Rolling timer;
	void onTimerStopRolling();
	void onTimerWindupColumn();		//windup the column;
	void onTimerSlowDownToStop();	//slot down to stop the column
	void onTimeShowWinline();		//show winlines

	bool ChangeSymbol(int slotItemID);		//change slotItem;
	bool BackToStartPosition(float srcY, float& destY);	//get new postion which are always on container;

	//void MoveColumByTime(float deltaTime, bool bReelModel);	//Move column at delta time;
	void MoveColumByDeltaPos(float yDeltaPos, bool bReelModel,  bool bChangeSymbolWhenBackToStartPos);		//Move column at delta yPos;
	void MoveColumToPos(float yNewPos, bool bReelModel,  bool bChangeSymbolWhenBackToStartPos);
	void MoveColumnByTween2D(const float deltaTime, GTTweener2D& tween2D, bool bReelModel,  bool bChangeSymbolWhenBackToStartPos);	//move column based on Tween2d Algorithm

	void SortSlotItems();	//sort slotitems;
	
	void PrintSlotItemList();	//print slotItem list;
public:
	BSReelColumn::ColumnStatus GetStatus();

	void StartSpin();	//start SlotItems
	void StopSpin();	//stop SlotItems
	
	void SetTicket(GTArray<int> ticket);	//set tickets;
	void ShowWinline(int winlineID, int slotPos, const int timeToShowPerWinline);		//show winline;
	void ShowWinFrame(bool visibility);		//show winframe animation
};

#endif /* _BS_REEL_COLUMN_COCOS2DX_H_ */