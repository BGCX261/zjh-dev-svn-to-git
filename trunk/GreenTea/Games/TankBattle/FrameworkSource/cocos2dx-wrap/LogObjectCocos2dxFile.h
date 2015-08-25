#ifndef _LOG_OBJECT_COCOS2DX_FILE_H_
#define _LOG_OBJECT_COCOS2DX_FILE_H_

#include <GTLog/GTLogObject.h>
#include <string>

class LogObjectCocos2dxFile : public GTLogObject
{
public:
	LogObjectCocos2dxFile(const tchar* szFileName);
	~LogObjectCocos2dxFile();

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
	void OutTimestamp(FILE* file);
	void LogOutout(const tchar* szMes, const tchar* szType);

private:
	std::string m_sPathWritable;
	std::string m_sPathLogFile;
};

#endif /* _LOG_OBJECT_COCOS2DX_FILE_H_ */
