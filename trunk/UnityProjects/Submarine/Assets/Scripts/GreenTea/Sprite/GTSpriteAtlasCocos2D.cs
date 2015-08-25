using UnityEngine;
using System;
using System.Collections.Generic;
using System.Xml;

/// <summary>
/// Stores metadata of cocos2d sprite atlas
/// </summary>
public class GTSpriteAtlasCocos2DMetadata
{
    // Metadata
    public int format;
    public string realTextureFileName;
    public Vector2 size;
    public string textureFileName;
}

/// <summary>
/// Stores a frame of cocos2d sprite atlas
/// </summary>
public class GTSpriteAtlasCocos2DFrame
{
    private string mName;
    private Rect mFrame;
    private Vector2 mOffset;
    private bool mRotated;
    private Rect mSourceColorRect;
    private Vector2 mSourceSize;

    public string name
    {
        get { return mName; }
        set { mName = value; }
    }
    public Rect frame
    {
        get { return mFrame; }
        set { mFrame = value; }
    }
    public Vector2 offset { get { return mOffset; } }
    public bool rotated { get { return mRotated; } }
    public Rect sourceColorRect { get { return mSourceColorRect; } }
    public Vector2 sourceSize { get { return mSourceSize; } }
    
    /// <summary>
    /// Parse a frame
    /// </summary>
    /// <param name="nodeFrame"></param>
    /// <returns></returns>
    public bool Parse(XmlNode nodeFrame, ref GTSpriteAtlasCocos2DMetadata metaData)
    {
        if (null == nodeFrame)
            return false;

        XmlNodeList nodeList = nodeFrame.SelectNodes("key");
        foreach (XmlNode n in nodeList)
        {
            switch (n.InnerText)
            {
                case "frame":
                    mFrame = GTSpriteAtlasCocos2D.StringToRect(n.NextSibling.InnerText);                        
                    break;

                case "offset":
                    mOffset = GTSpriteAtlasCocos2D.StringToVector2(n.NextSibling.InnerText);
                    break;

                case "rotated":
                    mRotated = bool.Parse(n.NextSibling.Name);
                    break;

                case "sourceColorRect":
                    mSourceColorRect = GTSpriteAtlasCocos2D.StringToRect(n.NextSibling.InnerText);
                    break;

                case "sourceSize":
                    mSourceSize = GTSpriteAtlasCocos2D.StringToVector2(n.NextSibling.InnerText);
                    break;
            }
        }

        // Convert the original point from left-top(Texture Packer) to left-bottom(Unity)
        mFrame.y = metaData.size.y - mFrame.y - mFrame.height;

        return true;
    }
}

/// <summary>
/// This class parses cocos2d atlas format = 2
/// </summary>
public class GTSpriteAtlasCocos2D : GTAsset
{    
    // Metadata
    private GTSpriteAtlasCocos2DMetadata mMetadata = new GTSpriteAtlasCocos2DMetadata();
    // Frames
    private GTSpriteAtlasCocos2DFrame[] mFrames = null;
    // Texture
    private Texture2D mTexture = null;
    public Texture2D texture { get { return mTexture; } }

    public GTSpriteAtlasCocos2DFrame this[int index]
    {
        get { return mFrames[index]; }
    }
    public int frameCount { get { return mFrames.Length; } }
        
    public GTSpriteAtlasCocos2D()
    {
    }
    
    //----------------------------------------------
    // Static methods
    //----------------------------------------------

    /// <summary>
    /// Load cocos2d atlas
    /// </summary>
    /// <param name="fileName">"Resources/Sprite/sprite1"</param>
    /// <returns></returns>
    static public GTSpriteAtlasCocos2D Create(string fileName)
    {
        // Check if this asset is loaded already
        if (GTAssetManager.Instance.AssetExists(fileName))
            return GTAssetManager.Instance.GetAsset<GTSpriteAtlasCocos2D>(fileName);

        // Load atlas xml(plist)
        TextAsset textAsset = Resources.Load(fileName, typeof(TextAsset)) as TextAsset;
        GTSpriteAtlasCocos2D spriteAtlas = GTSpriteAtlasCocos2D.Parse(textAsset.text);
        if (null == spriteAtlas)
        {
            Debug.LogError("Failed to load cocos2d sprite atlas xml(plist): " + fileName);
            return null;
        }
        // Load texture
        spriteAtlas.mTexture = Resources.Load(fileName, typeof(Texture2D)) as Texture2D;
        if (null == spriteAtlas.mTexture)
        {
            Debug.LogError("Failed to load cocos2d sprite atlas texture: " + fileName);
            return null;
        }

        // Cache this asset
        GTAssetManager.Instance.AddAsset(fileName, spriteAtlas);

        return spriteAtlas;
    }

    /// <summary>
    /// Parse frames
    /// </summary>
    /// <param name="nodeFrames"></param>
    /// <returns></returns>
    static private bool ParseFramesData(XmlNode nodeFrames, ref GTSpriteAtlasCocos2D spriteAtlas)
    {
        if (null == nodeFrames)
            return false;

        // Query all frames
        XmlNodeList nodeList = nodeFrames.NextSibling.SelectNodes("key");
        if (nodeList.Count == 0)
            return false;

        spriteAtlas.mFrames = new GTSpriteAtlasCocos2DFrame[nodeList.Count];
        if (null == spriteAtlas.mFrames)
            return false;

        // Parse each frame node
        for (int index = 0; index < nodeList.Count; index++)
        {
            XmlNode n = nodeList[index];
            GTSpriteAtlasCocos2DFrame newFrame = new GTSpriteAtlasCocos2DFrame();
            // Parse metadata
            newFrame.Parse(n.NextSibling, ref spriteAtlas.mMetadata);
            // Remove ".png" from frame name
            int lastIndex = n.InnerText.LastIndexOf('.');
            string frameName = (lastIndex >= 0) ? n.InnerText.Substring(0, lastIndex) : n.InnerText;
            newFrame.name = frameName;
            // Add the frame into the array
            spriteAtlas.mFrames[index] = newFrame;
        }

        return true;
    }

    /// <summary>
    /// Parse contents from metadata
    /// </summary>
    /// <param name="nodeMetadata"></param>
    /// <returns></returns>
    static private bool ParseMetaData(XmlNode nodeMetadata, ref GTSpriteAtlasCocos2D spriteAtlas)
    {
        if (null == nodeMetadata)
            return false;

        XmlNodeList nodeList = nodeMetadata.NextSibling.SelectNodes("key");
        foreach (XmlNode n in nodeList)
        {
            switch (n.InnerText)
            {
                case "format":
                    spriteAtlas.mMetadata.format = int.Parse(n.NextSibling.InnerText);
                    break;

                case "realTextureFileName":
                    spriteAtlas.mMetadata.realTextureFileName = n.NextSibling.InnerText;
                    break;

                case "size":
                    spriteAtlas.mMetadata.size = GTSpriteAtlasCocos2D.StringToVector2(n.NextSibling.InnerText);
                    break;

                case "textureFileName":
                    spriteAtlas.mMetadata.textureFileName = n.NextSibling.InnerText;
                    break;
            }
        }

        return true;
    }

    /// <summary>
    /// Parse atlas content
    /// </summary>
    /// <param name="content"></param>
    /// <returns></returns>
    static private GTSpriteAtlasCocos2D Parse(string content)
    {
        // Parse XML content
        XmlDocument xd = new XmlDocument();
        xd.LoadXml(content);

        GTSpriteAtlasCocos2D spriteAtlas = new GTSpriteAtlasCocos2D();

        XmlNodeList xnl = xd.SelectNodes("plist/dict/key");
        // Parse metadata
        GTSpriteAtlasCocos2D.ParseMetaData(GetNodeByKey(xnl, "metadata"), ref spriteAtlas);
        // Parse frames
        GTSpriteAtlasCocos2D.ParseFramesData(GetNodeByKey(xnl, "frames"), ref spriteAtlas);

        xd = null;

        return spriteAtlas;
    }

    /// <summary>
    /// Get a XmlNode by its InnderText
    /// </summary>
    /// <param name="xnl"></param>
    /// <param name="key"></param>
    /// <returns></returns>
    static private XmlNode GetNodeByKey(XmlNodeList xnl, string key)
    {
        foreach (XmlNode n in xnl)
        {
            if (n.InnerText == key)
                return n;
        }
        return null;
    }

    /// <summary>
    /// Convert a string to Vector2
    /// </summary>
    /// <param name="s"></param>
    /// <returns></returns>
    static public Vector2 StringToVector2(string s)
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
    static public Rect StringToRect(string s)
    {
        string _s = s.Substring(1, s.Length - 2);
        string[] sa = _s.Split(new string[] { "},{" }, System.StringSplitOptions.None);
        Vector2 v1 = StringToVector2(sa[0] + "}");
        Vector2 v2 = StringToVector2("{" + sa[1]);
        return new Rect(v1.x, v1.y, v2.x, v2.y);
    }
}
