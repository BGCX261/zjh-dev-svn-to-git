#include "UnManagedMethod.h"

__declspec(dllexport) int MathIntAdd(int a, int b)
{
	return (a + b);
}

__declspec(dllexport) int MathIntSub(int a, int b)
{
	return (a - b);
}

__declspec(dllexport) int MathIntMul(int a, int b)
{
	return (a * b);
}

__declspec(dllexport) int MathIntDiv(int a, int b)
{
	return (a / b);
}

