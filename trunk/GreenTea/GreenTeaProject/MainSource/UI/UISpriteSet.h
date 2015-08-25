#ifndef _UI_SPRITE_SET_H_
#define _UI_SPRITE_SET_H_

#include <GTGreenTea.h>

class GSprite;

class UISpriteSet
{
public:
	// State
	static const int32 StateEnabled = 0;
	static const int32 StateDisabled = 1;
	static const int32 StatePressed = 2;
	static const int32 StateCount = 3;

public:
	UISpriteSet(void);
	~UISpriteSet(void);

	// Set/Get the position
	void SetPosition(const float x, const float y);
	void SetPosition(const GTVector2& pos)
	{
		SetPosition(pos.x, pos.y);
	}
	GTVector2 GetPosition(void) const;
	// Release
	bool Release(void);
	// Set/Get a sprite
	void SetSprite(GSprite* pSprite, const int32 nState)
	{
		DBG_ASSERT(nState < UISpriteSet::StateCount);
		m_pSprites[nState] = pSprite;
		m_bHasSprite = true;
	}
	GSprite* GetSprite(const int32 nState)
	{
		DBG_ASSERT(nState < UISpriteSet::StateCount);
		return m_pSprites[nState];
	}
	// Is there any sprite available ?
	bool HasSprite(void) const
	{
		return m_bHasSprite;
	}

	// Sacle
	void SetScaleX(const float xs);
	void SetScaleY(const float ys);
	void SetScale(const float xs, const float ys);
	// Visible
	void SetVisible(bool visible, const int32 nState);
	// Set/Get texture rect
	GTRect GetTextureRect(const int32 nState) const;
	void SetTextureRect(const GTRect& rect, const int32 nState);
	// Set/Get AnchorPoint
	//
	// (0, 0) - Left-Bottom
	// (1, 1) - Right-Top
	// (0.5, 0.5) - Center
	void SetAnchorPoint(const GTVector2& anchorPoint);
	GTVector2 GetAnchorPoint(void) const;

protected:
	// Sprite array
	GSprite* m_pSprites[UISpriteSet::StateCount];
	// Sprite position
	GTVector2 m_Position;
	// Does the sprite array have available sprite ?
	bool m_bHasSprite;
};

#endif /* _UI_SPRITE_SET_H_ */
