#ifndef _G_SPRITE_ANIMATION_CLIP_H_
#define _G_SPRITE_ANIMATION_CLIP_H_

#include <GTBaseDef.h>

class GSpriteAnimationClip
{
public:
	GSpriteAnimationClip();
	virtual ~GSpriteAnimationClip();

	// Get animation clip name
	const tchar* GetClipName() const
	{
		return m_sClipName;
	}

	// Set animation clip name
	void SetClipName(const tchar* szName)
	{
		StringCopy(m_sClipName, szName);
	}

	// Set frame delay time
	void SetFrameDelayTime(const float fTime)
	{
		m_fFrameDelayTime = fTime;
	}

	// Get frame delay time
	float GetFrameDelayTime()
	{
		return m_fFrameDelayTime;
	}

	// Release the object
	virtual void Release() = 0;

private:
	// Animation clip name
	tchar m_sClipName[64];
	// Frame delay time
	float m_fFrameDelayTime;
};

#endif /* _G_SPRITE_ANIMATION_CLIP_H_ */
