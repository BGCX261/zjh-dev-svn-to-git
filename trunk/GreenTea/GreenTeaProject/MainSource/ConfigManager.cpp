#include "ConfigManager.h"
#include "PropertyFile.h"
#include <GTLog/GTLogManager.h>

GTSINGLETON_IMP(ConfigManager);

ConfigManager::ConfigManager():
	m_pGameObjectConfig(NULL),
	m_pGlobalConfig(NULL)
{
}


ConfigManager::~ConfigManager()
{
}


// When the object is initialized, this method is called.
int32 ConfigManager::OnInitialize(void)
{
	return Load() ? 1 : 0;
}


// Before the system is shut down, this method is called.
int32 ConfigManager::OnDestroy(void)
{
	return Release() ? 1 : 0;
}


GTTreeNode *ConfigManager::Load(const tchar *szName)
{
	if(NULL == szName)
	{
		return NULL;
	}

	GTTreeNode *pNode = PropertyFile::Load(szName);
	if(NULL == pNode)
	{
		GTLogManager::GetInstance()->LogFormatError(CTEXT("Failed to load '%s'"), szName);
		return NULL;
	}

	return pNode;
}


// Load all config files
bool ConfigManager::Load(void)
{
	// Load config\GameObjectConfig.property
	m_pGameObjectConfig = Load(CTEXT("config/GameObjectConfig.property"));
	// Load
	m_pGlobalConfig = Load(CTEXT("config/GlobalConfig.property"));

	return true;
}


// Reload all config fiels
bool ConfigManager::Reload(void)
{
	Release();
	Load();

	return true;
}


// Release
bool ConfigManager::Release(void)
{
	GTTREENODE_RELEASE(m_pGameObjectConfig);
	GTTREENODE_RELEASE(m_pGlobalConfig);

	return true;
}


// Query a property from m_pGlobalConfig
GTTreeNode *ConfigManager::QueryPropertyFromGlobalConfig(const tchar* szName)
{
	if(NULL == szName)
	{
		return NULL;
	}

	return m_pGlobalConfig->FindChild(szName);
}
