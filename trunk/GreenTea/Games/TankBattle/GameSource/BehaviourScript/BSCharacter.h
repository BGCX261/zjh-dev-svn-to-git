#ifndef _BS_CHARACTER_H_
#define _BS_CHARACTER_H_

#include <GTBehaviour.h>
#include <GTTreeNode.h>
#include <GameObjectSprite.h>

class BSCharacter : public GTBehaviour
{
public:
	GTBEHAVIOUR_DEF(BSCharacter, GTBehaviour);

public:
	BSCharacter();
	virtual ~BSCharacter();

	// This method is called when GTBehaviour object is created.
	virtual int32 OnCreate(void);
	// This method is called when GTBehaviour object is initialized.
	virtual int32 OnInitialize(GTBehaviourInit* param);
	// OnStart is called just before any of the OnUpdate methods is called the first time.
	virtual int32 OnStart(void);
	// This method is called when GTBehaviour object is updated.
	virtual int32 OnUpdate(void);
	// This method is called when GTBehaviour object is destroyed.
	virtual int32 OnDestroy(void);
	// If this GTBehaviour needs to be rebuilt
	virtual void OnDirty(void);
	// OnVisible is called when the the object is set visible.
	virtual void OnVisible(void);
	// OnVisible is called when the the object is set invisible.
	virtual void OnInvisible(void);
	// OnChangeZOrder is called when the the object is set with new z-order.
	virtual void OnChangeZOrder(const int32 nNewZOrder);
	// Copy
	virtual bool Copy(GTObject* pObjectFrom);

	// Update for status
	virtual void OnUpdateStatusIdle(void);
	virtual void OnUpdateStatusMoving(void);
	virtual void OnUpdateStatusAttack(void);
	virtual void OnUpdateStatusDying(void);
	virtual void OnUpdateStatusDied(void);

	void OnUpdatePost(void);

	// Create the sprite from the property tree node
	bool CreateFromPropertyTreeNode(GTTreeNode *pTreeNode);

	// Get the sprite object
	GameObjectSprite* GetSpriteObject(void)
	{
		return m_pGameObjectSprite;
	}
		
	/*
	// Play an animation by index
	// Flags = GSpriteAnimation::PlayMode_Loop/GSpriteAnimation::PlayMode_Once
	bool PlayAnimationByIndex(const uint32 index, const uint32 nFlags)
	{
		DBG_ASSERT(m_pSprite);
		return m_pSprite->PlayAnimationByIndex(index, nFlags);
	}
	bool PlayAnimationByIndex(
		const int32 index,
		const uint32 nFlags,
		GTObject_EventCallback pCallback,
		GTObject* pCallbackThis,
		void* pCallbackParam
		)
	{
		DBG_ASSERT(m_pSprite);
		return m_pSprite->PlayAnimationByIndex(index, nFlags, pCallback, pCallbackThis, pCallbackParam);
	}
	// Play an animation by name
	// Flags = GSpriteAnimation::PlayMode_Loop/GSpriteAnimation::PlayMode_Once
	bool PlayAnimationByName(const tchar* szName, const uint32 nFlags)
	{
		DBG_ASSERT(m_pSprite);
		return m_pSprite->PlayAnimationByName(szName, nFlags);
	}
	bool PlayAnimationByName(
		const tchar* szAnimationName,
		const uint32 nFlags,
		GTObject_EventCallback pCallback,
		GTObject* pCallbackThis,
		void* pCallbackParam
		)
	{
		DBG_ASSERT(m_pSprite);
		return m_pSprite->PlayAnimationByName(szAnimationName, nFlags, pCallback, pCallbackThis, pCallbackParam);
	}
	// Stop playing current animation
	bool StopAnimation()
	{
		DBG_ASSERT(m_pSprite);
		return m_pSprite->StopAnimation();
	}
	int32 GetZOrder(void) const
	{
		DBG_ASSERT(m_pSprite);
		return m_pSprite->GetZOrder();
	}
	void SetZOrder(const int32 nNewZOrder)
	{
		DBG_ASSERT(m_pSprite);
		return m_pSprite->SetZOrder(nNewZOrder);
	}
	void SetVisible(bool visible)
	{
		DBG_ASSERT(m_pSprite);
		return m_pSprite->SetVisible(visible);
	}
	bool GetVisible(void) const
	{
		DBG_ASSERT(m_pSprite);
		return m_pSprite->GetVisible();
	}
	// Set display frame
	// nFrame = 0 to frameCount - 1
	bool SetDisplayFrameByName(const tchar* szAnimName, const int32 nFrame)
	{
		DBG_ASSERT(m_pSprite);
		return m_pSprite->SetDisplayFrameByName(szAnimName, nFrame);
	}
	// nFrame = 0 to frameCount - 1
	bool SetDisplayFrameByIndex(const int32 nAnimIndex, const int32 nFrame)
	{
		DBG_ASSERT(m_pSprite);
		return m_pSprite->SetDisplayFrameByIndex(nAnimIndex, nFrame);
	}
	*/

public:	
	// Properties
	// The state of the unit
	GT_PROPERTY_DEF_VAR_SET_GET_INT16(Status);
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
	// The movement speed of the unit in pixels/second
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
	// The sprite object
	GameObjectSprite *m_pGameObjectSprite;

protected:
	// Time
	long m_lPrevTime;
	long m_lDeltaTime;

public:
	// Animation name
	static const tchar* AnimationName_Idle;
	static const tchar* AnimationName_MoveDown;
	static const tchar* AnimationName_MoveLeft;
	static const tchar* AnimationName_MoveRight;
	static const tchar* AnimationName_MoveUp;
	static const tchar* AnimationName_AttackDownLeft;
	static const tchar* AnimationName_AttackDownRight;
	static const tchar* AnimationName_AttackUpLeft;
	static const tchar* AnimationName_AttackUpRight;
	// Status
	static const int16 StatusIdle = 0;
	static const int16 StatusMoving = 1;
	static const int16 StatusAttack = 2;
	static const int16 StatusDying = 3;
	static const int16 StatusDied = 4;
};

#endif /* _BS_SPRITE_H_ */
