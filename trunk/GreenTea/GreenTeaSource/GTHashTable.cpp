//===========================================================
//
// FileName: HashTableObject.cpp
//
// Desc: The hash table
//
// Written by J. H. ZHANG - Aug/09/2004(Mon)
//
//===========================================================

#include "GTHashTable.h"

//===========================================================
//
// The hash function for file names
//
//===========================================================

// Convert a string upper
static inline void hs_StringToUpper( char *szStr )
{
	ASSERT( szStr );

	long lLength = strlen( szStr );
	if( 0L == lLength )
	{
		return;
	}

	char nChar;
	for( long i=0; i<lLength; i++ )
	{
		nChar = szStr[i];
		if( nChar >= 'a' && nChar <= 'z' )
		{
			szStr[i] = 'A' + (nChar - 'a');
		} // if()
	} // for(i)

	return;
}

// 将字母字符串大写
static inline char hs_CharToUpper( const char& theChar )
{
	if(theChar >= 'a' && theChar <= 'z')
		return 'A' + (theChar - 'a');
	else
		return theChar;
}

// 更换路径分割符
static inline char hs_FilenameChar( char theChar )
{
	theChar = hs_CharToUpper( theChar );
	if( '/' == theChar )
	{
		theChar = '\\';
	}

	return theChar;
}

// 计算一个文件名序列的 Code
// 
// 计算所有字符(如果是字母则转换为大写)的 ASCII 码数值与位置索引的乘积
// 的和
unsigned long HashFun::HashFun_GenerateCode_FileName( const void* pKeyWord, const unsigned long nKeyWordLen )
{
	char *pCurByte;
	unsigned long sum, i;

	sum = 0;

	char* szKeyWord = (char*)pKeyWord;
	unsigned long dataLen = strlen( szKeyWord );
	pCurByte = (char*)szKeyWord;
	for( i=0; i < dataLen; i++ )
	{
		sum += ((unsigned long)hs_FilenameChar(*pCurByte)) * i;
		++pCurByte;
	}

	return sum;
}



//===========================================================
//
// The hash function for strings
//
//===========================================================

// Strings with case
unsigned long HashFun::HashFun_GenerateCode_StringCase( const void* pKeyWord, const unsigned long nKeyWordLen )
{
	char *pCurByte;
	unsigned long sum, i;

	sum = 0;

	pCurByte = (char*)pKeyWord;
	for(i=0; i < nKeyWordLen; i++)
	{
		sum += ((unsigned long)(*pCurByte)) * i;
		++pCurByte;
	}

	return sum;
}

// Strings with no case
unsigned long HashFun::HashFun_GenerateCode_StringNoCase( const void* pKeyWord, const unsigned long nKeyWordLen )
{
	char *pCurByte;
	unsigned long sum, i;

	sum = 0;

	pCurByte = (char*)pKeyWord;
	for(i=0; i < nKeyWordLen; i++)
	{
		sum += ((unsigned long)hs_CharToUpper(*pCurByte)) * i;
		++pCurByte;
	}

	return sum;
}



//===========================================================
//
// The hash function for raw data
//
//===========================================================
unsigned long HashFun::HashFun_GenerateCode_RawData( const void* pKeyWord, const unsigned long nKeyWordLen )
{
	char *pCurByte;
	unsigned long sum, i;

	sum = 0;

	pCurByte = (char*)pKeyWord;
	for(i=0; i < nKeyWordLen; i++)
	{
		sum += ((unsigned long)*pCurByte) * i;
		++pCurByte;
	}

	return sum;
}


// Numbers
unsigned long HashFun::HashFun_GenerateCode_1ByteNumber( const void* pKeyWord, const unsigned long nKeyWordLen )
{
	return *((unsigned char*)pKeyWord);
}

unsigned long HashFun::HashFun_GenerateCode_2ByteNumber( const void* pKeyWord, const unsigned long nKeyWordLen )
{
	return *((unsigned short*)pKeyWord);
}

unsigned long HashFun::HashFun_GenerateCode_4ByteNumber( const void* pKeyWord, const unsigned long nKeyWordLen )
{
	return *((unsigned long*)pKeyWord);
}



//===========================================================
//
// Desc: Hash Functions for comparing code
//
// [In]
// pKeyWord1    - The first key word
// nKeyWordLen1 - The length of the first key word
// pKeyWord2    - The second key word
// nKeyWordLen2 - The length of the second key word
//
// [Return]
// true  - The two key words are completely same.
// false - The two key words are NOT same.
//
//===========================================================

// Numbers
bool HashCmpKeyFun::HashFun_CompareKeyWord_1ByteNumber( const void* pKeyWord1, const unsigned long nKeyWordLen1,
														const void* pKeyWord2, const unsigned long nKeyWordLen2 )
{
	unsigned char num1, num2;

	num1 = *((unsigned char*)pKeyWord1);
	num2 = *((unsigned char*)pKeyWord2);

	return num1 == num2;
}

bool HashCmpKeyFun::HashFun_CompareKeyWord_2ByteNumber( const void* pKeyWord1, const unsigned long nKeyWordLen1,
														const void* pKeyWord2, const unsigned long nKeyWordLen2 )
{
	unsigned short num1, num2;

	num1 = *((unsigned short*)pKeyWord1);
	num2 = *((unsigned short*)pKeyWord2);

	return num1 == num2;
}

bool HashCmpKeyFun::HashFun_CompareKeyWord_4ByteNumber( const void* pKeyWord1, const unsigned long nKeyWordLen1,
														const void* pKeyWord2, const unsigned long nKeyWordLen2 )
{
	unsigned long num1, num2;

	num1 = *((unsigned long*)pKeyWord1);
	num2 = *((unsigned long*)pKeyWord2);

	return num1 == num2;
}

// File Names
bool HashCmpKeyFun::HashFun_CompareKeyWord_FileName( const void* pKeyWord1, const unsigned long nKeyWordLen1, 
													 const void* pKeyWord2, const unsigned long nKeyWordLen2 )
{
	char *pEndKey1, *pKey1, *pKey2;

	if( nKeyWordLen1 != nKeyWordLen2 )
	{
		return false;
	}

	pKey1 = (char*)pKeyWord1;
	pKey2 = (char*)pKeyWord2;
	pEndKey1 = pKey1 + nKeyWordLen1;
	
	while(pKey1 < pEndKey1)
	{
		if(hs_FilenameChar(*pKey1) != hs_FilenameChar(*pKey2))
		{
			return false;
		}

		++pKey1;
		++pKey2;
	}

	return true;
}

// Strings with case
bool HashCmpKeyFun::HashFun_CompareKeyWord_StringCase( const void* pKeyWord1, const unsigned long nKeyWordLen1,
													   const void* pKeyWord2, const unsigned long nKeyWordLen2 )
{
	char *pEndKey1, *pKey1, *pKey2;

	if( nKeyWordLen1 != nKeyWordLen2 )
	{
		return false;
	}

	pKey1 = (char*)pKeyWord1;
	pKey2 = (char*)pKeyWord2;
	pEndKey1 = pKey1 + nKeyWordLen1;
	
	while(pKey1 < pEndKey1)
	{
		if((*pKey1) != (*pKey2))
		{
			return false;
		}

		++pKey1;
		++pKey2;
	}

	return true;
}

// Strings with no case
bool HashCmpKeyFun::HashFun_CompareKeyWord_StringNoCase( const void* pKeyWord1, const unsigned long nKeyWordLen1,
													     const void* pKeyWord2, const unsigned long nKeyWordLen2 )
{
	char *pEndKey1, *pKey1, *pKey2;

	if( nKeyWordLen1 != nKeyWordLen2 )
	{
		return false;
	}

	pKey1 = (char*)pKeyWord1;
	pKey2 = (char*)pKeyWord2;
	pEndKey1 = pKey1 + nKeyWordLen1;
	
	while(pKey1 < pEndKey1)
	{
		if(hs_CharToUpper(*pKey1) != hs_CharToUpper(*pKey2))
		{
			return false;
		}

		++pKey1;
		++pKey2;
	}

	return true;
}

// Raw data
bool HashCmpKeyFun::HashFun_CompareKeyWord_RawData( const void* pKeyWord1, const unsigned long nKeyWordLen1,
													const void* pKeyWord2, const unsigned long nKeyWordLen2 )
{
	char *pEndKey1, *pKey1, *pKey2;

	if( nKeyWordLen1 != nKeyWordLen2 )
	{
		return false;
	}

	pKey1 = (char*)pKeyWord1;
	pKey2 = (char*)pKeyWord2;
	pEndKey1 = pKey1 + nKeyWordLen1;
	
	while(pKey1 < pEndKey1)
	{
		if(*pKey1 != *pKey2)
		{
			return false;
		}

		++pKey1;
		++pKey2;
	}

	return true;
}
