#ifndef _EVENT_NAME_MANAGER_H_
#define _EVENT_NAME_MANAGER_H_

#include <GTBaseDef.h>
#include <GTSingleton.h>

#define EVENTNAMEMANAGER_DEF(_className) static const tchar* _className
#define EVENTNAMEMANAGER_IMP(_className) const tchar* EventNameManager::_className = CTEXT(#_className);

class EventNameManager : public GTSingleton<EventNameManager>
{
public:
	EventNameManager();
	virtual ~EventNameManager();

public:
	// Those events are for SceneManager
	// For single-click event
	EVENTNAMEMANAGER_DEF(EventName_SceneManagerSingleClick);
	// For double-click event
	EVENTNAMEMANAGER_DEF(EventName_SceneManagerDoubleClick);
	// For double-click event
	EVENTNAMEMANAGER_DEF(EventName_SceneManagerMove);

	// Those events are for UIManager
	// For single-click event
	EVENTNAMEMANAGER_DEF(EventName_UIManagerSingleClick);
	// For double-click event
	EVENTNAMEMANAGER_DEF(EventName_UIManagerDoubleClick);
	// For double-click event
	EVENTNAMEMANAGER_DEF(EventName_UIManagerMove);
};

#endif /* _EVENT_NAME_MANAGER_H_ */
