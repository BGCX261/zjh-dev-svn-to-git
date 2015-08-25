#ifndef _BS_SPRITE_BASE_H_
#define _BS_SPRITE_BASE_H_

#include <GTBehaviour.h>
#include <GTTreeNode.h>
#include "../Sprite/GSprite.h"

class BSSpriteBase : public GTBehaviour
{
public:
	GTBEHAVIOUR_DEF(BSSpriteBase, GTBehaviour);

public:
	BSSpriteBase();
	virtual ~BSSpriteBase();

	// This method is called when GTBehaviour object is created.
	virtual int32 OnCreate(void);
	// This method is called when GTBehaviour object is initialized.
	virtual int32 OnInitialize(GTBehaviourInitParam* param);
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
	bool Copy(GTObject* pObjectFrom);

	// Create the sprite from the property tree node
	bool CreateFromPropertyTreeNode(GTTreeNode *pTreeNode);

	// Get the sprite object
	GSprite* GetSpriteObject(void)
	{
		return m_pSprite;
	}

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

public:
	// The sprite object
	GSprite* m_pSprite;
};

#endif /* _BS_SPRITE_BASE_H_ */
