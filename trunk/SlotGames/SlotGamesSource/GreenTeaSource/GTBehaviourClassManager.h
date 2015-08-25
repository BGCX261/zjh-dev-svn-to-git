#ifndef _GREENTEA_BEHAVIOUR_CLASS_MANAGER_H_
#define _GREENTEA_BEHAVIOUR_CLASS_MANAGER_H_

#include "GTBaseDef.h"
#include "GTBehaviour.h"
#include "GTString.h"
#include "GTDictionary.h"

// This class manages all classes that derive from GTBehaviour.
// By going through this class, you can know how many classes that
// derive from GTBehaviour.
class GTBehaviourClassManager
{
public:
	GTBehaviourClassManager();
	virtual ~GTBehaviourClassManager();

	// Add a class into the dictionary
	bool AddClass(GTBehaviourClassContainer* pClassContainer);
	// Create a class instance from a class name specified
	GTBehaviour* CreateClassInstance(const tchar* szClassName);
	// Get how many classes that are stored in the manager
	int32 GetClassCount(void) const;
	// Release
	void Release(void);

	// Get singleton instance
	static GTBehaviourClassManager* GetInstance()
	{
		if(m_pInstance)
		{
			return m_pInstance;			
		}

		m_pInstance = new GTBehaviourClassManager();

		return m_pInstance;
	}

private:
	GTDictionary<GTString, GTBehaviourClassContainer*> m_DictionaryClass;

protected:
	// Singleton instance
	static GTBehaviourClassManager* m_pInstance;
};

#endif /* _GREENTEA_BEHAVIOUR_CLASS_MANAGER_H_ */
