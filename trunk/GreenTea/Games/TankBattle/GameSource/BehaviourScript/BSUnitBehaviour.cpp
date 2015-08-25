#include <GTGreenTea.h>
#include "BSUnitBehaviour.h"
#include <GTPropertyFile.h>
#include <GTTreeNode.h>
#include "BSPlayerController.h"
#include "BSClassName.h"
#include "GameDef.h"
#include <GTTweenInterpolation.h>

const tchar* BSUnitBehaviour::AnimationName_Idle = CTEXT("Idle");
const tchar* BSUnitBehaviour::AnimationName_RunDown = CTEXT("RunDown");
const tchar* BSUnitBehaviour::AnimationName_RunLeft = CTEXT("RunLeft");
const tchar* BSUnitBehaviour::AnimationName_RunRight = CTEXT("RunRight");
const tchar* BSUnitBehaviour::AnimationName_RunUp = CTEXT("RunUp");
const tchar* BSUnitBehaviour::AnimationName_AttackDownLeft = CTEXT("AttackDownLeft");
const tchar* BSUnitBehaviour::AnimationName_AttackDownRight = CTEXT("AttackDownRight");
const tchar* BSUnitBehaviour::AnimationName_AttackUpLeft = CTEXT("AttackUpLeft");
const tchar* BSUnitBehaviour::AnimationName_AttackUpRight = CTEXT("AttackUpRight");

static const tchar* g_AttackAnimationName[4] =
{
	BSUnitBehaviour::AnimationName_AttackUpLeft,
	BSUnitBehaviour::AnimationName_AttackUpRight,
	BSUnitBehaviour::AnimationName_AttackDownLeft,
	BSUnitBehaviour::AnimationName_AttackDownRight
};

GTBEHAVIOUR_IMP(BSUnitBehaviour, GTBehaviour);

BSUnitBehaviour::BSUnitBehaviour():
	m_pWeaponObject(NULL),
	m_pBSGameObjectGeneralWeapon(NULL),
	m_pBSTweener2DWeapon(NULL),
	m_pBSGameObjectGeneral(NULL),
	m_pGameObjectSprite(NULL)
{
}


BSUnitBehaviour::~BSUnitBehaviour()
{
}


// This method is called when GTBehaviour object is created.
int32 BSUnitBehaviour::OnCreate(void)
{
	GTBehaviour::OnCreate();

	return 1;
}


// This method is called when GTBehaviour object is initialized.
int32 BSUnitBehaviour::OnInitialize(GTBehaviourInit* param)
{
	GTBehaviour::OnInitialize(param);

	if(NULL == param || NULL == param->pParam2)
	{
		return 1;
	}

	// Cache behaviour objects
	m_pGameObjectSprite = GetGameObject<GameObjectSprite>();
	m_pBSGameObjectGeneral = (BSGameObjectGeneral*)BSCLASSNAME_GET_COMPONENT(BSClassName::BSGameObjectGeneral);

	GTTreeNode* pParam = (GTTreeNode*)(param->pParam2);
	const int32 nChildCount = pParam->GetChildCount();
	for(int32 i=0; i<nChildCount; i++)
	{
		GTTreeNode* pChildNode = pParam->GetChild(i);
		// Handle PairValue section
		if(pChildNode->GetTag() == GTPropertyFile::TagPairValue)
		{
			GTPairValue pv = pChildNode->ValueToPairValue();
			if(pv.m_sName == CTEXT("Life"))
				SetPropertyLife(pv.m_sValue.ToInt());
			else if(pv.m_sName == CTEXT("LifeMax"))
				SetPropertyLifeMax(pv.m_sValue.ToInt());
			else if(pv.m_sName == CTEXT("Attack"))
				SetPropertyAttack(pv.m_sValue.ToInt());
			else if(pv.m_sName == CTEXT("AttackSpeed"))
				SetPropertyAttackSpeed(pv.m_sValue.ToInt());
			else if(pv.m_sName == CTEXT("Armor"))
				SetPropertyArmor(pv.m_sValue.ToInt());
			else if(pv.m_sName == CTEXT("AttackRange"))
				SetPropertyAttackRange(pv.m_sValue.AsFloat() * MapManager::GetInstance()->GetMapTileSizeInPixel().width);
			else if(pv.m_sName == CTEXT("MovementSpeed"))
				SetPropertyMovementSpeed(pv.m_sValue.ToInt());
			else if(pv.m_sName == CTEXT("Experience"))
				SetPropertyExperience(pv.m_sValue.ToInt());
			else if(pv.m_sName == CTEXT("Money"))
				SetPropertyMoney(pv.m_sValue.ToInt());
			else if(pv.m_sName == CTEXT("Level"))
				SetPropertyLevel(pv.m_sValue.ToInt());
			else if(pv.m_sName == CTEXT("SkillPoint"))
				SetPropertySkillPoint(pv.m_sValue.ToInt());
			else if(pv.m_sName == CTEXT("SkillPointMax"))
				SetPropertySkillPointMax(pv.m_sValue.ToInt());
		}
	}

	return 1;
}


// This method is called before first OnUpdate
int32 BSUnitBehaviour::OnStart(void)
{
	GTBehaviour::OnStart();

	// Get main play object
	m_pMainPlayer = GTGameObjectManager::GetInstance()->FindGameObjectByName(BSPlayerController::m_szMainPlayName);
	if(m_pMainPlayer)
	{
		m_pBSGameObjectGeneralPlayer = (BSGameObjectGeneral*)(m_pMainPlayer->GetComponent(BSClassName::BSGameObjectGeneral));
	}
	else
	{
		GTLogManager::GetInstance()->LogError(CTEXT("BSUnitBehaviour: Failed to find main player game object"));
	}
	// Get weapon game object
	m_pWeaponObject = GetGameObject()->FindChild(CTEXT("Weapon"));
	if(m_pWeaponObject)
	{
		m_pWeaponObject->SetPosition(GetGameObject()->GetPosition());
		m_pBSGameObjectGeneralWeapon = (BSGameObjectGeneral*)(m_pWeaponObject->GetComponent(BSClassName::BSGameObjectGeneral));
		m_pBSTweener2DWeapon = (BSTweener2D*)(m_pWeaponObject->GetComponent(BSClassName::BSTweener2D));
	}

	// Play default animation
	SetPropertyState(BSUnitBehaviour::State_Idle);
	PlayAnimationByName(BSUnitBehaviour::AnimationName_Idle, GSpriteAnimation::PlayMode_Loop);

	return 1;
}


// This method is called when GTBehaviour object is updated.
int32 BSUnitBehaviour::OnUpdate(void)
{
	GTBehaviour::OnUpdate();

	if(NULL == m_pMainPlayer)
	{
		return 1;
	}

	float d = (m_pGameObject->GetPosition() - m_pMainPlayer->GetPosition()).Length();
	if(d <= GetPropertyAttackRange())
	{
		// The target is in the attack range
		OnStateAttack();
	}
	else
	{
		// The target is out of the attack range
		OnStateIdle();
	}

	return 1;
}


// This method is called when GTBehaviour object is destroyed.
int32 BSUnitBehaviour::OnDestroy(void)
{
	GTBehaviour::OnDestroy();

	return 1;
}


// When the animation played is completed, this method is called.
void BSUnitBehaviour::OnAnimationPlayingCompletion(void* pParam)
{
}


// Get correct attack animation according to the player's position
int32 BSUnitBehaviour::GetAttackAnimationIndexFromPlayerPosition(void)
{
	if(NULL == m_pMainPlayer)
	{
		return -1;
	}

	const GTVector2 posPlayer = m_pMainPlayer->GetPosition();
	const GTVector2 posUnit = m_pGameObject->GetPosition();

	if(posPlayer.x <= posUnit.x && posPlayer.y >= posUnit.y)
		return 0;
	else if(posPlayer.x > posUnit.x && posPlayer.y >= posUnit.y)
		return 1;
	else if(posPlayer.x <= posUnit.x && posPlayer.y < posUnit.y)
		return 2;
	else if(posPlayer.x > posUnit.x && posPlayer.y < posUnit.y)
		return 3;

	return -1;
}


void BSUnitBehaviour::OnStateIdle(void)
{
	if(GetPropertyState() != BSUnitBehaviour::State_Idle)
	{
		SetPropertyState(BSUnitBehaviour::State_Idle);
		PlayAnimationByName(
			BSUnitBehaviour::AnimationName_Idle,
			GSpriteAnimation::PlayMode_Loop
			);
	}	
}


// Does the weapon hit the player ?
bool BSUnitBehaviour::DoesWeaponHitPlayer(void)
{
	if(NULL == m_pMainPlayer || (!m_pWeaponObject->GetVisible()))
	{
		return false;
	}

	GTGameObjectCollider* pCollisionPlayer = m_pBSGameObjectGeneralPlayer->GetCollider();
	GTGameObjectCollider* pCollisionWeapon = m_pBSGameObjectGeneralWeapon->GetCollider();
	if(pCollisionPlayer && pCollisionWeapon)
	{
		if(pCollisionPlayer->Collide(pCollisionWeapon))
		{
			return true;
		}
	}

	return false;
}


void BSUnitBehaviour::OnStateAttack(void)
{
	if(GetPropertyState() != BSUnitBehaviour::State_Attack)
	{
		// Change to attack state
		int32 nAnimationIndex = GetAttackAnimationIndexFromPlayerPosition();
		SetPropertyState(BSUnitBehaviour::State_Attack);
		if(nAnimationIndex >= 0)
		{
			// Start playing attack animation
			PlayAnimationByName(
				g_AttackAnimationName[nAnimationIndex],
				GSpriteAnimation::PlayMode_Once,
				GTObject_EventCallback_Set(BSUnitBehaviour::OnAnimationPlayingCompletion),
				this,
				NULL
				);
			// Fire weapon
			FireWeapon();
		}
	}
	else
	{
		// Is alrady in attack state ?
		// If yes, if the animation is completed and the weapon is invisible,
		// fir the weapon.
		if(!IsAnimationPlaying() &&
		   !m_pWeaponObject->GetVisible())
		{
			int32 nAnimationIndex = GetAttackAnimationIndexFromPlayerPosition();
			if(nAnimationIndex >= 0)
			{
				// Continue playing attack animation
				PlayAnimationByName(
					g_AttackAnimationName[nAnimationIndex],
					GSpriteAnimation::PlayMode_Once,
					GTObject_EventCallback_Set(BSUnitBehaviour::OnAnimationPlayingCompletion),
					this,
					NULL
					);
				// Fire weapon
				FireWeapon();
			}
		}
	}

	// Check if the weapon hits the player
	if(m_pWeaponObject->GetVisible())
	{
		if(DoesWeaponHitPlayer())
		{
			// The player is hit
			m_pMainPlayer->OnCollision(m_pGameObject);
		}
	}
}


// The weapon fires
void BSUnitBehaviour::FireWeapon(void)
{
	DBG_ASSERT(m_pWeaponObject);
	DBG_ASSERT(m_pGameObject);
	DBG_ASSERT(m_pMainPlayer);

	if(NULL == m_pWeaponObject ||
	   NULL == m_pGameObject ||
	   NULL == m_pMainPlayer)
	{
		return;
	}
	// If the wapon is already fired, ignore this call.
	if(m_pWeaponObject->GetVisible())
	{
		return;
	}

	if(m_pBSTweener2DWeapon)
	{
		m_pWeaponObject->SetVisible(true, true);
		m_pBSTweener2DWeapon->Start(
			m_pGameObject->GetPosition(),
			m_pMainPlayer->GetPosition(),
			1000.0f, // 1 second
			GTTweenInterpolation::Linear,
			0.0f,
			BSUnitBehaviour::OnFireWeaponCompletion,
			this
			);
	}
}


// When fire weapon action is done, this callback is called.
void BSUnitBehaviour::OnFireWeaponCompletion(void *pParam)
{
	if(NULL == pParam)
	{
		return;
	}
	BSUnitBehaviour* pBSUnitBehaviour = (BSUnitBehaviour*)pParam;
	// Set this weapon object to invisible
	if(pBSUnitBehaviour && pBSUnitBehaviour->m_pWeaponObject)
	{
		if(pBSUnitBehaviour->DoesWeaponHitPlayer())
		{
		}
		// Reset the weapon
		pBSUnitBehaviour->OnResetWeapon();
	}
}


// Reset the weapon
void BSUnitBehaviour::OnResetWeapon(void)
{
	DBG_ASSERT(m_pWeaponObject);
	DBG_ASSERT(m_pGameObject);
	DBG_ASSERT(m_pBSTweener2DWeapon);

	if(m_pWeaponObject &&
	   m_pGameObject &&
	   m_pBSTweener2DWeapon)
	{
		m_pWeaponObject->SetVisible(false, true);
		// Reset the position to its parent
		m_pWeaponObject->SetPosition(m_pGameObject->GetPosition());
		// Update the collider object
		m_pBSGameObjectGeneralWeapon->OnUpdateCollider();
		// Stop running tweener
		m_pBSTweener2DWeapon->Stop();
		// Reset the state
		SetPropertyState(BSUnitBehaviour::State_Idle);
	}
}
