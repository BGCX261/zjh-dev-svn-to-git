#include "GOSys.h"
#include <GTBaseDef.h>
//#include "CCPlatformDefine.h"

// Get time
uint32 GOSys::GetTime(void)
{
#ifdef _WINDOWS
	return timeGetTime();
#endif
#ifdef _PLATFORM_ANDROID
	// Use Android time function here
	return 0;
#endif
#ifdef _PLATFORM_IOS
	// Use iOS time function here
	return 0;
#endif
}
