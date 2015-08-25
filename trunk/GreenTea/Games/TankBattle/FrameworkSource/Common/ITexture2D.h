#ifndef _I_TEXTURE_2D_H_
#define _I_TEXTURE_2D_H_

#include <GTBaseDef.h>

class ITexture2D
{
public:
	// Render the sprite object at position(x,y) using original width & height.
	virtual void Render(float x, float y) = 0;
	// Render a rectangle area of the texture at position(x,y) with texture-pos(sx,sy) and width & height.
	virtual void RenderRect(float x, float y, float sx, float sy, float w, float h) = 0;
	// Render a rectangle area of the texture at position(x,y) with texture-pos(sx,sy) and width & height
	// with rotation in rad, scale at H & V direction.
	virtual void RenderRect(float x, float y, float sx, float sy, float w, float h, uint32 color, float rot, float hscale, float vscale) = 0;
	// Render the sprite object at position(x,y) with rotation in rad, scale at H & V direction.
	virtual void RenderEx(float x, float y, float rot, float hscale, float vscale) = 0;
	// Render the sprite object at left-top(x1,y1) & right-bottom(x2,y2).
	virtual void RenderStretch(float x1, float y1, float x2, float y2) = 0;
	// Render the sprite object at customized four vertices, v0(x0,y0), v1(x1,y1), v2(x2,y2), v3(x3,y3).
	virtual void Render4V(float x0, float y0, float x1, float y1, float x2, float y2, float x3, float y3) = 0;

	// Get the width
	virtual float GetWidth() const = 0;
	// Get the height
	virtual float GetHeight() const = 0;

	// Release the object
	virtual void Release() = 0;
};

#endif /* _I_TEXTURE_2D_H_ */
