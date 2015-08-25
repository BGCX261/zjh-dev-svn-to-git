#ifndef _WEAPON_CACHE_MANAGER_H_
#define _WEAPON_CACHE_MANAGER_H_

#include <GTGreenTea.h>
#include <GTSingleton.h>
#include "GameObjectCreation.h"

class GameObjectSprite;

struct WeaponItemProperty
{
	// Unique id for this weapon item
	int32 nItemId;
	// Unique URL, property path
	GTString sUrl;
};

struct WeaponItemSlot
{
	int32 nSlotId;
	// Unique id for this weapon item
	int32 nItemId;
	// Game object for this item
	GameObjectSprite *pGameObject;
	long lTimeElapsed;
};

class WeaponCacheManager : GTObject, public GTSingleton<WeaponCacheManager>
{
public:
	WeaponCacheManager();
	~WeaponCacheManager();

	// When the object is initialized, this method is called.
	virtual int32 OnInitialize(void);

	// When the system is updated, this method is called for each frame.
	virtual int32 OnUpdate(void);

	// This method is called for rendering each frame.
	virtual int32 OnRender(void);

	// Before the system is shut down, this method is called.
	virtual int32 OnDestroy(void);

	// Create a weapon game object from item id defined in staticWeaponItemList
	// If the weapon game object specified by nItemId is not loaded yet, load it from file. Then clone and return it.
	// If the weapon game object is already loaded, clone and return it.
	GameObjectSprite* CreateWeaponGameObject(const int32 nItemId);
	// Find an available slot
	WeaponItemSlot* FindAvailableSlot(const int32 nItemId);

protected:
	// Save weapon item properties loaded from game/weapon-list.property
	WeaponItemProperty *m_pWeaponItemList;
	GTDictionary<int32, WeaponItemProperty*> m_DicItemList;
	// The list for weapons already fired
	GTArray<WeaponItemSlot> m_WeaponFiredList;

public:
	static const int32 m_nWeaponFiredListCount = 3;
};

#endif /* _WEAPON_CACHE_MANAGER_H_ */
