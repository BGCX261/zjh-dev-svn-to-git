#ifndef _GREENTEA_COMMAND_MANAGER_H_
#define _GREENTEA_COMMAND_MANAGER_H_

#include "GTBaseDef.h"
#include "GTSingleton.h"
#include "GTDictionary.h"
#include "GTEvent.h"
#include <string>
#include <deque>

struct GTCommandSlot
{
	int32 nPriority;
	std::string sEventName;
};

class GTCommandManager : public GTSingleton<GTCommandManager>
{
public:
	GTCommandManager();
	~GTCommandManager();

	// When the object is initialized, this method is called.
	int32 OnInitialize(void);

	// When the object is initialized, this method is called.
	int32 OnUpdate(void);

	// Before the system is shut down, this method is called.
	int32 OnDestroy(void);
	
	// Add a command
	bool AddCommand(const tchar* szEventName, const int32 nPriority);
	// Remove a command
	bool RemoveCommand(const tchar* szEventName);
	// Reset
	void Reset(void);

protected:
	std::deque<GTCommandSlot> m_CommandList;
};

#endif /* _GREENTEA_COMMAND_MANAGER_H_ */
