#ifndef _UI_WIDGET_CLASS_MANAGER_H_
#define _UI_WIDGET_CLASS_MANAGER_H_

#include <GTClassAutoInstanceManager.h>
#include "UIWidget.h"

class UIWidgetClassManager : public GTClassAutoInstanceManager<UIWidget>
{
public:
	UIWidgetClassManager();
	~UIWidgetClassManager();

public:
	static void CreateClassInstanceDefineCallback(GTClassAutoInstanceContainer<UIWidget>* pWidgetClass);
};

#endif /* _UI_WIDGET_CLASS_MANAGER_H_ */
