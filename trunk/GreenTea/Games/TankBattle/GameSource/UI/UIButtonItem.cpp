#include "UIButtonItem.h"
#include <UI/UIWidgetClassManager.h>
#include <GTGreenTea.h>
#include <GameObjectCreation.h>
#include <GTGameObjectManager.h>

UIWIDGET_IMP(UIButtonItem, UIWidget, UIWidgetClassManager::CreateClassInstanceDefineCallback)

UIButtonItem::UIButtonItem() : UIButton()
{
}


UIButtonItem::UIButtonItem(UIWidget* pParent) : UIButton(pParent)
{
}


UIButtonItem::~UIButtonItem()
{
}


// When the object is initialized, this method is called.
int32 UIButtonItem::OnInitialize(void)
{
	UIWidget::OnInitialize();

	return 1;
}


// When the system is updated, this method is called for each frame.
int32 UIButtonItem::OnUpdate(void)
{
	UIWidget::OnUpdate();

	return 1;
}


// This method is called for rendering each frame.
int32 UIButtonItem::OnRender(void)
{
	UIWidget::OnRender();

	return 1;
}


// Override GTObject::Release to do more things
void UIButtonItem::Release(void)
{
	UIWidget::Release();
}


bool UIButtonItem::OnSingleClick(const uint32 nFlags, const GTPoint2& pos)
{
	UIButton::OnSingleClick(nFlags, pos);

	if(nFlags & UIWidget::Flag_ClickUp)
	{
		/*
		switch(GetId())
		{
		}
		*/
	}

	return true;
}


// Before the system is shut down, this method is called.
int32 UIButtonItem::OnDestroy(void)
{
	UIWidget::OnDestroy();

	return 1;
}


bool UIButtonItem::OnDoubleClick(const uint32 nFlags, const GTPoint2& pos)
{
	return UIButton::OnDoubleClick(nFlags, pos);
}


bool UIButtonItem::OnStateChange(const uint32 nState)
{
	return UIButton::OnStateChange(nState);
}
