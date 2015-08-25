#include "UIFrame.h"
#include "UIWidgetClassManager.h"

UIWIDGET_IMP(UIFrame, UIWidget, UIWidgetClassManager::CreateClassInstanceDefineCallback)

UIFrame::UIFrame() : UIWidget()
{
}


UIFrame::UIFrame(UIWidget* pParent) : UIWidget(pParent)
{
}


UIFrame::~UIFrame()
{
}


// Override this method to serialize specific properties
bool UIFrame::OnSerializeTo(GTTreeNode* pTreeNode)
{
	return UIWidget::OnSerializeTo(pTreeNode);
}


// Override this method to serialize specific properties
bool UIFrame::OnSerializeFrom(GTTreeNode* pTreeNode)
{
	return UIWidget::OnSerializeFrom(pTreeNode);
}


// When the object is initialized, this method is called.
int32 UIFrame::OnInitialize(void)
{
	UIWidget::OnInitialize();

	return 1;
}


// When the system is updated, this method is called for each frame.
int32 UIFrame::OnUpdate(void)
{
	UIWidget::OnUpdate();

	return 1;
}


// This method is called for rendering each frame.
int32 UIFrame::OnRender(void)
{
	UIWidget::OnRender();

	return 1;
}


// Before the system is shut down, this method is called.
int32 UIFrame::OnDestroy(void)
{
	UIWidget::OnDestroy();

	return 1;
}


// Override GTObject::Release to do more things
void UIFrame::Release(void)
{
	UIWidget::Release();
}
