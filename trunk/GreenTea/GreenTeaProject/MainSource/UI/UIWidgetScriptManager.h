#ifndef _UI_WIDGET_SCRIPT_MANAGER_H_
#define _UI_WIDGET_SCRIPT_MANAGER_H_

#include <GTClassAutoInstanceManager.h>
#include "UIWidgetScript.h"

class UIWidgetScriptManager : public GTClassAutoInstanceManager<UIWidgetScript>
{
public:
	UIWidgetScriptManager();
	~UIWidgetScriptManager();

public:
	static void CreateClassInstanceDefineCallback(GTClassAutoInstanceContainer<UIWidgetScript>* pClass);
};

#endif /* _UI_WIDGET_SCRIPT_MANAGER_H_ */
