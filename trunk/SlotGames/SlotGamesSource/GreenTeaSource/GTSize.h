#ifndef _GREENTEA_SIZE_H_
#define _GREENTEA_SIZE_H_

#include "GTString.h"

class GTSize
{
public:
	GTSize()
	{
		width = 0.0f;
		height = 0.0f;
	}
		
	GTSize(const float w, const float h)
	{
		width = w;
		height = h;
	}

	GTSize(const GTSize& src)
	{
		width = src.width;
		height = src.height;
	}

	GTString ToString(void)
	{
		return GTString::Format(CTEXT("(%f,%f)"), width, height);
	}

	// ==
	bool operator == (const GTSize& b) const
	{
		return (b.width==width && b.height==height);
	}

	// !=
	bool operator != (const GTSize& b) const
	{
		return (!(b == (*this)));
	}

	// -
	const GTSize operator - () const
	{
		return GTSize(-width, -height);
	}

	// =
	const GTSize operator = (const GTSize& b)
	{
		width = b.width;
		height = b.height;

		return (*this);
	}

	// +
	const GTSize operator + (const float& f) const
	{
		return GTSize(width + f, height + f);
	}

	// -
	const GTSize operator - (const float& f) const
	{
		return GTSize(width - f, height - f);
	}

	// *
	const GTSize operator * (const float& f) const
	{
		return GTSize(width * f, height * f);
	}

	// /
	const GTSize operator / (const float& f) const
	{
		return GTSize(width/f, height/f);
	}

	// +=
	const GTSize& operator += (const float& f)
	{
		width += f;
		height += f;

		return (*this);
	}

	// -=
	const GTSize& operator -= (const float& f)
	{
		width -= f;
		height -= f;

		return (*this);
	}

	// *=
	const GTSize& operator *= (const float& f)
	{
		width *= f;
		height *= f;

		return (*this);
	}

	// /=
	const GTSize& operator /= (const float& f)
	{
		width /= f;
		height /= f;

		return (*this);
	}

	//----------------------------------------------
	// Format from a string: width height
	// Sample: 120 345
	//----------------------------------------------
	static GTSize Parse(const GTString& source);

public:
	float width;
	float height;

	// Zero object
	static GTSize Zero;
};

#endif /* _GREENTEA_SIZE_H_ */
