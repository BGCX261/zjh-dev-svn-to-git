#ifndef _GREENTEA_LIST_H_
#define _GREENTEA_LIST_H_

#include "GTBaseDef.h"
// STL
#include <list>

template <class ObjectType>
class GTList
{
public:
	typedef std::list<ObjectType> ListType;
	typedef typename std::list<ObjectType>::iterator ObjectTypeIterator;

public:
	GTList()
	{
	}

	// Initialize from a GTList
	GTList(GTList& gtl)
	{
		for(GTList::ObjectTypeIterator it = gtl.Begin();
			it != gtl.End();
			it++)
		{
			m_List.push_back((*it));
		}
	}

	GTList(typename GTList::ObjectTypeIterator first, typename GTList::ObjectTypeIterator last)
	{
		for(GTList::ObjectTypeIterator it = first;
			it != last;
			it++)
		{
			m_List.push_back((*it));
		}
	}

	// Initialize from a list
	//
	// Sample:
	//	int32 intArray[] = { 20, 45, 100, 4, 6 };
	//	GTList<int32> gtList(intArray, intArray + 5);
	GTList(ObjectType* first, ObjectType* last)
	{
		m_List.assign(first, last);		
	}

	// Initialize n x v
	//
	// Sample:
	//  GTList<int32> gtList(4, 100);
	GTList(int32 n, ObjectType v)
	{
		m_List.assign(n, v);
	}

	virtual ~GTList()
	{
		m_List.clear();
	}

	/*
	GTString ToString(void)
	{
		return GTString(CTEXT("GTList"));
	}
	*/

	// Add an object into the list at end
	void AddToTail(ObjectType ot)
	{
		m_List.push_back(ot);
	}

	// Add an object into the list at beginning
	void AddToHead(ObjectType ot)
	{
		m_List.push_front(ot);
	}

	// Remove an object from the list
	void Remove(ObjectType ot)
	{
		m_List.remove(ot);
	}

	void Erase(ObjectTypeIterator it)
	{
		m_List.erase(it);
	}

	// Get how many objects in the list
	int32 Count() const
	{
		return m_List.size();
	}

	int32 GetCount() const
	{
		return Count();
	}
	
	inline ObjectTypeIterator Begin()
	{
		return m_List.begin();
	}

	inline ObjectTypeIterator End()
	{
		return m_List.end();
	}

	void Clear()
	{
		m_List.clear();
	}

	// Get an object by its index
	ObjectType GetObjectByIndex(const int32 index)
	{
		DBG_ASSERT(index < Count());
		int32 count = 0;
		ObjectTypeIterator it;
		for(it = Begin(); it != End(); it++)
		{
			if(count == index)
			{
				break;
			}
			count++;
		}

		return (*it);
	}

	ObjectType operator[](const int32 index)
	{
		DBG_ASSERT(index < Count());
		return GetObjectByIndex(index);
	}

	// Sort
	void Sort(void)
	{
		m_List.sort();
	}
	// Sort with cumstomized comparing function
	//
	//	Sample:
	//	bool MyCompFunction (int i,int j) { return (i<j); }
	//  lst.Sort(MyCompFunction);
	template<class _CompFunction>
	void Sort(_CompFunction _CompFunctionInst)
	{
		m_List.sort(_CompFunctionInst);
	}

	// Output string content to a GTString object, seperated by ,
	// Sample: 123,8,9,2
	GTString ToString(void)
	{
		GTString str = GTString::EmptyString;
		for(ObjectTypeIterator it = Begin(); it != End(); it++)
		{
			str.Append(GTString::From(*it));
			str += CTEXT(",");
		}
		return str;
	}

private:
	ListType m_List;
};

// foreach every child in GTList
#define GTLIST_FOREACH(_type,_iterator,_container) \
	for(GTList<_type>::ObjectTypeIterator _iterator = _container.Begin(); \
		_iterator != _container.End(); \
		_iterator++)

#endif /* _GREENTEA_LIST_H_ */
