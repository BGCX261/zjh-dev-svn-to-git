#ifndef _MONO_SCRIPT_ENGINE_H_
#define _MONO_SCRIPT_ENGINE_H_

#include <GTGreenTea.h>
#include <GTSingleton.h>
#include "MonoScriptCore.h"

class MonoBehaviourClass;

class MonoScriptEngine : public GTSingleton<MonoScriptEngine>
{
public:
	MonoScriptEngine();
	virtual ~MonoScriptEngine();

	// Initialize
	bool Initialize(void);
	// Load an assembly with specified name
	bool LoadAssembly(const char* szAssemblyName);
	// Create an instance of MonoBehaviourClass with specified name space & class name
	MonoBehaviourClass* CreateBehaviourClassInstance(const char* szNameSpace, const char* szClassName);
	// Register an internal call
	// szName - Must be full name like this format class::method_name in C# code
	// pMethod - Method name
	bool RegisterInternalCall(const char* szName, const void* pMethod);	
	// Destroy
	bool Destroy(void);

	// Is an assembly load already ?
	bool IsAssemblyLoaded(void)
	{
		return m_pAssembly ? true : false;
	}
	// Get assembly name
	GTString GetAssemblyName(void)
	{
		m_strAssemblyName;
	}	

protected:
	MonoDomain* m_pDomain;
	MonoAssembly* m_pAssembly;
	MonoImage* m_pImage;
	GTString m_strAssemblyName;
};

#endif /* _MONO_SCRIPT_ENGINE_H_ */
