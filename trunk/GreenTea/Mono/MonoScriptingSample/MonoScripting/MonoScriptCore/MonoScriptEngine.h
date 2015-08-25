#ifndef _MONO_SCRIPT_ENGINE_H_
#define _MONO_SCRIPT_ENGINE_H_

#include "MonoScriptCore.h"

class MonoBehaviourClass;

class MonoScriptEngine
{
public:
	MonoScriptEngine();
	virtual ~MonoScriptEngine();

	bool Initialize(void);
	bool LoadAssembly(const char* szAssemblyName);
	bool Destroy(void);
	MonoBehaviourClass* CreateBehaviourClassInstance(const char* szNameSpace, const char* szClassName);
	MonoClass* GetMonoClassByName(const char* szNameSpace, const char* szClassName);
	MonoClass* GetMonoClassByNameFromEngine(const char* szNameSpace, const char* szClassName);
	// Register an internal call
	bool MonoScriptEngine::RegisterInternalCall(const char* szName, const void* pMethod);

protected:
	MonoDomain* m_pDomain;
	MonoAssembly* m_pAssembly;
	MonoAssembly* m_pAssemblyEngine;
	MonoImage* m_pImage;
	MonoImage* m_pImageEngine;
};

#endif /* _MONO_SCRIPT_ENGINE_H_ */
