#ifndef _GREENTEA_LOG_MANAGER_H_
#define _GREENTEA_LOG_MANAGER_H_

#include <GTBaseDef.h>
#include <GTSingleton.h>
#include <GTArray.h>
#include <stdio.h>
#include <time.h>

class GTLogObject;

class GTLogManager : public GTSingleton<GTLogManager>
{
public:
	GTLogManager();
	~GTLogManager();

	// Initialize Log object
	void Initialize(void);
	void AddLogObject(GTLogObject* pLogObject);
	// Destroy Log object
	void Destroy(void);
	// Log output
	void LogTrace(const tchar* szMes);
	void LogFormatTrace(const tchar* szMes, ...);
	void LogWarning(const tchar* szMes);
	void LogFormatWarning(const tchar* szMes, ...);
	void LogError(const tchar* szMes);
	void LogFormatError(const tchar* szMes, ...);
	void LogComment(const tchar* szMes);
	void LogFormatComment(const tchar* szMes, ...);

	// Static helpers
	static void SLogTrace(const tchar* szMes) { GTLogManager::GetInstance()->LogTrace(szMes); }
	static void SLogFormatTrace(const tchar* szMes, ...);
	static void SLogWarning(const tchar* szMes) { GTLogManager::GetInstance()->LogWarning(szMes); }
	static void SLogFormatWarning(const tchar* szMes, ...);
	static void SLogError(const tchar* szMes) { GTLogManager::GetInstance()->LogError(szMes); }
	static void SLogFormatError(const tchar* szMes, ...);
	static void SLogComment(const tchar* szMes) { GTLogManager::GetInstance()->LogComment(szMes); }
	static void SLogFormatComment(const tchar* szMes, ...);

private:
	GTArray<GTLogObject*> m_LogObjectList;
	void OutTimestamp(FILE* file);
	void LogOutout(const tchar* szMes, const tchar* szType);
};

#endif /* _GREENTEA_LOG_MANAGER_H_ */
