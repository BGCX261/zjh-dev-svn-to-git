#include <GTBaseDef.h>
#include "GSprite.h"

// (0.5, 0.5) - Center
GTVector2 GSprite::AnchorPoint_Center = GTVector2(0.5f, 0.5f);
// (0, 0) - Left-Bottom
GTVector2 GSprite::AnchorPoint_LeftBottom = GTVector2(0.0f, 0.0f);
// (0, 1) - Left-Top
GTVector2 GSprite::AnchorPoint_LeftTop = GTVector2(0.0f, 1.0f);
// (1, 0) - Right-Bottom
GTVector2 GSprite::AnchorPoint_RightBottom = GTVector2(1.0f, 0.0f);
// (1, 1) - Right-Top
GTVector2 GSprite::AnchorPoint_RightTop = GTVector2(1.0f, 1.0f);

GSprite::GSprite()
{
}

GSprite::~GSprite()
{
}


void GSprite::Release(void)
{
	//GTObject::Release();
}
