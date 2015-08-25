#ifndef _GREENTEA_TWEENER_2D_H_
#define _GREENTEA_TWEENER_2D_H_

#include <GTGreenTea.h>
#include <GTTweenInterpolation.h>

//--------------------------------------
// GTTweener
//--------------------------------------
class GTTweener
{
public:
	GTTweener();
	virtual ~GTTweener();

	GT_PROPERTY_DEF_VAR_SET_GET_FLOAT(Duration);
	GT_PROPERTY_DEF_VAR_SET_GET_FLOAT(ElapsedTime);

protected:
	GTTweenFunction m_pTweenFunction;
};


//--------------------------------------
// GTTweener2D
//--------------------------------------
class GTTweener2D : public GTTweener
{
public:
	GTTweener2D();
	virtual ~GTTweener2D();
		
	/// <summary>
	/// Start a new Tween if the tween class already exists
	/// </summary>
	/// <param name="from"> The destination of the tween </param>
	/// <param name="to"> The origin of the tween </param>
	/// <param name="duration"> The duration of the tween, in ms </param>
	/// <param name="tweenFunction"> The Tween function to use </param>
	void Tween(const GTVector2 from, const GTVector2 to, const int32 duration, GTTweenFunction tweenFunction);

	/// <summary>
	/// Get the next position in the tween
	/// </summary>
	/// <param name="time"> The amount of time elapsed since the last tween </param>
	/// <returns> The new position of the tween </returns>
	GTVector2 Update(const int32 deltaTime);

private:
	GTVector2 m_FromPosition;
	GTVector2 m_Change;
};


//--------------------------------------
// GTTweenerInteger
//--------------------------------------
class GTTweenerInteger : public GTTweener
{
public:
	GTTweenerInteger();
	virtual ~GTTweenerInteger();
		
	/// <summary>
	/// Start a new Tween if the tween class already exists
	/// </summary>
	/// <param name="from"> The destination of the tween </param>
	/// <param name="to"> The origin of the tween </param>
	/// <param name="duration"> The duration of the tween, in ms </param>
	/// <param name="tweenFunction"> The Tween function to use </param>
	void Tween(const int32 from, const int32 to, const int32 duration, GTTweenFunction tweenFunction);

	/// <summary>
	/// Get the next position in the tween
	/// </summary>
	/// <param name="time"> The amount of time elapsed since the last tween </param>
	/// <returns> The new position of the tween </returns>
	int32 Update(const int32 deltaTime);

private:
	int32 m_FromPosition;
	int32 m_Change;
};

#endif /* _GREENTEA_TWEENER_2D_H_ */
