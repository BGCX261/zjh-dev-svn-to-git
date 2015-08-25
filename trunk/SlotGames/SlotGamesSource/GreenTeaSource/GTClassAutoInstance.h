#ifndef _GT_CLASS_AUTO_INSTANCE_H_
#define _GT_CLASS_AUTO_INSTANCE_H_

#include "GTBaseDef.h"

// This class contains basic information about a class
// that derives from base class
template <class baseClassType>
class GTClassAutoInstanceContainer
{
public:
	// The type of pointer of the function of creating a new derived-class object
	typedef baseClassType* (*CreateClassInstanceDefine)(void);
	typedef void (*CreateClassInstanceDefineCallback)(GTClassAutoInstanceContainer* pfnCallback);

public:
	GTClassAutoInstanceContainer(
		const tchar* szClassName,
		CreateClassInstanceDefine pfn,
		CreateClassInstanceDefineCallback pfnCallback
		)
	{
		m_szClassName = szClassName;
		m_pfnCreateClass = pfn;

		if(pfnCallback)
		{
			pfnCallback(this);
		}
	}
	virtual ~GTClassAutoInstanceContainer()
	{
		m_szClassName = NULL;
		m_pfnCreateClass = NULL;
	}

	// The class name that derives from baseClassType
	const tchar* m_szClassName;
	// The pointer of the function of creating a new derived-class object
	CreateClassInstanceDefine m_pfnCreateClass;
};

// Add the variables and methods into the derived class to store the class name
#define GTCLSAUTOINST_DEF(className,baseClassName) \
	static const tchar* m_szClassName; \
	virtual const tchar* GetClassName(void) const; \
	static baseClassName* CreateClassInstance(void);

// Implement the variable and methods to store the class name
#define GTCLSAUTOINST_IMP(className,baseClassName,pfnCallback) \
	static GTClassAutoInstanceContainer<baseClassName> _g_GTClassAutoInstanceContainer_##className = GTClassAutoInstanceContainer<baseClassName>(className::m_szClassName,className::CreateClassInstance,pfnCallback); \
	const tchar* className::m_szClassName=CTEXT(#className); \
	const tchar* className::GetClassName(void) const {return className::m_szClassName;} \
	baseClassName* className::CreateClassInstance(void) {className* p=new className();return p;}

#endif /* _GT_CLASS_AUTO_INSTANCE_H_ */
