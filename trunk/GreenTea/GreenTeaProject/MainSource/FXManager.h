#ifndef _FX_MANAGER_H_
#define _FX_MANAGER_H_

#include <GTGameObject.h>
#include <GTSingleton.h>

class FXManager : public GTGameObject, public GTSingleton<FXManager>
{
public:
	FXManager();
	~FXManager();

	// When the object is initialized, this method is called.
	virtual int32 OnInitialize(void);

	// When the system is updated, this method is called for each frame.
	virtual int32 OnUpdate(void);

	// This method is called for rendering each frame.
	virtual int32 OnRender(void);

	// Before the system is shut down, this method is called.
	virtual int32 OnDestroy(void);
};

#endif /* _FX_MANAGER_H_ */
