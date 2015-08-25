#include "TicketGenerator.h"
#include <GTLog\GTLogManager.h>
#include "..\GreenTeaSource\GTGameObjectManager.h"

#define PROPERTY_TAG_ICONLOADER				CTEXT("IconLoader")

//for ticket writer;
#define PROPERTY_SPLIT_CHARACTER		"&&"
#define Value_Split_Charater			","
#define DICTIONARY_SPLIT_START			"["
#define DICTIONARY_SPLIT_END			"]"
#define DICTIONARY_KEY					"KEY="
#define DICTIONARY_VALUE				"VALUE="
#define REEL_COLUMN_COUNT				CTEXT("REEL_COLUMN_COUNT=")
#define SLOT_SYMBOLS					CTEXT("SLOT_SYMBOLS=")
#define TOTAL_WIN						CTEXT("TOTAL_WIN=")
#define WINLINE_REEL_SLOTS				CTEXT("WINLINE_REEL_SLOTS=")
#define SLOT_RESPIN_SYMBOLS				CTEXT("SLOT_RESPIN_SYMBOLS=")

TicketGenerator::TicketGenerator(int reelColumnCount, int testDataNumber)
{
	m_reelColumnCount = reelColumnCount;
	m_totalWin = 0;
	
	m_testDataNumber = testDataNumber;
	GTArray<int> slotSymbols = GetSlotSymbols();

	//step1: Get final win Result;
	GTDictionary<int, WinlineValue> * normal_finalWinlineRes = CalculateFinalWinResult(&slotSymbols);
	m_winlineResList.Add(normal_finalWinlineRes);

	//step2: respin?
	m_needRespin = NeedRespin(&slotSymbols);

	if(m_needRespin)
	{
		GTArray<int> respinSlotSymbols = GetRespinSlotSymbols();
		GTDictionary<int, WinlineValue>*  respin_finalWinlineRes = CalculateFinalWinResult(&respinSlotSymbols);
		m_winlineResList.Add(respin_finalWinlineRes);
	}

	CreateFullTicketString();	//for test to check ticket string;
}


TicketGenerator::~TicketGenerator(void)
{
	ReleaseWinlineResList();
}

void TicketGenerator::ReleaseWinlineResList()
{
	for(int i = 0; i < m_winlineResList.Length(); i++)
	{
		GTDictionary<int, WinlineValue> * pWinlineRes = m_winlineResList[i];
		delete pWinlineRes;
	}
}

//----------------------test datat------------------------//
GTArray<int> TicketGenerator::TestSlotSymbols(int testDataNumber)
{

	if(testDataNumber == 0)
	{
		int srcSlots[15] = { 
			//1, 3, 2, 5, 7,
			2, 2, 10, 6, 5,
			5, 10, 5, 8, 1,
			9, 3, 3, 8, 3
			//6, 3, 2, 1, 1,
		};

		return GTArray<int>(srcSlots, 15);
	}

	if(testDataNumber == 1)
	{
		int srcSlots[15] = { 
			//1, 3, 2, 5, 7,
			9, 5, 7, 1, 2,
			3, 3, 7, 3, 1,
			4, 1, 1, 2, 2
			//6, 3, 2, 1, 1,
		};

		return GTArray<int>(srcSlots, 15);
	}

	if(testDataNumber == 2)
	{
		int srcSlots[15] = { 
			//1, 3, 2, 5, 7,
			2, 2, 10, 6, 5,
			6, 2, 5, 6, 4,
			8, 3, 3, 8, 3
			//6, 3, 2, 1, 1,
		};

		return GTArray<int>(srcSlots, 15);
	}

	if(testDataNumber == 3)
	{
		int srcSlots[15] = { 
			//1, 3, 2, 5, 7,
			8, 2, 3, 3, 5,
			5, 1, 5, 8, 1,
			10, 3, 3, 8, 3
			//6, 3, 2, 1, 1,
		};

		return GTArray<int>(srcSlots, 15);
	}

	if(testDataNumber == 4)
	{
		int srcSlots[15] = { 
			//1, 3, 2, 5, 7,
			2, 2, 8, 6, 5,
			5, 2, 5, 8, 1,
			9, 3, 3, 8, 3
			//6, 3, 2, 1, 1,
		};

		return GTArray<int>(srcSlots, 15);
	}

	if(testDataNumber == 5)
	{
		int srcSlots[15] = { 
			//1, 3, 2, 5, 7,
			9, 2, 6, 6, 5,
			1, 5, 5, 8, 1,
			1, 3, 1, 8, 3
			//6, 3, 2, 1, 1,
		};

		return GTArray<int>(srcSlots, 15);
	}

	if(testDataNumber == 6)
	{
		int srcSlots[15] = { 
			//1, 3, 2, 5, 7,
			1, 2, 10, 6, 5,
			5, 4, 5, 8, 1,
			9, 3, 3, 4, 3
			//6, 3, 2, 1, 1,
		};

		return GTArray<int>(srcSlots, 15);
	}	
	
	if(testDataNumber == 1)
	{
		int srcSlots[15] = { 
			//1, 3, 2, 5, 7,
			4, 2, 4, 6, 5,
			1, 9, 4, 8, 1,
			9, 3, 4, 2, 3
			//6, 3, 2, 1, 1,
		};

		return GTArray<int>(srcSlots, 15);
	}
	else
	{
		int srcSlots[15] = { 
			//1, 3, 2, 5, 7,
			3, 3, 2, 6, 5,
			5, 4, 5, 8, 1,
			4, 5, 5, 4, 3
			//6, 3, 2, 1, 1,
		};

		return GTArray<int>(srcSlots, 15);
	}
}
//---------------------------------------------------------------//

//get slot symbols;
GTArray<int> TicketGenerator::GetSlotSymbols()
{

	return TestSlotSymbols(m_testDataNumber);
}

//get respin slots symbol
GTArray<int> TicketGenerator::GetRespinSlotSymbols()
{	
	//respin all other reels
	int srcSlots[15] = { 
		//1, 3, 2, 5, 7,
		1, 2, 10, 3, 9,
		1, 10, 5, 3, 9,
		3, 3, 3,  3, 10
		//6 1, 1,
	};

	return GTArray<int>(srcSlots, 15);
}

//get normal Final win result;
GTDictionary<int, WinlineValue> * TicketGenerator::GetNormalFinalWinRes()
{
	 GTDictionary<int, WinlineValue>* normal_finalWinlineRes = m_winlineResList[0];
	 return normal_finalWinlineRes;
}

//get respin Final win result;
GTDictionary<int, WinlineValue> * TicketGenerator::GetRespinFinalWinRes()
{
	if((!m_needRespin) || (m_winlineResList.Length() < 1))
		return NULL;

	GTDictionary<int, WinlineValue>* respin_finalWinlineRes = m_winlineResList[1];
	return respin_finalWinlineRes;
}

//************************************
// Method:    GetFinalWinResult
// FullName:  TicketGenerator::GetFinalWinResult
// Access:    protected 
// Returns:   GTDictionary<int, WinlineValue>
// Qualifier: Get final winline and result;
//************************************
GTDictionary<int, WinlineValue> * TicketGenerator::CalculateFinalWinResult(GTArray<int>* slotSymbols)
{
	//calculate winlines all win symbols;;	 
	GTDictionary<int, WinlineValue> winlineRes = WinlineAlgorithm::CalculateWinLines(*slotSymbols, GetWildSymbolID());
	
	//match paytable, calculate win prize;	
	GTDictionary<int, int> winlinePrizes = WinlineAlgorithm::CalculateWinPrize(winlineRes, m_totalWin);

	//get final winline
	GTDictionary<int, WinlineValue>* finalWinlineRes = new GTDictionary<int, WinlineValue>();
	for(GTDictionary<int, int>::ObjectTypeIterator it = winlinePrizes.Begin(); it != winlinePrizes.End(); it++)
	{
		int winlineID = it->first;
		WinlineValue value;
		winlineRes.GetValueByKey(winlineID, value);
		value.WinPrize = it->second;	//set winprize;

		finalWinlineRes->Add(winlineID, value);
	}
	
#ifdef GT_DEBUG
	GTLogManager::SLogFormatComment("<------------- calculate winline win symbol count----------->");
	for(GTDictionary<int,WinlineValue>::ObjectTypeIterator it= winlineRes.Begin(); it != winlineRes.End(); it++)
	{
		int winlineID = it->first;
		int WinCount = it->second.WinCount;
		int WinSymbol = it->second.WinSymbol;
		GTArray<int> WinSymbolArr = it->second.WinSymbolArr;
		GTString symboldArrStr = WinSymbolArr.ToString();
		GTLogManager::SLogFormatComment("winline %d ---> wincount = %d,  winsymbol = %d ---> win Symbol = %s", winlineID, WinCount, WinSymbol, symboldArrStr.ToCharString());
	}

	GTLogManager::SLogFormatComment("<------------- winline prize----------->");
	for(GTDictionary<int,int>::ObjectTypeIterator it= winlinePrizes.Begin(); it != winlinePrizes.End(); it++)
	{
		GTLogManager::SLogFormatComment("winlinePrizes :  winline %d : %d ", it->first, it->second);

	}
	GTLogManager::SLogFormatComment("<------------- total win :  %d ----------->", m_totalWin);
#endif

	return finalWinlineRes;
}

//get total win;
int TicketGenerator::GetTotalWin()
{
	return m_totalWin;
}

//get wild symbol id;
int TicketGenerator::GetWildSymbolID()
{
	int wildSymbolID = -1;
	GTGameObject* pIconLoaderObj = NULL;	
	pIconLoaderObj = GTGameObjectManager::FindGameObject(PROPERTY_TAG_ICONLOADER);
	if(pIconLoaderObj)
	{
		BSIconLoader* pBSSymbolLoader = (BSIconLoader*)pIconLoaderObj->GetBehaviour("BSIconLoader");

		if(NULL == pBSSymbolLoader)	{
			GTLogManager::SLogError("Error! Can't find IconLoader!");		
		}
		wildSymbolID = pBSSymbolLoader->GetWildIconID();
	}
	return wildSymbolID;
}

//create full ticket string
GTString TicketGenerator::CreateTicketString(bool bFullTicket)
{
	GTString ticket;
	
// 	if(bFullTicket)
// 	{
// 		//1.1 write reel column count; 
// 		GTString reelColumnCountStr = ConvertIntToTicketString(REEL_COLUMN_COUNT, m_reelColumnCount);
// 		ticket.Append(reelColumnCountStr);
// 	}

	//2 write slot symobls;
	ticket.Append(SLOT_SYMBOLS);
	GTArray<int> slotsSymbols = GetSlotSymbols();
	ticket.Append(slotsSymbols.ToString());
	ticket.Append(PROPERTY_SPLIT_CHARACTER);

	//3.1 write total win 
	GTString totalWinstr = ConvertIntToTicketString(TOTAL_WIN, m_totalWin);
	ticket.Append(totalWinstr);

	if(bFullTicket)
	{
		//4. write final Winline Res;
		ticket.Append(WINLINE_REEL_SLOTS);
		GTDictionary<int, WinlineValue> *normal_finalWinlineRes = GetNormalFinalWinRes();
		WriteWinlineResToTicket(normal_finalWinlineRes, ticket);

	}	

	//5. respin slot symbols;
	if(m_needRespin)
	{
		ticket.Append(SLOT_RESPIN_SYMBOLS);	
		GTArray<int> slotsRespinSymbols = GetRespinSlotSymbols();
		ticket.Append(slotsRespinSymbols.ToString());
		ticket.Append(PROPERTY_SPLIT_CHARACTER);

		if(bFullTicket)
		{
			GTDictionary<int, WinlineValue>* respin_finalWinlineRes = m_winlineResList[1];
			WriteWinlineResToTicket(respin_finalWinlineRes, ticket);
		}
	}


	GTLogManager::SLogComment(ticket.ToCharString());

	return ticket;
}
//create simple ticket string;
GTString TicketGenerator::CreateSimpleTicketString()
{
	return CreateTicketString(false);
}
//create full ticket string
GTString TicketGenerator::CreateFullTicketString()
{
	return CreateTicketString(true);
}

void TicketGenerator::WriteWinlineResToTicket( GTDictionary<int, WinlineValue> * finalWinlineRes, GTString &ticket ) 
{
	for(GTDictionary<int, WinlineValue>::ObjectTypeIterator it = finalWinlineRes->Begin(); it != finalWinlineRes->End(); it++)
	{
		ticket.Append(DICTIONARY_SPLIT_START);

		int winlineID = it->first;
		GTString winlineIDStr = ConvertIntToTicketString(DICTIONARY_KEY, winlineID);
		ticket.Append(winlineIDStr);	//add winlineID key

		WinlineValue winlineValue = it->second;
		GTString winlineValueStr = winlineValue.ToString();
		ticket.Append(DICTIONARY_VALUE);
		ticket.Append(winlineValueStr);

		ticket.Append(DICTIONARY_SPLIT_END);
	}
	ticket.Append(PROPERTY_SPLIT_CHARACTER);
}

//convert int to ticket string;
GTString TicketGenerator::ConvertIntToTicketString(GTString key, int v)
{
	GTString res;
	res.Append(key);
	res.Append(GTString::From((int32)v));
	res.Append(PROPERTY_SPLIT_CHARACTER);
	return res;
}

//get bonus symbol id;
int TicketGenerator::GetBonusSymbolID()
{
	int bonusSymbolID = -1;
	GTGameObject* pIconLoaderObj = NULL;	
	pIconLoaderObj = GTGameObjectManager::FindGameObject(PROPERTY_TAG_ICONLOADER);
	if(pIconLoaderObj)
	{
		BSIconLoader* pBSSymbolLoader = (BSIconLoader*)pIconLoaderObj->GetBehaviour("BSIconLoader");

		if(NULL == pBSSymbolLoader)	{
			GTLogManager::SLogError("Error! Can't find IconLoader!");		
		}
		bonusSymbolID = pBSSymbolLoader->GetBonusIconID();
	}
	return bonusSymbolID;
}

//check need respin or not;
bool TicketGenerator::NeedRespin(GTArray<int>* pSlotSymbols)
{
	//check bonus symbol;
	int bonusSymbolID = GetBonusSymbolID();

	for(int i = 0; i < pSlotSymbols->Length(); i++)
	{
		int reelID = i % m_reelColumnCount;
		int slotSymbolValue = (*pSlotSymbols)[i];

		//find bonus symbol, then add this reelID into dictionary for later lock;
		if(slotSymbolValue == bonusSymbolID)
		{
			return true;
		}
	}

	return false;
}

//************************************
// Method:    GetFreeSpinCount
// FullName:  TicketGenerator::GetFreeSpinCount
// Access:    protected 
// Returns:   int
// Qualifier: get total free spin count;
// Parameter: GTArray<int> * pSlotsSymbols   : slot symols
// Parameter: int number_for_every_bonus_Reel   : free spin number for every bonus reel;
//************************************
int TicketGenerator::GetFreeSpinCount(GTArray<int>* pSlotsSymbols, int number_for_every_bonus_Reel)
{
	if(pSlotsSymbols == NULL)
		return -1;

	int bonusReelCount = 0;

	//step1: check bonus symbols we have;
	int bonusSymbolID = GetBonusSymbolID();
	GTDictionary<int, int> bonusReels;		//key = reelid which has bonus, value is slotID( not use)
	
	for(int i = 0; i < pSlotsSymbols->Length(); i++)
	{
		int reelID = i % m_reelColumnCount;
		int slotSymbolValue = (*pSlotsSymbols)[i];

		//find bonus symbol, then add this reelID into dictionary for later lock;
		if(slotSymbolValue == bonusSymbolID)
		{
			if(!bonusReels.KeyExists(reelID))	//if not this reelid, add it;
			{
				bonusReels.Add(reelID, i);
				++bonusReelCount;
			}
		}
	}

	if(bonusReelCount <= 2)
		return 0;

	int freespinCount = bonusReelCount * number_for_every_bonus_Reel;
	return freespinCount;
}