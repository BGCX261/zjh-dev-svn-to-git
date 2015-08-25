#ifndef _UI_SKIN_PIECE_H_
#define _UI_SKIN_PIECE_H_

#include <GTGreenTea.h>
#include "../Sprite/GSprite.h"

class UISkinPiece
{
public:
	UISkinPiece();
	virtual ~UISkinPiece();

	void Release(void);

	void SetName(const tchar* szName)
	{
		m_sName = szName;
	}
	void SetName(const GTString& szName)
	{
		m_sName = szName;
	}
	GTString GetName(void)
	{
		return m_sName;
	}

	void SetPosition(const float x, const float y)
	{
		m_Rect.origin.x = x;
		m_Rect.origin.y = y;
	}
	void SetPosition(const GTPoint2 pos)
	{
		m_Rect.origin = pos;
	}

	void SetSize(const float width, const float height)
	{
		m_Rect.size.width = width;
		m_Rect.size.height = height;
	}
	void SetSize(const GTSize size)
	{
		m_Rect.size = size;
	}

	void SetRect(const float x, const float y, const float width, const float height)
	{
		m_Rect = GTRect(x, y, width, height);
	}
	void SetRect(const GTRect rect)
	{
		m_Rect = rect;
	}

	GTRect GetRect(void) const
	{
		return m_Rect;
	}

private:
	GTString m_sName;
	GTRect m_Rect;
};

#endif /* _UI_SKIN_PIECE_H_ */
