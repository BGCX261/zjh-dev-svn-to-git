#include "UIInfoPanelManager.h"
#include <UI/UIWidget.h>
#include <UI/UIManager.h>
#include "../SlotGameBehavior/BSSlotsContainer.h"
#include <GTGameObjectManager.h>
#include <cocos2dx-wrap/Cocos2dxGeneral.h>
#include <UI/UILabelValueTweener.h>
#include <UI/UIAnimation.h>
#include "UIDef.h"

GTSINGLETON_IMP(UIInfoPanelManager);

UIInfoPanelManager::UIInfoPanelManager() :
	m_pLabelEntryLvl(NULL),
	m_pLabelWin(NULL),
	m_pLabelWinPoints(NULL),
	m_pAnimationMaxEntry(NULL)
{
}


UIInfoPanelManager::~UIInfoPanelManager()
{
}


UILabelValueTweener* UIInfoPanelManager::FindLabelEntryLvl(void)
{
	UIWidget* pUIRoot = UIManager::Inst()->GetRootWidget();
	UIWidget* pFrame = pUIRoot->FindChildById<UIWidget>(UI_IdDef::INFOBAR_UIFRAME);
	if(pFrame)
	{
		UIWidget* pPic = pFrame->FindChildById<UIWidget>(UI_IdDef::INFOBAR_PIC_ENTRYLEVEL, true);
		if(pPic)
		{
			return pPic->FindChildById<UILabelValueTweener>(UI_IdDef::INFOBAR_LABEL_ENTRYLEVEL);
		}
	}
	return NULL;
}


UILabelValueTweener* UIInfoPanelManager::FindLabelWin(void)
{
	UIWidget* pUIRoot = UIManager::Inst()->GetRootWidget();
	UIWidget* pFrame = pUIRoot->FindChildById<UIWidget>(UI_IdDef::INFOBAR_UIFRAME);
	if(pFrame)
	{
		UIWidget* pPic = pFrame->FindChildById<UIWidget>(UI_IdDef::INFOBAR_PIC_WIN, true);
		if(pPic)
		{
			return pPic->FindChildById<UILabelValueTweener>(UI_IdDef::INFOBAR_LABEL_WIN);
		}
	}
	return NULL;
}


UILabelValueTweener* UIInfoPanelManager::FindLabelWinPoints(void)
{
	UIWidget* pUIRoot = UIManager::Inst()->GetRootWidget();
	UIWidget* pFrame = pUIRoot->FindChildById<UIWidget>(UI_IdDef::INFOBAR_UIFRAME);
	if(pFrame)
	{
		UIWidget* pPic = pFrame->FindChildById<UIWidget>(UI_IdDef::INFOBAR_PIC_WINPOINTS, true);
		if(pPic)
		{
			return pPic->FindChildById<UILabelValueTweener>(UI_IdDef::INFOBAR_LABEL_WINPOINTS);
		}
	}
	return NULL;
}


UIAnimation* UIInfoPanelManager::FindAnimationMaxEntry(void)
{
	UIWidget* pUIRoot = UIManager::Inst()->GetRootWidget();
	UIWidget* pFrame = pUIRoot->FindChildById<UIWidget>(UI_IdDef::INFOBAR_UIFRAME);
	if(pFrame)
	{
		UIWidget* pBtn = pFrame->FindChildById<UIWidget>(103, true);
		if(pBtn)
		{
			return pBtn->FindChildById<UIAnimation>(1005);
		}
	}
	return NULL;
}


void UIInfoPanelManager::UpdateEntryLevel(const int32 nCurrent, const int32 nTarget)
{
	if(NULL == m_pLabelEntryLvl)
		m_pLabelEntryLvl = FindLabelEntryLvl();

	if(m_pLabelEntryLvl)
	{
		m_pLabelEntryLvl->SetValue(nTarget);
	}
}


void UIInfoPanelManager::AddWin(const int32 nNewValue, const int32 nDurationInMs)
{
	// Update win
	if(NULL == m_pLabelWin)
		m_pLabelWin = FindLabelWin();
	if(m_pLabelWin)
		UpdateWin(m_pLabelWin->GetValue() + nNewValue, nDurationInMs);
	
	// Update win points
	if(NULL == m_pLabelWinPoints)
		m_pLabelWinPoints = FindLabelWinPoints();
	if(m_pLabelWinPoints)
	{
		int nCurrentWinPoints = m_pLabelWinPoints->GetValue();
		UpdateWinPoints(nCurrentWinPoints + nNewValue, nDurationInMs);
	}
}


void UIInfoPanelManager::UpdateWin(const int32 nNewValue, const int32 nDurationInMs)
{
	if(NULL == m_pLabelWin)
		m_pLabelWin = FindLabelWin();

	if(m_pLabelWin)
	{
		m_pLabelWin->SetValue(nNewValue, nDurationInMs);
	}
}

void UIInfoPanelManager::ResetWinLabel()
{
	UpdateWin(0, 0);
}


void UIInfoPanelManager::AddWinPoints(const int32 nCount)
{
	if(NULL == m_pLabelWin)
		m_pLabelWin = FindLabelWin();

	int nCurrent = m_pLabelWin->GetValue();
}

void UIInfoPanelManager::UpdateWinPoints(const int32 nNewValue, const int32 nDurationInMs)
{
	if(NULL == m_pLabelWinPoints)
		m_pLabelWinPoints = FindLabelWinPoints();
	if(m_pLabelWinPoints)
	{
		m_pLabelWinPoints->SetValue(nNewValue, nDurationInMs);
	}
}


bool UIInfoPanelManager::OnEntryLvlValueTweenerFinished(UIWidget* pWidget, void *pParam)
{
	GTLogManager::SLogFormatTrace(CTEXT("OnEntryLvlValueTweenerFinished called: %s"), pWidget->GetName());
	return true;
}


void UIInfoPanelManager::Initialize(void)
{
	m_pLabelEntryLvl = FindLabelEntryLvl();
	if(m_pLabelEntryLvl)
	{		
		// Hook an event listener for tweener finished
		m_pLabelEntryLvl->GetEventTweener()->AddEventListener(
			this,
			UIWidget_EventCallback2_Set(UIInfoPanelManager::OnEntryLvlValueTweenerFinished),
			NULL);
	}
	m_pLabelWin = FindLabelWin();
	m_pLabelWinPoints = FindLabelWinPoints();
}


void UIInfoPanelManager::OnAnimationPlayingCompletion(void* pParam)
{
	if(m_pAnimationMaxEntry)
	{
		m_pAnimationMaxEntry->StopAnimation();
		m_pAnimationMaxEntry->SetVisible(false);
	}
}


void UIInfoPanelManager::OnSingleClick(UIWidget* pWidget, const uint32 nFlags, const GTPoint2& pos)
{
	if(NULL == pWidget)
		return;
		
	if(nFlags & UIWidget::Flag_ClickUp)
	{
		const uint32 widgetId = pWidget->GetId();
		switch(widgetId)
		{
			// Show button
			case UI_IdDef::INFOBAR_BTN_SHOW:
				{
					GTGameObject* pReelsContainer = NULL;
					BSSlotsContainer* pBSSlotsContainer = NULL;
					pReelsContainer = GTGameObjectManager::FindGameObject("ReelsContainer");
					if(pReelsContainer)
						pBSSlotsContainer = (BSSlotsContainer*)pReelsContainer->GetBehaviour("BSSlotsContainer");
					if(pBSSlotsContainer)
					{
						pBSSlotsContainer->Test();
						GTLogManager::SLogFormatTrace("buttonSpin clicked");
					}
				}
			break;

			// Change game button
			case UI_IdDef::INFOBAR_BTN_CHANGEGAME:
				{
					//GTLogManager::SLogFormatTrace("buttonExit clicked");
					Cocos2dxGeneral::GetInstance()->Exit();
				}
			break;

			// Entry level
			case UI_IdDef::INFOBAR_BTN_ENTRYLEVEL:
				{
					if(m_pLabelEntryLvl)
					{
						UIInfoPanelManager::Inst()->UpdateEntryLevel(0, 80);
					}					
					//UIInfoPanelManager::Inst()->UpdateWin(0, 40);
					//UIInfoPanelManager::Inst()->UpdateWinPoints(100, 150);
				}
			break;

			// MaxEntry level
			case UI_IdDef::INFOBAR_BTN_MAXENTRY:
				{
					if(NULL == m_pAnimationMaxEntry)
						m_pAnimationMaxEntry = FindAnimationMaxEntry();
					if(m_pAnimationMaxEntry)
					{
						m_pAnimationMaxEntry->SetVisible(true);
						m_pAnimationMaxEntry->PlayAnimationByIndex(
							0,
							GSpriteAnimation::PlayMode_Once,
							GTObject_EventCallback_Set(UIInfoPanelManager::OnAnimationPlayingCompletion),
							this,
							NULL);
					}
					//UIInfoPanelManager::Inst()->UpdateEntryLevel(0, 100);
					//UIInfoPanelManager::Inst()->UpdateWin(0, 150);
					//UIInfoPanelManager::Inst()->UpdateWinPoints(100, 200);
				}
			break;
		}
	}
}
