#ifndef _BS_PLAYER_CONTROLLER_H_
#define _BS_PLAYER_CONTROLLER_H_

#include <GTGreenTea.h>
#include "BSSprite.h"
#include "BSPathFinding.h"
#include "BSPlayerPlayingUI.h"
#include "BSUnitBehaviour.h"
#include "BSEndPosition.h"
#include "GameObjectSprite.h"

class BSSpriteMovement;

class BSPlayerController : public GTBehaviour
{
public:
	GTBEHAVIOUR_DEF(BSPlayerController, GTBehaviour);

public:
	BSPlayerController();
	virtual ~BSPlayerController();

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
	virtual void OnCollisionEnter(GTGameObject* pGameObject);
	virtual void OnCollisionExit(GTGameObject* pGameObject);
	virtual void OnCollisionStay(GTGameObject* pGameObject);
	
	// On HP change
	void OnChangeHP(const int16 nChange);

	// Once single-click event occurs, this callback is called.
	static int32 OnSingleClickEventDelegate(const uint32 Flags, const GTPoint2 point, void* pParam);

private:
	// Get required GTBehaviour from pGameObject
	GTBehaviour* GetGTBehaviourFromGameObject(GTGameObject* pGameObject);
	void OnCollisionBSUnitBehaviour(BSUnitBehaviour* pBehaviour);
	void OnCollisionBSEndPosition(BSEndPosition* pBehaviour);

private:
	// Sprite
	GameObjectSprite* m_pGameObjectSprite;
	// BSPathFinding
	BSPathFinding *m_pPathFinding;
	// BSSpriteMovement
	BSSpriteMovement *m_pSpriteMovement;
	// BSPlayerPlayingUI
	BSPlayerPlayingUI *m_pBSPlayerPlayingUI;

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
	GT_PROPERTY_DEF_VAR_SET_GET_INT32(Experience);
	// The experience for next level
	GT_PROPERTY_DEF_VAR_SET_GET_INT32(ExperienceForNextLevel);
	// The money
	GT_PROPERTY_DEF_VAR_SET_GET_INT32(Money);
	// The level
	GT_PROPERTY_DEF_VAR_SET_GET_INT16(Level);
	// The skill points
	GT_PROPERTY_DEF_VAR_SET_GET_INT16(SkillPoint);
	// The max skill points of the unit
	GT_PROPERTY_DEF_VAR_SET_GET_INT16(SkillPointMax);

public:
	// Main player name
	static const tchar* m_szMainPlayName;
};

#endif /* _BS_PLAYER_CONTROLLER_H_ */
