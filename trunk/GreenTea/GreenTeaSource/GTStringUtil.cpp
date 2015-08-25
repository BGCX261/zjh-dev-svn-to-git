#include "GTStringUtil.h"

// GTStringUtil

// Split a string with separator.
// All sub-strings are stored at result.
void GTStringUtil::Split(const GTString& source,
					     const GTString& separator,
					     GTArray<GTString>& result,
						 StringSplitOptions splitOption)
{
	/*
	if(source.IsEmpty())
    {
        return;
    }

    GTString tmp;
	int pos_begin = source.FindFirstIndexNotOf(separator);
    int pos_separator = 0;

    while(pos_begin != std::string::npos)
    {
		pos_separator = source.Find(separator, pos_begin);
        if (pos_separator != GTString::BadPosition)
        {
			tmp = source.SubString(pos_begin, pos_separator - pos_begin);
			pos_begin = pos_separator + separator.Length();
        }
        else
        {
			tmp = source.SubString(pos_begin);
            pos_begin = pos_separator;
        }

		if(!tmp.IsEmpty())
        {
			// The string content is not empty
			result.Add(tmp);
			tmp.Clear();
        }
		else if(splitOption != RemoveEmptyEntries)
		{
			result.Add(tmp);
			tmp.Clear();
		}
    }
	*/

	GTString str = source;
    GTString substring;
    int start = 0, index;

    do
    {
		index = str.FindFirstIndexOf(separator, start);
		if (index != GTString::BadPosition)
        {   
			substring = str.SubString(start, index - start);
			if(substring.Length())
			{
				result.Add(substring);
			}
			else
			{
				// Length == 0
				if(splitOption != RemoveEmptyEntries)
				{
					result.Add(substring);
				}
			}
			start = str.FindFirstIndexNotOf(separator, index);
			if(start == GTString::BadPosition)
			{
				return;
			}
        }
    } while(index != GTString::BadPosition);
   
    // The last token
	substring = str.SubString(start);
	if(substring.Length())
	{
		result.Add(substring);
	}
	else
	{
		// Length == 0
		if(splitOption != RemoveEmptyEntries)
		{
			result.Add(substring);
		}
	}
}

void GTStringUtil::Split(const GTString& source,
					     const tchar* separator,
					     GTArray<GTString>& result,
						 StringSplitOptions splitOption)
{
	GTStringUtil::Split(source, GTString(separator), result, splitOption);
}

void GTStringUtil::Split(const GTString& source,
					     const tchar separator,
					     GTArray<GTString>& result,
						 StringSplitOptions splitOption)
{
	GTStringUtil::Split(source, GTString::From(separator), result, splitOption);
}

// Return true if c is a white-space character
inline bool IsWhiteSpaceChar(unsigned int c)
{
	return (c==0x20 || (c>=0x09 && c<=0x0D)) ? true : false;
}

// Remove all leading whitespace
GTString GTStringUtil::TrimLeft(const GTString& source)
{
	return GTString(source);
}

// Remove all trailing whitespace
GTString GTStringUtil::TrimRight(const GTString& source)
{
	// Find beginning of trailing spaces by starting
	// at beginning (DBCS aware)

	const tchar* psz = source.ToCharString();
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
		return GTString(source.SubString(0, nLastIndex));
	}

	return GTString(source);
}


/// <summary>
/// Strip out double slashes C++ style comments from a string
/// But allow double slashes to appear inside quotes.
/// 
/// For example:
/// an example //comment         => an example
/// "this is not a //comment"    => "this is not a //comment"
/// but //"this" is              => but
/// "this is //missing end quote => "this is //missing end quote
/// 
/// Not supported:
/// multi-line (untested)
/// quote escaped characters  (ie "will not \"//work\" "  => "will \"
/// </summary>
GTString GTStringUtil::StripDoubleSlashComments(const GTString& source)
{
	int32 length = source.Length() - 1; // -1 since you can't have two slashes with 1 character left
	bool inQuote = false;

	for(int32 i = 0; i < length; i++)
	{
		if(source[i] == CTEXT('"'))      // Should we support '?
		{
			inQuote = !inQuote;
		}

		if(!inQuote && ((source[i] == CTEXT('/')) && (source[i + 1] == CTEXT('/'))))
		{
			return source.SubString(0, i);
		}
	}

	// No double slash comment found
	return source;
}


/// <summary>
/// Strip out C++ style block comments from a string
/// But allow block comment delimeters (/* */) to appear inside quotes.
/// </summary>
/// <remarks>
/// For example:
/// an example /*comment*/			=> an example
/// "this is not a /*comment*/"		=> "this is not a ///*comment*/"
/// but /*"this"*/ is				=> but  is
/// "this is /*missing end quote	=> "this is /*missing end quote
/// line /*comments //are ignored*/	=> line
/// more/*than*/ one /*comment*/	=> more one
/// multi-line/* block
///	  comments */ work				=> multi-line work
/// 
/// Not supported:
/// quote escaped characters  (ie "will not \"//work\" "  => "will \"
/// </remarks>
GTString GTStringUtil::StripBlockComments(GTString& source)
{
	int32 length = source.Length() - 1; // -1 since you can't have //*/ with 1 character left
	bool inQuote = false;
	int32 blockCommentStart = -1;

	for(int32 i = 0; i < length; i++)
	{
		if (source[i] == CTEXT('"'))      // Should we support '?
		{
			inQuote = !inQuote;
		}

		if (!inQuote && blockCommentStart == -1 && ((source[i] == CTEXT('/')) && (source[i + 1] == CTEXT('*'))))
		{
			blockCommentStart = i;
		}

		if (!inQuote && blockCommentStart > -1 && ((source[i] == CTEXT('*')) && (source[i + 1] == CTEXT('/'))))
		{
			source = source.Remove(blockCommentStart, i + 2 - blockCommentStart);	// +2 to include the first and last /
			i = blockCommentStart - 1;	// Reset iterator to before this section
			blockCommentStart = -1;	// Reset for multiple block comments
			length = source.Length() - 1;	// Update the length for the shortened text
		}
	}

	return source;
}


/*
/// <summary>
	/// Splits a long string into an array of string of maxLength 
	/// Does not try to split on word boundaries
	/// todo: parameter to split on word boundaries
	/// </summary>
	/// <param name="source">long input string</param>
	/// <param name="maxLength">the maximum length of each returned string</param>
	/// <param name="splitLinePostFix">string to add to the end of each line</param>
	/// <returns>array of strings where each is &lt;= maxLength </returns>

	public static string[] SplitByLength(string source, int maxLength, string splitLinePostFix)
	{
		string[] response = new string[((source.Length - 1) / maxLength) + 1];
		int remains = source.Length;
		int start = 0;
		int rindex = 0;

		while (remains > 0)
		{
			string line;

			if (maxLength >= remains)
			{
				line = source.Substring(start, remains);
			}
			else
			{
				line = source.Substring(start, maxLength) + splitLinePostFix;
			}

			response[rindex] = line;

			remains -= maxLength;
			start += maxLength;
			rindex++;
		}

		return response;
	}

	/// <summary>
	/// Splits a long string into an array of string of maxLength 
	/// Does not try to split on word boundaries
	/// todo: parameter to split on word boundaries
	/// </summary>

	public static string[] SplitByLength(string source, int maxLength)
	{
		return SplitByLength(source, maxLength, "");
	}
*/

/*
	//http://www.unifycommunity.com/wiki/index.php?title=StringUtil
	// lineWrap
	//  Splits string into lines which are _charsPerLine or shorter.
	//
	//  Current word is buffered so that if _charsPerLine is reached in the middle
	//  of a word the entire word appears on the next line.
	//
	//  Note that variable width fonts are not accounted for so it is likely
	//  you will have to set _charsPerLine much shorter than desired so that lines
	//  with several capital letters or wide chars wrap correctly.
	//
	//  Also takes carriage returns (\n) already in the string into account.
	//
	//
	// Parameters:
	//  string _str      - string to process
	//  int _charPerLine - max # of characters per line.
	//  bool _forceWrap  - if set to true, a continuous string of characters with no spaces
	//            word will be forced to wrap to _charsPerLine
	//            if set to false, word will stay intact and violate _charsPerLine
	//
	// TODO:
	//  Don't count the space at end of a line.
	//  _forceWrap can cause somewhat odd behavior as it is a very simple implementation.
	//
	//  Provided by typeRice - June 12, 2009
	public static string lineWrap(string _str, int _charsPerLine, bool _forceWrap)
	{
		if (_str.Length < _charsPerLine)
			return _str;


		string result = "",
				buf = "";                  // Stores current word

		int cursor = 0,          // Position within _str
			charCount = 0;               // # of chars on current line

		bool bLineEmpty = false;                // if a new line was added to the result &
		// buf has not been appended.

		while (cursor < _str.Length)
		{
			buf += _str[cursor];                // add next character to buffer
			charCount++;                        // increment count of chars on current line

			if (_str[cursor] == ' ')         // if space is encountered
			{
				result += buf;          // write the buffer to the result and clear
				buf = "";
				bLineEmpty = false;    // Something added since the last carriage return
			}
			else if (_str[cursor] == '\n')  // manual carriage return encountered
			{
				result += buf;          // write the buffer to the result and clear (buf contains the \n already)
				buf = "";
				charCount = 0;                    // Start new line so reset character count.
			}

			if (charCount >= _charsPerLine)    // if charCount has reached max chars per line
			{
				if (!bLineEmpty)            // If line has something in it.
				{
					result += '\n';    // Start a new line in the result
					charCount = buf.Length;  // reset character count to current buf size as ths will be placed on the new line.
					bLineEmpty = true;      // Newest line is empty
				}
				else if (_forceWrap)         // else if the line is empty and we want to force word to wrap
				{
					result += buf + '\n';      // write the buffer to the result with a carriage return
					buf = "";               // clear the buffer
					bLineEmpty = true;      // Newest line is empty
					charCount = 0;        // Start new line so reset character count.
				}
			}

			cursor++;                     // Goto next character
		}

		result += buf;              // add any remaining characters in the buffer
		return result;
	}
	*/
