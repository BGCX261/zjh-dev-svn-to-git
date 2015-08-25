#ifndef _UI_LABEL_H_
#define _UI_LABEL_H_

#include "UIWidget.h"
#include "UILabelBMFont.h"

class UILabel : public UIWidget
{
public:
	UIWIDGET_DEF(UILabel, UIWidget)

public:
	UILabel();
	UILabel(UIWidget* pParent);
	virtual ~UILabel();

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

	// Set the text
	virtual void SetText(const tchar* szText);
	void SetTextFromINT8(const int8 nValue);
	void SetTextFromUINT8(const uint8 nValue);
	void SetTextFromINT16(const int16 nValue);
	void SetTextFromUINT16(const uint16 nValue);
	void SetTextFromINT32(const int32 nValue);
	void SetTextFromUINT32(const uint32 nValue);
	void SetTextFromFloat(const float fValue);
	// Set the position
	virtual void SetPosition(const GTPoint2& position);
	// Get the position
	virtual GTPoint2 GetPosition(void) const
	{
		return m_pUILabelBMFont ? m_pUILabelBMFont->GetPosition() : GTGameObject::GetPosition();
	}

	// Z-Order
	virtual int32 GetZOrder(void) const
	{
		return UIWidget::GetZOrder();
	}	
	virtual void SetZOrder(const int32 nZOrder)
	{
		UIWidget::SetZOrder(nZOrder);
		if(m_pUILabelBMFont)
			m_pUILabelBMFont->SetZOrder(nZOrder);
	}
	// Visible
	virtual void SetVisible(bool visible)
	{
		UIWidget::SetVisible(visible);
		if(m_pUILabelBMFont)
			m_pUILabelBMFont->SetVisible(visible);
	}
};

#endif /* _UI_LABEL_H_ */
