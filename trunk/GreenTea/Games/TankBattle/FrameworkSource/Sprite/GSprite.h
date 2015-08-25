#ifndef _G_SPRITE_H_
#define _G_SPRITE_H_

#include <GTGreenTea.h>
#include "GSpriteAnimationClip.h"
#include "GSpriteAnimation.h"

class GSprite : public GTObject
{
public:
	GSprite();
	virtual ~GSprite();

	// Get animation object
	virtual GSpriteAnimation* GetAnimation() = 0;

	// Set/Get the position of the screen (left-bottom is original)
	virtual void SetPosition(const float x, const float y) = 0;
	virtual void SetPosition(const GTVector2& position) = 0;
	virtual GTPoint2 GetPosition(void) const = 0;
	// Set/Get rotation
	virtual void SetRotation(float fRotation) = 0;
	virtual float GetRotation(float fRotation) const = 0;
	// Set/Get skew
    virtual void SetSkewX(float sx) = 0;
	virtual float GetSkewX(void) const = 0;
    virtual void SetSkewY(float sy) = 0;
	virtual float GetSkewY(void) const = 0;
	// Set/Get scale
    virtual void SetScaleX(float fScaleX) = 0;
	virtual float GetScaleX(void) const = 0;
    virtual void SetScaleY(float fScaleY) = 0;
	virtual float GetScaleY(void) const = 0;
    virtual void SetScale(float fScale) = 0;
	virtual float GetScale(void) const = 0;
	// Set/Get anchor point
    virtual void SetAnchorPoint(const GTPoint2& anchor) = 0;
	virtual GTPoint2 GetAnchorPoint(void) const = 0;
	// Set/Get visible
	virtual void SetVisible(bool visible) = 0;
	virtual bool GetVisible(void) const = 0;
	// Set/Get texture rect
	virtual GTRect GetTextureRect(void) const = 0;
	virtual void SetTextureRect(const float x, const float y, const float w, const float h) = 0;
	virtual void SetTextureRect(const GTRect& rect) = 0;
	// Set/Get z-order
	virtual int32 GetZOrder(void) const = 0;
	virtual void SetZOrder(const int32 nNewZOrder) = 0;
	// Set display frame
	// nFrame = 0 to frameCount - 1
	virtual bool SetDisplayFrameByName(const tchar* szAnimName, const int32 nFrame) = 0;
	virtual bool SetDisplayFrameByIndex(const int32 nAnimIndex, const int32 nFrame) = 0;
	
	// Initialize animations
	//virtual bool InitializeAnimation(void) = 0;
	// Play an animation specified by the name
	virtual bool PlayAnimationByName(
		const tchar* szAnimationName,
		const uint32 nFlags,
		GTObject_EventCallback pCallback,
		GTObject* pCallbackThis,
		void* pCallbackParam
		) = 0;
	// Flags: GSpriteAnimation::PlayMode_Loop/GSpriteAnimation::PlayMode_Once
	virtual bool PlayAnimationByName(const tchar* szAnimationName, const uint32 nFlags) = 0;
	// Play an animation specified by its index
	virtual bool PlayAnimationByIndex(
		const int32 index,
		const uint32 nFlags,
		GTObject_EventCallback pCallback,
		GTObject* pCallbackThis,
		void* pCallbackParam
		) = 0;
	// Flags: GSpriteAnimation::PlayMode_Loop/GSpriteAnimation::PlayMode_Once
	virtual bool PlayAnimationByIndex(const int32 index, const uint32 nFlags) = 0;
	// Stop playing animations
	virtual bool StopAnimation(void) = 0;
	// Is an animatino clip being played ?
	virtual bool IsAnimationPlaying(void) = 0;
	// Is this sprite animated ?
	virtual bool IsAnimatedSprite(void) = 0;
	
	// Release the sprite object
	virtual void Release(void);

public:
	// (0.5, 0.5) - Center
	static GTVector2 AnchorPoint_Center;
	// (0, 0) - Left-Bottom
	static GTVector2 AnchorPoint_LeftBottom;
	// (0, 1) - Left-Top
	static GTVector2 AnchorPoint_LeftTop;
	// (1, 0) - Right-Bottom
	static GTVector2 AnchorPoint_RightBottom;
	// (1, 1) - Right-Top
	static GTVector2 AnchorPoint_RightTop;
};

#endif /* _G_SPRITE_H_ */
