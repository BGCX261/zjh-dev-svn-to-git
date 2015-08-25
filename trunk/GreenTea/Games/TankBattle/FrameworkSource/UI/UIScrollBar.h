#ifndef _UI_SCROLLBAR_H_
#define _UI_SCROLLBAR_H_

#include "UIWidget.h"

class UIScrollBar : public UIWidget
{
public:
	UIWIDGET_DEF(UIScrollBar, UIWidget)

public:
	UIScrollBar();
	UIScrollBar(UIWidget* pParent);
	virtual ~UIScrollBar();

public:
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
};

#endif /* _UI_SCROLLBAR_H_ */
