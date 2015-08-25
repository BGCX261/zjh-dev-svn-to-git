#include <GTLog/GTLogManager.h>
#include "MonoManager.h"

// Debug
__declspec(dllexport) void InternalCall_DebugLogTrace(int nLevel, MonoString* msMessage)
{
	if(NULL == msMessage)
		return;
	GTLogManager::GetInstance()->LogTrace(mono_string_to_utf8(msMessage));
}

__declspec(dllexport) void InternalCall_DebugLogWarning(int nLevel, MonoString* msMessage)
{
	if(NULL == msMessage)
		return;
	GTLogManager::GetInstance()->LogWarning(mono_string_to_utf8(msMessage));
}

__declspec(dllexport) void InternalCall_DebugLogError(int nLevel, MonoString* msMessage)
{
	if(NULL == msMessage)
		return;
	GTLogManager::GetInstance()->LogError(mono_string_to_utf8(msMessage));
}

// Register all internal calls
void InternalCall_RegisterInternalCalls(void)
{
	MonoScriptEngine* mse = MonoManager::GetInstance()->GetMonoScriptEngine();
	if(mse)
	{
		// Debug
		mse->RegisterInternalCall("GreenTeaEngine.GTDebug::InternalCall_DebugLogTrace", (const void*)InternalCall_DebugLogTrace);
		mse->RegisterInternalCall("GreenTeaEngine.GTDebug::InternalCall_DebugLogWarning", (const void*)InternalCall_DebugLogWarning);
		mse->RegisterInternalCall("GreenTeaEngine.GTDebug::InternalCall_DebugLogError", (const void*)InternalCall_DebugLogError);
	}
}
