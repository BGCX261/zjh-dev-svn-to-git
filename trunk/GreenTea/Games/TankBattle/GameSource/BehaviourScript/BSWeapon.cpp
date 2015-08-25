#include "BSWeapon.h"
#include <GameObjectSprite.h>

GTBEHAVIOUR_IMP(BSWeapon, GTBehaviour);

BSWeapon::BSWeapon() : GTBehaviour(), m_pWeaponGameObject(NULL)
{
}


BSWeapon::~BSWeapon()
{
}


// This method is called when GTBehaviour object is created.
int32 BSWeapon::OnCreate(void)
{
	GTBehaviour::OnCreate();

	return 1;
}


// This method is called when GTBehaviour object is initialized.
int32 BSWeapon::OnInitialize(GTBehaviourInit* param)
{
	if(NULL == param || NULL == param->pParam2)
		return 0;
		
	GTBehaviour::OnInitialize(param);

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
int32 BSWeapon::OnStart(void)
{
	GTBehaviour::OnStart();

	// Get parent sprite game object
	m_pWeaponGameObject = GetGameObject<GameObjectSprite>();
	
	return 1;
}


// This method is called when GTBehaviour object is updated.
int32 BSWeapon::OnUpdate(void)
{
	GTBehaviour::OnUpdate();

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
int32 BSWeapon::OnDestroy(void)
{
	GTBehaviour::OnDestroy();

	return 1;
}
