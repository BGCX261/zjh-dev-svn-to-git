#ifndef _TEST_MANAGER_H_
#define _TEST_MANAGER_H_

#include <GTGreenTea.h>
#include <GTSingleton.h>

class TestManager : public GTSingleton<TestManager>
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
};

#endif /* _TEST_MANAGER_H_ */
