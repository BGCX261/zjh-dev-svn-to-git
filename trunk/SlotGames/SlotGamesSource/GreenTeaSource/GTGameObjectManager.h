#ifndef _GREENTEA_GAME_OBJECT_MANAGER_H_
#define _GREENTEA_GAME_OBJECT_MANAGER_H_

#include <GTGreenTea.h>

class GTGameObjectManager : public GTSingleton<GTGameObjectManager>
{
public:
	GTGameObjectManager();
	~GTGameObjectManager();

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

	// Initialize a game object with its property file name
	bool InitializeGameObject(GTGameObject *pGameObject, const tchar* szPropertyFileName);
	// Initialize a game object with default behaviour classes
	//bool IntializeGameObjectWithBehaviourScriptFromTreeNode(GTGameObject *pGameObject, GTTreeNode *pTreeNode, void* param);
	bool InitializeGameObjectDefaultBehaviour(GTGameObject *pGameObject, GTTreeNode *pRootTreeNode);
	// Initialize a game object if it's a sprite object
	bool InitializeGameObjectSprite(GTGameObject *pGameObject, GTTreeNode* pRootTreeNode);
	bool InitializeGameObjectBehaviour(GTGameObject *pGameObject, GTTreeNode* pRootTreeNode);
	bool InitializeChildGameObject(GTGameObject *pParentGameObject, GTTreeNode* pParentTreeNode);
	bool InitializeChildrenGameObjects(GTGameObject *pGameObject, GTTreeNode* pRootTreeNode);

	// Create a game object manually
	// All proerties must be manually setup, such as name, position, etc.
	// The game object must be released manually
	GTGameObject* CreateGameObject(GTGameObject* pParent, const tchar* szName);
	// Create a game object from property file
	GTGameObject* CreateGameObject(GTGameObject* pParent, const tchar* szName, const tchar* szPropFile);
	// Clone a game object from another object
	GTGameObject* CloneGameObject(GTGameObject* pParent, GTGameObject* pGameObjectSrc, const tchar* szNewName);
	// Destroy a game object manually
	bool DestroyGameObject(GTGameObject* pGameObject);

	// Static help methods
	static GTGameObject* FindGameObject(const tchar* szName)
	{
		return GTGameObjectManager::GetInstance()->FindGameObjectByName(szName);
	}

private:
	// Game object list
	GTGameObject* m_pRootGameObject;
};

#endif /* _GREENTEA_GAME_OBJECT_MANAGER_H_ */
