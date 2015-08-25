#ifndef _INPUT_MANAGER_H_
#define _INPUT_MANAGER_H_

#include <GTBaseDef.h>
#include <GTSingleton.h>
#include <GTPoint2.h>
#include <GTString.h>
#include <GTList.h>
#include <GTDictionary.h>

class InputManager : public GTSingleton<InputManager>
{
private:
	// The callback for the event
	typedef int32 (*InputEventDelegate)(const uint32 nFlags, const GTPoint2 point, void* pParam);
	// The event container for each registration
	class EventContainer
	{
	public:
		EventContainer(InputEventDelegate pDelegate, void* pParam)
		{
			m_pDelegate = pDelegate;
			m_pParam = pParam;
		}

		~EventContainer()
		{
			Release();
		}

		void Release()
		{
			if(m_pDelegate)
			{
				m_pDelegate = NULL;
				m_pParam = NULL;

				delete this;
			}
		}

	public:
		// Event name
		GTString m_sName;
		// Event callback
		InputEventDelegate m_pDelegate;
		// User parameters
		void* m_pParam;
	};

	// Helper typedef
	//typedef GTDictionary<GTString, EventContainer*> GTDictionaryEventContainer;
	//typedef GTDictionary<GTString, EventContainer*>::KeyValuePair GTDictionaryEventContainerKeyValuePair;
	typedef GTList<EventContainer*> GTEventContainer;

public:
	// Event type
	typedef enum
	{
		// Single click event
		EventType_SingleClick = 0,
		// Double click event
		EventType_DoubleClick = 1,
		// Movement event
		EventType_Move = 2,
		// Event count
		EventType_Count,
	} EventType;	

public:
	InputManager();
	~InputManager();
	
	// Single-click event
	// The original (0, 0) is at left-bottom of the screen
	bool OnSingleClickEvent(const uint32 nFlags, const GTPoint2& point);
	// Double-click event
	// The original (0, 0) is at left-bottom of the screen
	bool OnDoubleClickEvent(const uint32 nFlags, const GTPoint2& point);
	// Move event
	// The original (0, 0) is at left-bottom of the screen
	bool OnMoveEvent(const uint32 nFlags, const GTPoint2& point);

	// Register an event
	bool RegisterEvent(
		const EventType eventType,
		const tchar* szName,
		const InputEventDelegate pCallback,
		void* pParam
		);
	// Unregister an event
	bool UnregisterEvent(const EventType eventType, const tchar* szName);
	/*
	// Regist an event for single-click
	bool RegisterSingleClickEvent(const tchar* szName, const InputEventDelegate pCallback, void* pParam);
	// Regist an event for double-click
	bool RegisterDoubleClickEvent(const tchar* szName, const InputEventDelegate pCallback, void* pParam);
	// Regist an event for move
	bool RegisterMoveEvent(const tchar* szName, const InputEventDelegate pCallback, void* pParam);
	// Unregist an event for single-click
	bool UnregisterSingleClickEvent(const tchar* szName);
	// Unregist an event for double-click
	bool UnregisterDoubleClickEvent(const tchar* szName);
	// Unregist an event for move
	bool UnregisterMoveEvent(const tchar* szName);
	*/
	// Release all event list
	bool Release();

private:
	// Helper method to get an event list according to event type
	GTEventContainer* GetEventList(const int32 nEventType);
	/*
	// Helper method to register a click event
	bool RegisterEvent(GTDictionaryEventContainer *pEventList, const tchar* szName, const InputEventDelegate pCallback, void* pParam);
	// Helper method to unregister a click event
	bool UnregisterEvent(GTDictionaryEventContainer *pEventList, const tchar* szName);
	*/
	// Helper method to call click event
	bool OnEvent(GTEventContainer *pEventList, const uint32 nFlags, const GTPoint2 position);
	// Helper method to release an event list
	bool ReleaseEventList(GTEventContainer *pEventList);

private:
	// Event list for all events
	GTEventContainer m_EventList[EventType_Count];
};

#endif /* _INPUT_MANAGER_H_ */
