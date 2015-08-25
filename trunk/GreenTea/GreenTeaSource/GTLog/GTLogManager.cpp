#include "GTLogManager.h"
#include "GTLogTextFile.h"
#include "GTLogConsole.h"

GTSINGLETON_IMP(GTLogManager);

static tchar g_szBuffer[2048];

GTLogManager::GTLogManager()
{
}

GTLogManager::~GTLogManager()
{
}

// Initialize Log object
void GTLogManager::Initialize(void)
{
	/*
#ifdef GT_WINDOWS
	m_pLogObject = new GTLogConsole();
#else // GT_WINDOWS
	m_pLogObject = new GTLogTextFile();
#endif // GT_WINDOWS
	if(m_pLogObject != NULL)
	{
		m_pLogObject->Initialize();
	}
	*/
}


void GTLogManager::AddLogObject(GTLogObject* pLogObject)
{
	if(NULL == pLogObject)
		return;

	// Initialize log object
	pLogObject->Initialize();
	// Add this log object to the list
	m_LogObjectList.Add(pLogObject);
}

// Destroy Log object
void GTLogManager::Destroy(void)
{
	for(int32 i=0; i<m_LogObjectList.Length(); i++)
	{
		m_LogObjectList[i]->Destroy();
		delete m_LogObjectList[i];
	}
	m_LogObjectList.Clear();
}

// Log output
void GTLogManager::LogTrace(const tchar* szMes)
{
	for(int32 i=0; i<m_LogObjectList.Length(); i++)
	{
		m_LogObjectList[i]->LogTrace(szMes);
	}
}

void GTLogManager::LogWarning(const tchar* szMes)
{
	for(int32 i=0; i<m_LogObjectList.Length(); i++)
	{
		m_LogObjectList[i]->LogWarning(szMes);
	}
}

void GTLogManager::LogError(const tchar* szMes)
{
	for(int32 i=0; i<m_LogObjectList.Length(); i++)
	{
		m_LogObjectList[i]->LogError(szMes);
	}
}

void GTLogManager::LogComment(const tchar* szMes)
{
	for(int32 i=0; i<m_LogObjectList.Length(); i++)
	{
		m_LogObjectList[i]->LogComment(szMes);
	}
}

void GTLogManager::LogFormatTrace(const tchar* szMes, ...)
{
	if(0 == m_LogObjectList.Length())
		return;

	va_list args;
	va_start(args, szMes);
	vsprintf(g_szBuffer, szMes, args);
	va_end(args);

	for(int32 i=0; i<m_LogObjectList.Length(); i++)
	{
		m_LogObjectList[i]->LogTrace(g_szBuffer);
	}
}

void GTLogManager::LogFormatWarning(const tchar* szMes, ...)
{
	if(0 == m_LogObjectList.Length())
		return;

	va_list args;
	va_start(args, szMes);
	vsprintf(g_szBuffer, szMes, args);
	va_end(args);

	for(int32 i=0; i<m_LogObjectList.Length(); i++)
	{
		m_LogObjectList[i]->LogWarning(g_szBuffer);
	}
}

void GTLogManager::LogFormatError(const tchar* szMes, ...)
{
	if(0 == m_LogObjectList.Length())
		return;

	va_list args;
	va_start(args, szMes);
	vsprintf(g_szBuffer, szMes, args);
	va_end(args);

	for(int32 i=0; i<m_LogObjectList.Length(); i++)
	{
		m_LogObjectList[i]->LogError(g_szBuffer);
	}
}

void GTLogManager::LogFormatComment(const tchar* szMes, ...)
{
	if(0 == m_LogObjectList.Length())
		return;

	va_list args;
	va_start(args, szMes);
	vsprintf(g_szBuffer, szMes, args);
	va_end(args);

	for(int32 i=0; i<m_LogObjectList.Length(); i++)
	{
		m_LogObjectList[i]->LogComment(g_szBuffer);
	}
}

void GTLogManager::SLogFormatTrace(const tchar* szMes, ...)
{
	if(0 == m_Instance.m_LogObjectList.Length())
		return;

	va_list args;
	va_start(args, szMes);
	vsprintf(g_szBuffer, szMes, args);
	va_end(args);

	for(int32 i=0; i<m_Instance.m_LogObjectList.Length(); i++)
	{
		m_Instance.m_LogObjectList[i]->LogTrace(g_szBuffer);
	}
}
void GTLogManager::SLogFormatWarning(const tchar* szMes, ...)
{
	if(0 == m_Instance.m_LogObjectList.Length())
		return;

	va_list args;
	va_start(args, szMes);
	vsprintf(g_szBuffer, szMes, args);
	va_end(args);

	for(int32 i=0; i<m_Instance.m_LogObjectList.Length(); i++)
	{
		m_Instance.m_LogObjectList[i]->LogWarning(g_szBuffer);
	}
}
void GTLogManager::SLogFormatError(const tchar* szMes, ...)
{
	if(0 == m_Instance.m_LogObjectList.Length())
		return;

	va_list args;
	va_start(args, szMes);
	vsprintf(g_szBuffer, szMes, args);
	va_end(args);

	for(int32 i=0; i<m_Instance.m_LogObjectList.Length(); i++)
	{
		m_Instance.m_LogObjectList[i]->LogError(g_szBuffer);
	}
}
void GTLogManager::SLogFormatComment(const tchar* szMes, ...)
{
	if(0 == m_Instance.m_LogObjectList.Length())
		return;
	
	va_list args;
	va_start(args, szMes);
	vsprintf(g_szBuffer, szMes, args);
	va_end(args);
	
	for(int32 i=0; i<m_Instance.m_LogObjectList.Length(); i++)
	{
		m_Instance.m_LogObjectList[i]->LogComment(g_szBuffer);
	}
}

/*
void Log::outString( const char * str, ... )
{
    if( !str ) return;

    if(m_colored)
        SetColor(true,m_colors[LogNormal]);

    if(m_includeTime)
        outTime();

    va_list ap;
    va_start(ap, str);
    vprintf( str, ap );
    va_end(ap);

    if(m_colored)
        ResetColor(true);

    printf( "\n" );
    if(logfile)
    {
        outTimestamp(logfile);
        va_start(ap, str);
        vfprintf(logfile, str, ap);
        fprintf(logfile, "\n" );
        va_end(ap);
        fflush(logfile);
    }
    fflush(stdout);
}
*/
