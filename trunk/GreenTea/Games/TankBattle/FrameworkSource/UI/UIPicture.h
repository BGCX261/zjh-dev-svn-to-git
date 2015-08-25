#ifndef _UI_PICTURE_H_
#define _UI_PICTURE_H_

#include "UIWidget.h"
#include "UIWidgetSprite.h"

class UIPicture : public UIWidgetSprite
{
public:
	UIWIDGET_DEF(UIPicture, UIWidget)

public:
	UIPicture();
	UIPicture(UIWidget* pParent);
	virtual ~UIPicture();

public:
	// Override this method to serialize specific properties
	virtual bool OnSerializeTo(GTTreeNode* pTreeNode);
	// Override this method to serialize specific properties
	virtual bool OnSerializeFrom(GTTreeNode* pTreeNode);
	// OnChangeZOrder is called when the the object is set with new z-order.
	virtual void OnChangeZOrder(const int32 nNewZOrder);

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

	// Z-Order
	virtual int32 GetZOrder(void) const;
	virtual void SetZOrder(const int32 nZOrder);
	// Visible
	virtual void SetVisible(bool visible, bool bApplyForChildren);
	virtual bool GetVisible(void) const;
};

#endif /* _UI_PICTURE_H_ */
