#ifndef _TEST_MANAGER_H_
#define _TEST_MANAGER_H_

#include <GTGreenTea.h>
#include "../common/Singleton.h"
#include "../FrameworkSource/UI/UIBaseDef.h"

class TestManager : public GTObject, public Singleton<TestManager>
{
public:
	TestManager();
	~TestManager();

	// When the object is initialized, this method is called.
	virtual int32 OnInitialize(void);

	// When the system is updated, this method is called for each frame.
	virtual int32 OnUpdate(void);

	// This method is called for rendering each frame.
	virtual int32 OnRender(void);

	// Before the system is shut down, this method is called.
	virtual int32 OnDestroy(void);

	bool UIWidgetEventSingleClick(UIWidget* pWidget, uint32 nFlags, void *pParam);
	// Events
	bool EventManagerCallback1(void *pParam);
	bool EventManagerCallback2(void *pParam);

public:
	UIFrame* m_pDevTestUI;
};

#endif /* _TEST_MANAGER_H_ */
