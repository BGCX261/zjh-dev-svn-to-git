#include "UIBSProgressBarSmoothChange.h"
#include "TimeManager.h"

GTBEHAVIOUR_IMP(UIBSProgressBarSmoothChange, UIWidgetScript);

UIBSProgressBarSmoothChange::UIBSProgressBarSmoothChange():
	m_pUIProgressBar(NULL),
	m_fPrevTimer(0.0f),
	m_fTimerInterval(0.0f)
{
}


UIBSProgressBarSmoothChange::~UIBSProgressBarSmoothChange()
{
}


// This method is called when GTBehaviour object is created.
int32 UIBSProgressBarSmoothChange::OnCreate(void)
{
	GTBehaviour::OnCreate();
	
	return 1;
}


// This method is called when GTBehaviour object is initialized.
int32 UIBSProgressBarSmoothChange::OnInitialize(GTBehaviourInit* param)
{
	GTBehaviour::OnInitialize(param);
	
	if(param->pParam2)
	{
		GTTreeNode* pParam = (GTTreeNode*)(param->pParam2);
		const int32 nChildCount = pParam->GetChildCount();
		for(int32 i=0; i<nChildCount; i++)
		{
			GTTreeNode* pChildNode = pParam->GetChild(i);
			if(pChildNode->GetTag() == CTEXT("Interval"))
				m_fTimerInterval = pChildNode->GetValue().ToFloat();
		}
	}	

	return 1;
}


// This method is called before first OnUpdate
int32 UIBSProgressBarSmoothChange::OnStart(void)
{
	GTBehaviour::OnStart();

	m_pUIProgressBar = (UIProgressBar*)GetGameObject();
	
	return 1;
}


// Refresh value
void UIBSProgressBarSmoothChange::RefreshValue(void)
{
	if(m_pUIProgressBar)
	{
		m_pUIProgressBar->SetCurrentValue(m_nWorkingValue);
	}
}


// This method is called when GTBehaviour object is updated.
int32 UIBSProgressBarSmoothChange::OnUpdate(void)
{
	GTBehaviour::OnUpdate();
	
	// Check if it's time to update working value
	float fTimeNow = TimeManager::GetInstance()->GetTime();
	float fTimeDelta = fTimeNow - m_fPrevTimer;
	if(fTimeDelta > m_fTimerInterval)
	{
		if(m_nWorkingValue == m_nTargetValue)
		{
			m_fPrevTimer = fTimeNow;
			return 1;
		}

		if(m_nWorkingValue < m_nTargetValue)
		{
			m_nWorkingValue++;
		}
		else if(m_nWorkingValue > m_nTargetValue)
		{
			m_nWorkingValue--;
		}

		// Refresh the value dispalyed
		RefreshValue();
		// Save current time for next update
		m_fPrevTimer = fTimeNow;
	}

	return 1;
}


// This method is called when GTBehaviour object is destroyed.
int32 UIBSProgressBarSmoothChange::OnDestroy(void)
{
	GTBehaviour::OnDestroy();
	
	return 1;
}
