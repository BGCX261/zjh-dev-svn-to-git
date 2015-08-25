using UnityEngine;
using System.Collections;

public class MainPlayerScript : MovableCharacterScript
{
    public override void Awake()
    {
        base.Awake();
    }


    public override void Start()
    {
        base.Start();
    }


    public override void Update()
    {
        base.Update();

        if (Input.GetMouseButton(0))
        {
            Vector3 mousePos = Input.mousePosition;
            //Vector3 moveTowardWorldPoint = Camera.main.ScreenToWorldPoint(mousePos);
            //Debug.Log(string.Format("Mouse Pos = {0}, World Point = {1}", mousePos, moveTowardWorldPoint));
            base.MoveToPosition(mousePos);
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
        //GTTreeNode tnMoveLeftLimit = treeNode.GetChild("MoveLeftLimit");
        //mMoveLeftLimit = (tnMoveLeftLimit != null) ? tnMoveLeftLimit.AsFloat() : 40.0f;
        //GTTreeNode tnMoveRightLimit = treeNode.GetChild("MoveRightLimit");
        //mMoveRightLimit = (tnMoveRightLimit != null) ? tnMoveRightLimit.AsFloat() : 400.0f;

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
