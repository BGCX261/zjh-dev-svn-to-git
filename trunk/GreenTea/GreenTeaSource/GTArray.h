#ifndef _GREENTEA_ARRAY_H_
#define _GREENTEA_ARRAY_H_

#include "GTBaseDef.h"
#include <vector>
#include <GTString.h>

template <class ObjectType>
class GTArray
{
public:
	typedef std::vector<ObjectType> ArrayType;
	typedef typename std::vector<ObjectType>::iterator ObjectTypeIterator;

public:
	GTArray()
	{
	}

	// Reserve size
	GTArray(const int32 size)
	{
		m_Array.reserve(size);
		ObjectType v;
		for(int32 i=0; i<size; i++)
		{
			m_Array.push_back(v);
		}
	}

	// Initialize from a GTArray
	GTArray(const GTArray& gta)
	{
		for(int32 i=0; i<gta.Length(); i++)
		{
			m_Array.push_back(gta[i]);
		}
	}

	GTArray(typename GTArray::ObjectTypeIterator first, typename GTArray::ObjectTypeIterator last)
	{
		for(GTArray::ObjectTypeIterator it = first;
			it != last;
			it++)
		{
			m_Array.push_back((*it));
		}
	}

	// Initialize from an array
	//
	// Sample:
	//	int32 intArray[] = { 20, 45, 100, 4, 6 };
	//	GTArray<int32> gtArray(intArray, intArray + 5);
	GTArray(ObjectType* first, ObjectType* last)
	{
		for(ObjectType* it = first; it != last; it++)
		{
			m_Array.push_back(*it);
		}
	}

	// Initialize from an array
	//
	// Sample:
	//	int32 intArray[] = { 20, 45, 100, 4, 6 };
	//	GTArray<int32> gtArray(intArray, 5);
	GTArray(ObjectType* first, const int32 count)
	{
		for(int32 i=0; i<count; i++)
		{
			m_Array.push_back(first[i]);
		}
	}

	// Initialize n x v
	//
	// Sample:
	//  GTArray<int32> gtArray(4, 100);
	GTArray(int32 n, ObjectType v)
	{
		for(int32 i=0; i<n; i++)
		{
			m_Array.push_back(v);
		}
	}

	virtual ~GTArray()
	{
		m_Array.clear();
	}

	/*
	GTString ToString(void)
	{
		return GTString(CTEXT("GTArray"));
	}
	*/

	// Clear the array
	void Clear(void)
	{
		m_Array.clear();
	}

	// Reserve size
	void Reserve(const int32 size)
	{
		if(size)
		{
			m_Array.reserve(size);
			ObjectType v;
			for(int32 i=0; i<size; i++)
			{
				m_Array.push_back(v);
			}
		}
	}

	// Add an object into the list
	void Add(ObjectType ot)
	{
		m_Array.push_back(ot);
	}
	void AddToTail(ObjectType ot)
	{
		m_Array.push_back(ot);
	}

	// Get how many objects in the list
	int32 Length() const
	{
		return m_Array.size();
	}

	ObjectType operator[](int32 index) const
	{
		DBG_ASSERT(index < Length());
		return m_Array[index];
	}

	ObjectType& operator[](const int32 index)
	{
		DBG_ASSERT(index < Length());
		return (*(m_Array.begin() + index));
	}
	
	/*
	const ObjectType& operator[](int32 index) const
	{
		DBG_ASSERT(index < Length());
		return (*(m_Array.begin + index));
	}
	*/

	inline ObjectTypeIterator Begin()
	{
		return m_Array.begin();
	}

	inline ObjectTypeIterator End()
	{
		return m_Array.end();
	}

	// Output string content to a GTString object, seperated by ,
	// Sample: 123,8,9,2
	GTString ToString(void)
	{
		GTString str = GTString::EmptyString;
		for(int32 i=0; i<Length(); i++)
		{
			str.Append(GTString::From(m_Array[i]));
			str += CTEXT(",");
		}
		return str;
	}

private:
	ArrayType m_Array;
};

#endif /* _GREENTEA_ARRAY_H_ */
