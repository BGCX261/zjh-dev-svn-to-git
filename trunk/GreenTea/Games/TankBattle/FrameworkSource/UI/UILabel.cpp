#include "UILabel.h"
#include "UIWidgetClassManager.h"

UIWIDGET_IMP(UILabel, UIWidget, UIWidgetClassManager::CreateClassInstanceDefineCallback)

UILabel::UILabel() : UIWidget()
{
}


UILabel::UILabel(UIWidget* pParent) : UIWidget(pParent)
{
}


UILabel::~UILabel()
{
}


// Override this method to serialize specific properties
bool UILabel::OnSerializeTo(GTTreeNode* pTreeNode)
{
	return UIWidget::OnSerializeTo(pTreeNode);
}


// Override this method to serialize specific properties
bool UILabel::OnSerializeFrom(GTTreeNode* pTreeNode)
{
	UIWidget::OnSerializeFrom(pTreeNode);

	// Visible
	SetVisible(UIWidget::GetVisible(), true);

	return true;
}


// When the object is initialized, this method is called.
int32 UILabel::OnInitialize(void)
{
	UIWidget::OnInitialize();

	return 1;
}


// When the system is updated, this method is called for each frame.
int32 UILabel::OnUpdate(void)
{
	UIWidget::OnUpdate();

	return 1;
}


// This method is called for rendering each frame.
int32 UILabel::OnRender(void)
{
	UIWidget::OnRender();

	return 1;
}


// Before the system is shut down, this method is called.
int32 UILabel::OnDestroy(void)
{
	UIWidget::OnDestroy();

	return 1;
}


// Override GTObject::Release to do more things
void UILabel::Release(void)
{
	UIWidget::Release();
}


// Set the text
void UILabel::SetText(const tchar* szText)
{
	UIWidget::SetText(szText);
	if(m_pUILabelBMFont)
	{
		m_pUILabelBMFont->SetText(UIWidget::m_sText);
	}
}
void UILabel::SetTextFromINT8(const int8 nValue)
{
	UIWidget::SetTextFromINT8(nValue);
	if(m_pUILabelBMFont)
	{
		m_pUILabelBMFont->SetText(UIWidget::m_sText);
	}
}
void UILabel::SetTextFromUINT8(const uint8 nValue)
{
	UIWidget::SetTextFromUINT8(nValue);
	if(m_pUILabelBMFont)
	{
		m_pUILabelBMFont->SetText(UIWidget::m_sText);
	}
}
void UILabel::SetTextFromINT16(const int16 nValue)
{
	UIWidget::SetTextFromINT16(nValue);
	if(m_pUILabelBMFont)
	{
		m_pUILabelBMFont->SetText(UIWidget::m_sText);
	}
}
void UILabel::SetTextFromUINT16(const uint16 nValue)
{
	UIWidget::SetTextFromUINT16(nValue);
	if(m_pUILabelBMFont)
	{
		m_pUILabelBMFont->SetText(UIWidget::m_sText);
	}
}
void UILabel::SetTextFromINT32(const int32 nValue)
{
	UIWidget::SetTextFromINT32(nValue);
	if(m_pUILabelBMFont)
	{
		m_pUILabelBMFont->SetText(UIWidget::m_sText);
	}
}
void UILabel::SetTextFromUINT32(const uint32 nValue)
{
	UIWidget::SetTextFromUINT32(nValue);
	if(m_pUILabelBMFont)
	{
		m_pUILabelBMFont->SetText(UIWidget::m_sText);
	}
}
void UILabel::SetTextFromFloat(const float fValue)
{
	UIWidget::SetTextFromFloat(fValue);
	if(m_pUILabelBMFont)
	{
		m_pUILabelBMFont->SetText(UIWidget::m_sText);
	}
}


// Set the position
void UILabel::SetPosition(const GTPoint2& position)
{
	if(m_pUILabelBMFont)
	{
		m_pUILabelBMFont->SetPosition(position.x, position.y);			
	}
	else
	{
		GTGameObject::SetPosition(position);
	}
}
