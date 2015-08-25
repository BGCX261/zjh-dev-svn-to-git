#ifndef _GOSYS_H_
#define _GOSYS_H_

#include <GTBaseDef.h>

// This class is a wrapper for the calls/APIs related to specific OS.
class GOSys
{
public:
	// Get time
	static uint32 GetTime(void);
};

#endif /* _GOSYS_H_ */
