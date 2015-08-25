using UnityEngine;
using UnityEngine.UI;
using System.Collections;

public class GTUIButton : GTUIWidget
{    
    public Button mButton = null;
    public GTUIText mText = null;

    public GTUIButton()
    {
    }

    /// <summary>
    /// Position
    /// </summary>
    public override Vector2 position
    {
        get { return mImage.rectTransform.anchoredPosition; }
        set { mImage.rectTransform.anchoredPosition = value; }
    }

    /// <summary>
    /// Size
    /// </summary>
    public override Vector2 size
    {
        get { return mImage.rectTransform.sizeDelta; }
        set { mImage.rectTransform.sizeDelta = value; }
    }

    /// <summary>
    /// Text
    /// </summary>
    public string text
    {
        get { return mText.text; }
        set { mText.text = value; }
    }

    /// <summary>
    /// Events for click
    /// </summary>
    public Button.ButtonClickedEvent clickEvent
    {
        get { return mButton.onClick; }
    }

    /// <summary>
    /// Create a new button
    /// </summary>
    /// <param name="name"></param>
    /// <param name="pos"></param>
    /// <param name="tsize"></param>
    /// <param name="parent"></param>
    /// <returns></returns>
    public static GTUIButton Create(string name, Vector3 pos, Vector2 tsize, GameObject parent)
    {
        GTUIButton newButton = new GTUIButton();
        newButton.mGameObject = new GameObject(name);

        // RectTransform
        newButton.mRectTransform = newButton.mGameObject.AddComponent<RectTransform>();
        if (newButton.mRectTransform == null)
            Debug.LogError("GTUIButton: Failed to add RectTransform !");

        // CanvasRenderer
        newButton.mCanvasRenderer = newButton.mGameObject.AddComponent<CanvasRenderer>();
        if (newButton.mCanvasRenderer == null)
            Debug.LogError("GTUIButton: Failed to add CanvasRenderer !");

        // Image
        newButton.mImage = newButton.mGameObject.AddComponent<Image>();
        if (newButton.mImage == null)
            Debug.LogError("GTUIButton: Failed to add Image !");

        // Button
        newButton.mButton = newButton.mGameObject.AddComponent<Button>();
        if(newButton.mButton == null)
            Debug.LogError("GTUIButton: Failed to add Button !");

        if (parent != null)
            newButton.mImage.transform.parent = parent.transform;
        // Position
        newButton.position = pos;
        // Size
        newButton.size = tsize;

        // Create text object
        newButton.mText = GTUIText.Create("buttonText", new Vector3(0.0f, 0.0f, 0.0f), tsize, "Button", newButton.mGameObject);
        newButton.mText.color = new Color(1f, 1f, 1f, 1f);
        // Font
        string fontName = "BabelSans";
        if (GTUIManager.Instance.mNativeFonts.ContainsKey(fontName))
            newButton.mText.textFont = GTUIManager.Instance.mNativeFonts[fontName];
        else
            Debug.LogWarning("GTUIButton: Failed to find font !");
        // Text alignment            
        newButton.mText.textAlignment = TextAnchor.MiddleCenter;
        
        return newButton;
    }
}
