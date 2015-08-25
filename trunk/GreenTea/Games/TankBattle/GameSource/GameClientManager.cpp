#include "GameClientManager.h"
#include "SceneManager.h"
#include <GTLog/GTLogManager.h>
#include "UI/UIWidget.h"
#include "UI/UIManager.h"
#include "UI/FontManager.h"
#include "SystemManager.h"
#include "MapManager.h"
#include "WeaponCacheManager.h"
#include <stdio.h>

GTSINGLETON_IMP(GameClientManager);

GameClientManager::GameClientManager() :
	m_bExiting(false)
{
}

	
GameClientManager::~GameClientManager()
{
}


// When the object is initialized, this method is called.
int32 GameClientManager::OnInitialize(void)
{
	// Initialize weapon stuff
	WeaponCacheManager::Inst()->OnInitialize();
		
	// Load UI
	UIWidget* pWidget = NULL;
	//UIManager::GetInstance()->LoadLayout(CTEXT("ui/SampleTest.uilayout"));
	pWidget = UIManager::Inst()->LoadLayout(CTEXT("ui/MainUI.uilayout"));
	//pWidget = UIManager::GetInstance()->LoadLayout(CTEXT("SlotGame/UI/infobar.uilayout"));
	if(pWidget)
	{
		UIWidget* pFrame = NULL;
		UIWidget* pButtonExit = NULL;
		pFrame = UIManager::Inst()->GetRootWidget()->FindChildById<UIWidget>(100);
		if(pFrame)
			pButtonExit = pFrame->FindChildById<UIWidget>(1110);
		if(pButtonExit)
			pButtonExit->AddEventListener(
				UIWidgetEvent::EventTypeSingleClick,
				CTEXT("btnExitClick"),
				this,
				UIWidget_EventCallback_Set(GameClientManager::OnBtnExitSingleClick),
				NULL);

	}
	else
	{
		GTLogManager::SLogFormatError("Failed to load uilayout file !");
	}
	//pWidget = UIManager::GetInstance()->LoadLayout(CTEXT("ui/devtest/devtest.uilayout"));

	// Load item layout
	UIWidget *pItemLayout = UIManager::Inst()->LoadLayout(CTEXT("ui/item-layout.uilayout"));
	
	// Load the stage
	SceneManager::Inst()->LoadScene(CTEXT("stages/stage-test-01.tmx"));
	//SceneManager::Inst()->LoadScene(CTEXT("maps/Stage06_map_editor.tmx"));
	SceneManager::Inst()->SetScreenPositionInMap(0, 0);

	return 1;
}


// When the system is updated, this method is called for each frame.
int32 GameClientManager::OnUpdate(void)
{	
	return 1;
}


// This method is called for rendering each frame.
int32 GameClientManager::OnRender(void)
{
	return 1;
}


// Before the system is shut down, this method is called.
int32 GameClientManager::OnDestroy(void)
{
	// Release SceneManager object
	SceneManager::Inst()->ReleaseScene();
	//
	WeaponCacheManager::Inst()->OnDestroy();

	return 1;
}


bool GameClientManager::OnBtnExitSingleClick(UIWidget* pWidget, uint32 nFlags, void *pParam)
{
	if(nFlags & UIWidget::Flag_ClickUp)
	{
		m_bExiting = true;
	}
	
	return true;
}
