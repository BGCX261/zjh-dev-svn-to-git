#ifndef _G_SPRITE_COCOS2DX_H_
#define _G_SPRITE_COCOS2DX_H_

#pragma once

#include <GTBehaviour.h>
#include <GTTreeNode.h>
#include "BSReelColumn.h"
#include "..\WinlineAlgorithm.h"
#include "BSRespin.h"
#include "..\TicketGenerator.h"
#include <UI\UILabelBMFont.h>
#include "..\Freespin.h"

class BSSlotsContainer : public GTBehaviour
{
public:
	GTBEHAVIOUR_DEF(BSSlotsContainer, GTBehaviour);

	enum Game_Status {
		Status_NONE = 0, 
		Status_StartProcess,
		Status_Spin_Start,
		Status_Spin_End,
		Status_Respin_Start,
		Status_Respin_ReelStop, 
		Status_Respin_NewLock,
		Status_Respin_Unlock,
		Status_Respin_End,
		Status_FreeSpin_Start,
		Status_FreeSpin_End,
	};

public:
	BSSlotsContainer();
	virtual ~BSSlotsContainer();

	void ReleaseWinlineReelSlotsDict();	//clean winline reel slots dictionary;

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

	void CheckShowWinline();	//check whether to show winline;
	void OnFinishShowWinline();	//finish to show winline;
	
public:
	void Test();

	void StartSpinProcess();	//start spin process	

	GTArray<int> * GetCurrentSlotsSymbol();	//get current slots symbols;
protected:
	Game_Status m_status;
	GTList<BSReelColumn *> m_reelColumns;	//reel column list;
	//GTArray<BSReelColumn::ColumnStatus> m_reelColumnsStatus;	//reel status dictionary;
	GTArray<int> m_slotsSymbols;	//current slots symbols;

	int m_reelColumnCount;	

	TicketGenerator *m_pTicketGenerator;

	GTDictionary<int, WinlineValue>* m_pFinalWinlineRes;		//store winline result;
	GTDictionary<int, GTArray<GTVector2>* > m_winlineReelSlotsDict;	//store reel/winslots for winline; key = winlineID, value = (reelId, slotPosInReel) in reel;
	

	bool m_needRespinProcess;	//need respin process
	GTDictionary<int, GTGameObject* > m_lockReelsDict;	//key is reelID, value is slotSymbolID;
	
	bool m_isShowingWinline;	//flag of showing winlines
	int m_curWinlineIDForWinTextToshow;//current winline to show;
	UILabelBMFont* m_pWinTextLabel;	//win text label;

protected:
	//check all reels status;
	GTArray<BSReelColumn::ColumnStatus> CheckAllReelsStatus();
	//check whether is ready to spin
	bool AreAllReelsStopped();

	//based on real slot symbols to create fake tickets to all reels; Fake reels(top & bottom invisible)
	void BuildTicket(GTArray<int> slotSymbols);	//create tickets;
	void BuildTicket(GTString slotSymbolsStr);	//create tickets;

	//physical spin all reels;
	void SpinAllReels();	

	//get (reel and win slots in this reel) for all winline;
	void GetReelWinSlotsForWinlines(GTDictionary<int, WinlineValue> *pFinalWinlineRes);
	
	//setup all winlines to show;
	bool SetupAllWinlines(const int timeToShowPerWinline);
	//setup winline
	bool SetupWinline(const int winlineID, const int timeToShowPerWinline);
	//show win prize
	bool ShowWinPrize( const int winlineID );
	//show winline sprite;
	void ShowWinlineSprite(int winlineID, bool visibility);

	//------------for respin--------------//

	//check respin and do respin process if necessary
	void StartRespinProcess();

	//check bonus symbols and lock
	bool CheckBonusSymbolsAndLock(bool haveReelsLocked);	//depends on locked(2rd round) or not lock(1st round), to check bonus symbols and play respin or freespin
	//bool CheckBonusSymbolsAndLock(int bonusMiniCount) ;

	void FinishRespinProcess();
	
	//release respin reels dictionary;
	void ReleaseRespinReelsDict();
	//-------------------------------------//


	//------------for free spin--------------//
	void StartFreeSpinProcess();	//start freespin process
	FreeSpin m_freespin;
	//-------------------------------------//

	int m_delayDuration;	//for delay;
	void SetDelay(int sec);

	int m_debugTestTicket;
// 
// 	void DebugFinalSymbol(int debugTime)
// 	{
// 		for(int i = 0; i < m_reelColumns.Count(); i++)
// 		{
// 			GTLogManager::SLogFormatComment(" %d -----> setTicket -->before  -> m_finalSymbolIDQueue =  %d ! ", debugTime, m_reelColumns[i]->m_finalSymbolIDQueue.size());			
// 		}
// 
// 	}
};

#endif /* _G_SPRITE_COCOS2DX_H_ */