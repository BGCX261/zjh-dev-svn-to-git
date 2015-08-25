#include <GTPropertyFile.h>
#include "GameObjectSprite.h"
#include "GameGeneral.h"
#include "GameObjectCreation.h"
#include "SceneManager.h"

GTGAMEOBJECT_IMP(GameObjectSprite, GTGameObject, GTGameObjectClassManager::CreateClassInstanceDefineCallback)

GameObjectSprite::GameObjectSprite() : GTGameObject(), m_pSprite(NULL)
{
}


GameObjectSprite::GameObjectSprite(GTGameObject* pParent) : GTGameObject(pParent), m_pSprite(NULL)
{
}


GameObjectSprite::~GameObjectSprite()
{
}


// Copy
bool GameObjectSprite::Copy(GTObject* pObjectFrom)
{
	GTGameObject::Copy(pObjectFrom);

	GameObjectSprite* pSrc = dynamic_cast<GameObjectSprite*>(pObjectFrom);
	if(NULL == pSrc)
		return false;

	if(pSrc)
	{
		// Clone a sprite from source object
		m_pSprite = static_cast<GSprite*>(pSrc->m_pSprite->Clone());
	}

	return true;
}


/*
// Override this method to serialize specific properties
bool GameObjectSprite::OnSerializeTo(GTTreeNode* pTreeNode)
{
	//return GTGameObject::OnSerializeTo(pTreeNode);
	return true;
}


// Override this method to serialize specific properties
bool GameObjectSprite::OnSerializeFrom(GTTreeNode* pTreeNode)
{
	//return UIWidget::OnSerializeFrom(pTreeNode);
	return true;
}
*/


// This method is called when GTGameObject object is created (memory allocation).
int32 GameObjectSprite::OnCreate(void)
{
	GTGameObject::OnCreate();

	return 1;
}


// When the object is initialized, this method is called.
int32 GameObjectSprite::OnInitialize(GTGameObjectInit* param)
{
	if(NULL == param || NULL == param->pParam1)
		return 0;

	GTGameObject::OnInitialize(param);

	// Tree node
	GTTreeNode* pTreeNode = (GTTreeNode*)(param->pParam1);
	// Get property sprite
	GTTreeNode* pSpriteNode = pTreeNode->GetChild(GTPropertyFile::TagSprite);
	if(NULL == pSpriteNode)
		return false;
	// Get ZOrder
	GTTreeNode* pZOrderNode = pTreeNode->GetChild(GTPropertyFile::TagZOrder);
	const int32 nZOrder = (pZOrderNode != NULL) ? pZOrderNode->GetValue().AsInt() : GameGeneral::GetInstance()->GetZOrderIdSprite();
	// Get anchor point
	GTTreeNode* pAnchorPointNode = pTreeNode->GetChild(GTPropertyFile::TagAnchorPoint);
	// Get scale
	GTTreeNode* pScaleNode = pTreeNode->GetChild(GTPropertyFile::TagScale);
	
	// Create sprite object
	m_pSprite = GameObjectCreation::CreateSprite(
		pSpriteNode->GetValue().ToCharString(), // sprite file name
		GTGameObject::GetZOrder() // Use game object's z-order
		);
	if(NULL == m_pSprite)
		return false;
	// Set same visible as GTGameObject for initial status
	m_pSprite->SetVisible(GTGameObject::GetVisible());
	// Set same position as GTGameObject
	m_pSprite->SetPosition(GTGameObject::GetPosition());
	// Set anchor point
	if(pAnchorPointNode)
		m_pSprite->SetAnchorPoint(pAnchorPointNode->ValueToVector2());
	else // If there is no AnchorPoint defined, set default to center
		m_pSprite->SetAnchorPoint(GSprite::AnchorPoint_Center);
	// Set scale
	if(pScaleNode)
	{
		GTVector2 scale = pScaleNode->ValueToVector2();
		m_pSprite->SetScaleX(scale.x);
		m_pSprite->SetScaleY(scale.y);
	}
	// Set z-order
	GameObjectSprite::SetZOrder(nZOrder);

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

	return 1;
}


// The OnStart function is called after all OnCreated functions on all script instances have been called.
int32 GameObjectSprite::OnStart(void)
{
	return GTGameObject::OnStart();
}


// When the system is updated, this method is called for each frame.
int32 GameObjectSprite::OnUpdate(void)
{
	GTGameObject::OnUpdate();

	if(m_pSprite)
	{
	}

	return 1;
}


// This method is called for rendering each frame.
int32 GameObjectSprite::OnRender(void)
{
	GTGameObject::OnRender();

	return 1;
}


// Before the system is shut down, this method is called.
int32 GameObjectSprite::OnDestroy(void)
{
	GTGameObject::OnDestroy();

	if(m_pSprite)
	{
		m_pSprite->Release();
		m_pSprite = NULL;
	}

	return 1;
}


// Override GTObject::Release to do more things
void GameObjectSprite::Release(void)
{
	GTGameObject::Release();
}


// If the object needs to be rebuilt
void GameObjectSprite::OnDirty(void)
{
	GTGameObject::OnDirty();
}


// OnVisible is called when the the object is set visible.
void GameObjectSprite::OnVisible(GTGameObject *pCaller, bool bApplyForChildren)
{
	if(m_pSprite)
	{
		m_pSprite->SetVisible(true);
	}
	GTGameObject::OnVisible(pCaller, bApplyForChildren);
}


// OnInvisible is called when the the object is set invisible.
void GameObjectSprite::OnInvisible(GTGameObject *pCaller, bool bApplyForChildren)
{
	if(m_pSprite)
	{
		m_pSprite->SetVisible(false);
	}
	GTGameObject::OnInvisible(pCaller, bApplyForChildren);
}


// This function is called when the behaviour becomes disabled or inactive.
void GameObjectSprite::OnDisable(void)
{
	GTGameObject::OnDisable();
}


// This function is called when the object becomes enabled and active.
void GameObjectSprite::OnEnable(void)
{
	GTGameObject::OnEnable();
}


// OnChangeZOrder is called when the the object is set with new z-order.
void GameObjectSprite::OnChangeZOrder(const int32 nNewZOrder)
{
	GTGameObject::OnChangeZOrder(nNewZOrder);

	if(m_pSprite)
	{
		m_pSprite->SetZOrder(nNewZOrder);
	}
}


// OnChangePosition is called when the the object is set with new position.
void GameObjectSprite::OnChangePosition(const GTPoint2 position)
{
	GTGameObject::OnChangePosition(position);

	if(GTString::IsEqual(m_strName.ToCharString(), CTEXT("explosion")))
	{
		int32 k = 0;
	}
	if(m_pSprite)
	{
		// If the object has parent, apply Parent position + position.
		const GTVector2 posParent = m_pParent ? m_pParent->GetPosition() : GTVector2::Zero;
		const GTVector2 posObject = GetPosition();
		m_pSprite->SetPosition(posParent + posObject);
		//m_pSprite->SetPosition(m_pParent ? (m_pParent->GetPosition() + position) : position);
	}
}
