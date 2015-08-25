#include "GTTreeNode.h"
#include "GTStringUtil.h"
#include "GTArray.h"

GTTreeNode::GTTreeNode():
	m_sTag(CTEXT("Root")),
	m_sValue(CTEXT(""))
{	
}

GTTreeNode::~GTTreeNode()
{
	Release();
}

// Translate the value to GTVector2
GTVector2 GTTreeNode::ValueToVector2(void) const
{
	return GTVector2::Parse(m_sValue);
}

// Translate the value to GTVector3
GTVector3 GTTreeNode::ValueToVector3(void) const
{
	return GTVector3::Parse(m_sValue);
}

// Translate the value to GTSize
GTSize GTTreeNode::ValueToSize(void) const
{
	return GTSize::Parse(m_sValue);
}

// Translate the value to GTPairValue
GTPairValue GTTreeNode::ValueToPairValue(void) const
{
	GTArray<GTString> parts;
	GTStringUtil::Split(m_sValue, CTEXT(" "), parts, GTStringUtil::RemoveEmptyEntries);
	if(2 == parts.Length())
	{
		return GTPairValue(parts[0], parts[1]);
	}

	return GTPairValue(GTString::EmptyString, GTString::EmptyString);
}

// Translate the value to GTArray<int32>, seperated by space
void GTTreeNode::ValueToArrayInt(GTArray<int32>& gtArray)
{
	GTArray<GTString> parts;
	GTStringUtil::Split(m_sValue, CTEXT(" "), parts, GTStringUtil::RemoveEmptyEntries);
	if(0 == parts.Length())
	{
		return;
	}
	for(int32 i=0; i<parts.Length(); i++)
	{
		gtArray.Add(parts[i].ToInt());
	}
}

// Translate the value to GTArray<float>, seperated by space
void GTTreeNode::ValueToArrayFloat(GTArray<float>& gtArray)
{
	GTArray<GTString> parts;
	GTStringUtil::Split(m_sValue, CTEXT(" "), parts, GTStringUtil::RemoveEmptyEntries);
	if(0 == parts.Length())
	{
		return;
	}
	for(int32 i=0; i<parts.Length(); i++)
	{
		gtArray.Add(parts[i].ToFloat());
	}
}

// Translate the value to GTArray<GTString>, separated by space
void GTTreeNode::ValueToArrayString(GTArray<GTString>& gtArray)
{
	GTArray<GTString> parts;
	GTStringUtil::Split(m_sValue, CTEXT(" "), parts, GTStringUtil::RemoveEmptyEntries);
	if(0 == parts.Length())
	{
		return;
	}
	for(int32 i=0; i<parts.Length(); i++)
	{
		gtArray.Add(parts[i]);
	}
}


// Release
void GTTreeNode::Release()
{
	if(m_Children.Count())
	{
		for(GTList<GTTreeNode*>::ObjectTypeIterator it = m_Children.Begin();
			it != m_Children.End();
			it++)
		{
			if(*it)
			{
				(*it)->Release();
			}
		}

		m_Children.Clear();

		delete this;
	}
}

/*
public class TreeNode
{
	public string tag = "Root";
	private object mValue = null;
	private static string mDecimalSeparator = System.Globalization.NumberFormatInfo.CurrentInfo.CurrencyDecimalSeparator;

	public List<TreeNode> children = null;
	public Flags flags;

	public TreeNode() { }
	public TreeNode(string tagText) { tag = tagText; }
	public TreeNode(string tagText, object valueObject) { tag = tagText; value = valueObject; }

	/// <summary>
	/// Sets the node's value to an arbitrary object.
	/// </summary>

	public object value
	{
		get
		{
			return mValue;
		}
		set
		{
			if (value == null || value is float || value is int || value is string || value is bool ||
				value is float[] || value is int[])
			{
				mValue = value;
			}
			else if (value is Vector2)
			{
				Vector2 v = (Vector2)value;
				mValue = new float[] { v.x, v.y };
			}
			else if (value is Vector3)
			{
				Vector3 v = (Vector3)value;
				mValue = new float[] { v.x, v.y, v.z };
			}
			else if (value is Vector4)
			{
				Vector4 v = (Vector4)value;
				mValue = new float[] { v.x, v.y, v.z, v.w };
			}
			else if (value is Quaternion)
			{
				Quaternion v = (Quaternion)value;
				mValue = new float[] { v.x, v.y, v.z, v.w };
			}
			else if (value is Color)
			{
				Color v = (Color)value;
				mValue = new float[] { v.r, v.g, v.b, v.a };
			}
			else if (value is Rect)
			{
				Rect v = (Rect)value;
				mValue = new float[] { v.x, v.y, v.width, v.height };
			}
			else
			{
				Debugger.LogError(value.GetType() + " can't be added as a value of TreeNode!");
			}
		}
	}
*/

// Helper function that converts a hex digit to its decimal representation
int16 GTTreeNode::ReadHex(tchar ch)
{
	if (ch >= CTEXT('0') && ch <= CTEXT('9')) return (int16)(ch - CTEXT('0'));
	if (ch >= CTEXT('a') && ch <= CTEXT('f')) return (int16)(10 + ch - CTEXT('a'));
	if (ch >= CTEXT('A') && ch <= CTEXT('F')) return (int16)(10 + ch - CTEXT('A'));
	return 0;
}

// Adds a new child to this node.
GTTreeNode* GTTreeNode::AddChild()
{
	GTTreeNode* node = new GTTreeNode();
	m_Children.AddToTail(node);
	return node;
}

// Adds an existing tree node as a child of this one.
GTTreeNode* GTTreeNode::AddChild(GTTreeNode* child)
{
	if(child == NULL)
	{
		return NULL;
	}
	m_Children.AddToTail(child);
	return child;
}

// Adds a new child node to this node.
GTTreeNode* GTTreeNode::AddChild(const tchar* tag)
{
	GTTreeNode* node = AddChild();
	if(node != NULL)
	{
		node->m_sTag = tag;
	}

	return node;
}

// Retrieves a child node by its tag. This method does not recurse into children.
// Found child node, or null if a match was not found.
GTTreeNode* GTTreeNode::GetChild(const tchar* szTag, bool bVerifyCase)
{
	for(GTList<GTTreeNode*>::ObjectTypeIterator it = m_Children.Begin();
		it != m_Children.End();
		it++)
	{
		if((*it)->m_sTag.IsEqual(szTag))
		{
			return (*it);
		}
		/*
		if (it->m_sTag == szTag || (!bVerifyCase && it->m_sTag.ToLower()==tag.ToLower()))
				{
					return node;
				}
			}
		}
		return null;
		*/
	}

	return NULL;
}

// Retrieves a child node by its tag. This method does not recurse into children.
GTTreeNode* GTTreeNode::GetChild(const tchar* szTag)
{
	return GetChild(szTag, true);
}


// Retrieves a child node by its index. This method does not recurse into children.
GTTreeNode* GTTreeNode::GetChild(const int32 nIndex)
{
	int32 nCount = 0;
	for(GTList<GTTreeNode*>::ObjectTypeIterator it = m_Children.Begin();
		it != m_Children.End();
		it++)
	{
		if(nCount == nIndex)
		{
			// Found the child
			return (*it);
		}
		nCount++;
	}

	return NULL;
}


// Recursive search for a child with the specified tag.
GTTreeNode* GTTreeNode::FindChild(const tchar* szTag, bool bVerifyCase)
{
	return GetChild(szTag, bVerifyCase);

	/*
	GTTreeNode* child = GetChild(szTag, bVerifyCase);
	if(child != NULL)
	{
		return child;
	}
	*/

	/*
	for(GTList<GTTreeNode*>::ObjectTypeIterator it = m_Children.Begin();
		it != m_Children.End();
		it++)
	{
		child = (*it)->FindChild(szTag, bVerifyCase);
		if(child != NULL)
		{
			return child;
		}
	}
	*/

	return NULL;
}

/// <summary>
/// Recursive search for a child with the specified tag.
/// </summary>
/// <param name="tag">Tag to match.</param>
/// <param name="verifyCase">Check case during search</param>
/// <returns>Found child node, or null if a match was not found.</returns>
GTTreeNode* GTTreeNode::FindChild(const tchar* szTag)
{
	return FindChild(szTag, true);
}

/// <summary>
/// Finds a node that contains a child with the requested tag.
/// </summary>
/// <param name="tag">Tag to match.</param>
/// <returns>Foudn parent node, or null if no match was found.</returns>
GTTreeNode* GTTreeNode::FindParentOf(const tchar* szTag)
{
	GTTreeNode* child = GetChild(szTag);
	if(child != NULL)
	{
		return this;
	}

	for(GTList<GTTreeNode*>::ObjectTypeIterator it = m_Children.Begin();
		it != m_Children.End();
		it++)
	{
		child = (*it)->FindParentOf(szTag);
		if(child != NULL)
		{
			return child;
		}
	}

	return NULL;
}

int32 GTTreeNode::ProcessLines(GTArray<GTString>& lines, int32 offset)
{
	GTTreeNode* lastChild = NULL;
	GTString tagText, valueText;

	for(; offset < lines.Length(); ++offset)
	{
		GTString trimmed = lines[offset];

		// Remove C++ style comment
		trimmed = GTStringUtil::StripDoubleSlashComments(trimmed);
		trimmed.Trim();

		int32 length = trimmed.Length();
		// Do we still have something to work with?
		if(trimmed.Length() > 0)
		{
			int idx = trimmed.FindFirstIndexOf(CTEXT('='));
			if(idx == GTString::BadPosition)
			{
				// This line only contains tag, not value.
				tagText = trimmed;
				valueText = GTString::EmptyString;
			}
			else
			{
				// This line contains both tag and value.
				tagText = trimmed.SubString(0, idx).Trim();
				valueText = trimmed.SubString(idx + 1).Trim();
			}

			if(tagText == CTEXT("{"))
			{
				// Opening a new child segment
				offset = lastChild->ProcessLines(lines, offset + 1);
			}
			else if (tagText == CTEXT("}"))
			{
				// We're done with this segment
				return offset;
			}
			else
			{
				/*
				if (mDecimalSeparator == CTEXT(","))
				{
					//--ReplaceDecimalSeparator(ref tagText, '.', ',');
				}
				*/
				lastChild = AddChild((const tchar*)tagText);
				//--lastChild.value = StringToObject(valueText);
				if(lastChild)
				{
					lastChild->SetValue(valueText);
				}
			}
		}
	}

	return offset;
}

/*
// Processes a set of lines, parsing child nodes as well as own values
int TreeNode::ProcessLines(string[] lines, int offset)
	{
		TreeNode lastChild = null;
		string tagText, valueText;

		for (; offset < lines.Length; ++offset)
		{
			string trimmed = lines[offset];

			// Remove C++ style comment
			trimmed = StringUtility.StripDoubleSlashComments(trimmed);
			trimmed = trimmed.Trim();

			// Do we still have something to work with?
			if (trimmed.Length > 0)
			{
				int idx = trimmed.IndexOf('=');

				if (idx == -1)
				{
					tagText = trimmed;
					valueText = string.Empty;
				}
				else
				{
					tagText = trimmed.Substring(0, idx).Trim();
					valueText = trimmed.Substring(idx + 1).Trim();
				}

				if (tagText == "{")
				{
					// Opening a new child segment
					offset = lastChild.ProcessLines(lines, offset + 1);
				}
				else if (tagText == "}")
				{
					// We're done with this segment
					return offset;
				}
				else
				{
					if (mDecimalSeparator == ",")
					{
						ReplaceDecimalSeparator(ref tagText, '.', ',');
					}
					lastChild = AddChild(tagText);
					lastChild.value = StringToObject(valueText);
				}
			}
		}
		return offset;
	}
*/

GTTreeNode* GTTreeNode::FromString(const tchar* szText)
{
	GTString text = GTString(szText);
	const int32 nLength = text.Length();

	//if(szText != NULL && nLength > 1)
	if(nLength > 1)
	{
		// Note: All Unicode files have the first character as 0xeff
		// Adding the check for text[0] = 0xfeff address this issue.
		if (text[0] == CTEXT('{') || (text[0] == 0xfeff && text[1] == CTEXT('{')))
		{
			// JSON file format
			//text = JSONToTreeNode(text);
		}

		// Remove c++ style block comments (/* */)
		text = GTStringUtil::StripBlockComments(text);

		GTArray<GTString> lines;
		GTStringUtil::Split(text, CTEXT('\n'), lines, GTStringUtil::RemoveEmptyEntries);

		if(nLength > 0)
		{
			GTTreeNode* tree = new GTTreeNode();
			tree->ProcessLines(lines, 0);
			return (tree->HasChildren() ? tree->m_Children[0] : tree);
		}
	}

	return NULL;
}

/*
    	
	/// <summary>
	/// Converts the tree into an easy-to-read nested text format.
	/// </summary>
	/// <returns>Printable multi-line string representation of this tree.</returns>

	public override string ToString() { return ToString(0); }

	// Layered version of the function above
	private string ToString(int level)
	{
		string padding = "";
		for (int i = 0; i < level; ++i) padding += "\t";

		string returnText = padding + tag;
		string valueText = AsString();

		// Add a value to the end if there is something to add
		if (valueText.Length != 0)
		{
			returnText += " = ";

			if (mValue is string)
			{
				returnText += "\"" + valueText + "\"";
			}
			else
			{
				if (mDecimalSeparator == ",")
				{
					ReplaceDecimalSeparator(ref valueText, ',', '.');
				}
				returnText += valueText;
			}
		}

		// Start on the next line
		returnText += "\n";

		// Add all children if they are present
		if (hasChildren)
		{
			returnText += padding + "{\n";
			bool parentHadChildren = false;

			for (int i = 0; i < children.Count; ++i)
			{
				TreeNode node = children[i];

				// Split up logical blocks of text
				if (i > 0 && (parentHadChildren || node.hasChildren))
				{
					returnText += "\n";
				}

				// Append the child
				returnText += node.ToString(level + 1);

				// Remember whether this child had children for the following logical block check
				parentHadChildren = node.hasChildren;
			}

			returnText += padding + "}\n";
		}
		return returnText;
	}

	/// <summary>
	/// Convenience function that converts an array of bytes to a string to be processed.
	/// </summary>
	/// <param name="buffer">Array of ASCII bytes.</param>
	/// <returns>Parsed TreeNode.</returns>

	static public TreeNode FromBytes(byte[] buffer)
	{
		string str = null;

		try
		{
			str = System.Text.Encoding.UTF8.GetString(buffer);
			//str = System.Text.Encoding.ASCII.GetString(buffer);
		}
		catch (Exception)
		{
			return null;
		}
		return FromString(str);
	}

	/// <summary>
	/// Parses a string representation of the tree and fills out the hierarchy.
	/// Supports TreeNode as well as JSON formats.
	/// </summary>
	/// <param name="text">Text to parse.</param>
	/// <returns>Newly created tree or 'null' if parsing was not successful.</returns>

	static public TreeNode FromString(string text)
	{
		if (text != null && text.Length > 1)
		{
			// Note: All Unicode files have the first character as 0xeff
			// Adding the check for text[0] = 0xfeff address this issue.
			if (text[0] == '{' || (text[0] == 0xfeff && text[1] == '{'))
			{
				text = JSONToTreeNode(text);
			}

			//////// Remove c++ style block comments (/* *-/)
			text = StringUtility.StripBlockComments(text);

			string[] lines = text.Split(new char[] { '\n' }, StringSplitOptions.RemoveEmptyEntries);

			if (lines.Length > 0)
			{
				TreeNode tree = new TreeNode();
				tree.ProcessLines(lines, 0);
				return (tree.children != null) ? tree.children[0] : tree;
			}
		}
		return null;
	}

	/// <summary>
	/// Parses a JSON file format, converting it to a TreeNode string.
	/// </summary>
	/// <param name="text">Text to parse.</param>
	/// <returns>String in TreeNode format.</returns>

	static private string JSONToTreeNode(string text)
	{
		bool quoted = false, escaped = false;
		String parsed = "JSON\n";

		for (int i = 0; i < text.Length; ++i)
		{
			char ch = text[i];

			if (!escaped)
			{
				// Slash indicates an escaped character -- although we only support escaped quotes
				if (ch == '\\')
				{
					escaped = true;
					continue;
				}

				// If it's a quote, flip the quoted flag
				if (ch == '"')
				{
					quoted = !quoted;
					continue;
				}
			}

			// Process this character
			if (quoted)
			{
				parsed += ch;
			}
			else if (ch == ':')
			{
				parsed += " = ";
			}
			else if (ch == ',')
			{
				parsed += '\n';
			}
			else if (ch == '{')
			{
				parsed += "\n{\n";
			}
			else if (ch == '}')
			{
				parsed += "\n}\n";
			}
			else if (ch > ' ')
			{
				parsed += ch;
			}

			// Remove the escaped character flag
			escaped = false;
		}
		return parsed;
	}

	/// <summary>
	/// LEGACY FORMAT SUPPORT FUNCTION! Will be removed.
	/// </summary>

	private static object ProcessLegacyFormat(string subString)
	{
		string[] entries = subString.Split(',');

		try
		{
			if (entries.Length == 1)
			{
				return Convert.ToSingle(entries[0]);
			}
			else if (entries.Length == 2)
			{
				return new Vector2(
					Convert.ToSingle(entries[0]),
					Convert.ToSingle(entries[1]));
			}
			else if (entries.Length == 3)
			{
				return new Vector3(
					Convert.ToSingle(entries[0]),
					Convert.ToSingle(entries[1]),
					Convert.ToSingle(entries[2]));
			}
			else if (entries.Length == 4)
			{
				return new Vector4(
					Convert.ToSingle(entries[0]),
					Convert.ToSingle(entries[1]),
					Convert.ToSingle(entries[2]),
					Convert.ToSingle(entries[3]));
			}
		}
		catch (FormatException)
		{
			Debugger.LogError("Legacy format parsing error:\n" + subString);
		}
		return subString;
	}

	static private char[] mSeparator = { ' ' };

	/// <summary>
	/// New file format support parsing.
	/// </summary>

	private static object ProcessNewFormat(string line)
	{
		bool spaces = line.Contains(" ");
		bool dots = line.Contains(".");

		try
		{
			string[] entries = spaces ? line.Split(mSeparator, StringSplitOptions.RemoveEmptyEntries) : null;

			if (!dots)
			{
				if (entries == null) return int.Parse(line);

				int[] data = new int[entries.Length];

				for (int i = 0; i < data.Length; ++i)
				{
					data[i] = int.Parse(entries[i]);
				}
				return data;
			}

			if (entries == null)
			{
				if (mDecimalSeparator == ",")
				{
					ReplaceDecimalSeparator(ref line, '.', ',');
				}
				return float.Parse(line);
			}
			else
			{
				float[] data = new float[entries.Length];

				for (int i = 0; i < data.Length; ++i)
				{
					if (mDecimalSeparator == ",")
					{
						ReplaceDecimalSeparator(ref entries[i], '.', ',');
					}
					data[i] = float.Parse(entries[i]);
				}
				return data;
			}
		}
		catch (FormatException) { }
		return line;
	}

	/// <summary>
	/// Replaces decimal separator if string represents a floating point number.
	/// </summary>

	private static void ReplaceDecimalSeparator(ref string line, char original, char replacement)
	{
		bool number = true;
		foreach (char letter in line)
		{
			if (!Char.IsDigit(letter) &&
				letter != original &&
				letter != '-' &&
				letter != ' ' &&
				letter != ';')
			{
				number = false;
				break;
			}
		}
		if (number)
		{
			line = line.Replace(original, replacement);
		}
	}
	*/

/*
/// <summary>
/// Parses the specified string, returning an object that contains the string's value
/// </summary>
public static object StringToObject(string text)
	{
		object obj = null;

		if (text.Length > 0)
		{
			if (text.StartsWith("\"") && text.EndsWith("\""))
			{
				// Text wrapped in quotes comes as-is
				obj = text.Substring(1, text.Length - 2);
			}
			else
			{
				// LEGACY FORMAT SUPPORT, WILL BE REMOVED!
				if (text.EndsWith(")"))
				{
					if (text.StartsWith("RGBA("))
					{
						string subString = text.Substring(5, text.Length - 6);
						obj = ProcessLegacyFormat(subString);
					}
					else if (text.StartsWith("("))
					{
						string subString = text.Substring(1, text.Length - 2);
						obj = ProcessLegacyFormat(subString);
					}
					else
					{
						obj = text;
					}
				}
				else if (StringUtility.Equals(text, "true"))
				{
					obj = true;
				}
				else if (StringUtility.Equals(text, "false"))
				{
					obj = false;
				}
				else
				{
					// New file format -- parse the text into correct type
					obj = ProcessNewFormat(text);
				}
			}
		}
		else
		{
			obj = null;
		}
		return (obj == null) ? text : obj;
	}
	*/

	/*
	/// <summary>
	/// Conversion function
	/// </summary>

	public static string ObjectToString(object obj)
	{
		if (obj != null)
		{
			if (obj is string) return (string)obj;
			if (obj is float) return ((float)obj).ToString();
			if (obj is bool) return ((bool)obj) ? "true" : "false";
			if (obj is int) return ((int)obj).ToString();

			if (obj is float[])
			{
				float[] data = (float[])obj;
				if (data.Length == 0) return "";
				string retVal = data[0].ToString("0.0000");
				for (int i = 1; i < data.Length; ++i) retVal += " " + data[i].ToString("0.0000");
				return retVal;
			}

			if (obj is int[])
			{
				int[] data = (int[])obj;
				if (data.Length == 0) return "";
				string retVal = data[0].ToString();
				for (int i = 1; i < data.Length; ++i) retVal += " " + data[i];
				return retVal;
			}
		}
		return "";
	}

	// Processes a set of lines, parsing child nodes as well as own values
	private int ProcessLines(string[] lines, int offset)
	{
		TreeNode lastChild = null;
		string tagText, valueText;

		for (; offset < lines.Length; ++offset)
		{
			string trimmed = lines[offset];

			// Remove C++ style comment
			trimmed = StringUtility.StripDoubleSlashComments(trimmed);
			trimmed = trimmed.Trim();

			// Do we still have something to work with?
			if (trimmed.Length > 0)
			{
				int idx = trimmed.IndexOf('=');

				if (idx == -1)
				{
					tagText = trimmed;
					valueText = string.Empty;
				}
				else
				{
					tagText = trimmed.Substring(0, idx).Trim();
					valueText = trimmed.Substring(idx + 1).Trim();
				}

				if (tagText == "{")
				{
					// Opening a new child segment
					offset = lastChild.ProcessLines(lines, offset + 1);
				}
				else if (tagText == "}")
				{
					// We're done with this segment
					return offset;
				}
				else
				{
					if (mDecimalSeparator == ",")
					{
						ReplaceDecimalSeparator(ref tagText, '.', ',');
					}
					lastChild = AddChild(tagText);
					lastChild.value = StringToObject(valueText);
				}
			}
		}
		return offset;
	}

	/// <summary>
	/// Returns the value as an array of floats.
	/// </summary>

	public float[] AsFloatArray()
	{
		if (mValue != null)
		{
			if (mValue is float[]) return (float[])mValue;
		}
		return null;
	}

	/// <summary>
	/// Returns the value as an array of ints.
	/// </summary>

	public int[] AsIntArray()
	{
		if (mValue != null)
		{
			if (mValue is int[]) return (int[])mValue;
		}
		return null;
	}

	/// <summary>
	/// Returns the value as a string.
	/// </summary>

	public string AsString() { return ObjectToString(mValue); }

	/// <summary>
	/// Returns the value as a single-precision float.
	/// </summary>

	public float AsFloat()
	{
		if (mValue != null)
		{
			if (mValue is float) return (float)mValue;
			if (mValue is int) return (float)(int)mValue;

			if (mValue is float[])
			{
				float[] data = (float[])mValue;
				if (data.Length > 0) return data[0];
			}

			if (mValue is int[])
			{
				int[] data = (int[])mValue;
				if (data.Length > 0) return (float)data[0];
			}
		}
		return 0.0f;
	}

	/// <summary>
	/// Returns the value as an integer.
	/// </summary>

	public int AsInt()
	{
		if (mValue != null)
		{
			if (mValue is int) return (int)mValue;
			if (mValue is float) return (int)(float)mValue;

			if (mValue is int[])
			{
				int[] data = (int[])mValue;
				if (data.Length > 0) return data[0];
			}

			if (mValue is float[])
			{
				float[] data = (float[])mValue;
				if (data.Length > 0) return (int)data[0];
			}
		}
		return 0;
	}

	/// <summary>
	/// Returns the value as a a boolean.
	/// </summary>

	public bool AsBool()
	{
		if (mValue != null)
		{
			if (mValue is bool) return (bool)mValue;
			if (mValue is int) return (int)mValue != 0;
		}
		return false;
	}

	/// <summary>
	/// Returns the value as a Vector2
	/// </summary>

	public Vector2 AsVector2()
	{
		Vector2 v = Vector2.zero;

		if (mValue != null)
		{
			if (mValue is float[])
			{
				float[] fv = (float[])mValue;

				if (fv.Length > 1)
				{
					v.x = fv[0];
					v.y = fv[1];
				}
			}
			else if (mValue is int[])
			{
				int[] iv = (int[])mValue;

				if (iv.Length > 1)
				{
					v.x = iv[0];
					v.y = iv[1];
				}
			}
		}
		return v;
	}

	/// <summary>
	/// Returns the value as a Vector3
	/// </summary>

	public Vector3 AsVector3()
	{
		Vector3 v = Vector3.zero;

		if (mValue != null)
		{
			if (mValue is float[])
			{
				float[] fv = (float[])mValue;

				if (fv.Length > 2)
				{
					v.x = fv[0];
					v.y = fv[1];
					v.z = fv[2];
				}
			}
			else if (mValue is int[])
			{
				int[] iv = (int[])mValue;

				if (iv.Length > 2)
				{
					v.x = iv[0];
					v.y = iv[1];
					v.z = iv[2];
				}
			}
		}
		return v;
	}

	/// <summary>
	/// Returns the value as a Vector4
	/// </summary>

	public Vector4 AsVector4()
	{
		Vector4 v = Vector4.zero;

		if (mValue != null)
		{
			if (mValue is float[])
			{
				float[] fv = (float[])mValue;

				if (fv.Length > 3)
				{
					v.x = fv[0];
					v.y = fv[1];
					v.z = fv[2];
					v.w = fv[3];
				}
			}
			else if (mValue is int[])
			{
				int[] iv = (int[])mValue;

				if (iv.Length > 3)
				{
					v.x = iv[0];
					v.y = iv[1];
					v.z = iv[2];
					v.w = iv[3];
				}
			}
		}
		return v;
	}

	/// <summary>
	/// Returns the value as a Quaternion
	/// </summary>

	public Quaternion AsQuaternion()
	{
		Quaternion v = Quaternion.identity;

		if (mValue != null)
		{
			if (mValue is float[])
			{
				float[] fv = (float[])mValue;

				if (fv.Length > 3)
				{
					v.x = fv[0];
					v.y = fv[1];
					v.z = fv[2];
					v.w = fv[3];
				}
				else if (fv.Length > 2)
				{
					float max = Mathf.Max(Mathf.Max(Mathf.Abs(fv[0]), Mathf.Abs(fv[1])), Mathf.Abs(fv[2]));

					if (max < 0.0001f)
					{
						// Zeroed Euler angle
						v = Quaternion.identity;
					}
					else if (max > 1.0001f)
					{
						// Euler angle
						v = Quaternion.Euler(fv[0], fv[1], fv[2]);
					}
					else
					{
						// Directional vector
						Vector3 dir = new Vector3(fv[0], fv[1], fv[2]);
						v = Quaternion.LookRotation(dir);
					}
				}
			}
			else if (mValue is int[])
			{
				int[] iv = (int[])mValue;

				if (iv.Length > 3)
				{
					v.x = iv[0];
					v.y = iv[1];
					v.z = iv[2];
					v.w = iv[3];
				}
				else if (iv.Length > 2)
				{
					Vector3 dir = new Vector3(iv[0], iv[1], iv[2]);
					v = Quaternion.LookRotation(dir);
				}
			}
		}
		return v;
	}

	/// <summary>
	/// Returns the value as Color
	/// </summary>

	public Color AsColor()
	{
		Color v = Color.white;

		if (mValue != null)
		{
			if (mValue is float[])
			{
				float[] fv = (float[])mValue;

				if (fv.Length > 3)
				{
					v.r = fv[0];
					v.g = fv[1];
					v.b = fv[2];
					v.a = fv[3];
				}
				else if (fv.Length > 2)
				{
					v.r = fv[0];
					v.g = fv[1];
					v.b = fv[2];
				}
			}
			else if (mValue is int[])
			{
				int[] iv = (int[])mValue;

				if (iv.Length > 3)
				{
					v.r = iv[0];
					v.g = iv[1];
					v.b = iv[2];
					v.a = iv[3];
				}
				else if (iv.Length > 2)
				{
					v.r = iv[0];
					v.g = iv[1];
					v.b = iv[2];
				}
			}
			else if (mValue is string)
			{
				string s = (string)mValue;

				// Hex representation
				if (s.Length > 2 && s[0] == '0' && s[1] == 'x')
				{
					if (s.Length > 7)
					{
						v.r = ((ReadHex(s[2]) << 4) | ReadHex(s[3])) / 255.0f;
						v.g = ((ReadHex(s[4]) << 4) | ReadHex(s[5])) / 255.0f;
						v.b = ((ReadHex(s[6]) << 4) | ReadHex(s[7])) / 255.0f;

						if (s.Length > 9)
						{
							v.a = ((ReadHex(s[8]) << 4) | ReadHex(s[9])) / 255.0f;
						}
					}
				}
			}
		}
		return v;
	}

	/// <summary>
	/// Returns the value as a Rect
	/// </summary>

	public Rect AsRect()
	{
		Rect v = new Rect();

		if (mValue != null)
		{
			if (mValue is float[])
			{
				float[] fv = (float[])mValue;

				if (fv.Length > 3)
				{
					v.x = fv[0];
					v.y = fv[1];
					v.width = fv[2];
					v.height = fv[3];
				}
			}
			else if (mValue is int[])
			{
				int[] iv = (int[])mValue;

				if (iv.Length > 3)
				{
					v.x = iv[0];
					v.y = iv[1];
					v.width = iv[2];
					v.height = iv[3];
				}
			}
		}
		return v;
	}
}
*/
