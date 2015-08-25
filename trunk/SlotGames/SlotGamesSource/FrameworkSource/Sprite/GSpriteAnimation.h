#ifndef _G_SPRITE_ANIMATION_H_
#define _G_SPRITE_ANIMATION_H_

#include <GTBaseDef.h>
#include "GSpriteAnimationClip.h"

class GSpriteAnimation
{
public:
	GSpriteAnimation();
	virtual ~GSpriteAnimation();

	// Get clip count
	virtual int32 GetClipCount(void) = 0;
	// Get an animation clip by its name
	virtual GSpriteAnimationClip* GetClipByName(const tchar* szName) = 0;
	// Get an animation clip by its index
	virtual GSpriteAnimationClip* GetClipByIndex(const int32 index) = 0;
	// Release the object
	virtual void Release() = 0;

public:
	static const tchar* m_sAnimationClipNameFormat;
	
	// The flags of playing animations
	static const int32 PlayMode_None = 0;
	// Play the animation forver, never stop
	static const int32 PlayMode_Loop = 1;
	// Play the animation once
	static const int32 PlayMode_Once = 2;
};

#endif /* _G_SPRITE_ANIMATION_H_ */
