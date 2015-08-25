#include "GTLogConsole.h"
#include <time.h>
#include <stdarg.h>
#ifdef GT_WINDOWS
#include <tchar.h>
#include <wincon.h>
#endif /* GT_WINDOWS */

GTLogConsole::GTLogConsole()
{
}

GTLogConsole::~GTLogConsole()
{
}

// Initialize Log object
void GTLogConsole::Initialize(void)
{
#ifdef GT_WINDOWS
	if(AllocConsole())
	{
		SetConsoleTitle(_TEXT("Log Output"));
		freopen("CONOUT$", "w", stdout);
		tprintf(CTEXT("Debug Console\n"));
		tprintf(CTEXT("-------------\n"));
	}
	else
	{
		//printf("testing console");
		// Fail to create the console		
	}
#endif /* GT_WINDOWS */
}

// Destroy Log object
void GTLogConsole::Destroy(void)
{
#ifdef GT_WINDOWS
	FreeConsole();
#endif /* GT_WINDOWS */
}

// Log output
void GTLogConsole::LogTrace(const tchar* szMes)
{
	/*
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	if(handle != NULL)
	{
		SetConsoleTextAttribute(handle, BACKGROUND_RED);
	}
	*/

	LogOutout(szMes, CTEXT("TRACE"));

	/*
	if(handle != NULL)
	{
		SetConsoleTextAttribute(handle, BACKGROUND_RED);
	}
	*/
}

void GTLogConsole::LogWarning(const tchar* szMes)
{
	LogOutout(szMes, CTEXT("WARNING"));
}

void GTLogConsole::LogError(const tchar* szMes)
{
	LogOutout(szMes, CTEXT("ERROR"));
}

void GTLogConsole::LogComment(const tchar* szMes)
{
	LogOutout(szMes, CTEXT("COMMENT"));
}

void GTLogConsole::OutTimestamp()
{
	time_t t = time(NULL);
    tm* aTm = localtime(&t);
    //       YYYY   year
    //       MM     month (2 digits 01-12)
    //       DD     day (2 digits 01-31)
    //       HH     hour (2 digits 00-23)
    //       MM     minutes (2 digits 00-59)
    //       SS     seconds (2 digits 00-59)
    tprintf(CTEXT("%-4d-%02d-%02d %02d:%02d:%02d "),aTm->tm_year+1900,aTm->tm_mon+1,aTm->tm_mday,aTm->tm_hour,aTm->tm_min,aTm->tm_sec);
}

void GTLogConsole::LogOutout(const tchar* szMes, const tchar* szType)
{
	if(szMes && szType)
	{
		tprintf(CTEXT("[%s]: %s\n"), szType, szMes);
	}
}
