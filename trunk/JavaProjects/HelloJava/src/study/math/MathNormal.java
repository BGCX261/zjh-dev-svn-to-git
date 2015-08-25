package study.math;

public class MathNormal extends BasicMath
{
	@Override public float Add(float v1, float v2)
	{
		return v1 + v2;
	}
	
	@Override public float Sub(float v1, float v2)
	{
		return v1 - v2;
	}
	
	@Override public float Mul(float v1, float v2)
	{
		return v1 * v2;
	}
	
	@Override public float Div(float v1, float v2)
	{
		return v1 / v2;
	}
}
