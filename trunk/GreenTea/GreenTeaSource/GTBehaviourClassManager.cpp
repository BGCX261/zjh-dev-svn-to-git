#include "GTBehaviourClassManager.h"

GTBehaviourClassManager* GTBehaviourClassManager::m_pInstance = NULL;

GTBehaviourClassManager::GTBehaviourClassManager()
{
}


GTBehaviourClassManager::~GTBehaviourClassManager()
{
	Release();
}


// Add a class into the dictionary
bool GTBehaviourClassManager::AddClass(GTBehaviourClassContainer* pClassContainer)
{
	if(NULL == pClassContainer)
	{
		return false;
	}

	return m_DictionaryClass.Add(pClassContainer->m_szClassName, pClassContainer);
}


// Get how many classes that are stored in the manager
int32 GTBehaviourClassManager::GetClassCount(void) const
{
	return m_DictionaryClass.Count();
}


// Release
void GTBehaviourClassManager::Release(void)
{
	m_DictionaryClass.Clear();
}


// Create a class instance from a class name specified
GTBehaviour* GTBehaviourClassManager::CreateClassInstance(const tchar* szClassName)
{
	if(NULL == szClassName)
	{
		return NULL;
	}

	GTBehaviourClassContainer* pClassContainer = NULL;
	if(!m_DictionaryClass.GetValueByKey(szClassName, pClassContainer))
	{
		return NULL;
	}

	if(pClassContainer)
	{
		if(pClassContainer->m_pfnCreateBehaviourClass)
		{
			return pClassContainer->m_pfnCreateBehaviourClass();
		}
	}

	return NULL;
}
