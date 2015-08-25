using UnityEngine;
using System.Collections;

public class CharacterObject
{
    // Animation name
    public const string AnimNameIdle = "Idle";
    public const string AnimNameMoveDown = "MoveDown";
    public const string AnimNameMoveLeft = "MoveLeft";
    public const string AnimNameMoveRight = "MoveRight";
    public const string AnimNameMoveUp = "MoveUp";
    // Status
    public const int StatusIdle = 0;
    public const int StatusMoving = 1;
    public const int StatusAttack = 2;
    public const int StatusDying = 3;
    public const int StatusDied = 4;
}
