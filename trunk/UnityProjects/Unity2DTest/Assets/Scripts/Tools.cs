using System;
using System.Collections.Generic;
using System.Linq;
using UnityEngine;

public class Tools
{
    /// <summary>
    /// Load texture;
    /// /// Rename image file,  for unity, there is a bug, if png and xml are same names in the folder, Resources.Load() will have a error! 
    /// Thus, need change one name. Then, I add extra characters for all png file
    /// </summary>
    public static Texture2D LoadTextureFile(string textureFileName)
    {
        /// In unity, there is a bug, if png and xml are same names in the folder, Resources.Load() will have a error! 
        /// Thus, need change one name. Then, I add extra characters for all png file
        Texture2D texture = Resources.Load(textureFileName, typeof(Texture2D)) as Texture2D;

        if (texture == null)
        {
            Debug.LogError("  Error!!!!!  failt to Load texture:  " + textureFileName);
        }

        return texture;
    }

    //load atlas file;
    //Unity have a bug:
    //Resources.Load(mFileName) as TextAsset 
    //sometime, some files with extension can't be load. ----> Solution: change file extension to 
    //for example:  (*.xml) -> (.txt); or (.txt) ---> (*.xml) 
    public static TextAsset LoadTextFile(string textFileName)
    {
        TextAsset bindata = null;
        bindata = Resources.Load(textFileName, typeof(TextAsset)) as TextAsset;

        if (bindata == null)
        {
            Debug.LogError("  Error!!!!!  failt to Load Text file: " + textFileName);
        }
        return bindata;
    }



    public static string UVToString(Vector2[] uv)
    {
        string str = "uv[3] = " + uv[3] + "uv[0] = " + uv[0] + "uv[1] = " + uv[1] + "uv[2] = " + uv[2];
        return str;
    }
}