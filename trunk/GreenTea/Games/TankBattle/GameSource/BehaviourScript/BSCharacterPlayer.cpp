#include "BSCharacterPlayer.h"
#include <SceneManager.h>
#include <GTInputManager.h>
#include <UI/UIWidget.h>
#include <UI/UIFrame.h>
#include <UI/UIManager.h>
#include "../WeaponCacheManager.h"
#include "BehaviourScript/BSWeaponTimerBomb.h"

GTBEHAVIOUR_IMP(BSCharacterPlayer, BSCharacter);

// Once single-click event occurs, this callback is called.
int32 BSCharacterPlayer::OnSingleClickEventDelegate(const uint32 Flags, const GTPoint2 point, void* pParam)
{
	if(NULL == pParam)
		return 0;

	if(Flags & UIWidget::Flag_ClickDown)
	{
		//const GTPoint2 screenPosition = SceneManager::GetInstance()->GetScreenPositionInMap();
		BSCharacterPlayer* player = static_cast<BSCharacterPlayer*>(pParam);
		if(player)
		{
			player->MoveTo(point);
		}
	}
	
	return 1;
}

BSCharacterPlayer::BSCharacterPlayer() : BSCharacter()	
{
	SetPropertyMoveDirection(1);
	m_vDestination = GTVector2(0.0f, 0.0f);
	m_vMoveDirection = GTVector2(0.0f, 0.0f);
}


BSCharacterPlayer::~BSCharacterPlayer()
{
}


// This method is called when GTBehaviour object is created.
int32 BSCharacterPlayer::OnCreate(void)
{
	BSCharacter::OnCreate();

	return 1;
}


// This method is called when GTBehaviour object is initialized.
int32 BSCharacterPlayer::OnInitialize(GTBehaviourInit* param)
{
	if(NULL == param || NULL == param->pParam2)
		return 0;

	// Register single-click event
	if(!GTInputManager::GetInstance()->RegisterEvent(
		GTInputManager::EventType_SingleClick,
		GetClassName(),
		BSCharacterPlayer::OnSingleClickEventDelegate,
		this
		))
	{
		GTLogManager::GetInstance()->LogFormatError(
			CTEXT("BSCharacterPlayer::OnInitialize: Failed to call RegisterSingleClickEvent for %s"),
			CTEXT("BSCharacterPlayer")
			);
		return 1;
	}

	// Setup callbacks for item layout
	UIFrame *pFrame = UIManager::Inst()->GetRootWidget()->FindChildById<UIFrame>(1200);
	if(pFrame)
	{
		for(int32 wid=1201; wid<=1203; wid++)
		{
			UIWidget *pBtnItem = pFrame->FindChildById(wid);
			if(pBtnItem)
				pBtnItem->AddEventListener(UIWidgetEvent::EventTypeSingleClick, CTEXT("itemLayoutClicked"),
										   this, UIWidget_EventCallback_Set(BSCharacterPlayer::OnBtnItemSingleClick), NULL);
		}
	}
	
	BSCharacter::OnInitialize(param);

	GTTreeNode *pTreeNode = (GTTreeNode*)param->pParam2;

	// MoveLeftLimit
	GTTreeNode *pTnMoveLeftLimit = pTreeNode->GetChild(CTEXT("MoveLeftLimit"));
	SetPropertyMoveLeftLimit(pTnMoveLeftLimit ? pTnMoveLeftLimit->ValueToInt() : 0);
	// MoveRightLimit
	GTTreeNode *pTnMoveRightLimit = pTreeNode->GetChild(CTEXT("MoveRightLimit"));
	SetPropertyMoveRightLimit(pTnMoveRightLimit ? pTnMoveRightLimit->ValueToInt() : 0);
	// DefaultDirection: 0 - right, 1 - left
	GTTreeNode *pTnDefaultDirection = pTreeNode->GetChild(CTEXT("DefaultDirection"));
	SetPropertyDefaultDirection(pTnDefaultDirection ? pTnDefaultDirection->ValueToInt() : 0);

	// FloatingEnable
	GTTreeNode *pTnFloatingEnable = pTreeNode->GetChild(CTEXT("FloatingEnable"));
	SetPropertyFloatingEnable(pTnFloatingEnable ? pTnFloatingEnable->ValueToBool() : false);
	// FloatingSpeed
	GTTreeNode *pTnFloatingSpeed = pTreeNode->GetChild(CTEXT("FloatingSpeed"));
	m_fFloatingSpeed = pTnFloatingSpeed ? pTnFloatingSpeed->ValueToFloat() : 0.0f;
	// FloatingMax
	GTTreeNode *pTnFloatingMax = pTreeNode->GetChild(CTEXT("FloatingMax"));
	m_fFloatingMax = pTnFloatingMax ? pTnFloatingMax->ValueToFloat() : 0.0f;
		
	return 1;
}


// This method is called before first OnUpdate
int32 BSCharacterPlayer::OnStart(void)
{
	BSCharacter::OnStart();

	// Setup initial status
	SetPropertyStatus(BSCharacter::StatusIdle);

	// Setup initial direction
	const int16 nDirection = GetPropertyDefaultDirection();
	if(nDirection == 0)
		m_pGameObjectSprite->PlayAnimationByName(BSCharacter::AnimationName_MoveRight, GSpriteAnimation::PlayMode_Loop);
	else if(nDirection == 1)
		m_pGameObjectSprite->PlayAnimationByName(BSCharacter::AnimationName_MoveLeft, GSpriteAnimation::PlayMode_Loop);
	else
		m_pGameObjectSprite->PlayAnimationByIndex(0, GSpriteAnimation::PlayMode_Loop);
	
	// Initialize floating
	if(GetPropertyFloatingEnable())
	{
		m_vFloatingOldPos = GetGameObjectPosition();
		m_fFloatingYHigh = m_vFloatingOldPos.y + m_fFloatingMax;
		m_fFloatingYLow = m_vFloatingOldPos.y - m_fFloatingMax;
		m_nFloatingDirection = -1;
	}

	return 1;
}


// This method is called when GTBehaviour object is updated.
int32 BSCharacterPlayer::OnUpdate(void)
{
	BSCharacter::OnUpdate();

	// Call this for post update
	BSCharacter::OnUpdatePost();

	return 1;
}


// This method is called when GTBehaviour object is destroyed.
int32 BSCharacterPlayer::OnDestroy(void)
{
	BSCharacter::OnDestroy();

	return 1;
}


// Move to
void BSCharacterPlayer::MoveTo(const GTVector2& vNewPos)
{
	// Save current position
	m_vPrevPosition = GetGameObjectPosition();
	// Save target position
	m_vDestination = vNewPos;
	// Calculate movement direction
	m_vMoveDirection = vNewPos - m_vPrevPosition;
	m_vMoveDirection.Normalize();
	// Calculate movement distance
	m_nMoveDistance = (int32)(vNewPos - m_vPrevPosition).Length();

	// Change status
	SetPropertyStatus(BSCharacter::StatusMoving);
}


void BSCharacterPlayer::OnUpdateStatusIdle(void)
{
	// Floating in idle status
	if(!GetPropertyFloatingEnable())
		return;

	GTVector2 pos = GetGameObjectPosition();
	pos.y += m_nFloatingDirection * (((float)m_lDeltaTime / 1000.0f) * (float)m_fFloatingSpeed);
	if(pos.y > m_fFloatingYHigh)
	{
		pos.y = m_fFloatingYHigh;
		m_nFloatingDirection = -1;
	}
	else if(pos.y < m_fFloatingYLow)
	{
		pos.y = m_fFloatingYLow;
		m_nFloatingDirection = 1;
	}
	// Apply new position
	SetGameObjectPosition(pos);
}


void BSCharacterPlayer::OnUpdateStatusMoving(void)
{
	BSCharacter::OnUpdateStatusMoving();

	GTVector2 pos = GetGameObjectPosition();
	pos += m_vMoveDirection * (((float)m_lDeltaTime / 1000.0f) * (float)m_nMovementSpeed);
	// Calculate how much distance the player has moved
	int32 nMoveDistance = (float)(pos - m_vPrevPosition).Length();
	// Check if the player gets to the destination
	if(nMoveDistance >= m_nMoveDistance)
	{
		SetGameObjectPosition(m_vDestination);
		// Already get to the destination, change status to idle.
		SetPropertyStatus(BSCharacter::StatusIdle);

		// Setup floating if it's enabled
		if(GetPropertyFloatingEnable())
		{
			m_vFloatingOldPos = GetGameObjectPosition();
			m_fFloatingYHigh = m_vFloatingOldPos.y + m_fFloatingMax;
			m_fFloatingYLow = m_vFloatingOldPos.y - m_fFloatingMax;
			m_nFloatingDirection = -1;
		}
	}
	else
	{
		SetGameObjectPosition(pos);
		if(pos.x < m_vDestination.x)
		{
			// Going right
			m_pGameObjectSprite->PlayAnimationByName(BSCharacter::AnimationName_MoveRight, GSpriteAnimation::PlayMode_Loop);
		}
		else
		{
			// Going left
			m_pGameObjectSprite->PlayAnimationByName(BSCharacter::AnimationName_MoveLeft, GSpriteAnimation::PlayMode_Loop);
		}
	}
}


void BSCharacterPlayer::OnUpdateStatusAttack(void)
{
}


void BSCharacterPlayer::OnUpdateStatusDying(void)
{
}


void BSCharacterPlayer::OnUpdateStatusDied(void)
{
}


// Fire a weapon
void BSCharacterPlayer::FireWeapon(const int32 nItemId)
{
	GameObjectSprite *pWeaponNew = WeaponCacheManager::Inst()->CreateWeaponGameObject(nItemId);
	if(NULL == pWeaponNew)
		return;

	// Only main weapon game object is visible
	pWeaponNew->SetVisible(true, false);
	// Spawn this weapon	
	pWeaponNew->SetPosition(GetGameObjectPosition() + GTVector2(0.0f, -40.0f));
	pWeaponNew->SetZOrder(m_pGameObjectSprite->GetZOrder());	
	// Reset
	BSWeaponTimerBomb *pBehaviour = pWeaponNew->GetBehaviour<BSWeaponTimerBomb>();
	if(pBehaviour)
		pBehaviour->ResetExplosion();
}


bool BSCharacterPlayer::OnBtnItemSingleClick(UIWidget* pWidget, uint32 nFlags, void *pParam)
{
	if(nFlags & UIWidget::Flag_ClickDown)
		return true;

	//GTLogManager::Inst()->LogFormatComment(CTEXT("pWidget->Id = %d"), pWidget->GetId());

	switch(pWidget->GetId())
	{
		case 1201:
			FireWeapon(100);
			break;

		case 1202:
			FireWeapon(101);
			break;

		case 1203:
			FireWeapon(102);
			break;
	}

	return true;
}
