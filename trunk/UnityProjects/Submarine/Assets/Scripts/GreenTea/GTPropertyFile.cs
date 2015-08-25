using UnityEngine;
using System.Collections;

public class GTPropertyFile
{
    /// <summary>
    /// Load a *.property.txt file, returning GTTreeNode parsed
    /// </summary>
    /// <param name="propertyFileName"></param>
    /// <returns></returns>
    public static GTTreeNode Load(string propertyFileName)
    {
        if (null == propertyFileName)
            return null;

        // Load property.txt file
        TextAsset txtProperty = Resources.Load(propertyFileName, typeof(TextAsset)) as TextAsset;
        if (null == txtProperty)
        {
            Debug.LogError("GTPropertyFile: Failed to load property file: " + propertyFileName);
            return null;
        }

        return GTTreeNode.FromString(txtProperty.text);
    }

    // Tags
    // A
    public const string TagAnchor = "Anchor";
    public const string TagAnimation = "Animation";
    public const string TagAssetName = "AssetName";
    // C
    public const string TagChildren = "Children";
    // F
    public const string TagFPS = "FPS";
    public const string TagFrameCount = "FrameCount";
    public const string TagFrameSet = "FrameSet";
    // L
    public const string TagLayer = "Layer";
    // S
    public const string TagScale = "Scale";
    public const string TagScript = "Script";
    public const string TagSortingOrder = "SortingOrder";
    public const string TagSprite = "Sprite";
    public const string TagStartFrame = "StartFrame";
}
