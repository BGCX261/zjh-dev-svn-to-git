#include "UIProgressBarSmoothChange.h"
#include "UIWidgetClassManager.h"
#include "TimeManager.h"
#include "PropertyFile.h"

UIWIDGET_IMP(UIProgressBarSmoothChange, UIWidget, UIWidgetClassManager::CreateClassInstanceDefineCallback)

UIProgressBarSmoothChange::UIProgressBarSmoothChange() : UIProgressBar()
{
	m_nTargetValue = 100;
	m_nWorkingValue = 100;
	m_fPrevTimer = 0.0f;
}


UIProgressBarSmoothChange::UIProgressBarSmoothChange(UIWidget* pParent) : UIProgressBar(pParent)
{
	m_nTargetValue = 100;
	m_nWorkingValue = 100;
	m_fPrevTimer = 0.0f;
}


UIProgressBarSmoothChange::~UIProgressBarSmoothChange()
{
}


// Override this method to serialize specific properties
bool UIProgressBarSmoothChange::OnSerializeTo(GTTreeNode* pTreeNode)
{
	UIProgressBar::OnSerializeTo(pTreeNode);

	return true;
}


// Override this method to serialize specific properties
bool UIProgressBarSmoothChange::OnSerializeFrom(GTTreeNode* pTreeNode)
{
	UIProgressBar::OnSerializeFrom(pTreeNode);

	if(NULL == pTreeNode)
	{
		return true;
	}

	GTTreeNode* pCustomizedValueNode = pTreeNode->FindChild(PropertyFile::TagCustomizedValue);
	if(pCustomizedValueNode)
	{
		const int32 nChildCount = pCustomizedValueNode->GetChildCount();
		for(int32 i=0; i<nChildCount; i++)
		{
			GTTreeNode* pChildNode = pCustomizedValueNode->GetChild(i);
			if(pChildNode)
			{
				if(pChildNode->GetTag() == PropertyFile::TagPairValue)
				{
					GTPairValue pv = pChildNode->ValueToPairValue();
					if(pv.m_sName == CTEXT("MinValue"))				
						SetPropertyMinValue(pv.m_sValue.ToInt());
					else if(pv.m_sName == CTEXT("MaxValue"))
						SetPropertyMaxValue(pv.m_sValue.ToInt());
					else if(pv.m_sName == CTEXT("Interval"))
						SetPropertyTimerInterval(pv.m_sValue.ToFloat());
					else if(pv.m_sName == CTEXT("StepValue"))
						SetPropertyStepValue(pv.m_sValue.ToInt());
				}
			}
		}
	}

	return true;
}


// When the object is initialized, this method is called.
int32 UIProgressBarSmoothChange::OnInitialize(void)
{
	UIProgressBar::OnInitialize();

	return 1;
}


// When the system is updated, this method is called for each frame.
int32 UIProgressBarSmoothChange::OnUpdate(void)
{
	UIProgressBar::OnUpdate();

	int16 nCurrentValue = UIProgressBar::GetCurrentValue();
	if(nCurrentValue != m_nTargetValue)
	{
		// Check if it's time to update working value
		float fTimeNow = TimeManager::GetInstance()->GetTime();
		float fTimeDelta = fTimeNow - m_fPrevTimer;
		if(fTimeDelta > m_fTimerInterval)
		{
			if(nCurrentValue < m_nTargetValue)
			{
				nCurrentValue += m_nStepValue;
				if(nCurrentValue > m_nMaxValue)
					nCurrentValue = m_nMaxValue;
			}
			else if(nCurrentValue > m_nTargetValue)
			{
				nCurrentValue -= m_nStepValue;
				if(nCurrentValue < m_nMinValue)
					nCurrentValue = m_nMinValue;
			}

			// Refresh the value dispalyed
			UIProgressBar::SetCurrentValue(nCurrentValue);
			// Save current time for next update
			m_fPrevTimer = fTimeNow;
		}
	}

	return 1;
}


// This method is called for rendering each frame.
int32 UIProgressBarSmoothChange::OnRender(void)
{
	UIProgressBar::OnRender();

	return 1;
}


// Before the system is shut down, this method is called.
int32 UIProgressBarSmoothChange::OnDestroy(void)
{
	UIProgressBar::OnDestroy();

	return 1;
}


// Override GTObject::Release to do more things
void UIProgressBarSmoothChange::Release(void)
{
	UIProgressBar::Release();
}


// Set the current value of the progress bar
void UIProgressBarSmoothChange::SetCurrentValue(const int32 nValue)
{
	m_nTargetValue = nValue;
}


void UIProgressBarSmoothChange::RefreshValue(void)
{
	m_nCurrentValue = m_nTargetValue;
}
