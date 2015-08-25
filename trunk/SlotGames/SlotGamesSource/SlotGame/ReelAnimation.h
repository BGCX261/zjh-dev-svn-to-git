#ifndef _REEL_ANIMATION_H_
#define _REEL_ANIMATION_H_

#include <GTGreenTea.h>
#include <GTTweenInterpolation.h>

//--------------------------------------
// GTTweener
//--------------------------------------
/*
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
*/

//--------------------------------------
// ReelAnimation
//--------------------------------------
class ReelAnimation
{
public:
	ReelAnimation();
	virtual ~ReelAnimation();
		
	/// <summary>
	/// Start a new Tween if the tween class already exists
	/// </summary>
	/// <param name="from"> The destination of the tween </param>
	/// <param name="to"> The origin of the tween </param>
	/// <param name="duration"> The duration of the tween, in ms </param>
	/// <param name="tweenFunction"> The Tween function to use </param>
	//void Tween(const GTVector2 from, const GTVector2 to, const int32 duration, GTTweenFunction tweenFunction);

	/// <summary>
	/// Get the next position in the tween
	/// </summary>
	/// <param name="time"> The amount of time elapsed since the last tween </param>
	/// <returns> The new position of the tween </returns>
	GTVector2 Update(const int32 deltaTime);

public:
	//_ints = [_startDelay, _windUpDuration / 2, _windUpDuration / 2, _startAccelDuration, _midDuration, -1, _endDuration, 1];
	GT_PROPERTY_DEF_VAR_SET_GET_FLOAT(StartDelay);
	GT_PROPERTY_DEF_VAR_SET_GET_FLOAT(WindUpDuration);
	GT_PROPERTY_DEF_VAR_SET_GET_FLOAT(StartAccelDuration);
	GT_PROPERTY_DEF_VAR_SET_GET_FLOAT(MidDuration);
	GT_PROPERTY_DEF_VAR_SET_GET_FLOAT(EndDuration);
	GT_PROPERTY_DEF_VAR_SET_GET_FLOAT(SymbolSize);
	
private:
	GTVector2 m_FromPosition;
	GTVector2 m_Change;	
};

#endif /* _REEL_ANIMATION_H_ */
