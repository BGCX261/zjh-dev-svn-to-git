#ifndef _TAG_MANAGER_H_
#define _TAG_MANAGER_H_

#include <GTBaseDef.h>
#include <GTSingleton.h>

class TagManager : public GTSingleton<TagManager>
{
public:
	TagManager();
	virtual ~TagManager();

	// The tag for main map
	int32 GetTagMainMap() const
	{
		return 10;
	}
};

#endif /* _TAG_MANAGER_H_ */
