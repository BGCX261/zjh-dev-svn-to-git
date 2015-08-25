#include "UIBSLabelSmoothValueChange.h"
#include <GTPropertyFile.h>
#include "TimeManager.h"

GTBEHAVIOUR_IMP(UIBSLabelSmoothValueChange, UIWidgetScript);

UIBSLabelSmoothValueChange::UIBSLabelSmoothValueChange():
	m_pUILabelWidget(NULL),
	m_fPrevTimer(0.0f),
	m_fTimerInterval(0.0f)
{
}


UIBSLabelSmoothValueChange::~UIBSLabelSmoothValueChange()
{
}


// This method is called when GTBehaviour object is created.
int32 UIBSLabelSmoothValueChange::OnCreate(void)
{
	GTBehaviour::OnCreate();
	
	return 1;
}


// This method is called when GTBehaviour object is initialized.
int32 UIBSLabelSmoothValueChange::OnInitialize(GTBehaviourInit* param)
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
int32 UIBSLabelSmoothValueChange::OnStart(void)
{
	GTBehaviour::OnStart();

	m_pUILabelWidget = (UILabel*)GetGameObject();
	
	return 1;
}


// Refresh value
void UIBSLabelSmoothValueChange::RefreshValue(void)
{
	if(m_pUILabelWidget)
	{
		m_pUILabelWidget->SetTextFromINT16(m_nWorkingValue);
	}
}


// This method is called when GTBehaviour object is updated.
int32 UIBSLabelSmoothValueChange::OnUpdate(void)
{
	GTBehaviour::OnUpdate();

	if(m_nWorkingValue != m_nTargetValue)
	{
		// Check if it's time to update working value
		float fTimeNow = TimeManager::GetInstance()->GetTime();
		float fTimeDelta = fTimeNow - m_fPrevTimer;
		if(fTimeDelta > m_fTimerInterval)
		{
			if(m_nWorkingValue < m_nTargetValue)
			{
				m_nWorkingValue++;
				if(m_nWorkingValue > m_nTargetValue)
				{
					m_nWorkingValue = m_nTargetValue;
				}
			}
			else if(m_nWorkingValue > m_nTargetValue)
			{
				m_nWorkingValue--;
				if(m_nWorkingValue < 0)
				{
					m_nWorkingValue = 0;
				}
			}

			// Refresh the value dispalyed
			RefreshValue();
			// Save current time for next update
			m_fPrevTimer = fTimeNow;
		}
	}
	
	return 1;
}


// This method is called when GTBehaviour object is destroyed.
int32 UIBSLabelSmoothValueChange::OnDestroy(void)
{
	GTBehaviour::OnDestroy();
	
	return 1;
}
