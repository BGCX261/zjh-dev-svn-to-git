#include "Tweener2D.h"

Tweener2D::Tweener2D() : Tweener()
{
}


Tweener2D::~Tweener2D()
{
}


void Tweener2D::Tween(
	const GTVector2 from, 
	const GTVector2 to,
	const float duration,
	TweenFunction tweenFunction
	)
{
	m_FromPosition = from;
	m_Change = to - from;
	m_pTweenFunction = tweenFunction;
	SetPropertyDuration(duration);
	SetPropertyElapsedTime(0);
}


/// <summary>
/// Get the next position in the tween
/// </summary>
/// <param name="time"> The amout of time elapsed since the last tween </param>
/// <returns> The new position of the tween </returns>
GTVector2 Tweener2D::Update(const float deltaTime)
{
	DBG_ASSERT(m_pTweenFunction);

	GTVector2 newPosition;
	float factor = m_fElapsedTime / m_fDuration;

	newPosition.x = Mathf_Floor(m_pTweenFunction(m_FromPosition.x, m_Change.x, factor));
	newPosition.y = Mathf_Floor(m_pTweenFunction(m_FromPosition.y, m_Change.y, factor));

	m_fElapsedTime = Mathf_Clamp(m_fElapsedTime + deltaTime, 0.0f, m_fDuration);

	return newPosition;
}
