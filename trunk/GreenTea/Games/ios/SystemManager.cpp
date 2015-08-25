#include "../main/SystemManager.h"

SINGLETON_IMP(SystemManager);

// Start time since the system starts
static float g_fSystemManagerStartTime = 0.0f;

SystemManager::SystemManager()
{
	// Current time, in second
	m_fCurrentTime = 0.0f;
	// Delta time, in second
	m_fDeltaTime = 0.0f;
}

SystemManager::~SystemManager()
{
}

// When the object is initialized, this method is called.
int32 SystemManager::OnInitialize(void)
{
	// Save start time, converting to second from millsecond.
#ifdef OS_WINDOWS
	g_fSystemManagerStartTime = (float)::timeGetTime() / 1000.0f;
#endif /* OS_WINDOWS */
	
#ifdef OS_APPLE_IOS
#endif /* OS_APPLE_IOS */
	
		
	return 1;
}


// When the system is updated, this method is called for each frame.
int32 SystemManager::OnUpdate(void)
{
	float fCurrentTime = 0.0f;
#ifdef OS_WINDOWS
	fCurrentTime = ((float)::timeGetTime()/1000.0f) - g_fSystemManagerStartTime;
#endif /* OS_WINDOWS */
	
#ifdef OS_APPLE_IOS
#endif /* OS_APPLE_IOS */

	m_fDeltaTime = fCurrentTime - m_fCurrentTime;
	// Save current time
	m_fCurrentTime = fCurrentTime;

	return 1;
}


// This method is called for rendering each frame.
int32 SystemManager::OnRender(void)
{
	return 1;
}


// Before the system is shut down, this method is called.
int32 SystemManager::OnDestroy(void)
{
	return 1;
}
