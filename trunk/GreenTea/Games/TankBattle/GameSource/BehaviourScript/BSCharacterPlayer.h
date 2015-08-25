#ifndef _BS_CHARACTER_PLAYER_H_
#define _BS_CHARACTER_PLAYER_H_

#include <GTBehaviour.h>
#include "BSCharacter.h"

class UIWidget;

class BSCharacterPlayer : public BSCharacter
{
public:
	GTBEHAVIOUR_DEF(BSCharacterPlayer, BSCharacter);

public:
	BSCharacterPlayer();
	virtual ~BSCharacterPlayer();

	// This method is called when GTBehaviour object is created.
	virtual int32 OnCreate(void);
	// This method is called when GTBehaviour object is initialized.
	virtual int32 OnInitialize(GTBehaviourInit* param);
	// This method is called before first OnUpdate
	virtual int32 OnStart(void);
	// This method is called when GTBehaviour object is updated.
	virtual int32 OnUpdate(void);
	// This method is called when GTBehaviour object is destroyed.
	virtual int32 OnDestroy(void);

	// Update for status
	virtual void OnUpdateStatusIdle(void);
	virtual void OnUpdateStatusMoving(void);
	virtual void OnUpdateStatusAttack(void);
	virtual void OnUpdateStatusDying(void);
	virtual void OnUpdateStatusDied(void);

	// Move to
	void MoveTo(const GTVector2& vNewPos);
	// Fire a weapon
	void FireWeapon(const int32 nItemId);

	// Once single-click event occurs, this callback is called.
	static int32 OnSingleClickEventDelegate(const uint32 Flags, const GTPoint2 point, void* pParam);
	// Callbacks for item UI layout
	bool OnBtnItemSingleClick(UIWidget* pWidget, uint32 nFlags, void *pParam);

public:
	// The left limit of movement
	GT_PROPERTY_DEF_VAR_SET_GET_INT16(MoveLeftLimit);
	// The right limit of movement
	GT_PROPERTY_DEF_VAR_SET_GET_INT16(MoveRightLimit);
	// The direction of movement
	GT_PROPERTY_DEF_VAR_SET_GET_INT16(MoveDirection);
	// The default direction of movement
	GT_PROPERTY_DEF_VAR_SET_GET_INT16(DefaultDirection);

	// Floating
	GT_PROPERTY_DEF_VAR_SET_GET_BOOL(FloatingEnable);
	// Floating speed, pixels/second
	float m_fFloatingSpeed;
	// Floating maximum
	float m_fFloatingMax;
	GTVector2 m_vFloatingOldPos;
	float m_fFloatingYHigh;
	float m_fFloatingYLow;
	int32 m_nFloatingDirection;

	// Moving
	// Destination position
	GTVector2 m_vDestination;
	GTVector2 m_vPrevPosition;
	GTVector2 m_vMoveDirection;
	// Distance the player is going to move
	int32 m_nMoveDistance;
};

#endif /* _BS_CHARACTER_PLAYER_H_ */
