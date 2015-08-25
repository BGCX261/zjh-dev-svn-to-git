#include "BSPlayerController.h"
#include "BSClassName.h"
#include "BSSpriteMovement.h"
#include <GTInputManager.h>
#include <SceneManager.h>
#include <GTLog/GTLogManager.h>
#include <ScreenManager.h>
#include <GTGameObjectManager.h>
#include <GTPropertyFile.h>

const tchar* BSPlayerController::m_szMainPlayName = CTEXT("MainPlayer");

GTBEHAVIOUR_IMP(BSPlayerController, GTBehaviour);

// Once single-click event occurs, this callback is called.
int32 BSPlayerController::OnSingleClickEventDelegate(
	const uint32 Flags,
	const GTPoint2 point,
	void* pParam)
{
	if(NULL == pParam)
	{
		return 0;
	}

	const GTPoint2 screenPosition = SceneManager::GetInstance()->GetScreenPositionInMap();
	BSPlayerController* pPC = (BSPlayerController*)pParam;
	pPC->m_pPathFinding->DoPathFinding(GTPoint2(screenPosition.x + point.x, screenPosition.y + point.y));
	if(pPC->m_pPathFinding->GetPathFindingResultLength() > 1)
	{
		// Only do path finding if there are more than 2 nodes in the result
		pPC->m_pSpriteMovement->StartMovement();
	}

	return 1;
}


BSPlayerController::BSPlayerController():
	m_pGameObjectSprite(NULL),
	m_pPathFinding(NULL)
{
}


BSPlayerController::~BSPlayerController()
{
}


// This method is called when GTBehaviour object is created.
int32 BSPlayerController::OnCreate(void)
{
	GTBehaviour::OnCreate();

	return 1;
}


// This method is called when GTBehaviour object is initialized.
int32 BSPlayerController::OnInitialize(GTBehaviourInit* param)
{
	GTBehaviour::OnInitialize(param);
	DBG_ASSERT(m_pGameObject);
			
	// Register single-click event
	if(!GTInputManager::GetInstance()->RegisterEvent(
		GTInputManager::EventType_SingleClick,
		GetClassName(),
		BSPlayerController::OnSingleClickEventDelegate,
		this
		))
	{
		GTLogManager::GetInstance()->LogFormatError(
			CTEXT("Failed to call RegisterSingleClickEvent for %s"),
			CTEXT("BSPlayerController")
			);
		return 1;
	}

	if(param->pParam2)
	{
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
				else if(pv.m_sName == CTEXT("ExperienceForNextLevel"))
					SetPropertyExperienceForNextLevel(pv.m_sValue.ToInt());
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
	}

	return 1;
}


// This method is called before first OnUpdate
int32 BSPlayerController::OnStart(void)
{
	GTBehaviour::OnStart();

	// Cache sprite object
	m_pGameObjectSprite = GetGameObject<GameObjectSprite>();
	if(m_pGameObjectSprite)
	{		
		//m_pGameObjectSprite->PlayAnimationByName(CTEXT("RunUp"));
		//m_pGameObjectSprite->PlayAnimationByName(CTEXT("RunDown"));
		//m_pGameObjectSprite->PlayAnimationByName(CTEXT("RunLeft"));		
		m_pGameObjectSprite->PlayAnimationByName(CTEXT("RunRight"), GSpriteAnimation::PlayMode_Once);
		m_pGameObjectSprite->StopAnimation();
		//m_pGameObjectSprite->SetDisplayFrameByName(CTEXT("RunRight"), 0);
	}
	// Cache BS objects
	m_pPathFinding = m_pGameObject->GetBehaviour<BSPathFinding>();
	m_pSpriteMovement = m_pGameObject->GetBehaviour<BSSpriteMovement>();
	// Cache BS objects
	m_pBSPlayerPlayingUI = (BSPlayerPlayingUI*)BSCLASSNAME_GET_COMPONENT(BSClassName::BSPlayerPlayingUI);

	GTGameObject* pStartObject = GTGameObjectManager::Inst()->GetRootGameObject()->FindChild(CTEXT("StartPosition"));
	GTGameObject* pEndObject = GTGameObjectManager::Inst()->GetRootGameObject()->FindChild(CTEXT("EndPosition"));
	if(pStartObject)
	{
		// Setup initial position
		m_pGameObject->SetPosition(pStartObject->GetPosition());
	}

	return 1;
}


// This method is called when GTBehaviour object is updated.
int32 BSPlayerController::OnUpdate(void)
{
	GTBehaviour::OnUpdate();

	// The screen position follows the play position
	const GTPoint2 screenPosition = SceneManager::GetInstance()->GetScreenPositionInMap();
	SceneManager::GetInstance()->SetScreenPositionInMap(
		m_pGameObject->m_Position.x - ScreenManager::GetInstance()->GetScreenHalfWidth(),
		m_pGameObject->m_Position.y - ScreenManager::GetInstance()->GetScreenHalfHeight()
		);

	return 1;
}


// This method is called when GTBehaviour object is destroyed.
int32 BSPlayerController::OnDestroy(void)
{
	GTBehaviour::OnDestroy();

	// Unregister the event of single click
	GTInputManager::GetInstance()->UnregisterEvent(
		GTInputManager::EventType_SingleClick,
		GetClassName()
		);

	m_pGameObjectSprite = NULL;
	m_pPathFinding = NULL;

	return 1;
}


void BSPlayerController::OnCollisionEnter(GTGameObject* pGameObject)
{
	if(NULL == pGameObject)
	{
		return;
	}

	GTBehaviour* pBehaviour = GetGTBehaviourFromGameObject(pGameObject);
	if(NULL == pBehaviour)
	{
		return;
	}

	const tchar* szClassName = pBehaviour->GetClassName();
	if(GTString::StartsWith(szClassName, CTEXT("BSUnit")))
	{
		OnCollisionBSUnitBehaviour((BSUnitBehaviour*)pBehaviour);
	}
	else if(GTString::IsEqual(szClassName, CTEXT(BSClassName::BSEndPosition)))
	{
		OnCollisionBSEndPosition((BSEndPosition*)pBehaviour);
	}
}


void BSPlayerController::OnCollisionExit(GTGameObject* pGameObject)
{
}


void BSPlayerController::OnCollisionStay(GTGameObject* pGameObject)
{
}


// On HP change
void BSPlayerController::OnChangeHP(const int16 nDamage)
{
	if(m_pBSPlayerPlayingUI)
	{
		BSPlayerPlayingUIContainer* pContainerHP = m_pBSPlayerPlayingUI->GetContainerHP();
		//BSPlayerPlayingUIContainer* pContainerSP = m_pBSPlayerPlayingUI->GetContainerSP();
		//BSPlayerPlayingUIContainer* pContainerMoney = m_pBSPlayerPlayingUI->GetContainerMoney();
		if(pContainerHP)
		{
			if(pContainerHP->pUILabel)
			{
				int16 nNewTargetValue = pContainerHP->pUILabel->GetPropertyTargetValue() + nDamage;
				if(nNewTargetValue < 0)
				{
					nNewTargetValue = 0;
				}
				// Update UI
				pContainerHP->pUILabel->SetPropertyTargetValue(nNewTargetValue);
				//pContainerSP->pUILabel->SetPropertyTargetValue(nNewTargetValue);
				//pContainerMoney->pUILabel->SetPropertyTargetValue(nNewTargetValue);
				// Change life
				SetPropertyLife(nNewTargetValue);
			}
			// Update the progress bar
			if(pContainerHP->pUIProgressBar)
			{
				pContainerHP->pUIProgressBar->SetCurrentValue(GetPropertyLife());
				//pContainerSP->pUIProgressBar->SetCurrentValue(GetPropertyLife());
			}
		}
	}
}


// Get required GTBehaviour from pGameObject
GTBehaviour* BSPlayerController::GetGTBehaviourFromGameObject(GTGameObject* pGameObject)
{
	if(NULL == pGameObject)
	{
		return NULL;
	}

	// Check if pGameObject contains one of following behaviours

	// BSUnitBehaviour
	GTBehaviour* pBehaviour = pGameObject->GetBehaviourBySuperClassName(BSClassName::BSUnitBehaviour);
	if(pBehaviour)
	{
		return pBehaviour;
	}
	// BSEndPosition
	pBehaviour = pGameObject->GetBehaviour(BSClassName::BSEndPosition);
	if(pBehaviour)
	{
		return pBehaviour;
	}

	return NULL;
}


void BSPlayerController::OnCollisionBSUnitBehaviour(BSUnitBehaviour* pBehaviour)
{
	if(NULL == pBehaviour)
	{
		return;
	}

	//GTLogManager::GetInstance()->LogFormatComment("Player life decreased - %d", pBSUnitBehaviour->GetPropertyAttack());
	// On damage
	OnChangeHP(-pBehaviour->GetPropertyAttack());
	// Reset the weapon
	pBehaviour->OnResetWeapon();
}


void BSPlayerController::OnCollisionBSEndPosition(BSEndPosition* pBehaviour)
{
	if(NULL == pBehaviour)
	{
		return;
	}

	GTLogManager::GetInstance()->LogFormatComment(CTEXT("EndPosition reached: %s"), pBehaviour->GetGameObject()->GetName());
}
