#include "SceneGameObjectManager.h"
#include "ConfigManager.h"
#include "PropertyFile.h"

GTSINGLETON_IMP(SceneGameObjectManager);

SceneGameObjectManager::SceneGameObjectManager()
{	
}


SceneGameObjectManager::~SceneGameObjectManager()
{	
}


// Initialization
int32 SceneGameObjectManager::InitializeTree(GTTreeNode *pTreeNode, GTGameObject *pParent)
{
	if(NULL == pTreeNode)
	{
		return 0;
	}

	GTGameObject *pGameObjectNode = new GTGameObject(pParent);
	if(NULL == pGameObjectNode)
	{
		return 0;
	}

	pGameObjectNode->OnInitialize();
	// Setup name
	pGameObjectNode->SetName(pTreeNode->Tag().ToCharString());
	// Setup parent
	pGameObjectNode->SetParent(pParent);
	pParent->AddChild(pGameObjectNode);
	// Initialize behaviour classes
	GTTreeNode *pBehaviour = pTreeNode->GetChild(PropertyFile::TagBehaviour);
	if(pBehaviour)
	{
		PropertyFile::ApplyBehaviourForGameObject(pBehaviour, pGameObjectNode, NULL);
	}

	// Initialize the children
	const int32 nChildCount = pTreeNode->GetChildCount();
	for(int32 i=0; i<nChildCount; i++)
	{
		GTTreeNode *pChild = pTreeNode->GetChild(i);
		if(pChild->GetTag() == PropertyFile::TagBehaviour)
		{
			// Skip behaviour section
			continue;
		}
		InitializeTree(pChild, pGameObjectNode);
	}

	return 1;
}


int32 SceneGameObjectManager::OnInitialize()
{
	GTTreeNode* pGlobalConfig = ConfigManager::GetInstance()->GetGlobalConfig();
	if(pGlobalConfig)
	{
		GTTreeNode* pRootNode = pGlobalConfig->FindChild(CTEXT("SceneGameObjectTree"));
		if(pRootNode)
		{
			// Setup root game object
			m_pRootGameObject = new GTGameObject(NULL);
			if(m_pRootGameObject)
			{
				m_pRootGameObject->OnInitialize();
				// Setup the name
				m_pRootGameObject->SetName(pRootNode->Value().ToCharString());
				// Setup the parent
				m_pRootGameObject->SetParent(NULL);
				// Initialize behaviour classes
				GTTreeNode *pBehaviour = pRootNode->GetChild(PropertyFile::TagBehaviour);
				if(pBehaviour)
				{
					PropertyFile::ApplyBehaviourForGameObject(pBehaviour, m_pRootGameObject, NULL);
				}

				// Initialize the children
				const int32 nChildCount = pRootNode->GetChildCount();
				for(int32 i=0; i<nChildCount; i++)
				{
					GTTreeNode *pChild = pRootNode->GetChild(i);
					if(pChild->GetTag() == PropertyFile::TagBehaviour)
					{
						// Skip behaviour section
						continue;
					}
					InitializeTree(pChild, m_pRootGameObject);
				}
			}
			DBG_ASSERT(m_pRootGameObject);
		}
	}

	return 1;
}


// Destroy
int32 SceneGameObjectManager::OnDestroy()
{
	if(m_pRootGameObject)
	{
		m_pRootGameObject->Release();
		m_pRootGameObject = NULL;
	}

	return 1;
}


// Update all game obejcts
int32 SceneGameObjectManager::Update(void)
{
	// Update root game object
	if(m_pRootGameObject)
	{
		m_pRootGameObject->OnUpdate();
	}

	return 1;
}


// Release all game objects existing in the scene
int32 SceneGameObjectManager::ReleaseGameObject(void)
{
	if(m_pRootGameObject)
	{
		m_pRootGameObject->DestroyChildren();
	}

	return 1;
}


// Create a game object manually.
// All proerties must be manually setup, such as name, position, etc.
// The game object must be released manually.
GTGameObject* SceneGameObjectManager::CreateGameObject(GTGameObject* pParent, const tchar* szName)
{
	// If pParent == null, the parent is root game object
	GTGameObject* pParentFinal = (pParent != NULL) ? pParent : GetRootGameObject();
	if(NULL == pParentFinal)
		return NULL;

	// Create the child
	GTGameObject* pChild = pParentFinal->AddChild();
	if(NULL == pChild)
		return NULL;

	// Set name
	pChild->SetName(szName);
	// Set position
	pChild->SetPosition(100.0f, 100.0f);
	// Set visible
	pChild->SetVisible(true);

	// Create a child
	return pChild;
}
