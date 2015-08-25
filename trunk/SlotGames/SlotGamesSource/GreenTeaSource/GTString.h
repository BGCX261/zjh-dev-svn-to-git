#ifndef _GREENTEA_STRING_H_
#define _GREENTEA_STRING_H_

#include <string>
#include <algorithm>
#include <stdlib.h>
#include "GTBaseDef.h"

class GTString
{
public:
	typedef std::string DataStringType;

public:
	GTString() : m_sString(GTString::EmptyString)
	{
	}
	GTString(const GTString& src)
	{
		m_sString = src.m_sString;
	}
	GTString(const tchar* str)
	{
		m_sString = str;
	}
	/*
	GTString(const tchar str)
	{
		m_sString = str;
	}
	GTString(const int16 v)
	{
		m_sString = GTString::From(v);
	}
	GTString(const uint16 v)
	{
		m_sString = GTString::From(v);
	}
	GTString(const int32 v)
	{
		m_sString = GTString::From(v);
	}
	GTString(const uint32 v)
	{
		m_sString = GTString::From(v);
	}
	GTString(const float v)
	{
		m_sString = GTString::From(v);
	}
	*/
	
	virtual ~GTString()
	{
		m_sString.clear();
	}

	// Get the length of the string
	int Length() const
	{
		return StringLength(m_sString.c_str());
	}

	const tchar* ToCharString() const
	{
		return m_sString.c_str();
	}

	// Translate string value to integer
	int ToInt() const
	{
		return atoi(m_sString.c_str());
	}
	inline int AsInt() const
	{
		return ToInt();
	}

	// Translate string value to unsigned integer
	unsigned int ToUInt() const
	{
		return (unsigned int)atoi(m_sString.c_str());
	}
	inline unsigned int AsUInt() const
	{
		return ToUInt();
	}

	// Translate string value to float
	float ToFloat() const
	{
		return (float)atof(m_sString.c_str());
	}
	inline float AsFloat() const
	{
		return ToFloat();
	}

	// Translate string value to bool
	bool ToBool() const
	{
		if(m_sString == CTEXT("1") ||
		   m_sString == CTEXT("True") ||
		   m_sString == CTEXT("true") ||
		   m_sString == CTEXT("TRUE"))
		   
		{
			return true;
		}
		else if(m_sString == CTEXT("0") ||
		        m_sString == CTEXT("False") ||
				m_sString == CTEXT("false") ||
				m_sString == CTEXT("FALSE"))
		{
			return false;
		}

		return false;
	}
	inline bool AsBool() const
	{
		return ToBool();
	}

	std::string ToStdString()
	{
		return m_sString;
	}

	bool IsEmpty() const
	{
		return m_sString.empty();
	}

    bool IsEqual(const GTString& right) const
    {
		return StringCmp(m_sString.c_str(), right.m_sString.c_str()) ? false : true;
	}

	bool IsEqual(const tchar* sString) const
    {
		return StringCmp(m_sString.c_str(), sString) ? false : true;
	}

	operator const tchar*()
	{
		return m_sString.c_str();
	}

	operator int() const
	{
		return ToInt();
	}

	operator unsigned int() const
	{
		return ToUInt();
	}

	operator float() const
	{
		return ToFloat();
	}

	// operator=
	GTString& operator=(const GTString& right)
	{
		m_sString = right.m_sString;
		return (*this);
	}

	GTString& operator=(const tchar* right)
	{
		m_sString = right;
		return (*this);
	}
	
	GTString& operator=(tchar right)
	{
		m_sString = right;
		return (*this);
	}

	// operator+=
	GTString& operator+=(const GTString& right)
	{
		m_sString += right.m_sString;
		return (*this);
	}

	GTString& operator+=(const tchar* right)
	{
		m_sString += right;
		return (*this);
	}

	GTString& operator+=(tchar right)
	{
		m_sString += right;
		return (*this);
	}

	// operator==
	bool operator==(const GTString& right) const
	{
		return StringCmp(m_sString.c_str(), right.m_sString.c_str()) ? false : true;
	}

	bool operator==(const tchar* right) const
	{
		return StringCmp(m_sString.c_str(), right) ? false : true;
	}

	// operator<
	bool operator<(const tchar* right) const
	{
		return (m_sString < right);
	}

	bool operator<(const GTString& right) const
	{
		return (m_sString < right.ToCharString());
	}

	// operator>
	bool operator>(const tchar* right) const
	{
		return (m_sString > right);
	}

	bool operator>(const GTString& right) const
	{
		return (m_sString > right.ToCharString());
	}

	// operator!=
	bool operator!=(const tchar* right) const
	{
		return (m_sString != right);
	}

	bool operator!=(const GTString& right) const
	{
		return (m_sString != right.ToCharString());
	}

	// operator<=
	bool operator<=(const tchar* right) const
	{
		return (!(*this > right));
	}

	bool operator<=(const GTString& right) const
	{
		return (!(*this > right.ToCharString()));
	}

	// operator>=
	bool operator>=(const tchar* right) const
	{
		return (!(*this < right));
	}

	bool operator>=(const GTString& right) const
	{
		return (!(*this < right.ToCharString()));
	}

	// operator[]
	tchar operator[](int index) const
	{
		return m_sString[index];
	}

	void Clear(void)
	{
		m_sString.clear();
	}

	GTString& Append(const tchar* str) 
	{
		m_sString.append(str);
		return (*this);
	}

	GTString& Append(const GTString& str) 
	{
		m_sString.append(str.m_sString);
		return (*this);
	}

	int Find(const GTString& target) const
	{
		return m_sString.find(target.m_sString, 0);
	}

	int Find(const GTString& target, const int offset) const
	{
		return m_sString.find(target.m_sString, offset);
	}

	int Find(const tchar* target) const
	{
		return m_sString.find(target, 0);
	}

	int Find(const tchar* target, const int offset) const
	{
		return m_sString.find(target, offset);
	}

	int FindFirstIndexOf(const GTString& target, int offset) const
	{
		return m_sString.find_first_of(target.m_sString, offset);
	}

	int FindFirstIndexOf(const GTString& target) const
	{
		return m_sString.find_first_of(target.m_sString, 0);
	}

	int FindFirstIndexOf(const tchar* target, int offset) const
	{
		return m_sString.find_first_of(target, offset);
	}

	int FindFirstIndexOf(const tchar* target) const
	{
		return m_sString.find_first_of(target, 0);
	}

	int FindFirstIndexOf(tchar target, int offset) const
	{
		return m_sString.find_first_of(target, offset);
	}

	int FindFirstIndexOf(tchar target) const
	{
		return m_sString.find_first_of(target, 0);
	}

	int FindFirstIndexNotOf(const GTString& target) const
	{
		return m_sString.find_first_not_of(target.m_sString, 0);
	}

	int FindFirstIndexNotOf(const GTString& target, int offset) const
	{
		return m_sString.find_first_not_of(target.m_sString, offset);
	}

	int FindFirstIndexNotOf(const tchar* target) const
	{
		return m_sString.find_first_not_of(target, 0);
	}

	int FindFirstIndexNotOf(const tchar* target, int offset) const
	{
		return m_sString.find_first_not_of(target, offset);
	}

	int FindLastIndexOf(const GTString& target, int offset) const
	{
		return m_sString.find_last_of(target.m_sString, offset);
	}

	int FindLastIndexOf(const tchar* target, int offset) const
	{
		return m_sString.find_last_of(target, offset);
	}

	int FindLastIndexNotOf(const GTString& target, int offset) const
	{
		return m_sString.find_last_not_of(target.m_sString, offset);
	}

	int FindLastIndexNotOf(const tchar* target, int offset) const
	{
		return m_sString.find_last_not_of(target, offset);
	}

	// Set string length without change buffer, just adjusting
	// the position of GTString::StringTerminator
	void SetLength(const int32 nNewLength)
	{
		DBG_ASSERT(nNewLength < Length());
		m_sString[nNewLength] = GTString::StringTerminator;
	}

	// Return a sub-string of the string
	GTString SubString(const int32 start, const int32 count) const
	{
		DBG_ASSERT(start < Length());
		return GTString((const tchar*)m_sString.substr(start, count).c_str());
	}

	GTString SubString(const int32 start) const
	{
		DBG_ASSERT(start < Length());
		return GTString((const tchar*)m_sString.substr(start).c_str());
	}

	// Remove the characters beginning at specified position start
	GTString Remove(const int32 start, const int32 count)
	{
		DBG_ASSERT(start < Length());
		return GTString(m_sString.erase(start, count).c_str());
	}

	// Check if current string starts with s
	//   true - yes
	//   false - no
	bool StartsWith(const tchar* s)
	{
		return GTString::StartsWith(m_sString.c_str(), s);
	}
	bool StartsWith(const GTString& s)
	{
		return GTString::StartsWith(m_sString.c_str(), s.ToCharString());
	}

	// Returns a new string in which all occurrences of a specified 
	// character or String in the current string are replaced with
	// another specified character or String.
	GTString Replace(const int32 start, const int32 count, const tchar* newString)
	{
		DBG_ASSERT(start < Length());
		return GTString(m_sString.replace(start, count, newString).c_str());
	}

	// Return true if c is a white-space character
	inline bool IsWhiteSpaceChar(unsigned int c)
	{
		return (c==0x20 || (c>=0x09 && c<=0x0D)) ? true : false;
	}

	// To lower case
	void ToLower(void)
	{
		std::transform(m_sString.begin(), m_sString.end(), m_sString.begin(), ::tolower);
	}
	// To upper case
	void ToUpper(void)
	{
		std::transform(m_sString.begin(), m_sString.end(), m_sString.begin(), ::toupper);
	}
				
	// Remove all trailing whitespace
	GTString& TrimRight();	
	// Remove all leading whitespace
	GTString& TrimLeft();
	// Remove all leading and trailing whitespace
	GTString& Trim();

public:
	// Static methods
	// Compare two strings to see if they are exactly same:
	//   true - equal
	//   false - not equal
	static bool IsEqual(const tchar* s1, const tchar* s2)
	{
		return StringCmp(s1, s2) ? false : true;
	}

	// Check if s1 starts with s2
	//   true - yes
	//   false - no
	static bool StartsWith(const tchar* s1, const tchar* s2)
	{
		return StringNCmp(s1, s2, StringLength(s2)) ? false : true;
	}

	// Format a string
	static GTString Format(const tchar* szMes, ...);
	// Convert v to string
	static GTString From(const tchar v);
	static GTString From(const int16 v);
	static GTString From(const uint16 v);
	static GTString From(const int32 v);
	static GTString From(const uint32 v);
	static GTString From(const float v);

	// Static variables
	static const int32 BadPosition;
	static const tchar* EmptyString;
	static const tchar StringTerminator;
	static const int16 WhitespaceChars[];

private:
	DataStringType m_sString;
};

#endif /* _GREENTEA_STRING_H_ */
