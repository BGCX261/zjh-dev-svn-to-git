#include "UIWidgetScriptManager.h"

UIWidgetScriptManager::UIWidgetScriptManager() : GTClassAutoInstanceManager<UIWidgetScript>()
{
}


UIWidgetScriptManager::~UIWidgetScriptManager()
{
	GTClassAutoInstanceManager<UIWidgetScript>::Release();
}


void UIWidgetScriptManager::CreateClassInstanceDefineCallback(GTClassAutoInstanceContainer<UIWidgetScript>* pClass)
{
	if(NULL == pClass)
	{
		return;
	}

	UIWidgetScriptManager::GetInstance()->AddClass(pClass);
}
