#include "UIScrollBar.h"
#include "UIWidgetClassManager.h"

UIWIDGET_IMP(UIScrollBar, UIWidget, UIWidgetClassManager::CreateClassInstanceDefineCallback)

UIScrollBar::UIScrollBar() : UIWidget()
{
}


UIScrollBar::UIScrollBar(UIWidget* pParent) : UIWidget(pParent)
{
}


UIScrollBar::~UIScrollBar()
{
}


// When the object is initialized, this method is called.
int32 UIScrollBar::OnInitialize(void)
{
	UIWidget::OnInitialize();

	return 1;
}


// When the system is updated, this method is called for each frame.
int32 UIScrollBar::OnUpdate(void)
{
	UIWidget::OnUpdate();

	return 1;
}


// This method is called for rendering each frame.
int32 UIScrollBar::OnRender(void)
{
	UIWidget::OnRender();

	return 1;
}


// Before the system is shut down, this method is called.
int32 UIScrollBar::OnDestroy(void)
{
	UIWidget::OnDestroy();

	return 1;
}


// Override GTObject::Release to do more things
void UIScrollBar::Release(void)
{
	UIWidget::Release();
}
