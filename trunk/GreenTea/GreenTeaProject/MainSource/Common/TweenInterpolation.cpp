#include "TweenInterpolation.h"

// Get TweenFunction from the type
TweenFunction TweenInterpolation::GetFunctionByType(const int32 type)
{
	switch(type)
	{
	case TweenType_Linear:
		return Linear;
	case TweenType_SinusoidalEaseIn:
		return SinusoidalEaseIn;
	case TweenType_SinusoidalEaseOut:
		return SinusoidalEaseOut;
	case TweenType_SinusoidalEaseInOut:
		return SinusoidalEaseInOut;
	case TweenType_QuinticEaseIn:
		return QuinticEaseIn;
	case TweenType_QuinticEaseOut:
		return QuinticEaseOut;
	case TweenType_QuinticEaseInOut:
		return QuinticEaseInOut;
	case TweenType_QuarticEaseIn:
		return QuarticEaseIn;
	case TweenType_QuarticEaseOut:
		return QuarticEaseOut;
	case TweenType_QuarticEaseInOut:
		return QuarticEaseInOut;
	case TweenType_QuadraticEaseIn:
		return QuadraticEaseIn;
	case TweenType_QuadraticEaseOut:
		return QuadraticEaseOut;
	case TweenType_QuadraticEaseInOut:
		return QuadraticEaseInOut;
	case TweenType_ExponentialEaseIn:
		return ExponentialEaseIn;
	case TweenType_ExponentialEaseOut:
		return ExponentialEaseOut;
	case TweenType_ExponentialEaseInOut:
		return ExponentialEaseInOut;
	case TweenType_ElasticEaseIn:
		return ElasticEaseIn;
	case TweenType_ElasticEaseOut:
		return ElasticEaseOut;
	case TweenType_ElasticEaseInOut:
		return ElasticEaseInOut;
	case TweenType_CubicEaseIn:
		return CubicCubicEaseIn;
	case TweenType_CubicEaseOut:
		return CubicEaseOut;
	case TweenType_CubicEaseInOut:
		return CubicEaseInOut;
	case TweenType_CircularEaseIn:
		return CircularEaseIn;
	case TweenType_CircularEaseOut:
		return CircularEaseOut;
	case TweenType_CircularEaseInOut:
		return CircularEaseInOut;
	case TweenType_BounceEaseIn:
		return BounceEaseIn;
	case TweenType_BounceEaseOut:
		return BounceEaseOut;
	case TweenType_BounceEaseInOut:
		return BounceEaseInOut;
	case TweenType_BackEaseIn:
		return BackEaseIn;
	case TweenType_BackEaseOut:
		return BackEaseOut;
	case TweenType_BackEaseInOut:
		return BackEaseInOut;
	default:
		return Linear;
	}
}

float TweenInterpolation::Linear(float from, float change, float factor)
{
	return change * factor + from;
}

float TweenInterpolation::SinusoidalEaseIn(float from, float change, float factor)
{
	return -change * Mathf_Cos(factor * (Mathf_PI * 0.5f)) + change + from;
}

float TweenInterpolation::SinusoidalEaseOut(float from, float change, float factor)
{
	return change * Mathf_Sin(factor * (Mathf_PI * 0.5f)) + from;
}

float TweenInterpolation::SinusoidalEaseInOut(float from, float change, float factor)
{
	return -change * 0.5f * (Mathf_Cos(Mathf_PI * factor) - 1) + from;
}

float TweenInterpolation::QuinticEaseIn(float from, float change, float factor)
{
	return change * Mathf_Pow(factor, 5) + from;
}

float TweenInterpolation::QuinticEaseOut(float from, float change, float factor)
{
	return change * (Mathf_Pow((factor - 1.0f), 5) + 1) + from;
}

float TweenInterpolation::QuinticEaseInOut(float from, float change, float factor)
{
	if ((factor *= 2.0f) < 1)
	{
		return change * 0.5f * Mathf_Pow(factor, 5) + from;
	}
	return change * 0.5f * (Mathf_Pow((factor - 2), 5) + 2) + from;
}

float TweenInterpolation::QuarticEaseIn(float from, float change, float factor)
{
	return change * Mathf_Pow(factor, 4) + from;
}

float TweenInterpolation::QuarticEaseOut(float from, float change, float factor)
{
	return -change * (Mathf_Pow((factor - 1.0f), 4) - 1) + from;
}

float TweenInterpolation::QuarticEaseInOut(float from, float change, float factor)
{
	if ((factor *= 2.0f) < 1)
	{
		return change * 0.5f * Mathf_Pow(factor, 4) + from;
	}
	return -change * 0.5f * (Mathf_Pow((factor - 2), 4) - 2) + from;
}

float TweenInterpolation::QuadraticEaseIn(float from, float change, float factor)
{
	return change * factor * factor + from;
}

float TweenInterpolation::QuadraticEaseOut(float from, float change, float factor)
{
	return -change * factor * (factor - 2) + from;
}

float TweenInterpolation::QuadraticEaseInOut(float from, float change, float factor)
{
	if ((factor *= 2) < 1)
	{
		return change * 0.5f * factor * factor + from;
	}
	return -change * 0.5f * ((--factor) * (factor - 2) - 1) + from;
}

float TweenInterpolation::ExponentialEaseIn(float from, float change, float factor)
{
	return (factor == 0.0f) ? from : change * Mathf_Pow(2, 10 * (factor - 1)) + from;
}

float TweenInterpolation::ExponentialEaseOut(float from, float change, float factor)
{
	return (factor == 1.0f) ? from + change : change * (-Mathf_Pow(2, -10 * factor) + 1) + from;
}

float TweenInterpolation::ExponentialEaseInOut(float from, float change, float factor)
{
	if (factor == 0.0f)
	{
		return from;
	}
	if (factor == 1.0f)
	{
		return from + change;
	}
	if ((factor *= 2) < 1)
	{
		return change * 0.5f * Mathf_Pow(2, 10 * (factor - 1)) + from;
	}
	return change * 0.5f * (-Mathf_Pow(2, -10 * --factor) + 2) + from;
}

float TweenInterpolation::ElasticEaseIn(float from, float change, float factor)
{
	if (factor == 0.0f)
	{
		return from;
	}
	if (factor == 1.0f)
	{
		return from + change;
	}
	float p = 0.3f;
	float s = p * 0.25f;
	return -(change * Mathf_Pow(2, 10 * (factor -= 1)) * Mathf_Sin((factor - s) * (2 * Mathf_PI) / p)) + from;
}

float TweenInterpolation::ElasticEaseOut(float from, float change, float factor)
{
	if (factor == 0.0f)
	{
		return from;
	}
	if (factor == 1.0f)
	{
		return from + change;
	}
	float p = 0.3f;
	float s = p * 0.25f;
	return (change * Mathf_Pow(2, -10 * factor) * Mathf_Sin((factor - s) * (2 * Mathf_PI) / p) + change + from);
}

float TweenInterpolation::ElasticEaseInOut(float from, float change, float factor)
{
	if (factor == 0.0f)
	{
		return from;
	}
	if ((factor *= 2) == 2)
	{
		return from + change;
	}
	float p = 0.3f * 1.5f;
	float a = change;
	float s = p * 0.25f;
	if (factor < 1)
	{
		return -0.5f * (a * Mathf_Pow(2, 10 * (factor -= 1)) * Mathf_Sin((factor - s) * (2 * Mathf_PI) / p)) + from;
	}
	return (a * Mathf_Pow(2, -10 * (factor -= 1.0f)) * Mathf_Sin((factor - s) * (2 * Mathf_PI) / p) * 0.5f + change + from);
}

float TweenInterpolation::CubicCubicEaseIn(float from, float change, float factor)
{
	return change * Mathf_Pow(factor, 3) + from;
}

float TweenInterpolation::CubicEaseOut(float from, float change, float factor)
{
	return change * (Mathf_Pow(factor - 1, 3) + 1) + from;
}

float TweenInterpolation::CubicEaseInOut(float from, float change, float factor)
{
	if ((factor *= 2) < 1)
	{
		return change * 0.5f * Mathf_Pow(factor, 3) + from;
	}
	return change * 0.5f * (Mathf_Pow(factor - 2, 3) + 2) + from;
}

float TweenInterpolation::CircularEaseIn(float from, float change, float factor)
{
	return -change * Mathf_Sqrt(1 - (factor * factor) - 1) + from;
}

float TweenInterpolation::CircularEaseOut(float from, float change, float factor)
{
	return change * Mathf_Sqrt(1 - (factor -= 1) * factor) + from;
}

float TweenInterpolation::CircularEaseInOut(float from, float change, float factor)
{
	if ((factor *= 2) < 1)
	{
		return -change * 0.5f * (Mathf_Sqrt(1 - factor * factor) - 1) + from;
	}
	return change * 0.5f * (Mathf_Sqrt(1 - (factor -= 2) * factor) + 1) + from;
}

float TweenInterpolation::BounceEaseOut(float from, float change, float factor)
{
	if ((factor) < (1 / 2.75))
	{
		return change * (7.5625f * factor * factor) + from;
	}

	if (factor < (2 / 2.75))
	{
		return change * (7.5625f * (factor -= (1.5f / 2.75f)) * factor + .75f) + from;
	}

	if (factor < (2.5 / 2.75))
	{
		return change * (7.5625f * (factor -= (2.25f / 2.75f)) * factor + .9375f) + from;
	}
	return change * (7.5625f * (factor -= (2.625f / 2.75f)) * factor + .984375f) + from;
}

float TweenInterpolation::BounceEaseIn(float from, float change, float factor)
{
	return change - BounceEaseOut(0, change, 1.0f - factor) + from;
}

float TweenInterpolation::BounceEaseInOut(float from, float change, float factor)
{
	if (factor < 0.5f)
	{
		return BounceEaseIn(0, change, factor * 2) * 0.5f + from;
	}
	return BounceEaseOut(0, change, factor * 2 - 1.0f) * .5f + change * 0.5f + from;
}

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
float TweenInterpolation::BackEaseIn(float from, float change, float factor)
{
	return change * factor * factor * ((1.70158f + 1) * factor - 1.70158f) + from;
}

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
float TweenInterpolation::BackEaseOut(float from, float change, float factor)
{
	return change * ((factor -= 1) * factor * ((1.70158f + 1) * factor + 1.70158f) + 1) + from;
}

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
float TweenInterpolation::BackEaseInOut(float from, float change, float factor)
{
	float s = 1.70158f;
	if ((factor *= 2) < 1)
	{
		return change * 0.5f * (factor * factor * (((s *= (1.525f)) + 1) * factor - s)) + from;
	}
	return change * 0.5f * ((factor -= 2) * factor * (((s *= (1.525f)) + 1) * factor + s) + 2) + from;
}
