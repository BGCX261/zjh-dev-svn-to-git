#include "UILabelSmoothChange.h"
#include "UIWidgetClassManager.h"
#include "TimeManager.h"
#include <GTPropertyFile.h>

UIWIDGET_IMP(UILabelSmoothChange, UIWidget, UIWidgetClassManager::CreateClassInstanceDefineCallback)

UILabelSmoothChange::UILabelSmoothChange() : UILabel()
{
	SetPropertyStepValue(1);
	SetPropertyMinValue(0);	
	SetPropertyTimerInterval(0.05f);
	SetPropertyWorkingValue(0);
	SetPropertyTargetValue(0);
	SetPropertyStepValue(0);
}


UILabelSmoothChange::UILabelSmoothChange(UIWidget* pParent) : UILabel(pParent)
{
	SetPropertyStepValue(1);
	SetPropertyMinValue(0);
	SetPropertyTimerInterval(0.05f);
	SetPropertyWorkingValue(0);
	SetPropertyTargetValue(0);
	SetPropertyStepValue(0);
}


UILabelSmoothChange::~UILabelSmoothChange()
{
}


// Override this method to serialize specific properties
bool UILabelSmoothChange::OnSerializeTo(GTTreeNode* pTreeNode)
{
	return UILabel::OnSerializeTo(pTreeNode);
}


// Override this method to serialize specific properties
bool UILabelSmoothChange::OnSerializeFrom(GTTreeNode* pTreeNode)
{
	UILabel::OnSerializeFrom(pTreeNode);

	if(NULL == pTreeNode)
	{
		return true;
	}

	GTTreeNode* pCustomizedValueNode = pTreeNode->FindChild(GTPropertyFile::TagCustomizedValue);
	if(pCustomizedValueNode)
	{
		const int32 nChildCount = pCustomizedValueNode->GetChildCount();
		for(int32 i=0; i<nChildCount; i++)
		{
			GTTreeNode* pChildNode = pCustomizedValueNode->GetChild(i);
			if(pChildNode)
			{
				if(pChildNode->GetTag() == GTPropertyFile::TagPairValue)
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
int32 UILabelSmoothChange::OnInitialize(void)
{
	UILabel::OnInitialize();
	
	return 1;
}


// Refresh value
void UILabelSmoothChange::RefreshValue(void)
{
	UILabel::SetTextFromINT32(m_nWorkingValue);
}


// When the system is updated, this method is called for each frame.
int32 UILabelSmoothChange::OnUpdate(void)
{
	UILabel::OnUpdate();

	if(m_nWorkingValue != m_nTargetValue)
	{
		// Check if it's time to update working value
		float fTimeNow = TimeManager::GetInstance()->GetTime();
		float fTimeDelta = fTimeNow - m_fPrevTimer;
		if(fTimeDelta > m_fTimerInterval)
		{
			if(m_nWorkingValue < m_nTargetValue)
			{
				m_nWorkingValue += m_nStepValue;
				if(m_nWorkingValue > m_nTargetValue)
				{
					m_nWorkingValue = m_nTargetValue;
				}
			}
			else if(m_nWorkingValue > m_nTargetValue)
			{
				m_nWorkingValue -= m_nStepValue;
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


// This method is called for rendering each frame.
int32 UILabelSmoothChange::OnRender(void)
{
	UILabel::OnRender();

	return 1;
}


// Before the system is shut down, this method is called.
int32 UILabelSmoothChange::OnDestroy(void)
{
	UILabel::OnDestroy();

	return 1;
}


// Override GTObject::Release to do more things
void UILabelSmoothChange::Release(void)
{
	UILabel::Release();
}
