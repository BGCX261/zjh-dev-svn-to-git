#include "ReelAnimation.h"

//--------------------------------------
// ReelAnimation
//--------------------------------------
ReelAnimation::ReelAnimation()
{
}


ReelAnimation::~ReelAnimation()
{
}

/*
void ReelAnimation::Tween(
	const GTVector2 from, 
	const GTVector2 to,
	const int32 duration,
	GTTweenFunction tweenFunction
	)
{
	m_FromPosition = from;
	m_Change = to - from;
	m_pTweenFunction = tweenFunction;
	// If duration = 0, reset it to 1 in order to prevent an exception for (m_fElapsedTime / m_fDuration)
	SetPropertyDuration((duration <= 0) ? 1 : duration);
	SetPropertyElapsedTime(0);
}
*/

/// <summary>
/// Get the next position in the tween
/// </summary>
/// <param name="time"> The amount of time elapsed since the last tween </param>
/// <returns> The new position of the tween </returns>
GTVector2 ReelAnimation::Update(const int32 deltaTime)
{
	/*
	DBG_ASSERT(m_pTweenFunction);

	GTVector2 newPosition;
	float factor = m_fElapsedTime / m_fDuration;

	newPosition.x = Mathf_Floor(m_pTweenFunction(m_FromPosition.x, m_Change.x, factor));
	newPosition.y = Mathf_Floor(m_pTweenFunction(m_FromPosition.y, m_Change.y, factor));

	m_fElapsedTime = Mathf_Clamp(m_fElapsedTime + deltaTime, 0.0f, m_fDuration);

	return newPosition;
	*/
	return GTVector2::Zero;
}
