#include "TextureCocos2d.h"

TextureCocos2d::TextureCocos2d()
{
}


TextureCocos2d::~TextureCocos2d()
{
}


// Render the sprite object at position(x,y) using original width & height.
void TextureCocos2d::Render(float x, float y)
{
}


// Render a rectangle area of the texture at position(x,y) with texture-pos(sx,sy) and width & height.
void TextureCocos2d::RenderRect(float x, float y, float sx, float sy, float w, float h)
{
}


// Render a rectangle area of the texture at position(x,y) with texture-pos(sx,sy) and width & height
// with rotation in rad, scale at H & V direction.
void TextureCocos2d::RenderRect(float x, float y, float sx, float sy, float w, float h, uint32 color, float rot, float hscale, float vscale)
{
}


// Render the sprite object at position(x,y) with rotation in rad, scale at H & V direction.
void TextureCocos2d::RenderEx(float x, float y, float rot, float hscale, float vscale)
{
}


// Render the sprite object at left-top(x1,y1) & right-bottom(x2,y2).
void TextureCocos2d::RenderStretch(float x1, float y1, float x2, float y2)
{
}


// Render the sprite object at customized four vertices, v0(x0,y0), v1(x1,y1), v2(x2,y2), v3(x3,y3).
void TextureCocos2d::Render4V(float x0, float y0, float x1, float y1, float x2, float y2, float x3, float y3)
{
}


// Get the width
float TextureCocos2d:: GetWidth() const
{
	return 0.0f;
}


// Get the height
float TextureCocos2d::GetHeight() const
{
	return 0.0f;
}


// Release the object
void TextureCocos2d::Release()
{
}
