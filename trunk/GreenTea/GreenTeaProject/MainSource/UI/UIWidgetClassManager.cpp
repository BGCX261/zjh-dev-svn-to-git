#include "UIWidgetClassManager.h"

UIWidgetClassManager::UIWidgetClassManager() : GTClassAutoInstanceManager<UIWidget>()
{
}


UIWidgetClassManager::~UIWidgetClassManager()
{
	GTClassAutoInstanceManager<UIWidget>::Release();
}


void UIWidgetClassManager::CreateClassInstanceDefineCallback(GTClassAutoInstanceContainer<UIWidget>* pWidgetClass)
{
	if(NULL == pWidgetClass)
	{
		return;
	}

	UIWidgetClassManager::GetInstance()->AddClass(pWidgetClass);
}
