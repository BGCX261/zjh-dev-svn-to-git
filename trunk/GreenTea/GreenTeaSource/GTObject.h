#ifndef _GREENTEA_OBJECT_H_
#define _GREENTEA_OBJECT_H_

#include "GTBaseDef.h"
#include <GTString.h>

class GTObject
{
public:
	GTObject(void);
	virtual ~GTObject(void);

	// Release this object
	virtual void Release(void);
	// Reference this object by increasing the reference count
	void AddReference(void);
	// Get reference count
	int32 GetReferenceCount(void);
	// Check if pObject is same as this
	virtual bool IsEqual(const GTObject* pObject);
	// ToString: serialize the object to a string
	virtual GTString ToString(void);
	// Clone: create an exactly new object
	virtual GTObject* Clone(void);
	// Copy from an object
	virtual bool Copy(GTObject* pObjectFrom);

protected:
	// Reference count
	int m_nReferenceCount;
};

#endif /* _GREENTEA_OBJECT_H_ */
