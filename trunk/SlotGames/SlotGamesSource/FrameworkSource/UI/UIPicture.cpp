#include "UIPicture.h"
#include "UIWidgetClassManager.h"
#include <GTPropertyFile.h>
#include "GameObjectCreation.h"

UIWIDGET_IMP(UIPicture, UIWidget, UIWidgetClassManager::CreateClassInstanceDefineCallback)

UIPicture::UIPicture() : UIWidgetSprite()
{
}


UIPicture::UIPicture(UIWidget* pParent) : UIWidgetSprite(pParent)
{
}


UIPicture::~UIPicture()
{
}


// Override this method to serialize specific properties
bool UIPicture::OnSerializeTo(GTTreeNode* pTreeNode)
{
	return UIWidgetSprite::OnSerializeTo(pTreeNode);
}


// Override this method to serialize specific properties
bool UIPicture::OnSerializeFrom(GTTreeNode* pTreeNode)
{
	if(NULL == pTreeNode)
		return false;

	UIWidgetSprite::OnSerializeFrom(pTreeNode);

	// PieceEnabled is not defined so check Image node
	if(false == m_Sprite.HasSprite())
	{
		// Read Image node
		GTTreeNode* pImageNode = pTreeNode->FindChild(GTPropertyFile::TagImage);
		// Create static sprite object
		if(NULL == pImageNode)
			return false;
		m_pSprite = GameObjectCreation::CreateStaticSprite(
			pImageNode->GetValue().ToCharString(), // Image file name
			GetParent()->GetZOrder() // User parent's z-order
			);
		if(NULL == m_pSprite)
			return false;
	}
	
	if(m_pSprite)
	{
		// Setup position
		m_pSprite->SetPosition(GetPosition());
		// Setup ZOrder
		m_pSprite->SetZOrder(GetZOrder());
		// Setup Visible
		m_pSprite->SetVisible(GetVisible());
	}

	return true;
}


// OnChangeZOrder is called when the the object is set with new z-order.
void UIPicture::OnChangeZOrder(const int32 nNewZOrder)
{
	UIWidgetSprite::OnChangeZOrder(nNewZOrder);

	if(m_pSprite)
	{
		m_pSprite->SetZOrder(nNewZOrder);
	}
	else
	{
		m_Sprite.SetZOrder(nNewZOrder);
	}
}


// When the object is initialized, this method is called.
int32 UIPicture::OnInitialize(void)
{
	UIWidgetSprite::OnInitialize();

	return 1;
}


// When the system is updated, this method is called for each frame.
int32 UIPicture::OnUpdate(void)
{
	UIWidgetSprite::OnUpdate();

	return 1;
}


// This method is called for rendering each frame.
int32 UIPicture::OnRender(void)
{
	UIWidgetSprite::OnRender();

	return 1;
}


// Before the system is shut down, this method is called.
int32 UIPicture::OnDestroy(void)
{
	UIWidgetSprite::OnDestroy();

	return 1;
}


// Override GTObject::Release to do more things
void UIPicture::Release(void)
{
	UIWidgetSprite::Release();
}


// Z-Order
int32 UIPicture::GetZOrder(void) const
{
	return m_pSprite ? m_pSprite->GetZOrder() : UIWidget::GetZOrder();
}


void UIPicture::SetZOrder(const int32 nZOrder)
{
	UIWidgetSprite::SetZOrder(nZOrder);
	if(m_pSprite)
		m_pSprite->SetZOrder(nZOrder);
	else
		m_Sprite.SetZOrder(nZOrder);
}


// Visible
void UIPicture::SetVisible(bool visible)
{
	UIWidgetSprite::SetVisible(visible);
	if(m_pSprite)
		m_pSprite->SetVisible(visible);
	else
		m_Sprite.SetVisible(visible);
}


bool UIPicture::GetVisible(void) const
{
	return UIWidgetSprite::GetVisible();
}
