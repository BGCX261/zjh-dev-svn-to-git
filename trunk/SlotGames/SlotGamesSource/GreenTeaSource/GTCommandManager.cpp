#include "GTCommandManager.h"
#include "GTEventManager.h"
#include <GTLog/GTLogManager.h>
#include <algorithm>

GTSINGLETON_IMP(GTCommandManager);

GTCommandManager::GTCommandManager()
{
}


GTCommandManager::~GTCommandManager()
{
}


// When the object is initialized, this method is called.
int32 GTCommandManager::OnInitialize(void)
{
	return 1;
}


// When the object is initialized, this method is called.
int32 GTCommandManager::OnUpdate(void)
{
	// After process each item, remove it from the list.
	std::deque<GTCommandSlot>::iterator it = m_CommandList.begin();
	while(it != m_CommandList.end())
	{
		// Call the event listeners in the event manager
		GTEventManager::Inst()->Invoke((*it).sEventName.c_str());
		// Remove this item from the list
		m_CommandList.pop_front();
		// Next item
		it = m_CommandList.begin();
	}

	return 1;
}


// Before the system is shut down, this method is called.
int32 GTCommandManager::OnDestroy(void)
{
	return 1;
}


// Event with hi-priority is called first
// 0 is the lowest priority
static bool GTCommandManagerSortFunction(const GTCommandSlot& a, const GTCommandSlot& b)
{
	return (a.nPriority > b.nPriority);
}


// Add a command
bool GTCommandManager::AddCommand(const tchar* szEventName, const int32 nPriority)
{
	if(NULL == szEventName)
		return false;
	
	GTCommandSlot cs;
	std::string str = std::string(szEventName);
	// Check if this event already exists
	for(std::deque<GTCommandSlot>::iterator it = m_CommandList.begin();
		it != m_CommandList.end();
		it++)
	{
		if((*it).sEventName == str)
		{
			// Found it so the event already exists
			return false;
		}
	}
	// Add this command to the list
	cs.sEventName = str;
	cs.nPriority = nPriority;
	m_CommandList.push_back(cs);
	// Sort the list by priority
	std::sort(m_CommandList.begin(), m_CommandList.end(), GTCommandManagerSortFunction);

	return true;
}


// Remove a command
bool GTCommandManager::RemoveCommand(const tchar* szEventName)
{
	if(NULL == szEventName)
		return false;

	std::string str = std::string(szEventName);
	bool bFound = false;
	std::deque<GTCommandSlot>::iterator it;
	for(it = m_CommandList.begin(); it != m_CommandList.end(); it++)
	{
		if((*it).sEventName == str)
		{
			// The command already exists
			bFound = true;
			break;
		}
	}
	// Remove this command from the list
	m_CommandList.erase(it);

	return true;
}


// Reset
void GTCommandManager::Reset(void)
{
	m_CommandList.clear();
}
