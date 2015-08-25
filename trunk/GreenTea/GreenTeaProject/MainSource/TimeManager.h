#ifndef _TIME_MANAGER_H_
#define _TIME_MANAGER_H_

#include <GTGreenTea.h>
#include <cocos2d.h>

class TimeManager : public GTSingleton<TimeManager>
{
public:
	TimeManager();
	~TimeManager();

	// Initialize
	bool OnInitialize(void);
	// Update
	bool OnUpdate(void);
	// Destroy
	void OnDestroy(void);

	// Get time
	float GetTime(void) const
	{
		return m_fTime;
	}
	// Get delta time
	float GetDeltaTime(void) const
	{
		return m_fDeltaTime;
	}

protected:
	// Variable saving start timestamp when the system starts
	cocos2d::cc_timeval m_StartTime;
	// Variable saving last timestamp
	cocos2d::cc_timeval m_LastTime;
	// Current time since the system starts running
	float m_fTime;
	// Delta time since last update
	float m_fDeltaTime;
};

#endif /* _TIME_MANAGER_H_ */
