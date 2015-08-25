#ifndef _MONO_SCRIPT_CORE_H_
#define _MONO_SCRIPT_CORE_H_

#include <string>
#include <Windows.h>
// Mono includes
#include <mono/jit/jit.h>
#include <mono/metadata/assembly.h>

struct MonoMethodObject
{
	MonoMethod* pMethod;
	std::string strMethodName;
};

struct MonoClassObject
{
	MonoClass* pClass;
	MonoObject* pClassInstance;
	std::string strNameSpace;
	std::string strClassName;
};

#endif /* _MONO_SCRIPT_CORE_H_ */
