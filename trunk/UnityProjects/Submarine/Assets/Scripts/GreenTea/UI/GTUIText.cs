using UnityEngine;
using UnityEngine.UI;
using System.Collections;

public class GTUIText : GTUIWidget
{
    public Text mText = null;

    public GTUIText()
    {
    }

    /// <summary>
    /// Position
    /// </summary>
    public override Vector2 position
    {
        get { return mRectTransform.anchoredPosition; }
        set { mRectTransform.anchoredPosition = value; }
    }

    /// <summary>
    /// Text
    /// </summary>
    public string text
    {
        set { mText.text = value; }
        get { return mText.text; }
    }

    /// <summary>
    /// Font
    /// </summary>
    public Font textFont
    {
        set { mText.font = value; }
        get { return mText.font; }
    }

    /// <summary>
    /// Text size
    /// </summary>
    public override Vector2 size
    {
        set { mRectTransform.sizeDelta = value; }
        get { return mRectTransform.sizeDelta; }
    }

    /// <summary>
    /// Font style
    /// </summary>
    public FontStyle fontStyle
    {
        set { mText.fontStyle = value; }
        get { return mText.fontStyle; }
    }
        
    /// <summary>
    /// Font size
    /// </summary>
    public int fontSize
    {
        set { mText.fontSize = value; }
        get { return mText.fontSize; }
    }

    /// <summary>
    /// Whether support rich text
    /// </summary>
    public bool richText
    {
        set { mText.supportRichText = value; }
        get { return mText.supportRichText; }
    }

    /// <summary>
    /// Text alignment
    /// </summary>
    public TextAnchor textAlignment
    {
        set { mText.alignment = value; }
        get { return mText.alignment; }
    }

    /// <summary>
    /// Create GTUIText
    /// </summary>
    /// <param name="name"></param>
    /// <param name="pos"></param>
    /// <param name="tsize"></param>
    /// <param name="text"></param>
    /// <param name="parent"></param>
    /// <returns></returns>
    public static GTUIText Create(string name, Vector3 pos, Vector2 tsize, string text, GameObject parent)
    {
        GTUIText newText = new GTUIText();
        newText.mGameObject = new GameObject(name);
                
        // RectTransform
        newText.mRectTransform = newText.mGameObject.AddComponent<RectTransform>();
        if (newText.mRectTransform == null)
            Debug.LogError("GTUIImage: Failed to add RectTransform !");

        // CanvasRenderer
        newText.mCanvasRenderer = newText.mGameObject.AddComponent<CanvasRenderer>();
        if (newText.mCanvasRenderer == null)
            Debug.LogError("GTUIImage: Failed to add CanvasRenderer !");

        // Text
        newText.mText = newText.mGameObject.AddComponent<Text>();
        if (newText.mText == null)
            Debug.LogError("GTUIImage: Failed to add Text !");
        else
            newText.mText.text = text;

        if (parent != null)
            newText.mText.transform.parent = parent.transform;
        // Position
        newText.position = pos;
        // Size
        newText.size = tsize;

        return newText;
    }
}
