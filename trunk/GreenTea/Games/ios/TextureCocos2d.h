#ifndef _TEXTURE_COCOS2D_H_
#define _TEXTURE_COCOS2D_H_

#include "BaseDef.h"
#include "ITexture2D.h"
//#import "cocos2d.h"

class TextureCocos2d : public ITexture2D
{
public:
	TextureCocos2d();
	~TextureCocos2d();
	
	// Render the sprite object at position(x,y) using original width & height.
	virtual void Render(float x, float y);
	// Render a rectangle area of the texture at position(x,y) with texture-pos(sx,sy) and width & height.
	virtual void RenderRect(float x, float y, float sx, float sy, float w, float h);
	// Render a rectangle area of the texture at position(x,y) with texture-pos(sx,sy) and width & height
	// with rotation in rad, scale at H & V direction.
	virtual void RenderRect(float x, float y, float sx, float sy, float w, float h, uint32 color, float rot, float hscale, float vscale);
	// Render the sprite object at position(x,y) with rotation in rad, scale at H & V direction.
	virtual void RenderEx(float x, float y, float rot, float hscale, float vscale);
	// Render the sprite object at left-top(x1,y1) & right-bottom(x2,y2).
	virtual void RenderStretch(float x1, float y1, float x2, float y2);
	// Render the sprite object at customized four vertices, v0(x0,y0), v1(x1,y1), v2(x2,y2), v3(x3,y3).
	virtual void Render4V(float x0, float y0, float x1, float y1, float x2, float y2, float x3, float y3);

	// Get the width
	virtual float GetWidth() const;
	// Get the height
	virtual float GetHeight() const;

	// Release the object
	virtual void Release();
	
public:
	// cocos2d sprite object
	//CCSprite* m_pSprite;
};

#endif
