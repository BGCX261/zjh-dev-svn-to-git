#include <GTGameObject.h>
#include "UIButtonReveal.h"
#include "UIInfoPanelManager.h"
#include "../SlotGameBehavior/BSSlotsContainer.h"
#include <UI/UIWidgetClassManager.h>
#include "TimeManager.h"
#include <GTPropertyFile.h>
#include <GTGameObjectManager.h>

UIWIDGET_IMP(UIButtonReveal, UIWidget, UIWidgetClassManager::CreateClassInstanceDefineCallback)

UIButtonReveal::UIButtonReveal() : UIButton()
{
}


UIButtonReveal::UIButtonReveal(UIWidget* pParent) : UIButton(pParent)
{
}


UIButtonReveal::~UIButtonReveal()
{
}


// Override this method to serialize specific properties
bool UIButtonReveal::OnSerializeTo(GTTreeNode* pTreeNode)
{
	UIButton::OnSerializeTo(pTreeNode);

	return true;
}


// Override this method to serialize specific properties
bool UIButtonReveal::OnSerializeFrom(GTTreeNode* pTreeNode)
{
	UIButton::OnSerializeFrom(pTreeNode);

	if(NULL == pTreeNode)
	{
		return true;
	}

	return true;
}


// When the object is initialized, this method is called.
int32 UIButtonReveal::OnInitialize(void)
{
	UIButton::OnInitialize();

	return 1;
}


// When the system is updated, this method is called for each frame.
int32 UIButtonReveal::OnUpdate(void)
{
	UIButton::OnUpdate();

	return 1;
}


// This method is called for rendering each frame.
int32 UIButtonReveal::OnRender(void)
{
	UIButton::OnRender();

	return 1;
}


// Before the system is shut down, this method is called.
int32 UIButtonReveal::OnDestroy(void)
{
	UIButton::OnDestroy();

	return 1;
}


// Override GTObject::Release to do more things
void UIButtonReveal::Release(void)
{
	UIButton::Release();
}


bool UIButtonReveal::OnSingleClick(const uint32 nFlags, const GTPoint2& pos)
{
	UIButton::OnSingleClick(nFlags, pos);

	UIInfoPanelManager::GetInstance()->OnSingleClick(this, nFlags, pos);

	return true;
}


bool UIButtonReveal::OnDoubleClick(const uint32 nFlags, const GTPoint2& pos)
{
	return UIButton::OnDoubleClick(nFlags, pos);
}


bool UIButtonReveal::OnStateChange(const uint32 nState)
{
	return UIButton::OnStateChange(nState);
}
