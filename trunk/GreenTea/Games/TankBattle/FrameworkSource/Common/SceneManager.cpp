#include "SceneManager.h"
#include "GameObjectCreation.h"
#include <GTInputManager.h>
#include "GOS.h"
#include "MapManager.h"
#include <GTLog/GTLogManager.h>
#include "EventNameManager.h"
#include "ScreenManager.h"
#include <GTPropertyFile.h>
#include <GTConfigManager.h>
#include <GTGameObjectManager.h>
#include "GameGeneral.h"
#include <BehaviourScript/BSGameObjectGeneral.h>
#include <BehaviourScript/BSSprite.h>
#include <cocos2dx-wrap/SpriteAtlasCocos2dx.h>

USING_NS_CC;

GTSINGLETON_IMP(SceneManager);

static const tchar* g_szBSMainEntry = CTEXT("BSMainEntry");

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
	if(!GTInputManager::GetInstance()->RegisterEvent(
		GTInputManager::EventType_SingleClick,
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
	if(!GTInputManager::GetInstance()->RegisterEvent(
		GTInputManager::EventType_DoubleClick,
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
	if(!GTInputManager::GetInstance()->RegisterEvent(
		GTInputManager::EventType_Move,
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
	GTInputManager::GetInstance()->UnregisterEvent(
		GTInputManager::EventType_SingleClick,
		EventNameManager::GetInstance()->EventName_SceneManagerSingleClick
		);
	// Unregister the event of double click
	GTInputManager::GetInstance()->UnregisterEvent(
		GTInputManager::EventType_DoubleClick,
		EventNameManager::GetInstance()->EventName_SceneManagerDoubleClick
		);
	// Unregister the event of move
	GTInputManager::GetInstance()->UnregisterEvent(
		GTInputManager::EventType_Move,
		EventNameManager::GetInstance()->EventName_SceneManagerMove
		);

	return 1;
}


// When the object is initialized, this method is called.
int32 SceneManager::OnInitialize(void)
{
	// Initialize input event
	//InitializeInputEvent();

	GTGameObjectManager::Inst()->OnInitialize();
	// Create a default game object for BSMainEntry
	// BSMainEntry behaviour must be implemented by the client for main entry
	GTGameObject* pRootGameObject = GTGameObjectManager::Inst()->GetRootGameObject();
	DBG_ASSERT(pRootGameObject);
	GTGameObject* pMainEntryGameObject = pRootGameObject->AddChild(g_szBSMainEntry);
	if(NULL == pMainEntryGameObject)
	{
		// Failed to create the game object
		GTLogManager::SLogError(CTEXT("Failed to create BSMainEntry game object."));
		return 0;
	}
	// Add BSMainEntry behaviour
	GTBehaviour* pBSMainEntry = pMainEntryGameObject->AddBehaviour(g_szBSMainEntry);
	if(NULL == pBSMainEntry)
	{
		GTLogManager::SLogError(CTEXT("Failed to add BSMainEntry behaviour."));
		return 0;
	}
		
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
	// Destroy BSMainEntry game object first
	GTGameObject* pRootGameObject = GTGameObjectManager::Inst()->GetRootGameObject();
	DBG_ASSERT(pRootGameObject);
	GTGameObject* pGameObjectMainEntry = pRootGameObject->FindChild(g_szBSMainEntry);	
	if(pGameObjectMainEntry)
	{
		// Release BSMainEntry game object
		pGameObjectMainEntry->Release();
		pGameObjectMainEntry = NULL;
	}
	else
	{
		GTLogManager::SLogError(CTEXT("SceneManager::OnDestroy: Failed to find game object BSMainEntry"));
	}
	
	// Release all game objects
	DeInitializeGameObjects();

	ReleaseScene();

	GTGameObjectManager::GetInstance()->OnDestroy();

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
	else
	{
		GTLogManager::SLogTrace(CTEXT("GroundLayer found"));
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
	// Get screen size
	const int32 nScreenW = ScreenManager::GetInstance()->GetScreenWidth();
	const int32 nScreenH = ScreenManager::GetInstance()->GetScreenHeight();

	if(mapSizeInPixel.width <= nScreenW || mapSizeInPixel.height <= nScreenH)
	{
		// If map size is less that screen, ignore further calculation.
		MapManager::GetInstance()->SetPosition(x, y);
		return;
	}

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
	GTGameObjectManager::GetInstance()->Update();

	return true;
}


// Deinitialize game objects
bool SceneManager::DeInitializeGameObjects()
{
	GTGameObjectManager::GetInstance()->ReleaseGameObject();

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
			if(pChild->Tag() == GTPropertyFile::TagScript)
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


// Initialize game objects
bool SceneManager::IntializeGameObjects()
{
	// Get the layer which contains game objects
	cocos2d::CCTMXObjectGroup* pObjectGroup = MapManager::GetInstance()->GetUserObjectLayer();
	if(NULL == pObjectGroup)
	{
		GTLogManager::GetInstance()->LogError(CTEXT("IntializeGameObjects: UserObjectLayer not found"));
		return false;
	}

	// Get root object in the scene
	GTGameObject* pRootGameObject = GTGameObjectManager::GetInstance()->GetRootGameObject();
	if(NULL == pRootGameObject)
	{
		GTLogManager::GetInstance()->LogError("IntializeGameObjects: Scene root game object not found");
		return false;		
	}

	// Get user's game object list in the map
	cocos2d::CCArray* pObjects = pObjectGroup->getObjects();
	if(pObjects)
	{
		cocos2d::CCDictionary* pContent = NULL;
		cocos2d::CCObject* pObj = NULL;
		// Foreach game object
		CCARRAY_FOREACH(pObjects, pObj)
		{
			pContent = (cocos2d::CCDictionary*)pObj;
			if(pContent)
			{
				// Query the name
				cocos2d::CCString *sName = (cocos2d::CCString*)pContent->objectForKey(std::string(GTPropertyFile::TagNameV1));
				GTString strName = sName ? GTString(sName->getCString()) : CTEXT("tmx-go-no-name");
				// Query the property file name
				cocos2d::CCString *sProperty = (cocos2d::CCString*)pContent->objectForKey(std::string(GTPropertyFile::TagPropertyName));				

				GTGameObject* pChildGameObject = NULL;
				// 1.If the game object has .property file, then create it with the file.
				// 2.If the game object doesn't, create it as normal game object.
				if(sProperty)
				{
					// This game object has .property file, create it with .property file
					pChildGameObject = GTGameObjectManager::Inst()->CreateGameObject(
						pRootGameObject,
						strName.ToCharString(),
						sProperty->getCString()
						);
					if(NULL == pChildGameObject)
					{
						GTLogManager::GetInstance()->LogFormatError(
							CTEXT("IntializeGameObjects: Failed to create game object (%s), property file = %s"),
							strName.ToCharString(), sProperty->getCString());
						// Next game object
						continue;
					}					
				}
				else
				{
					// This game object doesn't have .property file, create it as normal game object.
					pChildGameObject = pRootGameObject->AddChild();
					if(NULL == pChildGameObject)
					{
						GTLogManager::GetInstance()->LogFormatError(
							CTEXT("IntializeGameObjects: Failed to create game object (%s)"),
							strName.ToCharString(), sProperty->getCString());
						// Next game object
						continue;
					}
				}
				// Setup the name
				pChildGameObject->SetName(strName.ToCharString());

				// Query the type
				cocos2d::CCString *sType = (cocos2d::CCString*)pContent->objectForKey(std::string(GTPropertyFile::TagTypeV1));
				// Query the position (x/y)
				cocos2d::CCString *sX = (cocos2d::CCString*)pContent->objectForKey(std::string(GTPropertyFile::TagX));
				cocos2d::CCString *sY = (cocos2d::CCString*)pContent->objectForKey(std::string(GTPropertyFile::TagY));
				if(NULL != sX && NULL != sY)
					pChildGameObject->SetPosition(sX->floatValue(), sY->floatValue());
				// Query the width/height
				cocos2d::CCString *sWidth = (cocos2d::CCString*)pContent->objectForKey(std::string(GTPropertyFile::TagWidth));
				cocos2d::CCString *sHeight = (cocos2d::CCString*)pContent->objectForKey(std::string(GTPropertyFile::TagHeight));
				// Query Z-order
				cocos2d::CCString *sZOrder = (cocos2d::CCString*)pContent->objectForKey(std::string(GTPropertyFile::TagZOrder));
				if(NULL != sZOrder)
					pChildGameObject->SetZOrder(sZOrder->intValue());
			}
		}
	}

	return true;
}
