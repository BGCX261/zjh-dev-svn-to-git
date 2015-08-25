using UnityEngine;
using UnityEngine.UI;
using System.Collections;
using System.Collections.Generic;

public enum GTUIAlignment
{
    Center,
    Left,
    Right,
    LeftBottom,
    LeftTop,
    RightBottom,
    RightTop
}

public struct GTUIRegion
{
    float x;
    float y;
    float width;
    float height;
}

public class GTUIWidget
{
    public GameObject mGameObject = null;
    public RectTransform mRectTransform = null;
    public CanvasRenderer mCanvasRenderer = null;
    public Image mImage = null;

    /// <summary>
    /// Position
    /// </summary>
    public virtual Vector2 position
    {
        get { return Vector2.zero; }
        set { }        
    }

    /// <summary>
    /// Size of the widget
    /// </summary>
    public virtual Vector2 size
    {
        get { return Vector2.zero; }
        set { }
    }

    public virtual Color color
    {
        get { return Color.black; }
        set { }
    }

    /// <summary>
    /// Sprite
    /// </summary>
    public Sprite sprite
    {
        set { mImage.sprite = value; }
    }

    /*
    // Parent
    public GTUIWidget parent=null;
    // Name
    public string name = string.Empty;
    // Text
    public string textContent = string.Empty;
    // Position
    public Vector2 position = new Vector2();
    // Region
    public GTUIRegion region = new GTUIRegion();
    // Alignment
    public GTUIAlignment alignment = GTUIAlignment.Center;
     * */

    // GTUIFont object
    private GTUIFont mFont = null;
    public GTUIFont font
    {
        get { return mFont; }
        set { mFont = value; }
    }
        
    public GTUIWidget()
    {
    }

    /*
    public GTUIWidget(GTUIWidget tparent)
    {
        parent = tparent;
    }
     * */

    /*
    /// <summary>
    /// Set position
    /// </summary>
    /// <param name="x"></param>
    /// <param name="y"></param>
    public void SetPosition(float x, float y)
    {
        position.x = x;
        position.y = y;
    }
     * */
}
