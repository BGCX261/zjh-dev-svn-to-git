#include "BSPlayerPlayingUI.h"
#include "PropertyFile.h"
#include "BSClassName.h"
#include "BSPlayerController.h"
#include <GTTreeNode.h>
#include "GTLog/GTLogManager.h"
#include "UI/UIManager.h"
#include "UIBehaviourScript/UIBSClassName.h"

GTBEHAVIOUR_IMP(BSPlayerPlayingUI, GTBehaviour);

BSPlayerPlayingUI::BSPlayerPlayingUI()
{
}


BSPlayerPlayingUI::~BSPlayerPlayingUI()
{
}


// This method is called when GTBehaviour object is created.
int32 BSPlayerPlayingUI::OnCreate(void)
{
	GTBehaviour::OnCreate();
	
	return 1;
}


// This method is called when GTBehaviour object is initialized.
int32 BSPlayerPlayingUI::OnInitialize(GTBehaviourInitParam* param)
{
	GTBehaviour::OnInitialize(param);

	// Cache game objects
	m_pBSPlayerController = (BSPlayerController*)BSCLASSNAME_GET_COMPONENT(BSClassName::BSPlayerController);
	if(NULL == m_pBSPlayerController)
	{
		GTLogManager::GetInstance()->LogError(CTEXT("BSPlayerController not found"));
		return 1;
	}

	return 1;
}


// Initialize a UI container
void BSPlayerPlayingUI::InitializeUIContainer(
	UIFrame* pUIFrame,
	BSPlayerPlayingUIContainer* pContainer,
	const tchar* szLabelName,
	const tchar* szProgressName
	)
{
	if(NULL == pUIFrame || NULL == pContainer)
	{
		return;
	}

	if(szLabelName)
	{
		pContainer->pUILabel = (UILabelSmoothChange*)(pUIFrame->FindChild(szLabelName));
	}
	if(szProgressName)
	{
		pContainer->pUIProgressBar = (UIProgressBar*)(pUIFrame->FindChild(szProgressName));
	}
}


// Setup a UI container
void BSPlayerPlayingUI::SetupUIContainer(
	BSPlayerPlayingUIContainer* pContainer,
	const int32 nMinValue,
	const int32 nMaxValue,
	const int32 nValue)
{
	if(NULL == pContainer)
	{
		return;
	}

	if(pContainer->pUILabel)
	{
		pContainer->pUILabel->SetPropertyTargetValue(nValue);
		pContainer->pUILabel->SetPropertyWorkingValue(nValue);
		pContainer->pUILabel->RefreshValue();
	}
	if(pContainer->pUIProgressBar)
	{
		pContainer->pUIProgressBar->SetMinValue(nMinValue);
		pContainer->pUIProgressBar->SetMaxValue(nMaxValue);
		pContainer->pUIProgressBar->SetCurrentValue(nValue);
		pContainer->pUIProgressBar->RefreshValue();
	}
}


// This method is called before first OnUpdate
int32 BSPlayerPlayingUI::OnStart(void)
{
	GTBehaviour::OnStart();

	for(int32 i=0; i<BSPlayerPlayingUI::UIContainerTypeCount; i++)
	{
		m_UIContainer[i].pUILabel = NULL;
		m_UIContainer[i].pUIProgressBar = NULL;
	}

	// UI widgets
	UIFrame* pFrame = (UIFrame*)(UIManager::GetInstance()->GetRootWidget()->FindChild(CTEXT("MainUIFrame")));
	if(pFrame)
	{
		// HP
		InitializeUIContainer(
			pFrame,
			&m_UIContainer[BSPlayerPlayingUI::UIContainerTypeHP],
			CTEXT("Label_HPValue"),
			CTEXT("ProgressBar_HP")
			);
		// SP
		InitializeUIContainer(
			pFrame,
			&m_UIContainer[BSPlayerPlayingUI::UIContainerTypeSP],
			CTEXT("Label_SPValue"),
			CTEXT("ProgressBar_SP")
			);
		// Exp
		InitializeUIContainer(
			pFrame,
			&m_UIContainer[BSPlayerPlayingUI::UIContainerTypeExp],
			CTEXT("Label_ExpValue"),
			CTEXT("ProgressBar_Exp")
			);
		// Level
		InitializeUIContainer(
			pFrame,
			&m_UIContainer[BSPlayerPlayingUI::UIContainerTypeLevel],
			CTEXT("Label_LevelValue"),
			NULL
			);
		// Money
		InitializeUIContainer(
			pFrame,
			&m_UIContainer[BSPlayerPlayingUI::UIContainerTypeMoney],
			CTEXT("Label_MoneyValue"),
			NULL
			);

		// HP
		SetupUIContainer(
			&m_UIContainer[BSPlayerPlayingUI::UIContainerTypeHP],
			0,
			m_pBSPlayerController->GetPropertyLifeMax(),
			m_pBSPlayerController->GetPropertyLife()
			);
		// SP
		SetupUIContainer(
			&m_UIContainer[BSPlayerPlayingUI::UIContainerTypeSP],
			0,
			m_pBSPlayerController->GetPropertySkillPointMax(),
			m_pBSPlayerController->GetPropertySkillPoint()
			);
		// Exp			
		SetupUIContainer(
			&m_UIContainer[BSPlayerPlayingUI::UIContainerTypeExp],
			0,
			m_pBSPlayerController->GetPropertyExperienceForNextLevel(),
			m_pBSPlayerController->GetPropertyExperience()
			);
		// Level
		SetupUIContainer(
			&m_UIContainer[BSPlayerPlayingUI::UIContainerTypeLevel],
			0,
			99,
			m_pBSPlayerController->GetPropertyLevel()
			);
		// Money			
		SetupUIContainer(
			&m_UIContainer[BSPlayerPlayingUI::UIContainerTypeMoney],
			0,
			999999,
			m_pBSPlayerController->GetPropertyMoney()
			);
	}
	
	return 1;
}


// This method is called when GTBehaviour object is updated.
int32 BSPlayerPlayingUI::OnUpdate(void)
{
	GTBehaviour::OnUpdate();
	
	return 1;
}


// This method is called when GTBehaviour object is destroyed.
int32 BSPlayerPlayingUI::OnDestroy(void)
{
	GTBehaviour::OnDestroy();
	
	return 1;
}
