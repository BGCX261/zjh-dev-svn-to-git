#ifndef _LOG_OBJECT_COCOS2DX_H_
#define _LOG_OBJECT_COCOS2DX_H_

#include <GTLog/GTLogObject.h>

class LogObjectCocos2dx : public GTLogObject
{
public:
	LogObjectCocos2dx();
	~LogObjectCocos2dx();

	// Initialize Log object
	virtual void Initialize(void);
	// Destroy Log object
	virtual void Destroy(void);
	// Log output
	virtual void LogTrace(const tchar* szMes);
	virtual void LogWarning(const tchar* szMes);
	virtual void LogError(const tchar* szMes);
	virtual void LogComment(const tchar* szMes);

private:
	void OutTimestamp();
	void LogOutout(const tchar* szMes, const tchar* szType);
};

#endif /* _LOG_OBJECT_COCOS2DX_H_ */
