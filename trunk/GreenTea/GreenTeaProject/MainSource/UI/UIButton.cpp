#include "UIButton.h"
#include "UIWidgetClassManager.h"

UIWIDGET_IMP(UIButton, UIWidget, UIWidgetClassManager::CreateClassInstanceDefineCallback)

UIButton::UIButton() : UIWidget(),
	m_bPressed(false)
{
}


UIButton::UIButton(UIWidget* pParent) : UIWidget(pParent),
	m_bPressed(false)
{
}


UIButton::~UIButton()
{
}


// Override this method to serialize specific properties
bool UIButton::OnSerializeTo(GTTreeNode* pTreeNode)
{
	return UIWidget::OnSerializeTo(pTreeNode);
}


// Override this method to serialize specific properties
bool UIButton::OnSerializeFrom(GTTreeNode* pTreeNode)
{
	return UIWidget::OnSerializeFrom(pTreeNode);
}


// When the object is initialized, this method is called.
int32 UIButton::OnInitialize(void)
{
	UIWidget::OnInitialize();
		
	return 1;
}


// When the system is updated, this method is called for each frame.
int32 UIButton::OnUpdate(void)
{
	UIWidget::OnUpdate();

	return 1;
}


// This method is called for rendering each frame.
int32 UIButton::OnRender(void)
{
	UIWidget::OnRender();

	return 1;
}


// Before the system is shut down, this method is called.
int32 UIButton::OnDestroy(void)
{
	UIWidget::OnDestroy();

	return 1;
}


// Override GTObject::Release to do more things
void UIButton::Release(void)
{
	UIWidget::Release();
}


// Events
bool UIButton::OnSingleClick(const uint32 nFlags, const GTPoint2& pos)
{
	// If this event is not handled by UIWidget::OnSingleClick,
	// UIButton doesn't need to handle it further.
	bool handled = UIWidget::OnSingleClick(nFlags, pos);
	if(!handled)
	{
		return (UISpriteSet::StateDisabled == GetState()) ? true : false;
	}

	if(nFlags & UIWidget::Flag_ClickDown)
	{
		m_bPressed = true;
		m_Sprite.SetVisible(true, UISpriteSet::StatePressed);
	}
	else if(nFlags & UIWidget::Flag_ClickUp)
	{
		m_Sprite.SetVisible(true, UISpriteSet::StateEnabled);
	}

	return handled;
}


bool UIButton::OnDoubleClick(const uint32 nFlags, const GTPoint2& pos)
{
	UIWidget::OnDoubleClick(nFlags, pos);

	return false;
}


bool UIButton::OnStateChange(const uint32 nState)
{
	UIWidget::OnStateChange(nState);

	return false;
}
