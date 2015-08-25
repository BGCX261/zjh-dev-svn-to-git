#include <GTFileUtil.h>
#include <GTString.h>
#include <platform/CCFileUtils.h>

const char* GTFileUtil::Read = "r";
const char* GTFileUtil::ReadBinary = "rb";

// Read file data from the hardware
unsigned char* GTFileUtil::GetFileData(const char* pszFileName,
									 const char* pszMode,
									 unsigned long* pSize)
{
	// Translate pszFileName to full path
	const char* szFileNameFullPath = cocos2d::CCFileUtils::sharedFileUtils()->fullPathFromRelativeFile(pszFileName, "");
	return cocos2d::CCFileUtils::sharedFileUtils()->getFileData(szFileNameFullPath, pszMode, pSize);
}

// Read file data from the hardware
unsigned char* GTFileUtil::ReadFileData(
		const char* pszFileName,
		unsigned long* pSize
		)
{
	// Translate pszFileName to full path
	const char* szFileNameFullPath = cocos2d::CCFileUtils::sharedFileUtils()->fullPathFromRelativeFile(pszFileName, "");
	return cocos2d::CCFileUtils::sharedFileUtils()->getFileData(szFileNameFullPath, GTFileUtil::Read, pSize);
}

// Read text file data from the hardware
char* GTFileUtil::ReadTextFileData(
		const char* pszFileName,
		unsigned long* pSize
		)
{
	char* pContent = (char*)GTFileUtil::ReadFileData(pszFileName, pSize);
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
unsigned char* GTFileUtil::ReadBinaryFileData(
		const char* pszFileName,
		unsigned long* pSize
		)
{
	// Translate pszFileName to full path
	const char* szFileNameFullPath = cocos2d::CCFileUtils::sharedFileUtils()->fullPathFromRelativeFile(pszFileName, NULL);
	return cocos2d::CCFileUtils::sharedFileUtils()->getFileData(szFileNameFullPath, GTFileUtil::ReadBinary, pSize);
}
