#ifndef _GAME_OBJECT_CREATION_H_
#define _GAME_OBJECT_CREATION_H_

#include "../main/GSprite.h"
#include "cocos2d.h"

class GameObjectCreationCocos2dx
{
public:
	// Sprite object
	static GSprite* CreateSprite(const tchar* szFileName, cocos2d::CCLayer *pLayer, int32 order);
	static bool ReleaseSprite(GSprite** ppSprite);
};

#endif /* _GAME_OBJECT_CREATION_H_ */
