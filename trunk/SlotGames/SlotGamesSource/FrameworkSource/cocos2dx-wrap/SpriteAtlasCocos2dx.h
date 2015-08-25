#ifndef _SPRITE_ATLAST_COCOS2DX_H_
#define _SPRITE_ATLAST_COCOS2DX_H_

#include "../Common/SpriteAtlas.h"
#include <layers_scenes_transitions_nodes/CCLayer.h>
#include <sprite_nodes/CCSpriteBatchNode.h>

class SpriteAtlasCocos2dx : public SpriteAtlas
{
public:
	SpriteAtlasCocos2dx();
	virtual ~SpriteAtlasCocos2dx();

	// Initialize texture atlas with a texture and property file
	virtual bool Initialize(const tchar* szFileName, const int32 nZOrder);
	// Add a sprite
	virtual GSprite* AddSprite(const float tx, const float ty, const float tw, const float th);
	virtual GSprite* AddSprite(const GTRect rect);
	// Remove a sprite
	virtual bool RemoveSprite(GSprite* pSprite);
	// Destroy
	virtual bool Release(void);

public:
	// CCSpriteBatchNode object
	cocos2d::CCSpriteBatchNode* m_pCCSpriteBatchNode;
	// Current layer the sprite stays
	cocos2d::CCLayer* m_pLayer;
};

#endif /* _SPRITE_ATLAST_COCOS2DX_H_ */
