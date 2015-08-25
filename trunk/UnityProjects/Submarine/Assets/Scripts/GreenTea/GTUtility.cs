using UnityEngine;
using System.Collections;

public class GTUtility
{
    /// <summary>
    /// Load TextAsset object that is under Resources folder
    /// </summary>
    /// <param name="fileName"></param>
    /// <returns></returns>
    public static TextAsset LoadResourceTextAsset(string fileName)
    {
        TextAsset textAsset = Resources.Load(fileName, typeof(TextAsset)) as TextAsset;
        if (textAsset == null)
        {
            Debug.LogError("LoadResourceTextAsset: Failed to load TextAsset: " + fileName);
            return null;
        }

        return textAsset;
    }

    /// <summary>
    /// Load Texture2D object that is under Resources folder
    /// </summary>
    /// <param name="fileName"></param>
    /// <returns></returns>
    public static Texture2D LoadResourceTextureAsset(string fileName)
    {
        Texture2D textureAsset = Resources.Load(fileName, typeof(Texture2D)) as Texture2D;
        if (textureAsset == null)
        {
            Debug.LogError("LoadResourceTextAsset: Failed to load Texture2D Asset: " + fileName);
            return null;
        }

        return textureAsset;
    }
}
