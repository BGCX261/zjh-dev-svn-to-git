//===========================================================
//
// FileName: NewMem.cpp
//
// Desc: the functions for allocating and debuging memory
//
// Write by zjh - Nov/06/2003(Thu)
//
//===========================================================

#include "GTNew.h"

// the global memory instance
static GTNew _g_new_memory;

static const long _g_long_string_size = (NEW_MEM_FILE_NAME_MAX - 1 - 11);

//===========================================================
//
// Desc: Initialize the data structure for memory manager system.
//       If the functions defined in this file cannot work well,
//	     please call new_Initialize(). If the system has been
//       successfully initialized, and this function is called
//       again, this call will be ignored. If this function is
//       called successfully, true will be returned, othewise,
//       false returned.
//
// [Return]
// true/false
//
//===========================================================
bool new_Initialize( void )
{
	return true;
}

//===========================================================
//
// Desc: Release the data structure for memory allocation system.
//       If this function has been successfully called, and this
//       function is called again, this call will be ignored.
//       If this function is called successfully, true will
//       be returned, othewise, false returned.
//
// [Return]
// true/false
//
//===========================================================
bool new_Release( void )
{
	return true;
}

//===========================================================
//
// Desc: Add a new memory info to the hash table
//       If it successfully executes, it will return true, otherwise false.
//
// [In]
// ptr - The start address allocated
// size - The memory size of ptr
// file - The file name calling this function
// line - The line number calling this function
//
// [Return]
// true/false
//
//===========================================================
// Hash table version
bool new_AddMemoryInfo( void *ptr, unsigned int size, const char *file, int line )
{
	StructMemUnit *pMemUnit = (StructMemUnit*)malloc( sizeof(StructMemUnit) );
	if( pMemUnit )
	{
		// the name name of allocating this memory unit
		if( StringLengthA( file ) < NEW_MEM_FILE_NAME_MAX )
		{
			//StringCopyA( pMemUnit->szFileName, NEW_MEM_FILE_NAME_MAX, file );
			StringCopyA( pMemUnit->szFileName, file );
		}
		else
		{
			StringCopyNA( pMemUnit->szFileName, file, 8 );
			pMemUnit->szFileName[8]  = '\0';
			StringCatA( pMemUnit->szFileName, "..." );
			StringCatA( pMemUnit->szFileName, &file[_g_long_string_size] );
		}
		
		// the line number of allocating this memory unit
		pMemUnit->nFileLine = line;
		
		// the length of allocating this memory unit
		pMemUnit->nSize = size;
		
		// the address of allocating this memory unit
		pMemUnit->pPtr = ptr;

		// count the amnount of memory
		_g_new_memory.m_memory_used_cur += size;
		if( _g_new_memory.m_memory_used_cur > _g_new_memory.m_memory_used_max )
		{
			_g_new_memory.m_memory_used_max = _g_new_memory.m_memory_used_cur;
		}

		// add this mem-unit to the _g_new_memory
		unsigned int dwAddress = (unsigned int)(pMemUnit->pPtr);
		_g_new_memory.AppendItem( (void*)&dwAddress, sizeof(dwAddress), pMemUnit );
	}
	else
	{
		return false;
	}

	return true;
}

//===========================================================
//
// Desc: Delete a new memory info from the link-list
//       If it successfully executes, it will return true, otherwise false.
//
// [In]
// ptr - the memory address to be freed
//
// [Return]
// true/false
//
//===========================================================
// Hash table version
bool new_DeleteMemoryInfo( void *ptr )
{
	if( NULL == ptr )
	{
		return false;
	}

	// Find the memory unit holding ptr
	StructMemUnit *pMemUnit = NULL;
	uint32 dwAddress = (uint32)ptr;
	if( _g_new_memory.FindItem( (void*)&dwAddress, sizeof(dwAddress), pMemUnit ) )
	{
		if( pMemUnit )
		{
			// Delete this memory unit from the table
			dwAddress = (uint32)ptr;
			if( _g_new_memory.DeleteItem( (void*)&dwAddress, sizeof(dwAddress) ) )
			{
				// Decrease the amount of memroy
				_g_new_memory.m_memory_used_cur -= pMemUnit->nSize;
			}

			// Release the memory
			free( pMemUnit );
			pMemUnit = NULL;
		}
	}
	else
	{
		return false;
	}
	
	return true;
}

// \fn __new_malloc
// \brief Allocate a chunk of memory with nSize, in bytes.
// \param nSize - The size of memory.
// \return The pointer of new buffer.
// \sa __new_free.
// \note This function is only used internally.
void* __new_malloc( size_t nSize )
{
	return malloc( nSize );
}

// \fn __new_free
// \brief Free a chunk of memory that is allocated by __new_malloc.
// \param ptr - The pointer to be freed.
void __new_free( void* ptr )
{
	free( ptr );
}

#define NEW_IS_2_POW_N(X)   (((X)&(X-1)) == 0)

// \fn __new_malloc_aligned
// \brief Allocate a chunk of memory with nSize, in bytes.
// \param nSize - The size of memory.
// \return The pointer of new buffer.
// \sa __new_free_aligned.
// \note This function is only used internally.
STDMOD void* __new_malloc_aligned( size_t size, size_t alignment )
{
	size_t ptr, r_ptr;
    size_t *reptr;

    if (!NEW_IS_2_POW_N(alignment))
    {
        return NULL;
    }

    alignment = (alignment > sizeof(void *) ? alignment : sizeof(void *));

    if ((ptr = (size_t)malloc(size + alignment + sizeof(void *))) == (size_t)NULL)
	{
        return NULL;
	}

    r_ptr = (ptr + alignment + sizeof(void *)) & ~(alignment -1);
    reptr = (size_t *)(r_ptr - sizeof(void *));
    *reptr = ptr;

    return (void *)r_ptr;
}

// \fn __new_free_aligned
// \brief Free a chunk of memory that is allocated by __new_malloc.
// \param ptr - The pointer to be freed.
STDMOD void __new_free_aligned( void* memblock )
{
	size_t ptr;

    if (memblock == NULL)
	{
        return;
	}

    ptr = (size_t)memblock;

    /* ptr points to the pointer to starting of the memory block */
    ptr = (ptr & ~(sizeof(void *) -1)) - sizeof(void *);

    /* ptr is the pointer to the start of memory block*/
    ptr = *((size_t *)ptr);
    free((void *)ptr);
}

// \fn new_malloc
// \brief Allocate a chunk of memory with nSize, in bytes.
// \param nSize - The size of memory.
// \return The pointer of new buffer.
// \sa new_free.
// \note This function is only used internally.
void* new_malloc_debug( size_t nSize, const char* szFile, const int nLine )
{
	if( 0 == nSize )
	{
		return NULL;
	}

	void *ptr = (void*)__new_malloc( nSize );

	if( ptr )
	{
		new_AddMemoryInfo( ptr, nSize, szFile, nLine );
	}

	return ptr;
}

// \fn new_free
// \brief Free a chunk of memory that is allocated by __new_malloc.
// \param ptr - The pointer to be freed.
void new_free_debug( void* ptr )
{
	if( new_DeleteMemoryInfo( ptr ) )
	{
		__new_free( ptr );
	}
}

// \fn new_malloc_aligned_debug
// \brief Allocate a chunk of memory with nSize, in bytes.
// \param nSize - The size of memory.
// \return The pointer of new buffer.
// \sa new_free_aligned_debug.
// \note This function is only used internally.
STDMOD void* new_malloc_aligned_debug( size_t nSize, size_t alignment, const char* szFile, const int nLine )
{
	if( 0 == nSize )
	{
		return NULL;
	}

	void *ptr = (void*)__new_malloc_aligned( nSize, alignment );

	if( ptr )
	{
		new_AddMemoryInfo( ptr, nSize, szFile, nLine );
	}

	return ptr;
}

// \fn new_free_aligned_debug
// \brief Free a chunk of memory that is allocated by __new_malloc.
// \param ptr - The pointer to be freed.
STDMOD void new_free_aligned_debug( void* ptr )
{
	if( new_DeleteMemoryInfo( ptr ) )
	{
		__new_free_aligned( ptr );
	}
}

//===========================================================
//
// Desc: Get maximum amount of memory used
//
//===========================================================
long new_GetMaxAmountMemoryUsed( void )
{
	return _g_new_memory.m_memory_used_max;
}

//===========================================================
//
// Desc: Get the amount of memory used currently
//
//===========================================================
long new_GetAmountMemoryUsed( void )
{
	return _g_new_memory.m_memory_used_cur;
}

//===========================================================
//
// Desc: Dump the memory leak memory to a log-file
//
//===========================================================
// Hash table version
bool new_DumpMemoryInfo()
{
	char szFileNameT[260];
	strcpy(szFileNameT,  CTEXT("DumpMemInfo.txt"));
	return new_DeleteMemoryInfo(szFileNameT);
}

bool new_DumpMemoryInfo( const tchar *szFileNameT )
#if _MSC_VER >= 1400
{
	char szFileName[GT_PATH_MAX_LEN];

#ifdef BASEDEF_UNICODE
	OSA::UnicodeToAnsi(szFileNameT, -1, szFileName, GT_PATH_MAX_LEN);
#else /* BASEDEF_UNICODE */
	StringCopyA(szFileName, szFileNameT);
#endif /* BASEDEF_UNICODE */

	FILE *fp = NULL;
	static char buf[512];

	if( 0 == StringLengthA( szFileName ) )
	{
		// the file name is invalid
		return false;
	}

	fp = fopen( szFileName, "w" );
	if( NULL == fp )
	{
		return false;
	}

	sprintf_s( buf, "\n" );
	fprintf( fp, buf );

	sprintf_s( buf, "  Debug File\n" );
	fprintf( fp, buf );

	sprintf_s( buf, "----------------------------------------------\n" );
	fprintf( fp, buf );

	sprintf_s( buf, "  This file can help you to find memory leaks.\n" );
	fprintf( fp, buf );

	sprintf_s( buf, "----------------------------------------------\n" );
	fprintf( fp, buf );

	sprintf_s( buf, "\n" );
	fprintf( fp, buf );

	sprintf_s( buf, "  Debug Information  \n" );
	fprintf( fp, buf );

	sprintf_s( buf, "=====================\n" );
	fprintf( fp, buf );

	sprintf_s( buf, "\n" );
	fprintf( fp, buf );

	//---------------------------------------//

	fprintf( fp, "Checking memory leaks...\n" );
	fprintf( fp, "\n" );

	// check the memory list and release the memory units unfreed
	uint32 dwNumUnits = _g_new_memory.GetNumItems();
	sprintf_s( buf, 256, "The Number of Memory-Units Unfreed : %ld\n", dwNumUnits );
	fprintf( fp, buf );
	fprintf( fp, "\n" );

	uint32 dwSize = 0;
	HashObjectItem<StructMemUnit*>* pHashItem = NULL;
	StructMemUnit *pMemUnit = NULL;
	uint32 dwCount = 0;
	for( uint32 j=0; j<_g_new_memory.m_dwSizeOfMap; j++ )
	{
		dwNumUnits = _g_new_memory.m_pResMap[j].m_ResList.GetNumObject();
		if( dwNumUnits )
		{
			if( _g_new_memory.m_pResMap[j].m_ResList.Start() )
			{
				for( uint32 i=0; i<dwNumUnits; i++ )
				{
					// Get a memory unit
					pHashItem = _g_new_memory.m_pResMap[j].m_ResList.GetObjectData();
					pMemUnit = (StructMemUnit*)pHashItem->m_UserData;
					// Get the size of the memory
					dwSize += pMemUnit->nSize;
					// Output the buffer
					sprintf_s( buf, 256, "(%ld) - FILE: %s, LINE: %ld, SIZE: %ld Bytes\n", dwCount, pMemUnit->szFileName, pMemUnit->nFileLine, pMemUnit->nSize );
					dwCount++;
					fprintf( fp, buf );
				} // for(i)
				
				_g_new_memory.m_pResMap[j].m_ResList.End();
			}
		}
	} // for(j)

	const unsigned int nOneKB = 1024;
	const unsigned int nOneMB = 1024*1024;

	fprintf( fp, "\n" );
	if( dwSize < nOneKB )
	{
		sprintf_s( buf, 256, "The Amount of Memory Unfreed : %ld Byte\n", dwSize );
	}
	else if( dwSize >= nOneKB && dwSize < nOneMB)
	{
		sprintf_s( buf, 256, "The Amount of Memory Unfreed : %ld Byte(%.2f KB)\n", dwSize, (FLOAT)dwSize/1024.0f );
	}
	else // dwSize >= 1024*1024 MB
	{
		sprintf_s( buf, 256, "The Amount of Memory Unfreed : %ld Byte(%.2f MB)\n", dwSize, (FLOAT)dwSize/(1024.0f*1024.0f) );
	}
	fprintf( fp, buf );
	if( _g_new_memory.m_memory_used_max < nOneMB )
	{
		sprintf_s( buf, 256, "The Maximum Amount of Memory Used : %ld Byte\n", _g_new_memory.m_memory_used_max );
	}
	else if( _g_new_memory.m_memory_used_max >= nOneKB && _g_new_memory.m_memory_used_max < nOneMB)
	{
		sprintf_s( buf, 256, "The Maximum Amount of Memory Used : %ld Byte/(%.2f KB)\n", _g_new_memory.m_memory_used_max, (FLOAT)_g_new_memory.m_memory_used_max/1024.0f );
	}
	else // _g_new_memory.m_memory_used_max >= 1024*1024 KBs(1 MB)
	{
		sprintf_s( buf, 256, "The Maximum Amount of Memory Used : %ld Byte/(%.2f MB)\n", _g_new_memory.m_memory_used_max, (FLOAT)_g_new_memory.m_memory_used_max/(1024.0f*1024.0f) );
	}
	fprintf( fp, buf );
	fprintf( fp, "\n" );

	//---------------------------------------//

	fclose( fp );
	fp = NULL;

	return true;
}
#else /* _MSC_VER >= 1400 */
{
    char szFileName[GT_PATH_MAX_LEN];
#ifdef BASEDEF_UNICODE
	OSA::UnicodeToAnsi(szFileNameT, -1, szFileName, GT_PATH_MAX_LEN);
#else /* BASEDEF_UNICODE */
	StringCopyA(szFileName, szFileNameT);
#endif /* BASEDEF_UNICODE */
    
	FILE *fp = NULL;
	static char buf[256];

	if( 0 == strlen( szFileName ) )
	{
		// the file name is invalid
		return false;
	}

	fp = fopen( szFileName, "w" );
	if( NULL == fp )
	{
		return false;
	}

	sprintf( buf, "\n" );
	fprintf( fp, buf );

	sprintf( buf, "  Debug File\n" );
	fprintf( fp, buf );

	sprintf( buf, "----------------------------------------------\n" );
	fprintf( fp, buf );

	sprintf( buf, "  This file can help you to find memory leaks.\n" );
	fprintf( fp, buf );

	sprintf( buf, "----------------------------------------------\n" );
	fprintf( fp, buf );

	sprintf( buf, "\n" );
	fprintf( fp, buf );

	sprintf( buf, "  Debug Information  \n" );
	fprintf( fp, buf );

	sprintf( buf, "=====================\n" );
	fprintf( fp, buf );

	sprintf( buf, "\n" );
	fprintf( fp, buf );

	//---------------------------------------//

	fprintf( fp, "Checking memory leaks...\n" );
	fprintf( fp, "\n" );

	// check the memory list and release the memory units unfreed
	uint32 dwNumUnits = _g_new_memory.GetNumItems();
	sprintf( buf, "The Number of Memory-Units Unfreed : %ld\n", dwNumUnits );
	fprintf( fp, buf );
	fprintf( fp, "\n" );

	uint32 dwSize = 0;
	HashObjectItem<StructMemUnit*>* pHashItem = NULL;
	StructMemUnit *pMemUnit = NULL;
	uint32 dwCount = 0;
	for( uint32 j=0; j<_g_new_memory.m_dwSizeOfMap; j++ )
	{
		dwNumUnits = _g_new_memory.m_pResMap[j].m_ResList.GetNumObject();
		if( dwNumUnits )
		{
			if( _g_new_memory.m_pResMap[j].m_ResList.Start() )
			{
				for( uint32 i=0; i<dwNumUnits; i++ )
				{
					// Get a memory unit
					pHashItem = _g_new_memory.m_pResMap[j].m_ResList.GetObjectData();
					pMemUnit = (StructMemUnit*)pHashItem->m_UserData;
					// Get the size of the memory
					dwSize += pMemUnit->nSize;
					// Output the buffer
					sprintf( buf, "(%ld) - FILE: %s, LINE: %ld, SIZE: %ld Bytes\n", dwCount, pMemUnit->szFileName, pMemUnit->nFileLine, pMemUnit->nSize );
					dwCount++;
					fprintf( fp, buf );
				} // for(i)
				
				_g_new_memory.m_pResMap[j].m_ResList.End();
			}
		}
	} // for(j)

    const unsigned int nOneKB = 1024;
	const unsigned int nOneMB = 1024*1024;

	fprintf( fp, "\n" );
	if( dwSize < nOneKB )
	{
		sprintf( buf, "The Amount of Memory Unfreed : %ld Byte\n", dwSize );
	}
	else if( dwSize >= nOneKB && dwSize < nOneMB )
	{
		sprintf( buf, "The Amount of Memory Unfreed : %ld Byte/(%.2f KB)\n", dwSize, (float)dwSize/1024.0f );
	}
	else // dwSize >= 1024*102 MB
	{
		sprintf( buf, "The Amount of Memory Unfreed : %ld Byte/(%.2f MB)\n", dwSize, (float)dwSize/(1024.0f*1024.0f) );
	}
	fprintf( fp, buf );
	if( _g_new_memory.m_memory_used_max < nOneKB )
	{
		sprintf( buf, "The Maximum Amount of Memory Used : %ld Byte\n", _g_new_memory.m_memory_used_max );
	}
	else if( _g_new_memory.m_memory_used_max >= nOneKB && _g_new_memory.m_memory_used_max < nOneMB )
	{
		sprintf( buf, "The Maximum Amount of Memory Used : %ld Byte/(%.2f KB)\n", _g_new_memory.m_memory_used_max, (float)_g_new_memory.m_memory_used_max/1024.0f );
	}
	else // _g_new_memory.m_memory_used_max >= 1024*1024 MB
	{
		sprintf( buf, "The Maximum Amount of Memory Used : %ld Byte/(%.2f MB)\n", _g_new_memory.m_memory_used_max, (float)_g_new_memory.m_memory_used_max/(1024.0f*1024.0f) );
	}
	fprintf( fp, buf );
	fprintf( fp, "\n" );

	//---------------------------------------//

	fclose( fp );
	fp = NULL;

	return true;
}
#endif // _MSC_VER >= 1400

//===========================================================
//
// Desc: construction
//
//===========================================================

void GTNew::Clear( void )
{
	m_memory_used_cur = 0L;
	m_memory_used_max = 0L;
}

GTNew::GTNew()
{
	Clear();

	//CHashTableMem<StructMemUnit*, 10000>::Cr
}

//===========================================================
//
// Desc: destruction
//
//===========================================================
GTNew::~GTNew()
{
#ifdef GT_DEBUG
#ifdef GT_WINDOWS

	char szBuf[256];

	::OutputDebugStringA( "\n" );
	::OutputDebugStringA( "---------------------------- NewMem (Start) ----------------------------\n" );
	::OutputDebugStringA( "Checking memory leaks...\n" );
	::OutputDebugStringA( "\n" );
	
	// check the memory list and release the memory units unfreed
	int dwNumUnits = GetNumItems();
	sprintf( szBuf, "The Number of Memory-Units Unfreed : %ld\n", dwNumUnits );

	::OutputDebugStringA( szBuf );
	::OutputDebugStringA( "\n" );

	int dwSize = 0;
	HashObjectItem<StructMemUnit*>* pHashItem = NULL;
	StructMemUnit *pMemUnit = NULL;
	int dwCount = 0;
	if( dwNumUnits )
	{
		for( unsigned int j=0; j<m_dwSizeOfMap; j++ )
		{
			dwNumUnits = m_pResMap[j].m_ResList.GetNumObject();
			if( dwNumUnits )
			{
				if( m_pResMap[j].m_ResList.Start() )
				{
					for( int i=0; i<dwNumUnits; i++ )
					{
						// Get a memory unit
						pHashItem = _g_new_memory.m_pResMap[j].m_ResList.GetObjectData();
						pMemUnit = (StructMemUnit*)pHashItem->m_UserData;
						
						// Decrease the amount of memroy
						m_memory_used_cur -= pMemUnit->nSize;
						
						dwSize += pMemUnit->nSize;
						
						// Release this memory leak unit
						free( pMemUnit->pPtr );

						sprintf( szBuf, "(%ld) - FILE: %s, LINE: %ld, SIZE: %ld Bytes\n", dwCount, pMemUnit->szFileName, pMemUnit->nFileLine, pMemUnit->nSize );
						
						dwCount++;

						// Output the memory leak information.
						OutputDebugStringA( szBuf );
						
						// Free this memory unit
						free( pMemUnit );
						pMemUnit = NULL;
					} // for(i)
					
					m_pResMap[j].m_ResList.End();
				}

				// Release the list
				m_pResMap[j].m_ResList.Release();
			}
		} // for(i)
	} // if( dwNumUnits )

	// Release the hash table
	ReleaseMap();

	if( dwSize < 1024 )
	{
		sprintf( szBuf, "The Amount of Memory Unfreed : %ld Byte(s)\n", dwSize );
	}
	else if( dwSize >= 1024 )
	{
		sprintf( szBuf, "The Amount of Memory Unfreed : %ld Byte(s)(%.2f KB)\n", dwSize, (FLOAT)dwSize/1024.0f );
	}
	else // dwSize >= 1024*102 MB
	{
		sprintf( szBuf, "The Amount of Memory Unfreed : %ld Byte(s)(%.2f MB)\n", dwSize, (FLOAT)dwSize/(1024.0f*1024.0f) );
	}

	::OutputDebugStringA( szBuf );
	if( m_memory_used_max < 1024 )
	{
		sprintf( szBuf, "The Maximum Amount of Memory Used : %ld Byte(s)\n", m_memory_used_max );
	}
	else if( m_memory_used_max >= 1024 )
	{
		sprintf( szBuf, "The Maximum Amount of Memory Used : %ld Byte(s)(%.2f KB)\n", m_memory_used_max, (FLOAT)m_memory_used_max/1024.0f );
	}
	else // m_memory_used_max >= 1024*102 MB
	{
		sprintf( szBuf, "The Maximum Amount of Memory Used : %ld Byte(s)(%.2f MB)\n", m_memory_used_max, (FLOAT)m_memory_used_max/(1024.0f*1024.0f) );
	}

	OutputDebugStringA( szBuf );

	OutputDebugStringA( "---------------------------- NewMem (End) ----------------------------\n" );
	OutputDebugStringA( "\n" );

#endif /* GT_WINDOWS */
#endif /* GT_DEBUG */
}
