using UnityEngine;
using System.Collections;
using System.Collections.Generic;

public class GTUIFont
{    
    // Character sprite set
    public Dictionary<char, Sprite> mSpriteSet = new Dictionary<char, Sprite>();

    // Name
    protected string mName;
    public string name
    {
        get { return mName; }
        set { mName = value; }
    }
    // Texture
    protected Texture2D mTexture = null;
    public Texture2D texture
    {
        get { return mTexture; }
        set { mTexture = value; }
    }
    
    public GTUIFont()
    {
    }
    
    /// <summary>
    /// Create a sprite for text
    /// </summary>
    /// <param name="sortingOrder"></param>
    /// <param name="gameObjectName"></param>
    /// <returns></returns>
    public static GameObject CreateTextSprite(int sortingOrder, string gameObjectName)
    {
        string finalGameObjectName = (gameObjectName != null) ? gameObjectName : "spriteTextNoName";
        GameObject spriteGameObject = new GameObject(finalGameObjectName);
        // Add SpriteRenderer
        SpriteRenderer spriteRenderer = spriteGameObject.AddComponent<SpriteRenderer>();
        if (null == spriteRenderer)
        {
            Debug.LogError("CreateTextSprite: Failed to add SpriteRenderer");
            return null;
        }
        spriteRenderer.sortingOrder = sortingOrder;
        spriteRenderer.sprite = null;
        // Add GTSpriteScript
        GTSpriteScript spriteScript = spriteGameObject.AddComponent<GTSpriteScript>();
        if (null == spriteScript)
        {
            Debug.LogError("CreateTextSprite: Failed to add GTSpriteScript");
            return null;
        }

        return spriteGameObject;
    }
}
