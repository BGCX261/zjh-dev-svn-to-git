#ifndef _SCENE_GAME_OBJECT_MANAGER_H_
#define _SCENE_GAME_OBJECT_MANAGER_H_

#include <GTGreenTea.h>

class SceneGameObjectManager : public GTSingleton<SceneGameObjectManager>
{
public:
	SceneGameObjectManager();
	~SceneGameObjectManager();

	// Initialization
	int32 InitializeTree(GTTreeNode *pTreeNode, GTGameObject *pParent);
	int32 OnInitialize();
	// Destroy
	int32 OnDestroy();

	// Update all game objects
	int32 Update(void);
	// Release all game objects existing in the scene
	int32 ReleaseGameObject(void);

	// Get root game object
	GTGameObject* GetRootGameObject(void)
	{
		return m_pRootGameObject;
	}

	// Find a game object by its name
	GTGameObject* FindGameObjectByName(const tchar* szName)
	{
		DBG_ASSERT(m_pRootGameObject);
		return m_pRootGameObject->FindChild(szName);
	}

	// Create a game object manually.
	// All proerties must be manually setup, such as name, position, etc.
	// The game object must be released manually.
	GTGameObject* CreateGameObject(GTGameObject* pParent, const tchar* szName);

private:
	// Game object list
	GTGameObject* m_pRootGameObject;
};

#endif /* _SCENE_GAME_OBJECT_MANAGER_H_ */
