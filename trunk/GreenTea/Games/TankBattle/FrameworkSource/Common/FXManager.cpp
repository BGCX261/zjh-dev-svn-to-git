#include "FXManager.h"

GTSINGLETON_IMP(FXManager);

FXManager::FXManager()
{
}


FXManager::~FXManager()
{
}


// When the object is initialized, this method is called.
int32 FXManager::OnInitialize(void)
{
	return 1;
}


// When the system is updated, this method is called for each frame.
int32 FXManager::OnUpdate(void)
{
	return 1;
}


// This method is called for rendering each frame.
int32 FXManager::OnRender(void)
{
	return 1;
}


// Before the system is shut down, this method is called.
int32 FXManager::OnDestroy(void)
{
	return 1;
}
