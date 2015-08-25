#ifndef _GREENTEA_VECTOR_3_H_
#define _GREENTEA_VECTOR_3_H_

#include <math.h>
#include "GTString.h"

class GTVector3
{
public:
	GTVector3()
	{
		x = y = z = 0.0f;
	}

	GTVector3(const float& tx, const float& ty, const float& tz)
	{
		x = tx;
		y = ty;
		z = tz;
	}

	GTVector3(const GTVector3& src)
	{
		x = src.x;
		y = src.y;
		z = src.z;
	}

	virtual ~GTVector3()
	{
	}

	GTString ToString(void)
	{
		return GTString::Format(CTEXT("(%f,%f,%f)"), x, y, z);
	}

	//----------------------------------------------
	// ==
	//----------------------------------------------
	bool operator == ( const GTVector3& b ) const
	{
		return (b.x==x && b.y==y && b.z == z);
	}

	//----------------------------------------------
	// !=
	//----------------------------------------------
	bool operator != ( const GTVector3& b ) const
	{
		return (!(b == (*this)));
	}

	//----------------------------------------------
	// -
	//----------------------------------------------
	const GTVector3 operator - () const
	{
		return GTVector3(-x, -y, -z);
	}

	//----------------------------------------------
	// =
	//----------------------------------------------
	const GTVector3 operator = (const GTVector3& vec)
	{
		x = vec.x;
		y = vec.y;
		z = vec.z;

		return (*this);
	}

	//----------------------------------------------
	// +=
	//----------------------------------------------
	const GTVector3& operator += (const GTVector3& vec)
	{
		x += vec.x;
		y += vec.y;
		z += vec.z;

		return (*this);
	}

	//----------------------------------------------
	// -=
	//----------------------------------------------
	const GTVector3& operator -= (const GTVector3& vec)
	{
		x -= vec.x;
		y -= vec.y;
		z -= vec.z;

		return (*this);
	}

	//----------------------------------------------
	// *=
	//----------------------------------------------
	const GTVector3& operator *= (const float& f)
	{
		x *= f;
		y *= f;
		z *= f;

		return (*this);
	}

	//----------------------------------------------
	// /=
	//----------------------------------------------
	const GTVector3& operator /= (const float& f)
	{
		x /= f;
		y /= f;
		z /= f;

		return (*this);
	}

	//----------------------------------------------
	// +
	//----------------------------------------------
	const GTVector3 operator + (const GTVector3& vec) const
	{
		return GTVector3(x + vec.x, y + vec.y, z + vec.z);
	}

	//----------------------------------------------
	// -
	//----------------------------------------------
	const GTVector3 operator - (const GTVector3& vec) const
	{
		return GTVector3(x - vec.x, y - vec.y, z - vec.z);
	}

	//----------------------------------------------
	// *
	//----------------------------------------------
	const GTVector3 operator * ( const float& f ) const
	{
		return GTVector3(x*f, y*f, z*f);
	}

	friend const GTVector3 operator * ( const float& f, const GTVector3& vec )
	{
		return (vec*f);
	}

	//----------------------------------------------
	// /
	//----------------------------------------------
	const GTVector3 operator / (const float& f) const
	{
		return GTVector3(x/f, y/f, z/f);
	}

	//----------------------------------------------
	// Cross product
	// NOTE: left-hand
	//----------------------------------------------
	const GTVector3 CrossProduct(const GTVector3& vec) const
	{
		return GTVector3(y*vec.z - z*vec.y, z*vec.x - x*vec.z, x*vec.y - y*vec.x);
	}

	//----------------------------------------------
	// Dot product
	//----------------------------------------------
	float DotProduct(const GTVector3& vec) const
	{
		return (x*vec.x + y*vec.y + z*vec.z);
	}

	//----------------------------------------------
	// length square
	//----------------------------------------------
	float LengthSquare( void ) const
	{
		return (x*x + y*y + z*z);
	}

	//----------------------------------------------
	// length
	//----------------------------------------------
	float Length( void ) const
	{
		return (float)sqrtf(LengthSquare());
	}

	//----------------------------------------------
	// distance
	//----------------------------------------------
	float Dist(const GTVector3& vec) const
	{
		return ((*this) - vec).Length();
	}

	//----------------------------------------------
	// distance square
	//----------------------------------------------
	float DistSquare(const GTVector3& vec ) const
	{
		return ((*this) - vec).LengthSquare();
	}

	//----------------------------------------------
	// normalize
	//----------------------------------------------
	void Normalize( void )
	{
		(*this) /= Length();
	}

	//----------------------------------------------
	// Format from a string: X Y Z
	// Sample: 120 345 789
	//----------------------------------------------
	static GTVector3 Parse(const GTString& source);

public:
	float x;
	float y;
	float z;

public:
	// Zero object
	static GTVector3 Zero;
};

#endif /* _GREENTEA_VECTOR_3_H_ */
