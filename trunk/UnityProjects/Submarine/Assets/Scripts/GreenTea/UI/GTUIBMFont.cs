using UnityEngine;
using System.Collections;
using System.Collections.Generic;

public class GTUIBMFont : GTUIFont
{
    public BMFont mBMFont = null;
    
    public GTUIBMFont()
    {
    }

    /// <summary>
    /// Load BMFont file
    /// </summary>
    /// <param name="path">Path</param>
    /// <param name="fileName">Font file name</param>
    /// <returns></returns>
    public static GTUIBMFont Create(string path, string fileName)
    {
        string fontPath = string.Format("{0}/{1}", path, fileName);
        TextAsset textAsset = GTUtility.LoadResourceTextAsset(fontPath);
        if (textAsset == null)
        {
            Debug.LogError("GTUIBMFont.Load: Failed to load BMFont TextAsset file: " + fileName);
            return null;
        }

        GTUIBMFont bmf = new GTUIBMFont();
        bmf.mBMFont = BMFontLoader.LoadFontFromXmlFile(textAsset.text);
        if (bmf.mBMFont == null)
        {
            Debug.LogError("GTUIBMFont.Load: Failed to parse BMFont file: " + fileName);
            return null;
        }
        // Save the name
        bmf.name = fontPath;

        // Load texture
        if (bmf.mBMFont.Pages.Length == 0)
        {
            bmf = null;
            Debug.LogError(string.Format("GTUIBMFont.Load: BMFont {0} doesn't have pages !", fileName));
            return null;
        }
        // Always load first page, not supporting multiple-pages
        BMFontPage bmfPage = bmf.mBMFont.Pages[0];
        // Remove .png: arial-16-bold.png => arial-16-bold
        int lastDotIndex = bmfPage.FileName.LastIndexOf('.');
        string textureFileName = (lastDotIndex > 0) ? bmfPage.FileName.Substring(0, lastDotIndex) : bmfPage.FileName;
        string fontTexturePath = string.Format("{0}/{1}", path, textureFileName);
        // Load texture
        bmf.texture = GTUtility.LoadResourceTextureAsset(fontTexturePath);
        if (bmf.texture == null)
        {
            bmf = null;
            Debug.LogError("GTUIBMFont.Load: Failed to load BMFont texture: " + fileName);
            return null;
        }
        // Create sprites for characters
        foreach (KeyValuePair<char, BMFontCharacter> fc in bmf.mBMFont.Characters)
        {
            BMFontCharacter fcv = fc.Value;
            // Build character rectangle in texture
            Rect rectCharSprite = new Rect(
                fcv.Bounds.Left,
                bmf.mBMFont.TextureSize.Height - fcv.Bounds.Top - fcv.Bounds.Height, // Convert original to bottom-left from top-left
                fcv.Bounds.Width,
                fcv.Bounds.Height
                );
            // Build new sprite for character
            Sprite charSprite = Sprite.Create(
                bmf.texture,
                rectCharSprite,
                GTSpriteFrameSet.PivotLeftTop,
                GTSystemSetting.PixelsToUnits
                );
            bmf.mSpriteSet.Add(fcv.Char, charSprite);
        }

        return bmf;
    }
}
