#include "GTEventManager.h"
#include <GTLog/GTLogManager.h>

#ifdef GT_DEBUG
#include <GTNew.h>
#endif // GT_DEBUG

GTSINGLETON_IMP(GTEventManager);

GTEventManager::GTEventManager()
{
}


GTEventManager::~GTEventManager()
{
}


// When the object is initialized, this method is called.
int32 GTEventManager::OnInitialize(void)
{
	return 1;
}


// Before the system is shut down, this method is called.
int32 GTEventManager::OnDestroy(void)
{
	Reset();

	return 1;
}


bool GTEventManagerSortFunction(const GTEventSlotItem& a, const GTEventSlotItem& b)
{
	return (a.nPriority < b.nPriority);
}


// Add an event listener
bool GTEventManager::AddListener(
	const GTString& sEventType,
	GTObject* pClassInst,
	GTObject_EventCallback2 handler,
	void* pParam,
	const int32 nPriority
	)
{
	if(sEventType.Length() == 0 || NULL == pClassInst || NULL == handler)
		return false;

	GTEventSlotItem esi;
	GTEventSlot* pES = NULL;
	if(m_EventList.KeyExists(sEventType))
	{		
		// The event exists
		if(m_EventList.GetValueByKey(sEventType, pES))
		{
			if(pES)
			{
				esi.nPriority = nPriority;
				esi.pClassInst = pClassInst;
				esi.pCallback = handler;
				esi.pParam = pParam;
				// Add
				pES->m_EventList.AddToTail(esi);
				// Sort
				pES->m_EventList.Sort(GTEventManagerSortFunction);
			}
		}
	}
	else
	{
		// The event doesn't exist
		esi.nPriority = nPriority;
		esi.pClassInst = pClassInst;
		esi.pCallback = handler;
		esi.pParam = pParam;

		pES = new GTEventSlot();
		pES->m_sEventName = sEventType;
		pES->m_EventList.AddToTail(esi);

		m_EventList.Add(sEventType, pES);
	}
	
	return true;
}


// Remove an event listener
bool GTEventManager::RemoveListener(
	const GTString& sEventType,
	GTObject* pClassInst,
	GTObject_EventCallback2 handler
	)
{
	if(sEventType.Length() == 0 || NULL == pClassInst || NULL == handler)
		return false;

	GTEventSlot* pES = NULL;
	if(m_EventList.KeyExists(sEventType))
	{		
		// The event exists
		if(m_EventList.GetValueByKey(sEventType, pES))
		{
			pES->Remove(pClassInst, handler);
			// If there are no more event listeners, delete pES
			if(0 == pES->m_EventList.Count())
			{
				m_EventList.Remove(pES->m_sEventName);
				delete pES;
				pES = NULL;
			}
		}
	}

	return true;
}


// Invoke callbacks
bool GTEventManager::Invoke(const GTString& sEventType)
{
	if(sEventType.Length() == 0)
		return false;

	GTEventSlot* pES = NULL;
	if(m_EventList.KeyExists(sEventType))
	{
		// The event exists
		if(m_EventList.GetValueByKey(sEventType, pES))
		{
			GTEventSlotItem esi;
			GTList<GTEventSlotItem>::ObjectTypeIterator it, itNext;
			// First item
			it = pES->m_EventList.Begin();
			while(it != pES->m_EventList.End())
			{
				itNext = it;
				// Point to next item
				itNext++;
				// Invoke callback
				esi = (*it);
				// If the listener callback returns false, the callback will be removed
				if(false == (esi.pClassInst->*esi.pCallback)(esi.pParam))
				{
					// Removing this event from the list
					pES->m_EventList.Erase(it);
				}
				// Process next item
				it = itNext;
			}

			// If there are no more event listeners, delete pES
			if(0 == pES->m_EventList.Count())
			{
				m_EventList.Remove(pES->m_sEventName);
				delete pES;
				pES = NULL;
			}
		}
	}

	return true;
}


// Reset
void GTEventManager::Reset(void)
{
	GTDictionary<GTString, GTEventSlot*>::ObjectTypeIterator it;
	while(m_EventList.Count())
	{
		GTEventSlot* pES = m_EventList.Begin()->second;
		if(pES)
		{
			// Remove current item from the list
			m_EventList.Remove(pES->m_sEventName);
			// Release
			pES->m_EventList.Clear();
			pES->m_sEventName = CTEXT("");
			delete pES;
			pES = NULL;
		}
	}
}
