using UnityEngine;
using System;
using System.Collections.Generic;
using System.Text;
using System.Xml;
using System.IO;

/*
public class Vector2
{
    public Vector2(float tx, float ty)
    {
        x = tx;
        y = ty;
    }

    public float x;
    public float y;
}

public class Rect
{
    public Rect(float l, float t, float r, float b)
    {
        left = l;
        top = t;
        right = r;
        bottom = b;
    }
    public float left;
    public float top;
    public float right;
    public float bottom;
}
 * */

public class GTSpriteAtlasCocos2DMetadata
{
    // Metadata
    public int format;
    public string realTextureFileName;
    public Vector2 size;
    public string textureFileName;
}

public class GTSpriteAtlasCocos2DFrame
{
    /*
    <key>frame</key>
    <string>{{2,116},{108,36}}</string>
    <key>offset</key>
    <string>{-1,-3}</string>
    <key>rotated</key>
    <false/>
    <key>sourceColorRect</key>
    <string>{{0,7},{108,36}}</string>
    <key>sourceSize</key>
    <string>{110,44}</string>
     * */

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
    public bool Parse(XmlNode nodeFrame, GTSpriteAtlasCocos2DMetadata metaData)
    {
        if (null == nodeFrame)
            return false;

        XmlNodeList nodeList = nodeFrame.SelectNodes("key");
        foreach (XmlNode n in nodeList)
        {
            switch (n.InnerText)
            {
                case "frame":
                    {
                        mFrame = GTUtility.StringToRect(n.NextSibling.InnerText);
                        // Convert the original point from left-top(Texture Packer) to left-bottom(Unity)
                        mFrame.y = metaData.size.y - mFrame.y;
                    }
                    break;

                case "offset":
                    mOffset = GTUtility.StringToVector2(n.NextSibling.InnerText);
                    break;

                case "rotated":
                    mRotated = bool.Parse(n.NextSibling.Name);
                    break;

                case "sourceColorRect":
                    {
                        mSourceColorRect = GTUtility.StringToRect(n.NextSibling.InnerText);
                        // Convert the original point from left-top(Texture Packer) to left-bottom(Unity)
                        mSourceColorRect.y = metaData.size.y - mSourceColorRect.y;
                    }
                    break;

                case "sourceSize":
                    mSourceSize = GTUtility.StringToVector2(n.NextSibling.InnerText);
                    break;
            }
        }

        return true;
    }
}

public class GTSpriteAtlasCocos2D
{
    // Metadata
    GTSpriteAtlasCocos2DMetadata mMetadata = new GTSpriteAtlasCocos2DMetadata();    
    // Frames
    //Dictionary<string, GTSpriteAtlasCocos2DFrame> mFrames = new Dictionary<string, GTSpriteAtlasCocos2DFrame>();
    private List<GTSpriteAtlasCocos2DFrame> mFrames = new List<GTSpriteAtlasCocos2DFrame>();
    // Texture
    Texture2D mTexture = null;
        
    public Texture2D texture { get { return mTexture; } }

    public GTSpriteAtlasCocos2DFrame this[int index]
    {
        get { return mFrames[index]; }
    }
        
    public GTSpriteAtlasCocos2D()
    {
    }

    /// <summary>
    /// Parse frames
    /// </summary>
    /// <param name="nodeFrames"></param>
    /// <returns></returns>
    private bool ParseFramesData(XmlNode nodeFrames)
    {
        if (null == nodeFrames)
            return false;

        XmlNodeList nodeList = nodeFrames.NextSibling.SelectNodes("key");
        foreach (XmlNode n in nodeList)
        {
            GTSpriteAtlasCocos2DFrame newFrame = new GTSpriteAtlasCocos2DFrame();
            newFrame.Parse(n.NextSibling, mMetadata);

            int lastIndex = n.InnerText.LastIndexOf('.');
            string frameName = (lastIndex >= 0) ? n.InnerText.Substring(0, lastIndex) : n.InnerText;
            newFrame.name = frameName;
            mFrames.Add(newFrame);
        }

        return true;
    }

    /// <summary>
    /// Parse contents from metadata
    /// </summary>
    /// <param name="nodeMetadata"></param>
    /// <returns></returns>
    private bool ParseMetaData(XmlNode nodeMetadata)
    {
        if (null == nodeMetadata)
            return false;

        XmlNodeList nodeList = nodeMetadata.NextSibling.SelectNodes("key");
        foreach (XmlNode n in nodeList)
        {
            switch (n.InnerText)
            {
                case "format":
                    mMetadata.format = int.Parse(n.NextSibling.InnerText);
                    break;

                case "realTextureFileName":
                    mMetadata.realTextureFileName = n.NextSibling.InnerText;
                    break;

                case "size":
                    mMetadata.size = GTUtility.StringToVector2(n.NextSibling.InnerText);
                    break;

                case "textureFileName":
                    mMetadata.textureFileName = n.NextSibling.InnerText;
                    break;
            }
        }

        return true;
    }

    public bool Parse(string content)
    {
        // Parse XML content
        XmlDocument xd = new XmlDocument();
        xd.LoadXml(content);

        XmlNodeList xnl = xd.SelectNodes("plist/dict/key");
        // Parse metadata
        ParseMetaData(GetNodeByKey(xnl, "metadata"));
        // Parse frames
        ParseFramesData(GetNodeByKey(xnl, "frames"));

        xd = null;
        
        return true;
    }

    public bool Load(string fileName)
    {
        // Load xml
        TextAsset textAsset = Resources.Load(fileName, typeof(TextAsset)) as TextAsset;
        Parse(textAsset.text);
        // Load texture
        mTexture = Resources.Load(fileName, typeof(Texture2D)) as Texture2D;
        if (null == mTexture)
            return false;
        
        return true;
    }

    /// <summary>
    /// Get a XmlNode by its InnderText
    /// </summary>
    /// <param name="xnl"></param>
    /// <param name="key"></param>
    /// <returns></returns>
    private XmlNode GetNodeByKey(XmlNodeList xnl, string key)
    {
        foreach (XmlNode n in xnl)
        {
            if (n.InnerText == key)
                return n;
        }
        return null;
    }
}
