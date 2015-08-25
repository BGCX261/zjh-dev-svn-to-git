#ifndef _SLOTGAME_PLAYER_H_
#define _SLOTGAME_PLAYER_H_

#pragma once 
#include "..\GreenTeaSource\GTString.h"

class Player
{
public:
	Player(const GTString &name);
	~Player(void);

	int AddWinPoints(const int nWinPoints);
public:
	GTString m_name;	//name
	int m_winPoints;	//win points

};



#endif /* _SLOTGAME_PLAYER_H_ */