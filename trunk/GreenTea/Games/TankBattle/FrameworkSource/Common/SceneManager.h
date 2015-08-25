#ifndef _SCENE_MANAGER_H_
#define _SCENE_MANAGER_H_

#include <GTGameObject.h>
#include <GTSingleton.h>
#include "SceneLayer.h"
#include "ITexture2D.h"
#include "MapManager.h"
#include <GTTreeNode.h>
#include <GTList.h>
#include <GTPoint2.h>
#include <GTSize.h>
#include "Common/SpriteAtlas.h"

class SceneManager : public GTSingleton<SceneManager>
{
public:
	SceneManager();
	~SceneManager();

	// When the object is initialized, this method is called.
	virtual int32 OnInitialize(void);

	// When the system is updated, this method is called for each frame.
	virtual int32 OnUpdate(void);

	// This method is called for rendering each frame.
	virtual int32 OnRender(void);

	// Before the system is shut down, this method is called.
	virtual int32 OnDestroy(void);

	// Initialize input event
	int32 InitializeInputEvent();
	// Deinitialize input event
	int32 DeInitializeInputEvent();	
	// Initialize game objects
	bool IntializeGameObjects();
	// Update game objects
	bool UpdateGameObjects();
	// Deinitialize game objects
	bool DeInitializeGameObjects();
	// Load a scene from a file
	bool LoadScene(const tchar* sSceneName);
	// Release the scene
	void ReleaseScene(void);

	// Set the screen to the position which in map coordinate system
	void SetScreenPositionInMap(const float x, const float y);
	// Get the screen position which in map coordinate system
	GTPoint2 GetScreenPositionInMap(void) const
	{
		return m_ScreenPositionInMap;
	}
		
	// Once the event of single click occurs, this callback method is called.
	// point: screen position
	static int32 OnSingleClickEventDelegate(const uint32 nFlags, const GTPoint2 point, void* pParam);
	// Once the event of double click occurs, this callback method is called.
	// point: screen position
	static int32 OnDoubleClickEventDelegate(const uint32 nFlags, const GTPoint2 point, void* pParam);
	// Once the event of movement occurs, this callback method is called.
	// point: movement
	static int32 OnMoveEventDelegate(const uint32 nFlags, const GTPoint2 point, void* pParam);

public:
	// The position of the screen in the map
	GTPoint2 m_ScreenPositionInMap;
};

#endif /* _SCENE_MANAGER_H_ */
