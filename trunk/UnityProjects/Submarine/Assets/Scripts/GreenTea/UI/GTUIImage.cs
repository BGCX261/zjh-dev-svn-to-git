using UnityEngine;
using UnityEngine.UI;
using System.Collections;

public class GTUIImage : GTUIWidget
{
    public GTUIImage()
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
    /// Color
    /// </summary>
    public override Color color
    {
        get { return mImage.color; }
        set { mImage.color = value; }
    }

    /// <summary>
    /// Create an Image object
    /// </summary>
    /// <param name="name"></param>
    /// <param name="pos"></param>
    /// <param name="tsize"></param>
    /// <param name="parent"></param>
    /// <returns></returns>
    public static GTUIImage Create(string name, Vector3 pos, Vector2 tsize, GameObject parent)
    {
        GTUIImage newImage = new GTUIImage();
        newImage.mGameObject = new GameObject(name);

        // RectTransform
        newImage.mRectTransform = newImage.mGameObject.AddComponent<RectTransform>();
        if (newImage.mRectTransform == null)
            Debug.LogError("GTUIImage: Failed to add RectTransform !");

        // CanvasRenderer
        newImage.mCanvasRenderer = newImage.mGameObject.AddComponent<CanvasRenderer>();
        if (newImage.mCanvasRenderer == null)
            Debug.LogError("GTUIImage: Failed to add CanvasRenderer !");

        // Image
        newImage.mImage = newImage.mGameObject.AddComponent<Image>();
        if (newImage.mImage == null)
            Debug.LogError("GTUIImage: Failed to add Image !");

        if (parent != null)
            newImage.mImage.transform.parent = parent.transform;
        // Position
        newImage.position = pos;
        // Size
        newImage.size = tsize;

        return newImage;
    }
}
