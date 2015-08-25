#include "UILabelValueTweener.h"
#include "UIWidgetClassManager.h"
#include "TimeManager.h"
#include <GTPropertyFile.h>
#include <GTTweenInterpolation.h>

UIWIDGET_IMP(UILabelValueTweener, UIWidget, UIWidgetClassManager::CreateClassInstanceDefineCallback)

UILabelValueTweener::UILabelValueTweener() : UILabel()
{
	SetPropertyValue(0);
	SetPropertyDuration(1500);
	SetPropertyRunning(false);
	SetPropertyDelay(0.0f);
	SetPropertyStartTime(0.0f);
}


UILabelValueTweener::UILabelValueTweener(UIWidget* pParent) : UILabel(pParent)
{
	SetPropertyValue(0);
	SetPropertyDuration(1500);
	SetPropertyRunning(false);
	SetPropertyDelay(0.0f);
	SetPropertyStartTime(0.0f);
}


UILabelValueTweener::~UILabelValueTweener()
{
}


// Override this method to serialize specific properties
bool UILabelValueTweener::OnSerializeTo(GTTreeNode* pTreeNode)
{
	return UILabel::OnSerializeTo(pTreeNode);
}


// Override this method to serialize specific properties
bool UILabelValueTweener::OnSerializeFrom(GTTreeNode* pTreeNode)
{
	if(NULL == pTreeNode)
		return true;

	UILabel::OnSerializeFrom(pTreeNode);

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
					if(pv.m_sName == CTEXT("Duration"))
						SetPropertyDuration(pv.m_sValue.ToInt());
					/*
					else if(pv.m_sName == CTEXT("MinValue"))
						SetPropertyMinValue(pv.m_sValue.ToInt());
					
					else if(pv.m_sName == CTEXT("MaxValue"))
						SetPropertyMaxValue(pv.m_sValue.ToInt());
					else if(pv.m_sName == CTEXT("Interval"))
						SetPropertyTimerInterval(pv.m_sValue.ToFloat());
					else if(pv.m_sName == CTEXT("StepValue"))
						SetPropertyStepValue(pv.m_sValue.ToInt());
						*/
				}
			}
		}
	}

	return true;
}


// When the object is initialized, this method is called.
int32 UILabelValueTweener::OnInitialize(void)
{
	UILabel::OnInitialize();
	
	return 1;
}


// When the system is updated, this method is called for each frame.
int32 UILabelValueTweener::OnUpdate(void)
{
	if(!GetPropertyRunning())
		return 0; // Not running

	UILabel::OnUpdate();
	
	if(TimeManager::GetInstance()->GetTime() > (m_fStartTime + m_fDelay))
	{
		TweenUpdate();
	}
		
	return 1;
}


// This method is called for rendering each frame.
int32 UILabelValueTweener::OnRender(void)
{
	UILabel::OnRender();

	return 1;
}


// Before the system is shut down, this method is called.
int32 UILabelValueTweener::OnDestroy(void)
{
	UILabel::OnDestroy();
	m_EventTweenerFinished.Clear();

	return 1;
}


// Override GTObject::Release to do more things
void UILabelValueTweener::Release(void)
{
	UILabel::Release();
}


// Start
//
// from: start position
// to: end position
// duration: how long for (from, to), in ms
// tweenFunction: tweener type, see TweenInterpolation
// delay: delay to start, in ms
void UILabelValueTweener::Start(
	const int32 from,
	const int32 to,
	const float duration,
	GTTweenFunction tweenFunction,
	const float delay,
	GTStatic_EventCallback onCompleted,
	void* pParam
	)
{
	m_Tweener.Tween(from, to, duration, tweenFunction);
	GT_PROPERTY_REF_VAR_FLOAT(StartTime) = TimeManager::GetInstance()->GetTime();
	GT_PROPERTY_REF_VAR_FLOAT(Delay) = delay;
	// Setup callback
	//m_StaticCallback.Setup(onCompleted, pParam);

	// Start running
	SetPropertyRunning(true);
}


// Start
//
// from: start position
// to: end position
// duration: how long for (from, to), in ms
// tweenFunction: tweener type, see TweenInterpolation
// delay: delay to start, in ms
void UILabelValueTweener::Start(
	const int32 from,
	const int32 to,
	const float duration,
	GTTweenFunction tweenFunction,
	const float delay
	)
{
	Start(from, to, duration, tweenFunction, delay, NULL, NULL);
}


void UILabelValueTweener::TweenUpdate(void)
{
	bool bStop = m_Tweener.GetPropertyElapsedTime() >= m_Tweener.GetPropertyDuration();
	// Calculate new position
	const int32 nNewValue = m_Tweener.Update(TimeManager::GetInstance()->GetDeltaTime());
	UILabel::SetTextFromINT32(nNewValue);

	if(bStop)
	{
		// Callback
		//m_StaticCallback.Execute();
		//(this->*m_pOnCompletion)(NULL);
		//m_pOnCompletion = NULL;
		// Restore the position with its parent
		//m_pGameObject->SetPosition(m_pGameObject->m_pParent->GetPosition());

		// Stop running
		Stop();
		// Save the lastest value
		SetPropertyValue(nNewValue);
	}
}


// Stop
void UILabelValueTweener::Stop(void)
{
	SetPropertyRunning(false);

	// Callback
	m_EventTweenerFinished.Invoke(this);
}


// Set value
void UILabelValueTweener::SetValue(const int32 nNewValue, const int32 nDurationInMs)
{
	const int32 nCurrent = GetPropertyValue();
	// Save target value
	SetPropertyValue(nNewValue);
	// Start running
	SetPropertyRunning(true);
	// Start tweener
	Start(nCurrent, nNewValue, nDurationInMs, GTTweenInterpolation::Linear, 0.0f);
}


void UILabelValueTweener::SetValue(const int32 nNewValue)
{
	SetValue(nNewValue, GetPropertyDuration());
}
