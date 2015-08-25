#ifndef _GAMEOBJECT_SPRITE_H_
#define _GAMEOBJECT_SPRITE_H_

#include <GTGameObject.h>
#include <GTGameObjectClassManager.h>
#include <Sprite/GSprite.h>

class GameObjectSprite : public GTGameObject
{
public:
	GTGAMEOBJECT_DEF(GameObjectSprite, GTGameObject)

public:
	GameObjectSprite();
	GameObjectSprite(GTGameObject* pParent);
	virtual ~GameObjectSprite();

public:
	// Copy
	virtual bool Copy(GTObject* pObjectFrom);
	// This method is called when GTGameObject object is created (memory allocation).
	virtual int32 OnCreate(void);
	// Override this method to serialize specific properties
	//virtual bool OnSerializeTo(GTTreeNode* pTreeNode);
	// Override this method to serialize specific properties
	//virtual bool OnSerializeFrom(GTTreeNode* pTreeNode);
	// When the object is initialized, this method is called.
	// param - the parameter passed to this game object
	// param->pParam1 - the root GTTreeNode
	// param->pParam2 - the tree node under this game object
	virtual int32 OnInitialize(GTGameObjectInit* param);
	// The OnStart function is called after all OnCreated functions on all script instances have been called.
	virtual int32 OnStart(void);
	// When the system is updated, this method is called for each frame.
	virtual int32 OnUpdate(void);
	// This method is called for rendering each frame.
	virtual int32 OnRender(void);
	// Before the system is shut down, this method is called.
	virtual int32 OnDestroy(void);
	// Override Release to do more things
	virtual void Release(void);
	// If the object needs to be rebuilt
	virtual void OnDirty(void);
	// OnVisible is called when the the object is set visible.
	virtual void OnVisible(GTGameObject *pCaller, bool bApplyForChildren);
	// OnInvisible is called when the the object is set invisible.
	virtual void OnInvisible(GTGameObject *pCaller, bool bApplyForChildren);
	// This function is called when the behaviour becomes disabled or inactive.
	virtual void OnDisable(void);
	// This function is called when the object becomes enabled and active.
	virtual void OnEnable(void);
	// OnChangeZOrder is called when the the object is set with new z-order.
	virtual void OnChangeZOrder(const int32 nNewZOrder);
	// OnChangePosition is called when the the object is set with new position.
	virtual void OnChangePosition(const GTPoint2 position);

	/*
	// Set position
	virtual void SetPosition(const float x, const float y)
	{
		GTGameObject::SetPosition(x, y);
		if(m_pSprite)
			m_pSprite->SetPosition(x, y);
	}
	virtual void SetPosition(const GTPoint2 position)
	{
		GTGameObject::SetPosition(position);
		if(m_pSprite)
			m_pSprite->SetPosition(position);
	}
	// Get position
	virtual GTPoint2 GetPosition(void) const
	{
		return GTGameObject::GetPosition();
	}
	*/

	/*
	// If this game object needs to be rebuilt
	virtual void SetDirty(void)
	{
		GTGameObject::SetDirty();
	}

	// Z-Order
	virtual void SetZOrder(const int32 nZOrder)
	{
		GTGameObject::SetZOrder(nZOrder);
		if(m_pSprite)
			m_pSprite->SetZOrder(nZOrder);
	}
	virtual int32 GetZOrder(void) const
	{
		DBG_ASSERT(m_pSprite);
		return m_pSprite->GetZOrder();
	}
	*/

	/*
	// Set/Get visible
	virtual void SetVisible(bool visible)
	{
		GTGameObject::SetVisible(visible);
		if(m_pSprite)
			m_pSprite->SetVisible(visible);
	}
	virtual bool GetVisible(void) const
	{
		return GTGameObject::GetVisible();
	}
	*/

	// Set/Get scale
	virtual void SetScaleX(float fScaleX)
	{
		DBG_ASSERT(m_pSprite);
		m_pSprite->SetScaleX(fScaleX);
	}
	virtual float GetScaleX(void) const
	{
		DBG_ASSERT(m_pSprite);
		return m_pSprite->GetScaleX();
	}
    virtual void SetScaleY(float fScaleY)
	{
		DBG_ASSERT(m_pSprite);
		m_pSprite->SetScaleY(fScaleY);
	}
	virtual float GetScaleY(void) const
	{
		DBG_ASSERT(m_pSprite);
		return m_pSprite->GetScaleY();
	}
    virtual void SetScale(float fScale)
	{
		DBG_ASSERT(m_pSprite);
		m_pSprite->SetScale(fScale);
	}
	virtual float GetScale(void) const
	{
		DBG_ASSERT(m_pSprite);
		return m_pSprite->GetScale();
	}

	void SetScale(const GTVector2& scale)
	{
		DBG_ASSERT(m_pSprite);
		m_pSprite->SetScaleX(scale.x);
		m_pSprite->SetScaleX(scale.y);
	}

	// Set/Get texture rect
	virtual GTRect GetTextureRect(void) const
	{
		DBG_ASSERT(m_pSprite);
		return m_pSprite->GetTextureRect();
	}

	// Help methods

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
	bool IsAnimationPlaying()
	{
		DBG_ASSERT(m_pSprite);
		return m_pSprite->IsAnimationPlaying();
	}
	// Stop playing current animation
	bool StopAnimation()
	{
		DBG_ASSERT(m_pSprite);
		return m_pSprite->StopAnimation();
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

public:
	// The sprite object
	GSprite* m_pSprite;
};

#endif /* _GAMEOBJECT_SPRITE_H_ */
