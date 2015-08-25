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

	// Get time, in millisecond
	long GetTime(void) const;
	/*
	// Get delta time, in millisecond
	long GetDeltaTime(void) const
	{
		return m_lDeltaTime;
	}
	*/

	static long QueryTime(void)
	{
		return TimeManager::GetInstance()->GetTime();
	}
	/*
	static long QueryDeltaTime(void)
	{
		return TimeManager::GetInstance()->GetDeltaTime();
	}
	*/

protected:
	// Variable saving start timestamp when the system starts
	cocos2d::cc_timeval m_StartTime;
	/*
	// Variable saving last timestamp
	cocos2d::cc_timeval m_LastTime;
	// Current time since the system starts running in seconds
	long m_lTime;
	// Delta time since last update in seconds
	long m_lDeltaTime;
	*/
};

#endif /* _TIME_MANAGER_H_ */
