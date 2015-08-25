#ifndef _SYSTEM_MANAGER_H_
#define _SYSTEM_MANAGER_H_

#include <GTGameObject.h>
#include <GTSingleton.h>

class SystemManager : public GTGameObject, public GTSingleton<SystemManager>
{
public:
	SystemManager();
	~SystemManager();

	// When the object is initialized, this method is called.
	virtual int32 OnInitialize(void);

	// When the system is updated, this method is called for each frame.
	virtual int32 OnUpdate(void);

	// This method is called for rendering each frame.
	virtual int32 OnRender(void);

	// Before the system is shut down, this method is called.
	virtual int32 OnDestroy(void);

	// Get current time in second since the system starts.
	float GetTime(void) const
	{
		return m_fCurrentTime;
	}

	// Get delta time in second since last update.
	float GetDeltaTime(void) const
	{
		return m_fDeltaTime;
	}

private:
	// Current time, in second
	float m_fCurrentTime;
	// Delta time, in second
	float m_fDeltaTime;
};

#endif /* _SYSTEM_MANAGER_H_ */
