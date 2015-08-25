using UnityEngine;
using System.Collections;
using System.Collections.Generic;

public class GTUILabel : GTUIWidget
{
    // Text sprites
    protected List<GameObject> mTextGameObjects = new List<GameObject>();

    public GTUILabel()
    {
    }

    /// <summary>
    /// Set text and build up sprite set
    /// </summary>
    /// <param name="text"></param>
    public virtual void SetText(string text)
    {
        if (string.IsNullOrEmpty(text))
            return;

        // Check if mTextGameObjects has enough room to handle text
        if (text.Length > mTextGameObjects.Count)
        {
            // Resize
            int newSize = text.Length - mTextGameObjects.Count;
            for (int i = 0; i < newSize; i++)
            {
                mTextGameObjects.Add(GTUIFont.CreateTextSprite(1, "labelSpriteText" + i));
            }
        }
    }
}
