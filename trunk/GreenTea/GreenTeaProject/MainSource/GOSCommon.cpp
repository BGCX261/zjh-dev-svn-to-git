#include "GOS.h"

int32 GOS::GetFileSize(const tchar* szFileName)
{
	if(NULL == szFileName)
	{
		return -1;
	}

	FILE* fp = tfopen(szFileName, CTEXT("rb"));
	if(NULL == fp)
	{
		// The file doesn't exist.
		return -2;
	}
	// Set fp to the end of the file
	tfseek(fp, 0, SEEK_END);
	// Get the current fp position to get the size
	const int32 nFileSize = tftell(fp);
	// Close the file
	tfclose(fp);
	fp = NULL;

	return nFileSize;
}

// Load a file data into memory
void* GOS::LoadFileIntoMemory(const tchar* szFileName, uint32* pSize)
{
	/*
	// Windows version
	HANDLE hFile = INVALID_HANDLE_VALUE;
	uint32 nFileSize = 0;
	void* ptr = NULL;

	hFile = ::CreateFile(szFileName, GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL | FILE_FLAG_RANDOM_ACCESS, NULL);
	if(hFile == INVALID_HANDLE_VALUE)
	{
		return NULL;
	}
	nFileSize = ::GetFileSize(hFile, NULL);
	ptr = ::malloc(nFileSize);
	if(!ptr)
	{
		::CloseHandle(hFile);
		return NULL;
	}
	if(::ReadFile(hFile, ptr, nFileSize, &nFileSize, NULL ) == 0)
	{
		::CloseHandle(hFile);
		::free(ptr);
		return NULL;
	}
	
	::CloseHandle(hFile);
	if(pSize)
	{
		(*pSize) = nFileSize;
	}

	return ptr;
	*/
	
	uint32 nFileSize = 0;
	FILE* hFile = NULL;	
	void* ptr = NULL;

	// Get the file size
	nFileSize = GOS::GetFileSize(szFileName);
	if(nFileSize <= 0)
	{
		return NULL;
	}

	hFile = tfopen(szFileName, CTEXT("rb"));
	if(hFile == NULL)
	{
		return NULL;
	}

	ptr = malloc(nFileSize);
	if(!ptr)
	{
		fclose(hFile);
		return NULL;
	}

	if(0 == tfread(ptr, nFileSize, 1, hFile))
	{
		tfclose(hFile);
		free(ptr);
		return NULL;
	}
	
	tfclose(hFile);
	if(pSize)
	{
		(*pSize) = nFileSize;
	}

	return ptr;
}

/*
// Open a file
GOSHFILE GOS::OpenFile(const tchar* szFileName, const char* opType)
{
	if(NULL == szFileName || NULL == opType)
	{
		return NULL;
	}

	return fopen(szFileName, opType);
}


// Read data from the file
uint32 GOS::ReadFile(GOSHFILE hFile, void* pBuffer, const uint32 nSizeRead, const uint32 nReadCount)
{
	if(NULL == hFile || NULL == pBuffer || 0 == nSizeRead || 0 == nReadCount)
	{
		return 0;
	}

	return fread(pBuffer, nSizeRead, nReadCount, (FILE*)hFile);
}


// Close the file
void GOS::CloseFile(GOSHFILE hFile)
{
	if(NULL == hFile)
	{
		return;
	}

	fclose((FILE*)hFile);
}
*/
