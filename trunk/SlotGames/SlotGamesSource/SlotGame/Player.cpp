#include "Player.h"


Player::Player(const GTString &name)
{
	m_winPoints = 0;
}


Player::~Player(void)
{ 
}

int Player::AddWinPoints(const int nWinPoints)
{
	m_winPoints += nWinPoints;
	return m_winPoints;
}