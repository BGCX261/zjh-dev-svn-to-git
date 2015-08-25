#ifndef _BS_WEAPON_H_
#define _BS_WEAPON_H_

#include <GTGreenTea.h>
#include <GTBehaviour.h>

class GameObjectSprite;

class BSWeapon : public GTBehaviour
{
public:
	GTBEHAVIOUR_DEF(BSWeapon, GTBehaviour);

public:
	BSWeapon();
	virtual ~BSWeapon();

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
	
public:
	GameObjectSprite *m_pWeaponGameObject;
	// The left limit of movement
	GT_PROPERTY_DEF_VAR_SET_GET_INT16(MoveLeftLimit);
	// The right limit of movement
	GT_PROPERTY_DEF_VAR_SET_GET_INT16(MoveRightLimit);
	// The direction of movement
	GT_PROPERTY_DEF_VAR_SET_GET_INT16(MoveDirection);
	// The default direction of movement
	GT_PROPERTY_DEF_VAR_SET_GET_INT16(DefaultDirection);
	// Damage
	GT_PROPERTY_DEF_VAR_SET_GET_INT16(Damage);
	// Damage range
	GT_PROPERTY_DEF_VAR_SET_GET_INT16(DamageRange);
};

#endif /* _BS_WEAPON_H_ */
