#include "ResourceManager.h"
#include "../Common/GameObjectCreation.h"
#include "GSpriteAnimationCocos2dx.h"
#include <GTLog/GTLogManager.h>

#ifdef GT_DEBUG
#include <GTNew.h>
#endif // GT_DEBUG

GTSINGLETON_IMP(ResourceManager);

ResourceManager::ResourceManager()
{
}

ResourceManager::~ResourceManager()
{
	m_ResAnimationList.Clear();
}


// Add an animation resource by specified name & sprite object
bool ResourceManager::AddAnimation(const GTString& name, GSpriteAnimationCocos2dx* pAnimationNew)
{
	if(name.Length() == 0 || NULL == pAnimationNew)
		return false;

	/*
	ResourceManagerAnimationHolder holder;
	holder.name = name;
	holder.name.ToLower(); // To lower case
	holder.pAnimation = pAnimationNew;
	*/
	GTString keyName = name;
	keyName.ToLower();
	// Add
	m_ResAnimationList.Add(keyName.ToCharString(), pAnimationNew);

	return true;
}


// Find an animation resource by specified name
GSpriteAnimationCocos2dx* ResourceManager::FindAnimation(const GTString& name)
{
	/*
	GTString strName = name;
	strName.ToLower(); // To lower case
	GTLIST_FOREACH(ResourceManagerAnimationHolder, it, m_ResAnimationList)
	{
		if(GTString::IsEqual((*it).name.ToCharString(), name.ToCharString()))
		{
			// Find it
			return (*it).pAnimation;
		}
	}
	return NULL;
	*/

	GTString keyName = name;
	keyName.ToLower(); // To lower case
	GSpriteAnimationCocos2dx* pAnimation = NULL;
	m_ResAnimationList.GetValueByKey(keyName.ToCharString(), pAnimation);
	return pAnimation;
}


// Remove animation resource
bool ResourceManager::RemoveAnimation(const GTString& name)
{
	GTString keyName = name;
	keyName.ToLower();
	GSpriteAnimationCocos2dx* pAnimation = FindAnimation(keyName);
	if(pAnimation)
	{
		m_ResAnimationList.Remove(keyName.ToCharString());
		return true;
	}
	return false;
}


void ResourceManager::OnDestroy(void)
{
	GTLogManager::SLogTrace(CTEXT("ResourceManager----------------"));
	GTLogManager::SLogFormatTrace(CTEXT("Resource Unfreed Count = %d"), m_ResAnimationList.Count());

	GSpriteAnimationCocos2dx* pAnim = NULL;
	for(GTDictionary<std::string, GSpriteAnimationCocos2dx*>::ObjectTypeIterator it = m_ResAnimationList.Begin();
		it != m_ResAnimationList.End();
		it++)
	{
		pAnim = GTDictionaryGetValue((*it));
		GTLogManager::SLogFormatTrace(CTEXT("Key name = %s"), pAnim->m_strKey.ToCharString());
	}

	GTLogManager::SLogTrace(CTEXT("ResourceManager----------------"));
}
