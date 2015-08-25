#ifndef _UI_WIDGET_EVENT_H_
#define _UI_WIDGET_EVENT_H_

#include <GTGreenTea.h>

class UIWidget;

class UIWidgetEvent
{
public:
	// Events
	static const int32 EventTypeSingleClick = 0;
	static const int32 EventTypeDoubleClick = 1;
	static const int32 EventTypeMove = 2;
	static const int32 EventTypeCount = 3;
};

// Callback for UIWidget events
typedef bool (GTObject::*UIWidgetEventCallback)(UIWidget* pWidget, uint32 nFlags, void *pParam);
typedef bool (GTObject::*UIWidgetEventCallback2)(UIWidget* pWidget, void *pParam);
#define UIWidget_EventCallback_Set(_value) (UIWidgetEventCallback)(&_value)
#define UIWidget_EventCallback2_Set(_value) (UIWidgetEventCallback2)(&_value)

// For callback UIWidgetEventCallback
struct UIWidgetEventSlot
{
	GTString sEventName;
	// Class instance
	GTObject* pClassInst;
	// Callback
	UIWidgetEventCallback pCallback;
	// Parameter
	void* pParam;
};

// For callback UIWidgetEventCallback2
struct UIWidgetEventSlot2
{
	GTString sEventName;
	// Class instance
	GTObject* pClassInst;
	// Callback
	UIWidgetEventCallback2 pCallback;
	// Parameter
	void* pParam;
};

class UIWidgetEvent2
{
public:
	UIWidgetEvent2();
	virtual ~UIWidgetEvent2();

	void Clear(void);
	// Add an event listener
	bool AddEventListener(
		GTString sEventName,
		GTObject* pClassInst,
		UIWidgetEventCallback2 pCallback,
		void* pParam);
	bool AddEventListener(
		GTObject* pClassInst,
		UIWidgetEventCallback2 pCallback,
		void* pParam)
	{
		return AddEventListener(CTEXT("no-name"), pClassInst, pCallback, pParam);
	}
	// Invoke all event listeners
	bool Invoke(UIWidget* pWidget);

public:
	GTList<UIWidgetEventSlot2> m_EventList;
};

#endif /* _UI_WIDGET_EVENT_H_ */
