#ifndef _GAME_GENERAL_H_
#define _GAME_GENERAL_H_

#include <GTGreenTea.h>
#include <GTSingleton.h>

class GameGeneral : public GTSingleton<GameGeneral>
{
public:
	GameGeneral();
	~GameGeneral();

	// Get order id for UI
	int32 GetZOrderIdUI(void) const
	{
		return GameGeneral::m_nZOrderIdUI;
	}
	// Get order id for sprite
	int32 GetZOrderIdSprite(void) const
	{
		return GameGeneral::m_nZOrderIdSprite;
	}
	// Get order id for map
	int32 GetZOrderIdMap(void) const
	{
		return GameGeneral::m_nZOrderIdMap;
	}

public:
	// Z-order ids for different objects
	// The number is more higher, more top layer.
	static const int32 m_nZOrderIdMap = 0;
	static const int32 m_nZOrderIdSprite = 1;
	static const int32 m_nZOrderIdUI = 2;
};

#endif /* _GAME_GENERAL_H_ */
