#ifndef _UI_BUTTON_H_
#define _UI_BUTTON_H_

#include "UIWidget.h"

class UIButton : public UIWidget
{
public:
	UIWIDGET_DEF(UIButton, UIWidget)

public:
	UIButton();
	UIButton(UIWidget* pParent);
	virtual ~UIButton();

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

	// Events
	virtual bool OnSingleClick(const uint32 nFlags, const GTPoint2& pos);
	virtual bool OnDoubleClick(const uint32 nFlags, const GTPoint2& pos);
	virtual bool OnStateChange(const uint32 nState);

protected:
	bool m_bPressed;
};

#endif /* _UI_BUTTON_H_ */
