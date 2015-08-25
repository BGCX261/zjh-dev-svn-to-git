#ifndef _GREENTEA_DYNAMIC_BUFFER_H_
#define _GREENTEA_DYNAMIC_BUFFER_H_

#include <GTBaseDef.h>
#include <GTString.h>

template<class T>
class GTDynamicBuffer
{
public:
	GTDynamicBuffer() :
	  m_pBuffer(NULL),
	  m_nSize(0),
	  m_nMaxSize(0)
	{
	}

	GTDynamicBuffer(const int32 nSize) :
	  m_pBuffer(NULL),
	  m_nSize(0),
	  m_nMaxSize(0)
	{
		if(nSize)
		{
			m_pBuffer = new T[nSize];
			DBG_ASSERT(m_pBuffer);
			m_nSize = nSize;
			m_nMaxSize = m_nSize;
		}
	}
		
	GTDynamicBuffer(const GTDynamicBuffer& src) :
	  m_pBuffer(NULL),
	  m_nSize(0),
	  m_nMaxSize(0)
	{
		if(src.GetSize())
		{
			Release();
			if(Resize(src.GetSize()))
			{
				memcpy(m_pBuffer, src.m_pBuffer, src.GetSize()*sizeof(T));
			}
		}
	}

	~GTDynamicBuffer()
	{
		Release();
	}

	GTString ToString(void)
	{
		return GTString::EmptyString;
	}

	// If new is size is lager than old, resize the buffer
	int32 Resize(const int32 nNewSize)
	{
		if(nNewSize > m_nSize)
		{
			// Resize the buffer
			if(m_pBuffer)
			{
				delete [] m_pBuffer;
				m_pBuffer = NULL;
			}
			// New size
			m_pBuffer = new T[nNewSize];
			DBG_ASSERT(m_pBuffer);
			m_nSize = nNewSize;
			m_nMaxSize = m_nSize;
		}
		return m_nSize;
	}

	void Release(void)
	{
		if(m_pBuffer)
		{
			delete [] m_pBuffer;
			m_pBuffer = NULL;
		}
		m_nSize = 0;
		m_nMaxSize = 0;
	}

	int32 GetSize(void) const
	{
		return m_nSize;
	}

	int32 GetMaxSize(void) const
	{
		return m_nMaxSize;
	}

	/*
	// =
	const GTDynamicBuffer operator = (const GTDynamicBuffer& src)
	{
		return (*this);
	}
	*/

public:
	T* m_pBuffer;
	int32 m_nSize;
	int32 m_nMaxSize;
};

#endif /* _GREENTEA_DYNAMIC_BUFFER_H_ */
