#ifndef _TWEEN_INTERPOLATION_H_
#define _TWEEN_INTERPOLATION_H_

#include <GTGreenTea.h>
#include "TweenInterpolation.h"

// Tween function pointer
typedef float (*TweenFunction)(float v0, float v1, float factor);

class TweenInterpolation
{
public:
	// Tween type
	static const int32 TweenType_Linear = 0;
	static const int32 TweenType_SinusoidalEaseIn = 1;
	static const int32 TweenType_SinusoidalEaseOut = 2;
	static const int32 TweenType_SinusoidalEaseInOut = 3;
	static const int32 TweenType_QuinticEaseIn = 4;
	static const int32 TweenType_QuinticEaseOut = 5;
	static const int32 TweenType_QuinticEaseInOut = 6;
	static const int32 TweenType_QuarticEaseIn = 7;
	static const int32 TweenType_QuarticEaseOut = 8;
	static const int32 TweenType_QuarticEaseInOut = 9;
	static const int32 TweenType_QuadraticEaseIn = 10;
	static const int32 TweenType_QuadraticEaseOut = 11;
	static const int32 TweenType_QuadraticEaseInOut = 12;
	static const int32 TweenType_ExponentialEaseIn = 13;
	static const int32 TweenType_ExponentialEaseOut = 14;
	static const int32 TweenType_ExponentialEaseInOut = 15;
	static const int32 TweenType_ElasticEaseIn = 16;
	static const int32 TweenType_ElasticEaseOut = 17;
	static const int32 TweenType_ElasticEaseInOut = 18;
	static const int32 TweenType_CubicEaseIn = 19;
	static const int32 TweenType_CubicEaseOut = 20;
	static const int32 TweenType_CubicEaseInOut = 21;
	static const int32 TweenType_CircularEaseIn = 22;
	static const int32 TweenType_CircularEaseOut = 23;
	static const int32 TweenType_CircularEaseInOut = 24;
	static const int32 TweenType_BounceEaseIn = 25;
	static const int32 TweenType_BounceEaseOut = 26;
	static const int32 TweenType_BounceEaseInOut = 27;
	static const int32 TweenType_BackEaseIn = 28;
	static const int32 TweenType_BackEaseOut = 29;
	static const int32 TweenType_BackEaseInOut = 30;	
	
	// Get TweenFunction from the type
	static TweenFunction GetFunctionByType(const int32 type);
	
	static float Linear(float from, float change, float factor);
	static float SinusoidalEaseIn(float from, float change, float factor);
	static float SinusoidalEaseOut(float from, float change, float factor);
	static float SinusoidalEaseInOut(float from, float change, float factor);
	static float QuinticEaseIn(float from, float change, float factor);
	static float QuinticEaseOut(float from, float change, float factor);
	static float QuinticEaseInOut(float from, float change, float factor);
	static float QuarticEaseIn(float from, float change, float factor);
	static float QuarticEaseOut(float from, float change, float factor);
	static float QuarticEaseInOut(float from, float change, float factor);
	static float QuadraticEaseIn(float from, float change, float factor);
	static float QuadraticEaseOut(float from, float change, float factor);
	static float QuadraticEaseInOut(float from, float change, float factor);
	static float ExponentialEaseIn(float from, float change, float factor);
	static float ExponentialEaseOut(float from, float change, float factor);
	static float ExponentialEaseInOut(float from, float change, float factor);
	static float ElasticEaseIn(float from, float change, float factor);
	static float ElasticEaseOut(float from, float change, float factor);
	static float ElasticEaseInOut(float from, float change, float factor);
	static float CubicCubicEaseIn(float from, float change, float factor);
	static float CubicEaseOut(float from, float change, float factor);
	static float CubicEaseInOut(float from, float change, float factor);
	static float CircularEaseIn(float from, float change, float factor);
	static float CircularEaseOut(float from, float change, float factor);
	static float CircularEaseInOut(float from, float change, float factor);
	static float BounceEaseOut(float from, float change, float factor);
	static float BounceEaseIn(float from, float change, float factor);
	static float BounceEaseInOut(float from, float change, float factor);
	/// <summary>
	/// Starts the motion by backtracking and then reversing direction and moving toward the target. 
	/// </summary>
	/// <param name="from">
	/// A <see cref="System.Single"/>
	/// </param>
	/// <param name="change">
	/// A <see cref="System.Single"/>
	/// </param>
	/// <param name="factor">
	/// A <see cref="System.Single"/>
	/// </param>
	/// <returns>
	/// A <see cref="System.Single"/>
	/// </returns>
	static float BackEaseIn(float from, float change, float factor);
	/// <summary>
	/// Starts the motion by moving towards the target, overshooting it slightly, and then reversing direction back toward the target. 
	/// </summary>
	/// <param name="from">
	/// A <see cref="System.Single"/>
	/// </param>
	/// <param name="change">
	/// A <see cref="System.Single"/>
	/// </param>
	/// <param name="factor">
	/// A <see cref="System.Single"/>
	/// </param>
	/// <returns>
	/// A <see cref="System.Single"/>
	/// </returns>
	static float BackEaseOut(float from, float change, float factor);
	/// <summary>
	/// Start the motion by backtracking, then reversing direction and moving toward the target, overshooting the target slightly, reversing direction again, and then moving back toward the target. 
	/// </summary>
	/// <param name="from">
	/// A <see cref="System.Single"/>
	/// </param>
	/// <param name="change">
	/// A <see cref="System.Single"/>
	/// </param>
	/// <param name="factor">
	/// A <see cref="System.Single"/>
	/// </param>
	/// <returns>
	/// A <see cref="System.Single"/>
	/// </returns>
	static float BackEaseInOut(float from, float change, float factor);
};

#endif /* _TWEEN_INTERPOLATION_H_ */
