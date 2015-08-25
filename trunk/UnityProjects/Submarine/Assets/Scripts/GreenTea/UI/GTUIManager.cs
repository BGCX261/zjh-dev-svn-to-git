using UnityEngine;
using UnityEngine.UI;
using System.Collections;
using System.Collections.Generic;

public class GTUIManager
{
    // Tags defined in uilayout file
    public const string TagUILayout = "UILayout";
    public const string TagUICanvas = "UICanvas";
    public const string TagUIImage = "UIImage";
    public const string TagUIButton = "UIButton";
    public const string TagSkin = "Skin";
    public const string TagFont = "Font";
    public const string TagFontSize = "FontSize";
    public const string TagPosition = "Position";
    public const string TagSize = "Size";
    public const string TagVisible = "Visible";
    public const string TagEventType = "EventType";
    public const string TagChildren = "Children";
    public const string TagPieceEnabled = "PieceEnabled";
    public const string TagAnchorPoint = "AnchorPoint";
    public const string TagColor = "Color";
    public const string TagText = "Text";

    public static GTUIManager mInstance = new GTUIManager();
    public static GTUIManager Instance { get { return mInstance; } }
    public static GTUIManager Inst { get { return mInstance; } }

    // Skins
    private Dictionary<string, GTUISkin> mSkins = new Dictionary<string, GTUISkin>();
    // Fonts
    private Dictionary<string, GTUIFont> mFonts = new Dictionary<string, GTUIFont>();
    public Dictionary<string, Font> mNativeFonts = new Dictionary<string, Font>();
    // Canvas
    private Dictionary<string, GTUICanvas> mCanvases = new Dictionary<string, GTUICanvas>();

    public GTUIManager()
    {
        InitializeFonts();
    }

    /// <summary>
    /// Create default font objects from Fonts/BabelSans
    /// </summary>
    private void InitializeFonts()
    {
        // Add native fonts
        string fontPath = "Fonts/Default/BabelSans/";
        Font fontBabelSans = Resources.Load(fontPath + "BabelSans", typeof(Font)) as Font;
        Font fontBabelSansBold = Resources.Load(fontPath + "BabelSans-Bold", typeof(Font)) as Font;
        Font fontBabelSansBoldOblique = Resources.Load(fontPath + "BabelSans-BoldOblique", typeof(Font)) as Font;
        Font fontBabelSansOblique = Resources.Load(fontPath + "BabelSans-Oblique", typeof(Font)) as Font;

        if (fontBabelSans != null)
            mNativeFonts.Add("BabelSans", fontBabelSans);
        else
            Debug.LogError("GTUIManager: Failed to load font BabelSans !");

        if (fontBabelSansBold != null)
            mNativeFonts.Add("BabelSans-Bold", fontBabelSansBold);
        else
            Debug.LogError("GTUIManager: Failed to load font BabelSans-Bold !");

        if (fontBabelSansBoldOblique != null)
            mNativeFonts.Add("BabelSans-BoldOblique", fontBabelSansBoldOblique);
        else
            Debug.LogError("GTUIManager: Failed to load font BabelSans-BoldOblique !");

        if (fontBabelSansOblique != null)
            mNativeFonts.Add("BabelSans-Oblique", fontBabelSansOblique);
        else
            Debug.LogError("GTUIManager: Failed to load font BabelSans-Oblique !");
    }

    /// <summary>
    /// Get a Font by its name
    /// </summary>
    /// <param name="fontName"></param>
    /// <returns></returns>
    public Font GetFont(string fontName)
    {
        if (!GTUIManager.Instance.mNativeFonts.ContainsKey(fontName))
            return null;
        return GTUIManager.Instance.mNativeFonts[fontName];
    }

    /// <summary>
    /// Load BMFont
    /// </summary>
    /// <param name="fileName"></param>
    /// <returns></returns>
    public GTUIFont LoadBMFont(string path, string fileName)
    {
        GTUIFont font = GTUIBMFont.Create(path, fileName);
        if (font == null)
        {
            Debug.LogError("LoadBMFont: Failed to load BMFont: " + fileName);
            return null;
        }

        mFonts.Add(fileName, font);

        return font;
    }
        
    /// <summary>
    /// Load a UI layout file
    /// </summary>
    /// <param name="fileName"></param>
    /// <returns></returns>
    public bool LoadLayout(string fileName)
    {
        GTTreeNode treeNode = GTPropertyFile.Load(fileName);
        if (treeNode == null)
        {
            Debug.LogError("LoadLayout: Failed to load layout file: " + fileName);
            return false;
        }
        if (treeNode.tag != TagUILayout)
            return false;

        for (int i = 0; i < treeNode.childCount; i++)
        {
            GTTreeNode tn = treeNode.GetChild(i);
            if (tn != null)
            {
                if (tn.tag == TagUICanvas)
                    CreateCanvas(tn);
            }
        }

        return true;
    }
    
    /// <summary>
    /// Create cavans object
    /// </summary>
    /// <param name="treeNode"></param>
    /// <returns></returns>
    private bool CreateCanvas(GTTreeNode treeNode)
    {
        if (treeNode == null)
            return false;
        if (treeNode.tag != TagUICanvas)
            return false;

        // Use specified or default name
        string name = (treeNode.AsString() != string.Empty) ? treeNode.AsString() : "_UICanvasNoName";
        GTUICanvas canvas = GTUICanvas.Create(name);

        for (int child = 0; child < treeNode.childCount; child++)
        {
            GTTreeNode childNode = treeNode.GetChild(child);
            if (childNode == null)
                continue;

            switch (childNode.tag)
            {
                case TagSkin:
                    {
                        string skinFileName = childNode.AsString();
                        if (skinFileName != string.Empty)
                        {
                            // Check if this skin object is loaded already
                            if(!mSkins.ContainsKey(skinFileName))
                            {
                                // Not load yet
                                GTUISkin skin = GTUISkin.Create(skinFileName);
                                if (skin != null)
                                {
                                    mSkins.Add(skinFileName, skin);
                                    canvas.mSkin = skin;
                                    mCanvases.Add(name, canvas);
                                }
                                else
                                    Debug.LogError("CreateCanvas: Failed to load GTUISkin: " + childNode.AsString());
                            }
                        }
                    }
                    break;

                case TagFont:
                    break;

                case TagPosition:
                    break;

                case TagSize:
                    break;

                case TagVisible:
                    break;

                case TagEventType:
                    break;

                case TagChildren:
                    CreateChildren(childNode, canvas as GTUIWidget, canvas);
                    break;
            }
        }

        return true;
    }

    private bool CreateChildren(GTTreeNode treeNode, GTUIWidget parent, GTUICanvas canvas)
    {
        if (treeNode == null)
            return false;

        for (int child = 0; child < treeNode.childCount; child++)
        {
            GTTreeNode childNode = treeNode.GetChild(child);
            if (childNode == null)
                continue;

            switch (childNode.tag)
            {
                case TagUIImage:
                    CreateImage(childNode, parent, canvas);
                    break;

                case TagUIButton:
                    CreateButton(childNode, parent, canvas);
                    break;
            }
        }

        return true;
    }

    /// <summary>
    /// Create image object
    /// </summary>
    /// <param name="treeNode"></param>
    /// <param name="parent"></param>
    /// <param name="canvas"></param>
    /// <returns></returns>
    private bool CreateImage(GTTreeNode treeNode, GTUIWidget parent, GTUICanvas canvas)
    {
        if (treeNode == null || parent == null || null == canvas)
            return false;

        string name = (treeNode.AsString() != string.Empty) ? treeNode.AsString() : "_UIImageNoName";
        GTTreeNode nodePosition = treeNode.GetChild(TagPosition);
        GTTreeNode nodeSize = treeNode.GetChild(TagSize);
        GTTreeNode nodePieceEnabled = treeNode.GetChild(TagPieceEnabled);
        GTTreeNode nodeEventType = treeNode.GetChild(TagEventType);
        GTTreeNode nodeVisible = treeNode.GetChild(TagVisible);
        GTTreeNode nodeAnchorPoint = treeNode.GetChild(TagAnchorPoint);
        GTTreeNode nodeColor = treeNode.GetChild(TagColor);
        GTTreeNode nodeChildren = treeNode.GetChild(TagChildren);

        Vector3 position = (nodePosition != null) ? nodePosition.AsVector3() : new Vector3(0.0f, 0.0f, 0.0f);
        Vector2 size = (nodeSize != null) ? nodeSize.AsVector2() : new Vector2(0.0f, 0.0f);
        string pieceName = (nodePieceEnabled != null) ? nodePieceEnabled.AsString() : "_noPieceName";
        Vector2 anchor = (nodeAnchorPoint != null) ? nodeAnchorPoint.AsVector2() : new Vector2(0.0f, 0.0f);
        Vector3 vColor = (nodeColor != null) ? nodeColor.AsVector3() : new Vector3(255.0f, 255.0f, 255.0f);
        Color color = new Color(vColor.x / 255.0f, vColor.y / 255.0f, vColor.z / 255.0f);

        GTUIImage image = GTUIImage.Create(name, position, size, parent.mGameObject);
        if (image == null)
        {
            Debug.LogError("CreateImage: Failed to create an image object: " + name);
            return false;
        }
        image.color = color;
        // Sprite
        Sprite sprite = canvas.mSkin.mFrameSet[pieceName];
        if (sprite != null)
            image.sprite = canvas.mSkin.mFrameSet[pieceName];
        else
            Debug.LogWarning("CreateImage: No piece sprite found: " + pieceName);

        // Children
        CreateChildren(nodeChildren, image, canvas);

        return true;
    }

    /// <summary>
    /// Create button object
    /// </summary>
    /// <param name="treeNode"></param>
    /// <param name="parent"></param>
    /// <param name="canvas"></param>
    /// <returns></returns>
    private bool CreateButton(GTTreeNode treeNode, GTUIWidget parent, GTUICanvas canvas)
    {
        if (treeNode == null || parent == null || null == canvas)
            return false;

        string name = (treeNode.AsString() != string.Empty) ? treeNode.AsString() : "_UIButtonNoName";
        GTTreeNode nodePosition = treeNode.GetChild(TagPosition);
        GTTreeNode nodeSize = treeNode.GetChild(TagSize);
        GTTreeNode nodePieceEnabled = treeNode.GetChild(TagPieceEnabled);
        GTTreeNode nodeEventType = treeNode.GetChild(TagEventType);
        GTTreeNode nodeVisible = treeNode.GetChild(TagVisible);
        GTTreeNode nodeAnchorPoint = treeNode.GetChild(TagAnchorPoint);
        GTTreeNode nodeColor = treeNode.GetChild(TagColor);
        GTTreeNode nodeChildren = treeNode.GetChild(TagChildren);
        GTTreeNode nodeText = treeNode.GetChild(TagText);
        GTTreeNode nodeFont = treeNode.GetChild(TagFont);
        GTTreeNode nodeFontSize = treeNode.GetChild(TagFontSize);

        Vector3 position = (nodePosition != null) ? nodePosition.AsVector3() : new Vector3(0.0f, 0.0f, 0.0f);
        Vector2 size = (nodeSize != null) ? nodeSize.AsVector2() : new Vector2(0.0f, 0.0f);
        string pieceName = (nodePieceEnabled != null) ? nodePieceEnabled.AsString() : "_noPieceName";
        Vector2 anchor = (nodeAnchorPoint != null) ? nodeAnchorPoint.AsVector2() : new Vector2(0.0f, 0.0f);
        Vector3 vColor = (nodeColor != null) ? nodeColor.AsVector3() : new Vector3(255.0f, 255.0f, 255.0f);
        Color color = new Color(vColor.x / 255.0f, vColor.y / 255.0f, vColor.z / 255.0f);
        string text = (nodeText != null) ? nodeText.AsString() : "Button";
        string fontName = (nodeFont != null) ? nodeFont.AsString() : "BabelSans";
        int fontSize = (nodeFontSize != null) ? nodeFontSize.AsInt() : 16;
                
        GTUIButton button = GTUIButton.Create(name, position, size, parent.mGameObject);
        if (button == null)
        {
            Debug.LogError("CreateButton: Failed to create a button object: " + name);
            return false;
        }
        button.color = color;
        button.text = text;
        button.mText.textFont = GTUIManager.Instance.GetFont(fontName);
        button.mText.fontSize = fontSize;
        // Sprite
        Sprite sprite = canvas.mSkin.mFrameSet[pieceName];
        if (sprite != null)
            button.sprite = canvas.mSkin.mFrameSet[pieceName];
        else
            Debug.LogWarning("CreateButton: No piece sprite found: " + pieceName);
        //btn1.clickEvent.AddListener(OnBtnClick);

        // Children
        CreateChildren(nodeChildren, button, canvas);

        return true;
    }
}
