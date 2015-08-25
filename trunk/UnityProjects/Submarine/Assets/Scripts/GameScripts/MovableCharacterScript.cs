using UnityEngine;
using System.Collections;

/// <summary>
/// This class is for characters that are able to move
/// </summary>
public class MovableCharacterScript : CharacterScript
{
    private float mDeltaTime; // In seconds
    private float mPrevTime;    
    // The movement speed of the unit in pixels/second
    private int mMovementSpeed;
    // Moving    
    private Vector2 mDestination; // Destination position
    private Vector2 mPrevPosition;
    private Vector2 mMoveDirection;
    // Distance the player is going to move
    private float mMoveDistance = 0;
    // Floating    
    private bool mFloatingEnable = false; // Floating is allowed or not
    private Vector3 mFloatingOldPos;
    private float mFloatingYHigh, mFloatingYLow;
    private float mFloatingDirection = 1;
    private float mFloatingMax = 2;
    private float mFloatingSpeed = 5;
    
    public bool floatingEnable
    {
        get { return mFloatingEnable; }
        set { mFloatingEnable = value; }
    }
    public float floatingMax
    {
        get { return mFloatingMax; }
        set { mFloatingMax = value; }
    }
    public float floatingSpeed
    {
        get { return mFloatingSpeed; }
        set { mFloatingSpeed = value; }
    }

    public int movementSpeed
    {
        get { return mMovementSpeed; }
        set { mMovementSpeed = value; }
    }

    public override void Awake()
    {
        base.Awake();
    }

    public override void Start()
    {
        base.Start();
        OnPrevSetupIdleStatus();
    }

    public override void Update()
    {
        mDeltaTime = Time.time - mPrevTime;

        switch (status)
        {
            case CharacterObject.StatusIdle:
                OnUpdateStatusIdle();
                break;

            case CharacterObject.StatusMoving:
                OnUpdateStatusMoving();
                break;
        }

        mPrevTime = Time.time;
    }

    public override void OnStatusChange(int newStatus)
    {
        switch (newStatus)
        {
            case CharacterObject.StatusIdle:
                OnPrevSetupIdleStatus();
                break;

            case CharacterObject.StatusMoving:
                break;
        }
    }

    public void OnPrevSetupIdleStatus()
    {
        // Setup floating if it's enabled
        if (mFloatingEnable)
        {
            mFloatingOldPos = base.spriteScript.GetPosition();
            mFloatingYHigh = mFloatingOldPos.y + mFloatingMax;
            mFloatingYLow = mFloatingOldPos.y - mFloatingMax;
            mFloatingDirection = -1.0f;
        }
    }

    /// <summary>
    /// For status of Moving
    /// </summary>
    private void OnUpdateStatusMoving()
    {
        Vector3 posv3 = base.GetPosition();
        Vector2 pos = new Vector2(posv3.x, posv3.y);
        pos += mMoveDirection * movementSpeed * mDeltaTime;

        // Calculate how much distance the player has moved
        float fMoveDistance = (pos - mPrevPosition).magnitude;
        if (fMoveDistance >= mMoveDistance)
        {
            base.SetPosition(pos.x, pos.y);
            // Already get to the destination, change status to idle.
            status = CharacterObject.StatusIdle;
            OnPrevSetupIdleStatus();
            // Setup floating if it's enabled
            mFloatingOldPos = base.GetPosition();
            mFloatingYHigh = mFloatingOldPos.y + mFloatingMax;
            mFloatingYLow = mFloatingOldPos.y - mFloatingMax;
            mFloatingDirection = -1.0f;
        }
        else
        {
            base.SetPosition(pos);
        }
    }

    /// <summary>
    /// For status of Idle
    /// </summary>
    private void OnUpdateStatusIdle()
    {
        if (!mFloatingEnable)
            return;

        Vector3 pos = base.GetPosition();
        pos.y += mFloatingDirection * (mDeltaTime * mFloatingSpeed);
        if (pos.y > mFloatingYHigh)
        {
            pos.y = mFloatingYHigh;
            mFloatingDirection = -1;
        }
        else if (pos.y < mFloatingYLow)
        {
            pos.y = mFloatingYLow;
            mFloatingDirection = 1.0f;
        }
        // Apply new position
        base.SetPosition(pos);
    }

    /// <summary>
    /// Move current game object to specified new position
    /// </summary>
    /// <param name="newPos"></param>
    public void MoveToPosition(Vector2 newPos)
    {
        // Save current position
        mPrevPosition = base.GetPosition();
        // Save target position
        mDestination = newPos;
        // Calculate movement direction
        mMoveDirection = newPos - mPrevPosition;
        mMoveDirection.Normalize();
        // Calculate movement distance
        mMoveDistance = (newPos - mPrevPosition).magnitude;
        // Change status to Moving
        status = CharacterObject.StatusMoving;

        // Check if the player gets to the destination
        if (mPrevPosition.x < mDestination.x)
        {
            // Moving right
            spriteScript.PlayAnimation(CharacterObject.AnimNameMoveRight, GTSpriteFrameSet.PlayMode.Loop);
        }
        else
        {
            // Moving left
            spriteScript.PlayAnimation(CharacterObject.AnimNameMoveLeft, GTSpriteFrameSet.PlayMode.Loop);
        }
    }
}
