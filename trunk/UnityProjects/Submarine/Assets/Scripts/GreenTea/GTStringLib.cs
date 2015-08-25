using System;
using System.Text.RegularExpressions;
using UnityEngine;

public class GTStringLib
{
	// Split the string on this if no splitter is provided.
	private const string cDefaultSplitter = ",";

	/// <summary>
	/// Convert a string to int.
	/// </summary>
	/// <param name="input">The string containing a int.</param>
	/// <returns>The string as a int or zero.</returns>

	public static int ToInt(string input)
	{
		int result;
		if (!int.TryParse(input, out result))
		{
			Debug.LogError("Unable to parse " + input + " in ToInt");
			return 0;
		}

		return result;
	}

    /// <summary>
    /// Convert a string to long.
    /// </summary>
    /// <param name="input">The string containing a long.</param>
    /// <returns>The string as a long or zero.</returns>

    public static long ToLong(string input)
    {
        long result;
        if (!long.TryParse(input, out result))
        {
            Debug.LogError("Unable to parse " + input + " in ToInt");
            return 0;
        }

        return result;
    }

	/// <summary>
	/// Convert a string to float.
	/// </summary>
	/// <param name="input">The string containing a float.</param>
	/// <returns>The string as a float or zero.</returns>

	public static float ToFloat(string input)
	{
		float result;
		if (!float.TryParse(input, out result))
		{
			Debug.LogError("Unable to parse " + input + " in ToFloat");
			return 0f;
		}

		return result;
	}

	/// <summary>
	/// Return a Vector2 from a comma delimited string.
	/// </summary>
	/// <param name="str">The string to parse.</param>
	/// <returns>The Vector2 from the string or Vector2.zero</returns>

	public static Vector2 ToVector2(string str)
	{
		return ToVector2(str, cDefaultSplitter);
	}

	/// <summary>
	/// Return a Vector2 from a comma delimited string.
	/// </summary>
	/// <param name="str">The string to parse.</param>
	/// <param name="splitOnThis">Split the string on this character.</param>
	/// <returns>The Vector2 from the string or Vector2.zero</returns>

	public static Vector2 ToVector2(string str, string splitOnThis)
	{
		if (null == str)
		{
			Debug.LogError("Passed null to ToVector2");
			return Vector2.zero;
		}

		string[] splitString = Regex.Split(str, splitOnThis);
		if (splitString.Length != 2)
		{
			Debug.LogError("Unable to split string into ToVector2 " + str);
			return Vector2.zero;
		}

		// TODO: use better float parser
		return new Vector2(ToFloat(splitString[0]), ToFloat(splitString[1]));
	}


	/// <summary>
	/// Return a Vector3 from a comma delimited string.
	/// </summary>
	/// <param name="str">The string to parse.</param>
	/// <returns>The Vector3 from the string or Vector3.zero</returns>

	public static Vector3 ToVector3(string str)
	{
		return ToVector3(str, cDefaultSplitter);
	}

	/// <summary>
	/// Return a Vector3 from a comma delimited string.
	/// </summary>
	/// <param name="str">The string to parse.</param>
	/// <param name="splitOnThis">Split the string on this character.</param>
	/// <returns>The Vector3 from the string or Vector3.zero</returns>

	public static Vector3 ToVector3(string str, string splitOnThis)
	{
		if (null == str)
		{
			Debug.LogError("Passed null to ToVector3");
			return Vector3.zero;
		}

		string[] splitString = Regex.Split(str, splitOnThis);
		if (splitString.Length != 3)
		{
			Debug.LogError("Unable to split string '" + str + "' into Vector3 ");
			return Vector3.zero;
		}

		// TODO: use better float parser
		return new Vector3(ToFloat(splitString[0]), ToFloat(splitString[1]), ToFloat(splitString[2]));
	}

	/// <summary>
	/// Return a Vector4 from a comma delimited string.
	/// </summary>
	/// <param name="str">The string to parse.</param>
	/// <returns>The Vector4 from the string or Vector4.zero</returns>

	public static Vector4 ToVector4(string str)
	{
		return ToVector4(str, cDefaultSplitter);
	}

	/// <summary>
	/// Return a Vector4 from a comma delimited string.
	/// </summary>
	/// <param name="str">The string to parse.</param>
	/// <param name="splitOnThis">Split the string on this character.</param>
	/// <returns>The Vector4 from the string or Vector4.zero</returns>

	public static Vector4 ToVector4(string str, string splitOnThis)
	{
		if (null == str)
		{
			Debug.LogError("Passed null to ToVector4");
			return Vector4.zero;
		}

		string[] splitString = Regex.Split(str, splitOnThis);
		if (splitString.Length != 4)
		{
			Debug.LogError("Unable to split string into ToVector4 " + str);
			return Vector4.zero;
		}

		// TODO: use better float parser
		return new Vector4(ToFloat(splitString[0]), ToFloat(splitString[1]), ToFloat(splitString[2]), ToFloat(splitString[3]));
	}

	/// <summary>
	/// Return a Vector3 from a comma delimited string.
	/// </summary>
	/// <param name="str">The string to parse.</param>
	/// <returns>The Vector3 from the string or Vector3.zero</returns>

	public static Color ToColor(string str)
	{
		return ToColor(str, cDefaultSplitter);
	}

	/// <summary>
	/// Return a Vector3 from a comma delimited string.
	/// </summary>
	/// <param name="str">The string to parse.</param>
	/// <param name="splitOnThis">Split the string on this character.</param>
	/// <returns>The Vector3 from the string or Vector3.zero</returns>

	public static Color ToColor(string str, string splitOnThis)
	{
		if (null == str)
		{
			Debug.LogError("Passed null to ToColor");
			return Color.white;
		}

		string[] splitString = Regex.Split(str, splitOnThis);
		if (splitString.Length == 3)
		{
			// TODO: use better float parser
			return new Color(ToFloat(splitString[0]), ToFloat(splitString[1]), ToFloat(splitString[2]));

		}
		else if (splitString.Length == 4)
		{
			// TODO: use better float parser
			return new Color(ToFloat(splitString[0]), ToFloat(splitString[1]), ToFloat(splitString[2]), ToFloat(splitString[3]));

		}
		else
		{
			Debug.LogError("Unable to split string into ToColor " + str);
			return Color.white;
		}
	}

	/// <summary>
	/// Convert a string to an enum.
	/// </summary>
	/// <param name="str">The string to convert.</param>
	/// <param name="enumType">The type of enum to convert the string to.</param>
	/// <returns>Returns the enum (as an object) if successful, null otherwise.</returns>

	public static object ToEnum(string str, System.Type enumType)
	{
		if (null == str || null == enumType)
		{
			Debug.LogError("Passed null to StringLib ToEnum");
			return null;
		}

		try
		{
			return Enum.Parse(enumType, str);
		}
		catch (Exception e)
		{
			Debug.LogError("Unable to convert " + str + " to " + enumType + " in StringLib ToEnum " + e.Message);
			return null;
		}
	}

	/// <summary>
	/// Return a string array from a comma delimited string.
	/// </summary>
	/// <param name="str">The string to parse.</param>
	/// <returns>The Vector3 from the string or Vector3.zero</returns>

	public static string[] ToStringArray(string str)
	{
		return ToStringArray(str, cDefaultSplitter);
	}

	/// <summary>
	/// Return a string array from a splitOnThis delimited string.
	/// </summary>
	/// <param name="str">The string to parse.</param>
	/// <param name="splitOnThis">Split the string on this string pattern.</param>
	/// <returns>The an array of strings or null.</returns>

	public static string[] ToStringArray(string str, string splitOnThis)
	{
		if (null == str)
		{
			Debug.LogError("Passed null to ToStringArray");
			return null;
		}

		return Regex.Split(str, splitOnThis);
	}

	/// <summary>
	/// Return a Vector3 array from a comma delimited string.
	/// </summary>
	/// <param name="str">The string to parse.</param>
	/// <returns>An array of Vector3 or null. </returns>

	public static Vector3[] ToVector3Array(string str)
	{
		return ToVector3Array(str, cDefaultSplitter);
	}

	/// <summary>
	/// Return a Vector3 array from a comma delimited string.
	/// </summary>
	/// <param name="str">The string to parse.</param>
	/// <param name="spiltOnThis">Split the string on this string pattern.</param>
	/// <returns>An array of Vector3 or null. </returns>

	public static Vector3[] ToVector3Array(string str, string spiltOnThis)
	{
		return ToVector3Array(ToStringArray(str, spiltOnThis));
	}

	/// <summary>
	/// Return a Vector3 array from a comma delimited string.
	/// </summary>
	/// <param name="stringArray">The string to parse.</param>
	/// <returns>An array of Vector3 or null</returns>

	public static Vector3[] ToVector3Array(string[] stringArray)
	{
		if (null == stringArray)
		{
			Debug.LogError("Passed null to ToVector3Array");
			return null;
		}

		Vector3[] vectorArray = new Vector3[stringArray.Length];
		for (int i = 0; i < stringArray.Length; i++)
		{
			vectorArray[i] = ToVector3(stringArray[i]);
		}

		return vectorArray;
	}

	/// <summary>
	/// Get the number of characters of type pattern in input string.
	/// </summary>
	/// <param name="input">The string containing the pattern.</param>
	/// <param name="pattern">The pattern to look for.</param>
	/// <returns>The number of times the pattern is found in the input.</returns>

	public static int NumCharactersInString(string input, string pattern)
	{
		if (null == input || null == pattern)
		{
			Debug.LogError("Passed null to NumCharactersInString");
			return 0;
		}

		return Regex.Matches(input, pattern, RegexOptions.IgnoreCase).Count;
	}

	/// <summary>
	/// Convert the any newline characters in the string to actual newlines.
	/// </summary>
	/// <param name="input">The line containing the newlines</param>
	/// <returns>A new string containing newline characters out of the input string.</returns>

	public static string ConvertNewLineCharacters(string input)
	{
		if (null == input)
		{
			Debug.LogError("Passed null to ConvertNewLineCharacters");
			return null;
		}

		return input.Replace("\\n", "\n");
	}

	/// <summary>
	/// Remove the last character from a string.
	/// </summary>
	/// <param name="input">The string to remove the last character from.</param>
	/// <returns>The input string without the last character.</returns>

	public static string RemoveLastCharacterFromString(string input)
	{
		if (string.IsNullOrEmpty(input))
		{
			Debug.LogError("Passed null to RemoveLastCharacterFromString");
			return null;
		}

		return input.Substring(0, input.Length - 1);
	}
	
	/// <summary>
	/// Get a number from a string (NOTE: only returns the first number range in the string).
	/// </summary>
	/// <param name="str">The string to get the number from.</param>
	/// <returns>The number value of the string.</returns>

	public static string GetNumberFromString(string str)
	{
		if (null == str)
		{
			Debug.LogError("Passed null to GetNumberFromString");
			return null;
		}

		str = str.Trim();
		Match m = Regex.Match(str, @"[0-9]+");
		return (m.Value);
	}

	/// <summary>
	/// Parses Quaternion from string (from server).
	/// </summary>
	/// <param name="quaternion">String in a format "123, 456, 789, 345".</param>
	/// <returns>Quaternion object created from a parsed string or Quaternion.identity.</returns>
	public static Quaternion ParseQuaternion(string quaternion)
	{
		if (string.IsNullOrEmpty(quaternion))
		{
			// For now we will assume a null rotation is no rotation.
			//Debug.LogError("Passed null to StringLib ParseQuaternion");
			return Quaternion.identity;
		}

		try
		{
			string[] xyzw;
			quaternion = quaternion.Replace("(", "");
			quaternion = quaternion.Replace(")", "");

			if (quaternion.Contains(","))
			{
				xyzw = quaternion.Split(',');
			}
			else if (quaternion.Contains(";"))
			{
				xyzw = quaternion.Split(';');
			}
			else
			{
				xyzw = quaternion.Split(' ');
			}
			return new Quaternion(
				float.Parse(xyzw[0].Trim()),
				float.Parse(xyzw[1].Trim()),
				float.Parse(xyzw[2].Trim()),
				float.Parse(xyzw[3].Trim()));
		}
		catch (Exception ex)
		{
			Debug.LogError("Error parsing rotation in StringLib ParseQuaternion " + quaternion + "," + ex.Message);
			return Quaternion.identity;
		}
	}

}