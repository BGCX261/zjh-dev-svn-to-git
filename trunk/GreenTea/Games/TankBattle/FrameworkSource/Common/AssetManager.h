#ifndef _ASSET_MANAGER_H_
#define _ASSET_MANAGER_H_

#include <GTGreenTea.h>

class GTGameObject;

struct AssetItem
{
	// Unique URL, property path
	std::string sUrl;
	// Game object instance
	GTGameObject *pGameObject;
};

class AssetManager : public GTSingleton<AssetManager>
{
public:
	AssetManager();
	~AssetManager();

	// When the object is initialized, this method is called.
	virtual int32 OnInitialize(void);

	// When the system is updated, this method is called for each frame.
	virtual int32 OnUpdate(void);

	// This method is called for rendering each frame.
	virtual int32 OnRender(void);

	// Before the system is shut down, this method is called.
	virtual int32 OnDestroy(void);

	// Create a game object from specified .property path
	GTGameObject* CreateGameObject(const tchar *szPropPath, const tchar *szName, GTGameObject *pParent);
	template<typename T> T* CreateGameObject(const tchar *szPropPath, const tchar *szName, GTGameObject *pParent)
	{
		return dynamic_cast<T*>(CreateGameObject(szPropPath, szName, pParent));
	}

protected:
	// Cached asset list
	GTDictionary<std::string, AssetItem> m_AssetCachedList;
};

#endif /* _ASSET_MANAGER_H_ */
