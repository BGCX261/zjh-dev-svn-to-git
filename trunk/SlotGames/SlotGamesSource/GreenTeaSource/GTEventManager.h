#ifndef _GREENTEA_EVENT_MANAGER_H_
#define _GREENTEA_EVENT_MANAGER_H_

#include "GTBaseDef.h"
#include "GTSingleton.h"
#include "GTDictionary.h"
#include "GTEvent.h"

class GTEventManager : public GTSingleton<GTEventManager>
{
public:
	GTEventManager();
	~GTEventManager();

	// When the object is initialized, this method is called.
	int32 OnInitialize(void);

	// Before the system is shut down, this method is called.
	int32 OnDestroy(void);

	// Add an event listener
	bool AddListener(const GTString& sEventType, GTObject* pClassInst, GTObject_EventCallback2 handler, void* pParam, const int32 nPriority);
	// Remove an event listener
	bool RemoveListener(const GTString& sEventType, GTObject* pClassInst, GTObject_EventCallback2 handler);
	// Invoke callbacks
	bool Invoke(const GTString& sEventType);
	// Reset
	void Reset(void);

protected:
	GTDictionary<GTString, GTEventSlot*> m_EventList;
};

#endif /* _GREENTEA_EVENT_MANAGER_H_ */
