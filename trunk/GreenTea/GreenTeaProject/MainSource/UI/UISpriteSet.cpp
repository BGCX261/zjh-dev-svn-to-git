#include "UISpriteSet.h"
#include "../Sprite/GSprite.h"
#include "../GameObjectCreation.h"

UISpriteSet::UISpriteSet(void) :
	m_Position(GTVector2::Zero),
	m_bHasSprite(false)
{
	for(int32 i=0; i<UISpriteSet::StateCount; i++)
	{
		m_pSprites[i] = NULL;
	}
}


UISpriteSet::~UISpriteSet(void)
{
}


void UISpriteSet::SetPosition(const float x, const float y)
{
	for(int32 i=0; i<UISpriteSet::StateCount; i++)
	{
		if(m_pSprites[i])
		{
			m_pSprites[i]->SetPosition(x, y);
		}
	}

	m_Position = GTVector2(x, y);	
}


GTVector2 UISpriteSet::GetPosition(void) const
{
	return m_Position;
}


bool UISpriteSet::Release(void)
{
	for(int32 i=0; i<UISpriteSet::StateCount; i++)
	{
		if(m_pSprites[i])
		{
			m_pSprites[i]->Release();
			m_pSprites[i] = NULL;
		}
	}

	return true;
}


void UISpriteSet::SetScaleX(const float xs)
{
	for(int32 i=0; i<UISpriteSet::StateCount; i++)
	{
		if(m_pSprites[i])
		{
			m_pSprites[i]->SetScaleX(xs);
		}
	}
}


void UISpriteSet::SetScaleY(const float ys)
{
	for(int32 i=0; i<UISpriteSet::StateCount; i++)
	{
		if(m_pSprites[i])
		{
			m_pSprites[i]->SetScaleY(ys);
		}
	}
}


void UISpriteSet::SetScale(const float xs, const float ys)
{
	for(int32 i=0; i<UISpriteSet::StateCount; i++)
	{
		if(m_pSprites[i])
		{
			m_pSprites[i]->SetScaleX(xs);
			m_pSprites[i]->SetScaleY(ys);
		}
	}
}


// Visible
void UISpriteSet::SetVisible(bool visible, const int32 nState)
{
	DBG_ASSERT(nState < UISpriteSet::StateCount);

	for(int32 i=0; i<UISpriteSet::StateCount; i++)
	{
		if(m_pSprites[i])
		{
			m_pSprites[i]->SetVisible(false);
		}
	}
	if(m_pSprites[nState])
	{
		m_pSprites[nState]->SetVisible(visible);
	}
}


GTRect UISpriteSet::GetTextureRect(const int32 nState) const
{
	DBG_ASSERT(nState < UISpriteSet::StateCount);

	if(m_pSprites[nState])
	{
		return m_pSprites[nState]->GetTextureRect();
	}

	return GTRect::Zero;
}


void UISpriteSet::SetTextureRect(const GTRect& rect, const int32 nState)
{
	DBG_ASSERT(nState < UISpriteSet::StateCount);

	if(m_pSprites[nState])
	{
		m_pSprites[nState]->SetTextureRect(rect);
	}
}


// Set/Get AnchorPoint
//
// (0, 0) - Left-Bottom
// (1, 1) - Right-Top
// (0.5, 0.5) - Center
void UISpriteSet::SetAnchorPoint(const GTVector2& anchorPoint)
{
	for(int32 i=0; i<UISpriteSet::StateCount; i++)
	{
		if(m_pSprites[i])
		{
			m_pSprites[i]->SetAnchorPoint(anchorPoint);
		}
	}
}


GTVector2 UISpriteSet::GetAnchorPoint(void) const
{
	for(int32 i=0; i<UISpriteSet::StateCount; i++)
	{
		if(m_pSprites[i])
		{
			return m_pSprites[i]->GetAnchorPoint();
		}
	}

	return GTVector2::Zero;
}
