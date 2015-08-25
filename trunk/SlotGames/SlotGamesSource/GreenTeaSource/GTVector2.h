#ifndef _GREENTEA_VECTOR_2_H_
#define _GREENTEA_VECTOR_2_H_

#include <math.h>
#include <GTBaseDef.h>
#include <GTString.h>

/*
// Vector2 template
template<class T>
class Vector2Template
{
public:
	T x;
	T y;

public:
	Vector2Template() {};
	Vector2Template( const T& tx, const T& ty )
	{
		x = tx;
		y = ty;
	}
	virtual ~Vector2Template() {}

	//----------------------------------------------
	// ==
	//----------------------------------------------
	bool operator == ( const Vector2Template& b ) const
	{
		return (b.x==x && b.y==y);
	}

	//----------------------------------------------
	// !=
	//----------------------------------------------
	bool operator != ( const Vector2Template& b ) const
	{
		return (!(b == (*this)));
	}

	//----------------------------------------------
	// -
	//----------------------------------------------
	const Vector2Template operator - () const
	{
		return Vector2Template( -x, -y );
	}

	//----------------------------------------------
	// =
	//----------------------------------------------
	const Vector2Template operator = ( const Vector2Template& Vec )
	{
		x = Vec.x;
		y = Vec.y;

		return (*this);
	}

	//----------------------------------------------
	// +=
	//----------------------------------------------
	const Vector2Template& operator += ( const Vector2Template& Vec )
	{
		x += Vec.x;
		y += Vec.y;

		return (*this);
	}

	//----------------------------------------------
	// -=
	//----------------------------------------------
	const Vector2Template& operator -= ( const Vector2Template& Vec )
	{
		x -= Vec.x;
		y -= Vec.y;

		return (*this);
	}

	//----------------------------------------------
	// *=
	//----------------------------------------------
	const Vector2Template& operator *= ( const T& f )
	{
		x *= f;
		y *= f;

		return (*this);
	}

	//----------------------------------------------
	// /=
	//----------------------------------------------
	const Vector2Template& operator /= ( const T& f )
	{
		x /= f;
		y /= f;

		return (*this);
	}

	//----------------------------------------------
	// +
	//----------------------------------------------
	const Vector2Template operator + ( const Vector2Template& Vec ) const
	{
		return Vector2Template( x + Vec.x, y + Vec.y );
	}

	//----------------------------------------------
	// -
	//----------------------------------------------
	const Vector2Template operator - ( const Vector2Template& Vec ) const
	{
		return Vector2Template( x - Vec.x, y - Vec.y );
	}

	//----------------------------------------------
	// *
	//----------------------------------------------
	const Vector2Template operator * ( const T& f ) const
	{
		return Vector2Template( x*f, y*f );
	}

	friend const Vector2Template operator * ( const T& f, const Vector2Template& Vec )
	{
		return (Vec*f);
	}

	//----------------------------------------------
	// /
	//----------------------------------------------
	const Vector2Template operator / ( const T& f ) const
	{
		return Vector2Template( x/f, y/f );
	}

	//----------------------------------------------
	// cross product
	// NOTE: left-hand
	//----------------------------------------------
	//const Vector2Template CrossProduct( const Vector2Template& Vec ) const
	//{
	//return Vector2Template( y*Vec.m_z - m_z*Vec.y, m_z*Vec.x - x*Vec.m_z, x*Vec.y - y*Vec.x );
	//}

	//----------------------------------------------
	// dot product
	//----------------------------------------------
	//T DotProduct( const Vector2Template& Vec ) const
	//{
	//return (x*Vec.x + y*Vec.y + m_z*Vec.m_z);
	//}

	//----------------------------------------------
	// length square
	//----------------------------------------------
	T LengthSquare( void ) const
	{
		return (x*x + y*y);
	}

	//----------------------------------------------
	// length
	//----------------------------------------------
	T Length( void ) const
	{
		return (T)sqrtf( LengthSquare() );
	}

	//----------------------------------------------
	// distance
	//----------------------------------------------
	T Dist( const Vector2Template& Vec ) const
	{
		return ((*this) - Vec).Length();
	}

	//----------------------------------------------
	// distance square
	//----------------------------------------------
	T DistSquare( const Vector2Template& Vec ) const
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
};

typedef Vector2Template<float> GTVector2;
*/

class GTVector2
{
public:
	GTVector2()
	{
		x = 0.0f;
		y = 0.0f;
	}

	GTVector2(const float tx, const float ty)
	{
		x = tx;
		y = ty;
	}

	GTVector2(const GTVector2& src)
	{
		x = src.x;
		y = src.y;
	}

	virtual ~GTVector2()
	{
	}

	GTString ToString(void)
	{
		return GTString::Format(CTEXT("(%f,%f)"), x, y);
	}

	//----------------------------------------------
	// ==
	//----------------------------------------------
	bool operator == ( const GTVector2& b ) const
	{
		return (b.x==x && b.y==y);
	}

	//----------------------------------------------
	// !=
	//----------------------------------------------
	bool operator != ( const GTVector2& b ) const
	{
		return (!(b == (*this)));
	}

	//----------------------------------------------
	// -
	//----------------------------------------------
	const GTVector2 operator - () const
	{
		return GTVector2( -x, -y );
	}

	//----------------------------------------------
	// =
	//----------------------------------------------
	const GTVector2 operator = ( const GTVector2& Vec )
	{
		x = Vec.x;
		y = Vec.y;

		return (*this);
	}

	//----------------------------------------------
	// +=
	//----------------------------------------------
	const GTVector2& operator += ( const GTVector2& Vec )
	{
		x += Vec.x;
		y += Vec.y;

		return (*this);
	}

	//----------------------------------------------
	// -=
	//----------------------------------------------
	const GTVector2& operator -= ( const GTVector2& Vec )
	{
		x -= Vec.x;
		y -= Vec.y;

		return (*this);
	}

	//----------------------------------------------
	// *=
	//----------------------------------------------
	const GTVector2& operator *= ( const float& f )
	{
		x *= f;
		y *= f;

		return (*this);
	}

	//----------------------------------------------
	// /=
	//----------------------------------------------
	const GTVector2& operator /= ( const float& f )
	{
		x /= f;
		y /= f;

		return (*this);
	}

	//----------------------------------------------
	// +
	//----------------------------------------------
	const GTVector2 operator + ( const GTVector2& Vec ) const
	{
		return GTVector2( x + Vec.x, y + Vec.y );
	}

	//----------------------------------------------
	// -
	//----------------------------------------------
	const GTVector2 operator - ( const GTVector2& Vec ) const
	{
		return GTVector2( x - Vec.x, y - Vec.y );
	}

	//----------------------------------------------
	// *
	//----------------------------------------------
	const GTVector2 operator * ( const float& f ) const
	{
		return GTVector2( x*f, y*f );
	}

	friend const GTVector2 operator * ( const float& f, const GTVector2& Vec )
	{
		return (Vec*f);
	}

	//----------------------------------------------
	// /
	//----------------------------------------------
	const GTVector2 operator / ( const float& f ) const
	{
		return GTVector2( x/f, y/f );
	}

	//----------------------------------------------
	// cross product
	// NOTE: left-hand
	//----------------------------------------------
	/*
	const GTVector2 CrossProduct( const GTVector2& Vec ) const
	{
	return GTVector2( y*Vec.m_z - m_z*Vec.y, m_z*Vec.x - x*Vec.m_z, x*Vec.y - y*Vec.x );
	}
	*/

	//----------------------------------------------
	// dot product
	//----------------------------------------------
	/*
	T DotProduct( const GTVector2& Vec ) const
	{
	return (x*Vec.x + y*Vec.y + m_z*Vec.m_z);
	}
	*/

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
	float Dist( const GTVector2& Vec ) const
	{
		return ((*this) - Vec).Length();
	}

	//----------------------------------------------
	// distance square
	//----------------------------------------------
	float DistSquare( const GTVector2& Vec ) const
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

	//----------------------------------------------
	// Format from a string: X Y
	// Sample: 120 345
	//----------------------------------------------
	static GTVector2 Parse(const GTString& source);

public:
	float x;
	float y;

public:
	// Zero object
	static GTVector2 Zero;
};

#endif /* _GREENTEA_VECTOR_2_H_ */
