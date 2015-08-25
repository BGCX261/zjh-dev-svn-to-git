#ifndef _GT_LOG_OBJECT_H_
#define _GT_LOG_OBJECT_H_

#include "../GTBaseDef.h"

class GTLogObject
{
public:
	// Initialize Log object
	virtual void Initialize(void) = 0;
	// Destroy Log object
	virtual void Destroy(void) = 0;
	// Log output
	virtual void LogTrace(const tchar* szMes) = 0;
	virtual void LogWarning(const tchar* szMes) = 0;
	virtual void LogError(const tchar* szMes) = 0;
	virtual void LogComment(const tchar* szMes) = 0;
};

#endif /* _GT_LOG_OBJECT_H_ */
