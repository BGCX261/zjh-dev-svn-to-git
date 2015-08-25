#ifndef _G_SPRITE_ANIMATION_CLIP_COCOS2DX_H_
#define _G_SPRITE_ANIMATION_CLIP_COCOS2DX_H_

#include <Sprite/GSpriteAnimationClip.h>
#include <cocos2d.h>

class GSpriteAnimationClipCocos2dx : public GSpriteAnimationClip
{
	friend class GameObjectCreation;

private:
	cocos2d::CCArray* m_pAnimFrames;
	cocos2d::CCAnimation* m_pAnimation;

public:
	GSpriteAnimationClipCocos2dx();
	~GSpriteAnimationClipCocos2dx();

	// Get cocos2d::CCSpriteFrame object by its index
	cocos2d::CCSpriteFrame* GetSpriteFrameByIndex(const int32 index)
	{
		DBG_ASSERT(index >= 0);
		DBG_ASSERT(m_pAnimFrames);
		return (cocos2d::CCSpriteFrame*)(m_pAnimFrames->objectAtIndex(index));
	}

	// Get cocos2d::CCAnimation object
	cocos2d::CCAnimation* GetAnimation()
	{
		DBG_ASSERT(m_pAnimation);
		return m_pAnimation;
	}

	// Initialize m_pAnimFrames object, allocating memory for animation frames.
	bool InitializeFrame(const int32 nFrameCount);
	// Initialize m_pAnimation object
	bool InitializeAnimation();

	// Get frame counts of the clip
	virtual uint32 GetFrameCount(void)
	{
		DBG_ASSERT(m_pAnimFrames);
		return m_pAnimFrames->count();
	}

	// Release the sprite object
	virtual void Release(void);
};

#endif /* _G_SPRITE_ANIMATION_CLIP_COCOS2DX_H_ */
