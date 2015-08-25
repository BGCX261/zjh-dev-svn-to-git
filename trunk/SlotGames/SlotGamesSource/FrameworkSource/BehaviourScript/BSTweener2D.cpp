#include "BSTweener2D.h"
#include "TimeManager.h"

GTBEHAVIOUR_IMP(BSTweener2D, GTBehaviour);

//Graphic result:  http://www.cnblogs.com/cloudgamer/archive/2009/01/06/Tween.html

BSTweener2D::BSTweener2D()
{
	SetPropertyRunning(false);
	SetPropertyDelay(0.0f);
	SetPropertyStartTime(0.0f);
	m_StaticCallback.Setup(NULL, NULL);
}


BSTweener2D::~BSTweener2D()
{
}


// This method is called when GTBehaviour object is created.
int32 BSTweener2D::OnCreate(void)
{
	GTBehaviour::OnCreate();
	
	return 1;
}


// This method is called when GTBehaviour object is initialized.
int32 BSTweener2D::OnInitialize(GTBehaviourInitParam* param)
{
	GTBehaviour::OnInitialize(param);
	
	return 1;
}


// This method is called before first OnUpdate
int32 BSTweener2D::OnStart(void)
{
	GTBehaviour::OnStart();
	
	return 1;
}


// This method is called when GTBehaviour object is updated.
int32 BSTweener2D::OnUpdate(void)
{
	if(!GetPropertyRunning())
	{
		return 0;
	}

	GTBehaviour::OnUpdate();
	
	if(TimeManager::GetInstance()->GetTime() > (m_fStartTime + m_fDelay))
	{
		TweenUpdate();
	}

	return 1;
}


// This method is called when GTBehaviour object is destroyed.
int32 BSTweener2D::OnDestroy(void)
{
	GTBehaviour::OnDestroy();
	
	return 1;
}


// Start
//
// from: start position
// to: end position
// duration: how long for (from, to), in ms
// tweenFunction: tweener type, see TweenInterpolation
// delay: delay to start, in ms
void BSTweener2D::Start(
	const GTVector2 from,
	const GTVector2 to,
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
	m_StaticCallback.Setup(onCompleted, pParam);

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
void BSTweener2D::Start(
	const GTVector2 from,
	const GTVector2 to,
	const float duration,
	GTTweenFunction tweenFunction,
	const float delay
	)
{
	Start(from, to, duration, tweenFunction, delay, NULL, NULL);
}


void BSTweener2D::TweenUpdate(void)
{
	DBG_ASSERT(m_pGameObject);

	if(m_pGameObject)
	{
		bool bRemoveTween = m_Tweener.GetPropertyElapsedTime() >= m_Tweener.GetPropertyDuration();
		// Calculate new position
		GTVector2 position = m_Tweener.Update(TimeManager::GetInstance()->GetDeltaTime());
		// Apply new position for the game object
		m_pGameObject->SetPosition(position);

		if(bRemoveTween)
		{
			// Callback
			m_StaticCallback.Execute();
			//(this->*m_pOnCompletion)(NULL);
			//m_pOnCompletion = NULL;
			// Restore the position with its parent
			//m_pGameObject->SetPosition(m_pGameObject->m_pParent->GetPosition());

			// Stop running
			Stop();
		}
	}
}


// Stop
void BSTweener2D::Stop(void)
{
	SetPropertyRunning(false);
}
