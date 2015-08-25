#ifndef _G_SPRITE_COCOS2DX_H_
#define _G_SPRITE_COCOS2DX_H_

#include <Sprite/GSprite.h>
#include <Sprite/GSpriteAnimation.h>
#include "cocos2d.h"

class GSpriteAnimationClipCocos2dx;

class GSpriteCocos2dx : public cocos2d::CCObject, public GSprite
{
	friend class GameObjectCreation;

public:
	// Main sprite object
	cocos2d::CCSprite* m_pSprite;
	// Animations
	GSpriteAnimation* m_pAnimation;
	// Current layer the sprite stays
	cocos2d::CCLayer* m_pLayer;
	// Current action
	cocos2d::CCAction* m_pCurrentAction;
	cocos2d::CCFiniteTimeAction* m_pCurrentSequenceActions;

public:
	GSpriteCocos2dx();
	~GSpriteCocos2dx();

	// Initialize animations
	virtual bool InitializeAnimation(void);
	// Play an animation specified by the name
	virtual bool PlayAnimationByName(const tchar* szAnimationName, const uint32 nFlags, GTObject_CallbackFunction pCallback);
	virtual bool PlayAnimationByName(const tchar* szAnimationName, const uint32 nFlags);
	// Play an animation specified by its index
	virtual bool PlayAnimationByIndex(const int32 index, const uint32 nFlags, GTObject_CallbackFunction pCallback);
	virtual bool PlayAnimationByIndex(const int32 index, const uint32 nFlags);
	// Stop playing animations
	virtual bool StopAnimation(void);
	// Is an animatino clip being played ?
	virtual bool IsAnimationPlaying(void);

	// Release the sprite object
	virtual void Release(void);

	// Play a specified clip
	bool PlayClip(GSpriteAnimationClipCocos2dx* pClip, const uint32 nFlags);
	// Once the animation clip is completed this callback is called.
	void OnAnimationCompleteCallback();

	// Get animation object
	virtual GSpriteAnimation* GetAnimation()
	{
		DBG_ASSERT(m_pAnimation);
		return m_pAnimation;
	}

	// Set/Get the position
	virtual void SetPosition(const float x, const float y)
	{
		DBG_ASSERT(m_pSprite);
		m_pSprite->setPosition(ccp(x, y));
	}
	virtual void SetPosition(const GTVector2& position)
	{
		DBG_ASSERT(m_pSprite);
		m_pSprite->setPosition(ccp(position.x, position.y));
	}
	virtual GTPoint2 GetPosition(void) const
	{
		DBG_ASSERT(m_pSprite);
		cocos2d::CCPoint pos = m_pSprite->getPosition();
		return GTPoint2(pos.x, pos.y);
	}

	// Set/Get rotation
	virtual void SetRotation(float fRotation)
	{
		DBG_ASSERT(m_pSprite);
		m_pSprite->setRotation(fRotation);
	}
	virtual float GetRotation(float fRotation) const
	{
		DBG_ASSERT(m_pSprite);
		return m_pSprite->getRotation();
	}

	// Set/Get skew
	virtual void SetSkewX(float sx)
	{
		DBG_ASSERT(m_pSprite);
		m_pSprite->setSkewX(sx);
	}
	virtual float GetSkewX(void) const
	{
		DBG_ASSERT(m_pSprite);
		return m_pSprite->getSkewX();
	}
    virtual void SetSkewY(float sy)
	{
		DBG_ASSERT(m_pSprite);
		m_pSprite->setSkewY(sy);
	}
	virtual float GetSkewY() const
	{
		DBG_ASSERT(m_pSprite);
		return m_pSprite->getSkewY();
	}

	// Set/Get scale
    virtual void SetScaleX(float fScaleX)
	{
		DBG_ASSERT(m_pSprite);
		m_pSprite->setScaleX(fScaleX);
	}
	virtual float GetScaleX(void) const
	{
		DBG_ASSERT(m_pSprite);
		return m_pSprite->getScaleX();
	}
    virtual void SetScaleY(float fScaleY)
	{
		DBG_ASSERT(m_pSprite);
		m_pSprite->setScaleY(fScaleY);
	}
	virtual float GetScaleY(void) const
	{
		DBG_ASSERT(m_pSprite);
		return m_pSprite->getScaleY();
	}
    virtual void SetScale(float fScale)
	{
		DBG_ASSERT(m_pSprite);
		m_pSprite->setScale(fScale);
	}
	virtual float GetScale(void) const
	{
		DBG_ASSERT(m_pSprite);
		return m_pSprite->getScale();
	}

	// Set/Get anchor point
    virtual void SetAnchorPoint(const GTPoint2& anchor)
	{
		DBG_ASSERT(m_pSprite);
		return m_pSprite->setAnchorPoint(cocos2d::CCPoint(anchor.x, anchor.y));
	}	
	virtual GTPoint2 GetAnchorPoint(void) const
	{
		DBG_ASSERT(m_pSprite);
		cocos2d::CCPoint pt = m_pSprite->getAnchorPoint();
		return GTPoint2(pt.x, pt.y);
	}

	// Set/Get visible
	virtual void SetVisible(bool visible)
	{
		DBG_ASSERT(m_pSprite);
		m_pSprite->setVisible(visible);
	}
	virtual bool GetVisible(void) const
	{
		DBG_ASSERT(m_pSprite);
		return false;
	}

	// Set/Get texture rect
	virtual GTRect GetTextureRect(void) const
	{
		DBG_ASSERT(m_pSprite);
		cocos2d::CCRect rect = m_pSprite->getTextureRect();
		return GTRect(rect.origin.x, rect.origin.y, rect.size.width, rect.size.height);
	}
	virtual void SetTextureRect(const float x, const float y, const float w, const float h)
	{
		DBG_ASSERT(m_pSprite);
		m_pSprite->setTextureRect(cocos2d::CCRect(x, y, w, h));
	}
	virtual void SetTextureRect(const GTRect& rect)
	{
		DBG_ASSERT(m_pSprite);
		m_pSprite->setTextureRect(cocos2d::CCRect(rect.origin.x, rect.origin.y, rect.size.width, rect.size.height));
	}

protected:
	// Callback for playing animation clip
	GTObject_CallbackFunction m_pCallbackForAnimationCompletion;
};

#endif /* _G_SPRITE_COCOS2DX_H_ */
