#ifndef _UIBS_GAME_SETTING_H_
#define _UIBS_GAME_SETTING_H_

#include <GTBehaviour.h>
#include "../UI/UIWidgetScript.h"
#include "../UI/UIProgressBar.h"

class UIBSGameSetting : public UIWidgetScript
{
public:
	GTBEHAVIOUR_DEF(UIBSGameSetting, UIWidgetScript);

public:
	UIBSGameSetting();
	virtual ~UIBSGameSetting();

	// This method is called when GTBehaviour object is created.
	virtual int32 OnCreate(void);
	// This method is called when GTBehaviour object is initialized.
	virtual int32 OnInitialize(GTBehaviourInitParam* param);
	virtual int32 OnStart(void);
	// This method is called when GTBehaviour object is updated.
	virtual int32 OnUpdate(void);
	// This method is called when GTBehaviour object is destroyed.
	virtual int32 OnDestroy(void);

	virtual bool OnSingleClick(const uint32 nFlags, const GTPoint2& pos);
	virtual bool OnDoubleClick(const uint32 nFlags, const GTPoint2& pos);
	virtual bool OnMove(const uint32 nFlags, const GTPoint2& pos, const GTPoint2& delta, bool dragging);
	virtual bool OnStateChange(const uint32 nState);

	UIProgressBar* m_pUIProgressBar;
};

#endif /* _UIBS_GAME_SETTING_H_ */
