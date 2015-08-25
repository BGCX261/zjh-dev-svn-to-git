#include "BSEndPosition.h"
#include "BSClassName.h"
#include "BSPlayerController.h"
#include <GTGameObjectManager.h>

GTBEHAVIOUR_IMP(BSEndPosition, GTBehaviour);

BSEndPosition::BSEndPosition()
{
}


BSEndPosition::~BSEndPosition()
{
}


// This method is called when GTBehaviour object is created.
int32 BSEndPosition::OnCreate(void)
{
	GTBehaviour::OnCreate();

	SetPropertyTrigger(false);
	
	return 1;
}


// This method is called when GTBehaviour object is initialized.
int32 BSEndPosition::OnInitialize(GTBehaviourInit* param)
{
	GTBehaviour::OnInitialize(param);

	m_pBSGameObjectGeneral = (BSGameObjectGeneral*)BSCLASSNAME_GET_COMPONENT(BSClassName::BSGameObjectGeneral);
	
	return 1;
}


// This method is called before first OnUpdate
int32 BSEndPosition::OnStart(void)
{
	GTBehaviour::OnStart();
	
	// Get main play object
	m_pMainPlayer = GTGameObjectManager::Inst()->FindGameObjectByName(BSPlayerController::m_szMainPlayName);
	if(NULL == m_pMainPlayer)
	{
		GTLogManager::GetInstance()->LogError(CTEXT("BSEndPosition: Failed to find main player game object"));
	}

	return 1;
}


// This method is called when GTBehaviour object is updated.
int32 BSEndPosition::OnUpdate(void)
{
	GTBehaviour::OnUpdate();

	if(!GetPropertyTrigger())
	{
		// Check to see if the player reach at current end position object
		BSGameObjectGeneral* pBSGameObjectGeneralPlayer = (BSGameObjectGeneral*)(m_pMainPlayer->GetComponent(BSClassName::BSGameObjectGeneral));
		if(pBSGameObjectGeneralPlayer)
		{
			GTGameObjectCollider* pCollisionPlayer = pBSGameObjectGeneralPlayer->GetCollider();
			GTGameObjectCollider* pCollisionEndPosition = m_pBSGameObjectGeneral->GetCollider();
			if(pCollisionEndPosition->Collide(pCollisionPlayer))
			{
				m_pMainPlayer->OnCollision(m_pGameObject);
				// Set the trigger
				SetPropertyTrigger(true);
			}
		}
	}

	return 1;
}


// This method is called when GTBehaviour object is destroyed.
int32 BSEndPosition::OnDestroy(void)
{
	GTBehaviour::OnDestroy();
	
	return 1;
}


// Reset the trigger
void BSEndPosition::Reset(void)
{
	SetPropertyTrigger(false);
}
