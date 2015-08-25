using UnityEngine;
using System.Collections;

public class EnemyScript : MovableCharacterScript
{
    private float mMoveLeftLimit = 10.0f;
    private float mMoveRightLimit = 100.0f;

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
        base.Update();

        if (status == CharacterObject.StatusIdle)
        {
            Vector2 pos = base.GetPositionVector2();
            if (pos.x < mMoveLeftLimit)
            {
                base.MoveToPosition(new Vector2(mMoveRightLimit, pos.y));
            }
            else if (pos.x > mMoveRightLimit)
            {
                base.MoveToPosition(new Vector2(mMoveLeftLimit, pos.y));
            }
            else
            {
                base.MoveToPosition(new Vector2(mMoveLeftLimit, pos.y));
            }
        }
    }

    public override void Parse(GTTreeNode treeNode)
    {
        if (null == treeNode)
            return;

        GTTreeNode tnLife = treeNode.GetChild("Life");
        GTTreeNode tnMovementSpeed = treeNode.GetChild("MovementSpeed");
        base.movementSpeed = (tnMovementSpeed != null) ? tnMovementSpeed.AsInt() : 10;
        GTTreeNode tnFloatingEnable = treeNode.GetChild("FloatingEnable");
        base.floatingEnable = (tnFloatingEnable != null) ? tnFloatingEnable.AsBool() : false;
        GTTreeNode tnFloatingSpeed = treeNode.GetChild("FloatingSpeed");
        base.floatingSpeed = (tnFloatingSpeed != null) ? tnFloatingSpeed.AsFloat() : 2.5f;
        GTTreeNode tnFloatingMax = treeNode.GetChild("FloatingMax");
        base.floatingMax = (tnFloatingMax != null) ? tnFloatingMax.AsFloat() : 1.0f;
        GTTreeNode tnMoveLeftLimit = treeNode.GetChild("MoveLeftLimit");
        mMoveLeftLimit=(tnMoveLeftLimit!=null)?tnMoveLeftLimit.AsFloat():40.0f;
        GTTreeNode tnMoveRightLimit = treeNode.GetChild("MoveRightLimit");
        mMoveRightLimit = (tnMoveRightLimit != null) ? tnMoveRightLimit.AsFloat() : 400.0f;        

        //Life = 50
        //LifeMax = 50
        //Attack = 10
        //AttackSpeed = 1
        //AttackRange = 3
        //Armor = 1			
        //Experience = 10
        //ExperienceForNextLevel = 40
        //Money = 700
        //Level = 1
        //SkillPoint = 60
        //SkillPointMax = 60
        //DefaultDirection = 0
    }
}
