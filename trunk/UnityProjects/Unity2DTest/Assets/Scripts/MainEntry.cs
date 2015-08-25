using UnityEngine;
using System.Collections;

public class MainEntry : MonoBehaviour
{
    private GTSpriteAtlasCocos2D mAtlasSheet = new GTSpriteAtlasCocos2D();

    // Use this for initialization
    void Start()
    {
        //TextAsset textAsset = Resources.Load("Sprites/enemy-01", typeof(TextAsset)) as TextAsset;

        Texture2D texMainPlayer = Resources.Load("Sprites/mainplayer", typeof(Texture2D)) as Texture2D;

        mAtlasSheet.Load("Sprites/enemy-01");
        //parser.Parse(textAsset.text);"
        GTSpriteAtlasCocos2DFrame frame = mAtlasSheet[0];

        GameObject goSprite = new GameObject("spriteEnemy01");
        SpriteRenderer spriteRenderer = goSprite.AddComponent<SpriteRenderer>();
        spriteRenderer.sortingOrder = 1;
        // Pivot:
        // Vector2(0.5f, 0.5f) - Center
        // Vector2(0.0f, 1.0f) - Left-Top
        // Vector2(0.0f, 0.0f) - Left-Bottom
        // Vector2(1.0f, 1.0f) - Right-Top
        // Vector2(1.0f, 0.0f) - Right-Bottom
        spriteRenderer.sprite = Sprite.Create(
            mAtlasSheet.texture,
            new Rect(frame.frame.x, frame.frame.y, frame.frame.width, frame.frame.height),
            //new Vector2(0.5f, 0.5f),
            //new Vector2(0.0f, 0.0f),
            //new Vector2(1.0f, 1.0f),
            //new Vector2(0.0f, 1.0f),
            new Vector2(0.5f, 0.5f),
                100.0f
                );

        // Texture:
        // x/y - Left-Bottom (0,0)
        /*
        spriteRenderer.sprite = Sprite.Create(
            texMainPlayer,
            new Rect(0, 40, texMainPlayer.width/2, texMainPlayer.height/2),
            new Vector2(0.5f, 0.5f),
            100.0f
            );
         * */
    }

    // Update is called once per frame
    void Update()
    {

    }
}
