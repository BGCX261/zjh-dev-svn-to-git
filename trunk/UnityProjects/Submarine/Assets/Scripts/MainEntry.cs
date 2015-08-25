using UnityEngine;
using UnityEngine.UI;
using System.Collections;

public class MainEntry : MonoBehaviour
{
    /*
    private GTUILabel mLabel1 = null;
    private GTUILabel mLabel2 = null;
    private GTUILabel mLabel3 = null;
    private GTUISkin mSkin = null;
     * */

    void OnBtnClick()
    {
        Debug.Log(Time.time);
    }

    void Start()
    {
        GTUIManager.Instance.LoadLayout("UI/uiskin1.uilayout");
        
        /*
        GameObject tc = GameObject.Find("_UICanvas");
        GameObject tb = tc.transform.FindChild("btnQuit").gameObject;
        GameObject tf = tc.transform.FindChild("text").gameObject;
        RectTransform trt = tb.GetComponent<RectTransform>();
        RectTransform trf = tf.GetComponent<RectTransform>();
         * */

        /*
        mSkin = GTUISkin.Create("UI/uiskin1.uiskin");

        GTUICanvas canvas = GTUICanvas.Create("_UICanvasTest");
        //Texture2D btnTex = Resources.Load("UI/Button_Green", typeof(Texture2D)) as Texture2D;
        Texture2D btnTex1 = Resources.Load("UI/Button_Red", typeof(Texture2D)) as Texture2D;
        Texture2D texTitle = Resources.Load("UI/title", typeof(Texture2D)) as Texture2D;
        Texture2D texPanel = Resources.Load("UI/totalWinPopup", typeof(Texture2D)) as Texture2D;
        
        GTUIButton btn1 = GTUIButton.Create(
            "btn1",
            new Vector3(490.0f, 100.0f, 0.0f), // position
            new Vector2(btnTex1.width, btnTex1.height), // size
            canvas.mGameObject
            );
        btn1.color = new Color(1f, 1f, 1f, 1f);
        btn1.sprite = Sprite.Create(
            btnTex1,
            new Rect(0f, 0f, btnTex1.width, btnTex1.height),
            new Vector2(0.5f, 0.5f)
            );
        btn1.clickEvent.AddListener(OnBtnClick);

        GTUIImage img1 = GTUIImage.Create(
            "img11",
            new Vector3(-234.0f, -103.0f, 0.0f),
            //new Vector2(texPanel.width, texPanel.height),
            new Vector2(mSkin.mFrameSet[2].textureRect.width, mSkin.mFrameSet[2].textureRect.height),
            canvas.mGameObject
            );
        img1.color = new Color(1f, 1f, 1f, 1f);
        img1.sprite = mSkin.mFrameSet["panel"];
         * */
        /*
        img1.sprite = Sprite.Create(
            texPanel,
            new Rect(0f, 0f, texPanel.width, texPanel.height),
            new Vector2(0.5f, 0.5f)
            );
         * */
        /*
        GTUIText text1 = GTUIText.Create(
            "text1",
            //new Vector3(341.0f, -200.0f, 0.0f),
            new Vector3(0.0f, 0.0f, 0.0f),
            new Vector2(texTitle.width, texTitle.height),
            "hello",
            btn1.mGameObject
            );
        text1.color = new Color(1f, 1f, 1f, 1f);
        text1.textFont = fonts[0];
        text1.size = new Vector2(40.0f, 16.0f);
        //text1.text = ;

        GTUIFont font1 = GTUIManager.Instance.LoadBMFont("Fonts", "msyahei-32.xml");
        GTUIFont font2 = GTUIManager.Instance.LoadBMFont("Fonts", "arial-16.xml");
        GTUIFont font3 = GTUIManager.Instance.LoadBMFont("Fonts", "arial-16-bold.xml");
         * */

        /*
        mLabel1 = new GTUIBMFontLabel();
        mLabel1.font = font1;
        mLabel1.SetPosition(450.0f, 300.0f);
        mLabel1.alignment = GTUIAlignment.Center;
        mLabel1.SetText("Bitmap Font");

        mLabel2 = new GTUIBMFontLabel();
        mLabel2.font = font2;
        mLabel2.SetPosition(450.0f, 270.0f);
        mLabel2.alignment = GTUIAlignment.Center;
        mLabel2.SetText("Rendering Example");

        mLabel3 = new GTUIBMFontLabel();
        mLabel3.font = font3;
        mLabel3.SetPosition(450.0f, 330.0f);
        mLabel3.alignment = GTUIAlignment.Center;
        mLabel3.SetText("ABCabc@#$%");

        //font.DrawText("ABCabc@#$%", 450.0f, 300.0f, GTUIAlignment.Center);
        //font.DrawText("Bitmap Font", 450.0f, 300.0f, GTUIAlignment.Center);
        //font.DrawText("Rendering Example", 450.0f, 300.0f, GTUIAlignment.Center);
         * */
        
        GameObject spriteMainPlayer = GTGameObjectCreation.CreateFromProperty("Sprites/mainplayer.property", "spriteMainPlayer");
        GTSpriteScript scriptSpriteMainPlayer = spriteMainPlayer.GetComponent<GTSpriteScript>();
        scriptSpriteMainPlayer.SetPosition(335.0f, 325.0f);
        scriptSpriteMainPlayer.PlayAnimation(0, GTSpriteFrameSet.PlayMode.Loop);

        GameObject spriteGameObject1 = GTGameObjectCreation.CreateFromProperty("Sprites/enemy-01.property", "spriteEnemy01");
        GTSpriteScript scriptSprite1 = spriteGameObject1.GetComponent<GTSpriteScript>();
        scriptSprite1.SetPosition(805.0f, 460.0f);
        //scriptSprite1.PlayAnimation(0, GTSpriteFrameSet.PlayMode.Loop);
        //scriptSprite1.PlayAnimation(1, GTSpriteFrameSet.PlayMode.Loop);

        GameObject spriteTestRed = GTGameObjectCreation.CreateSprite("Sprites/test-red.sprite", 1, "spriteTestRed");
        GTSpriteScript scriptTestRed = spriteTestRed.GetComponent<GTSpriteScript>();
        scriptTestRed.SetPosition(503.0f, 350.0f);
        scriptTestRed.ShowFrame(0, 0);

        GameObject spriteGameObject6 = GTGameObjectCreation.CreateSprite("Sprites/icon06_anim.sprite", 1, "spriteEnemy06");
        GTSpriteScript scriptSprite6 = spriteGameObject6.GetComponent<GTSpriteScript>();
        scriptSprite6.SetPosition(813.0f, 306.0f);
        scriptSprite6.PlayAnimation(0, GTSpriteFrameSet.PlayMode.Loop);
    }

    void Update()
    {
    }
}
