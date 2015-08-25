#include "UIAnimation.h"
#include "UIWidgetClassManager.h"
#include <GTPropertyFile.h>
#include "GameObjectCreation.h"

UIWIDGET_IMP(UIAnimation, UIWidget, UIWidgetClassManager::CreateClassInstanceDefineCallback)

UIAnimation::UIAnimation() : UIWidgetSprite()
{
}


UIAnimation::UIAnimation(UIWidget* pParent) : UIWidgetSprite(pParent)
{
}


UIAnimation::~UIAnimation()
{
}


// Override this method to serialize specific properties
bool UIAnimation::OnSerializeTo(GTTreeNode* pTreeNode)
{
	return UIWidgetSprite::OnSerializeTo(pTreeNode);
}


// Override this method to serialize specific properties
bool UIAnimation::OnSerializeFrom(GTTreeNode* pTreeNode)
{
	if(NULL == pTreeNode)
		return false;

	UIWidgetSprite::OnSerializeFrom(pTreeNode);
	
	// Read sprite node
	GTTreeNode* pSpriteNode = pTreeNode->FindChild(GTPropertyFile::TagSprite);
	// Read animation nodes
	GTTreeNode* pDefaultAnimationNode = pTreeNode->FindChild(GTPropertyFile::TagDefaultAnimation);
	GTTreeNode* pDefaultAnimationNodePlayMode = pTreeNode->FindChild(GTPropertyFile::TagDefaultAnimationPlayMode);
		
	// Create sprite object
	if(NULL == pSpriteNode)
		return false;
	m_pSprite = GameObjectCreation::CreateAnimatedSprite(
		pSpriteNode->GetValue().ToCharString(), // sprite file name
		GetParent()->GetZOrder() // User parent's z-order
		);
	if(NULL == m_pSprite)
		return false;
	
	// Setup position
	m_pSprite->SetPosition(UIWidget::GetPosition());
	// Setup ZOrder
	m_pSprite->SetZOrder(UIWidget::GetZOrder());
	// Setup Visible
	m_pSprite->SetVisible(UIWidget::GetVisible());

	// Setup animation to see if this sprite has animations
	int32 nPlayMode = GSpriteAnimation::PlayMode_Once;	
	if(pDefaultAnimationNodePlayMode)
	{
		if(pDefaultAnimationNodePlayMode->GetValue() == CTEXT("None"))
			nPlayMode = GSpriteAnimation::PlayMode_None;
		else if(pDefaultAnimationNodePlayMode->GetValue() == CTEXT("Loop"))
			nPlayMode = GSpriteAnimation::PlayMode_Loop;
		else if(pDefaultAnimationNodePlayMode->GetValue() == CTEXT("Once"))
			nPlayMode = GSpriteAnimation::PlayMode_Once;
	}
	if(pDefaultAnimationNode)
	{
		// NOTE: I think playing animation might be in OnStart
		m_pSprite->PlayAnimationByIndex(pDefaultAnimationNode->GetValue().ToInt(), nPlayMode);
		//m_pSprite->StopAnimation();
	}

	return true;
}


// OnChangeZOrder is called when the the object is set with new z-order.
void UIAnimation::OnChangeZOrder(const int32 nNewZOrder)
{
	UIWidgetSprite::OnChangeZOrder(nNewZOrder);

	if(m_pSprite)
	{
		m_pSprite->SetZOrder(nNewZOrder);
	}
}


// When the object is initialized, this method is called.
int32 UIAnimation::OnInitialize(void)
{
	UIWidgetSprite::OnInitialize();
		
	return 1;
}


// When the system is updated, this method is called for each frame.
int32 UIAnimation::OnUpdate(void)
{
	UIWidgetSprite::OnUpdate();

	return 1;
}


// This method is called for rendering each frame.
int32 UIAnimation::OnRender(void)
{
	UIWidgetSprite::OnRender();

	return 1;
}


// Before the system is shut down, this method is called.
int32 UIAnimation::OnDestroy(void)
{
	return UIWidgetSprite::OnDestroy();
}


// Override GTObject::Release to do more things
void UIAnimation::Release(void)
{
	UIWidgetSprite::Release();
}
