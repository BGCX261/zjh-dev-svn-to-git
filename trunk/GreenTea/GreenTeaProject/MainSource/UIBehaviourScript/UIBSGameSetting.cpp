#include "UIBSGameSetting.h"
#include "../UI/UIWidgetScriptManager.h"
#include <GTLog/GTLogManager.h>
#include "../AudioManager.h"
#include "../UI/UIManager.h"

GTBEHAVIOUR_IMP(UIBSGameSetting, GTBehaviour);

UIBSGameSetting::UIBSGameSetting()
{
}


UIBSGameSetting::~UIBSGameSetting()
{
}


// This method is called when GTBehaviour object is created.
int32 UIBSGameSetting::OnCreate(void)
{
	UIWidgetScript::OnCreate();

	return 1;
}


// This method is called when GTBehaviour object is initialized.
int32 UIBSGameSetting::OnInitialize(GTBehaviourInitParam* param)
{
	UIWidgetScript::OnInitialize(param);

	return 1;
}


int32 UIBSGameSetting::OnStart(void)
{
	UIWidgetScript::OnStart();

	m_pUIProgressBar = (UIProgressBar*)UIManager::GetInstance()->GetRootWidget()->FindChild(CTEXT("ProgressBar_HP"), true);

	return 1;
}


// This method is called when GTBehaviour object is updated.
int32 UIBSGameSetting::OnUpdate(void)
{
	UIWidgetScript::OnUpdate();

	return 1;
}


// This method is called when GTBehaviour object is destroyed.
int32 UIBSGameSetting::OnDestroy(void)
{
	UIWidgetScript::OnDestroy();

	return 1;
}


bool UIBSGameSetting::OnSingleClick(const uint32 nFlags, const GTPoint2& pos)
{
	if(nFlags & UIWidget::Flag_ClickUp)
	{
		//uint32 nSoundEffectId = AudioManager::GetInstance()->PlayEffect(CTEXT("sounds/button_click.mp3"));
		//GTLogManager::GetInstance()->LogComment(CTEXT("UIBSGameSetting: OnSingleClick"));
		if(m_pUIProgressBar)
		{
			m_pUIProgressBar->SetCurrentValue(m_pUIProgressBar->GetCurrentValue() - 1);
		}
	}

	return true;
}


bool UIBSGameSetting::OnDoubleClick(const uint32 nFlags, const GTPoint2& pos)
{
	return true;
}


bool UIBSGameSetting::OnMove(const uint32 nFlags, const GTPoint2& pos, const GTPoint2& delta, bool dragging)
{
	return true;
}


bool UIBSGameSetting::OnStateChange(const uint32 nState)
{
	return true;
}
