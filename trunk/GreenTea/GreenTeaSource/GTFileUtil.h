#ifndef _GREENTEA_FILE_UTIL_H_
#define _GREENTEA_FILE_UTIL_H_

class GTFileUtil
{
public:
	static const char* Read;
	static const char* ReadBinary;

public:
	// Get file data from the hardware
	static unsigned char* GetFileData(
		const char* pszFileName,
		const char* pszMode,
		unsigned long * pSize
		);

	// Read file data from the hardware
	static unsigned char* ReadFileData(
		const char* pszFileName,
		unsigned long * pSize
		);

	// Read text file data from the hardware
	static char* ReadTextFileData(
		const char* pszFileName,
		unsigned long * pSize
		);

	// Read binary file data from the hardware
	static unsigned char* ReadBinaryFileData(
		const char* pszFileName,
		unsigned long * pSize
		);
};

#endif /* _GREENTEA_FILE_UTIL_H_ */
