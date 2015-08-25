#include "WinlineAlgorithm.h"
#include "GTLog\GTLogManager.h"
#include "..\..\GreenTeaSource\GTGameObject.h"
#include <GTGameObjectManager.h>
#include "SlotGameBehavior\BSWinlineLoader.h"
 
//------------------------------Winline-------------------------//
WinlineAlgorithm::WinlineAlgorithm(void)
{
}


WinlineAlgorithm::~WinlineAlgorithm(void)
{
}


//************************************
// Method:    GetWinlines
// FullName:  Winline::GetWinlines
// Access:    public 
// Returns:   void
// Qualifier: get all winlines from winline loader;
//************************************
GTDictionary<int, GTArray<int> >* WinlineAlgorithm::GetWinlines()
{
	return BSWinlineLoader::GetInstance()->GetWinlines();

	//-------Example--------//
	/*
	Winline1 =   5 6 7 8 9       
	Winline2 =   0 1 2 3 4       
	Winline3 =   10 11 12 13 14  
	Winline4 =   0 6 12 8 4      
	Winline5 =   10 6 2 8 14     
	Winline6 =   10 6 2 3 4      
	Winline7 =   0 6 12 13 14    
	Winline8 =   5 6 7 3 4       
	Winline9 =   5 6 7 13 14     
	Winline10 =  5 1 2 3 9      
	Winline11 =  5 11 12 13 9   
	Winline12 =  0 11 2 13 4    
	Winline13 =  10 1 12 3 14   
	Winline14 =  0 6 2 8 4      
	Winline15 =  10 11 12 8 4   
	Winline16 =  5 6 2 8 9      
	Winline17 =  5 6 12 8 9     
	Winline18 =  5 2 7 4 9      
	Winline19 =  5 11 7 13 9    
	Winline20 =  0 1 7 13 14     
	Winline21 =  10 11 7 3 4    
	Winline22 =  10 6 12 8 14   
	Winline23 =  10 6 7 8 14    
	Winline24 =  0 6 7 8 4      
	Winline25 =  0 1 2 8 14 
	*/
}

//************************************
// Method:    CalculateWin
// FullName:  Winline::CalculateWin
// Access:    public 
// Returns:   GTDictionary<int, WinlineValue>  : key = winlineID; value = winlineValue
// Qualifier: calculate slots to get which numbers of winline(Winned);
// Parameter: GTList<int> slots   : slot symbol id
// Parameter: wildSymbolID   : wild symbol ID
//************************************
GTDictionary<int, WinlineValue> WinlineAlgorithm::CalculateWinLines(GTArray<int> srcSlots, int wildSymbolID)
{
	GTDictionary<int, GTArray<int> >* pWindlinesDefine = GetWinlines(); //GTList<int> slotIDList;//symbolList to define slots in winline

	GTDictionary<int, WinlineValue> res;
	
	if(NULL == pWindlinesDefine)
		return res;	

	for(GTDictionary<int, GTArray<int> >::ObjectTypeIterator it = pWindlinesDefine->Begin(); it != pWindlinesDefine->End(); it++)
	{
		int winlineID = it->first;
		GTArray<int>& winlineSlots = it->second;

		if(winlineSlots.Length() < 2)
		{	
			//This winline is wrong! There are less than 2 slots
			GTLogManager::SLogFormatError("Error! winline[%d] is less than 2 slots, can't compare!!! ", winlineID);
			continue;
		}
		else
		{
			//compare slots, check how many symbols are same;
			bool bEqual = false;	
			int firstSymbolID = srcSlots[winlineSlots[0]];

			WinlineValue curWinlineValue;	//create winline value;
			curWinlineValue.WinCount = 1;
			curWinlineValue.WinSymbol = firstSymbolID;
			curWinlineValue.WinSymbolArr.AddToTail(firstSymbolID);

			for(int i = 1; i < winlineSlots.Length(); i++)
			{
				int slotPosID = winlineSlots[i];	//slot postion ID			
				int curSymbolID = srcSlots[slotPosID];

				if( (firstSymbolID == curSymbolID) || (firstSymbolID == wildSymbolID) || (curSymbolID == wildSymbolID))
				{
					//current symbol is same as previous symbol;  or it is wild symbol;

					if(firstSymbolID == wildSymbolID)
					{
						firstSymbolID = curSymbolID;	//find current symbol to replace first(not wild symbol)						
					}

					bEqual = true;

					//create winline value;
					curWinlineValue.WinCount++;
					curWinlineValue.WinSymbol = firstSymbolID;
					curWinlineValue.WinSymbolArr.AddToTail(curSymbolID);
				}
				else
				{
					//currrent symbol is not same;
					break;
				}
			}

			//add winline id and value into dict
			if(bEqual)
			{
				res.Add(winlineID, curWinlineValue);
			}
		}		
	}
	return res;
}


//************************************
// Method:    GetPaytable
// FullName:  Winline::GetWinlines
// Access:    public 
// Returns:   void
// Qualifier: get wintable from winline loader;
//************************************
GTDictionary<int, int>* WinlineAlgorithm::GetPaytable()
{
	return BSWinlineLoader::GetInstance()->GetPaytable();

	//-------Example--------//
	/*
	PayTable1 =   510 5000      
	PayTable2 =   501 4000       
	PayTable3 =   401 250
	PayTable4 =   301 25 
	PayTable5 =   502 2000   
	PayTable6 =   402 200   
	PayTable7 =   302 20 
	PayTable8 =   503 1000     
	PayTable9 =   403 150    
	PayTable10 =  303 15     
	PayTable11 =  504 300 
	PayTable12 =  404 50     
	PayTable13 =  304 10  
	PayTable14 =  505 200 
	PayTable15 =  405 35
	PayTable16 =  305 8
	PayTable17 =  506 150
	PayTable18 =  406 20
	PayTable19 =  306 7
	PayTable20 =  507 100
	PayTable21 =  407 20
	PayTable22 =  307 5
	PayTable23 =  508 100
	PayTable24 =  408 20
	PayTable25 =  308 5
	PayTable26 =  561 50
	PayTable27 =  462 10
	PayTable22 =  363 3
	PayTable23 =  209 2
	*/
}

//************************************
// Method:    CalculateWinPrize
// FullName:  Winline::CalculateWinPrize
// Access:    public static 
// Returns:   GTDictionary<int, int>: key = winlineID; value = prize
// Qualifier: calculate win prize
//************************************
GTDictionary<int, int> WinlineAlgorithm::CalculateWinPrize(GTDictionary<int, WinlineValue> winlinesDict, int& totalWin)
{
	//initialize 
	GTDictionary<int, int> prizeRes;

	//get paytable
	GTDictionary<int, int >* pPattableDefine = GetPaytable();
	if(pPattableDefine->Count() < 1)
	{
		GTLogManager::SLogWarning("Warning! Can not find paytable!");
		return prizeRes;
	}

	//loop to get all winline win values, and find them in paytable,
	for(GTDictionary<int, WinlineValue>::ObjectTypeIterator it = winlinesDict.Begin(); it != winlinesDict.End(); it++)
	{
		int winlineID = it->first;
		WinlineValue curWinlineValue = it->second;
		int paytableKey = ConvertWinlineValueToPaytableKey(curWinlineValue.WinCount, curWinlineValue.WinSymbol);

		//find win symbol in paytable and calculate the prize
		if(pPattableDefine->KeyExists(paytableKey))
		{
			int prize;
			pPattableDefine->GetValueByKey(paytableKey, prize);
			prizeRes.Add(winlineID, prize);
			totalWin += prize;
		}
	}

	return prizeRes;
}


//************************************
// Method:    ConvertPaytableKey
// FullName:  Winline::ConvertPaytableKey
// Access:    public static 
// Returns:   void
// Qualifier: Convert paytable key into value;
//				510 = 5 count  winsymbol is 10
//				401 = 4 count  winsymbol is 1
//************************************
void WinlineAlgorithm::ConvertPaytableKey(int key, int& winCount, int& winSymbol)
{
	winCount = (int)(key/100);
	winSymbol = (int)((key - 100 * winCount)%10);
}

int WinlineAlgorithm::ConvertWinlineValueToPaytableKey(int winCount, int winSymbol)
{
	int key = winCount * 100 + winSymbol;
	return key;
}