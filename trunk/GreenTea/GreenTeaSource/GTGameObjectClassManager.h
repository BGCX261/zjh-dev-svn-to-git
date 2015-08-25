#ifndef _GREENTEA_GAMEOBJECT_CLASS_MANAGER_H_
#define _GREENTEA_GAMEOBJECT_CLASS_MANAGER_H_

#include <GTClassAutoInstanceManager.h>
#include <GTGameObject.h>

// Add the variables and methods into the derived class to store the class name
#define GTGAMEOBJECT_DEF(className,baseClassName) GTCLSAUTOINST_DEF(className,baseClassName)
// Implement the variable and methods to store the class name
#define GTGAMEOBJECT_IMP(className,baseClassName,pfnCallback) GTCLSAUTOINST_IMP(className,baseClassName,pfnCallback)

class GTGameObjectClassManager : public GTClassAutoInstanceManager<GTGameObject>
{
public:
	GTGameObjectClassManager();
	~GTGameObjectClassManager();

public:
	static void CreateClassInstanceDefineCallback(GTClassAutoInstanceContainer<GTGameObject>* pInstClass);
};

#endif /* _GREENTEA_GAMEOBJECT_CLASS_MANAGER_H_ */
