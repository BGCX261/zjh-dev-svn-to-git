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
	/*
	// Animation strings
	static tchar* m_sAnimationClipNameUp;
	static tchar* m_sAnimationClipNameDown;
	static tchar* m_sAnimationClipNameLeft;
	static tchar* m_sAnimationClipNameRight;
	*/
	static const tchar* m_sAnimationClipNameFormat;
	// Animation clip count
	//static int32 m_nAnimationClipCount;
	
	// The flags of playing animations
	// Play the animation forver, never stop
	static const int32 PlayMode_Loop = 0;
	// Play the animation once
	static const int32 PlayMode_Once = 1;
};

#endif /* _G_SPRITE_ANIMATION_H_ */
