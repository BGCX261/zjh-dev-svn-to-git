#include "UIPicture.h"
#include "UIWidgetClassManager.h"

UIWIDGET_IMP(UIPicture, UIWidget, UIWidgetClassManager::CreateClassInstanceDefineCallback)

UIPicture::UIPicture() : UIWidget()
{
}


UIPicture::UIPicture(UIWidget* pParent) : UIWidget(pParent)
{
}


UIPicture::~UIPicture()
{
}


// When the object is initialized, this method is called.
int32 UIPicture::OnInitialize(void)
{
	UIWidget::OnInitialize();

	return 1;
}


// When the system is updated, this method is called for each frame.
int32 UIPicture::OnUpdate(void)
{
	UIWidget::OnUpdate();

	return 1;
}


// This method is called for rendering each frame.
int32 UIPicture::OnRender(void)
{
	UIWidget::OnRender();

	return 1;
}


// Before the system is shut down, this method is called.
int32 UIPicture::OnDestroy(void)
{
	UIWidget::OnDestroy();

	return 1;
}


// Override GTObject::Release to do more things
void UIPicture::Release(void)
{
	UIWidget::Release();
}
