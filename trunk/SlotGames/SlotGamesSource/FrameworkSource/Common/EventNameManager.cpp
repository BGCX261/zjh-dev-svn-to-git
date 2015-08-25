#include "EventNameManager.h"

GTSINGLETON_IMP(EventNameManager)

// Those events are for SceneManager
EVENTNAMEMANAGER_IMP(EventName_SceneManagerSingleClick);
EVENTNAMEMANAGER_IMP(EventName_SceneManagerDoubleClick);
EVENTNAMEMANAGER_IMP(EventName_SceneManagerMove);
// Those events are for UIManager
EVENTNAMEMANAGER_IMP(EventName_UIManagerSingleClick);
EVENTNAMEMANAGER_IMP(EventName_UIManagerDoubleClick);
EVENTNAMEMANAGER_IMP(EventName_UIManagerMove);

EventNameManager::EventNameManager()
{
}


EventNameManager::~EventNameManager()
{
}
