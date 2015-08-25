#include "UnManagedCode.h"

UnManagedCode::UnManagedCode()
{
}


UnManagedCode::~UnManagedCode()
{
}

int __stdcall TestAdd(int a, int b)
{
	return (a + b);
}


int __stdcall TestSub(int a, int b)
{
	return (a - b);
}
