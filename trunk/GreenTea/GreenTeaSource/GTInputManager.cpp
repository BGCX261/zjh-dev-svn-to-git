#include <GTInputManager.h>
#include <GTLog/GTLogManager.h>

GTSINGLETON_IMP(GTInputManager);

GTInputManager::GTInputManager()
{
}


GTInputManager::GTInputManager(const GTInputManager& im)
{
}


GTInputManager::~GTInputManager()
{
	Release();
}


// Helper method to release an event list
bool GTInputManager::ReleaseEventList(GTEventContainer *pEventList)
{
	if(NULL == pEventList)
	{
		return false;
	}

	for(GTEventContainer::ObjectTypeIterator it = pEventList->Begin();
		it != pEventList->End();
		it++)
	{
		if((*it))
		{
			EventContainer *pEC = (*it);
			if(pEC)
			{
				pEC->Release();
				pEC = NULL;
			}
		}
	}

	pEventList->Clear();
	
	return true;
}


// Release all event list
bool GTInputManager::Release()
{
	for(int32 i=0; i<EventType_Count; i++)
	{
		ReleaseEventList(GetEventList(i));
	}

	return true;
}


// Register an event
bool GTInputManager::RegisterEvent(
	const EventType eventType,
	const tchar* szName,
	const InputEventDelegate pCallback,
	void* pParam
	)
{
	if(eventType >= EventType_Count || NULL == szName || NULL == pCallback)
	{
		return false;
	}
	if(0 == StringLength(szName))
	{
		return false;
	}

	// Get the event list according to event type
	GTEventContainer *pEventList = GetEventList(eventType);
	if(NULL == pEventList)
	{
		return false;
	}
	// Create a new EventContainer object
	EventContainer* pEventContainer = new EventContainer(pCallback, pParam);
	if(NULL == pEventContainer)
	{
		GTLogManager::GetInstance()->LogFormatError(CTEXT("Failed to new EventContainer object with the name = %s"), szName);
		return false;
	}
	// Add this event into the event list
	pEventList->AddToTail(pEventContainer);

	return true;
}


// Unregister an event
bool GTInputManager::UnregisterEvent(const EventType eventType, const tchar* szName)
{
	if(eventType >= EventType_Count || NULL == szName)
	{
		return false;
	}
	if(0 == StringLength(szName))
	{
		return false;
	}

	// Get the event list according to event type
	GTEventContainer *pEventList = GetEventList(eventType);
	if(NULL == pEventList)
	{
		return false;
	}
	EventContainer *pResult = NULL;
	for(GTEventContainer::ObjectTypeIterator it = pEventList->Begin();
		it != pEventList->End();
		it++)
	{
		if((*it)->m_sName == szName)
		{
			pResult = (*it);
			break;
		}
	}

	if(pResult)
	{
		// Remove this event from the event list
		pEventList->Remove(pResult);
		// Release this EventContainer
		pResult->Release();
		pResult = NULL;

		return true;
	}

	return true;
}


// Helper method to get an event list according to event type
GTInputManager::GTEventContainer* GTInputManager::GetEventList(const int32 nEventType)
{
	if(nEventType >= EventType_Count)
	{
		return NULL;
	}

	return &m_EventList[nEventType];
}


// Helper method to call event callback
bool GTInputManager::OnEvent(GTEventContainer *pEventList,
							 const uint32 nFlags,
							 const GTPoint2 point)
{
	if(NULL == pEventList)
	{
		return false;
	}

	for(GTEventContainer::ObjectTypeIterator it = pEventList->Begin();
		it != pEventList->End();
		it++)
	{
		// Get the value from the dictionary pair
		EventContainer *pEC = (*it);
		if(pEC && pEC->m_pDelegate)
		{
			if(pEC->m_pDelegate(nFlags, point, pEC->m_pParam))
			{
				// If m_pDelegate returns true, this event is not going to
				// pass further.
				break;
			}
		}
	}

	return true;
}


// Single click event
// The original (0, 0) is at left-bottom of the screen
bool GTInputManager::OnSingleClickEvent(const uint32 nFlags, const GTPoint2& point)
{
	return OnEvent(GetEventList(EventType_SingleClick), nFlags, point);
}


// Double click event
// The original (0, 0) is at left-bottom of the screen
bool GTInputManager::OnDoubleClickEvent(const uint32 nFlags, const GTPoint2& point)
{
	return OnEvent(GetEventList(EventType_DoubleClick), nFlags, point);
}


// Move event
// The original (0, 0) is at left-bottom of the screen
bool GTInputManager::OnMoveEvent(const uint32 nFlags, const GTPoint2& point)
{
	return OnEvent(GetEventList(EventType_Move), nFlags, point);
}
