#include "BSSprite.h"
#include "GameObjectCreation.h"
#include "GameGeneral.h"
#include <SceneManager.h>
#include "PropertyFile.h"

GTBEHAVIOUR_IMP(BSSprite, GTBehaviour);

BSSprite::BSSprite():
	m_pSprite(NULL)
{
}


BSSprite::~BSSprite()
{
}


// This method is called when GTBehaviour object is created.
int32 BSSprite::OnCreate(void)
{
	GTBehaviour::OnCreate();

	return 1;
}


// This method is called when GTBehaviour object is initialized.
int32 BSSprite::OnInitialize(GTBehaviourInitParam* param)
{
	GTBehaviour::OnInitialize(param);

	if(NULL == param || NULL == param->pParam2)
	{
		return 0;
	}

	return CreateFromPropertyTreeNode((GTTreeNode*)param->pParam2) ? 1 : 0;
}


// If this GTBehaviour needs to be rebuilt
void BSSprite::OnDirty(void)
{
}


// OnVisible is called when the the object is set visible.
void BSSprite::OnVisible(void)
{
	// The game object is visible
	if(m_pSprite)
	{
		// Setup visibility
		m_pSprite->SetVisible(true);
	}
}


// OnVisible is called when the the object is set invisible.
void BSSprite::OnInvisible(void)
{
	// The game object is invisible
	if(m_pSprite)
	{
		// Setup visibility
		m_pSprite->SetVisible(false);
	}
}


// OnStart is called just before any of the OnUpdate methods is called the first time.
int32 BSSprite::OnStart(void)
{
	GTBehaviour::OnStart();

	return 1;
}


// This method is called when GTBehaviour object is updated.
int32 BSSprite::OnUpdate(void)
{
	GTBehaviour::OnUpdate();

	if(m_pSprite && m_pGameObject)
	{
		// Transform game object position in map coordinate system to screen coordinate system
		const GTPoint2 screenPosition = SceneManager::GetInstance()->GetScreenPositionInMap();
		m_pSprite->SetPosition(
			m_pGameObject->m_Position.x - screenPosition.x,
			m_pGameObject->m_Position.y - screenPosition.y
			);
	}

	return 1;
}


// This method is called when GTBehaviour object is destroyed.
int32 BSSprite::OnDestroy(void)
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
bool BSSprite::CreateFromPropertyTreeNode(GTTreeNode *pTreeNode)
{
	if(NULL == pTreeNode)
	{
		return false;
	}

	// Create sprite object
	GTTreeNode* pSpriteNode = pTreeNode->GetChild(PropertyFile::TagSprite);
	if(NULL == pSpriteNode)
	{
		return false;
	}
	m_pSprite = GameObjectCreation::CreateAnimatedSprite(
		pSpriteNode->GetValue().ToCharString(),
		GameGeneral::GetInstance()->GetZOrderIdSprite()
		);
	if(NULL == m_pSprite)
	{
		return false;
	}

	int32 nPlayMode = GSpriteAnimation::PlayMode_Once;
	GTTreeNode* pDefaultAnimationNode = pTreeNode->FindChild(PropertyFile::TagDefaultAnimation);
	GTTreeNode* pDefaultAnimationNodePlayMode = pTreeNode->FindChild(PropertyFile::TagDefaultAnimationPlayMode);
	if(pDefaultAnimationNodePlayMode)
	{
		if(pDefaultAnimationNodePlayMode->GetValue() == CTEXT("Loop"))
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
