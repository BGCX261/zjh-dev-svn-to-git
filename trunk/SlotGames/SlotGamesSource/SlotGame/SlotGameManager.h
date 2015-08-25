#ifndef _SLOT_GAME_MANAGER_H_
#define _SLOT_GAME_MANAGER_H_

#include <GTGreenTea.h>
#include <GTSingleton.h>
#include "GameObjectCreation.h"
#include "ITexture2D.h"
#include "UI/UIFont.h"
#include "ScenePathFinding.h"
#include "../../SlotGame/Player.h"

class SlotGameManager : public GTSingleton<SlotGameManager>
{
public:
	SlotGameManager();
	~SlotGameManager();

	// When the object is initialized, this method is called.
	virtual int32 OnInitialize(void);

	// When the system is updated, this method is called for each frame.
	virtual int32 OnUpdate(void);

	// This method is called for rendering each frame.
	virtual int32 OnRender(void);

	// Before the system is shut down, this method is called.
	virtual int32 OnDestroy(void);

	//get current player;
	Player* GetPlayer()	{ 
		if(m_pPlayer == NULL)
			m_pPlayer = new Player("TestPlayer1");
		return m_pPlayer;
	}
protected:
	Player* m_pPlayer;
};

#endif /* _SLOT_GAME_MANAGER_H_ */
