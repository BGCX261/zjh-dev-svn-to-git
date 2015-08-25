#include "GTString.h"
#include "GTStringUtil.h"

// DataString static variables
const int32 GTString::BadPosition = -1;
const tchar* GTString::EmptyString = CTEXT("");
const tchar GTString::StringTerminator = CTEXT('\0');
const int16 GTString::WhitespaceChars[] = {
	CTEXT('/t'),
	CTEXT('/n'),
	CTEXT('/v'),
	CTEXT('/f'),
	CTEXT('/r'),
	//CTEXT('/x0085'),
	//CTEXT('/x00a0'),
	//CTEXT('/u2028'),
	//CTEXT('/u2029')
};

// Remove all trailing whitespace
GTString& GTString::TrimRight()
{
	// Find beginning of trailing spaces by starting
	// at beginning (DBCS aware)
	const tchar* psz = ToCharString();
	int nLastIndex = -1;
	int nIndex = 0;
	while(psz[nIndex] != 0)
	{
		if(IsWhiteSpaceChar(psz[nIndex]))
		{
			if(nLastIndex < 0)
				nLastIndex = nIndex;
		}
		else
		{
			nLastIndex = -1;
		}
		// Next character
		nIndex++;
	}

	if(nLastIndex >= 0)
	{
		// Truncate at trailing space start
		SetLength(nLastIndex);
	}

	return (*this);
}

// Remove all leading whitespace
GTString& GTString::TrimLeft()
{
	// Find first non-space character
	const tchar* psz = ToCharString();
	int nIndex = 0;
	while(IsWhiteSpaceChar(psz[nIndex]))
	{
		nIndex++;
	}

	if(nIndex > 0)
	{
		// Fix up data and length
		memmove((void*)psz, (void*)(psz+nIndex), (Length()-nIndex)*sizeof(tchar));
		SetLength(Length() - nIndex);
	}

	return(*this);
}

// Remove all leading and trailing whitespace
GTString& GTString::Trim()
{
	return (TrimRight().TrimLeft());
}


// Temp buffer
static tchar g_szTempBuf[512];

// Format a string
GTString GTString::Format(const tchar* szMes, ...)
{
	va_list args;
	va_start(args, szMes);
	vsprintf(g_szTempBuf, szMes, args);
	va_end(args);
	return GTString(g_szTempBuf);
}

// Convert v to string
GTString GTString::From(const tchar v)
{
	tsprintf(g_szTempBuf, CTEXT("%c"), v);
	return GTString(g_szTempBuf);
}
GTString GTString::From(const int16 v)
{
	tsprintf(g_szTempBuf, CTEXT("%d"), v);
	return GTString(g_szTempBuf);
}
GTString GTString::From(const uint16 v)
{
	tsprintf(g_szTempBuf, CTEXT("%d"), v);
	return GTString(g_szTempBuf);
}
GTString GTString::From(const int32 v)
{
	tsprintf(g_szTempBuf, CTEXT("%d"), v);
	return GTString(g_szTempBuf);
}
GTString GTString::From(const uint32 v)
{
	tsprintf(g_szTempBuf, CTEXT("%d"), v);
	return GTString(g_szTempBuf);
}
GTString GTString::From(const float v)
{
	tsprintf(g_szTempBuf, CTEXT("%f"), v);
	return GTString(g_szTempBuf);
}
