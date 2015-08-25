#ifndef _UI_LABEL_VALUE_TWEENER_H_
#define _UI_LABEL_VALUE_TWEENER_H_

#include "UILabel.h"
#include "UIWidgetEvent.h"
#include <GTTweener2D.h>

class UILabelValueTweener : public UILabel
{
public:
	UIWIDGET_DEF(UILabelValueTweener, UIWidget)

public:
	UILabelValueTweener();
	UILabelValueTweener(UIWidget* pParent);
	virtual ~UILabelValueTweener();

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

	// Start
	//
	// from: start position
	// to: end position
	// duration: how long for (from, to), in ms
	// tweenFunction: tweener type, see TweenInterpolation
	// delay: delay to start, in ms
	// onCompleted: call-back when completes
	// pParam: customized parameters for onCompleted
	void Start(
		const int32 from,
		const int32 to,
		const float duration,
		GTTweenFunction tweenFunction,
		const float delay,
		GTStatic_EventCallback onCompleted,
		void* pParam
		);
	// Start
	//
	// from: start position
	// to: end position
	// duration: how long for (from, to), in ms
	// tweenFunction: tweener type, see TweenInterpolation
	// delay: delay to start, in ms
	void Start(
		const int32 from,
		const int32 to,
		const float duration,
		GTTweenFunction tweenFunction,
		const float delay
		);
	// Update
	void TweenUpdate(void);
	// Stop
	void Stop(void);
	// Set/Get value	
	void SetValue(const int32 nNewValue, const int32 nDurationInMs);
	void SetValue(const int32 nNewValue);
	int32 GetValue(void) const
	{
		return GetPropertyValue();
	}
	// Event listener
	UIWidgetEvent2* GetEventTweener(void)
	{
		return &m_EventTweenerFinished;
	}

public:
	// GTTweenerInteger object
	GTTweenerInteger m_Tweener;
	// Properties
	GT_PROPERTY_DEF_VAR_SET_GET_INT32(Value);
	GT_PROPERTY_DEF_VAR_SET_GET_INT32(Duration);	
	GT_PROPERTY_DEF_VAR_SET_GET_FLOAT(Delay);
	GT_PROPERTY_DEF_VAR_SET_GET_FLOAT(StartTime);
	GT_PROPERTY_DEF_VAR_SET_GET_BOOL(Running);
	// Event
	UIWidgetEvent2 m_EventTweenerFinished;

protected:
	// Previous time
	long m_lPrevTime;
};

#endif /* _UI_LABEL_VALUE_TWEENER_H_ */
