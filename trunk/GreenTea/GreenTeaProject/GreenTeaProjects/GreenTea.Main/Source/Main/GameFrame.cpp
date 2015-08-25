// Main game frame

#include "GameDef.h"
#include "GameFrame.h"
#include <GTLog/GTLogManager.h>
#include "SystemManager.h"
#include "GameManager.h"
#include "SceneManager.h"
#include "MapManager.h"
#include "FXManager.h"
#include "LocalizationManager.h"
#include "UI/UIManager.h"
#include "InputManager.h"
#include "ConfigManager.h"
#include "SceneGameObjectManager.h"
#include "UI/FontManager.h"
#include <GTBehaviourClassManager.h>
#include "UI/UIWidgetClassManager.h"
#include "AudioManager.h"
#include "TimeManager.h"
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
	ConfigManager::GetInstance()->OnInitialize();
	LocalizationManager::GetInstance()->OnInitialize();
	SystemManager::GetInstance()->OnInitialize();
	FontManager::GetInstance()->Initialize();
	UIManager::GetInstance()->OnInitialize();
	MapManager::GetInstance()->OnInitialize();
	FXManager::GetInstance()->OnInitialize();
	SceneManager::GetInstance()->OnInitialize();
	GameManager::GetInstance()->OnInitialize();
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
	UIManager::GetInstance()->OnUpdate();
	FXManager::GetInstance()->OnUpdate();
	MapManager::GetInstance()->OnUpdate();
	SceneManager::GetInstance()->OnUpdate();
	GameManager::GetInstance()->OnUpdate();
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
	GameManager::GetInstance()->OnRender();
#ifdef GT_DEBUG
	TestManager::GetInstance()->OnRender();
#endif /* GT_DEBUG */

	return 1;
}


// Before the system is shut down, this method is called.
int32 GameFrame::OnDestroy(void)
{
	// Destroy the managers
	GameManager::GetInstance()->OnDestroy();
	SceneManager::GetInstance()->OnDestroy();
	MapManager::GetInstance()->OnDestroy();
	FXManager::GetInstance()->OnDestroy();
	UIManager::GetInstance()->OnDestroy();	
	FontManager::GetInstance()->Destroy();
	SystemManager::GetInstance()->OnDestroy();
	LocalizationManager::GetInstance()->OnDestroy();
	ConfigManager::GetInstance()->OnDestroy();
	GTBehaviourClassManager::GetInstance()->Release();
	UIWidgetClassManager::GetInstance()->Release();
#ifdef GT_DEBUG
	TestManager::GetInstance()->OnDestroy();
#endif /* GT_DEBUG */
	AudioManager::GetInstance()->Destroy();
	GTLogManager::GetInstance()->Destroy();
	TimeManager::GetInstance()->OnDestroy();
	
	return 1;
}
