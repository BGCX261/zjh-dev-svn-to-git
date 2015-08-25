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
#define GTCLSAUTOINST_DEF(className,superClassName) \
	static const tchar* m_szClassName; \
	static const tchar* m_szSuperClassName; \
	virtual const tchar* GetClassName(void) const; \
	virtual const tchar* GetSuperClassName(void) const; \
	static superClassName* CreateClassInstance(void); \
	static const tchar* GetClassNameStatic(void); \
	static const tchar* GetSuperClassNameStatic(void);

// Implement the variable and methods to store the class name
#define GTCLSAUTOINST_IMP(className,superClassName,pfnCallback) \
	static GTClassAutoInstanceContainer<superClassName> _g_GTClassAutoInstanceContainer_##className = GTClassAutoInstanceContainer<superClassName>(className::m_szClassName,className::CreateClassInstance,pfnCallback); \
	const tchar* className::m_szClassName=CTEXT(#className); \
	const tchar* className::m_szSuperClassName=CTEXT(#superClassName); \
	const tchar* className::GetClassName(void) const {return className::m_szClassName;} \
	const tchar* className::GetSuperClassName(void) const {return className::m_szSuperClassName;} \
	superClassName* className::CreateClassInstance(void) {className* p=new className();return p;} \
	const tchar* className::GetClassNameStatic(void) {return className::m_szClassName;} \
	const tchar* className::GetSuperClassNameStatic(void) {return className::m_szSuperClassName;}

#endif /* _GT_CLASS_AUTO_INSTANCE_H_ */
