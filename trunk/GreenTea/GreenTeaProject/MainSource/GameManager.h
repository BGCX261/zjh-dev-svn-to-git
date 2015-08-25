#ifndef _GAME_MANAGER_H_
#define _GAME_MANAGER_H_

#include <GTGreenTea.h>
#include <GTSingleton.h>
#include "GameObjectCreation.h"
#include "ITexture2D.h"
#include "UI/UIFont.h"
#include "ScenePathFinding.h"

class GameManager : public GTGameObject, public GTSingleton<GameManager>
{
public:
	GameManager();
	~GameManager();

	// When the object is initialized, this method is called.
	virtual int32 OnInitialize(void);

	// When the system is updated, this method is called for each frame.
	virtual int32 OnUpdate(void);

	// This method is called for rendering each frame.
	virtual int32 OnRender(void);

	// Before the system is shut down, this method is called.
	virtual int32 OnDestroy(void);
};

#endif /* _GAME_MANAGER_H_ */
