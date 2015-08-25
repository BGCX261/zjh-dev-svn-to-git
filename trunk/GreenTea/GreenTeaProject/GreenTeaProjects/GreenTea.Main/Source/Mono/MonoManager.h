#ifndef _MONO_MANAGER_H_
#define _MONO_MANAGER_H_

#include <GTGreenTea.h>
#include "../Mono/MonoScriptEngine.h"

class MonoManager : public GTSingleton<MonoManager>
{
public:
	MonoManager();
	~MonoManager();

	// Initialize the audio
	bool Initialize(void);
	// Register internal calls
	bool RegisterInternalCall(void);
	// Destroy
	void Destroy(void);

	// Load an assembly with specified name
	bool LoadAssembly(const char* szAssemblyName)
	{
		return m_MonoScriptEngine.LoadAssembly(szAssemblyName);
	}
	// Create an instance of MonoBehaviourClass with specified name space & class name
	MonoBehaviourClass* CreateBehaviourClassInstance(const char* szNameSpace, const char* szClassName)
	{
		return m_MonoScriptEngine.CreateBehaviourClassInstance(szNameSpace, szClassName);
	}
	MonoBehaviourClass* CreateBehaviourClassInstance(const char* szClassName)
	{
		return m_MonoScriptEngine.CreateBehaviourClassInstance("", szClassName);
	}
	// Is an assembly load already ?
	bool IsAssemblyLoaded(void)
	{
		return m_MonoScriptEngine.IsAssemblyLoaded();
	}
	// Get assembly name
	GTString GetAssemblyName(void)
	{
		return m_MonoScriptEngine.GetAssemblyName();
	}
	// Get Mono script engine instance
	MonoScriptEngine* GetMonoScriptEngine(void)
	{
		return &m_MonoScriptEngine;
	}

protected:
	MonoScriptEngine m_MonoScriptEngine;
};

#endif /* _MONO_MANAGER_H_ */
