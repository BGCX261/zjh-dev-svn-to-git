#ifndef _GREENTEA_LOG_TEXT_FILE_H_
#define _GREENTEA_LOG_TEXT_FILE_H_

#include "GTLogObject.h"

class GTLogTextFile : public GTLogObject
{
public:
	GTLogTextFile();
	~GTLogTextFile();

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
	static const tchar* g_szLogFileName;
	void OutTimestamp(FILE* file);
	void LogOutout(const tchar* szMes, const tchar* szType);
};

#endif /* _GREENTEA_LOG_TEXT_FILE_H_ */
