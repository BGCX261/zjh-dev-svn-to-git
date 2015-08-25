#include "UIWidget.h"
#include "UIWidgetEvent.h"


//---------------------------------------------
// UIWidgetEvent2
//---------------------------------------------
UIWidgetEvent2::UIWidgetEvent2()
{
}


UIWidgetEvent2::~UIWidgetEvent2()
{
}


void UIWidgetEvent2::Clear(void)
{
	m_EventList.Clear();
}


bool UIWidgetEvent2::AddEventListener(
		GTString sEventName,
		GTObject* pClassInst,
		UIWidgetEventCallback2 pCallback,
		void* pParam)
{
	UIWidgetEventSlot2 es;
	es.sEventName = sEventName;
	es.pClassInst = pClassInst;
	es.pCallback = pCallback;
	es.pParam = pParam;

	// Add this listener to the list
	m_EventList.AddToTail(es);

	return true;
}


// Invoke all event listeners
bool UIWidgetEvent2::Invoke(UIWidget* pWidget)
{
	UIWidgetEventSlot2 es;	
	for(GTList<UIWidgetEventSlot2>::ObjectTypeIterator it = m_EventList.Begin();
		it != m_EventList.End();
		it++)
	{
		es = (*it);
		(es.pClassInst->*es.pCallback)(pWidget, es.pParam);
	}

	return true;
}
