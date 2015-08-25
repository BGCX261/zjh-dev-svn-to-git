//===========================================================
//
// FileName: GTNew.h
//
// Desc: the functions for allocating and debuging memory
//
// Write by zjh - Nov/06/2003(Thu)
//
//===========================================================

#ifndef _GREENTEA_NEW_MEM_H_
#define _GREENTEA_NEW_MEM_H_

// Avoid [c2365 'operator new' redefinition previous definition was 'function']
// by including this header file
//#include <crtdbg.h>

//#include "GTBaseDef.h"
#include "GTNewLinkList.h"
//#include "GTNewHashTable.h"

#ifndef STDMOD
#define STDMOD
#endif /* STDMOD */

#define NEW_MEM_FILE_NAME_MAX (64)

// Thi structure is for an allocation.
struct StructMemUnit
{
	// the name name of allocating this memory unit
	char szFileName[NEW_MEM_FILE_NAME_MAX];

	// the line number of allocating this memory unit
	unsigned long nFileLine;

	// the length of allocating this memory unit
	unsigned long nSize;

	// the address of allocating this memory unit
	void *pPtr;
};

//===========================================================
//
// The Functions
//
//===========================================================


// Initialize the data structure for memory manager system.
// If the functions defined in this file cannot work well,
// please call new_Initialize(). If the system has been
// successfully initialized, and this function is called
// again, this call will be ignored. If this function is
// called successfully, true will be returned, othewise,
// false returned.
STDMOD bool new_Initialize( void );

// Release the data structure for memory allocation system.
// If this function has been successfully called, and this
// function is called again, this call will be ignored.
// If this function is called successfully, true will
// be returned, othewise, false returned.
STDMOD bool new_Release( void );

// Get the maximum amount of memory used
STDMOD long new_GetMaxAmountMemoryUsed( void );

// Get the maximum amount of memory used currently
STDMOD long new_GetAmountMemoryUsed( void );

// Dump the memory leak memory to a log-file
STDMOD bool new_DumpMemoryInfo(const tchar *szFileName);
STDMOD bool new_DumpMemoryInfo(); 

// Add a new memory info to the link-list
// If it successfully executes, it will return true, otherwise false.
//
// NOTE: This function is called by external functions, not for users.
bool new_AddMemoryInfo( void *ptr, unsigned int size, const char *file, int line );

// Delete a new memory info from the link-list
// If it successfully executes, it will return true, otherwise false.
//
// NOTE: This function is called by external functions, not for users.
bool new_DeleteMemoryInfo( void *ptr );

// \fn __new_malloc
// \brief Allocate a chunk of memory with nSize, in bytes.
// \param nSize - The size of memory.
// \return The pointer of new buffer.
// \sa __new_free.
// \note This function is only used internally.
STDMOD void* __new_malloc( size_t nSize );

// \fn __new_free
// \brief Free a chunk of memory that is allocated by __new_malloc.
// \param ptr - The pointer to be freed.
STDMOD void __new_free( void* ptr );

// \fn __new_malloc_aligned
// \brief Allocate a chunk of memory with nSize, in bytes.
// \param nSize - The size of memory.
// \return The pointer of new buffer.
// \sa __new_free.
// \note This function is only used internally.
STDMOD void* __new_malloc_aligned( size_t size, size_t alignment );

// \fn __new_free_aligned
// \brief Free a chunk of memory that is allocated by __new_malloc.
// \param ptr - The pointer to be freed.
STDMOD void __new_free_aligned( void* ptr );

// \fn new_malloc
// \brief Allocate a chunk of memory with nSize, in bytes.
// \param nSize - The size of memory.
// \return The pointer of new buffer.
// \sa new_free.
// \note This function is only used internally.
STDMOD void* new_malloc_debug( size_t nSize, const char* szFile = __FILE__, const int nLine = __LINE__ );

// \fn new_free
// \brief Free a chunk of memory that is allocated by __new_malloc.
// \param ptr - The pointer to be freed.
STDMOD void new_free_debug( void* ptr );

// \fn new_malloc_aligned_debug
// \brief Allocate a chunk of memory with nSize, in bytes.
// \param nSize - The size of memory.
// \return The pointer of new buffer.
// \sa new_free_aligned_debug.
// \note This function is only used internally.
STDMOD void* new_malloc_aligned_debug( size_t nSize, size_t alignment, const char* szFile = __FILE__, const int nLine = __LINE__ );

// \fn new_free_aligned_debug
// \brief Free a chunk of memory that is allocated by __new_malloc.
// \param ptr - The pointer to be freed.
STDMOD void new_free_aligned_debug( void* ptr );

#ifdef _DEBUG

#define new_malloc(nSize) new_malloc_debug(nSize,__FILE__,__LINE__)
#define new_free(ptr) new_free_debug(ptr)

#define new_malloc_aligned(nSize,alignment) new_malloc_aligned_debug(nSize,alignment,__FILE__,__LINE__)
#define new_free_aligned(ptr) new_free_aligned_debug(ptr)

#else // _DEBUG

#define new_malloc(nSize) __new_malloc(nSize)
#define new_free(ptr) __new_free(ptr)

#define new_malloc_aligned(nSize,alignment) __new_malloc_aligned(nSize,alignment)
#define new_free_aligned(ptr) __new_free_aligned(ptr)

#endif // _DEBUG

#ifdef _DEBUG

// new()
inline void * __cdecl operator new( unsigned int size, const char *file, int line )
{
	return new_malloc_debug( size, file, line );
}

// 和上面的 new() 配对，否则编译器给出警告
// delete()
inline void __cdecl operator delete( void *ptr, const char *file, int line )
{
	new_free_debug( ptr );
}

// delete()
inline void __cdecl operator delete( void *ptr )
{
	new_free_debug( ptr );
}

// new[]()
inline void * __cdecl operator new[]( size_t size, const char *file, int line )
{
	return new_malloc_debug( size, file, line );
}

// 和上面的 new[]() 配对，否则编译器给出警告
// delete[]()
inline void __cdecl operator delete[]( void *ptr, const char *file, int line )
{
	new_free_debug( ptr );
}

// delete[]()
inline void __cdecl operator delete[]( void *ptr )
{
	new_free_debug( ptr );
}

#define DEBUG_NEWMEM new(__FILE__,__LINE__)

#define new DEBUG_NEWMEM

#endif // _DEBUG

//-----------------------------------------------------------

//-----------------------------------------------------------
//
// This file defines and implements some structures and
// classes of hash tables for holding data. 
// If a collision occurs, use chain algorithm to solve it.
//
//-----------------------------------------------------------

//-----------------------------------------------------------
//
// Hash object item
//
// This structure holds an item of an object. UserDataType is
// a type of data defined by users. For example, if users
// want to hold float numbers, the syntax is:
//
// HashObjectItem<float> itemObject;
//
// NOTE: This structure is used by the class, not users.
//
//-----------------------------------------------------------
template < class UserDataType >
struct HashObjectItem
{
	// The key word(file name)
	void* m_pKeyWord;

	// The length of the key word
	unsigned long m_nKeyWordLen;

	// The data handling the user data
	UserDataType m_UserData;

	void Clear( void )
	{
		m_pKeyWord = NULL;
		m_nKeyWordLen = 0;
	}

	bool InitResItem( const void* pKeyWord, const unsigned long& nKeyWordLen, UserDataType& UserData )
	{
		ASSERT( pKeyWord );
		ASSERT( nKeyWordLen );

		m_pKeyWord = malloc( nKeyWordLen );
		if( NULL == m_pKeyWord )
		{
			return false;
		}
		// Save the key word
		memcpy( m_pKeyWord, pKeyWord, nKeyWordLen );
		m_nKeyWordLen = nKeyWordLen;
		// Save the user data
		m_UserData = UserData;

		return true;
	}

	void Release( void )
	{
		if( m_pKeyWord )
		{
			free( m_pKeyWord );
			m_pKeyWord = NULL;
		}

		Clear();
	}
};

//-----------------------------------------------------------
//
// Hash object map entry
//
// This structure defines an entry for a hash table.
// A hash table contains a list of this structure.
// For example, if users want to hold float numbers,
// the syntax is:
//
// HashObjectMapEntry<float> entry;
//
// NOTE: This structure is used by the class, not users.
//
//-----------------------------------------------------------
template < class UserDataType >
struct HashObjectMapEntry
{
	// The link list
	GTNewLinkList< HashObjectItem< UserDataType >* > m_ResList;

	void Clear( void )
	{
		m_ResList.Clear();
	}

	void Release( void )
	{
		HashObjectItem<UserDataType>* pResItem = NULL;
		unsigned long dwNumItems = m_ResList.GetNumObject();

		if( dwNumItems )
		{
			if( m_ResList.Start() )
			{
				for( unsigned long j=0; j<dwNumItems; j++ )
				{
					pResItem = m_ResList.GetObjectData();
					ASSERT( pResItem );
					pResItem->Release();
					free( pResItem );
					pResItem = NULL;
				} // for(j)
				
				m_ResList.End();
			}
		} // if( dwNumItems )

		m_ResList.Release();
	}
};

template <class UserDataType, unsigned long dwSizeOfMap>
class CHashTableMem
{
public:
	// The number of collisions
	unsigned long m_dwNumCollisions;

	// The res map
	HashObjectMapEntry<UserDataType> m_pResMap[dwSizeOfMap];

	// The size of the object map(how many items in m_pResMap)
	static unsigned long m_dwSizeOfMap;

	// The number of items appended
	unsigned long m_dwNumItemsAppended;

public:
	//-----------------------------------------
	// construction
	//-----------------------------------------
	void Clear( void );

    CHashTableMem();

	//-----------------------------------------
	// destruction
	//-----------------------------------------
	~CHashTableMem();

	//-----------------------------------------
	// Has functions accessor
	//-----------------------------------------

	// The function for generating codes
	unsigned long HashFunGetCode( const void* pKeyWord, const unsigned long nKeyWordLen );

	// The function for comparing two key words
	bool HashFunCompareKeyWord( const void* pKeyWord1, const unsigned long nKeyWordLen1, const void* pKeyWord2, const unsigned long nKeyWordLen2 );
	
	//-----------------------------------------
	// Main functions
	//-----------------------------------------

	// Is valid
	bool IsValid( void ) const { return (m_pResMap ? true : false); }

	// The number of items appended
	unsigned long GetNumItemsAppend( void ) const { return m_dwNumItemsAppended; }

	// Append an item
	bool AppendItem( const void* pKeyWord, const unsigned long& nKeyWordLen, UserDataType& UserData );

	// Delete an item
	bool DeleteItem( const void* pKeyWord, const unsigned long& nKeyWordLen );

	// Find an item according to the key word
	//
	// [Return]
	// If the function returns true, the item has been found. Otherwise, not.
	bool FindItem( const void* pKeyWord, const unsigned long& nKeyWordLen, UserDataType& UserData );

	// Get the map entry index
	unsigned long GetMapEntryIndex( const void* pKeyWord, const unsigned long& nKeyWordLen );

	// Release the hash table
	void ReleaseMap( void );

	// Get the number of items in the hash table
	unsigned long GetNumItems( void );
};

//===========================================================
//
// Desc: The function for generating codes
//
//===========================================================
template <class UserDataType, unsigned long dwSizeOfMap>
unsigned long CHashTableMem<UserDataType, dwSizeOfMap>::HashFunGetCode( const void* pKeyWord,
																	    const unsigned long nKeyWordLen )
{
	return (unsigned long)(*((unsigned long*)pKeyWord));
}

//===========================================================
//
// Desc: The function for comparing two key words
//
//===========================================================
template <class UserDataType, unsigned long dwSizeOfMap>
bool CHashTableMem<UserDataType, dwSizeOfMap>::HashFunCompareKeyWord( const void* pKeyWord1,
																	  const unsigned long nKeyWordLen1,
																	  const void* pKeyWord2,
																	  const unsigned long nKeyWordLen2 )
{
	unsigned long num1 = (unsigned long)(*((unsigned long*)pKeyWord1));
	unsigned long num2 = (unsigned long)(*((unsigned long*)pKeyWord2));

	return num1 == num2;
}

//===========================================================
//
// Desc: construction
//
//===========================================================
template <class UserDataType, unsigned long dwSizeOfMap>
void CHashTableMem<UserDataType, dwSizeOfMap>::Clear( void )
{
	// The number of collisions
	m_dwNumCollisions = 0;
	
	// The number of items appended
	m_dwNumItemsAppended = 0;

	for( uint32 i=0; i<m_dwSizeOfMap; i++ )
	{
		m_pResMap[i].Clear();
	}
}

template <class UserDataType, unsigned long dwSizeOfMap>
CHashTableMem<UserDataType, dwSizeOfMap>::CHashTableMem()
{
	Clear();
}



//===========================================================
//
// Desc: destruction
//
//===========================================================
template <class UserDataType, unsigned long dwSizeOfMap>
CHashTableMem<UserDataType, dwSizeOfMap>::~CHashTableMem()
{
	Clear();
}

//===========================================================
//
// Desc: Release the hash table
//
//===========================================================
template <class UserDataType, unsigned long dwSizeOfMap>
void CHashTableMem<UserDataType, dwSizeOfMap>::ReleaseMap( void )
{
	if( m_pResMap )
	{
		for( uint32 i=0; i<m_dwSizeOfMap; i++ )
		{
			m_pResMap[i].Release();			
		} // for(i)
	} // if( m_pResMap )

	Clear();

	return;
}

//===========================================================
//
// Desc: 计算入口索引号
//       将计算出来的文件名字序列的 Code 与表长度求余，
//       余数即为表入口索引
//
// [In]
// szKeyWord - The key word
//
// [Return]
// The index of a map entry
//
//===========================================================
template <class UserDataType, unsigned long dwSizeOfMap>
unsigned long CHashTableMem<UserDataType, dwSizeOfMap>::GetMapEntryIndex( const void* pKeyWord,
																		  const unsigned long& nKeyWordLen )
{
	ASSERT( pKeyWord );
	ASSERT( nKeyWordLen );
	
	unsigned long sum;

	sum = HashFunGetCode( pKeyWord, nKeyWordLen );
	sum %= m_dwSizeOfMap;

	return sum;
}

//===========================================================
//
// Desc: Append a res item into the table
//
// [In]
// szKeyWord - The key word of the res data
// pResData - The res data to be added
//
// [Return]
// TRUE/FALSE
//
//===========================================================
template <class UserDataType, unsigned long dwSizeOfMap>
bool CHashTableMem<UserDataType, dwSizeOfMap>::AppendItem( const void* pKeyWord,
								                           const unsigned long& nKeyWordLen,
								                           UserDataType& UserData )
{
	ASSERT( pKeyWord );

	// Init a res item
	HashObjectItem<UserDataType>* pResItem = (HashObjectItem<UserDataType>*)malloc( sizeof(HashObjectItem<UserDataType>) );
	if( NULL == pResItem )
	{
		return false;
	}
	pResItem->Clear();

	if( false == pResItem->InitResItem( pKeyWord, nKeyWordLen, UserData ) )
	{
		free( pResItem );
		pResItem = NULL;

		return false;
	}

	// Compute the map entry index according to the key word
	unsigned long dwMapEntryIndex = GetMapEntryIndex( pKeyWord, nKeyWordLen );
	if( false == m_pResMap[dwMapEntryIndex].m_ResList.AddTail( pResItem ) )
	{
		pResItem->Release();
		free( pResItem );
		pResItem = NULL;

		return false;
	}

	if( m_pResMap[dwMapEntryIndex].m_ResList.GetNumObject() > 1 )
	{
		m_dwNumCollisions++;
	}

	// Count the number of items
	m_dwNumItemsAppended++;

	return true;
}

//===========================================================
//
// Desc: Delete an item from the table
//
// [In]
// szKeyWord - The key word of the res data that will be deleted.
//
// [Return]
// TRUE/FALSE
//
//===========================================================
template <class UserDataType, unsigned long dwSizeOfMap>
bool CHashTableMem<UserDataType, dwSizeOfMap>::DeleteItem( const void* pKeyWord, const unsigned long& nKeyWordLen )
{
	ASSERT( pKeyWord && nKeyWordLen );
	
	HashObjectItem<UserDataType>* pResItem = NULL;
	HashObjectItem<UserDataType>* pResItemFound = NULL;
	// Compute the map entry index according to the key word
	unsigned long dwMapEntryIndex = GetMapEntryIndex( pKeyWord, nKeyWordLen );
	unsigned long dwNumItems = m_pResMap[dwMapEntryIndex].m_ResList.GetNumObject();

	if( m_pResMap[dwMapEntryIndex].m_ResList.Start() )
	{
		for( unsigned long i=0; i<dwNumItems; i++ )
		{
			pResItem = m_pResMap[dwMapEntryIndex].m_ResList.GetObjectData();
			ASSERT( pResItem );
			if( HashFunCompareKeyWord( pResItem->m_pKeyWord, pResItem->m_nKeyWordLen, pKeyWord, nKeyWordLen ) )
			{
				pResItemFound = pResItem;
				break;
			}
		}

		m_pResMap[dwMapEntryIndex].m_ResList.End();

		if( pResItemFound )
		{
			// Remove the res item from the list
			m_pResMap[dwMapEntryIndex].m_ResList.Remove( pResItemFound );
			
			// Release the res item
			pResItemFound->Release();
			free( pResItemFound );
			pResItemFound = NULL;

			m_dwNumItemsAppended--;

			return true;
		}
	}

	return false;
}

//===========================================================
//
// Desc: Find a res item from the table
//
// [In]
// pKeyWord    - The key word of the res data
// nKeyWordLen - The length of the key word
// UserData    - The user data
//
// [Out]
// UserData - For saving data returned
//
// [Return]
// If the function returns true, the item has been found.
// Otherwise, not.
//
//===========================================================
template <class UserDataType, unsigned long dwSizeOfMap>
bool CHashTableMem<UserDataType, dwSizeOfMap>::FindItem( const void* pKeyWord,
											             const unsigned long& nKeyWordLen,
											             UserDataType& UserData )
{
	ASSERT( pKeyWord && nKeyWordLen );

	HashObjectItem<UserDataType>* pResItem = NULL;
	HashObjectItem<UserDataType>* pResItemFound = NULL;
	// Compute the map entry index according to the key word
	unsigned long dwMapEntryIndex = GetMapEntryIndex( pKeyWord, nKeyWordLen );
	unsigned long dwNumItems = m_pResMap[dwMapEntryIndex].m_ResList.GetNumObject();
	
	if( m_pResMap[dwMapEntryIndex].m_ResList.Start() )
	{
		for( unsigned long i=0; i<dwNumItems; i++ )
		{
			pResItem = m_pResMap[dwMapEntryIndex].m_ResList.GetObjectData();
			ASSERT( pResItem );
			if( HashFunCompareKeyWord( pResItem->m_pKeyWord, pResItem->m_nKeyWordLen, pKeyWord, nKeyWordLen ) )
			{
				pResItemFound = pResItem;
				break;
			}
		}

		m_pResMap[dwMapEntryIndex].m_ResList.End();
	}

	if( pResItemFound )
	{
		// Save the item found
		UserData = pResItemFound->m_UserData;

		return true;
	}

	return false;
}

//===========================================================
//
// Desc: Get the number of items in the hash table
//
//===========================================================
template <class UserDataType, unsigned long dwSizeOfMap>
unsigned long CHashTableMem<UserDataType, dwSizeOfMap>::GetNumItems( void )
{
	unsigned long dwNumItems = 0;
	for( unsigned long i=0; i<m_dwSizeOfMap; i++ )
	{
		dwNumItems += m_pResMap[i].m_ResList.GetNumObject();
	}

	return dwNumItems;
}

// Initialize the static members
template <class UserDataType, unsigned long dwSizeOfMap>
unsigned long CHashTableMem<UserDataType, dwSizeOfMap>::m_dwSizeOfMap = dwSizeOfMap;

//-----------------------------------------------------------


//===========================================================
//
// GTNew
//
//===========================================================

class GTNew : public CHashTableMem<StructMemUnit*, 10000>
{
public:
	// The amount of memory currently used
	long m_memory_used_cur;

	// The maximum amount of memory ever used
	long m_memory_used_max;

public:
	//-----------------------------------------
	// construction
	//-----------------------------------------
	void Clear( void );

    GTNew();

	//-----------------------------------------
	// destruction
	//-----------------------------------------
	virtual ~GTNew();

	// add a mem-unit
	void AddMemUnit( StructMemUnit *pMemUnit );
};

#define GTNEW_SAFE_DELETE(ptr) if(ptr) { delete ptr; ptr = NULL; }
#define GTNEW_SAFE_DELETE_ARRAY(ptr) if(ptr) { delete [] ptr; ptr = NULL; }

//===========================================================

#endif // _GREENTEA_NEW_MEM_H_
