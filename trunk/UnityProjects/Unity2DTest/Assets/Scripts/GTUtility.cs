using UnityEngine;
using System.Collections.Generic;

public class GTUtility
{
    /// <summary>
    /// Convert a string to Vector2
    /// </summary>
    /// <param name="s"></param>
    /// <returns></returns>
    public static Vector2 StringToVector2(string s)
    {
        string _s = s.Substring(1, s.Length - 2);
        string[] sa = _s.Split(',');
        return new Vector2(System.Convert.ToSingle(sa[0]), System.Convert.ToSingle(sa[1]));
    }

    /// <summary>
    /// Convert a string to Rect
    /// </summary>
    /// <param name="s"></param>
    /// <returns></returns>
    public static Rect StringToRect(string s)
    {
        string _s = s.Substring(1, s.Length - 2);
        string[] sa = _s.Split(new string[] { "},{" }, System.StringSplitOptions.None);
        Vector2 v1 = StringToVector2(sa[0] + "}");
        Vector2 v2 = StringToVector2("{" + sa[1]);
        return new Rect(v1.x, v1.y, v2.x, v2.y);
    }
}
