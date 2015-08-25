#ifndef _UI_LABEL_SMOOTH_CHANGE_H_
#define _UI_LABEL_SMOOTH_CHANGE_H_

#include "UILabel.h"

class UILabelSmoothChange : public UILabel
{
public:
	UIWIDGET_DEF(UILabelSmoothChange, UIWidget)

public:
	UILabelSmoothChange();
	UILabelSmoothChange(UIWidget* pParent);
	virtual ~UILabelSmoothChange();

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

	// Refresh value
	void RefreshValue(void);

public:
	GT_PROPERTY_DEF_VAR_SET_GET_INT32(TargetValue);
	GT_PROPERTY_DEF_VAR_SET_GET_INT32(WorkingValue);
	GT_PROPERTY_DEF_VAR_SET_GET_INT32(StepValue);
	GT_PROPERTY_DEF_VAR_SET_GET_INT32(MinValue);
	GT_PROPERTY_DEF_VAR_SET_GET_INT32(MaxValue);
	GT_PROPERTY_DEF_VAR_SET_GET_FLOAT(TimerInterval);

protected:
	float m_fPrevTimer;
};

#endif /* _UI_LABEL_SMOOTH_CHANGE_H_ */
