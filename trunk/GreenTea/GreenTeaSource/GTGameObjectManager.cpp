#include <GTGameObjectManager.h>
#include <GTConfigManager.h>
#include <GTPropertyFile.h>
#include <GTGameObjectClassManager.h>

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
		return 0;

	GTGameObject *pGameObjectNode = new GTGameObject(pParent);
	if(NULL == pGameObjectNode)
		return 0;

	pGameObjectNode->OnInitialize(NULL);
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
				m_pRootGameObject->OnInitialize(NULL);
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
		return false;

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
		// Initialize this game object
		InitializeChildGameObject(pGameObject, pChildNode);
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
	GTGameObject* pChildGameObject = CreateGameObjectByClassName(
		pParentGameObject,
		pParentTreeNode->GetValue().ToCharString(),
		pParentTreeNode->GetTag().ToCharString()
		);
	if(NULL != pChildGameObject)
	{
		// Initialize properties
		// Set the name
		pChildGameObject->SetName(pParentTreeNode->GetValue().ToCharString());
		// Set the position same as its parent
		pChildGameObject->SetPosition(pParentGameObject->GetPosition());
		// Visible
		if(pVisibleNode)
			pChildGameObject->SetVisible(pVisibleNode->GetValue().AsBool(), true);		
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
			// A .property file is specified so load it
			GTTreeNode* pLocalRootTreeNode = GTPropertyFile::Load(pPropertyNameNode->GetValue().ToCharString());
			if(pLocalRootTreeNode)
			{
				// Set the name again in case the name is reset by InitializeGameObjectFromTreeNode
				pChildGameObject->SetName(pParentTreeNode->GetValue().ToCharString());
				// Parameters for OnInitialize
				GTGameObjectInit initParam;
				initParam.pParam1 = pLocalRootTreeNode;
				initParam.pParam2 = NULL;
				// Call derived OnInitialize before initializing behaviours & child game objects
				pChildGameObject->OnInitialize(&initParam);
				// ZOrder
				if(pZOrderNode)
					pChildGameObject->SetZOrder(pZOrderNode->Value().AsInt());
				// Initialize this game game from a tree node
				InitializeGameObjectFromTreeNode(pChildGameObject, pLocalRootTreeNode, pParentTreeNode->GetValue().ToCharString());
				// Set the name again in case the name is reset by InitializeGameObjectFromTreeNode
				pChildGameObject->SetName(pParentTreeNode->GetValue().ToCharString());
				// Release property file
				if(pLocalRootTreeNode)
				{
					pLocalRootTreeNode->Release();
					pLocalRootTreeNode = NULL;
				}
			}
			else
			{
				GTLogManager::GetInstance()->LogFormatError(CTEXT("InitializeChildGameObject: Failed to load property file: %s"), pPropertyNameNode->GetValue().ToCharString());
			}
			/*	
			if(InitializeGameObjectFromPropertyFile(pChildGameObject, pPropertyNameNode->GetValue().ToCharString()))
			{
			}
			*/
		}
		else
		{
			// Parameters for OnInitialize
			GTGameObjectInit initParam;
			initParam.pParam1 = pParentTreeNode;
			initParam.pParam2 = NULL;
			// Call derived OnInitialize
			pChildGameObject->OnInitialize(&initParam);

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
		return false;

	// If the property file has image node, this game object is a sprite object.
	GTTreeNode* pNodeImage = pRootTreeNode->FindChild(GTPropertyFile::TagImage);
	if(NULL == pNodeImage)
		return false;

	GTTreeNode *pTreeNodeGOC = GTConfigManager::GetInstance()->GetGameObjectConfig();
	if(NULL == pTreeNodeGOC)
		return false;

	GTTreeNode *pSpriteBehaviourClass = pTreeNodeGOC->FindChild(GTPropertyFile::TagSpriteBehaviourClass);
	if(NULL == pSpriteBehaviourClass)
		return false;

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


// Initialize a game object with a GTTreeNode
bool GTGameObjectManager::InitializeGameObjectFromTreeNode(
	GTGameObject *pGameObject,
	GTTreeNode* pTreeNode,
	const tchar* szObjectName
	)
{
	if(NULL == pGameObject || NULL == pTreeNode)
		return false;

	// Name
	if(pTreeNode->GetValue() == GTString::EmptyString)
		pGameObject->SetName(CTEXT("go-no-name"));
	else
		pGameObject->SetName(pTreeNode->GetValue().ToCharString());
	if(szObjectName)
		pGameObject->SetName(szObjectName);
	/*
	GTTreeNode* pNodeName = pTreeNode->FindChild(GTPropertyFile::TagNameV2);
	if(pNodeName)
		pGameObject->SetName(pNodeName->GetValue().ToCharString());
		*/
	// Position
	GTTreeNode* pNodePos = pTreeNode->FindChild(GTPropertyFile::TagPosition);
	if(pNodePos)
		pGameObject->SetPosition(pNodePos->ValueToVector2());
	// Size
	GTTreeNode* pNodeSize = pTreeNode->FindChild(GTPropertyFile::TagSize);
	if(pNodeSize)
	{
	}
	// ZOrder
	GTTreeNode* pNodeZOrder = pTreeNode->FindChild(GTPropertyFile::TagZOrder);
	if(pNodeZOrder)
		pGameObject->SetZOrder(pNodeZOrder->ValueToInt());

	// Initialize behaviour scripts
	InitializeGameObjectBehaviour(pGameObject, pTreeNode);
	// Initialize children game objects
	InitializeChildrenGameObjects(pGameObject, pTreeNode);

	return true;
}


// Initialize a game object with its property file name
//
// pGameObject - An instance of GTGameObject
// szPropertyFileName - Property file name, such as sprites/player.property
bool GTGameObjectManager::InitializeGameObjectFromPropertyFile(GTGameObject *pGameObject, const tchar* szPropertyFileName)
{
	if(NULL == pGameObject || NULL == szPropertyFileName)
		return false;

	bool result = false;

	// Load property file
	GTTreeNode* pRootTreeNode = GTPropertyFile::Load(szPropertyFileName);
	if(pRootTreeNode == NULL)
	{
		GTLogManager::GetInstance()->LogFormatError(CTEXT("Failed to load property file: %s"), szPropertyFileName);
		return false;
	}

	// Initialize this game from a tree node
	result = InitializeGameObjectFromTreeNode(pGameObject, pRootTreeNode, NULL);

	// Release property file
	if(pRootTreeNode)
	{
		pRootTreeNode->Release();
		pRootTreeNode = NULL;
	}

	return result;
}


// Create a game object manually.
//
// All properties must be manually setup, such as name, position, etc.
// The game object must be released manually.
GTGameObject* GTGameObjectManager::CreateGameObjectByClassName(
	GTGameObject* pParent,
	const tchar* szName,
	const tchar* szClassName
	)
{
	static tchar* szGTGameObject = CTEXT("GTGameObject");
	static tchar* szGameObject = CTEXT("GameObject");

	// If pParent == null, the parent is root game object
	GTGameObject* pParentFinal = (pParent != NULL) ? pParent : GetRootGameObject();
	if(NULL == pParentFinal)
		return NULL;

	GTGameObject* pChild = NULL;
	if(GTString::IsEqual(szClassName, szGTGameObject) ||
	   GTString::IsEqual(szClassName, szGameObject))
	{
		// Default GTGameObject
		// Create the child
		pChild = pParentFinal->AddChild();
		if(NULL == pChild)
			return NULL;
	}
	else
	{
		// Customized game object
		pChild = GTGameObjectClassManager::GetInstance()->CreateClassInstance(szClassName);
		if(NULL == pChild)
		{
			GTLogManager::Inst()->LogFormatError(CTEXT("CreateGameObjectByClassName: Failed to create game object (%s) with class name (%s)"), szName, szClassName);
			return NULL;
		}
		// Add this game object to the parent
		pParentFinal->AddChild(pChild);
	}		

	if(pChild)
	{		
		// Set name
		pChild->SetName(szName);
		// Set position
		pChild->SetPosition(0.0f, 0.0f);
		// Set visible
		pChild->SetVisible(true, true);
		// Call derived OnCreate
		pChild->OnCreate();
	}

	// Create a child
	return pChild;
}


// Create a game object from property file
GTGameObject* GTGameObjectManager::CreateGameObject(
	GTGameObject* pParent,
	const tchar* szName,
	const tchar* szPropFile
	)
{
	if(NULL == szName || NULL == szPropFile)
		return NULL;

	// Load property file
	GTTreeNode* pRootTreeNode = GTPropertyFile::Load(szPropFile);
	if(pRootTreeNode == NULL)
	{
		GTLogManager::GetInstance()->LogFormatError(CTEXT("Failed to load property file: %s"), szPropFile);
		return false;
	}

	// Parameters for OnInitialize
	GTGameObjectInit initParam;
	initParam.pParam1 = pRootTreeNode;
	initParam.pParam2 = NULL;
	// Create new game object
	GTGameObject* pNewChild = CreateGameObjectByClassName(pParent, szName, pRootTreeNode->GetTag().ToCharString());
	if(pNewChild)
	{
		// Set the name specified in property file
		pNewChild->SetName(pRootTreeNode->GetValue().ToCharString());
		// Call derived OnInitialize before initializing behaviours & child game objects
		pNewChild->OnInitialize(&initParam);
		// Initialize this game object from a property file
		if(false == InitializeGameObjectFromTreeNode(pNewChild, pRootTreeNode, NULL))
			GTLogManager::Inst()->LogFormatError(CTEXT("CreateGameObject: Failed to create game object (%s) with property file (%s)"), szName, szPropFile);
		else
		{
			// Set the name if new name specified (overrides the name specified in property file)
			pNewChild->SetName(szName);			
			// Call update once
			//pNewChild->OnUpdate();
		}
	}

	// Release property file
	if(pRootTreeNode)
	{
		pRootTreeNode->Release();
		pRootTreeNode = NULL;
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
	GTGameObject* pNewChild = CreateGameObjectByClassName(pParent, szNewName, pGameObjectSrc->GetClassName());
	if(NULL == pNewChild)
		return NULL;

	pNewChild->Copy(pGameObjectSrc);
	pNewChild->SetName(szNewName);
	pNewChild->SetZOrder(pGameObjectSrc->GetZOrder());
	
	return pNewChild;
}
