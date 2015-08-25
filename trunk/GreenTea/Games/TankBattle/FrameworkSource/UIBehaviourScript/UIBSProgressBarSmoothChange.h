#ifndef _UIBS_PROGRESS_BAR_SMOOTH_CHANGE_H_
#define _UIBS_PROGRESS_BAR_SMOOTH_CHANGE_H_

#include <GTBehaviour.h>
#include "../UI/UIWidgetScript.h"
#include "../UI/UIProgressBar.h"

class UIBSProgressBarSmoothChange : public UIWidgetScript
{
public:
	GTBEHAVIOUR_DEF(UIBSProgressBarSmoothChange, UIWidgetScript);

public:
	UIBSProgressBarSmoothChange();
	virtual ~UIBSProgressBarSmoothChange();

	// This method is called when GTBehaviour object is created.
	virtual int32 OnCreate(void);
	// This method is called when GTBehaviour object is initialized.
	virtual int32 OnInitialize(GTBehaviourInit* param);
	// This method is called before first OnUpdate
	virtual int32 OnStart(void);
	// This method is called when GTBehaviour object is updated.
	virtual int32 OnUpdate(void);
	// This method is called when GTBehaviour object is destroyed.
	virtual int32 OnDestroy(void);

	// Refresh value
	void RefreshValue(void);

public:
	GT_PROPERTY_DEF_VAR_SET_GET_INT16(TargetValue);
	GT_PROPERTY_DEF_VAR_SET_GET_INT16(WorkingValue);
	GT_PROPERTY_DEF_VAR_SET_GET_INT16(MaxValue);

protected:
	UIProgressBar* m_pUIProgressBar;
	float m_fPrevTimer;
	float m_fTimerInterval;
};

#endif /* _UIBS_PROGRESS_BAR_SMOOTH_CHANGE_H_ */
