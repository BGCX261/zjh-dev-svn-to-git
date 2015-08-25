using UnityEngine;
using System.Collections;

public class GTUISkin
{
    public GTSpriteAtlasCocos2D mAtlasSheet = null;
    public GTSpriteFrameSet mFrameSet = null;

    public GTUISkin()
    {
    }

    /// <summary>
    /// Load a skin by name
    /// </summary>
    /// <param name="fileName"></param>
    /// <returns></returns>
    public static GTUISkin Create(string fileName)
    {
        GTUISkin skin = new GTUISkin();
        skin.mAtlasSheet = GTSpriteAtlasCocos2D.Create(fileName);
        if (skin.mAtlasSheet == null)
        {
            Debug.LogError("Failed to load skin file: " + fileName);
            return null;
        }
        skin.mFrameSet = new GTSpriteFrameSet();
        if (!skin.mFrameSet.Create(skin.mAtlasSheet, 0, skin.mAtlasSheet.frameCount, GTSpriteFrameSet.PivotCenter))
        {
            Debug.LogError("Failed to create frameset: " + fileName);
            return null;
        }

        return skin;
    }
}
