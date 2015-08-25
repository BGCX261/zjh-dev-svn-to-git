#include "UIWidgetSprite.h"
#include "UIWidgetClassManager.h"
#include <GTPropertyFile.h>

UIWIDGET_IMP(UIWidgetSprite, UIWidget, UIWidgetClassManager::CreateClassInstanceDefineCallback)

UIWidgetSprite::UIWidgetSprite() : UIWidget(), m_pSprite(NULL)
{
}


UIWidgetSprite::UIWidgetSprite(UIWidget* pParent) : UIWidget(pParent), m_pSprite(NULL)
{
}


UIWidgetSprite::~UIWidgetSprite()
{
}


// Override this method to serialize specific properties
bool UIWidgetSprite::OnSerializeTo(GTTreeNode* pTreeNode)
{
	return UIWidget::OnSerializeTo(pTreeNode);
}


// Override this method to serialize specific properties
bool UIWidgetSprite::OnSerializeFrom(GTTreeNode* pTreeNode)
{
	if(NULL == pTreeNode)
		return false;

	UIWidget::OnSerializeFrom(pTreeNode);
	
	return true;
}


// OnChangeZOrder is called when the the object is set with new z-order.
void UIWidgetSprite::OnChangeZOrder(const int32 nNewZOrder)
{
	UIWidget::OnChangeZOrder(nNewZOrder);

	if(m_pSprite)
	{
		m_pSprite->SetZOrder(nNewZOrder);
	}
}


// When the object is initialized, this method is called.
int32 UIWidgetSprite::OnInitialize(void)
{
	UIWidget::OnInitialize();
		
	return 1;
}


// When the system is updated, this method is called for each frame.
int32 UIWidgetSprite::OnUpdate(void)
{
	UIWidget::OnUpdate();

	return 1;
}


// This method is called for rendering each frame.
int32 UIWidgetSprite::OnRender(void)
{
	UIWidget::OnRender();

	return 1;
}


// Before the system is shut down, this method is called.
int32 UIWidgetSprite::OnDestroy(void)
{
	UIWidget::OnDestroy();

	if(m_pSprite)
	{
		m_pSprite->Release();
		m_pSprite = NULL;
	}

	return 1;
}


// Override GTObject::Release to do more things
void UIWidgetSprite::Release(void)
{
	UIWidget::Release();
}
