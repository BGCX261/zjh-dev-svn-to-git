#ifndef _G_SPRITE_ANIMATION_COCOS2DX_H_
#define _G_SPRITE_ANIMATION_COCOS2DX_H_

#include <Sprite/GSpriteAnimation.h>
#include "GSpriteAnimationClipCocos2dx.h"
#include "cocos2d.h"
#include <GTObject.h>
#include <GTString.h>

class GSpriteAnimationCocos2dx : public GSpriteAnimation, public GTObject
{
private:
	// Clip array
	GSpriteAnimationClipCocos2dx** m_ppAnimation;
	// How many clips in the array
	int32 m_nAnimationCount;

public:
	// Key
	GTString m_strKey;
	
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
	virtual GSpriteAnimationClip* GetClipByIndex(const int32 index)
	{
		DBG_ASSERT(index >= 0 && index < m_nAnimationCount);
		DBG_ASSERT(m_ppAnimation);
		return m_ppAnimation[index];
	}	
	// Release the object
	virtual void Release();
};

#endif /* _G_SPRITE_ANIMATION_COCOS2DX_H_ */
