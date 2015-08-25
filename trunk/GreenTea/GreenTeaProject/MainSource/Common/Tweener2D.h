#ifndef _TWEENER_2D_H_
#define _TWEENER_2D_H_

#include "Tweener.h"

class Tweener2D : public Tweener
{
public:
	Tweener2D();
	virtual ~Tweener2D();
		
	/// <summary>
	/// Start a new Tween if the tween class already exists
	/// </summary>
	/// <param name="from"> The destination of the tween </param>
	/// <param name="to"> The origin of the tween </param>
	/// <param name="duration"> The duration of the tween </param>
	/// <param name="tweenFunction"> The Tween function to use </param>
	void Tween(const GTVector2 from, const GTVector2 to, const float duration, TweenFunction tweenFunction);

	/// <summary>
	/// Get the next position in the tween
	/// </summary>
	/// <param name="time"> The amout of time elapsed since the last tween </param>
	/// <returns> The new position of the tween </returns>
	GTVector2 Update(const float deltaTime);

private:
	GTVector2 m_FromPosition;
	GTVector2 m_Change;
};

#endif /* _TWEENER_2D_H_ */
