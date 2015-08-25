#ifndef _BS_SPRITE_MOVEMENT_H_
#define _BS_SPRITE_MOVEMENT_H_

#include <GTGreenTea.h>
#include <GameObjectSprite.h>

class BSMapSprite;
class BSPathFinding;

class BSSpriteMovement : public GTBehaviour
{
public:
	GTBEHAVIOUR_DEF(BSSpriteMovement, GTBehaviour);

public:
	BSSpriteMovement();
	virtual ~BSSpriteMovement();

	// This method is called when GTBehaviour object is created.
	virtual int32 OnCreate(void);
	// This method is called when GTBehaviour object is initialized.
	virtual int32 OnInitialize(GTBehaviourInit* param);
	// This method is called when GTBehaviour object is updated.
	virtual int32 OnUpdate(void);
	// This method is called when GTBehaviour object is destroyed.
	virtual int32 OnDestroy(void);

	// Initialize the properties
	void InitializeProperties(GTTreeNode* pTreeNode);
	void GetMovementPathNode(const int32 nStartIndex);
	// Get direction from two positions
	int32 GetDirection(const CPF_Pos *pos1, const CPF_Pos *pos2);
	// Start moving
	void StartMovement(void);
	// Stop moving
	void StopMovement(void);

private:
	GameObjectSprite* m_pGameObjectSprite;
	BSPathFinding *m_pPathFinding;
	int32 m_nCurrentPathNodeIndex;
	int32 m_nDirection;
	GTPoint2 m_StartPos;
	GTPoint2 m_EndPos;
	// Properties
	float m_Speed;

public:
	// The direction of the sprite
	static const int32 DirectionUp;
	static const int32 DirectionDown;
	static const int32 DirectionLeft;
	static const int32 DirectionRight;

	static const tchar* RunAnimation[];
};

#endif /* _BS_SPRITE_MOVEMENT_H_ */
