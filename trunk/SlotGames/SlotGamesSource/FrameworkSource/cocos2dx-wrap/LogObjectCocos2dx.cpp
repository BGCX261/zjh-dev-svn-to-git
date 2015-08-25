#include "LogObjectCocos2dx.h"
#include "cocos2d.h"

LogObjectCocos2dx::LogObjectCocos2dx()
{
}

LogObjectCocos2dx::~LogObjectCocos2dx()
{
}

// Initialize Log object
void LogObjectCocos2dx::Initialize(void)
{
}

// Destroy Log object
void LogObjectCocos2dx::Destroy(void)
{
}

// Log output
void LogObjectCocos2dx::LogTrace(const tchar* szMes)
{
	LogOutout(szMes, CTEXT("TRACE"));
}

void LogObjectCocos2dx::LogWarning(const tchar* szMes)
{
	LogOutout(szMes, CTEXT("WARNING"));
}

void LogObjectCocos2dx::LogError(const tchar* szMes)
{
	LogOutout(szMes, CTEXT("ERROR"));
}

void LogObjectCocos2dx::LogComment(const tchar* szMes)
{
	LogOutout(szMes, CTEXT("COMMENT"));
}

void LogObjectCocos2dx::LogOutout(const tchar* szMes, const tchar* szType)
{
	if(szMes && szType)
	{
		cocos2d::CCLog(CTEXT("[%s]: %s"), szType, szMes);
	}
}
