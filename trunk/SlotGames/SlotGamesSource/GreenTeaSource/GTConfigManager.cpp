#include "GTConfigManager.h"
#include <GTPropertyFile.h>
#include <GTLog/GTLogManager.h>

GTSINGLETON_IMP(GTConfigManager);

GTConfigManager::GTConfigManager():
	m_pGameObjectConfig(NULL),
	m_pGlobalConfig(NULL)
{
}


GTConfigManager::~GTConfigManager()
{
}


// When the object is initialized, this method is called.
int32 GTConfigManager::OnInitialize(void)
{
	return Load() ? 1 : 0;
}


// Before the system is shut down, this method is called.
int32 GTConfigManager::OnDestroy(void)
{
	return Release() ? 1 : 0;
}


GTTreeNode *GTConfigManager::Load(const tchar *szName)
{
	if(NULL == szName)
	{
		return NULL;
	}

	GTTreeNode *pNode = GTPropertyFile::Load(szName);
	if(NULL == pNode)
	{
		GTLogManager::GetInstance()->LogFormatError(CTEXT("Failed to load '%s'"), szName);
		return NULL;
	}

	return pNode;
}


// Load all config files
bool GTConfigManager::Load(void)
{
	// Load config\GameObjectConfig.property
	m_pGameObjectConfig = Load(CTEXT("config/GameObjectConfig.property"));
	// Load
	m_pGlobalConfig = Load(CTEXT("config/GlobalConfig.property"));

	return true;
}


// Reload all config fiels
bool GTConfigManager::Reload(void)
{
	Release();
	Load();

	return true;
}


// Release
bool GTConfigManager::Release(void)
{
	GTTREENODE_RELEASE(m_pGameObjectConfig);
	GTTREENODE_RELEASE(m_pGlobalConfig);

	return true;
}


// Query a property from m_pGlobalConfig
GTTreeNode *GTConfigManager::QueryPropertyFromGlobalConfig(const tchar* szName)
{
	if(NULL == szName)
	{
		return NULL;
	}

	return m_pGlobalConfig->FindChild(szName);
}
