#include "LogObjectCocos2dxFile.h"
#include "cocos2d.h"

LogObjectCocos2dxFile::LogObjectCocos2dxFile(const tchar* szFileName)
{
	m_sPathLogFile = std::string(szFileName);
}

LogObjectCocos2dxFile::~LogObjectCocos2dxFile()
{
}

// Initialize Log object
void LogObjectCocos2dxFile::Initialize(void)
{
	m_sPathWritable = cocos2d::CCFileUtils::sharedFileUtils()->getWritablePath();
	m_sPathLogFile = m_sPathWritable + m_sPathLogFile;
	cocos2d::CCLog(CTEXT("LogObjectCocos2dxFile.pathWritable = %s"), m_sPathWritable.c_str());
	cocos2d::CCLog(CTEXT("LogObjectCocos2dxFile.pathLogFile = %s"), m_sPathLogFile.c_str());

	FILE* fp = fopen(m_sPathLogFile.c_str(), "w");
	if(fp)
	{
		OutTimestamp(fp);
		fprintf(fp, "\n");
		tfclose(fp);
		fp = NULL;
	}
}

// Destroy Log object
void LogObjectCocos2dxFile::Destroy(void)
{
}

// Log output
void LogObjectCocos2dxFile::LogTrace(const tchar* szMes)
{
	LogOutout(szMes, CTEXT("TRACE"));
}

void LogObjectCocos2dxFile::LogWarning(const tchar* szMes)
{
	LogOutout(szMes, CTEXT("WARNING"));
}

void LogObjectCocos2dxFile::LogError(const tchar* szMes)
{
	LogOutout(szMes, CTEXT("ERROR"));
}

void LogObjectCocos2dxFile::LogComment(const tchar* szMes)
{
	LogOutout(szMes, CTEXT("COMMENT"));
}

void LogObjectCocos2dxFile::OutTimestamp(FILE* file)
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

void LogObjectCocos2dxFile::LogOutout(const tchar* szMes, const tchar* szType)
{
	if(szMes && szType)
	{
		FILE* fp = fopen(m_sPathLogFile.c_str(), CTEXT("a+"));
		if(fp)
		{
			fprintf(fp, CTEXT("[%s]: %s\n"), szType, szMes);
			fclose(fp);
			fp = NULL;
		}
	}
}
