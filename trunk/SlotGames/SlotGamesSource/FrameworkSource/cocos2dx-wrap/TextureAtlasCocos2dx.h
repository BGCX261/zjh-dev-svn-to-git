#ifndef _TEXTURE_ATLAS_COCOS2DX_H_
#define _TEXTURE_ATLAS_COCOS2DX_H_

#include "../Common/TextureAtlas.h"
#include <textures/CCTextureAtlas.h>

class CCTextureAtlas;

class TextureAtlasCocos2dx : public TextureAtlas
{
public:
	TextureAtlasCocos2dx();
	virtual ~TextureAtlasCocos2dx();

	// Initialize texture atlas with a texture and property file
	virtual bool Initialize(const tchar* szTextureFileName, const tchar* szPropertyFileName);
	// Destroy
	virtual bool Release(void);

public:
	// cocos2d-x CCTextureAtlas object
	cocos2d::CCTextureAtlas* m_pCCTextureAtlas;
};

#endif /* _TEXTURE_ATLAS_COCOS2DX_H_ */
