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

#include "BaseDef.h"

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
// CLinkList
//
//===========================================================
template < class ObjectType >
class CLinkList
{
	public:
		void Clear( void );
		CLinkList() { Clear(); }
		~CLinkList() { Release(); Clear(); }

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
		// TRUE  - 处于 Start()/End() 之间
		// FALSE - 不处于 Start()/End() 之间
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
		uint32 GetNumNode( void ) { return m_dwNumNode; }
		uint32 GetNumObject( void ) { return m_dwNumNode; }

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
		CLinkListNode< ObjectType > *SearchNode( uint32 dwIndex );
		ObjectType SearchObjectData( uint32 dwIndex );

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
void CLinkList< ObjectType >::Clear( void )
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
bool CLinkList< ObjectType >::Start( void )
{
	if( 0 == m_dwNumNode )
	{
		return FALSE;
	}

	m_lpCurTemp = m_lpHead;
	
	return TRUE;
}

//===========================================================
//
// Desc: 访问 link-list 之后必须调用该函数
//
//===========================================================
template < class ObjectType >
void CLinkList< ObjectType >::End( void )
{
	m_lpCurTemp = NULL;

	return;
}

//===========================================================
//
// Desc: 检查是否处于 Start()/End() 之间
//       TRUE  - 处于 Start()/End() 之间
//       FALSE - 不处于 Start()/End() 之间
//
//===========================================================
template < class ObjectType >
bool CLinkList< ObjectType >::IsLocking( void )
{
	return (m_lpCurTemp ? TRUE : FALSE);
}

//===========================================================
//
// Desc: 获取一个 node 指针
//
//===========================================================
template < class ObjectType >
CLinkListNode< ObjectType >* CLinkList< ObjectType >::GetNode( void )
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
ObjectType CLinkList< ObjectType >::GetObjectData( void ) 
{ 
#ifdef _DEBUG
	//if( NULL == m_lpCurTemp ) { return 0; }
	//ASSERT( m_lpCurTemp );
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
ObjectType* CLinkList< ObjectType >::GetObjectDataPointer( void ) 
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
CLinkListNode< ObjectType >* CLinkList< ObjectType >::GetFirstPos( void )
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
CLinkListNode< ObjectType >* CLinkList< ObjectType >::GetLastPos( void )
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
CLinkListNode< ObjectType >* CLinkList< ObjectType >::GetNextPos( CLinkListNode< ObjectType >* pPos,
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
CLinkListNode< ObjectType >* CLinkList< ObjectType >::GetPrevPos( CLinkListNode< ObjectType >* pPos,
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
bool CLinkList< ObjectType >::GetCurPosItem( CLinkListNode< ObjectType >* pPos,
										     ObjectType& ObjectItem )
{
	if( NULL == pPos )
	{
		return FALSE;
	}

	// Save the object
	ObjectItem = pPos->m_Object;

	return TRUE;
}

//===========================================================
//
// Desc: 从头部加入一个数据
//
//===========================================================
template < class ObjectType >
bool CLinkList< ObjectType >::AddHead( const ObjectType& otObject )
{
	if( m_lpHead )
	{
		//CLinkListNode< ObjectType > *lpNewNode = (CLinkListNode< ObjectType >*)malloc( sizeof(CLinkListNode< ObjectType >) );
		CLinkListNode< ObjectType > *lpNewNode = new CLinkListNode< ObjectType >;
		if( NULL == lpNewNode )
		{
			return FALSE;
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
		//m_lpHead = (CLinkListNode< ObjectType >*)malloc( sizeof(CLinkListNode< ObjectType >) );
		m_lpHead = new CLinkListNode< ObjectType >;
		if( NULL == m_lpHead )
		{
			return FALSE;
		}

		m_lpHead->m_lpPrev = NULL;
		m_lpHead->m_lpNext = NULL;
		m_lpHead->m_Object = otObject; // save data
		m_lpTail = m_lpHead;
		m_dwNumNode++;
	}

	return TRUE;
}

//===========================================================
//
// Desc: 从尾部加入一个数据
//
//===========================================================
template < class ObjectType >
bool CLinkList< ObjectType >::AddTail( const ObjectType& otObject )
{
	if( m_lpTail )
	{
		//CLinkListNode< ObjectType > *lpNewNode = (CLinkListNode< ObjectType >*)malloc( sizeof(CLinkListNode< ObjectType >) );
		CLinkListNode< ObjectType > *lpNewNode = new CLinkListNode< ObjectType >;
		if( NULL == lpNewNode )
		{
			return FALSE;
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
		//CLinkListNode< ObjectType > *lpNewNode = (CLinkListNode< ObjectType >*)malloc( sizeof(CLinkListNode< ObjectType >) );
		CLinkListNode< ObjectType > *lpNewNode = new CLinkListNode< ObjectType >;
		if( NULL == lpNewNode )
		{
			return FALSE;
		}

		lpNewNode->m_lpPrev = NULL;
		lpNewNode->m_Object = otObject;
		lpNewNode->m_lpNext = NULL;
		m_lpHead = lpNewNode;
		m_lpTail = lpNewNode;
		m_dwNumNode++;
	}

	return TRUE;
}


//===========================================================
//
// Desc: 在指定的节点 lpNode 之前加入一个数据
//
//===========================================================
template < class ObjectType >
bool CLinkList< ObjectType >::InsertBefore( ObjectType& otObject, CLinkListNode< ObjectType > *lpNode )
{
	//CLinkListNode< ObjectType > *lpNewNode = (CLinkListNode< ObjectType >*)malloc( sizeof(CLinkListNode< ObjectType >) );
	CLinkListNode< ObjectType > *lpNewNode = new CLinkListNode< ObjectType >;
	if( NULL == lpNewNode )
	{
		return FALSE;
	}

	lpNewNode->m_lpNext = lpNode;
	lpNewNode->m_Object = otObject;
	lpNewNode->m_lpPrev = lpNode->m_lpPrev;
	lpNewNode->m_lpPrev->m_lpNext = lpNewNode->m_lpNext->m_lpPrev = lpNewNode;
	m_dwNumNode++;
	
	return TRUE;
}

//===========================================================
//
// Desc: 在指定的节点 lpNode 之后加入一个数据
//
//===========================================================
template < class ObjectType >
bool CLinkList< ObjectType >::InsertAfter( ObjectType& otObject, CLinkListNode< ObjectType > *lpNode )
{
	//CLinkListNode< ObjectType > *lpNewNode = (CLinkListNode< ObjectType >*)malloc( sizeof(CLinkListNode< ObjectType >) );
	CLinkListNode< ObjectType > *lpNewNode = new CLinkListNode< ObjectType >;
	if( NULL == lpNewNode )
	{
		return FALSE;
	}

	lpNewNode->m_lpPrev = lpNode;
	lpNewNode->m_Object = otObject;
	lpNewNode->m_lpNext = lpNode->m_lpNext;
	lpNewNode->m_lpPrev->m_lpNext = lpNewNode->m_lpNext->m_lpPrev = lpNewNode;
	m_dwNumNode++;

	return TRUE;
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
CLinkListNode< ObjectType > *CLinkList< ObjectType >::SearchNode( uint32 dwIndex )
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
ObjectType CLinkList< ObjectType >::SearchObjectData( uint32 dwIndex )
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
bool CLinkList< ObjectType >::RemoveHead( void )
{
	if( NULL == m_lpHead )
	{
		return FALSE;
	}

	CLinkListNode< ObjectType > *lpNode = m_lpHead;
	m_lpHead = m_lpHead->m_lpNext;
	if( m_lpHead && m_lpHead->m_lpPrev ) { m_lpHead->m_lpPrev = NULL; }
	//free( lpNode );
	delete lpNode;
	m_dwNumNode--;
	if( 0 == m_dwNumNode ) { m_lpTail = NULL; }

	return TRUE;
}


//===========================================================
//
// Desc: 删除尾部的第一个 node
//
//===========================================================
template < class ObjectType >
bool CLinkList< ObjectType >::RemoveTail( void )
{
	if( NULL == m_lpTail )
	{
		return FALSE;
	}

	CLinkListNode< ObjectType > *lpNode = m_lpTail;
	m_lpTail = m_lpTail->m_lpPrev;
	if( m_lpTail && m_lpTail->m_lpNext ) { m_lpTail->m_lpNext = NULL; }
	//free( lpNode );
	delete lpNode;
	m_dwNumNode--;
	if( 0 == m_dwNumNode ) { m_lpHead = NULL; }

	return TRUE;
}


//===========================================================
//
// Desc: 释放链表中所有的 node 成为一个空链表
//
//===========================================================
template < class ObjectType >
void CLinkList< ObjectType >::Release( void )
{
	if( NULL == m_lpTail ) return;
	CLinkListNode< ObjectType > *p;
	p = m_lpTail;
	while( m_lpHead != p )
	{
		p = p->m_lpPrev;
		//free( p->m_lpNext );
		delete p->m_lpNext;
		p->m_lpNext = NULL;
	} // while()

	//free( m_lpHead );
	delete m_lpHead;
	m_lpHead = NULL;

	Clear();
}


//===========================================================
//
// Desc: 删除一个指定数据的 node
//
//===========================================================
template < class ObjectType >
bool CLinkList< ObjectType >::Remove( const ObjectType& otObject )
{
	if( NULL == m_lpHead )
	{
		return FALSE;
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
				//free( lpNode );
				delete lpNode;
			}
			else if( m_lpTail == lpNode )
			{
				// remove the last node
				if( m_lpTail ) m_lpTail = m_lpTail->m_lpPrev; // prev node
				m_lpTail->m_lpNext = NULL;
				//free( lpNode );
				delete lpNode;
			}
			else
			{
				// remove this node from link-list
				lpNode->m_lpPrev->m_lpNext = lpNode->m_lpNext;
				lpNode->m_lpNext->m_lpPrev = lpNode->m_lpPrev;
				//free( lpNode );
				delete lpNode;
			}
			m_dwNumNode--;
			if( 0 == m_dwNumNode ) { Clear(); }

			return TRUE;
		}
		lpNode = lpNode->m_lpNext;
	} // while()

	return FALSE;
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
class linklist : public CLinkList< ObjectType >
{
	public:
		typedef linklist_Iterator< ObjectType > iterator;
		typedef const iterator const_iterator;

	public:
		// Default constructor.
		linklist() : CLinkList< ObjectType >()
		{ CLinkList< ObjectType >::Clear(); }

		// Default de-constructor.
		~linklist()
		{ clear(); }

		// Get the header of the list.
		iterator begin( void )
		{ return iterator( CLinkList< ObjectType >::GetHead() ); }
		const_iterator begin( void ) const
		{ return iterator( CLinkList< ObjectType >::GetHead() ); }

		// Return null node.
		iterator null( void )
		{ return iterator( NULL ); }
		const_iterator null( void ) const
		{ return iterator( NULL ); }

		// Get the tail of the list.
		iterator tail( void )
		{ return iterator( CLinkList< ObjectType >::GetTail() ); }
		const_iterator tail( void ) const
		{ return iterator( CLinkList< ObjectType >::GetTail() ); }

		// Get the end of the list.
		iterator end( void )
		{ return null(); }
		const_iterator end( void ) const
		{ return null(); }

		// Get the number of items in the list.
		int32 size( void )
		{ return CLinkList< ObjectType >::GetNumNode(); }

		// Insert an item before the header.
		void push_front( const ObjectType& obj )
		{ CLinkList< ObjectType >::AddHead( obj ); }

		// Insert an item after the tailer.
		void push_back( const ObjectType& obj )
		{ CLinkList< ObjectType >::AddTail( obj ); }

		// Release
		void clear( void );
};

// Release
template < class ObjectType >
void linklist< ObjectType >::clear( void )
{
	CLinkList< ObjectType >::Release();
	CLinkList< ObjectType >::Clear();
}

//===========================================================

#endif // _TEMPLATE_LINK_LIST_H_
