#include "BSCharacter.h"
#include "GameObjectCreation.h"
#include "GameGeneral.h"
#include <TimeManager.h>
#include <SceneManager.h>
#include <GTPropertyFile.h>

const tchar* BSCharacter::AnimationName_Idle = CTEXT("Idle");
const tchar* BSCharacter::AnimationName_MoveDown = CTEXT("MoveDown");
const tchar* BSCharacter::AnimationName_MoveLeft = CTEXT("MoveLeft");
const tchar* BSCharacter::AnimationName_MoveRight = CTEXT("MoveRight");
const tchar* BSCharacter::AnimationName_MoveUp = CTEXT("MoveUp");
const tchar* BSCharacter::AnimationName_AttackDownLeft = CTEXT("AttackDownLeft");
const tchar* BSCharacter::AnimationName_AttackDownRight = CTEXT("AttackDownRight");
const tchar* BSCharacter::AnimationName_AttackUpLeft = CTEXT("AttackUpLeft");
const tchar* BSCharacter::AnimationName_AttackUpRight = CTEXT("AttackUpRight");

static const tchar* g_AttackAnimationName[4] =
{
	BSCharacter::AnimationName_AttackUpLeft,
	BSCharacter::AnimationName_AttackUpRight,
	BSCharacter::AnimationName_AttackDownLeft,
	BSCharacter::AnimationName_AttackDownRight
};

GTBEHAVIOUR_IMP(BSCharacter, GTBehaviour);

BSCharacter::BSCharacter() : m_pGameObjectSprite(NULL)
{
}


BSCharacter::~BSCharacter()
{
}


// This method is called when GTBehaviour object is created.
int32 BSCharacter::OnCreate(void)
{
	GTBehaviour::OnCreate();

	return 1;
}


// This method is called when GTBehaviour object is initialized.
int32 BSCharacter::OnInitialize(GTBehaviourInit* param)
{
	GTBehaviour::OnInitialize(param);
		
	if(NULL == param || NULL == param->pParam2)
		return 0;

	return CreateFromPropertyTreeNode((GTTreeNode*)param->pParam2) ? 1 : 0;
}


// If this GTBehaviour needs to be rebuilt
void BSCharacter::OnDirty(void)
{
}


// OnVisible is called when the the object is set visible.
void BSCharacter::OnVisible(void)
{
	/*
	// The game object is visible
	if(m_pGameObjectSprite)
	{
		// Setup visibility
		m_pGameObjectSprite->SetVisible(true);
	}
	*/
}


// OnVisible is called when the the object is set invisible.
void BSCharacter::OnInvisible(void)
{
	/*
	// The game object is invisible
	if(m_pGameObjectSprite)
	{
		// Setup visibility
		m_pGameObjectSprite->SetVisible(false);
	}
	*/
}


// OnChangeZOrder is called when the the object is set with new z-order.
void BSCharacter::OnChangeZOrder(const int32 nNewZOrder)
{
	/*
	if(m_pGameObjectSprite)
	{
		//const int32 nOldZOrder = m_pSprite->GetZOrder();
		m_pGameObjectSprite->SetZOrder(nNewZOrder);
	}
	*/
}


// Copy
bool BSCharacter::Copy(GTObject* pObjectFrom)
{
	GTBehaviour::Copy(pObjectFrom);
	
	return true;
}


// OnStart is called just before any of the OnUpdate methods is called the first time.
int32 BSCharacter::OnStart(void)
{
	GTBehaviour::OnStart();

	m_pGameObjectSprite = GetGameObject<GameObjectSprite>();

	if(m_pGameObjectSprite)
	{
		// Initially, visible is same as game object's
		m_pGameObjectSprite->SetVisible(m_pGameObject->GetVisible(), true);
		// Initially, position is same as game object's
		m_pGameObjectSprite->SetPosition(m_pGameObject->m_Position);
	}

	// Save current time
	m_lPrevTime = TimeManager::Inst()->GetTime();
	m_lDeltaTime = 0;

	return 1;
}


// This method is called when GTBehaviour object is updated.
int32 BSCharacter::OnUpdate(void)
{
	GTBehaviour::OnUpdate();

	if(m_pGameObjectSprite)
	{
		m_pGameObjectSprite->SetPosition(m_pGameObject->m_Position);
	}

	switch(GetPropertyStatus())
	{
		case BSCharacter::StatusIdle:
			OnUpdateStatusIdle();
			break;

		case BSCharacter::StatusMoving:
			OnUpdateStatusMoving();
			break;

		case BSCharacter::StatusAttack:
			OnUpdateStatusAttack();
			break;

		case BSCharacter::StatusDying:
			OnUpdateStatusDying();
			break;

		case BSCharacter::StatusDied:
			OnUpdateStatusDied();
			break;
	}

	// Calculate delta time
	m_lDeltaTime = TimeManager::Inst()->GetTime() - m_lPrevTime;

	return 1;
}


void BSCharacter::OnUpdatePost(void)
{
	// Save current time
	m_lPrevTime = TimeManager::Inst()->GetTime();
}


// This method is called when GTBehaviour object is destroyed.
int32 BSCharacter::OnDestroy(void)
{
	GTBehaviour::OnDestroy();
		
	return 1;
}


// Create the sprite from the property tree node
bool BSCharacter::CreateFromPropertyTreeNode(GTTreeNode *pTreeNode)
{
	if(NULL == pTreeNode)
		return false;

	GTTreeNode *pTnLife = pTreeNode->GetChild(CTEXT("Life"));
	SetPropertyLife(pTnLife ? pTnLife->ValueToInt() : 0);

	GTTreeNode *pTnLifeMax = pTreeNode->GetChild(CTEXT("LifeMax"));
	SetPropertyLifeMax(pTnLifeMax ? pTnLifeMax->ValueToInt() : 0);

	GTTreeNode *pTnAttack = pTreeNode->GetChild(CTEXT("Attack"));
	SetPropertyAttack(pTnAttack ? pTnAttack->ValueToInt() : 0);

	GTTreeNode *pTnAttackSpeed = pTreeNode->GetChild(CTEXT("AttackSpeed"));
	SetPropertyAttackSpeed(pTnAttackSpeed ? pTnAttackSpeed->ValueToInt() : 0);

	GTTreeNode *pTnArmor = pTreeNode->GetChild(CTEXT("Armor"));
	SetPropertyArmor(pTnArmor ? pTnArmor->ValueToInt() : 0);

	GTTreeNode *pTnAttackRange = pTreeNode->GetChild(CTEXT("AttackRange"));
	SetPropertyAttackRange(pTnAttackRange ? pTnAttackRange->ValueToInt() : 0);

	GTTreeNode *pTnMovementSpeed = pTreeNode->GetChild(CTEXT("MovementSpeed"));
	SetPropertyMovementSpeed(pTnMovementSpeed ? pTnMovementSpeed->ValueToInt() : 0);

	GTTreeNode *pTnExperience = pTreeNode->GetChild(CTEXT("Experience"));
	SetPropertyExperience(pTnExperience ? pTnExperience->ValueToInt() : 0);

	GTTreeNode *pTnMoney = pTreeNode->GetChild(CTEXT("Money"));
	SetPropertyMoney(pTnMoney ? pTnMoney->ValueToInt() : 0);

	GTTreeNode *pTnLevel = pTreeNode->GetChild(CTEXT("Level"));
	SetPropertyLevel(pTnLevel ? pTnLevel->ValueToInt() : 0);

	GTTreeNode *pTnSkillPoint = pTreeNode->GetChild(CTEXT("SkillPoint"));
	SetPropertySkillPoint(pTnSkillPoint ? pTnSkillPoint->ValueToInt() : 0);

	GTTreeNode *pTnSkillPointMax = pTreeNode->GetChild(CTEXT("SkillPointMax"));
	SetPropertySkillPointMax(pTnSkillPointMax ? pTnSkillPointMax->ValueToInt() : 0);

	/*
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
	*/
	
	return true;
}


void BSCharacter::OnUpdateStatusIdle(void)
{
}


void BSCharacter::OnUpdateStatusMoving(void)
{
}


void BSCharacter::OnUpdateStatusAttack(void)
{
}


void BSCharacter::OnUpdateStatusDying(void)
{
}


void BSCharacter::OnUpdateStatusDied(void)
{
}
