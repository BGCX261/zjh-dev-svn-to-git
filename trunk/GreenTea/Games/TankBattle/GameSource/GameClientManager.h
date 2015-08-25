#ifndef _GAME_CLIENT_MANAGER_H_
#define _GAME_CLIENT_MANAGER_H_

#include <GTGreenTea.h>
#include <GTSingleton.h>
#include <UI/UIWidget.h>

class GameClientManager : GTObject, public GTSingleton<GameClientManager>
{
public:
	GameClientManager();
	~GameClientManager();

	// When the object is initialized, this method is called.
	virtual int32 OnInitialize(void);

	// When the system is updated, this method is called for each frame.
	virtual int32 OnUpdate(void);

	// This method is called for rendering each frame.
	virtual int32 OnRender(void);

	// Before the system is shut down, this method is called.
	virtual int32 OnDestroy(void);

	bool OnBtnExitSingleClick(UIWidget* pWidget, uint32 nFlags, void *pParam);

public:
	bool m_bExiting;
};

#endif /* _GAME_CLIENT_MANAGER_H_ */
