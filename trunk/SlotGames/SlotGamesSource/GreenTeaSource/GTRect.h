#ifndef _GREENTEA_RECT_H_
#define _GREENTEA_RECT_H_

#include "GTPoint2.h"
#include "GTSize.h"

class GTRect
{
public:
	GTRect()
	{
		origin = GTPoint2(0.0f, 0.0f);
		size = GTSize(0.0f, 0.0f);
	}

	GTRect(const float x, const float y, const float width, const float height)
	{
		origin = GTPoint2(x, y);
		size = GTSize(width, height);
	}

	GTRect(const GTRect& src)
	{
		origin = src.origin;
		size = src.size;
	}
	
	GTString ToString(void)
	{
		return GTString::Format(CTEXT("(%f,%f,%f,%f)"), origin.x, origin.y, size.width, size.height);
	}

	// If pt is in this GTRect
	bool IsPointInRect(const GTVector2& pt) const
	{
		return (pt.x >= origin.x && pt.x <= (origin.x + size.width) &&
			    pt.y >= origin.y && pt.y <= (origin.y + size.height)) ?
				true :
				false;
	}

	// If anotherRect collides with the rect.
	bool Collide(const GTRect& anotherRect) const;

public:
	GTPoint2 origin;
	GTSize size;

	// GTRect zero object
	static GTRect Zero;
};

#endif /* _GREENTEA_RECT_H_ */
