#ifndef _CONFIG_MANAGER_H_
#define _CONFIG_MANAGER_H_

#include <GTGreenTea.h>

class ConfigManager : public GTSingleton<ConfigManager>
{
public:
	ConfigManager();
	~ConfigManager();

	// When the object is initialized, this method is called.
	int32 OnInitialize(void);

	// Before the system is shut down, this method is called.
	int32 OnDestroy(void);

	// Load all config files
	GTTreeNode *Load(const tchar *szName);
	bool Load(void);
	// Reload all config fiels
	bool Reload(void);
	// Release
	bool Release(void);

	// Get tree node for game object config
	GTTreeNode* GetGameObjectConfig()
	{
		return m_pGameObjectConfig;
	}
	// Get tree node for global config
	GTTreeNode* GetGlobalConfig()
	{
		return m_pGlobalConfig;
	}

	// Query a property from m_pGlobalConfig
	GTTreeNode *QueryPropertyFromGlobalConfig(const tchar* szName);

private:
	// Game object config
	GTTreeNode *m_pGameObjectConfig;
	// Global config
	GTTreeNode *m_pGlobalConfig;
};

#endif /* _CONFIG_MANAGER_H_ */
