#include "AssetManager.h"
#include "GameGeneral.h"
#include <GTLog/GTLogManager.h>
#include <GTGameObjectManager.h>

GTSINGLETON_IMP(AssetManager);

AssetManager::AssetManager()
{
}


AssetManager::~AssetManager()
{
}


// When the object is initialized, this method is called.
int32 AssetManager::OnInitialize(void)
{
	return 1;
}


// When the system is updated, this method is called for each frame.
int32 AssetManager::OnUpdate(void)
{
	return 1;
}


// This method is called for rendering each frame.
int32 AssetManager::OnRender(void)
{
	return 1;
}


// Before the system is shut down, this method is called.
int32 AssetManager::OnDestroy(void)
{
	// Release all cached game objects
	for(GTDictionary<std::string, AssetItem>::ObjectTypeIterator it = m_AssetCachedList.Begin();
		it != m_AssetCachedList.End();
		it++)
	{
		if(it->second.pGameObject)
		{
			it->second.pGameObject->Release();
			it->second.pGameObject = NULL;
			it->second.sUrl = CTEXT("");
		}
	}
	// Clear the dictionary
	m_AssetCachedList.Clear();

	return 1;
}


// Create a game object from specified .property path
GTGameObject* AssetManager::CreateGameObject(const tchar *szPropPath, const tchar *szName, GTGameObject *pParent)
{
	if(NULL == szPropPath)
		return NULL;

	GTGameObject *pGameObjectNew = NULL;
	// Check if the game object is cached
	AssetItem assetItem;
	if(m_AssetCachedList.GetValueByKey(std::string(szPropPath), assetItem))
	{
		// The game object is already cached so clone a new game object
		pGameObjectNew = assetItem.pGameObject->Clone(szName, pParent);
	}
	else
	{
		// Not cached yet. Load the game object first and cache it.
		GTGameObject* pGameObjectCached = GTGameObjectManager::Inst()->CreateGameObject(pParent, szName, szPropPath);
		if(NULL == pGameObjectCached)
		{
			GTLogManager::SLogFormatError(CTEXT("AssetManager::CreateGameObject: Failed to create game object (%s) !"), szPropPath);
			return NULL;
		}
		// Because this game object is cached, detache this game object from its parent.
		// Otherwise it will be released automatically by game object manager when the game exits.
		if(pGameObjectCached->GetParent())
		{
			pGameObjectCached->GetParent()->RemoveChild(pGameObjectCached);
			pGameObjectCached->SetParent(NULL);
		}
		// Setup name
		pGameObjectCached->SetName(GTString::Format(CTEXT("%s-cached"), szName));
		// Set a position that is not in visible screen
		pGameObjectCached->SetPosition(-10000.0f, -10000.0f);
		// Disable this cached game object
		pGameObjectCached->SetEnable(false);
		pGameObjectCached->SetVisible(false, true);
		pGameObjectCached->SetZOrder(GameGeneral::Inst()->GetZOrderCacheObject());
		// Add it to cache list
		AssetItem ai;
		ai.sUrl = szPropPath;
		ai.pGameObject = pGameObjectCached;
		m_AssetCachedList.Add(ai.sUrl, ai);
		// Clone
		pGameObjectNew = pGameObjectCached->Clone(szName, pParent);
	}
	
	return pGameObjectNew;
}
