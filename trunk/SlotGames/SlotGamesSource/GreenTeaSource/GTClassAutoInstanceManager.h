#ifndef _GT_CLASS_AUTO_INSTANCE_MANAGER_H_
#define _GT_CLASS_AUTO_INSTANCE_MANAGER_H_

#include "GTClassAutoInstance.h"
#include "GTString.h"
#include "GTDictionary.h"

// Sample:
//
// class YourClassManager : public GTClassAutoInstanceManager<YourClassWidget>
// {
// public:
// 	YourClassManager();
// 	~YourClassManager();
// 
// public:
// 	static void CreateClassInstanceDefineCallback(GTClassAutoInstanceContainer<YourClassWidget>* pWidgetClass);
// };
//
// void YourClassManager::CreateClassInstanceDefineCallback(GTClassAutoInstanceContainer<YourClassWidget>* pWidgetClass)
// {
// 	if(NULL == pWidgetClass)
// 	{
// 		return;
// 	}
// 
// 	YourClassManager::GetInstance()->AddClass(pWidgetClass);
// }

template<class baseClassName>
class GTClassAutoInstanceManager
{
public:
	GTClassAutoInstanceManager()
	{
	}

	virtual ~GTClassAutoInstanceManager()
	{
		Release();
	}

	// Add a class into the dictionary
	bool AddClass(GTClassAutoInstanceContainer<baseClassName>* pClassContainer);
	// Create a class instance from a class name specified
	baseClassName* CreateClassInstance(const tchar* szClassName);
	// Get how many classes that are stored in the manager
	int32 GetClassCount(void) const;
	// Release
	void Release(void);

public:
	// Get singleton instance
	static GTClassAutoInstanceManager* GetInstance()
	{
		if(m_pInstance)
		{
			return m_pInstance;			
		}

		m_pInstance = new GTClassAutoInstanceManager();

		return m_pInstance;
	}

private:
	GTDictionary<GTString, GTClassAutoInstanceContainer<baseClassName>*> m_DictionaryClass;

protected:
	// Singleton instance
	static GTClassAutoInstanceManager* m_pInstance;
};


template<class baseClassName>
GTClassAutoInstanceManager<baseClassName>* GTClassAutoInstanceManager<baseClassName>::m_pInstance = NULL;


// Add a class into the dictionary
template<class baseClassName>
bool GTClassAutoInstanceManager<baseClassName>::AddClass(GTClassAutoInstanceContainer<baseClassName>* pClassContainer)
{
	if(NULL == pClassContainer)
	{
		return false;
	}

	return m_DictionaryClass.Add(pClassContainer->m_szClassName, pClassContainer);
}


// Create a class instance from a class name specified
template<class baseClassName>
baseClassName* GTClassAutoInstanceManager<baseClassName>::CreateClassInstance(const tchar* szClassName)
{
	if(NULL == szClassName)
	{
		return NULL;
	}

	GTClassAutoInstanceContainer<baseClassName>* pClassContainer = NULL;
	if(!m_DictionaryClass.GetValueByKey(szClassName, pClassContainer))
	{
		return NULL;
	}

	if(pClassContainer)
	{
		if(pClassContainer->m_pfnCreateClass)
		{
			return pClassContainer->m_pfnCreateClass();
		}
	}

	return NULL;
}


// Get how many classes that are stored in the manager
template<class baseClassName>
int32 GTClassAutoInstanceManager<baseClassName>::GetClassCount(void) const
{
	return m_DictionaryClass.Count();
}


// Release
template<class baseClassName>
void GTClassAutoInstanceManager<baseClassName>::Release(void)
{
	m_DictionaryClass.Clear();
}

#endif /* _GT_CLASS_AUTO_INSTANCE_MANAGER_H_ */
