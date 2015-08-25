using UnityEngine;
using System.Collections;

public class GTUIBMFontLabel : GTUILabel
{
    public GTUIBMFontLabel()
    {
    }

    public override void SetText(string text)
    {
        if (string.IsNullOrEmpty(text))
            return;

        if (base.font == null)
            return;

        //if (!base.font.GetType().IsSubclassOf(typeof(GTUIBMFont)))
        //    return;

        GTUIBMFont bmFont = base.font as GTUIBMFont;
        if (bmFont == null)
            return;

        base.SetText(text);

        // For details of those lines of code drawing text,
        // please reference BitmapFontParser.
        float tx = base.position.x;
        float ty = base.position.y;
        char previousCharacter = ' ';
        int kerning = 0;
        for (int ti = 0; ti < text.Length; ti++)
        {
            char character = text[ti];
            BMFontCharacter bmfChar = bmFont.mBMFont.Characters[character];
            // Get Sprite object to draw this letter
            Sprite textSprite = bmFont.mSpriteSet[character];
            GameObject spriteGameObject = mTextGameObjects[ti];
            if (textSprite != null && spriteGameObject != null)
            {
                kerning = bmFont.mBMFont.GetKerning(previousCharacter, character);
                GTSpriteScript spriteScript = spriteGameObject.GetComponent<GTSpriteScript>();
                spriteScript.spriteRenderer.sprite = textSprite;
                spriteScript.SetPosition(
                    tx + bmfChar.Offset.X + kerning,
                    ty - bmfChar.Offset.Y // Convert to bottom-left from top-left(ty + bmfChar.Offset.Y)
                    );
            }
            tx += (float)(bmfChar.XAdvance + kerning);
            previousCharacter = character;
        }
    }
}
