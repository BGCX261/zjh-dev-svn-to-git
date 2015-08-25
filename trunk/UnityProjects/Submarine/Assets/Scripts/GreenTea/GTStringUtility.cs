using System;

public class GTStringUtility
{
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

	public static string StripDoubleSlashComments(string line)
	{
		int length = line.Length - 1; // -1 since you can't have two slashes with 1 character left
		bool inQuote = false;

		for (int i = 0; i < length; i++)
		{
			if (line[i] == '"')      //should we support '?
			{
				inQuote = !inQuote;
			}

			if (!inQuote && ((line[i] == '/') && (line[i + 1] == '/')))
			{
				return line.Substring(0, i);
			}
		}

		//no double slash comment found
		return line;
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

	public static string StripBlockComments(string text)
	{
		int length = text.Length - 1; // -1 since you can't have */ with 1 character left
		bool inQuote = false;
		int blockCommentStart = -1;

		for (int i = 0; i < length; i++)
		{
			if (text[i] == '"')      //should we support '?
			{
				inQuote = !inQuote;
			}

			if (!inQuote && blockCommentStart == -1 && ((text[i] == '/') && (text[i + 1] == '*')))
			{
				blockCommentStart = i;
			}

			if (!inQuote && blockCommentStart > -1 && ((text[i] == '*') && (text[i + 1] == '/')))
			{
				text = text.Remove(blockCommentStart, i + 2 - blockCommentStart);	// +2 to include the first and last /
				i = blockCommentStart - 1;	// Reset iterator to before this section
				blockCommentStart = -1;	// Reset for multiple block comments
				length = text.Length - 1;	// Update the length for the shortened text
			}
		}

		return text;
	}

	/// <summary>
	/// Remove most whitespace (including \n\r) and quotes " & ' from the ends of a string
	/// ex.  "hi there  " => hi there
	/// </summary>
	/// <param name="value">The input string to do the trimming</param>
	/// <returns>the value string with all whitespace and quotes removed from the ends</returns>

	public static string TrimWhiteSpaceAndQuotes(string value)
	{
		char[] quotes = { ' ', '\t', '\n', '\r', '"', '\'' };
		return value.Trim(quotes);
	}

	/// <summary>
	/// Returns 'true' if the specified strings are equal. Case-insensitive.
	/// </summary>

	public static bool Equals(string a, string b)
	{
		return string.Equals(a, b, StringComparison.OrdinalIgnoreCase);
	}

	/// <summary>
	/// Whether string 'a' begins with string 'b'.
	/// </summary>

	public static bool StartsWith(string a, string b)
	{
		return a.StartsWith(b, StringComparison.OrdinalIgnoreCase);
	}

	/// <summary>
	/// Whether string 'a' ends with string 'b'.
	/// </summary>

	public static bool EndsWith(string a, string b)
	{
		return a.EndsWith(b, StringComparison.OrdinalIgnoreCase);
	}

	/// <summary>
	/// Case-insensitive string comparison.
	/// </summary>

	public static bool Match(string a, string b)
	{
		return (0 == string.Compare(a, b, true));
	}

	/// <summary>
	/// The function reverses each sub string splitted by '\n'
	/// </summary>
	/// <param name="s"></param>
	/// <returns></returns>
	public static string ReverseString(string s)
	{
		string[] stringArray = s.Split('\n');
		string sortedString = "";
		for (int i = 0; i < stringArray.Length; i++)
		{
			char[] arr = stringArray[i].ToCharArray();
			Array.Reverse(arr);
			sortedString += new string(arr);
			if (i != stringArray.Length - 1)
			{
				sortedString += '\n';
			}
		}
		return sortedString;
	}

	/// <summary>
	/// Retrieves a continuous line at the specified coordinates, up to the last word that fits
	/// </summary>
	/// <param name="inString">The string to be parsed</param>
	/// <param name="outString">The string that is returned</param>
	/// <param name="from">Index to start at</param>
	/// <param name="to">Index to try and read to</param>

	public static int GetPhrase (string inString, out string outString, int from, int to)
	{
		if (to < inString.Length)
		{
			// Backtrack to the last space
			int index = to;
			while (index > from && inString[index] > 32) --index;

			// Found a space -- the line will count up to this character, skipping the space
			if (index > from)
			{
				outString = inString.Substring(from, index);
				return index + 1;
			}
		}

		// No modification to the line -- remember it as-is
		outString = inString.Substring(from, to);
		return to;
	}

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
}
