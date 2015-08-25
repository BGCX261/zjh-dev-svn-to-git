#include "BSWeaponTimerBomb.h"
#include <GameObjectSprite.h>
#include <TimeManager.h>

GTBEHAVIOUR_IMP(BSWeaponTimerBomb, BSWeapon);

BSWeaponTimerBomb::BSWeaponTimerBomb() : BSWeapon()	
{
}


BSWeaponTimerBomb::~BSWeaponTimerBomb()
{
}


// This method is called when GTBehaviour object is created.
int32 BSWeaponTimerBomb::OnCreate(void)
{
	BSWeapon::OnCreate();

	return 1;
}


// This method is called when GTBehaviour object is initialized.
int32 BSWeaponTimerBomb::OnInitialize(GTBehaviourInit* param)
{
	if(NULL == param || NULL == param->pParam2)
		return 0;

	BSWeapon::OnInitialize(param);

	/*
	GTTreeNode *pTreeNode = (GTTreeNode*)param->pParam2;

	GTTreeNode *pTnMoveLeftLimit = pTreeNode->GetChild(CTEXT("MoveLeftLimit"));
	SetPropertyMoveLeftLimit(pTnMoveLeftLimit ? pTnMoveLeftLimit->ValueToInt() : 0);

	GTTreeNode *pTnMoveRightLimit = pTreeNode->GetChild(CTEXT("MoveRightLimit"));
	SetPropertyMoveRightLimit(pTnMoveRightLimit ? pTnMoveRightLimit->ValueToInt() : 0);

	// 0 - right, 1 - left
	GTTreeNode *pTnDefaultDirection = pTreeNode->GetChild(CTEXT("DefaultDirection"));
	SetPropertyDefaultDirection(pTnDefaultDirection ? pTnDefaultDirection->ValueToInt() : 0);
	*/
		
	return 1;
}


// This method is called before first OnUpdate
int32 BSWeaponTimerBomb::OnStart(void)
{
	BSWeapon::OnStart();

	if(m_pWeaponGameObject)
	{
		// Get child explosion sprite game object
		m_pSpriteExplosion = GetGameObject()->FindChild<GameObjectSprite>(CTEXT("explosion"));
		if(NULL == m_pSpriteExplosion)
			GTLogManager::Inst()->LogError(CTEXT("BSWeaponTimerBomb::OnStart: Failed to find explosion sprite game object !"));
		else
		{
			ResetExplosion();			
			m_pSpriteExplosion->SetVisible(false, true);			
			//m_pWeaponParentGameObject->PlayAnimationByIndex(0, GSpriteAnimation::PlayMode_Loop);
		}
	}

	/*
	const int16 nDirection = GetPropertyDefaultDirection();
	if(nDirection == 0)
		m_pGameObjectSprite->PlayAnimationByName(BSCharacter::AnimationName_MoveRight, GSpriteAnimation::PlayMode_Loop);
	else if(nDirection == 1)
		m_pGameObjectSprite->PlayAnimationByName(BSCharacter::AnimationName_MoveLeft, GSpriteAnimation::PlayMode_Loop);
	else
		m_pGameObjectSprite->PlayAnimationByIndex(0, GSpriteAnimation::PlayMode_Loop);
		*/
	
	return 1;
}


// This method is called when GTBehaviour object is updated.
int32 BSWeaponTimerBomb::OnUpdate(void)
{
	BSWeapon::OnUpdate();
		
	if( false == m_bExplode && (TimeManager::Inst()->GetTime() - m_lTimeElapsed) >= 3000)
	{
		m_bExplode = true;
		// Invisble weapon sprite
		if(m_pWeaponGameObject)
		{
			m_pWeaponGameObject->SetVisible(false, false);
		}
		// Explode
		if(m_pSpriteExplosion)
		{
			m_pSpriteExplosion->SetVisible(true, true);
			m_pSpriteExplosion->PlayAnimationByIndex(
				0,
				GSpriteAnimation::PlayMode_Once,
				GTObject_EventCallback_Set(BSWeaponTimerBomb::OnExplosionAnimationComplete),
				this,
				NULL
				);
		}
	}

	/*
	// Move the character
	GTVector2 pos = GetGameObjectPosition();
	pos.x += m_nMoveDirection * (((float)m_lDeltaTime / 1000.0f) * (float)m_nMovementSpeed);	
	// Change movement direction if the NPC hits left/right limit
	if(pos.x <= m_nMoveLeftLimit)
	{
		pos.x = m_nMoveLeftLimit;
		m_nMoveDirection = 1;
		m_pGameObjectSprite->PlayAnimationByName(BSCharacter::AnimationName_MoveRight, GSpriteAnimation::PlayMode_Loop);
	}
	else if(pos.x >= m_nMoveRightLimit)
	{
		pos.x = m_nMoveRightLimit;
		m_nMoveDirection = -1;
		m_pGameObjectSprite->PlayAnimationByName(BSCharacter::AnimationName_MoveLeft, GSpriteAnimation::PlayMode_Loop);
	}
	// Apply new position
	SetGameObjectPosition(pos);

	// Call this for post update
	BSCharacter::OnUpdatePost();
	*/

	return 1;
}


// This method is called when GTBehaviour object is destroyed.
int32 BSWeaponTimerBomb::OnDestroy(void)
{
	BSWeapon::OnDestroy();

	return 1;
}


// OnVisible is called when the the object is set visible.
void BSWeaponTimerBomb::OnVisible(GTGameObject *pCaller, bool bApplyForChildren)
{
}


void BSWeaponTimerBomb::OnExplosionAnimationComplete(void *pParam)
{
	if(m_pSpriteExplosion)
	{
		m_pSpriteExplosion->StopAnimation();
		m_pSpriteExplosion->SetVisible(false, true);
	}
	// Disable this weapon in order to let weapon cache manager know
	// this game object can be reused
	m_pWeaponGameObject->SetEnable(false);
}


void BSWeaponTimerBomb::ResetExplosion(void)
{
	m_bExplode = false;
	m_lTimeElapsed = TimeManager::Inst()->GetTime();
}
