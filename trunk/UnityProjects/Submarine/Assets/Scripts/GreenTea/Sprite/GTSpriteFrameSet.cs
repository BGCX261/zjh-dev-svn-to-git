using UnityEngine;
using System.Collections;
using System.Collections.Generic;

/// <summary>
/// GTSpriteFrameSet handles Unity Sprite collection, representing an aniamtion
/// </summary>
public class GTSpriteFrameSet
{
    // Pivots pre-defined
    static public Vector2 PivotLeftTop = new Vector2(0.0f, 1.0f);
    static public Vector2 PivotLeftBottom = new Vector2(0.0f, 0.0f);
    static public Vector2 PivotCenter = new Vector2(0.5f, 0.5f);
    static public Vector2 PivotRightTop = new Vector2(1.0f, 1.0f);
    static public Vector2 PivotRightBottom = new Vector2(1.0f, 0.0f);
    // Play mode
    public enum PlayMode
    {
        None = 0,
        Once = 1,
        Loop = 2
    }

    private Sprite[] mSpriteSet = null;
    public Dictionary<string, Sprite> mDicSpriteSet = new Dictionary<string, Sprite>();
    // Get a Sprite object by its index
    public Sprite this[uint index] { get { return mSpriteSet[index]; } }
    // Get a Sprite object by its name
    public Sprite this[string name] { get { return mDicSpriteSet[name]; } }

    // Name
    private string mName;
    public string name
    {
        get { return mName; }
        set { mName = value; }
    }

    // FPS (Frames Per Seconds)
    private float mFPS = 10.0f;
    private int mFrameInverval = (int)((1.0f / 10.0f) * 1000.0f); // In mill-seconds
    public float FPS
    {
        get
        {
            return mFPS;
        }
        set
        {
            mFPS = value;
            mFrameInverval = (int)((1.0f / mFPS) * 1000.0f); // In Mill-seconds
        }
    }
    public float frameInverval { get { return mFrameInverval; } }
    // How many frames this frame set has
    public int frameCount { get { return mSpriteSet.Length; } }

    /// <summary>
    /// Create a frame set from a atlas, start frame index, and number of frames
    /// </summary>
    /// <param name="spriteAtlas">Sprite atlas</param>
    /// <param name="startFrameIndex">Start frame index</param>
    /// <param name="frameCount">Number of frames</param>
    /// <returns>true/false</returns>
    public bool Create(GTSpriteAtlasCocos2D spriteAtlas, int startFrameIndex, int frameCount, Vector2 pivot)
    {
        if (spriteAtlas == null || startFrameIndex < 0 || frameCount == 0)
            return false;

        mSpriteSet = new Sprite[frameCount];
        for (int i = 0; i < frameCount; i++)
        {
            GTSpriteAtlasCocos2DFrame frame = spriteAtlas[startFrameIndex + i];
            mSpriteSet[i] = Sprite.Create(
                spriteAtlas.texture,
                new Rect(frame.frame.x, frame.frame.y, frame.frame.width, frame.frame.height),
                pivot,
                GTSystemSetting.PixelsToUnits
                );
            if (mSpriteSet[i] != null)
            {
                mDicSpriteSet.Add(frame.name, mSpriteSet[i]);
            }
        }

        return true;
    }
}
