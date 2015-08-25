#include "BSSpriteBase.h"
#include "GameObjectCreation.h"
#include "GameGeneral.h"
#include <SceneManager.h>
#include <GTPropertyFile.h>

GTBEHAVIOUR_IMP(BSSpriteBase, GTBehaviour);

BSSpriteBase::BSSpriteBase() : m_pSprite(NULL)
{
}


BSSpriteBase::~BSSpriteBase()
{
}


// This method is called when GTBehaviour object is created.
int32 BSSpriteBase::OnCreate(void)
{
	GTBehaviour::OnCreate();

	return 1;
}


// This method is called when GTBehaviour object is initialized.
int32 BSSpriteBase::OnInitialize(GTBehaviourInit* param)
{
	GTBehaviour::OnInitialize(param);

	if(NULL == param || NULL == param->pParam2)
		return 0;

	return CreateFromPropertyTreeNode((GTTreeNode*)param->pParam2) ? 1 : 0;
}


// If this GTBehaviour needs to be rebuilt
void BSSpriteBase::OnDirty(void)
{
}


// OnVisible is called when the the object is set visible.
void BSSpriteBase::OnVisible(void)
{
	// The game object is visible
	if(m_pSprite)
	{
		// Setup visibility
		m_pSprite->SetVisible(true);
	}
}


// OnVisible is called when the the object is set invisible.
void BSSpriteBase::OnInvisible(void)
{
	// The game object is invisible
	if(m_pSprite)
	{
		// Setup visibility
		m_pSprite->SetVisible(false);
	}
}


// OnChangeZOrder is called when the the object is set with new z-order.
void BSSpriteBase::OnChangeZOrder(const int32 nNewZOrder)
{
	if(m_pSprite)
	{
		//const int32 nOldZOrder = m_pSprite->GetZOrder();
		m_pSprite->SetZOrder(nNewZOrder);
	}
}


// Copy
bool BSSpriteBase::Copy(GTObject* pObjectFrom)
{
	BSSpriteBase* pSrc = static_cast<BSSpriteBase*>(pObjectFrom);
	DBG_ASSERT(pSrc && pSrc->m_pSprite);

	// Clone a sprite from source object
	m_pSprite = static_cast<GSprite*>(pSrc->m_pSprite->Clone());

	return true;
}


// OnStart is called just before any of the OnUpdate methods is called the first time.
int32 BSSpriteBase::OnStart(void)
{
	GTBehaviour::OnStart();

	if(m_pSprite && m_pGameObject)
	{
		// Initially, visible is same as game object's
		m_pSprite->SetVisible(m_pGameObject->GetVisible());
		// Initially, position is same as game object's
		m_pSprite->SetPosition(m_pGameObject->m_Position);
	}

	return 1;
}


// This method is called when GTBehaviour object is updated.
int32 BSSpriteBase::OnUpdate(void)
{
	GTBehaviour::OnUpdate();

	if(m_pSprite && m_pGameObject)
	{
		m_pSprite->SetPosition(m_pGameObject->m_Position);
	}

	return 1;
}


// This method is called when GTBehaviour object is destroyed.
int32 BSSpriteBase::OnDestroy(void)
{
	GTBehaviour::OnDestroy();

	if(m_pSprite)
	{
		m_pSprite->Release();
		m_pSprite = NULL;
	}

	return 1;
}


// Create the sprite from the property tree node
bool BSSpriteBase::CreateFromPropertyTreeNode(GTTreeNode *pTreeNode)
{
	if(NULL == pTreeNode)
		return false;

	// Get property sprite
	GTTreeNode* pSpriteNode = pTreeNode->GetChild(GTPropertyFile::TagSprite);
	if(NULL == pSpriteNode)
		return false;
	// Get property ZOrder
	GTTreeNode* pZOrderNode = pTreeNode->GetChild(GTPropertyFile::TagZOrder);
	const int32 nZOrder = (pZOrderNode != NULL) ? pZOrderNode->GetValue().AsInt() : GameGeneral::GetInstance()->GetZOrderIdSprite();

	// Create sprite object
	m_pSprite = GameObjectCreation::CreateAnimatedSprite(
		pSpriteNode->GetValue().ToCharString(), // sprite file name
		m_pGameObject->GetZOrder() // Use game object's z-order
		);
	if(NULL == m_pSprite)
		return false;

	// Get DefaultAnimation tag to see if this sprite has animations
	int32 nPlayMode = GSpriteAnimation::PlayMode_Once;
	GTTreeNode* pDefaultAnimationNode = pTreeNode->FindChild(GTPropertyFile::TagDefaultAnimation);
	GTTreeNode* pDefaultAnimationNodePlayMode = pTreeNode->FindChild(GTPropertyFile::TagDefaultAnimationPlayMode);
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
