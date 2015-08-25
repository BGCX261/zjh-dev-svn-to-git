#include "GTObject.h"

GTObject::GTObject()
{
	// When the object is created, the refrence count of it is 1
	m_nReferenceCount = 1;
}


GTObject::~GTObject()
{
}


// Release this object
void GTObject::Release(void)
{
	DBG_ASSERT(m_nReferenceCount > 0);
	m_nReferenceCount--;

	if(m_nReferenceCount == 0)
	{
		// No object is referencing this object, release it.
		delete this;
	}
}


// Reference this object by increasing the reference count
void GTObject::AddReference(void)
{
	DBG_ASSERT(m_nReferenceCount > 0);

	m_nReferenceCount++;
}


// Get reference count
int32 GTObject::GetReferenceCount(void)
{
	return m_nReferenceCount;
}


// Check if pObject is same as this
bool GTObject::IsEqual(const GTObject* pObject)
{
	return (this == pObject);
}


// ToString: serialize the object to a string
GTString GTObject::ToString(void)
{
	return GTString::EmptyString;
}


// Clone: create an exact and seperate object
GTObject* GTObject::Clone(void)
{
	return NULL;
}


// Copy from an object
bool GTObject::Copy(GTObject* pObjectFrom)
{
	return true;
}
