#include "TextureAtlasCocos2dx.h"
#include "cocos2d.h"

TextureAtlasCocos2dx::TextureAtlasCocos2dx():
	m_pCCTextureAtlas(NULL)
{
}


TextureAtlasCocos2dx::~TextureAtlasCocos2dx()
{
}


// Initialize texture atlas with a texture and property file
bool TextureAtlasCocos2dx::Initialize(const tchar* szTextureFileName,
									  const tchar* szPropertyFileName)
{
	if(NULL == szTextureFileName ||
	   NULL == szPropertyFileName)
	{
		return false;
	}

	const uint32 capacity = 32;
	cocos2d::CCTexture2D *pTexture2D = cocos2d::CCTextureCache::sharedTextureCache()->addImage(szTextureFileName);
	if(NULL == pTexture2D)
	{
		return false;
	}

	m_pCCTextureAtlas = new cocos2d::CCTextureAtlas();
	m_pCCTextureAtlas->initWithTexture(pTexture2D, capacity);

	return true;
}

	
// Destroy
bool TextureAtlasCocos2dx::Release(void)
{
	if(m_pCCTextureAtlas)
	{
		CC_SAFE_RELEASE(m_pCCTextureAtlas);
		m_pCCTextureAtlas = NULL;
	}

	return true;
}
