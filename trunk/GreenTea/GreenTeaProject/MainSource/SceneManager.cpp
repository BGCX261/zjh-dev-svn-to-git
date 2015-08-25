#include "SceneManager.h"
#include "GameObjectCreation.h"
#include "InputManager.h"
#include "GOS.h"
#include "MapManager.h"
#include <GTLog/GTLogManager.h>
#include "EventNameManager.h"
#include "ScreenManager.h"
#include "PropertyFile.h"
#include "ConfigManager.h"
#include "SceneGameObjectManager.h"
#include "GameGeneral.h"
#include "UI/UIBasedef.h"
#include <BehaviourScript/BSGameObjectGeneral.h>
#include <BehaviourScript/BSSprite.h>
#include "cocos2dx-wrap/SpriteAtlasCocos2dx.h"

USING_NS_CC;

GTSINGLETON_IMP(SceneManager);

// Once the event of single click occurs, this callback method is called.
// point: screen position
int32 SceneManager::OnSingleClickEventDelegate(const uint32 Flags, const GTPoint2 point, void* pParam)
{
	//LogManager::GetInstance()->LogComment(CTEXT("OnSingleClickEventDelegate called"));

	//SceneManager::GetInstance()->SetScreenPositionInMap(point.x, point.y);

	return 0;
}


// Once the event of double click occurs, this callback method is called.
// point: screen position
int32 SceneManager::OnDoubleClickEventDelegate(const uint32 Flags, const GTPoint2 point, void* pParam)
{
	return 0;
}


// Once the event of movement occurs, this callback method is called.
// point: movement
int32 SceneManager::OnMoveEventDelegate(const uint32 Flags, const GTPoint2 point, void* pParam)
{
	/*
	const GTPoint2 screenPosition = SceneManager::GetInstance()->GetScreenPositionInMap();
	SceneManager::GetInstance()->SetScreenPositionInMap(
		screenPosition.x - point.x,
		screenPosition.y - point.y
		);
		*/
	
	return 0;
}


SceneManager::SceneManager():
		m_ScreenPositionInMap(GTPoint2::Zero)
{	
}


SceneManager::~SceneManager()
{
}


// Initialize input event
int32 SceneManager::InitializeInputEvent()
{
	// Register single click event for SceneManager
	if(!InputManager::GetInstance()->RegisterEvent(
		InputManager::EventType_SingleClick,
		EventNameManager::GetInstance()->EventName_SceneManagerSingleClick,
		SceneManager::OnSingleClickEventDelegate,
		this
		))
	{
		GTLogManager::GetInstance()->LogFormatError(
			CTEXT("Failed to call RegisterSingleClickEvent for %s"),
			EventNameManager::GetInstance()->EventName_SceneManagerSingleClick
			);
		return 1;
	}
	// Register double click event for SceneManager
	if(!InputManager::GetInstance()->RegisterEvent(
		InputManager::EventType_DoubleClick,
		EventNameManager::GetInstance()->EventName_SceneManagerDoubleClick,
		SceneManager::OnDoubleClickEventDelegate,
		this
		))
	{
		GTLogManager::GetInstance()->LogFormatError(
			CTEXT("Failed to call RegisterDoubleClickEvent for %s"),
			EventNameManager::GetInstance()->EventName_SceneManagerDoubleClick
			);
		return 1;
	}
	// Register move event for SceneManager
	if(!InputManager::GetInstance()->RegisterEvent(
		InputManager::EventType_Move,
		EventNameManager::GetInstance()->EventName_SceneManagerMove,
		SceneManager::OnMoveEventDelegate,
		this
		))
	{
		GTLogManager::GetInstance()->LogFormatError(
			CTEXT("Failed to call RegisterDoubleClickEvent for %s"),
			EventNameManager::GetInstance()->EventName_SceneManagerMove
			);
		return 1;
	}

	return 1;
}


// Deinitialize input event
int32 SceneManager::DeInitializeInputEvent()
{	
	// Unregister the event of single click
	InputManager::GetInstance()->UnregisterEvent(
		InputManager::EventType_SingleClick,
		EventNameManager::GetInstance()->EventName_SceneManagerSingleClick
		);
	// Unregister the event of double click
	InputManager::GetInstance()->UnregisterEvent(
		InputManager::EventType_DoubleClick,
		EventNameManager::GetInstance()->EventName_SceneManagerDoubleClick
		);
	// Unregister the event of move
	InputManager::GetInstance()->UnregisterEvent(
		InputManager::EventType_Move,
		EventNameManager::GetInstance()->EventName_SceneManagerMove
		);

	return 1;
}


// When the object is initialized, this method is called.
int32 SceneManager::OnInitialize(void)
{
	// Initialize input event
	//InitializeInputEvent();

	SceneGameObjectManager::GetInstance()->OnInitialize();

	//UIManager::GetInstance()->LoadLayout(CTEXT("ui/SampleTest.uilayout"));
	UIManager::GetInstance()->LoadLayout(CTEXT("ui/MainUI.uilayout"));
		
	return 1;
}


// When the system is updated, this method is called for each frame.
int32 SceneManager::OnUpdate(void)
{
	// Update game objects
	UpdateGameObjects();

	return 1;
}


// This method is called for rendering each frame.
int32 SceneManager::OnRender(void)
{
	return 1;
}


// Before the system is shut down, this method is called.
int32 SceneManager::OnDestroy(void)
{
	// Deinitialize game objects
	DeInitializeGameObjects();

	ReleaseScene();

	SceneGameObjectManager::GetInstance()->OnDestroy();

	// Deinitialize input event
	DeInitializeInputEvent();

	return 1;
}


// Load s scene from a file
bool SceneManager::LoadScene(const tchar* sSceneName)
{
	if(NULL == sSceneName)
	{
		return false;
	}

	// Load the map
	if(!MapManager::GetInstance()->LoadMap(sSceneName))
	{
		return false;
	}

	// Setup map size
	cocos2d::CCTMXLayer *pGroundLayer = MapManager::GetInstance()->GetGroundLayer();
	if(NULL == pGroundLayer)
	{
		GTLogManager::GetInstance()->LogError(CTEXT("GroundLayer not found"));
		return false;
	}

	// Initialize game objects in the scene
	if(!IntializeGameObjects())
	{
		GTLogManager::GetInstance()->LogError(CTEXT("Failed to call IntializeGameObjects"));
	}

	// Build up path finding stuff
	
	return true;
}


// Release the scene
void SceneManager::ReleaseScene(void)
{
	MapManager::GetInstance()->ReleaseMap();
}


// Set the screen to the position which in map coordinate system
void SceneManager::SetScreenPositionInMap(const float x, const float y)
{
	// Get map current position
	GTPoint2 mapPosition = MapManager::GetInstance()->GetPosition();
	GTSize mapSizeInPixel = MapManager::GetInstance()->GetMapSizeInPixel();

	const int32 nScreenW = ScreenManager::GetInstance()->GetScreenWidth();
	const int32 nScreenH = ScreenManager::GetInstance()->GetScreenHeight();
	const int32 nRightBorderX = (int32)mapSizeInPixel.width - nScreenW;
	const int32 nRightBorderY = (int32)mapSizeInPixel.height - nScreenH;

	int32 nFinalMapPositionX = (int32)x;
	int32 nFinalMapPositionY = (int32)y;

	if(nFinalMapPositionX < 0)
	{
		nFinalMapPositionX = 0;
	}
	else if(nFinalMapPositionX >= nRightBorderX)
	{
		nFinalMapPositionX = nRightBorderX;
	}
	
	if(nFinalMapPositionY < 0)
	{
		nFinalMapPositionY = 0;
	}
	else if(nFinalMapPositionY >= nRightBorderY)
	{
		nFinalMapPositionY = nRightBorderY;
	}

	m_ScreenPositionInMap.x = (float)nFinalMapPositionX;
	m_ScreenPositionInMap.y = (float)nFinalMapPositionY;

	// Set map position
	MapManager::GetInstance()->SetPosition(-m_ScreenPositionInMap.x, -m_ScreenPositionInMap.y);
}


// Update game objects
bool SceneManager::UpdateGameObjects()
{
	SceneGameObjectManager::GetInstance()->Update();

	return true;
}


// Deinitialize game objects
bool SceneManager::DeInitializeGameObjects()
{
	SceneGameObjectManager::GetInstance()->ReleaseGameObject();

	return true;
}


/*
// Initialize a game object with default behaviour classes
// Apply all scripts under pTreeNode node
bool SceneManager::IntializeGameObjectWithBehaviourScriptFromTreeNode(
	 GTGameObject *pGameObject,
	 GTTreeNode *pTreeNode,
	 void* param
	)
{
	if(NULL == pGameObject || NULL == pTreeNode)
	{
		return false;
	}

	GTBehaviourInitParam initParam;
	// Get the count of behaviour scripts attached to this object
	const int32 nNodeCount = pTreeNode->GetChildCount();
	for(int count=0; count<nNodeCount; count++)
	{
		// Get a node of behaviour script
		GTTreeNode* pChild = pTreeNode->GetChild(count);
		if(pChild)
		{
			if(pChild->Tag() == PropertyFile::TagScript)
			{
				// Prepare the paramters for behaviour initialization
				initParam.pParam1 = param;
				initParam.pParam2 = pChild;

				GTBehaviour *pBehaviour = pGameObject->AddComponent(pChild->GetValue().ToCharString(), &initParam);
				if(NULL == pBehaviour)
				{
					GTLogManager::GetInstance()->LogFormatError(CTEXT("Failed to AddComponent '%s' for the game object '%s'"), pChild->GetValue().ToCharString(), pGameObject->GetName());
				}
			}
		}
	}

	return true;
}
*/


// Initialize a game object if it's a sprite object
bool SceneManager::IntializeGameObjectSprite(GTGameObject *pGameObject, GTTreeNode* pRootTreeNode)
{
	if(NULL == pGameObject || NULL == pRootTreeNode)
	{
		return false;
	}

	// If the property file has image node, this game object is a sprite object.
	GTTreeNode* pNodeImage = pRootTreeNode->FindChild(PropertyFile::TagImage);
	if(NULL == pNodeImage)
	{
		return false;
	}

	GTTreeNode *pTreeNodeGOC = ConfigManager::GetInstance()->GetGameObjectConfig();
	if(NULL == pTreeNodeGOC)
	{
		return false;
	}

	GTTreeNode *pSpriteBehaviourClass = pTreeNodeGOC->FindChild(PropertyFile::TagSpriteBehaviourClass);
	if(NULL == pSpriteBehaviourClass)
	{
		return false;
	}

	// Apply all behaviour scripts under pSpriteBehaviourClass for this game object pGameObject.
	return PropertyFile::ApplyBehaviourForGameObject(pSpriteBehaviourClass, pGameObject, pRootTreeNode);
}


// Initialize behaviour scripts for specified game object pGameObject
bool SceneManager::IntializeGameObjectBehaviour(GTGameObject *pGameObject, GTTreeNode* pRootTreeNode)
{
	if(NULL == pGameObject || NULL == pRootTreeNode)
	{
		return false;
	}

	GTTreeNode* pBehaviourNode = pRootTreeNode->FindChild(PropertyFile::TagBehaviour);
	if(NULL == pBehaviourNode)
	{
		GTLogManager::GetInstance()->LogError(CTEXT("Behaviour node not found"));
		return false;
	}

	// Apply all behaviour scripts under pBehaviourNode for this game object
	return PropertyFile::ApplyBehaviourForGameObject(pBehaviourNode, pGameObject, pRootTreeNode);
}


bool SceneManager::IntializeChildGameObject(GTGameObject *pParentGameObject, GTTreeNode* pParentTreeNode)
{
	if(NULL == pParentGameObject || NULL == pParentTreeNode)
	{
		return false;
	}

	GTTreeNode* pPropertyNameNode = pParentTreeNode->GetChild(PropertyFile::TagPropertyName);
	if(NULL == pPropertyNameNode)
	{
		return false;
	}
	GTTreeNode* pVisibleNode = pParentTreeNode->GetChild(PropertyFile::TagVisible);

	// Create child game object under pParentGameObject
	GTGameObject* pChildGameObject = pParentGameObject->AddChild();
	if(NULL != pChildGameObject)
	{
		if(IntializeGameObject(pChildGameObject, pPropertyNameNode->GetValue().ToCharString()))
		{
			// Set the name
			pChildGameObject->SetName(pParentTreeNode->GetValue().ToCharString());
			// Set the position same as its parent
			pChildGameObject->SetPosition(pParentGameObject->GetPosition());
			// Visible
			if(pVisibleNode)
			{
				pChildGameObject->SetVisible(pVisibleNode->GetValue().AsBool());				
			}
		}
	}
	else
	{
		GTLogManager::GetInstance()->LogError(CTEXT("Failed to pParentGameObject->AddChild()"));
	}

	return true;
}


// Initialize children game objects for specified game object pGameObject
bool SceneManager::IntializeChildrenGameObjects(GTGameObject *pGameObject, GTTreeNode* pRootTreeNode)
{
	if(NULL == pGameObject || NULL == pRootTreeNode)
	{
		return false;
	}

	// Find children node
	GTTreeNode* pChildrenNode = pRootTreeNode->FindChild(PropertyFile::TagChildren);
	if(NULL == pChildrenNode)
	{
		//GTLogManager::GetInstance()->LogError(CTEXT("Children node not found"));
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
		if(pChildNode->GetTag() == PropertyFile::TagGameObject)
		{
			// Initialize this game object
			IntializeChildGameObject(pGameObject, pChildNode);
		}
	}

	return true;
}


// Initialize a game object with default behaviour classes
bool SceneManager::IntializeGameObjectDefaultBehaviour(GTGameObject *pGameObject, GTTreeNode *pRootTreeNode)
{
	if(NULL == pGameObject)
	{
		return false;
	}

	GTTreeNode *pTreeNodeGOC = ConfigManager::GetInstance()->GetGameObjectConfig();
	if(NULL == pTreeNodeGOC)
	{
		return false;
	}

	GTTreeNode *pDefaultBehaviourClass = pTreeNodeGOC->FindChild(PropertyFile::TagDefaultBehaviourClass);
	if(NULL == pDefaultBehaviourClass)
	{
		return false;
	}

	// Apply all behaviour scripts under pDefaultBehaviourClass for this game object pGameObject.
	return PropertyFile::ApplyBehaviourForGameObject(pDefaultBehaviourClass, pGameObject, pRootTreeNode);
}


// Initialize a game object with its property file name
bool SceneManager::IntializeGameObject(GTGameObject *pGameObject, const tchar* szPropertyFileName)
{
	if(NULL == pGameObject || NULL == szPropertyFileName)
	{
		return false;
	}

	// Load property file
	GTTreeNode* pRootTreeNode = PropertyFile::Load(szPropertyFileName);
	if(pRootTreeNode == NULL)
	{
		GTLogManager::GetInstance()->LogFormatError(CTEXT("Failed to load property file: %s"), szPropertyFileName);
		return false;
	}

	// Initialize behaviour scripts
	IntializeGameObjectBehaviour(pGameObject, pRootTreeNode);
	// Initialize children game objects
	IntializeChildrenGameObjects(pGameObject, pRootTreeNode);
	
	if(pRootTreeNode)
	{
		pRootTreeNode->Release();
		pRootTreeNode = NULL;
	}

	return true;
}


// Initialize game objects
bool SceneManager::IntializeGameObjects()
{
	// Get the layer which contains game objects
	cocos2d::CCTMXObjectGroup* pObjectGroup = MapManager::GetInstance()->GetUserObjectLayer();
	if(NULL == pObjectGroup)
	{
		GTLogManager::GetInstance()->LogError(CTEXT("UserObjectLayer not found"));
		return false;
	}

	GTGameObject* pRootGameObject = SceneGameObjectManager::GetInstance()->GetRootGameObject();
	if(NULL == pRootGameObject)
	{
		GTLogManager::GetInstance()->LogError("Scene root game object not found");
		return false;		
	}

	// Query game object set
	cocos2d::CCArray* pObjects = pObjectGroup->getObjects();
	if(pObjects)
	{
		cocos2d::CCDictionary* pContent = NULL;
		cocos2d::CCObject* pObj = NULL;
		CCARRAY_FOREACH(pObjects, pObj)
		{
			pContent = (cocos2d::CCDictionary*)pObj;
			if(pContent)
			{
				GTGameObject *pChild = pRootGameObject->AddChild();
				if(pChild)
				{					
					// Query the name
					cocos2d::CCString *sName = (cocos2d::CCString*)pContent->objectForKey(std::string(PropertyFile::TagNameV1));
					if(sName)
					{
						pChild->SetName(sName->getCString());
					}
					// Query the type
					cocos2d::CCString *sType = (cocos2d::CCString*)pContent->objectForKey(std::string(PropertyFile::TagType));
					// Query the position (x/y)
					cocos2d::CCString *sX = (cocos2d::CCString*)pContent->objectForKey(std::string(PropertyFile::TagX));
					cocos2d::CCString *sY = (cocos2d::CCString*)pContent->objectForKey(std::string(PropertyFile::TagY));
					if(NULL != sX && NULL != sY)
					{
						pChild->SetPosition(sX->floatValue(), sY->floatValue());
					}
					// Query the width/height
					cocos2d::CCString *sWidth = (cocos2d::CCString*)pContent->objectForKey(std::string(PropertyFile::TagWidth));
					cocos2d::CCString *sHeight = (cocos2d::CCString*)pContent->objectForKey(std::string(PropertyFile::TagHeight));
					// Query the property file name
					cocos2d::CCString *sProperty = (cocos2d::CCString*)pContent->objectForKey(std::string(PropertyFile::TagPropertyName));
					if(sProperty)
					{
						// Further intialize the game object from the property file
						IntializeGameObject(pChild, sProperty->getCString());
					}
					else
					{
						GTLogManager::GetInstance()->LogError(CTEXT("PropertyName not found"));
					}
					// Call derived OnInitialize
					pChild->OnInitialize();
				}
			}
		}

		/*
		// Call derived OnStart of each child because all game objects
		// and behaviour scripts have successfully created and initialized.
		GTLIST_FOREACH(GTGameObject*, it, pRootGameObject->m_Children)
		{
			(*it)->OnStart();
		}
		*/
	}

	return true;
}
