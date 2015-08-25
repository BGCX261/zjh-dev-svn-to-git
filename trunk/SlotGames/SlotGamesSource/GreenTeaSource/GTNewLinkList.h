//===========================================================
//
// FileName: LinkList.h
// Desc: The Template Manager of Link-List
//
// Write by zjh 11/21/2001
//
//===========================================================

#ifndef _TEMPLATE_LINK_LIST_H_
#define _TEMPLATE_LINK_LIST_H_

//===========================================================

#include "GTBaseDef.h"

#ifndef ASSERT
#define ASSERT
#endif /* ASSERT */

//===========================================================
//
// CLinkListNode
//
//===========================================================
template < class ObjectType >
struct CLinkListNode
{
	public:
		CLinkListNode() { m_lpPrev = NULL; m_lpNext = NULL; }

	public:
		ObjectType m_Object;
		ObjectType GetObject( void ) { return m_Object; }
		ObjectType GetData( void )   { return m_Object; }

		CLinkListNode *m_lpPrev;
		CLinkListNode *m_lpNext;

		CLinkListNode *GetPrev( void ) { return m_lpPrev; }
		CLinkListNode *GetNext( void ) { return m_lpNext; }
};

//===========================================================
//
// GTNewLinkList
//
//===========================================================
template < class ObjectType >
class GTNewLinkList
{
	public:
		void Clear( void );
		GTNewLinkList() { Clear(); }
		virtual ~GTNewLinkList() { Release(); Clear(); }

	public:
		CLinkListNode< ObjectType > *m_lpHead;
		CLinkListNode< ObjectType > *m_lpTail;
		uint32 m_dwNumNode;

	public:
		// 临时指针，仅仅在 Start()/End() 之间有效
		CLinkListNode< ObjectType > *m_lpCurTemp;

		// Get the current pointer. If the pos is NULL, it means that the link-list
		// is not locked. Otherwise, it is locked.
		CLinkListNode< ObjectType >* GetCurPos( void ) { return m_lpCurTemp; }

		// Set the current pointer that is returned by GetCurPos().
		void SetCurPos( CLinkListNode< ObjectType >* pCurTemp ) { m_lpCurTemp = pCurTemp; }

		//---------------------------------------------------
		// The first method for accessing items in the list
		/*
		The following example shows how to use this mehtod
		to access all items hold by the list. For example,
		the list is used to hold int numbers.
		
		// Initialize the list
		CLinkList<int> list;
		list.AddTail( 10 );
		list.AddTail( 20 );
		list.AddTail( 30 );
		
		// Get the number of items
		uint32 dwNumItems = list.GetNumObjects();
		
		// Use a fixed loop to access all items.
		int nItem;
		// Lock the list
		if( list.Start() )
		{
		    for( uint32 i=0; i<dwNumItems; i++ )
		    {
		         nItem = list.GetObjectData();
		    }
		    list.End();
		}
		
		// Release the list
		list.Release();
		
		NOTE:
		1. The length of the loop must be known already,
		   otherwise it does not work.
		2. In the loop, DO NOT remove any item because
		   the number of items in the list will change.
		   Then, the loop will fail.
		*/
		//---------------------------------------------------

		// 访问 link-list 中的元素之前必须调用该函数
		bool Start( void );

		// 访问 link-list 之后必须调用该函数
		void End( void );

		// 检查是否处于 Start()/End() 之间
		// true  - 处于 Start()/End() 之间
		// false - 不处于 Start()/End() 之间
		bool IsLocking( void );

		// 获取一个 node 指针
		CLinkListNode< ObjectType > *GetNode( void );

		// 获取 node 中包含的数据
		ObjectType GetObjectData( void );

		// 获取 node 中包含数据的地址
		ObjectType* GetObjectDataPointer( void );

		//---------------------------------------------------
		// The second method for accessing items in the list
		/*
		The following example shows how to use this mehtod
		to access all items hold by the list. For example,
		the list is used to hold int numbers.
		
		// Initialize the list
		CLinkList<int> list;
		list.AddTail( 10 );
		list.AddTail( 20 );
		list.AddTail( 30 );

        // Get the first pos
        CLinkListNode<int>* pos = list.GetFirstPos();
		int item;

        while( pos )
		{
		    pos = list.GetNextPos( pos, item );
		}

		// Release the list
		list.Release();
		*/
		//---------------------------------------------------

		// Get the first pos
		CLinkListNode< ObjectType >* GetFirstPos( void );

		// Get the last pos
		CLinkListNode< ObjectType >* GetLastPos( void );

		// Get the next pos. The new pos and data are returned
		// respectively.
		CLinkListNode< ObjectType >* GetNextPos( CLinkListNode< ObjectType >* pPos, ObjectType& ObjectItem );

		// Get the previous pos. The new pos and data are returned
		// respectively.
		CLinkListNode< ObjectType >* GetPrevPos( CLinkListNode< ObjectType >* pPos, ObjectType& ObjectItem );

		// Get the data contained by the cur pos
		bool GetCurPosItem( CLinkListNode< ObjectType >* pPos, ObjectType& ObjectItem );

		//---------------------------------------------------
		// Get
		//---------------------------------------------------
		// Get the head of the list
		CLinkListNode< ObjectType > *GetHead( void ) { return m_lpHead; }

		// Get the tail of the list
		CLinkListNode< ObjectType > *GetTail( void ) { return m_lpTail; }

		// Get the number of nodes contained by the list
		uint32 GetNumNode( void ) const { return m_dwNumNode; }
		uint32 GetNumObject( void ) const { return m_dwNumNode; }

		//---------------------------------------------------
		// Add
		//
		// AddHead - Add an item to the list's head.
		// AddTail - Add an item to the list's tail.
		//---------------------------------------------------
		bool AddHead( const ObjectType& otObject );
		bool AddTail( const ObjectType& otObject );

		//---------------------------------------------------
		// Insert
		//---------------------------------------------------
		bool InsertBefore( ObjectType& otObject, CLinkListNode< ObjectType > *lpNode );
		bool InsertAfter( ObjectType& otObject, CLinkListNode< ObjectType > *lpNode );

		//---------------------------------------------------
		// Search
		//---------------------------------------------------
		CLinkListNode< ObjectType > *SearchNode( const uint32 dwIndex );
		ObjectType SearchObjectData( const uint32 dwIndex );

		//---------------------------------------------------
		// Remove/Delete an item from the list.
		//---------------------------------------------------
		// RemoveHead/DeleteHead - Remove an item from the list's head.
		bool RemoveHead( void );
		bool DeleteHead( void ) { return RemoveHead(); }

		// RemoveTail/DeleteTail - Remove an item from the list's tail.
		bool RemoveTail( void );
		bool DeleteTail( void ) { return RemoveTail(); }

		// Remove/Delete - Remove a specific item.
		bool Remove( const ObjectType& otObject );
		bool Delete( const ObjectType& otObject ) { return Remove( otObject ); }

		//---------------------------------------------------
		// Release the list.
		//---------------------------------------------------
		void Release( void );
};


//===========================================================
//
// Desc: clear
//
//===========================================================
template < class ObjectType >
void GTNewLinkList< ObjectType >::Clear( void )
{
	m_dwNumNode = 0;
	m_lpHead = NULL;
	m_lpTail = NULL;
	m_lpCurTemp = NULL;

	return;
}

//===========================================================
//
// Desc: 访问 link-list 中的元素之前必须调用该函数
//
//===========================================================
template < class ObjectType >
bool GTNewLinkList< ObjectType >::Start( void )
{
	if( 0 == m_dwNumNode )
	{
		return false;
	}

	m_lpCurTemp = m_lpHead;
	
	return true;
}

//===========================================================
//
// Desc: 访问 link-list 之后必须调用该函数
//
//===========================================================
template < class ObjectType >
void GTNewLinkList< ObjectType >::End( void )
{
	m_lpCurTemp = NULL;

	return;
}

//===========================================================
//
// Desc: 检查是否处于 Start()/End() 之间
//       true  - 处于 Start()/End() 之间
//       false - 不处于 Start()/End() 之间
//
//===========================================================
template < class ObjectType >
bool GTNewLinkList< ObjectType >::IsLocking( void )
{
	return (m_lpCurTemp ? true : false);
}

//===========================================================
//
// Desc: 获取一个 node 指针
//
//===========================================================
template < class ObjectType >
CLinkListNode< ObjectType >* GTNewLinkList< ObjectType >::GetNode( void )
{
#ifdef _DEBUG
	if( NULL == m_lpCurTemp )
	{
		return NULL;
	}
#endif //_DEBUG
	static CLinkListNode< ObjectType > *lpNode;
	lpNode = m_lpCurTemp;
	m_lpCurTemp = m_lpCurTemp->m_lpNext; 

	return lpNode;
}

//===========================================================
//
// Desc: 获取 node 中包含的数据
//
//===========================================================
template < class ObjectType >
ObjectType GTNewLinkList< ObjectType >::GetObjectData( void ) 
{ 
#ifdef _DEBUG
	//if( NULL == m_lpCurTemp ) { return 0; }
	ASSERT( m_lpCurTemp );
#endif // _DEBUG
	CLinkListNode< ObjectType > *lpNode;
	lpNode = m_lpCurTemp;
	m_lpCurTemp = m_lpCurTemp->m_lpNext; 

	return lpNode->m_Object;
}

//===========================================================
//
// Desc: 获取 node 中包含数据的地址
//
//===========================================================
template < class ObjectType >
ObjectType* GTNewLinkList< ObjectType >::GetObjectDataPointer( void ) 
{ 
#ifdef _DEBUG
	if( NULL == m_lpCurTemp )
	{
		return 0;
	}
#endif // _DEBUG
	static CLinkListNode< ObjectType > *lpNode;
	lpNode = m_lpCurTemp;
	m_lpCurTemp = m_lpCurTemp->m_lpNext; 

	return &lpNode->m_Object;
}

//===========================================================
//
// Desc: Get the first pos of the list.
//
// [Return]
// If the list DOES NOT contain any item, returns NULL.
// Otherwise, the first pos will be returned.
//
//===========================================================
template < class ObjectType >
CLinkListNode< ObjectType >* GTNewLinkList< ObjectType >::GetFirstPos( void )
{
	return m_lpHead;
}

//===========================================================
//
// Desc: Get the last pos of the list.
//
// [Return]
// If the list DOES NOT contain any item, returns NULL.
// Otherwise, the last pos will be returned.
//
//===========================================================
template < class ObjectType >
CLinkListNode< ObjectType >* GTNewLinkList< ObjectType >::GetLastPos( void )
{
	return m_lpTail;
}

//===========================================================
//
// Desc: Get the next pos.
//       The new pos and data are returned respectively.
//
// [In]
// pPos - The current pos handle in order to get the next pos
//
// [Out]
// ObjectItem - For saving the item returned
//
// [Return]
// The new pos handle
//
//===========================================================
template < class ObjectType >
CLinkListNode< ObjectType >* GTNewLinkList< ObjectType >::GetNextPos( CLinkListNode< ObjectType >* pPos,
															          ObjectType& ObjectItem )
{
	if( NULL == pPos )
	{
		return NULL;
	}

	// Save the object
	ObjectItem = pPos->m_Object;

	// Point to the next item
	pPos = pPos->m_lpNext;

	return pPos;
}

//===========================================================
//
// Desc: Get the previous pos.
//       The new pos and data are returned respectively.
//
// [In]
// pPos - The current pos handle in order to get the next pos
//
// [Out]
// ObjectItem - For saving the item returned
//
// [Return]
// The new pos handle
//
//===========================================================
template < class ObjectType >
CLinkListNode< ObjectType >* GTNewLinkList< ObjectType >::GetPrevPos( CLinkListNode< ObjectType >* pPos,
															          ObjectType& ObjectItem )
{
	if( NULL == pPos )
	{
		return NULL;
	}

	// Save the object
	ObjectItem = pPos->m_Object;

	// Point to the prev item
	pPos = pPos->m_lpPrev;

	return pPos;
}

//===========================================================
//
// Desc: Get the data contained by the cur pos
//
// [In]
// pPos - The current pos
//
// [Out]
// ObjectItem - For saving the item returned.
//
//===========================================================
template < class ObjectType >
bool GTNewLinkList< ObjectType >::GetCurPosItem( CLinkListNode< ObjectType >* pPos,
										         ObjectType& ObjectItem )
{
	if( NULL == pPos )
	{
		return false;
	}

	// Save the object
	ObjectItem = pPos->m_Object;

	return true;
}

//===========================================================
//
// Desc: 从头部加入一个数据
//
//===========================================================
template < class ObjectType >
bool GTNewLinkList< ObjectType >::AddHead( const ObjectType& otObject )
{
	if( m_lpHead )
	{
		CLinkListNode< ObjectType > *lpNewNode = (CLinkListNode< ObjectType >*)malloc( sizeof(CLinkListNode< ObjectType >) );
		if( NULL == lpNewNode )
		{
			return false;
		}

		lpNewNode->m_lpPrev = NULL;
		lpNewNode->m_Object = otObject;
		lpNewNode->m_lpNext = m_lpHead;
		m_lpHead->m_lpPrev = lpNewNode;
		m_lpHead = lpNewNode;
		m_dwNumNode++;
	}
	else
	{
		// first node
		m_lpHead = (CLinkListNode< ObjectType >*)malloc( sizeof(CLinkListNode< ObjectType >) );
		if( NULL == m_lpHead )
		{
			return false;
		}

		m_lpHead->m_lpPrev = NULL;
		m_lpHead->m_lpNext = NULL;
		m_lpHead->m_Object = otObject; // save data
		m_lpTail = m_lpHead;
		m_dwNumNode++;
	}

	return true;
}

//===========================================================
//
// Desc: 从尾部加入一个数据
//
//===========================================================
template < class ObjectType >
bool GTNewLinkList< ObjectType >::AddTail( const ObjectType& otObject )
{
	if( m_lpTail )
	{
		CLinkListNode< ObjectType > *lpNewNode = (CLinkListNode< ObjectType >*)malloc( sizeof(CLinkListNode< ObjectType >) );
		if( NULL == lpNewNode )
		{
			return false;
		}

		lpNewNode->m_lpPrev = m_lpTail;
		lpNewNode->m_Object = otObject;
		lpNewNode->m_lpNext = NULL;
		m_lpTail->m_lpNext = lpNewNode;
		m_lpTail = lpNewNode;
		m_dwNumNode++;
	}
	else
	{
		// first node
		CLinkListNode< ObjectType > *lpNewNode = (CLinkListNode< ObjectType >*)malloc( sizeof(CLinkListNode< ObjectType >) );
		if( NULL == lpNewNode )
		{
			return false;
		}

		lpNewNode->m_lpPrev = NULL;
		lpNewNode->m_Object = otObject;
		lpNewNode->m_lpNext = NULL;
		m_lpHead = lpNewNode;
		m_lpTail = lpNewNode;
		m_dwNumNode++;
	}

	return true;
}


//===========================================================
//
// Desc: 在指定的节点 lpNode 之前加入一个数据
//
//===========================================================
template < class ObjectType >
bool GTNewLinkList< ObjectType >::InsertBefore( ObjectType& otObject, CLinkListNode< ObjectType > *lpNode )
{
	CLinkListNode< ObjectType > *lpNewNode = (CLinkListNode< ObjectType >*)malloc( sizeof(CLinkListNode< ObjectType >) );
	if( NULL == lpNewNode )
	{
		return false;
	}

	lpNewNode->m_lpNext = lpNode;
	lpNewNode->m_Object = otObject;
	lpNewNode->m_lpPrev = lpNode->m_lpPrev;
	lpNewNode->m_lpPrev->m_lpNext = lpNewNode->m_lpNext->m_lpPrev = lpNewNode;
	m_dwNumNode++;
	
	return true;
}

//===========================================================
//
// Desc: 在指定的节点 lpNode 之后加入一个数据
//
//===========================================================
template < class ObjectType >
bool GTNewLinkList< ObjectType >::InsertAfter( ObjectType& otObject, CLinkListNode< ObjectType > *lpNode )
{
	CLinkListNode< ObjectType > *lpNewNode = (CLinkListNode< ObjectType >*)malloc( sizeof(CLinkListNode< ObjectType >) );
	if( NULL == lpNewNode )
	{
		return false;
	}

	lpNewNode->m_lpPrev = lpNode;
	lpNewNode->m_Object = otObject;
	lpNewNode->m_lpNext = lpNode->m_lpNext;
	lpNewNode->m_lpPrev->m_lpNext = lpNewNode->m_lpNext->m_lpPrev = lpNewNode;
	m_dwNumNode++;

	return true;
}


//===========================================================
//
// Desc: 根据索引搜索一个 node
//
// [In]
// dwIndex - the index want to get
//
// [Out]
//
// [Return]
// != NULL - succeed
// == NULL - failed
//
//===========================================================
template < class ObjectType >
CLinkListNode< ObjectType > *GTNewLinkList< ObjectType >::SearchNode( const uint32 dwIndex )
{
	if( dwIndex >= m_dwNumNode )
	{
		return NULL;
	}

	uint32 dwCnt = 0;
	CLinkListNode< ObjectType > *lpNode = m_lpHead;
	while( lpNode != m_lpTail )
	{
		if( dwCnt == dwIndex )
		{
			return lpNode;
		}

		dwCnt++;
		lpNode = lpNode->m_lpNext;
	} // while()

	if( dwCnt == dwIndex )
	{
		return lpNode;
	}

	return NULL;
}


//===========================================================
//
// Desc: 根据索引搜索一个 node 中包含的数据
//
// [In]
// dwIndex - the index want to get
//
// [Out]
//
// [Return]
// != NULL - succeed
// == NULL - failed
//
//===========================================================
template < class ObjectType >
ObjectType GTNewLinkList< ObjectType >::SearchObjectData( const uint32 dwIndex )
{
	if( dwIndex >= m_dwNumNode )
	{
		return NULL;
	}

	uint32 dwCnt = 0;
	CLinkListNode< ObjectType > *lpNode = m_lpHead;
	while( lpNode != m_lpTail )
	{
		if( dwCnt == dwIndex )
		{
			return lpNode->m_Object;
		}

		dwCnt++;
		lpNode = lpNode->m_lpNext;
	} // while()

	if( dwCnt == dwIndex )
	{
		return lpNode->m_Object;
	}

	return 0;
}


//===========================================================
//
// Desc: 删除头部的第一个 node
//
//===========================================================
template < class ObjectType >
bool GTNewLinkList< ObjectType >::RemoveHead( void )
{
	if( NULL == m_lpHead )
	{
		return false;
	}

	CLinkListNode< ObjectType > *lpNode = m_lpHead;
	m_lpHead = m_lpHead->m_lpNext;
	if( m_lpHead && m_lpHead->m_lpPrev ) { m_lpHead->m_lpPrev = NULL; }
	free( lpNode );
	m_dwNumNode--;
	if( 0 == m_dwNumNode ) { m_lpTail = NULL; }

	return true;
}


//===========================================================
//
// Desc: 删除尾部的第一个 node
//
//===========================================================
template < class ObjectType >
bool GTNewLinkList< ObjectType >::RemoveTail( void )
{
	if( NULL == m_lpTail )
	{
		return false;
	}

	CLinkListNode< ObjectType > *lpNode = m_lpTail;
	m_lpTail = m_lpTail->m_lpPrev;
	if( m_lpTail && m_lpTail->m_lpNext ) { m_lpTail->m_lpNext = NULL; }
	free( lpNode );
	m_dwNumNode--;
	if( 0 == m_dwNumNode ) { m_lpHead = NULL; }

	return true;
}


//===========================================================
//
// Desc: 释放链表中所有的 node 成为一个空链表
//
//===========================================================
template < class ObjectType >
void GTNewLinkList< ObjectType >::Release( void )
{
	if( NULL == m_lpTail ) return;
	CLinkListNode< ObjectType > *p;
	p = m_lpTail;
	while( m_lpHead != p )
	{
		p = p->m_lpPrev;
		free( p->m_lpNext );
		p->m_lpNext = NULL;
	} // while()

	free( m_lpHead );
	m_lpHead = NULL;

	Clear();
}


//===========================================================
//
// Desc: 删除一个指定数据的 node
//
//===========================================================
template < class ObjectType >
bool GTNewLinkList< ObjectType >::Remove( const ObjectType& otObject )
{
	if( NULL == m_lpHead )
	{
		return false;
	}

	CLinkListNode< ObjectType > *lpNode = m_lpHead;

	while( NULL != lpNode )
	{
		if( lpNode->m_Object == otObject )
		{
			if( m_lpHead == lpNode )
			{
				// remove the first node
				m_lpHead = m_lpHead->m_lpNext; // next node
				if( m_lpHead ) m_lpHead->m_lpPrev = NULL;
				free( lpNode );
			}
			else if( m_lpTail == lpNode )
			{
				// remove the last node
				if( m_lpTail ) m_lpTail = m_lpTail->m_lpPrev; // prev node
				m_lpTail->m_lpNext = NULL;
				free( lpNode );
			}
			else
			{
				// remove this node from link-list
				lpNode->m_lpPrev->m_lpNext = lpNode->m_lpNext;
				lpNode->m_lpNext->m_lpPrev = lpNode->m_lpPrev;
				free( lpNode );
			}
			m_dwNumNode--;
			if( 0 == m_dwNumNode ) { Clear(); }

			return true;
		}
		lpNode = lpNode->m_lpNext;
	} // while()

	return false;
}


// linklist template.
//
// This class template derives from CLinkList.
// New helper functions make the link-list easy to use.

// Usage:
//
// linklist<int> list;
// list.push_back( (int)100 );
// list.push_back( (int)200 );
// list.push_back( (int)300 );
// list.push_back( (int)400 );
// list.push_back( (int)500 );
// for( linklist<int>::iterator it = list.begin(); it != list.end(); it++ )
// {
// 		int value = (*it);
// 		printf( "%ld\n", value );
// }

// Iterator container.
template < class ObjectType >
struct linklist_Iterator
{
	CLinkListNode< ObjectType >* m_pNode;

	typedef ObjectType  value_type;
	typedef ObjectType* pointer;
	typedef ObjectType& reference;
	typedef linklist_Iterator< ObjectType > SelfType;


	linklist_Iterator()
	{ }

	linklist_Iterator( CLinkListNode< ObjectType >* pNode )
	{ m_pNode = pNode; }

	void incr( void )
	{ m_pNode = m_pNode->m_lpNext; }

	void decr( void )
	{ m_pNode = m_pNode->m_lpPrev; }
	
	bool operator==( const linklist_Iterator< ObjectType >& x ) const
	{ return m_pNode == x.m_pNode; }
	
	bool operator!=( const linklist_Iterator< ObjectType >& x ) const
	{ return m_pNode != x.m_pNode; }

	ObjectType operator*()
	{ return m_pNode->m_Object; }

	ObjectType operator*() const
	{ return m_pNode->m_Object; }

	// Right operator: linklist_Iterator++
	SelfType operator++( int )
	{
		SelfType tmp = (*this);
		this->incr();
		return tmp;
	}

	// Right operator: linklist_Iterator--
	SelfType operator--( int )
	{
		SelfType tmp = (*this);
		this->decr();
		return tmp;
	}

	// Left operator: ++linklist_Iterator
	SelfType& operator++()
	{
		this->incr();
		return (*this);
	}

	// Left operator: --linklist_Iterator
	SelfType& operator--()
	{
		this->decr();
		return (*this);
	}
};

// linklist.
template < class ObjectType >
class linklist : public GTNewLinkList< ObjectType >
{
	public:
		typedef linklist_Iterator< ObjectType > iterator;
		typedef const iterator const_iterator;

	public:
		// Default constructor.
		linklist() : GTNewLinkList< ObjectType >()
		{ GTNewLinkList< ObjectType >::Clear(); }

		// Default de-constructor.
		~linklist()
		{ clear(); }

		// Get the header of the list.
		iterator begin( void )
		{ return iterator( GTNewLinkList< ObjectType >::GetHead() ); }
		const_iterator begin( void ) const
		{ return iterator( GTNewLinkList< ObjectType >::GetHead() ); }

		// Return null node.
		iterator null( void )
		{ return iterator( NULL ); }
		const_iterator null( void ) const
		{ return iterator( NULL ); }

		// Get the tail of the list.
		iterator tail( void )
		{ return iterator( GTNewLinkList< ObjectType >::GetTail() ); }
		const_iterator tail( void ) const
		{ return iterator( GTNewLinkList< ObjectType >::GetTail() ); }

		// Get the end of the list.
		iterator end( void )
		{ return null(); }
		const_iterator end( void ) const
		{ return null(); }

		// Get the number of items in the list.
		size_t size( void )
		{ return GTNewLinkList< ObjectType >::GetNumNode(); }

		// Insert an item before the header.
		void push_front( const ObjectType& obj )
		{ GTNewLinkList< ObjectType >::AddHead( obj ); }

		// Insert an item after the tailer.
		void push_back( const ObjectType& obj )
		{ GTNewLinkList< ObjectType >::AddTail( obj ); }

		// Release
		void clear( void );
};

// Release
template < class ObjectType >
void linklist< ObjectType >::clear( void )
{
	GTNewLinkList< ObjectType >::Release();
	GTNewLinkList< ObjectType >::Clear();
}

//===========================================================

#endif // _TEMPLATE_LINK_LIST_H_
