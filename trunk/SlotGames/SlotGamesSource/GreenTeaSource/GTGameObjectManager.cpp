#include <GTGameObjectManager.h>
#include <GTConfigManager.h>
#include <GTPropertyFile.h>

#ifdef GT_DEBUG
#include <GTNew.h>
#endif // GT_DEBUG

GTSINGLETON_IMP(GTGameObjectManager);

GTGameObjectManager::GTGameObjectManager()
{	
}


GTGameObjectManager::~GTGameObjectManager()
{	
}


// Initialization
int32 GTGameObjectManager::InitializeTree(GTTreeNode *pTreeNode, GTGameObject *pParent)
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
	GTTreeNode *pBehaviour = pTreeNode->GetChild(GTPropertyFile::TagBehaviour);
	if(pBehaviour)
	{
		GTPropertyFile::ApplyBehaviourForGameObject(pBehaviour, pGameObjectNode, NULL);
	}

	// Initialize the children
	const int32 nChildCount = pTreeNode->GetChildCount();
	for(int32 i=0; i<nChildCount; i++)
	{
		GTTreeNode *pChild = pTreeNode->GetChild(i);
		if(pChild->GetTag() == GTPropertyFile::TagBehaviour)
		{
			// Skip behaviour section
			continue;
		}
		InitializeTree(pChild, pGameObjectNode);
	}

	return 1;
}


int32 GTGameObjectManager::OnInitialize()
{
	GTTreeNode* pGlobalConfig = GTConfigManager::GetInstance()->GetGlobalConfig();
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
				GTTreeNode *pBehaviour = pRootNode->GetChild(GTPropertyFile::TagBehaviour);
				if(pBehaviour)
				{
					GTPropertyFile::ApplyBehaviourForGameObject(pBehaviour, m_pRootGameObject, NULL);
				}

				// Initialize the children
				const int32 nChildCount = pRootNode->GetChildCount();
				for(int32 i=0; i<nChildCount; i++)
				{
					GTTreeNode *pChild = pRootNode->GetChild(i);
					if(pChild->GetTag() == GTPropertyFile::TagBehaviour)
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
int32 GTGameObjectManager::OnDestroy()
{
	if(m_pRootGameObject)
	{
		m_pRootGameObject->Release();
		m_pRootGameObject = NULL;
	}

	return 1;
}


// Update all game obejcts
int32 GTGameObjectManager::Update(void)
{
	// Update root game object
	if(m_pRootGameObject)
	{
		m_pRootGameObject->OnUpdate();
	}

	return 1;
}


// Release all game objects existing in the scene
int32 GTGameObjectManager::ReleaseGameObject(void)
{
	if(m_pRootGameObject)
	{
		m_pRootGameObject->DestroyChildren();
	}

	return 1;
}


// Initialize children game objects for specified game object pGameObject
bool GTGameObjectManager::InitializeChildrenGameObjects(GTGameObject *pGameObject, GTTreeNode* pRootTreeNode)
{
	if(NULL == pGameObject || NULL == pRootTreeNode)
	{
		return false;
	}

	// Find children node
	GTTreeNode* pChildrenNode = pRootTreeNode->FindChild(GTPropertyFile::TagChildren);
	if(NULL == pChildrenNode)
	{
		//GTLogManager::GetInstance()->LogError(CTEXT("Children node not found"));
		// No child nodes
		return false;
	}
	// Process each child
	const int32 nChildCount = pChildrenNode->GetChildCount();
	for(int32 i=0; i<nChildCount; i++)
	{
		GTTreeNode* pChildNode = pChildrenNode->GetChild(i);
		if(NULL == pChildNode)
		{
			continue;
		}
		if(pChildNode->GetTag() == GTPropertyFile::TagGameObject)
		{
			// Initialize this game object
			InitializeChildGameObject(pGameObject, pChildNode);
		}
	}

	return true;
}


// Initialize a child game object
bool GTGameObjectManager::InitializeChildGameObject(GTGameObject *pParentGameObject, GTTreeNode* pParentTreeNode)
{
	if(NULL == pParentGameObject || NULL == pParentTreeNode)
	{
		return false;
	}

	// PropertyName
	GTTreeNode* pPropertyNameNode = pParentTreeNode->GetChild(GTPropertyFile::TagPropertyName);
	// Behaviour
	GTTreeNode* pBehaviourNode = pParentTreeNode->GetChild(GTPropertyFile::TagBehaviour);
	// Children
	GTTreeNode* pChildrenNode = pParentTreeNode->GetChild(GTPropertyFile::TagChildren);
	// Visible
	GTTreeNode* pVisibleNode = pParentTreeNode->GetChild(GTPropertyFile::TagVisible);
	// Position
	GTTreeNode* pPositionNode = pParentTreeNode->GetChild(GTPropertyFile::TagPosition);
	// ZOrder
	GTTreeNode* pZOrderNode = pParentTreeNode->GetChild(GTPropertyFile::TagZOrder);
	
	// Create child game object under pParentGameObject
	GTGameObject* pChildGameObject = pParentGameObject->AddChild();
	if(NULL != pChildGameObject)
	{
		// Initialize properties
		// Set the name
		pChildGameObject->SetName(pParentTreeNode->GetValue().ToCharString());
		// Set the position same as its parent
		pChildGameObject->SetPosition(pParentGameObject->GetPosition());
		// Visible
		if(pVisibleNode)
			pChildGameObject->SetVisible(pVisibleNode->GetValue().AsBool());		
		// Position
		if(pPositionNode)
			pChildGameObject->SetPosition(pPositionNode->ValueToVector2());
		// ZOrder
		if(pZOrderNode)
			pChildGameObject->SetZOrder(pZOrderNode->Value().AsInt());

		// Initialize this game object
		// If this game object has property file, initialize it.
		// Meanwhile ignores Behaviour and Children nodes
		if(pPropertyNameNode)
		{
			if(InitializeGameObject(pChildGameObject, pPropertyNameNode->GetValue().ToCharString()))
			{
			}
		}
		else
		{
			// InitializeGameObjectBehaviour
			if(pBehaviourNode)
				InitializeGameObjectBehaviour(pChildGameObject, pParentTreeNode);
			// InitializeChildrenGameObjects
			if(pChildrenNode)
				InitializeChildrenGameObjects(pChildGameObject, pParentTreeNode);
		}
	}
	else
	{
		GTLogManager::GetInstance()->LogError(CTEXT("Failed to pParentGameObject->AddChild()"));
	}

	return true;
}


// Initialize behaviour scripts for specified game object pGameObject
bool GTGameObjectManager::InitializeGameObjectBehaviour(GTGameObject *pGameObject, GTTreeNode* pRootTreeNode)
{
	if(NULL == pGameObject || NULL == pRootTreeNode)
	{
		return false;
	}

	GTTreeNode* pBehaviourNode = pRootTreeNode->FindChild(GTPropertyFile::TagBehaviour);
	if(NULL == pBehaviourNode)
	{
		//GTLogManager::GetInstance()->LogError(CTEXT("Behaviour node not found"));
		return false;
	}

	// Apply all behaviour scripts under pBehaviourNode for this game object
	return GTPropertyFile::ApplyBehaviourForGameObject(pBehaviourNode, pGameObject, pRootTreeNode);
}


// Initialize a game object if it's a sprite object
bool GTGameObjectManager::InitializeGameObjectSprite(GTGameObject *pGameObject, GTTreeNode* pRootTreeNode)
{
	if(NULL == pGameObject || NULL == pRootTreeNode)
	{
		return false;
	}

	// If the property file has image node, this game object is a sprite object.
	GTTreeNode* pNodeImage = pRootTreeNode->FindChild(GTPropertyFile::TagImage);
	if(NULL == pNodeImage)
	{
		return false;
	}

	GTTreeNode *pTreeNodeGOC = GTConfigManager::GetInstance()->GetGameObjectConfig();
	if(NULL == pTreeNodeGOC)
	{
		return false;
	}

	GTTreeNode *pSpriteBehaviourClass = pTreeNodeGOC->FindChild(GTPropertyFile::TagSpriteBehaviourClass);
	if(NULL == pSpriteBehaviourClass)
	{
		return false;
	}

	// Apply all behaviour scripts under pSpriteBehaviourClass for this game object pGameObject.
	return GTPropertyFile::ApplyBehaviourForGameObject(pSpriteBehaviourClass, pGameObject, pRootTreeNode);
}


// Initialize a game object with default behaviour classes
bool GTGameObjectManager::InitializeGameObjectDefaultBehaviour(GTGameObject *pGameObject, GTTreeNode *pRootTreeNode)
{
	if(NULL == pGameObject)
	{
		return false;
	}

	GTTreeNode *pTreeNodeGOC = GTConfigManager::GetInstance()->GetGameObjectConfig();
	if(NULL == pTreeNodeGOC)
	{
		return false;
	}

	GTTreeNode *pDefaultBehaviourClass = pTreeNodeGOC->FindChild(GTPropertyFile::TagDefaultBehaviourClass);
	if(NULL == pDefaultBehaviourClass)
	{
		return false;
	}

	// Apply all behaviour scripts under pDefaultBehaviourClass for this game object pGameObject.
	return GTPropertyFile::ApplyBehaviourForGameObject(pDefaultBehaviourClass, pGameObject, pRootTreeNode);
}


// Initialize a game object with its property file name
//
// pGameObject - An instance of GTGameObject
// szPropertyFileName - Property file name, such as sprites/player.property
bool GTGameObjectManager::InitializeGameObject(GTGameObject *pGameObject, const tchar* szPropertyFileName)
{
	if(NULL == pGameObject || NULL == szPropertyFileName)
		return false;

	// Load property file
	GTTreeNode* pRootTreeNode = GTPropertyFile::Load(szPropertyFileName);
	if(pRootTreeNode == NULL)
	{
		GTLogManager::GetInstance()->LogFormatError(CTEXT("Failed to load property file: %s"), szPropertyFileName);
		return false;
	}

	// Name
	GTTreeNode* pNodeName = pRootTreeNode->FindChild(GTPropertyFile::TagNameV2);
	if(pNodeName)
		pGameObject->SetName(pNodeName->GetValue().ToCharString());
	// Position
	GTTreeNode* pNodePos = pRootTreeNode->FindChild(GTPropertyFile::TagPosition);
	if(pNodePos)
		pGameObject->SetPosition(pNodePos->ValueToVector2());
	// Size
	GTTreeNode* pNodeSize = pRootTreeNode->FindChild(GTPropertyFile::TagSize);
	if(pNodeSize)
	{
	}
	// ZOrder
	GTTreeNode* pNodeZOrder = pRootTreeNode->FindChild(GTPropertyFile::TagZOrder);
	if(pNodeZOrder)
		pGameObject->SetZOrder(pNodeZOrder->ValueToInt());

	// Initialize behaviour scripts
	InitializeGameObjectBehaviour(pGameObject, pRootTreeNode);
	// Initialize children game objects
	InitializeChildrenGameObjects(pGameObject, pRootTreeNode);
			
	if(pRootTreeNode)
	{
		pRootTreeNode->Release();
		pRootTreeNode = NULL;
	}

	return true;
}


// Create a game object manually.
// All properties must be manually setup, such as name, position, etc.
// The game object must be released manually.
GTGameObject* GTGameObjectManager::CreateGameObject(GTGameObject* pParent, const tchar* szName)
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
	pChild->SetPosition(0.0f, 0.0f);
	// Set visible
	pChild->SetVisible(true);

	// Create a child
	return pChild;
}


// Create a game object from property file
GTGameObject* GTGameObjectManager::CreateGameObject(
	GTGameObject* pParent,
	const tchar* szName,
	const tchar* szPropFile)
{
	if(NULL == szName || NULL == szPropFile)
		return NULL;

	// Create new game object
	GTGameObject* pNewChild = CreateGameObject(pParent, szName);
	if(pNewChild)
	{
		// Initialize this game object from a property file
		if(false == InitializeGameObject(pNewChild, szPropFile))
			GTLogManager::Inst()->LogFormatError(CTEXT("CreateGameObject: Failed to create game object (%s) with property file (%s)"), szName, szPropFile);
		else
		{
			// Set the name
			pNewChild->SetName(szName);
			// Call update once
			pNewChild->OnUpdate();
		}
	}

	return pNewChild;
}


// Destroy a game object manually
bool GTGameObjectManager::DestroyGameObject(GTGameObject* pGameObject)
{
	if(NULL == pGameObject)
		return false;

	// If pParent == null, the parent is root game object
	GTGameObject* pParent = pGameObject->GetParent();
	GTGameObject* pParentFinal = (pParent != NULL) ? pParent : GetRootGameObject();
	if(NULL == pParentFinal)
	{
		// All game objects created by users must have a parent,
		// otherwise there might be something wrong.
		return false;
	}

	// Find this game object for double confirmation
	// The name cannot be used for looking for this child because
	// if some children have same name, a wrong game object might be relased.
	/*
	GTGameObject* pChildConfrimed = pParentFinal->FindChild(pGameObject->GetName());
	if(NULL == pChildConfrimed)
		return false;
		*/
	GTGameObject* pChildConfrimed = NULL;
	GTLIST_FOREACH(GTGameObject*, it, pParentFinal->m_Children)
	{
		if(pGameObject == (*it))
		{
			pChildConfrimed = (*it);
			break;
		}
	}

	// Remove the child from its parent
	pParentFinal->RemoveChild(pChildConfrimed);
	// Release children
	pChildConfrimed->DestroyChildren();
	// Release
	pChildConfrimed->Release();

	return true;
}


// Clone a game object from another object
GTGameObject* GTGameObjectManager::CloneGameObject(
	GTGameObject* pParent,
	GTGameObject* pGameObjectSrc,
	const tchar* szNewName
	)
{
	if(NULL == pGameObjectSrc || NULL == szNewName)
		return NULL;

	// Create new child and attach the child to its parent
	GTGameObject* pNewChild = CreateGameObject(pParent, szNewName);
	if(NULL == pNewChild)
		return NULL;

	pNewChild->Copy(pGameObjectSrc);
	pNewChild->SetName(szNewName);
	
	return pNewChild;
}
