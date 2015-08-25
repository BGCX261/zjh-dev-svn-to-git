#ifndef _G_SPRITE_ANIMATION_COCOS2DX_H_
#define _G_SPRITE_ANIMATION_COCOS2DX_H_

#include <Sprite/GSpriteAnimation.h>
#include "GSpriteAnimationClipCocos2dx.h"
#include "cocos2d.h"

class GSpriteAnimationCocos2dx : public GSpriteAnimation
{
private:
	GSpriteAnimationClipCocos2dx** m_ppAnimation;
	int32 m_nAnimationCount;
	
public:
	GSpriteAnimationCocos2dx();
	~GSpriteAnimationCocos2dx();

	// Initialize the animatons
	bool Initialize(const int32 nAnimationCount);
	// Get clip count
	virtual int32 GetClipCount(void)
	{
		return m_nAnimationCount;
	}
	// Get an animation clip by its name
	virtual GSpriteAnimationClip* GetClipByName(const tchar* szName);
	// Get an animation clip by its index
	virtual GSpriteAnimationClipCocos2dx* GetClipByIndex(const int32 index)
	{
		DBG_ASSERT(index >= 0 && index < m_nAnimationCount);
		DBG_ASSERT(m_ppAnimation);
		return m_ppAnimation[index];
	}	
	// Release the object
	virtual void Release();
};

#endif /* _G_SPRITE_ANIMATION_COCOS2DX_H_ */
