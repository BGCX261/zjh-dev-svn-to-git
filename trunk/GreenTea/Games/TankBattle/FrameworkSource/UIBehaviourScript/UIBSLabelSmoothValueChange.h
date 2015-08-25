#ifndef _UIBS_LABEL_SMOOTH_VALUE_CHANGE_H_
#define _UIBS_LABEL_SMOOTH_VALUE_CHANGE_H_

#include <GTGreenTea.h>
#include <GTBehaviour.h>
#include "../UI/UIWidgetScript.h"
#include "../UI/UILabel.h"

class UIBSLabelSmoothValueChange : public UIWidgetScript
{
public:
	GTBEHAVIOUR_DEF(UIBSLabelSmoothValueChange, UIWidgetScript);

public:
	UIBSLabelSmoothValueChange();
	virtual ~UIBSLabelSmoothValueChange();

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

protected:
	UILabel* m_pUILabelWidget;
	float m_fPrevTimer;
	float m_fTimerInterval;
};

#endif /* _UIBS_LABEL_SMOOTH_VALUE_CHANGE_H_ */
