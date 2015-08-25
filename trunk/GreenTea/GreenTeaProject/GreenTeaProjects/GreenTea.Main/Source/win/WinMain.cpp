#include "WinMain.h"
#include "../Main/AppDelegate.h"
#include "CCEGLView.h"
#include <string>
#include "../Mono/MonoScriptEngine.h"
#include "../Mono/MonoBehaviourClass.h"
#include "../Mono/MonoInternalCall.h"
#include "../Mono/MonoManager.h"
// GreenTea
#include <GTLog/GTLogManager.h>

void LoadAssemblyDLL(const char* szAssemblyName, const char* szClassName)
{
	MonoScriptEngine* mse = MonoManager::GetInstance()->GetMonoScriptEngine();
	mse->Initialize();
	if(mse->LoadAssembly(szAssemblyName))
	{
		// Register internal calls
		InternalCall_RegisterInternalCalls();

		// Call methods
		std::string runException;
		MonoBehaviourClass* pBehaviourClass = mse->CreateBehaviourClassInstance("", szClassName);
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
	mse->Destroy();
}

void Initialize(LPTSTR lpCmdLine, int nCmdShow)
{
	if(nCmdShow != 1)
	{
		//printf("Usage: MonoScripting.exe 'Assembly Name' 'Class Name'\n");
		//printf("Usage: MonoScripting.exe 'HelloAssembly.dll' 'HelloClass'\n");
		//return 0;
		return;
	}

	/*
	printf("Assembly Name = %s\n", argv[1]);
	printf("Class Name = %s\n", argv[2]);
	printf("\n");
	*/

	const char* szAssembly = (const char*)lpCmdLine;
	FILE* fp = fopen(szAssembly, "rb");
	if(NULL == fp)
	{
		/*
		// The assembly doesn't exist
		printf("The assembly (%s) doesn't exist\n", argv[1]);
		printf("\n");
		printf("Press enter key to exit...\n");
		getchar();
		return 0;
		*/
		return;
	}
	else
	{
		fclose(fp);
		fp = NULL;
	}

	LoadAssemblyDLL(szAssembly, "StartPointClass");

	/*
	printf("\n");
	printf("Press enter key to exit...\n");
	getchar();
	*/
}

int APIENTRY _tWinMain(HINSTANCE hInstance,
					   HINSTANCE hPrevInstance,
					   LPTSTR    lpCmdLine,
					   int       nCmdShow)
{
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);

	// Initialize log object
	GTLogManager::GetInstance()->Initialize();
	GTLogManager::GetInstance()->LogTrace("Initialized log object");

	// Initialize mono script engine

    // create the application instance
	AppDelegate app;
	cocos2d::CCEGLView* eglView = cocos2d::CCEGLView::sharedOpenGLView();
    eglView->setFrameSize(480, 320);
	// If screen resolution is big use this factor to debug the app on desktop
	// The resolution of ipad3 is very large. In general, PC's resolution is smaller than it.
    // So we need to invoke 'setFrameZoomFactor'(only valid on desktop(win32, mac, linux)) to make the window smaller.
	eglView->setFrameZoomFactor(1.0);

	// Run
    int codeReturn = cocos2d::CCApplication::sharedApplication()->run();
	
	Initialize(lpCmdLine, nCmdShow);

	// Destroy log object
	GTLogManager::GetInstance()->Destroy();

	return codeReturn;
}
