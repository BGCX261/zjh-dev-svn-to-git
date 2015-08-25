#include "GTGameObjectClassManager.h"

GTGameObjectClassManager::GTGameObjectClassManager() : GTClassAutoInstanceManager<GTGameObject>()
{
}


GTGameObjectClassManager::~GTGameObjectClassManager()
{
	GTClassAutoInstanceManager<GTGameObject>::Release();
}


void GTGameObjectClassManager::CreateClassInstanceDefineCallback(GTClassAutoInstanceContainer<GTGameObject>* pWidgetClass)
{
	if(NULL == pWidgetClass)
	{
		return;
	}

	GTGameObjectClassManager::GetInstance()->AddClass(pWidgetClass);
}
