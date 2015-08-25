#include "BSStaticSprite.h"
#include "GameObjectCreation.h"
#include "GameGeneral.h"
#include <SceneManager.h>
#include <GTPropertyFile.h>

GTBEHAVIOUR_IMP(BSStaticSprite, GTBehaviour);

BSStaticSprite::BSStaticSprite():
	m_pSprite(NULL)
{
}


BSStaticSprite::~BSStaticSprite()
{
}


// This method is called when GTBehaviour object is created.
int32 BSStaticSprite::OnCreate(void)
{
	GTBehaviour::OnCreate();

	return 1;
}


// This method is called when GTBehaviour object is initialized.
int32 BSStaticSprite::OnInitialize(GTBehaviourInitParam* param)
{
	GTBehaviour::OnInitialize(param);

	if(NULL == param || NULL == param->pParam2)
	{
		return 0;
	}

	return CreateFromPropertyTreeNode((GTTreeNode*)param->pParam2) ? 1 : 0;
}


// If this GTBehaviour needs to be rebuilt
void BSStaticSprite::OnDirty(void)
{
}


// OnVisible is called when the the object is set visible.
void BSStaticSprite::OnVisible(void)
{
	// The game object is visible
	if(m_pSprite)
	{
		// Setup visibility
		m_pSprite->SetVisible(true);
	}
}


// OnVisible is called when the the object is set invisible.
void BSStaticSprite::OnInvisible(void)
{
	// The game object is invisible
	if(m_pSprite)
	{
		// Setup visibility
		m_pSprite->SetVisible(false);
	}
}


// OnStart is called just before any of the OnUpdate methods is called the first time.
int32 BSStaticSprite::OnStart(void)
{
	GTBehaviour::OnStart();

	return 1;
}


// This method is called when GTBehaviour object is updated.
int32 BSStaticSprite::OnUpdate(void)
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
int32 BSStaticSprite::OnDestroy(void)
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
bool BSStaticSprite::CreateFromPropertyTreeNode(GTTreeNode *pTreeNode)
{
	if(NULL == pTreeNode)
	{
		return false;
	}

	// Get sprite node
	GTTreeNode* pSpriteNode = pTreeNode->GetChild(GTPropertyFile::TagSprite);
	if(NULL == pSpriteNode)
	{
		return false;
	}
	// Create sprite object
	m_pSprite = GameObjectCreation::CreateStaticSpriteWithSpriteFile(
		pSpriteNode->GetValue().ToCharString(),
		GameGeneral::GetInstance()->GetZOrderIdSprite()
		);
	if(NULL == m_pSprite)
	{
		return false;
	}

	return true;
}
