#include "GTEvent.h"

#ifdef GT_DEBUG
#include <GTNew.h>
#endif // GT_DEBUG

//-------------------------------------
// GTEventSlot
//-------------------------------------
GTEventSlot::GTEventSlot() : m_sEventName(CTEXT("no-event-name"))
{
}


GTEventSlot::~GTEventSlot()
{
}


// Remove an event listener
bool GTEventSlot::Remove(GTObject* pClassInst, GTObject_EventCallback2 handler)
{
	if(NULL == pClassInst || NULL == handler)
		return false;

	GTEventSlotItem esi;
	for(GTList<GTEventSlotItem>::ObjectTypeIterator it = m_EventList.Begin();
		it != m_EventList.End();
		it++)
	{
		esi = (*it);
		if(esi.pClassInst == pClassInst && esi.pCallback == handler)
		{
			// Found and remove it
			m_EventList.Erase(it);
			return true;
		}
	}

	return false;
}
