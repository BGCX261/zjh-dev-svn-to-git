#ifndef _GREENTEA_EVENT_H_
#define _GREENTEA_EVENT_H_

#include "GTBaseDef.h"
#include "GTObject.h"
#include "GTList.h"

// Event callbacks
// Event callbacks for the classes deriving from GTObject
typedef void (GTObject::*GTObject_EventCallback)(void *pParam);
typedef bool (GTObject::*GTObject_EventCallback2)(void *pParam);
#define GTObject_EventCallback_Set(_value) (GTObject_EventCallback)(&_value)
#define GTObject_EventCallback2_Set(_value) (GTObject_EventCallback2)(&_value)
// The callback for static methods
typedef void (*GTStatic_EventCallback)(void *pParam);

// GTEventSlotItem
struct GTEventSlotItem
{
	// Priority of this item
	int32 nPriority;
	// Class instance
	GTObject* pClassInst;
	// Callback
	GTObject_EventCallback2 pCallback;
	// Parameter
	void* pParam;
};

// GTEventSlot
class GTEventSlot
{
public:
	GTEventSlot();
	~GTEventSlot();
	// Remove an event listener
	bool Remove(GTObject* pClassInst, GTObject_EventCallback2 handler);

public:
	// Event name
	GTString m_sEventName;
	// Callback list
	GTList<GTEventSlotItem> m_EventList;
	
};

#endif /* _GREENTEA_EVENT_H_ */
