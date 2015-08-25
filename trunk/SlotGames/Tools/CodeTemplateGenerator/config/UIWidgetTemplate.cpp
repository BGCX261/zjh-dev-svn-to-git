#include "$ClassReplacement$.h"
#include "UIWidgetClassManager.h"

UIWIDGET_IMP($ClassReplacement$, UIWidget, UIWidgetClassManager::CreateClassInstanceDefineCallback)

$ClassReplacement$::$ClassReplacement$() : UIWidget()
{
}


$ClassReplacement$::$ClassReplacement$(UIWidget* pParent) : UIWidget(pParent)
{
}


$ClassReplacement$::~$ClassReplacement$()
{
}


// When the object is initialized, this method is called.
int32 $ClassReplacement$::OnInitialize(void)
{
	UIWidget::OnInitialize();

	return 1;
}


// When the system is updated, this method is called for each frame.
int32 $ClassReplacement$::OnUpdate(void)
{
	UIWidget::OnUpdate();

	return 1;
}


// This method is called for rendering each frame.
int32 $ClassReplacement$::OnRender(void)
{
	UIWidget::OnRender();

	return 1;
}


// Before the system is shut down, this method is called.
int32 $ClassReplacement$::OnDestroy(void)
{
	UIWidget::OnDestroy();

	return 1;
}


// Override GTObject::Release to do more things
void $ClassReplacement$::Release(void)
{
	UIWidget::Release();
}
