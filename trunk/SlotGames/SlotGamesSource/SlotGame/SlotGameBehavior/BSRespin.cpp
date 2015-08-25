#include "BSRespin.h"
#include <BehaviourScript/BSClassName.h>
#include <GameObjectCreation.h>
#include "GTGameObjectManager.h"

GTBEHAVIOUR_IMP(BSRespin, GTBehaviour);

#define PROPERTY_TAG_LOCK		CTEXT("lockAnimation")
#define PROPERTY_TAG_LOCK_HIGHLIGHT		CTEXT("lock_highlight_Animation")

BSRespin::BSRespin() : m_pLockAnimation(NULL), m_pLockHighlightAnim(NULL)
{
}


BSRespin::~BSRespin()
{
}


// This method is called when GTBehaviour object is created.
int32 BSRespin::OnCreate(void)
{
	GTBehaviour::OnCreate();

	m_status = Status_None;

	return 1;
}


// This method is called when GTBehaviour object is initialized.
int32 BSRespin::OnInitialize(GTBehaviourInitParam* param)
{
	GTBehaviour::OnInitialize(param);
		
	if(NULL == param || NULL == param->pParam2)
	{
		return 0;
	}

	return CreateFromPropertyTreeNode((GTTreeNode*)param->pParam2) ? 1 : 0;
}


// This method is called before first OnUpdate
int32 BSRespin::OnStart(void)
{
	GTBehaviour::OnStart();
	int32 res = 0;

	GTString errorCode("");

	// Look for the game object with the name 'lock'
	GTGameObject* pLockChild = m_pGameObject->FindChild(PROPERTY_TAG_LOCK, true);
	if(NULL == pLockChild)
	{
		GTLogManager::SLogError(CTEXT("Failed to find lock game object !"));
	}
	// Get BSSprite instance from current game object
	m_pLockAnimation = (BSSprite*)(pLockChild->GetBehaviour(CTEXT("BSSprite")));
	if(NULL == m_pLockAnimation)
	{
		GTLogManager::SLogError(CTEXT("Failed to find BSSprite for lock game object !"));	
	}

	// Look for the game object with the name 'lock_highlight'
	GTGameObject* pLockHighlightChild = m_pGameObject->FindChild(PROPERTY_TAG_LOCK_HIGHLIGHT, true);
	if(NULL == pLockHighlightChild)
	{
		GTLogManager::SLogError(CTEXT("Failed to find lock_highlight game object !"));
	}
	m_pLockHighlightAnim = (BSSprite*)(pLockHighlightChild->GetBehaviour(CTEXT("BSSprite")));
	if(NULL == m_pLockHighlightAnim)
	{
		GTLogManager::SLogError(CTEXT("Failed to find BSSprite for lock_highlight game object !"));
	}

	res = 1;	

	return res;
}


// This method is called when GTBehaviour object is updated.
int32 BSRespin::OnUpdate(void)
{
	GTBehaviour::OnUpdate();
	 
	 
	return 1;
}


// This method is called when GTBehaviour object is destroyed.
int32 BSRespin::OnDestroy(void)
{
	GTBehaviour::OnDestroy();
	
	return 1;
}


// Create the sprite from the property tree node
bool BSRespin::CreateFromPropertyTreeNode(GTTreeNode *pTreeNode)
{
	if(NULL == pTreeNode)
	{
		return false;
	}

	bool res = false;
	/*
	//get lock animation
	GTTreeNode* pLockAnimNode = pTreeNode->GetChild(PROPERTY_TAG_LOCK);
	if(pLockAnimNode != NULL)
	{
		GTString filename = pLockAnimNode->GetValue();
		GTGameObject* pLockAnimObj = GameObjectManager::Instance()->CreateGameObject(NULL, "LockAnimObj", filename);
		if(NULL != pLockAnimObj)
		{
			m_pLockAnimation = (BSSprite*) (pLockAnimObj->GetBehaviour("BSSprite"));
			res = true;
		}		
	}
	*/
	return res;
}

// Set position for the game object
void BSRespin::SetGameObjectPosition(const GTPoint2& pos)
{
	SetGameObjectPosition(pos.x, pos.y);
}
void BSRespin::SetGameObjectPosition(const float x, const float y)
{
	m_pGameObject->SetPosition(x, y);

	if(m_pLockAnimation != NULL)
	{
		GTPoint2 src = m_pLockAnimation->GetGameObjectPosition();
		m_pLockAnimation->SetGameObjectPosition(src.x+x, src.y+y);
	}

	if(m_pLockHighlightAnim != NULL)
	{

		GTPoint2 src = m_pLockHighlightAnim->GetGameObjectPosition();
		m_pLockHighlightAnim->SetGameObjectPosition(src.x+x, src.y+y);
	}
}

void BSRespin::PlayLockAnimation()
{
	m_status = Status_Locking;
	m_pLockAnimation->m_pSprite->SetVisible(true);
	m_pLockAnimation->m_pSprite->PlayAnimationByName(
		"lock",
		GSpriteAnimation::PlayMode_Once,
		GTObject_EventCallback_Set(BSRespin::OnFinishPlayLockAnim),
		this,
		NULL
		);
	//GTLogManager::SLogFormatTrace(" BSRespin :  playing lock animation");
}

void BSRespin::OnFinishPlayLockAnim(void *pParam)
{
	m_status = Status_FinishLock;
	//GTLogManager::SLogComment("OnFinishPlayLockAnim ");

	PlayLockHighlightAnimation();
}

void BSRespin::PlayUnLockAnimation()
{
	m_status = Status_Unlocking;
	m_pLockAnimation->m_pSprite->SetVisible(true);
	m_pLockAnimation->m_pSprite->PlayAnimationByName(
		"unlock",
		GSpriteAnimation::PlayMode_Once,
		GTObject_EventCallback_Set(BSRespin::OnFinishPlayUnLockAnim),
		this,
		NULL
		);
	//GTLogManager::SLogFormatTrace(" BSRespin :  playing unlock animation   m_status = Status_Unlocking");

	if(m_pLockHighlightAnim != NULL)
	{
		m_pLockHighlightAnim->m_pSprite->SetVisible(false);
		m_pLockHighlightAnim->m_pSprite->StopAnimation();
		GTLogManager::SLogFormatTrace(" BSRespin :  stop lock highlight animation");
	}
}
void BSRespin::OnFinishPlayUnLockAnim(void *pParam)
{
	m_status = Status_None;
	//GTLogManager::SLogComment("OnFinishPlayUnLockAnim m_status = Status_None ");
}

void BSRespin::PlayLockHighlightAnimation()
{
	if(m_pLockHighlightAnim == NULL)
		return;
	
	m_pLockAnimation->m_pSprite->SetVisible(false);
	m_pLockHighlightAnim->m_pSprite->SetVisible(true);
	m_pLockHighlightAnim->m_pSprite->PlayAnimationByName(
		"lock_highlight",
		GSpriteAnimation::PlayMode_Loop,
		GTObject_EventCallback_Set(BSRespin::OnFinishPlayLockHighlightAnim),
		this,
		NULL
		);
	//GTLogManager::SLogFormatTrace(" BSRespin :  playing lock highlight animation");
	m_status = Status_Lock_Highligh;
}

void BSRespin::OnFinishPlayLockHighlightAnim(void *pParam)
{
	GTLogManager::SLogComment("OnFinishPlayLockHighlightAnim ");
}