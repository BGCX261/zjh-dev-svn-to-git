#ifndef _GOS_H_
#define _GOS_H_

#include <GTBaseDef.h>

// This class is a wrapper for the calls/APIs related to specific OS.
class GOS
{
public:
	static int32 GetFileSize(const tchar* szFileName);
	// Load a file data into memory
	static void* LoadFileIntoMemory(const tchar* szFileName, uint32* pSize);
	
	/*
	// File attributes
	typedef void* GOSHFILE;
	#define READ_BIN "rb"
	#define WRITE_BIN "wb"
	// Open a file
	static GOSHFILE OpenFile(const tchar* szFileName, const char* opType);
	// Read data from the file
	static uint32 ReadFile(GOSHFILE hFile, void* pBuffer, const uint32 nSizeRead, const uint32 nReadCount);
	// Close the file
	static void CloseFile(GOSHFILE hFile);
	*/
};

#endif /* _GOS_H_ */
