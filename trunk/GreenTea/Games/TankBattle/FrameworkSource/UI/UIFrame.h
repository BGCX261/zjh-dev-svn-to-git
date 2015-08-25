#ifndef _UI_FRAME_H_
#define _UI_FRAME_H_

#include "UIWidget.h"

class UIFrame : public UIWidget
{
public:
	UIWIDGET_DEF(UIFrame, UIWidget)

public:
	UIFrame();
	UIFrame(UIWidget* pParent);
	virtual ~UIFrame();

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
};

#endif /* _UI_FRAME_H_ */
