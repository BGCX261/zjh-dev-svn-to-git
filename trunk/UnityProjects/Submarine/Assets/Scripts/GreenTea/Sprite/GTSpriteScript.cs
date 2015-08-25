using UnityEngine;
using System.Collections;
using System.Collections.Generic;

/// <summary>
/// GTSpriteComponent handles all stuff related to frameset, animtions, etc
/// </summary>
public class GTSpriteScript : MonoBehaviour
{
    // Delegates
    public delegate void DelegateOnAnimationComplete(uint animationIndex);
    private DelegateOnAnimationComplete mDelegateOnAnimationComplete = null;

    // Atlas & frame sets
    private GTSpriteFrameSet[] mFrameSet = null;
    private Dictionary<string, uint> mFrameSetNameDic = new Dictionary<string, uint>();
    private SpriteRenderer mSpriteRenderer = null;
    // Working variables
    private float mPrevTime = 0;
    private GTSpriteFrameSet mCurrentFrameSet = null;
    private uint mFrameSetIndex = 0;
    private uint mFrameIndex = 0;
    // If there is an animation being played
    private bool mPlayingAnimation = false;
    private GTSpriteFrameSet.PlayMode mPlayingMode = GTSpriteFrameSet.PlayMode.None;

    public SpriteRenderer spriteRenderer { get { return mSpriteRenderer; } }

    void Awake()
    {
        if (mSpriteRenderer == null)
            mSpriteRenderer = gameObject.GetComponent<SpriteRenderer>();
    }

    void Start()
    {
    }

    void Update()
    {
        UpdateAnimation();
    }

    /// <summary>
    /// Play an animation by its index
    /// </summary>
    /// <param name="animationIndex"></param>
    /// <param name="playMode"></param>
    public void PlayAnimation(uint animationIndex, GTSpriteFrameSet.PlayMode playMode)
    {
        if (animationIndex > mFrameSet.Length)
            return;

        // Pre-setup for playing the animation
        mFrameSetIndex = animationIndex;
        mCurrentFrameSet = mFrameSet[animationIndex];        
        mFrameIndex = 0;
        mPlayingMode = playMode;
        mPrevTime = Time.time;
        mPlayingAnimation = true;
        // Show first frame
        ShowFrame(animationIndex, mFrameIndex);
    }

    public void PlayAnimation(string animName, GTSpriteFrameSet.PlayMode playMode)
    {
        if (mFrameSetNameDic.ContainsKey(animName))
        {
            PlayAnimation(mFrameSetNameDic[animName], playMode);
        }
    }
        
    /// <summary>
    /// Get a frameset by its index
    /// </summary>
    /// <param name="index"></param>
    /// <returns></returns>
    public GTSpriteFrameSet GetFrameSet(uint index)
    {
        return (index < mFrameSet.Length) ? mFrameSet[index] : null;
    }

    /// <summary>
    /// Set position (in screen pixels) instead of setting gameObject.transform.position
    /// </summary>
    /// <param name="newPos">New position in screen pixels</param>
    public void SetPosition(Vector3 newPos)
    {
        Vector3 pos = newPos / GTSystemSetting.PixelsToUnits;
        pos.z = gameObject.transform.position.z;
        gameObject.transform.position = pos;
    }
    public void SetPosition(float x, float y)
    {
        gameObject.transform.position = new Vector3(
            x / GTSystemSetting.PixelsToUnits,
            y / GTSystemSetting.PixelsToUnits,
            gameObject.transform.position.z
            );
    }

    /// <summary>
    /// Get position returned in screen pixels
    /// </summary>
    /// <returns></returns>
    public Vector3 GetPosition()
    {
        Vector3 pos = gameObject.transform.position;
        pos *= GTSystemSetting.PixelsToUnits;
        pos.z = gameObject.transform.position.z;
        return pos;
    }
    public Vector2 GetPositionVector2()
    {
        Vector2 pos = new Vector2(gameObject.transform.position.x, gameObject.transform.position.y);
        pos *= GTSystemSetting.PixelsToUnits;
        return pos;
    }

    /// <summary>
    /// Add an event for animation complete
    /// </summary>
    /// <param name="callback"></param>
    public void AddEventAnimationComplete(DelegateOnAnimationComplete callback)
    {
        if (mDelegateOnAnimationComplete == null)
            mDelegateOnAnimationComplete = new DelegateOnAnimationComplete(callback);
        else
            mDelegateOnAnimationComplete += new DelegateOnAnimationComplete(callback);
    }

    /// <summary>
    /// Update animation
    /// </summary>
    private void UpdateAnimation()
    {
        if (mPlayingAnimation == false)
            return;

        int deltaTime = (int)(((Time.time - mPrevTime) * 1000.0f)); // second to mill-second
        if (deltaTime > mCurrentFrameSet.frameInverval)
        {
            // Next frame
            mFrameIndex++;
            // Check the frame
            if (mFrameIndex >= mCurrentFrameSet.frameCount)
            {
                if (mPlayingMode == GTSpriteFrameSet.PlayMode.Once)
                {
                    mPlayingAnimation = false;
                    OnAnimationComplete(mFrameSetIndex);
                    return;
                }
                else if (mPlayingMode == GTSpriteFrameSet.PlayMode.Loop)
                {
                    // Reset to start frame for Loop
                    mFrameIndex = 0;
                }                
            }
            // Show the frame
            mSpriteRenderer.sprite = mCurrentFrameSet[mFrameIndex];
            // Save time
            mPrevTime = Time.time;
        }
    }

    /// <summary>
    /// Show a specified frame in specified frame set
    /// </summary>
    /// <param name="frameSetIndex"></param>
    /// <param name="frameIndex"></param>
    public void ShowFrame(uint frameSetIndex, uint frameIndex)
    {
        if (mSpriteRenderer != null &&
            frameSetIndex < mFrameSet.Length &&
            frameIndex < mFrameSet[frameSetIndex].frameCount)
        {
            mSpriteRenderer.sprite = mFrameSet[frameSetIndex][frameIndex];
        }
    }

    /// <summary>
    /// Create a sprite from the atlas
    /// </summary>
    /// <param name="spriteAtlas"></param>
    /// <returns></returns>
    public bool Create(GTSpriteAtlasCocos2D spriteAtlas, GTTreeNode tnSprite)
    {
        if (null == spriteAtlas || spriteAtlas.frameCount == 0)
            return false;

        GTTreeNode tnAnimation = tnSprite.GetChild(GTPropertyFile.TagAnimation);
        GTTreeNode tnAnchor = tnSprite.GetChild(GTPropertyFile.TagAnchor);
        Vector2 pivot = GTSpriteFrameSet.PivotCenter;
        if (tnAnchor != null)
            pivot = tnAnchor.AsVector2();

        if (tnAnimation != null && tnAnimation.childCount != 0)
        {
            mFrameSet = new GTSpriteFrameSet[tnAnimation.childCount];
            // Create each frameset
            for (int childIndex = 0; childIndex < tnAnimation.childCount; childIndex++)
            {
                GTTreeNode tnFramdset = tnAnimation.GetChild(childIndex);
                if (tnFramdset != null)
                {
                    GTTreeNode tnFPS = tnFramdset.GetChild(GTPropertyFile.TagFPS);
                    GTTreeNode tnStartFrame = tnFramdset.GetChild(GTPropertyFile.TagStartFrame);
                    GTTreeNode tnFrameCount = tnFramdset.GetChild(GTPropertyFile.TagFrameCount);
                    if (tnStartFrame == null)
                        Debug.LogError("Couldn't find StartFrame in GTTreeNode !");
                    if (tnFrameCount == null)
                        Debug.LogError("Couldn't find FrameCount in GTTreeNode !");
                    if (tnStartFrame != null && tnFrameCount != null)
                    {
                        mFrameSet[childIndex] = new GTSpriteFrameSet();
                        mFrameSet[childIndex].name = tnFramdset.AsString();
                        mFrameSet[childIndex].Create(
                            spriteAtlas,
                            tnStartFrame.AsInt(),
                            tnFrameCount.AsInt(),
                            pivot
                            );
                        if (tnFPS != null)
                        {
                            mFrameSet[childIndex].FPS = tnFPS.AsFloat();
                        }
                    }

                    if(!mFrameSetNameDic.ContainsKey(tnFramdset.AsString()))
                        mFrameSetNameDic.Add(tnFramdset.AsString(), (uint)childIndex);
                }
            }
        }

        return true;
    }

    /// <summary>
    /// When an animation playing is complete this method is called
    /// </summary>
    /// <param name="frameSetIndex"></param>
    private void OnAnimationComplete(uint frameSetIndex)
    {
        if (mDelegateOnAnimationComplete != null)
        {
            mDelegateOnAnimationComplete(frameSetIndex);
        }
    }
}
