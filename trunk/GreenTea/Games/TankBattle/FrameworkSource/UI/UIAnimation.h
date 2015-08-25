#ifndef _UI_ANIMATION_H_
#define _UI_ANIMATION_H_

#include "UIWidget.h"
#include "UIWidgetSprite.h"

class UIAnimation : public UIWidgetSprite
{
public:
	UIWIDGET_DEF(UIAnimation, UIWidget)

public:
	UIAnimation();
	UIAnimation(UIWidget* pParent);
	virtual ~UIAnimation();

public:
	// Override this method to serialize specific properties
	virtual bool OnSerializeTo(GTTreeNode* pTreeNode);
	// Override this method to serialize specific properties
	virtual bool OnSerializeFrom(GTTreeNode* pTreeNode);
	// OnChangeZOrder is called when the the object is set with new z-order.
	virtual void OnChangeZOrder(const int32 nNewZOrder);

	// When the object is initialized, this method is called.
	virtual int32 OnInitialize(void);

	// When the system is updated, this method is called for each frame.
	virtual int32 OnUpdate(void);

	// This method is called for rendering each frame.
	virtual int32 OnRender(void);

	// Before the system is shut down, this method is called.
	virtual int32 OnDestroy(void);

	// Override GTObject::Release to do more things
	virtual void Release(void);

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
};

#endif /* _UI_ANIMATION_H_ */
