#ifndef _LOCALIZATION_MANAGER_H_
#define _LOCALIZATION_MANAGER_H_

#include <GTBaseDef.h>
#include <GTGameObject.h>
#include <GTSingleton.h>
#include <GTString.h>

//class LocalizationManager : public GTGameObject, public GTSingleton<LocalizationManager>
class LocalizationManager : public GTSingleton<LocalizationManager>
{
public:
	LocalizationManager();
	LocalizationManager(const LocalizationManager& lm);
	virtual ~LocalizationManager();

	// When the object is initialized, this method is called.
	virtual int32 OnInitialize(void);

	// When the system is updated, this method is called for each frame.
	virtual int32 OnUpdate(void);

	// This method is called for rendering each frame.
	virtual int32 OnRender(void);

	// Before the system is shut down, this method is called.
	virtual int32 OnDestroy(void);

	// Get a localized string with its string id.
	GTString GetLocalizedString(const tchar* szStringId);
};

#endif /* _LOCALIZATION_MANAGER_H_ */
