#ifndef _UI_BUTTON_INFOBAR_H_
#define _UI_BUTTON_INFOBAR_H_

#include <UI/UIWidget.h>
#include <UI/UIButton.h>

class UIButtonInfobar : public UIButton
{
public:
	UIWIDGET_DEF(UIButtonInfobar, UIWidget)

public:
	UIButtonInfobar();
	UIButtonInfobar(UIWidget* pParent);
	virtual ~UIButtonInfobar();

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
};

#endif /* _UI_BUTTON_INFOBAR_H_ */
