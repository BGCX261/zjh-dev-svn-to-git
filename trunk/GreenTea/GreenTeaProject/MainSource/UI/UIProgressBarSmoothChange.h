#ifndef _UI_PROGRESS_BAR_SMOOTH_CHANGE_H_
#define _UI_PROGRESS_BAR_SMOOTH_CHANGE_H_

#include "UIWidget.h"
#include "UIProgressBar.h"

class UIProgressBarSmoothChange : public UIProgressBar
{
public:
	UIWIDGET_DEF(UIProgressBarSmoothChange, UIWidget)

public:
	UIProgressBarSmoothChange();
	UIProgressBarSmoothChange(UIWidget* pParent);
	virtual ~UIProgressBarSmoothChange();

public:
	// Override this method to serialize specific properties
	virtual bool OnSerializeTo(GTTreeNode* pTreeNode);
	// Override this method to serialize specific properties
	virtual bool OnSerializeFrom(GTTreeNode* pTreeNode);

	// When the object is initialized, this method is called.
	virtual int32 OnInitialize(void);

	// When the system is updated, this method is called for each frame.
	virtual int32 OnUpdate(void);

	// This method is called for rendering each frame.
	virtual int32 OnRender(void);

	// Before the system is shut down, this method is called.
	virtual int32 OnDestroy(void);

	// Override GTObject::Release to do more things
	virtual void Release(void);

	// Set the current value of the progress bar
	virtual void SetCurrentValue(const int32 nValue);
	virtual void RefreshValue(void);

public:
	GT_PROPERTY_DEF_VAR_SET_GET_INT16(TargetValue);
	GT_PROPERTY_DEF_VAR_INT16(WorkingValue);
	GT_PROPERTY_DEF_VAR_SET_GET_INT32(StepValue);
	GT_PROPERTY_DEF_VAR_SET_GET_INT32(MinValue);
	GT_PROPERTY_DEF_VAR_SET_GET_INT32(MaxValue);
	GT_PROPERTY_DEF_VAR_SET_GET_FLOAT(TimerInterval);

protected:
	float m_fPrevTimer;
};

#endif /* _UI_PROGRESS_BAR_SMOOTH_CHANGE_H_ */
