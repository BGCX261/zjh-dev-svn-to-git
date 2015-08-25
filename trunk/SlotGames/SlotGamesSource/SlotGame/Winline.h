#ifndef _WINLINE_H_
#define _WINLINE_H_

#pragma once
#include "..\..\GreenTeaSource\GTDictionary.h"
#include "..\..\GreenTeaSource\GTArray.h"
#include "GTLog\GTLogManager.h"
 

#define PROPERTY_SPLIT_CHARACTER		"&&"
#define Value_Split_Charater			","

struct WinlineValue {
	int WinCount;
	int WinSymbol;
	int WinPrize;
	GTArray<int> WinSymbolArr;
	
	WinlineValue() :WinCount(0), WinSymbol(0), WinPrize(0) {}
	
	GTString ToString()
	{
		GTString res;
		res.Append(GTString::From(WinCount));
		res.Append(PROPERTY_SPLIT_CHARACTER);

		res.Append(GTString::From(WinSymbol));
		res.Append(PROPERTY_SPLIT_CHARACTER);

		GTString winSymbolArrStr = WinSymbolArr.ToString();
		res.Append(winSymbolArrStr);
		return res;
	}

	WinlineValue FromString(GTString valueStr)
	{
		//TODO: need parse string value to WinlineValue;
		GTLogManager::SLogWarning("TODO: need parse string value to WinlineValue!");
		return WinlineValue();
	}
};

//winline and paytable class
class Winline
{
public:
	//calculate winlines
	static GTDictionary<int, WinlineValue> CalculateWinLines(GTArray<int> slots, int wildSymbolID);	//calculate slots to get which numbers of winline(Winned);

	//calculate win prize
	static GTDictionary<int, int> CalculateWinPrize(GTDictionary<int, WinlineValue> winlinesDict, int& totalWin);	//calculate prize based on winlines;

	static GTDictionary<int, GTArray<int> >* GetWinlines();	//getWinlines from winline loader
	static GTDictionary<int, int>* GetPaytable();	//getpaytable from winline loader
protected:
	//static GTDictionary<int, GTArray<int> > m_windlinesDefine; //GTList<int> slotIDList;//symbolList to define slots in winline

	//Convert paytable key into value;
	static void ConvertPaytableKey(int key, int& winCount, int& winSymbol);
	//convert wincount & winsymbol to Key;
	static int ConvertWinlineValueToPaytableKey(int winCount, int winSymbol);
	Winline(void);
	~Winline(void);
};


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

#endif /* _WINLINE_H_ */