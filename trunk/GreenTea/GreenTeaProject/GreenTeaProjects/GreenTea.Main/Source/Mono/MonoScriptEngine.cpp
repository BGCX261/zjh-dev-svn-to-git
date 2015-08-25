#include "MonoScriptEngine.h"
#include "MonoBehaviourClass.h"

GTSINGLETON_IMP(MonoScriptEngine);

MonoScriptEngine::MonoScriptEngine()
{
	m_pDomain = NULL;
	m_pAssembly = NULL;
	m_pImage = NULL;
}


MonoScriptEngine::~MonoScriptEngine()
{
	Destroy();
}


bool MonoScriptEngine::Initialize(void)
{
	mono_set_dirs(NULL, NULL);
	//mono_config_parse(NULL);

	return true;
}


bool MonoScriptEngine::LoadAssembly(const char* szAssemblyName)
{
	if(NULL == szAssemblyName)
		return false;

	m_pDomain = mono_jit_init("default_domain");
	if(m_pDomain)
	{
		// Load assembly
		m_pAssembly = ::mono_domain_assembly_open(m_pDomain, szAssemblyName);
		if(m_pAssembly)
		{
			// Get assembly image
			m_pImage = mono_assembly_get_image(m_pAssembly);
			if(m_pImage)
			{
				m_strAssemblyName = GTString(szAssemblyName);
				return true;
			}
		}
	}

	return false;
}


bool MonoScriptEngine::Destroy(void)
{
	if(m_pDomain)
	{
		mono_jit_cleanup(m_pDomain);
		m_pDomain = NULL;
		m_pAssembly = NULL;
		m_pImage = NULL;
	}

	return true;
}


MonoBehaviourClass* MonoScriptEngine::CreateBehaviourClassInstance(
	const char* szNameSpace,
	const char* szClassName
	)
{
	MonoBehaviourClass* pNewClass = new MonoBehaviourClass();
	if(NULL == pNewClass)
		return NULL;

	// Get the class with specified namespace
	pNewClass->m_ClassObject.pClass = mono_class_from_name(m_pImage, szNameSpace, szClassName);
	if(pNewClass->m_ClassObject.pClass)
	{
		// Create a class instance
		pNewClass->m_ClassObject.pClassInstance = mono_object_new(m_pDomain, pNewClass->m_ClassObject.pClass);
		if(pNewClass->m_ClassObject.pClassInstance)
		{
			// Calls the constructor
			mono_runtime_object_init(pNewClass->m_ClassObject.pClassInstance);

			// OnPreStart
			pNewClass->m_MonoMethodObject[MonoBehaviourClass::METHOD_OnPreStart].pMethod = mono_class_get_method_from_name(
				pNewClass->m_ClassObject.pClass, MonoBehaviourClass::METHOD_OnPreStart_Name, 0);
			pNewClass->m_MonoMethodObject[MonoBehaviourClass::METHOD_OnPreStart].strMethodName = MonoBehaviourClass::METHOD_OnPreStart_Name;
			// OnStart
			pNewClass->m_MonoMethodObject[MonoBehaviourClass::METHOD_OnStart].pMethod = mono_class_get_method_from_name(
				pNewClass->m_ClassObject.pClass, MonoBehaviourClass::METHOD_OnStart_Name, 0);
			pNewClass->m_MonoMethodObject[MonoBehaviourClass::METHOD_OnStart].strMethodName = MonoBehaviourClass::METHOD_OnStart_Name;
			// OnUpdate
			pNewClass->m_MonoMethodObject[MonoBehaviourClass::METHOD_OnUpdate].pMethod = mono_class_get_method_from_name(
				pNewClass->m_ClassObject.pClass, MonoBehaviourClass::METHOD_OnUpdate_Name, 0);
			pNewClass->m_MonoMethodObject[MonoBehaviourClass::METHOD_OnUpdate].strMethodName = MonoBehaviourClass::METHOD_OnUpdate_Name;
			// OnDestroy
			pNewClass->m_MonoMethodObject[MonoBehaviourClass::METHOD_OnDestroy].pMethod = mono_class_get_method_from_name(
				pNewClass->m_ClassObject.pClass, MonoBehaviourClass::METHOD_OnDestroy_Name, 0);
			pNewClass->m_MonoMethodObject[MonoBehaviourClass::METHOD_OnDestroy].strMethodName = MonoBehaviourClass::METHOD_OnDestroy_Name;
		}
	}

	return pNewClass;			
}


// Register an internal call
// szName - Must be full name like this format class::method_name in C# code
// pMethod - Method name
bool MonoScriptEngine::RegisterInternalCall(const char* szName, const void* pMethod)
{
	if(NULL == szName || NULL == pMethod)
		return false;

	mono_add_internal_call(szName, pMethod);

	return true;
}
