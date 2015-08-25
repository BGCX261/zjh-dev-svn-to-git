// Main game frame

#include "GameDef.h"
#include "GameFrame.h"
#include <GTLog/GTLogManager.h>
#include <GTLog/GTLogTextFile.h>
#include "SystemManager.h"
#include "SceneManager.h"
#include "MapManager.h"
#include "FXManager.h"
#include "LocalizationManager.h"
#include "UI/UIManager.h"
#include <GTInputManager.h>
#include <GTConfigManager.h>
#include <GTGameObjectManager.h>
#include <GTCommandManager.h>
#include <GTEventManager.h>
#include "UI/FontManager.h"
#include <GTBehaviourClassManager.h>
#include "UI/UIWidgetClassManager.h"
#include "AudioManager.h"
#include "TimeManager.h"
#include "AssetManager.h"
#include <cocos2dx-wrap/LogObjectCocos2dx.h>
#include <cocos2dx-wrap/LogObjectCocos2dxFile.h>
#include <cocos2dx-wrap/ResourceManager.h>

#ifdef GT_DEBUG
#include "../Test/TestManager.h"
#endif /* GT_DEBUG */

// After the system is initialized, this method is called.
int32 GameFrame::OnInitialize(void)
{
	// Initialize the managers
	TimeManager::GetInstance()->OnInitialize();
	AudioManager::GetInstance()->Initialize();
	GTLogManager::GetInstance()->Initialize();
	// Log object - output to the console
	GTLogManager::GetInstance()->AddLogObject(new LogObjectCocos2dx());
	// Log object - output to the text file
	GTLogManager::GetInstance()->AddLogObject(new LogObjectCocos2dxFile(CTEXT("TB.log")));
	GTConfigManager::GetInstance()->OnInitialize();
	LocalizationManager::GetInstance()->OnInitialize();
	SystemManager::GetInstance()->OnInitialize();
	FontManager::GetInstance()->Initialize();
	AssetManager::GetInstance()->OnInitialize();
	UIManager::GetInstance()->OnInitialize();
	GTEventManager::GetInstance()->OnInitialize();
	GTCommandManager::GetInstance()->OnInitialize();
	MapManager::GetInstance()->OnInitialize();
	FXManager::GetInstance()->OnInitialize();
	SceneManager::GetInstance()->OnInitialize();

#ifdef GT_DEBUG
	TestManager::GetInstance()->OnInitialize();
#endif /* GT_DEBUG */

	return 1;
}


// When the system is running, this method is called for each frame.
int32 GameFrame::OnUpdate(void)
{
	// Update the managers
	TimeManager::GetInstance()->OnUpdate();
	SystemManager::GetInstance()->OnUpdate();
	GTCommandManager::GetInstance()->OnUpdate();
	UIManager::GetInstance()->OnUpdate();
	FXManager::GetInstance()->OnUpdate();
	MapManager::GetInstance()->OnUpdate();
	SceneManager::GetInstance()->OnUpdate();

#ifdef GT_DEBUG
	TestManager::GetInstance()->OnUpdate();
#endif /* GT_DEBUG */

	return 1;
}


// This method is called for rendering each frame.
int32 GameFrame::OnRender(void)
{
	// Render the managers
	SystemManager::GetInstance()->OnRender();
	SceneManager::GetInstance()->OnRender();
	MapManager::GetInstance()->OnRender();
	FXManager::GetInstance()->OnRender();
	UIManager::GetInstance()->OnRender();

#ifdef GT_DEBUG
	TestManager::GetInstance()->OnRender();
#endif /* GT_DEBUG */

	return 1;
}


// Before the system is shut down, this method is called.
int32 GameFrame::OnDestroy(void)
{
#ifdef GT_DEBUG
	TestManager::GetInstance()->OnDestroy();
#endif /* GT_DEBUG */

	// Destroy the managers
	SceneManager::GetInstance()->OnDestroy();
	MapManager::GetInstance()->OnDestroy();
	FXManager::GetInstance()->OnDestroy();
	UIManager::GetInstance()->OnDestroy();
	GTEventManager::GetInstance()->OnDestroy();
	GTCommandManager::GetInstance()->OnDestroy();
	FontManager::GetInstance()->Destroy();
	SystemManager::GetInstance()->OnDestroy();
	LocalizationManager::GetInstance()->OnDestroy();
	GTConfigManager::GetInstance()->OnDestroy();
	GTBehaviourClassManager::GetInstance()->Release();
	UIWidgetClassManager::GetInstance()->Release();
	AssetManager::GetInstance()->OnDestroy();
	ResourceManager::GetInstance()->OnDestroy();
	AudioManager::GetInstance()->Destroy();	
	GTLogManager::GetInstance()->Destroy();
	TimeManager::GetInstance()->OnDestroy();
	
	return 1;
}
