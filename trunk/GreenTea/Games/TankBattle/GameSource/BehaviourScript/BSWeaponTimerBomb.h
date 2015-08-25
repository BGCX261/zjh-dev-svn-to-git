#ifndef _BS_WEAPON_TIMER_BOMB_H_
#define _BS_WEAPON_TIMER_BOMB_H_

#include <GTBehaviour.h>
#include "BSWeapon.h"

class BSWeaponTimerBomb : public BSWeapon
{
public:
	GTBEHAVIOUR_DEF(BSWeaponTimerBomb, BSWeapon);

public:
	BSWeaponTimerBomb();
	virtual ~BSWeaponTimerBomb();

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
	// OnVisible is called when the the object is set visible.
	virtual void OnVisible(GTGameObject *pCaller, bool bApplyForChildren);

	void ResetExplosion(void);
	void OnExplosionAnimationComplete(void *pParam);

public:
	GameObjectSprite *m_pSpriteExplosion;
	/*
	// The left limit of movement
	GT_PROPERTY_DEF_VAR_SET_GET_INT16(MoveLeftLimit);
	// The right limit of movement
	GT_PROPERTY_DEF_VAR_SET_GET_INT16(MoveRightLimit);
	// The direction of movement
	GT_PROPERTY_DEF_VAR_SET_GET_INT16(MoveDirection);
	// The default direction of movement
	GT_PROPERTY_DEF_VAR_SET_GET_INT16(DefaultDirection);
	*/
	long m_lTimeElapsed;
	bool m_bExplode;
};

#endif /* _BS_WEAPON_TIMER_BOMB_H_ */
