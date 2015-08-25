#include "TimeManager.h"

GTSINGLETON_IMP(TimeManager);

TimeManager::TimeManager():
	m_fTime(0.0f),
	m_fDeltaTime(0.0f)
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
	m_fTime = (m_LastTime.tv_sec - m_StartTime.tv_sec) + (m_LastTime.tv_usec - m_StartTime.tv_usec) / 1000000.0f;
	m_fDeltaTime = 0.0f;

	return true;
}


bool TimeManager::OnUpdate(void)
{
	struct cocos2d::cc_timeval now;
    if(cocos2d::CCTime::gettimeofdayCocos2d(&now, NULL) != 0)
	{
		m_fTime = 0.0f;
		m_fDeltaTime = 0.0f;
		return false;
	}
	
	m_fTime = (now.tv_sec - m_StartTime.tv_sec) + (now.tv_usec - m_StartTime.tv_usec) / 1000000.0f;
	m_fDeltaTime = (now.tv_sec - m_LastTime.tv_sec) + (now.tv_usec - m_LastTime.tv_usec) / 1000000.0f;
	m_fDeltaTime = MAX(0, m_fDeltaTime);
	m_LastTime = now;

	return true;
}


// Destroy
void TimeManager::OnDestroy(void)
{
}
