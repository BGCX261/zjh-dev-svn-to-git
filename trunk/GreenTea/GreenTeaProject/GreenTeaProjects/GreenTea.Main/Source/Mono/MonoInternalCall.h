#ifndef _INTERNAL_CALL_H_
#define _INTERNAL_CALL_H_

// Debug
__declspec(dllexport) void InternalCall_DebugLogTrace(int nLevel, MonoString* msMessage);
__declspec(dllexport) void InternalCall_DebugLogWarning(int nLevel, MonoString* msMessage);
__declspec(dllexport) void InternalCall_DebugLogError(int nLevel, MonoString* msMessage);

// Register all internal calls
void InternalCall_RegisterInternalCalls(void);

#endif /* _INTERNAL_CALL_DEBUG_H_ */
