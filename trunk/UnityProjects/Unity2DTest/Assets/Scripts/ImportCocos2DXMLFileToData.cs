using System.Xml;
using System.Collections.Generic;
using UnityEngine;
using System.IO;

/// <summary>
/// Use XML to import atlas cocos2D XML file to data(Frames);
/// </summary>
public class ImportCocos2DXMLFileToData
{
    protected Texture2D mTexture;
    protected TextAsset mTextAsset = null;
    /*
    public ImportCocos2DXMLFileToData(Texture texture, TextAsset atlasDataFile)
    {
        mTexture = texture;
        mTextAsset = atlasDataFile;
    }
    */
    public ImportCocos2DXMLFileToData(string textureFilename, string atlasfileName)
    {
        mTexture = Tools.LoadTextureFile(textureFilename);
        mTextAsset = Tools.LoadTextFile(atlasfileName);
    }

    public ImportCocos2DXMLFileToData(string filename)
    {
        mTexture = Tools.LoadTextureFile(filename);
        mTextAsset = Tools.LoadTextFile(filename);
    }

    public Texture2D GetTexture()
    {
        return mTexture;
    }

    public Texture2D texture
    {
        get
        {
            return mTexture;
        }
    }

    public FrameData[] GetFrames()
    {
        FrameData[] frames = AtlasDataToFrames.GetFrames(GetData(), mTexture);
        return frames;
    }

    protected AtlasData[] GetData()
    {
        if (mTextAsset == null)
        {
            Debug.LogError(" mTextAsset is null!!! Please check ");
            return null;
        }
        AtlasData[] atlasData = Import();
        return atlasData;
    }
    /*
    protected virtual void LocateAtlasData()
    {
#if UNITY_EDITOR
        string path = Path.GetDirectoryName(UnityEditor.AssetDatabase.GetAssetPath(mTexture)) + "/" + mTexture.name + ".xml";
        Object o = (UnityEditor.AssetDatabase.LoadAssetAtPath(path, typeof(TextAsset)));
        if (o is TextAsset)
            mTextAsset = (o as TextAsset);
#else        

        mTextAsset = Resources.Load(mTexture.name) as TextAsset;

        if (mTextAsset == null)
        {
            Debug.LogError(" Can not load txt asset: " + mTexture
        }

#endif
    }
    */

    protected XmlDocument xml = new XmlDocument();
    /// <summary>
    /// Check if xml provided is valid
    /// </summary>
    /// <returns>Array with atlas frame data</returns>
    protected bool ValidXML()
    {
        try
        {
            xml.LoadXml(mTextAsset.text);
            return true;
        }
        catch (System.Exception err)
        {
            Debug.LogError("Error : Atlas XML file could not be read!");
            Debug.LogError(err.Message);
        }
        return false;
    }

    /// <summary>
    /// Import atlasData from sparrow xml
    /// </summary>
    protected AtlasData[] Import()
    {
        if (!ValidXML())
            return new AtlasData[] { };

        List<AtlasData> data = new List<AtlasData>();
        if (xml.DocumentElement.Name == "plist")
        {
            XmlNode frames = xml.DocumentElement.SelectSingleNode("dict/key");
            if (frames != null && frames.InnerText == "frames")
            {
                XmlNodeList subTextureNames = xml.DocumentElement.SelectNodes("dict/dict/key");
                XmlNodeList subTextures = xml.DocumentElement.SelectNodes("dict/dict/dict");
                try
                {
                    for (int si = 0; si < subTextures.Count; si++)
                    {
                        subTexture = subTextures[si];
                        AtlasData ad = new AtlasData();

                        bool rotated = GetBool("rotated");
                        Rect frame = GetRect("frame");
                        Rect colorRect = GetRect("sourceColorRect");
                        Vector2 sourceSize = GetVector2("sourceSize");
                        try
                        {
                            ad.name = subTextureNames[si].InnerText.Split('.')[0];
                        }
                        catch (System.Exception)
                        {
                            ad.name = subTextureNames[si].InnerText;
                        }
                        ad.position = new Vector2(frame.xMin, frame.yMin);
                        if (rotated)
                            ad.rotated = true;

                        ad.size = new Vector2(colorRect.width, colorRect.height);
                        ad.frameSize = sourceSize;
                        ad.offset = new Vector2(colorRect.xMin, colorRect.yMin);

                        data.Add(ad);
                    }
                }
                catch (System.Exception ERR)
                {
                    Debug.LogError("Orthello : Cocos2D Atlas Import error!");
                    Debug.LogError(ERR.Message);
                }
            }
        }
        return data.ToArray();
    }

    protected string AttrS(XmlNode node, string field)
    {
        try
        {
            return node.Attributes[field].InnerText;
        }
        catch (System.Exception)
        {
            return "";
        }
    }

    protected int AttrI(XmlNode node, string field)
    {
        try
        {
            return System.Convert.ToInt16(node.Attributes[field].InnerText);
        }
        catch (System.Exception)
        {
            return -1;
        }
    }

    XmlNode subTexture = null;

    Vector2 StringToVector2(string s)
    {
        string _s = s.Substring(1, s.Length - 2);
        string[] sa = _s.Split(',');
        return new Vector2(System.Convert.ToSingle(sa[0]), System.Convert.ToSingle(sa[1]));
    }

    Rect StringToRect(string s)
    {
        string _s = s.Substring(1, s.Length - 2);
        string[] sa = _s.Split(new string[] { "},{" }, System.StringSplitOptions.None);
        Vector2 v1 = StringToVector2(sa[0] + "}");
        Vector2 v2 = StringToVector2("{" + sa[1]);
        return new Rect(v1.x, v1.y, v2.x, v2.y);
    }

    Rect GetRect(string name)
    {
        XmlNode nameNode = subTexture.SelectSingleNode("key[.='" + name + "']");
        if (nameNode != null)
        {
            XmlNode stringNode = nameNode.NextSibling;
            return StringToRect(stringNode.InnerText);
        }
        return new Rect(0, 0, 0, 0);
    }

    Vector2 GetVector2(string name)
    {
        XmlNode nameNode = subTexture.SelectSingleNode("key[.='" + name + "']");
        if (nameNode != null)
        {
            XmlNode stringNode = nameNode.NextSibling;
            return StringToVector2(stringNode.InnerText);
        }
        return Vector2.zero;
    }

    bool GetBool(string name)
    {
        XmlNode nameNode = subTexture.SelectSingleNode("key[.='" + name + "']");
        if (nameNode != null)
        {
            XmlNode boolNode = nameNode.NextSibling;
            return (boolNode.Name.ToLower() == "true");
        }
        return false;
    }

    class AtlasDataToFrames
    {
        public static FrameData[] GetFrames(AtlasData[] atlasData, Texture texture)
        {
            if ((atlasData == null) || (texture == null))
            {
                Debug.LogError(" can't find atlas data or texture, please check it!!");
                return new FrameData[] { };
            }

            Vector2 texSize = Vector2.zero;
            if (Vector2.Equals(texSize, Vector2.zero) && texture != null)
                texSize = new Vector2(texture.width, texture.height);

            // convert atlasData to frames
            FrameData[] frames = new FrameData[atlasData.Length];

            for (int a = 0; a < atlasData.Length; a++)
            {
                AtlasData data = atlasData[a];
                FrameData frame = new FrameData();
                frame.name = data.name;
                frame.offset = Vector2.zero;
                frame.size = data.frameSize;

                Vector2 vOffset = new Vector2(data.offset.x / frame.size.x, data.offset.y / frame.size.y);
                Vector2 vSize = new Vector2(data.size.x / frame.size.x, data.size.y / frame.size.y);

                Vector3 tl = new Vector3(((1f / 2f) * -1) + vOffset.x, (1f / 2f) - vOffset.y, 0);
                frame.vertices = new Vector3[] { 
                    tl,
                    tl + new Vector3(vSize.x,0,0),
                    tl + new Vector3(vSize.x,vSize.y * -1,0),
                    tl + new Vector3(0,vSize.y * -1,0)
                };

                frame.imageSize = data.frameSize;

                frame.uv = new Vector2[4];
                float sx = data.position.x / texSize.x;
                float sy = 1 - ((data.position.y + data.size.y) / texSize.y);
                float scx = data.size.x / texSize.x;
                float scy = data.size.y / texSize.y;
                if (data.rotated)
                {
                    sy = 1 - ((data.position.y + data.size.x) / texSize.y);
                    scx = data.size.y / texSize.x;
                    scy = data.size.x / texSize.y;
                    frame.uv[3] = new Vector2(sx, sy + scy);
                    frame.uv[0] = new Vector2(sx + scx, sy + scy);
                    frame.uv[1] = new Vector2(sx + scx, sy);
                    frame.uv[2] = new Vector2(sx, sy);
                }
                else
                {
                    frame.uv[0] = new Vector2(sx, sy + scy);
                    frame.uv[1] = new Vector2(sx + scx, sy + scy);
                    frame.uv[2] = new Vector2(sx + scx, sy);
                    frame.uv[3] = new Vector2(sx, sy);
                }
                frames[a] = frame;
            }
            return frames;
        }
    }
}
