// MonoScripting.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <cstdio>
#include <string>
#include <vector>
#include <Windows.h>
#include "MonoScriptCore/MonoBehaviourClass.h"
#include "MonoScriptCore/MonoScriptEngine.h"
#include "UnManagedMethod.h"
#include "GTTest.h"

extern GTGameObjectMgr goManager;

/*
std::string GetAssemlyFullPath(const char* szName)
{
	char path[MAX_PATH];
	::GetCurrentDirectory(MAX_PATH, path);
	return
}
*/

/*
void TestAssemblyEXE(void)
{
	MonoDomain* domain = NULL;
	MonoAssembly* assembly = NULL;
	MonoImage* image = NULL;
	
	const char* szAssembly = "Program.exe";
	char *args[1] = {"Test Param"};

	mono_set_dirs(NULL, NULL);
	//mono_config_parse(NULL);

	domain = mono_jit_init("dev");
	if(domain)
	{
		assembly = ::mono_domain_assembly_open(domain, szAssembly);
		if(assembly)
		{
			int retval = mono_jit_exec(domain, assembly, 1, args);
		}
		
		// Clearn up domain object
		mono_jit_cleanup(domain);
		domain = NULL;
	}
}
*/

MonoScriptEngine monoScriptEngine;

void TestAssemblyDLL(const char* szAssemblyName, const char* szClassName)
{	
	monoScriptEngine.Initialize();
	if(monoScriptEngine.LoadAssembly(szAssemblyName))
	{
		// Format:
		// Syntax: Namespace.ClassName::Method
		//
		// If pass TestPrint::MathIntAdd, it works.
		// If pass MonoScriptManaged::TestPrint::MathIntAdd, it doesn't work.
		/*
		monoScriptEngine.RegisterInternalCall("GTEngineManaged.TestPrint::MathIntAdd", (const void*)MathIntAdd);
		monoScriptEngine.RegisterInternalCall("GTEngineManaged.TestPrint::MathIntSub", (const void*)MathIntSub);
		monoScriptEngine.RegisterInternalCall("GTEngineManaged.TestPrint::MathIntMul", (const void*)MathIntMul);
		monoScriptEngine.RegisterInternalCall("GTEngineManaged.TestPrint::MathIntDiv", (const void*)MathIntDiv);
		*/
		// GTGameObject
		monoScriptEngine.RegisterInternalCall("GTEngineManaged.GTInternalCall::GT_CreateGameObject", (const void*)GT_CreateGameObject);
		monoScriptEngine.RegisterInternalCall("GTEngineManaged.GTInternalCall::GT_DestroyGameObject", (const void*)GT_DestroyGameObject);
		monoScriptEngine.RegisterInternalCall("GTEngineManaged.GTInternalCall::GT_GetGameObjectName", (const void*)GT_GetGameObjectName);
		monoScriptEngine.RegisterInternalCall("GTEngineManaged.GTInternalCall::GT_SetGameObjectPosition", (const void*)GT_SetGameObjectPosition);
		monoScriptEngine.RegisterInternalCall("GTEngineManaged.GTInternalCall::GT_GetGameObjectPosition", (const void*)GT_GetGameObjectPosition);
		monoScriptEngine.RegisterInternalCall("GTEngineManaged.GTInternalCall::GT_AddBehaviourGameObject", (const void*)GT_AddBehaviourGameObject);
		monoScriptEngine.RegisterInternalCall("GTEngineManaged.GTInternalCall::GT_FindGameObjectByName", (const void*)GT_FindGameObjectByName);
		monoScriptEngine.RegisterInternalCall("GTEngineManaged.GTInternalCall::GT_GetGTVector2C", (const void*)GT_GetGTVector2C);

		monoScriptEngine.RegisterInternalCall("TC_TestPrint::GetVector2C", (const void*)GT_GetVector2C);
		
		std::string runException;
		MonoBehaviourClass* pBehaviourClass = monoScriptEngine.CreateBehaviourClassInstance("", szClassName);
		if(pBehaviourClass)
		{
			if(!pBehaviourClass->InvokeOnPreStart(runException))
				printf("EXCEPTION:\n%s\n", runException.c_str());
			if(!pBehaviourClass->InvokeOnStart(runException))
				printf("EXCEPTION:\n%s\n", runException.c_str());
			if(!pBehaviourClass->InvokeOnUpdate(runException))
				printf("EXCEPTION:\n%s\n", runException.c_str());
			if(!pBehaviourClass->InvokeOnDestroy(runException))
				printf("EXCEPTION:\n%s\n", runException.c_str());

			pBehaviourClass->Release();
			pBehaviourClass = NULL;
		}
	}

	int loopCount = 0;
	while(true)
	{
		goManager.OnUpdate();
		Sleep(1000);

		loopCount++;
		if(loopCount > 5)
			break;
	}

	goManager.Release();
	monoScriptEngine.Destroy();
}


int _tmain(int argc, _TCHAR* argv[])
{
	//TestAssemblyEXE();
	if(argc != 3)
	{
		printf("Usage: MonoScripting.exe 'Assembly Name' 'Class Name'\n");
		printf("Usage: MonoScripting.exe 'HelloAssembly.dll' 'HelloClass'\n");
		return 0;
	}

	printf("Assembly Name = %s\n", argv[1]);
	printf("Class Name = %s\n", argv[2]);
	printf("\n");

	FILE* fp = fopen(argv[1], "rb");
	if(NULL == fp)
	{
		// The assembly doesn't exist
		printf("The assembly (%s) doesn't exist\n", argv[1]);
		printf("\n");
		printf("Press enter key to exit...\n");
		getchar();
		return 0;
	}
	else
	{
		fclose(fp);
		fp = NULL;
	}

	TestAssemblyDLL(argv[1], argv[2]);

	printf("\n");
	printf("Press enter key to exit...\n");
	getchar();

	return 0;
}
