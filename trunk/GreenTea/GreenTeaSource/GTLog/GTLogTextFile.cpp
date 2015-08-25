#include "GTLogTextFile.h"
#include <time.h>

const tchar* GTLogTextFile::g_szLogFileName = CTEXT("GTLogTextFile.log");

GTLogTextFile::GTLogTextFile()
{
}

GTLogTextFile::~GTLogTextFile()
{
}

// Initialize Log object
void GTLogTextFile::Initialize(void)
{
	FILE* fp = tfopen(GTLogTextFile::g_szLogFileName, CTEXT("w"));
	if(fp)
	{
		OutTimestamp(fp);
		fprintf(fp, "\n");
		tfclose(fp);
		fp = NULL;
	}
}

// Destroy Log object
void GTLogTextFile::Destroy(void)
{
}

// Log output
void GTLogTextFile::LogTrace(const tchar* szMes)
{
	LogOutout(szMes, CTEXT("TRACE"));
}

void GTLogTextFile::LogWarning(const tchar* szMes)
{
	LogOutout(szMes, CTEXT("WARNING"));
}

void GTLogTextFile::LogError(const tchar* szMes)
{
	LogOutout(szMes, CTEXT("ERROR"));
}

void GTLogTextFile::LogComment(const tchar* szMes)
{
	LogOutout(szMes, CTEXT("COMMENT"));
}

void GTLogTextFile::OutTimestamp(FILE* file)
{
	time_t t = time(NULL);
    tm* aTm = localtime(&t);
    //       YYYY   year
    //       MM     month (2 digits 01-12)
    //       DD     day (2 digits 01-31)
    //       HH     hour (2 digits 00-23)
    //       MM     minutes (2 digits 00-59)
    //       SS     seconds (2 digits 00-59)
    fprintf(file,"%-4d-%02d-%02d %02d:%02d:%02d\n",aTm->tm_year+1900,aTm->tm_mon+1,aTm->tm_mday,aTm->tm_hour,aTm->tm_min,aTm->tm_sec);
	fprintf(file,"-------------------");
}

void GTLogTextFile::LogOutout(const tchar* szMes, const tchar* szType)
{
	if(szMes && szType)
	{
		FILE* fp = tfopen(GTLogTextFile::g_szLogFileName, CTEXT("a+"));
		if(fp)
		{
			tfprintf(fp, CTEXT("[%s]: %s\n"), szType, szMes);
			tfclose(fp);
			fp = NULL;
		}
	}
}
