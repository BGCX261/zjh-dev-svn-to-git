#ifndef _BS_UNIT_BEHAVIOUR_H_
#define _BS_UNIT_BEHAVIOUR_H_

#include <GTBehaviour.h>
#include "SceneGameObjectManager.h"
#include "BSGameObjectGeneral.h"
#include "BSSprite.h"
#include "../BehaviourScript/BSTweener2D.h"

class BSUnitBehaviour : public GTBehaviour
{
public:
	GTBEHAVIOUR_DEF(BSUnitBehaviour, GTBehaviour);

public:
	BSUnitBehaviour();
	virtual ~BSUnitBehaviour();

	// This method is called when GTBehaviour object is created.
	virtual int32 OnCreate(void);
	// This method is called when GTBehaviour object is initialized.
	virtual int32 OnInitialize(GTBehaviourInitParam* param);
	// This method is called before first OnUpdate
	virtual int32 OnStart(void);
	// This method is called when GTBehaviour object is updated.
	virtual int32 OnUpdate(void);
	// This method is called when GTBehaviour object is destroyed.
	virtual int32 OnDestroy(void);

	// Reset the weapon
	virtual void OnResetWeapon(void);

	// Get correct attack animation according to the player's position
	int32 GetAttackAnimationIndexFromPlayerPosition(void);
	// When the animation played is completed, this method is called.
	void OnAnimationPlayingCompletion(void* pParam);
	void OnStateIdle(void);
	void OnStateAttack(void);
	void FireWeapon(void);
	// When fire weapon actin is done, this callback is called.
	static void OnFireWeaponCompletion(void *pParam);
	// Does the weapon hit the player ?
	bool DoesWeaponHitPlayer(void);
	
	bool IsAnimationPlaying(void)
	{
		return m_pSprite ? m_pSprite->m_pSprite->IsAnimationPlaying() : false;
	}
	bool PlayAnimationByName(const tchar* szAnimationName, const uint32 nFlags, GTObject_CallbackFunction pCallback)
	{
		return m_pSprite ? m_pSprite->m_pSprite->PlayAnimationByName(szAnimationName, nFlags, pCallback) : false;
	}
	bool PlayAnimationByName(const tchar* szAnimationName, const uint32 nFlags)
	{
		return m_pSprite ? m_pSprite->m_pSprite->PlayAnimationByName(szAnimationName, nFlags) : false;
	}
	bool PlayAnimationByIndex(const int32 index, const uint32 nFlags, GTObject_CallbackFunction pCallback)
	{
		return m_pSprite ? m_pSprite->m_pSprite->PlayAnimationByIndex(index, nFlags, pCallback) : false;
	}
	bool PlayAnimationByIndex(const int32 index, const uint32 nFlags)
	{
		return m_pSprite ? m_pSprite->m_pSprite->PlayAnimationByIndex(index, nFlags) : false;
	}

public:
	// The state of the unit
	GT_PROPERTY_DEF_VAR_SET_GET_INT16(State);
	// The life of the unit
	GT_PROPERTY_DEF_VAR_SET_GET_INT16(Life);
	// The max life of the unit
	GT_PROPERTY_DEF_VAR_SET_GET_INT16(LifeMax);
	// The attack of the unit
	GT_PROPERTY_DEF_VAR_SET_GET_INT16(Attack);
	// The attack speed of the unit
	GT_PROPERTY_DEF_VAR_SET_GET_INT16(AttackSpeed);
	// The armor of the unit
	GT_PROPERTY_DEF_VAR_SET_GET_INT16(Armor);
	// The attack arange
	GT_PROPERTY_DEF_VAR_SET_GET_INT16(AttackRange);
	// The movement speed of the unit
	GT_PROPERTY_DEF_VAR_SET_GET_INT16(MovementSpeed);
	// The experience
	GT_PROPERTY_DEF_VAR_SET_GET_INT16(Experience);
	// The money
	GT_PROPERTY_DEF_VAR_SET_GET_INT16(Money);
	// The level
	GT_PROPERTY_DEF_VAR_SET_GET_INT16(Level);
	// The skill points
	GT_PROPERTY_DEF_VAR_SET_GET_INT16(SkillPoint);
	// The max skill points of the unit
	GT_PROPERTY_DEF_VAR_SET_GET_INT16(SkillPointMax);

	// Mian player object
	GTGameObject* m_pMainPlayer;
	BSGameObjectGeneral* m_pBSGameObjectGeneralPlayer;
	// BSSprite
	BSSprite *m_pSprite;
	// Weapon game object
	GTGameObject* m_pWeaponObject;
	BSGameObjectGeneral* m_pBSGameObjectGeneralWeapon;
	BSTweener2D* m_pBSTweener2DWeapon;
	// BSGameObjectGeneral
	BSGameObjectGeneral* m_pBSGameObjectGeneral;
	
public:
	// Animation name
	static const tchar* AnimationName_Idle;
	static const tchar* AnimationName_RunDown;
	static const tchar* AnimationName_RunLeft;
	static const tchar* AnimationName_RunRight;
	static const tchar* AnimationName_RunUp;
	static const tchar* AnimationName_AttackDownLeft;
	static const tchar* AnimationName_AttackDownRight;
	static const tchar* AnimationName_AttackUpLeft;
	static const tchar* AnimationName_AttackUpRight;
	// Status
	static const int32 State_Idle = 0;
	static const int32 State_Attack = 1;
	static const int32 State_Dying = 2;
	static const int32 State_Died = 3;
};

#endif /* _BS_UNIT_BEHAVIOUR_H_ */
