#include "UICheckBox.h"
#include "UIWidgetClassManager.h"

UIWIDGET_IMP(UICheckBox, UIWidget, UIWidgetClassManager::CreateClassInstanceDefineCallback)

UICheckBox::UICheckBox() : UIWidget()
{
}


UICheckBox::UICheckBox(UIWidget* pParent) : UIWidget(pParent)
{
}


UICheckBox::~UICheckBox()
{
}


// Override this method to serialize specific properties
bool UICheckBox::OnSerializeTo(GTTreeNode* pTreeNode)
{
	return UIWidget::OnSerializeTo(pTreeNode);
}


// Override this method to serialize specific properties
bool UICheckBox::OnSerializeFrom(GTTreeNode* pTreeNode)
{
	return UIWidget::OnSerializeFrom(pTreeNode);
}


// When the object is initialized, this method is called.
int32 UICheckBox::OnInitialize(void)
{
	UIWidget::OnInitialize();

	return 1;
}


// When the system is updated, this method is called for each frame.
int32 UICheckBox::OnUpdate(void)
{
	UIWidget::OnUpdate();

	return 1;
}


// This method is called for rendering each frame.
int32 UICheckBox::OnRender(void)
{
	UIWidget::OnRender();

	return 1;
}


// Before the system is shut down, this method is called.
int32 UICheckBox::OnDestroy(void)
{
	UIWidget::OnDestroy();

	return 1;
}


// Override GTObject::Release to do more things
void UICheckBox::Release(void)
{
	UIWidget::Release();
}
