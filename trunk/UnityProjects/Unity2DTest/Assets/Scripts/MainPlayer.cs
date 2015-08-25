using UnityEngine;
using System.Collections;

public class MainPlayer : MonoBehaviour
{
    public float moveSpeed = 1.0f;
    private float prevTime;
    private bool moving = false;
    // Moving
    // Destination position
    private Vector2 mDestination;
    private Vector2 mPrevPosition;
    private Vector2 mMoveDirection;
    // Distance the player is going to move
    float mMoveDistance;

    // Use this for initialization
    void Start()
    {
        //prevTime = Time.time;

        SpriteRenderer sr = gameObject.GetComponent<SpriteRenderer>();
        if (sr != null)
        {
            //sr.sprite.
        }
    }

    void MoveTo(Vector2 newPos)
    {
        // Save current position
        mPrevPosition = gameObject.transform.position;
        // Save target position
        mDestination = newPos;
        // Calculate movement direction
        mMoveDirection = newPos - mPrevPosition;
        mMoveDirection.Normalize();
        // Calculate movement distance
        mMoveDistance = (newPos - mPrevPosition).magnitude;
        // Change status
        moving = true;
    }

    // Update is called once per frame
    void Update()
    {
        if (moving)
        {
            float deltaTime = Time.time - prevTime;
            prevTime = Time.time;

            Vector2 pos = new Vector2(gameObject.transform.position.x, gameObject.transform.position.y);
            pos += mMoveDirection * moveSpeed * deltaTime;

            // Calculate how much distance the player has moved
            float fMoveDistance = (pos - mPrevPosition).magnitude;
            if (fMoveDistance >= mMoveDistance)
            {
                gameObject.transform.position = new Vector3(pos.x, pos.y, gameObject.transform.position.z);
                // Already get to the destination, change status to idle.
                moving = false;
                // Setup floating if it's enabled
                /*
		        if(GetPropertyFloatingEnable())
		        {
			        m_vFloatingOldPos = GetGameObjectPosition();
			        m_fFloatingYHigh = m_vFloatingOldPos.y + m_fFloatingMax;
			        m_fFloatingYLow = m_vFloatingOldPos.y - m_fFloatingMax;
			        m_nFloatingDirection = -1;
		        }
                 * */
            }
            else
            {
                gameObject.transform.position = new Vector3(pos.x, pos.y, gameObject.transform.position.z);
            }

            //------
            //GTVector2 pos = GetGameObjectPosition();
            //pos += m_vMoveDirection * (((float)m_lDeltaTime / 1000.0f) * (float)m_nMovementSpeed);

            // Check if the player gets to the destination
            /*
            else
            {
                SetGameObjectPosition(pos);
                if(pos.x < m_vDestination.x)
                {
                    // Going right
                    m_pGameObjectSprite->PlayAnimationByName(BSCharacter::AnimationName_MoveRight, GSpriteAnimation::PlayMode_Loop);
                }
                else
                {
                    // Going left
                    m_pGameObjectSprite->PlayAnimationByName(BSCharacter::AnimationName_MoveLeft, GSpriteAnimation::PlayMode_Loop);
                }
            }
                }
             * */
        }

        if (Input.GetMouseButton(0))
        {
            Vector3 moveToward = Camera.main.ScreenToWorldPoint(Input.mousePosition);
            Debug.Log(string.Format("mouse position = {0}/{1}", moveToward, moveToward*100.0f));
            MoveTo(moveToward);
            prevTime = Time.time;
            moving = true;
        }
    }
}
