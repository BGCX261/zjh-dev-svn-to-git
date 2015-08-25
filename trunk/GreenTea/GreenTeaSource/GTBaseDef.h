#ifndef _GREENTEA_BASE_DEF_H_
#define _GREENTEA_BASE_DEF_H_

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdlib.h>
#include <assert.h>
#include <stdarg.h>

#if defined(_MSC_VER)
	#define GT_MSC
#endif // _MSC_VER

#if defined(__GNUC__)
	#define GT_GNUC
#endif // __GNUC__

#if defined(__CYGWIN__)
	#define GT_CYGWIN
#endif // __CYGWIN__

// Apple iOS
#ifdef GT_DEF_IOS
#define GT_PLATFORM GT_DEF_IOS
#define GT_IOS
#endif // GT_DEF_IOS

// Android
#ifdef GT_DEF_ANDROID
#define GT_PLATFORM GT_DEF_ANDROID
#define GT_ANDROID
#endif // GT_DEF_ANDROID

// Assert statement
#define GT_ASSERT(cond,mes) assert(cond)
#define GT_ASSERT_1ARG(cond) GT_ASSERT(cond,"")
#define DBG_ASSERT(cond) GT_ASSERT_1ARG(cond)

//-------------------------------------------------------
// Microsoft Windows
//-------------------------------------------------------
#if defined(_MSC_VER) || defined(_WINDOWS)

	#define GT_PLATFORM GT_DEF_WINDOWS
	#define GT_WINDOWS

	// By defing this macro remove error C2011: 'xxxxx' : 'xxxxx' type redefinition 
	#define WIN32_LEAN_AND_MEAN
	#include <windows.h>
	#include <MMSystem.h>

	#if _MSC_VER >= 1400
	// warning C4244: '=' : conversion from 'double' to 'float', possible loss of data
	#pragma warning(disable : 4244)
	// warning C4345: behavior change: an object of POD type constructed with an initializer of the form () will be default-initialized
	#pragma warning(disable : 4345)
	// warning C4996: 'xxxxx': This function or variable may be unsafe.
	// Consider using strcpy_s instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS.
	#pragma warning(disable : 4996)
	#endif /* _MSC_VER >= 1400 */

	#if _MSC_VER >= 1600
	// warning C4251: class 'xxxxx' needs to have dll-interface to be used by clients of class 'xxxxx'
	#pragma warning(disable : 4251)
	#endif /* _MSC_VER >= 1600 */

	// Disable some warnings
	// warning C4091: 'static ' : ignored on left of 'ClassName' when no variable is declared
	#pragma warning (disable : 4091)
	// warning C4996: 'FunctionName': This function or variable may be unsafe. Consider using FunctionName_s instead.
	// To disable deprecation, use _CRT_SECURE_NO_WARNINGS. See online help for details.
	#pragma warning (disable : 4996)
	
	// UNICODE Version
	#define StringCopyW(dst,src) lstrcpyW(dst,src)
	#define StringCopyNW(dst,src,num) lstrcpyn(dst,src,num)
	#define StringCatW(dst,src) lstrcat(dst,src)
	//#define StringCatNW(dst,src,num) strncat(dst,src,num)
	#define StringLengthW(src) lstrlenW(src)
	#define StringCmpW(str1,str2) lstrcmpW(str1,str2)
	#define StringNCmpW(str1,str2,count) wcsncmp(str1,str2,count)
	#define StrrchrW(str,c) wcsrchr(str,c)
	// ANSI Version
	/*
	// lstr*** functions might not work on MAC OS, not testing yet.
	#define StringCopyA(dst,src) lstrcpyA(dst,src)
	#define StringLengthA(src) lstrlenA(src)
	#define StringCmpA(str1,str2) lstrcmpA(str1,str2)
	*/
	#define StringCopyA(dst,src) strcpy(dst,src)
	#define StringCopyNA(dst,src,num) strncpy(dst,src,num)
	#define StringCatA(dst,src) strcat(dst,src)
	#define StringCatNA(dst,src,num) strncat(dst,src,num)
	#define StringLengthA(src) strlen(src)
	#define StringCmpA(str1,str2) lstrcmpA(str1,str2)
	#define StringNCmpA(str1,str2,count) strncmp(str1,str2,count)
	#define StrrchrA(str,c) strrchr(str,c)

	// String functions
	#ifdef _UNICODE_DEF_
		#define StringCopy(dst,src) StringCopyW(dst,src)
		#define StringLength(src) StringLengthW(src)
		#define StringCmp(str1,str2) StringCmpW(str1,str2)
		#define StringNCmp(str1,str2,count) StringNCmpW(str1,str2,count)
		#define Strrchr(str,c) StrrchrW(str,c)
		#define ClearMemory(dest,size) memset(dest,0,size);
	#else /* _UNICODE_DEF_ */
		#define StringCopy(dst,src) StringCopyA(dst,src)
		#define StringLength(src) StringLengthA(src)
		#define StringCmp(str1,str2) StringCmpA(str1,str2)
		#define StringNCmp(str1,str2,count) StringNCmpA(str1,str2,count)
		#define Strrchr(str,c) StrrchrA(str,c)
		#define ClearMemory(dest,size) memset(dest,0,size);
	#endif /* _UNICODE_DEF_ */

	// File IO functions
	#ifdef _UNICODE_DEF_
		#define tfopen _wfopen
		#define tfseek fseek
		#define tftell ftell
		#define tfread fread
		#define tfclose fclose
		#define tsprintf swprintf
		#define tsscanf swscanf
		#define tfprintf fwprintf
		#define tprintf wprintf
	#else /* _UNICODE_DEF_ */
		#define tfopen fopen
		#define tfseek fseek
		#define tftell ftell
		#define tfread fread
		#define tfclose fclose
		#define tsprintf sprintf
		#define tsscanf sscanf
		#define tfprintf fprintf
		#define tprintf printf
	#endif /* _UNICODE_DEF_ */

#endif // defined(_MSC_VER) || defined(_WINDOWS)

#if defined(_UNICODE) || defined(UNICODE)
#define GT_UNICODE
#endif /* defined(_UNICODE) || defined(UNICODE) */

//-------------------------------------------------------

#if defined(_DEBUG) || defined(GT_DEF_DEBUG)
	#define GT_DEBUG
#else
	#define GT_RELEASE
#endif

typedef char int8;
typedef unsigned char uint8;
typedef int8 GTint8;
typedef uint8 GTuint8;

typedef short int16;
typedef unsigned short uint16;
typedef int16 GTint16;
typedef uint16 GTuint16;

typedef int int32;
typedef unsigned int uint32;
typedef int32 GTint32;
typedef uint32 GTuint32;

typedef long long32;
typedef unsigned long ulong32;
typedef long32 GTlong32;
typedef ulong32 GTulong32;

#ifdef GT_WINDOWS
	typedef __int64 int64;
	typedef unsigned __int64 uint64;
	typedef int64 GTint64;
	typedef uint64 GTuint64;
#endif // GT_WINDOWS

#if defined(GT_IOS) || defined(GT_ANDROID)
	typedef int64_t int64;
	typedef unsigned __int64 uint64;
	typedef int64 GTint64;
	typedef uint64 GTuint64;
#endif // GT_IOS || GT_ANDROID

typedef float real32;
typedef float GTfloat;
typedef real32 GTreal32;

//#ifdef GT_UNICODE
//typedef wchar_t tchar;
//#define CTEXT(quote) L##quote
//#else /* GT_UNICODE */
//typedef char tchar;
//#define CTEXT(quote) quote
//#endif /* GT_UNICODE */

// UTF-8 is being used, currently only use char
typedef char tchar;
#define CTEXT(quote) quote

// Maximum length of path, including the terminator '\0'
#define GT_PATH_MAX_LEN (256)


//-------------------------------------------------------
// GNU C/C++
//-------------------------------------------------------
#if defined(__GNUC__) || defined(__CYGWIN__)

	// ANSI
	#define StringCopyA(dst,src) strcpy(dst,src)
	#define StringCopyNA(dst,src,num) strncpy(dst,src,num)
	#define StringCatA(dst,src) strcat(dst,src)
	#define StringCatNA(dst,src,num) strncat(dst,src,num)
	#define StringLengthA(src) strlen(src)
	#define StringCmpA(str1,str2) strcmp(str1,str2)
	#define StringNCmpA(str1,str2,count) strncmp(str1,str2,count)
	#define StrrchrA(str,c) strrchr(str,c)

	// String functions
	#define StringCopy(dst,src) StringCopyA(dst,src)
	#define StringCopyN(dst,src,num) StringCopyNA(dst,src,num)
	#define StringCat(dst,src) StringCatA(dst,src)
	#define StringCatN(dst,src,num) StringCatNA(dst,src,num)
	#define StringLength(src) StringLengthA(src)
	#define StringCmp(str1,str2) StringCmpA(str1,str2)
	#define StringNCmp(str1,str2,count) StringNCmpA(str1,str2,count)
	#define Strrchr(str,c) StrrchrA(str,c)
	#define ClearMemory(dest,size) memset(dest,0,size);

	// File IO functions
	#define tfopen fopen
	#define tfseek fseek
	#define tftell ftell
	#define tfread fread
	#define tfclose fclose
	#define tsprintf sprintf
	#define tsscanf sscanf
	#define tfprintf fprintf
	#define tprintf printf

#endif // defined(__GNUC__) || defined(__CYGWIN__)

/*
// Apple iOS
#define OS_APPLE_IOS

#include <stdarg.h>

#ifndef NULL
#define NULL 0
#endif //

#ifndef TRUE
#define TRUE 1
#endif //

#ifndef FALSE
#define FALSE 0
#endif //

typedef char int8;
typedef unsigned char uint8;

typedef short int16;
typedef unsigned short uint16;

typedef int int32;
typedef unsigned int uint32;

//typedef __int64 int64;
//typedef unsigned __int64 uint64;

typedef float real32;

#ifdef _UNICODE_DEF_
typedef wchar_t tchar;
#define CTEXT(quote) L##quote
#else //
typedef char tchar;
#define CTEXT(quote) quote
#endif //

// Maximum length of path, including the terminator '\0'
#define PATH_MAX_LEN (256)

#endif
*/

#endif /* _GREENTEA_BASE_DEF_H_ */
