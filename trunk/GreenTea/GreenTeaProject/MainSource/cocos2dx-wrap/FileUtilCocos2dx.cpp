#include <GTCommon/FileUtil.h>
#include <GTString.h>
#include <platform/CCFileUtils.h>

const char* FileUtil::Read = "r";
const char* FileUtil::ReadBinary = "rb";

// Read file data from the hardware
unsigned char* FileUtil::GetFileData(const char* pszFileName,
									 const char* pszMode,
									 unsigned long* pSize)
{
	// Translate pszFileName to full path
	const char* szFileNameFullPath = cocos2d::CCFileUtils::sharedFileUtils()->fullPathFromRelativeFile(pszFileName, "");
	return cocos2d::CCFileUtils::sharedFileUtils()->getFileData(szFileNameFullPath, pszMode, pSize);
}

// Read file data from the hardware
unsigned char* FileUtil::ReadFileData(
		const char* pszFileName,
		unsigned long* pSize
		)
{
	// Translate pszFileName to full path
	const char* szFileNameFullPath = cocos2d::CCFileUtils::sharedFileUtils()->fullPathFromRelativeFile(pszFileName, "");
	return cocos2d::CCFileUtils::sharedFileUtils()->getFileData(szFileNameFullPath, FileUtil::Read, pSize);
}

// Read text file data from the hardware
char* FileUtil::ReadTextFileData(
		const char* pszFileName,
		unsigned long* pSize
		)
{
	char* pContent = (char*)FileUtil::ReadFileData(pszFileName, pSize);
	if(pContent == NULL || (*pSize) == 0)
	{
		return NULL;
	}
	// Copy the file contents and add '\0' at the end.
	char* pContentText = new char[(*pSize) + 1];
	if(pContentText == NULL)
	{
		delete [] pContent;
		pContent = NULL;

		return NULL;
	}
	
	// Copy the text to destination buffer
	memcpy(pContentText, pContent, (*pSize));
	// Add string terminator at the end
	pContentText[(*pSize)] = GTString::StringTerminator;
	//
	(*pSize) += 1;

	delete[] pContent;
	pContent = NULL;

	return pContentText;
}

// Read binary file data from the hardware
unsigned char* FileUtil::ReadBinaryFileData(
		const char* pszFileName,
		unsigned long* pSize
		)
{
	// Translate pszFileName to full path
	const char* szFileNameFullPath = cocos2d::CCFileUtils::sharedFileUtils()->fullPathFromRelativeFile(pszFileName, NULL);
	return cocos2d::CCFileUtils::sharedFileUtils()->getFileData(szFileNameFullPath, FileUtil::ReadBinary, pSize);
}
