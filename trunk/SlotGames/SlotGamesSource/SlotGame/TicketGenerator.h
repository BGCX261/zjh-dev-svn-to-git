#ifndef _TICKET_GENERATOR_H_
#define _TICKET_GENERATOR_H_

#pragma once
#include <GTArray.h>
#include <GTDictionary.h>
#include <GTGameObject.h>

#include "SlotGameBehavior\BSReelColumn.h"
#include "WinlineAlgorithm.h"

//generate ticket;
class TicketGenerator
{
public:
	TicketGenerator() {}
	TicketGenerator(int reelColumnCount, int testDataNumber);
	~TicketGenerator(void);

	void ReleaseWinlineResList();

	//create simple ticket string;
	GTString CreateSimpleTicketString();
	//create full ticket string
	GTString CreateFullTicketString();
	
	//get slot symbols;
	GTArray<int> GetSlotSymbols();

	//get total win;
	int GetTotalWin();
	
	GTArray<int> GetRespinSlotSymbols();	//get respin slots symbol

	//get normal Final win result;
	GTDictionary<int, WinlineValue> * GetNormalFinalWinRes();
	//get respin Final win result;
	GTDictionary<int, WinlineValue> * GetRespinFinalWinRes();

	//get bonus symbol id;
	int GetBonusSymbolID();

	//get freespin count
	int GetFreeSpinCount(GTArray<int>* pSlotsSymbols, int number_for_every_bonus_Reel);


protected:
	int m_reelColumnCount;

	//GTArray<int> m_slotSymbols;		//slot symobls;
	//GTDictionary<int, WinlineValue> m_normal_finalWinlineRes;	//final win res; key: winlineID, value: winlineVlaue
	//GTDictionary<int, WinlineValue> m_respin_finalWinlineRes;	//final win res; key: winlineID, value: winlineVlaue
	
	GTArray< GTDictionary<int, WinlineValue> *> m_winlineResList;
	int m_totalWin;

	int m_needRespin;

protected:	
	
	//Get final win Result;
	GTDictionary<int, WinlineValue> * CalculateFinalWinResult(GTArray<int>* slotSymbols);

	//get wild symbol id;
	int GetWildSymbolID();

	bool NeedRespin(GTArray<int>* pSlotSymbols);

	//create ticket string
	GTString CreateTicketString(bool bFullTicket);

	void WriteWinlineResToTicket(GTDictionary<int, WinlineValue> * finalWinlineRes, GTString &ticket ) ;


	//convert int to ticket string;
	static GTString ConvertIntToTicketString(GTString key, int value);

public:
	GTArray<int> TestSlotSymbols(int testDataNumber);
	int m_testDataNumber;
};


#endif /* _G_SPRITE_COCOS2DX_H_ */