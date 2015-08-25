#ifndef _GREENTEA_STRING_UTIL_H_
#define _GREENTEA_STRING_UTIL_H_

#include "GTBaseDef.h"
#include "GTString.h"
#include "GTArray.h"

class GTStringUtil
{
public:
	// The options for splitting a string
	typedef enum
	{
		// The return value includes array elements that contain an empty string
		None = 0,
		// The return value does not include array elements that contain an empty string
		RemoveEmptyEntries,
	} StringSplitOptions;

public:
	// Split a string with separator.
	// All sub-strings are stored at result.
	static void Split(
		const GTString& source,
		const GTString& separator,
		GTArray<GTString>& result,
		StringSplitOptions splitOption = RemoveEmptyEntries
		);

	static void Split(
		const GTString& source,
		const tchar* separator,
		GTArray<GTString>& result,
		StringSplitOptions splitOption = RemoveEmptyEntries
		);

	static void Split(
		const GTString& source,
		const tchar separator,
		GTArray<GTString>& result,
		StringSplitOptions splitOption = RemoveEmptyEntries
		);

	// Remove all leading whitespace
	static GTString TrimLeft(const GTString& source);
	// Remove all trailing whitespace
	static GTString TrimRight(const GTString& source);

	// Strip out double slashes C++ style comments from a string
	// But allow double slashes to appear inside quotes.
	static GTString StripDoubleSlashComments(const GTString& source);
	// Strip out C++ style block comments from a string
	// But allow block comment delimeters (/* */) to appear inside quotes.
	static GTString StripBlockComments(GTString& source);
};

#endif /* _GREENTEA_STRING_UTIL_H_ */
