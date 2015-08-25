#include "LocalizationManager.h"

GTSINGLETON_IMP(LocalizationManager);

LocalizationManager::LocalizationManager()
{
}


LocalizationManager::LocalizationManager(const LocalizationManager& lm)
{
}


LocalizationManager::~LocalizationManager()
{
}


// When the object is initialized, this method is called.
int32 LocalizationManager::OnInitialize(void)
{
	return 1;
}


// When the system is updated, this method is called for each frame.
int32 LocalizationManager::OnUpdate(void)
{
	return 1;
}


// This method is called for rendering each frame.
int32 LocalizationManager::OnRender(void)
{
	return 1;
}


// Before the system is shut down, this method is called.
int32 LocalizationManager::OnDestroy(void)
{
	return 1;
}


// Get a localized string with its string id.
GTString LocalizationManager::GetLocalizedString(const tchar* szStringId)
{
	if(NULL == szStringId)
	{
		return GTString(GTString::EmptyString);
	}

	return GTString(GTString::EmptyString);
}
