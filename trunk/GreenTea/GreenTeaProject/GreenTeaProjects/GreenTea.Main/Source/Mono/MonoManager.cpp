#include "MonoManager.h"
#include "../Mono/MonoInternalCall.h"

GTSINGLETON_IMP(MonoManager);

MonoManager::MonoManager()
{
}


MonoManager::~MonoManager()
{
}


// Initialize
bool MonoManager::Initialize(void)
{
	return m_MonoScriptEngine.Initialize();
}


// Destroy
void MonoManager::Destroy(void)
{
	m_MonoScriptEngine.Destroy();
}


// Register internal calls
bool MonoManager::RegisterInternalCall(void)
{
	InternalCall_RegisterInternalCalls();

	return true;
}
