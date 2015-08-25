#ifndef _GREENTEA_LOG_CONSOLE_H_
#define _GREENTEA_LOG_CONSOLE_H_

#include "GTLogObject.h"

class GTLogConsole : public GTLogObject
{
public:
	GTLogConsole();
	~GTLogConsole();

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

#endif /* _GREENTEA_LOG_CONSOLE_H_ */
