#include "TimeManager.h"

GTSINGLETON_IMP(TimeManager);

TimeManager::TimeManager():
	m_lTime(0L),
	m_lDeltaTime(0L)
{	
}


TimeManager::~TimeManager()
{
}


// Initialize
bool TimeManager::OnInitialize(void)
{
	cocos2d::CCTime::gettimeofdayCocos2d(&m_StartTime, NULL);
	cocos2d::CCTime::gettimeofdayCocos2d(&m_LastTime, NULL);
	m_lTime = (m_LastTime.tv_sec - m_StartTime.tv_sec) * 1000 + (m_LastTime.tv_usec - m_StartTime.tv_usec) / 1000;
	m_lDeltaTime = 0.0f;

	return true;
}


bool TimeManager::OnUpdate(void)
{
	static struct cocos2d::cc_timeval now;
    if(cocos2d::CCTime::gettimeofdayCocos2d(&now, NULL) != 0)
	{
		m_lTime = 0.0f;
		m_lDeltaTime = 0.0f;
		return false;
	}
	
	m_lTime = (now.tv_sec - m_StartTime.tv_sec) * 1000 + (now.tv_usec - m_StartTime.tv_usec) / 1000;
	m_lDeltaTime = (now.tv_sec - m_LastTime.tv_sec) * 1000 + (now.tv_usec - m_LastTime.tv_usec) / 1000;
	m_lDeltaTime = MAX(0, m_lDeltaTime);
	m_LastTime = now;

	return true;
}


// Destroy
void TimeManager::OnDestroy(void)
{
}
