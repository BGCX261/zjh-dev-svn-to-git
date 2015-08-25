#ifndef _GREENTEA_POINT_2_H_
#define _GREENTEA_POINT_2_H_

#include "GTVector2.h"

/*
#include <math.h>

class GTPoint2
{
public:
	GTPoint2()
	{
		x = 0.0f;
		y = 0.0f;
	}

	GTPoint2(const float tx, const float ty)
	{
		x = tx;
		y = ty;
	}

	virtual ~GTPoint2()
	{
	}

	//----------------------------------------------
	// ==
	//----------------------------------------------
	bool operator == ( const GTPoint2& b ) const
	{
		return (b.x==x && b.y==y);
	}

	//----------------------------------------------
	// !=
	//----------------------------------------------
	bool operator != ( const GTPoint2& b ) const
	{
		return (!(b == (*this)));
	}

	//----------------------------------------------
	// -
	//----------------------------------------------
	const GTPoint2 operator - () const
	{
		return GTPoint2( -x, -y );
	}

	//----------------------------------------------
	// =
	//----------------------------------------------
	const GTPoint2 operator = ( const GTPoint2& Vec )
	{
		x = Vec.x;
		y = Vec.y;

		return (*this);
	}

	//----------------------------------------------
	// +=
	//----------------------------------------------
	const GTPoint2& operator += ( const GTPoint2& Vec )
	{
		x += Vec.x;
		y += Vec.y;

		return (*this);
	}

	//----------------------------------------------
	// -=
	//----------------------------------------------
	const GTPoint2& operator -= ( const GTPoint2& Vec )
	{
		x -= Vec.x;
		y -= Vec.y;

		return (*this);
	}

	//----------------------------------------------
	// *=
	//----------------------------------------------
	const GTPoint2& operator *= ( const float& f )
	{
		x *= f;
		y *= f;

		return (*this);
	}

	//----------------------------------------------
	// /=
	//----------------------------------------------
	const GTPoint2& operator /= ( const float& f )
	{
		x /= f;
		y /= f;

		return (*this);
	}

	//----------------------------------------------
	// +
	//----------------------------------------------
	const GTPoint2 operator + ( const GTPoint2& Vec ) const
	{
		return GTPoint2( x + Vec.x, y + Vec.y );
	}

	//----------------------------------------------
	// -
	//----------------------------------------------
	const GTPoint2 operator - ( const GTPoint2& Vec ) const
	{
		return GTPoint2( x - Vec.x, y - Vec.y );
	}

	//----------------------------------------------
	// *
	//----------------------------------------------
	const GTPoint2 operator * ( const float& f ) const
	{
		return GTPoint2( x*f, y*f );
	}

	friend const GTPoint2 operator * ( const float& f, const GTPoint2& Vec )
	{
		return (Vec*f);
	}

	//----------------------------------------------
	// /
	//----------------------------------------------
	const GTPoint2 operator / ( const float& f ) const
	{
		return GTPoint2( x/f, y/f );
	}

	//----------------------------------------------
	// cross product
	// NOTE: left-hand
	//----------------------------------------------
	//const GTPoint2 CrossProduct( const GTPoint2& Vec ) const
	//{
	//return GTPoint2( y*Vec.m_z - m_z*Vec.y, m_z*Vec.x - x*Vec.m_z, x*Vec.y - y*Vec.x );
	//}

	//----------------------------------------------
	// dot product
	//----------------------------------------------
	//T DotProduct( const GTPoint2& Vec ) const
	//{
	//return (x*Vec.x + y*Vec.y + m_z*Vec.m_z);
	//}

	//----------------------------------------------
	// length square
	//----------------------------------------------
	float LengthSquare( void ) const
	{
		return (x*x + y*y);
	}

	//----------------------------------------------
	// length
	//----------------------------------------------
	float Length( void ) const
	{
		return (float)sqrtf( LengthSquare() );
	}

	//----------------------------------------------
	// distance
	//----------------------------------------------
	float Dist( const GTPoint2& Vec ) const
	{
		return ((*this) - Vec).Length();
	}

	//----------------------------------------------
	// distance square
	//----------------------------------------------
	float DistSquare( const GTPoint2& Vec ) const
	{
		return ((*this) - Vec).LengthSquare();
	}

	//----------------------------------------------
	// normalize
	//----------------------------------------------
	void Normalize( void )
	{
		(*this) /= Length();
	}

public:
	float x;
	float y;

public:
	// Zero object
	static GTPoint2 Zero;
};
*/

typedef GTVector2 GTPoint2;

#endif /* _GREENTEA_POINT_2_H_ */
