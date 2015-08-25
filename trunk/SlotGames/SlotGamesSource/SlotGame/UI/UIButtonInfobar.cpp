#include <GTGameObject.h>
#include "UIButtonInfobar.h"
#include "UIInfoPanelManager.h"
#include "../SlotGameBehavior/BSSlotsContainer.h"
#include <UI/UIWidgetClassManager.h>
#include "TimeManager.h"
#include <GTPropertyFile.h>
#include <GTGameObjectManager.h>

UIWIDGET_IMP(UIButtonInfobar, UIWidget, UIWidgetClassManager::CreateClassInstanceDefineCallback)

UIButtonInfobar::UIButtonInfobar() : UIButton()
{
}


UIButtonInfobar::UIButtonInfobar(UIWidget* pParent) : UIButton(pParent)
{
}


UIButtonInfobar::~UIButtonInfobar()
{
}


// Override this method to serialize specific properties
bool UIButtonInfobar::OnSerializeTo(GTTreeNode* pTreeNode)
{
	UIButton::OnSerializeTo(pTreeNode);

	return true;
}


// Override this method to serialize specific properties
bool UIButtonInfobar::OnSerializeFrom(GTTreeNode* pTreeNode)
{
	UIButton::OnSerializeFrom(pTreeNode);

	if(NULL == pTreeNode)
	{
		return true;
	}

	return true;
}


// When the object is initialized, this method is called.
int32 UIButtonInfobar::OnInitialize(void)
{
	UIButton::OnInitialize();

	return 1;
}


// When the system is updated, this method is called for each frame.
int32 UIButtonInfobar::OnUpdate(void)
{
	UIButton::OnUpdate();

	return 1;
}


// This method is called for rendering each frame.
int32 UIButtonInfobar::OnRender(void)
{
	UIButton::OnRender();

	return 1;
}


// Before the system is shut down, this method is called.
int32 UIButtonInfobar::OnDestroy(void)
{
	UIButton::OnDestroy();

	return 1;
}


// Override GTObject::Release to do more things
void UIButtonInfobar::Release(void)
{
	UIButton::Release();
}


bool UIButtonInfobar::OnSingleClick(const uint32 nFlags, const GTPoint2& pos)
{
	UIButton::OnSingleClick(nFlags, pos);

	UIInfoPanelManager::GetInstance()->OnSingleClick(this, nFlags, pos);

	return true;
}


bool UIButtonInfobar::OnDoubleClick(const uint32 nFlags, const GTPoint2& pos)
{
	return UIButton::OnDoubleClick(nFlags, pos);
}


bool UIButtonInfobar::OnStateChange(const uint32 nState)
{
	return UIButton::OnStateChange(nState);
}
