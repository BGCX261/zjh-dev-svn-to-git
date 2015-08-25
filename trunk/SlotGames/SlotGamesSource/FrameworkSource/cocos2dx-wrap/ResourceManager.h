#ifndef _RESOURCE_MANAGER_H_
#define _RESOURCE_MANAGER_H_

#include <GTGreenTea.h>

class GSpriteAnimationCocos2dx;

class ResourceManager : public GTSingleton<ResourceManager>
{
public:
	ResourceManager();
	~ResourceManager();

	// Add an animation resource by specified name & sprite object
	bool AddAnimation(const GTString& name, GSpriteAnimationCocos2dx* pAnimationNew);
	// Find an animation resource by specified name
	GSpriteAnimationCocos2dx* FindAnimation(const GTString& name);
	// Remove animation resource
	bool RemoveAnimation(const GTString& name);

	void OnDestroy(void);

public:
	GTDictionary<std::string, GSpriteAnimationCocos2dx*> m_ResAnimationList;
};

#endif /* _RESOURCE_MANAGER_H_ */
