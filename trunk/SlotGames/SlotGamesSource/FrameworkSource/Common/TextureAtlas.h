#ifndef _TEXTURE_ATLAS_H_
#define _TEXTURE_ATLAS_H_

#include <GTGreenTea.h>

class TextureAtlas
{
public:
	TextureAtlas();
	virtual ~TextureAtlas();

	// Initialize texture atlas with a texture and property file
	virtual bool Initialize(const tchar* szTextureFileName, const tchar* szPropertyFileName) = 0;
	// Destroy
	virtual bool Release(void) = 0;
	//
	//virtual bool AddQuad(
};

#endif /* _TEXTURE_ATLAS_H_ */
