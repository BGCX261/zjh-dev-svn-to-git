#include "WeaponCacheManager.h"
#include "SceneManager.h"
#include <GTLog/GTLogManager.h>
#include <GTPropertyFile.h>
#include <GTGameObjectManager.h>
#include <GameObjectSprite.h>
#include <AssetManager.h>

#ifdef GT_DEBUG
#include <GTNew.h>
#endif // GT_DEBUG

GTSINGLETON_IMP(WeaponCacheManager);

WeaponCacheManager::WeaponCacheManager()
{
	m_pWeaponItemList = NULL;
}


WeaponCacheManager::~WeaponCacheManager()
{
}


// When the object is initialized, this method is called.
int32 WeaponCacheManager::OnInitialize(void)
{
	// Load weapon list from property file
	GTTreeNode *pTreeNode = GTPropertyFile::Load(CTEXT("game/weapon-list.property"));
	if(pTreeNode)
	{
		const int32 nChildCount = pTreeNode->GetChildCount();
		if(nChildCount)
		{
			m_pWeaponItemList = new WeaponItemProperty[nChildCount];
			if(m_pWeaponItemList)
			{
				for(int32 i=0; i<nChildCount; i++)
				{
					GTTreeNode *pChildNode = pTreeNode->GetChild(i);
					if(pChildNode)
					{
						// Weapon item id
						m_pWeaponItemList[i].nItemId = pChildNode->GetTag().ToInt();
						// Weapon item property url
						m_pWeaponItemList[i].sUrl = pChildNode->GetValue();

						// Add this weapon item to the dictionary
						m_DicItemList.Add(m_pWeaponItemList[i].nItemId, &m_pWeaponItemList[i]);
					}
				}
			}
		}
	}
	else
	{
		GTLogManager::SLogError(CTEXT("WeaponCacheManager::OnInitialize: Failed to load (game/weapon-list.property) !"));
	}

	// Release
	if(pTreeNode)
	{
		pTreeNode->Release();
		pTreeNode = NULL;
	}

	// Clean m_WeaponFiredList
	WeaponItemSlot wis;
	wis.nItemId = -1;
	wis.pGameObject = NULL;
	wis.lTimeElapsed = 0;
	for(int32 i=0; i<WeaponCacheManager::m_nWeaponFiredListCount; i++)
	{
		wis.nSlotId = i;
		m_WeaponFiredList.Add(wis);
	}

	return 1;
}


// When the system is updated, this method is called for each frame.
int32 WeaponCacheManager::OnUpdate(void)
{	
	return 1;
}


// This method is called for rendering each frame.
int32 WeaponCacheManager::OnRender(void)
{
	return 1;
}


// Before the system is shut down, this method is called.
int32 WeaponCacheManager::OnDestroy(void)
{
	if(m_pWeaponItemList)
	{
		delete [] m_pWeaponItemList;
		m_pWeaponItemList = NULL;
	}

	return 1;
}


// Find an available slot
WeaponItemSlot* WeaponCacheManager::FindAvailableSlot(const int32 nItemId)
{
	WeaponItemSlot *pItemSlotFree = NULL;
	WeaponItemSlot *pItemSlotDisabled = NULL;

	// Go through each slot
	const int32 nLength = m_WeaponFiredList.Length();
	for(int32 i=0; i<nLength; i++)
	{
		WeaponItemSlot *wis = &m_WeaponFiredList[i];
		// Make sure this slot has a game object
		if(wis->nItemId >= 0 && wis->pGameObject)
		{
			// Check if this game object is cached/expired or still live
			if(wis->nItemId == nItemId)
			{
				 if(false == wis->pGameObject->GetEnable())
				 {
					 // The game object is cached/expired. Re-active this game object.
					 wis->pGameObject->SetEnable(true);					 
					 pItemSlotDisabled = wis;
				 }
				 else
				 {
					 // The game object is still live & running
				 }
			}
		}
		else
		{
			// Save first available item slot for future use
			if(NULL == pItemSlotFree)
				pItemSlotFree = wis;
		}

		// If find both, no further going through required
		if(pItemSlotFree && pItemSlotDisabled)
		{
			break;
		}
	}

	// Re-use this disabled game object
	if(pItemSlotDisabled)
	{
		return pItemSlotDisabled;
	}

	// Use this available slot
	// Load the game object from property
	if(pItemSlotFree)
	{
		// Get the property url
		WeaponItemProperty *pWIP = NULL;
		if(m_DicItemList.GetValueByKey(nItemId, pWIP))
		{
			GameObjectSprite *pNewWeaponItem = AssetManager::Inst()->CreateGameObject<GameObjectSprite>(
				pWIP->sUrl,
				GTString::Format(CTEXT("go-weapon-%d"), nItemId),
				NULL);
			if(NULL == pNewWeaponItem)
			{
				GTLogManager::Inst()->LogFormatError(CTEXT("WeaponCacheManager::FindAvailableSlot: Failed to load (%s)(item id = %d)"), pWIP->sUrl, nItemId);
				return NULL;
			}
			// Save this item
			pItemSlotFree->nItemId = nItemId;
			pItemSlotFree->pGameObject = pNewWeaponItem;
			pItemSlotFree->lTimeElapsed = 0;
			return pItemSlotFree;
		}
		else
		{
			GTLogManager::Inst()->LogFormatError(CTEXT("WeaponCacheManager::FindAvailableSlot: weapon item (id = %d) doesn't exist."), nItemId);
			return NULL;
		}
	}

	// All slots are used up so no more slots
	return NULL;
}


// Create a weapon game object from item id defined in staticWeaponItemList
// If the weapon game object specified by nItemId is not loaded yet, load it from file. Then clone and return it.
// If the weapon game object is already loaded, clone and return it.
GameObjectSprite* WeaponCacheManager::CreateWeaponGameObject(const int32 nItemId)
{
	// Check if the item id is available in existing list
	WeaponItemProperty *pWIP = NULL;
	if(false == m_DicItemList.GetValueByKey(nItemId, pWIP))
		return NULL; // Key not found

	WeaponItemSlot *pWIS = FindAvailableSlot(nItemId);
	if(NULL == pWIS)
	{
		GTLogManager::Inst()->LogFormatError(CTEXT("WeaponCacheManager::CreateWeaponGameObject: Failed to find available slot (item id = %d)"), nItemId);
		return NULL;
	}
	
	return pWIS->pGameObject;
}
