#ifndef _GAME_OBJECT_CREATION_H_
#define _GAME_OBJECT_CREATION_H_

#include "Sprite/GSprite.h"
#include <GTTreeNode.h>
#include <GTString.h>
#include "cocos2d.h"

class SpriteAtlas;
class UILabelBMFont;

class GameObjectCreation
{
public:
	// Create a static sprite without animations, like an image
	//
	// szFileName = <Sprite Image File Name>.png
	static GSprite* CreateStaticSprite(const tchar* szFileName, const int32 nZOrder);
	static SpriteAtlas* CreateSpriteAtlas(const tchar* szFileName, const int32 nZOrder);
	// szFileName = <Sprite Image File Name>.sprite
	static GSprite* CreateStaticSpriteWithSpriteFile(const tchar* szFileName, const int32 nZOrder);
	
	// Create an animated sprite
	//
	// szFileName = <Sprte Data File>.sprite
	static GSprite* CreateAnimatedSprite(const tchar* szFileName, const int32 nZOrder);
	static GSprite* CreateAnimatedSpriteFromTreeNode(GTTreeNode* pTreeNode, const int32 nZOrder);

	// Release a sprite object created by CreateSprite or CreateAnimatedSprite
	static bool ReleaseSprite(GSprite** ppSprite);

	// Map object
	// Load a map from the name specified
	static cocos2d::CCTMXTiledMap* LoadMap(const tchar* szName);

	// UILabelBMFont object
	static UILabelBMFont* CreateUILabelBMFont(void);
};

#endif /* _GAME_OBJECT_CREATION_H_ */
