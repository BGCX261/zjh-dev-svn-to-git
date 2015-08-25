#ifndef _UI_WIDGET_SPRITE_H_
#define _UI_WIDGET_SPRITE_H_

#include "UIWidget.h"
#include <Sprite/GSprite.h>

class UIWidgetSprite : public UIWidget
{
public:
	UIWIDGET_DEF(UIWidgetSprite, UIWidget)

public:
	UIWidgetSprite();
	UIWidgetSprite(UIWidget* pParent);
	virtual ~UIWidgetSprite();

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
	virtual int32 GetZOrder(void) const
	{
		return m_pSprite ? m_pSprite->GetZOrder() : -1;
	}	
	virtual void SetZOrder(const int32 nZOrder)
	{
		UIWidget::SetZOrder(nZOrder);
		if(m_pSprite)
			m_pSprite->SetZOrder(nZOrder);			
	}

	// Visible
	virtual void SetVisible(bool visible)
	{
		UIWidget::SetVisible(visible);
		if(m_pSprite)
			m_pSprite->SetVisible(visible);
	}
	virtual bool GetVisible(void) const	
	{
		return m_pSprite ? m_pSprite->GetVisible() : false;
	}

protected:
	// The sprite object
	GSprite* m_pSprite;
};

#endif /* _UI_WIDGET_SPRITE_H_ */
