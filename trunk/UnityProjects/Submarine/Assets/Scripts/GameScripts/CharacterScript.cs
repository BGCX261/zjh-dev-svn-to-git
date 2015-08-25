using UnityEngine;
using System.Collections;

/// <summary>
/// This class contains basic properties for characters
/// </summary>
public class CharacterScript : GTScript
{
    // The status of the character
	private int mStatus = CharacterObject.StatusIdle;
    /*
    // The life of the unit
	private int life;
	// The max life of the unit
	private int lifeMax;
	// The attack of the unit
	private int attack;
	// The attack speed of the unit
	private int attackSpeed;
	// The armor of the unit
	private int armor;
	// The attack arange
	private int attackRange;
	// The experience
	private int experience;
	// The money
	private int money;
	// The level
	private int level;
	// The skill points
	private int skillPoint;
	// The max skill points of the unit
	private int skillPointMax;
    // The left limit of movement
	private float moveLeftLimit;
	// The right limit of movement
	private float moveRightLimit;
	// The direction of movement
	private float moveDirection;
	// The default direction of movement
	private float defaultDirection;
     * */
    // Sprite script
    public GTSpriteScript spriteScript = null;
    
    public int status
    {
        get { return mStatus; }
        set
        {
            mStatus = value;
            OnStatusChange(mStatus);
        }
    }

    public override void Awake()
    {
        base.Awake();

        if (spriteScript == null)
            spriteScript = gameObject.GetComponent<GTSpriteScript>();
    }

    public override void Start()
    {
        base.Start();

        if (spriteScript == null)
            spriteScript = gameObject.GetComponent<GTSpriteScript>();
    }

    public override void Update()
    {
        base.Update();
    }

    public virtual void OnStatusChange(int newStatus)
    {
    }    

    /// <summary>
    /// Set position
    /// </summary>
    /// <param name="x"></param>
    /// <param name="y"></param>
    public void SetPosition(float x, float y)
    {
        spriteScript.SetPosition(x, y);
    }
    public void SetPosition(Vector3 newPos)
    {
        spriteScript.SetPosition(newPos);
    }
    public void SetPosition(Vector2 newPos)
    {
        spriteScript.SetPosition(newPos.x, newPos.y);
    }
    /// <summary>
    /// Get position
    /// </summary>
    /// <returns></returns>
    public Vector3 GetPosition()
    {
        return spriteScript.GetPosition();
    }
    public Vector2 GetPositionVector2()
    {
        return spriteScript.GetPositionVector2();
    }
}
