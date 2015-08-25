//===========================================================
//
// FileName: HashTableObject.h
//
// Desc: The hash table
//
// Written by J. H. ZHANG - Aug/09/2004(Mon)
//
//===========================================================

#ifndef _HASH_TABLE_OBJECT_H_
#define _HASH_TABLE_OBJECT_H_

#include "GTNewLinkList.h"

#ifndef STDMOD
#define STDMOD
#endif /* STDMOD */

#ifndef ASSERT
#define ASSERT
#endif /* ASSERT */

// Note: Because this file is a template source file, so it
//       does not include any header file. If you want to
//       use this file, please add basic header files before
//       including this file.
//
// Example:
//         #include <LinkList.h>
//         #include <HashTableObject.h>
//
// The notice above is just a suggestion, if your souece file
// can be correctly compiled. You don't need to include above
// header file.

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

//-----------------------------------------------------------
//
// The hash function for generating hash codes.
//
// [In]
// pKeyWord    - The key word
// nKeyWordLen - The length of the key word
//
// [Return]
// The index of a map entry
//
//-----------------------------------------------------------
typedef unsigned long (*HashTableFunction_GetCode)( const void* pKeyWord, const unsigned long nKeyWordLen );

//-----------------------------------------------------------
//
// The hash function for comparing two key words.
//
// [In]
// pKeyWord1    - The first key word
// nKeyWordLen1 - The length of the first key word
// pKeyWord2    - The second key word
// nKeyWordLen2 - The length of the second key word
//
// [Return]
// true  - The two key words are completely same.
// false - The two key words are NOT same.
//
//-----------------------------------------------------------
typedef bool (*HashTableFunction_CompareKeyWord)( const void* pKeyWord1, const unsigned long nKeyWordLen1, const void* pKeyWord2, const unsigned long nKeyWordLen2 );

//-----------------------------------------------------------
//
// The functions pre-defined by this structure are for
// generating hash codes for according to key words.
//
//-----------------------------------------------------------
struct STDMOD HashFun
{
	// Numbers

	// This hash function is for 1 byte number, such as char and unsigned char.
	static unsigned long HashFun_GenerateCode_1ByteNumber( const void* pKeyWord, const unsigned long nKeyWordLen );

	// This hash function is for 2 bytes numbers, such as short and unsigned short.
	static unsigned long HashFun_GenerateCode_2ByteNumber( const void* pKeyWord, const unsigned long nKeyWordLen );
	
	// This hash function is for 4 bytes numbers, such as int, unsigned int, long and unsigned long.
	static unsigned long HashFun_GenerateCode_4ByteNumber( const void* pKeyWord, const unsigned long nKeyWordLen );
	
	// File Names
	static unsigned long HashFun_GenerateCode_FileName( const void* pKeyWord, const unsigned long nKeyWordLen );
	
	// Strings with case
	// For example, there two key words, ABC and abc. The results of them are NOT same.
	static unsigned long HashFun_GenerateCode_StringCase( const void* pKeyWord, const unsigned long nKeyWordLen );
	
	// Strings with no case
	// For example, there two key words, ABC and abc. The results of them are same.
	static unsigned long HashFun_GenerateCode_StringNoCase( const void* pKeyWord, const unsigned long nKeyWordLen );
	
	// Raw data
	static unsigned long HashFun_GenerateCode_RawData( const void* pKeyWord, const unsigned long nKeyWordLen );
};

//-----------------------------------------------------------
//
// The functions pre-defined by this structure are for
// comparing key words.
//
//-----------------------------------------------------------
struct STDMOD HashCmpKeyFun
{
	// Numbers

	// This hash function is for 1 byte number, such as char and unsigned char.
	static bool HashFun_CompareKeyWord_1ByteNumber( const void* pKeyWord1, const unsigned long nKeyWordLen1, const void* pKeyWord2, const unsigned long nKeyWordLen2 );
	
	// This hash function is for 2 bytes numbers, such as short and unsigned short.
	static bool HashFun_CompareKeyWord_2ByteNumber( const void* pKeyWord1, const unsigned long nKeyWordLen1, const void* pKeyWord2, const unsigned long nKeyWordLen2 );
	
	// This hash function is for 4 bytes numbers, such as int, unsigned int, long and unsigned long.
	static bool HashFun_CompareKeyWord_4ByteNumber( const void* pKeyWord1, const unsigned long nKeyWordLen1, const void* pKeyWord2, const unsigned long nKeyWordLen2 );
	
	// File Names
	static bool HashFun_CompareKeyWord_FileName( const void* pKeyWord1, const unsigned long nKeyWordLen1, const void* pKeyWord2, const unsigned long nKeyWordLen2 );
	
	// Strings with case
	// For example, there two key words, ABC and abc. The results of them are NOT same.
	static bool HashFun_CompareKeyWord_StringCase( const void* pKeyWord1, const unsigned long nKeyWordLen1, const void* pKeyWord2, const unsigned long nKeyWordLen2 );
	
	// Strings with no case
	// For example, there two key words, ABC and abc. The results of them are same.
	static bool HashFun_CompareKeyWord_StringNoCase( const void* pKeyWord1, const unsigned long nKeyWordLen1, const void* pKeyWord2, const unsigned long nKeyWordLen2 );
	
	// Raw data
	static bool HashFun_CompareKeyWord_RawData( const void* pKeyWord1, const unsigned long nKeyWordLen1, const void* pKeyWord2, const unsigned long nKeyWordLen2 );
};

//===========================================================
//
// CHashTableObject
//
// This hash table class is for holding data. For example,
// if users want to hold float numbers. They will follow
// the following steps.
//
// STEP - 1: Define the hash table.
//
// CHashTableObject<float> hashTable;
//
//
// STEP - 2: Create the hash table. The parameter dwMapSize
//           controls how large the internal table is.
//           The larger it is, the less collisions are likely,
//           but larger numbers means more memory usage.
//           For this example, the size of the table is 10.
//           If successfully, it returns true.
//
// hashTable.CreateTable( 10 );
//
//
// STEP - 3: Append items. 
//
// hashTable.Append( (float)10.0f );
// hashTable.Append( (float)20.0f );
// hashTable.Append( (float)30.0f );
//
//
// STEP - 4: Search an item. If the item exists in the table,
//           the function returns true, otherwise false.
//
// hashTable.FindItem( (float)20.0f );
//
//
// STEP - 5: Release the hash table.
//
// hashTable.ReleaseMap();
//
//===========================================================
template < class UserDataType >
class CHashTableObject
{
public:
	// The number of collisions
	unsigned long m_dwNumCollisions;

	// The res map
	HashObjectMapEntry<UserDataType> *m_pResMap;

	// The size of the object map(how many items in m_pResMap)
	unsigned long m_dwSizeOfMap;

	// The function for generating codes
	HashTableFunction_GetCode HashFunGetCode;

	// The function for comparing two key words
	HashTableFunction_CompareKeyWord HashFunCompareKeyWord;

	// The number of items appended
	unsigned long m_dwNumItemsAppended;

public:
	//-----------------------------------------
	// construction
	//-----------------------------------------
	void Clear( void );

    CHashTableObject();

	//-----------------------------------------
	// destruction
	//-----------------------------------------
	~CHashTableObject();

	//-----------------------------------------
	// Has functions accessor
	//-----------------------------------------

	void SetHashFun( HashTableFunction_GetCode pHashFunGetCode ) { HashFunGetCode = pHashFunGetCode; }

	HashTableFunction_GetCode GetHashFun( void ) const { return HashFunGetCode; }

	void SetCompareFun( HashTableFunction_CompareKeyWord pHashFunCompareKeyWord ) { HashFunCompareKeyWord = pHashFunCompareKeyWord; }

	HashTableFunction_CompareKeyWord SetCompareFun( void ) const { return HashFunCompareKeyWord; }

	//-----------------------------------------
	// Main functions
	//-----------------------------------------

	// Is valid
	bool IsValid( void ) const { return (m_pResMap ? true : false); }

	// The number of items appended
	unsigned long GetNumItemsAppend( void ) const { return m_dwNumItemsAppended; }

	// Create the hash table. The parameter dwMapSize controls how large the
	// internal table is. The larger it is, the less collisions are likely,
	// but larger numbers means more memory usage.
	bool CreateMap( const unsigned long& dwMapSize );

	// Append an item
	bool AppendItem( const void* pKeyWord, const unsigned long& nKeyWordLen, UserDataType& UserData );

	bool AppendItem( char UserData ) { return AppendItem( (void*)&UserData, sizeof(UserData), UserData ); }
	bool AppendItem( unsigned char UserData ) { return AppendItem( (void*)&UserData, sizeof(UserData), UserData ); }
	bool AppendItem( short UserData ) { return AppendItem( (void*)&UserData, sizeof(UserData), UserData ); }
	bool AppendItem( unsigned short UserData ) { return AppendItem( (void*)&UserData, sizeof(UserData), UserData ); }
	bool AppendItem( int UserData ) { return AppendItem( (void*)&UserData, sizeof(UserData), UserData ); }
	bool AppendItem( unsigned int UserData ) { return AppendItem( (void*)&UserData, sizeof(UserData), UserData ); }
	bool AppendItem( long UserData ) { return AppendItem( (void*)&UserData, sizeof(UserData), UserData ); }
	bool AppendItem( unsigned long UserData ) { return AppendItem( (void*)&UserData, sizeof(UserData), UserData ); }
	bool AppendItem( float UserData ) { return AppendItem( (void*)&UserData, sizeof(UserData), UserData ); }
	bool AppendItem( double UserData ) { return AppendItem( (void*)&UserData, sizeof(UserData), UserData ); }
	bool AppendItem( char* UserData ) { return AppendItem( (void*)UserData, strlen(UserData)+1, UserData ); }

	// Delete an item
	bool DeleteItem( const void* pKeyWord, const unsigned long& nKeyWordLen );

	bool DeleteItem( char UserData ) { return DeleteItem( (void*)&UserData, sizeof(UserData) ); }
	bool DeleteItem( unsigned char UserData ) { return DeleteItem( (void*)&UserData, sizeof(UserData) ); }
	bool DeleteItem( short UserData ) { return DeleteItem( (void*)&UserData, sizeof(UserData) ); }
	bool DeleteItem( unsigned short UserData ) { return DeleteItem( (void*)&UserData, sizeof(UserData) ); }
	bool DeleteItem( int UserData ) { return DeleteItem( (void*)&UserData, sizeof(UserData) ); }
	bool DeleteItem( unsigned int UserData ) { return DeleteItem( (void*)&UserData, sizeof(UserData) ); }
	bool DeleteItem( long UserData ) { return DeleteItem( (void*)&UserData, sizeof(UserData) ); }
	bool DeleteItem( unsigned long UserData ) { return DeleteItem( (void*)&UserData, sizeof(UserData) ); }
	bool DeleteItem( float UserData ) { return DeleteItem( (void*)&UserData, sizeof(UserData) ); }
	bool DeleteItem( double UserData ) { return DeleteItem( (void*)&UserData, sizeof(UserData) ); }
	bool DeleteItem( char* UserData ) { return DeleteItem( (void*)UserData, sizeof(UserData) ); }

	// Find an item according to the key word
	//
	// [Return]
	// If the function returns true, the item has been found. Otherwise, not.
	bool FindItem( const void* pKeyWord, const unsigned long& nKeyWordLen, UserDataType& UserData );

	bool FindItem( char UserData ) { char tmp; return FindItem( (void*)&UserData, sizeof(UserData), tmp ); }
	bool FindItem( unsigned char UserData ) { unsigned char tmp; return FindItem( (void*)&UserData, sizeof(UserData), tmp ); }
	bool FindItem( short UserData ) { short tmp; return FindItem( (void*)&UserData, sizeof(UserData), tmp ); }
	bool FindItem( unsigned short UserData ) { unsigned short tmp; return FindItem( (void*)&UserData, sizeof(UserData), tmp ); }
	bool FindItem( int UserData ) { int tmp; return FindItem( (void*)&UserData, sizeof(UserData), tmp ); }
	bool FindItem( unsigned int UserData ) { unsigned int tmp; return FindItem( (void*)&UserData, sizeof(UserData), tmp ); }
	bool FindItem( long UserData ) { long tmp; return FindItem( (void*)&UserData, sizeof(UserData), tmp ); }
	bool FindItem( unsigned long UserData ) { unsigned long tmp; return FindItem( (void*)&UserData, sizeof(UserData), tmp ); }
	bool FindItem( float UserData ) { float tmp; return FindItem( (void*)&UserData, sizeof(UserData), tmp ); }
	bool FindItem( double UserData ) { double tmp; return FindItem( (void*)&UserData, sizeof(UserData), tmp ); }

	// Get the map entry index
	unsigned long GetMapEntryIndex( const void* pKeyWord, const unsigned long& nKeyWordLen );

	// Release the hash table
	void ReleaseMap( void );

	// Get the number of items in the hash table
	unsigned long GetNumItems( void );
};



//===========================================================
//
// Desc: construction
//
//===========================================================
template < class UserDataType >
void CHashTableObject< UserDataType >::Clear( void )
{
	// The number of collisions
	m_dwNumCollisions = 0;
	
	// The res map
	m_pResMap = NULL;

	// The size of the res map(how many items in m_pResMap)
	m_dwSizeOfMap = 0;

	// The function for generating codes
	SetHashFun( HashFun::HashFun_GenerateCode_RawData );

	// The function for comparing two key words
	SetCompareFun( HashCmpKeyFun::HashFun_CompareKeyWord_RawData );

	// The number of items appended
	m_dwNumItemsAppended = 0;
}

template < class UserDataType >
CHashTableObject< UserDataType >::CHashTableObject()
{
	Clear();
}



//===========================================================
//
// Desc: destruction
//
//===========================================================
template < class UserDataType >
CHashTableObject< UserDataType >::~CHashTableObject()
{
	Clear();
}



//===========================================================
//
// Desc: Create the hash table. The parameter dwMapSize
//       controls how large the internal table is.
//       The larger it is, the less collisions are likely,
//       but larger numbers means more memory usage.
//
// [In]
// dwMapSize - The size of the hash table
//
// [Return]
// TRUE/FALSE
//
//===========================================================
template < class UserDataType >
bool CHashTableObject< UserDataType >::CreateMap( const unsigned long& dwMapSize )
{
	if( 0 == dwMapSize )
	{
		return false;
	}

	// If the table is already valid, ignor this call.
	if( IsValid() )
	{
		return true;
	}

	uint32 dwMemSize = sizeof(HashObjectMapEntry<UserDataType>)*dwMapSize;
	m_pResMap = (HashObjectMapEntry<UserDataType>*)malloc( dwMemSize );
	if( NULL == m_pResMap )
	{
		return false;
	}

	m_dwNumCollisions = 0;
	m_dwSizeOfMap = dwMapSize;
	m_dwNumItemsAppended = 0;

	for( uint32 i=0; i<m_dwSizeOfMap; i++ )
	{
		m_pResMap[i].Clear();
	}

	return true;
}



//===========================================================
//
// Desc: Release the hash table
//
//===========================================================
template < class UserDataType >
void CHashTableObject< UserDataType >::ReleaseMap( void )
{
	if( m_pResMap )
	{
		for( uint32 i=0; i<m_dwSizeOfMap; i++ )
		{
			m_pResMap[i].Release();			
		} // for(i)

		free( m_pResMap );
		m_pResMap = NULL;
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
template < class UserDataType >
unsigned long CHashTableObject< UserDataType >::GetMapEntryIndex( const void* pKeyWord, const unsigned long& nKeyWordLen )
{
	ASSERT( pKeyWord );
	ASSERT( nKeyWordLen );
	ASSERT( HashFunGetCode );

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
template < class UserDataType >
bool CHashTableObject< UserDataType >::AppendItem( const void* pKeyWord,
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
template < class UserDataType >
bool CHashTableObject< UserDataType >::DeleteItem( const void* pKeyWord, const unsigned long& nKeyWordLen )
{
	ASSERT( pKeyWord && nKeyWordLen );
	ASSERT( HashFunCompareKeyWord );

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

			// Decrease the counter
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
template < class UserDataType >
bool CHashTableObject< UserDataType >::FindItem( const void* pKeyWord,
											   const unsigned long& nKeyWordLen,
											   UserDataType& UserData )
{
	ASSERT( pKeyWord && nKeyWordLen );
	ASSERT( HashFunCompareKeyWord );

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
template < class UserDataType >
unsigned long CHashTableObject< UserDataType >::GetNumItems( void )
{
	unsigned long dwNumItems = 0;
	for( unsigned long i=0; i<m_dwSizeOfMap; i++ )
	{
		dwNumItems += m_pResMap[i].m_ResList.GetNumObject();
	}

	return dwNumItems;
}

//===========================================================

#endif // _HASH_TABLE_OBJECT_H_
