#ifndef _SPRITE_ATLAST_H_
#define _SPRITE_ATLAST_H_

#include <GTGreenTea.h>

class GSprite;

class SpriteAtlas
{
public:
	SpriteAtlas();
	virtual ~SpriteAtlas();

	// Initialize texture atlas with a texture and property file
	virtual bool Initialize(const tchar* szFileName, const int32 nZOrder) = 0;
	// Add a sprite
	virtual GSprite* AddSprite(const float tx, const float ty, const float tw, const float th) = 0;
	virtual GSprite* AddSprite(const GTRect rect) = 0;
	// Remove a sprite
	virtual bool RemoveSprite(GSprite* pSprite) = 0;
	// Destroy
	virtual bool Release(void) = 0;
};

#endif /* _SPRITE_ATLAST_H_ */
