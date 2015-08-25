#include "BSGameObjectGeneralV2.h"
#include <GTPropertyFile.h>
#include "MapManager.h"
#include "TimeManager.h"

GTBEHAVIOUR_IMP(BSGameObjectGeneralV2, GTBehaviour);

BSGameObjectGeneralV2::BSGameObjectGeneralV2()
{
}


BSGameObjectGeneralV2::~BSGameObjectGeneralV2()
{
}


// This method is called when GTBehaviour object is created.
int32 BSGameObjectGeneralV2::OnCreate(void)
{
	GTBehaviour::OnCreate();

	return 1;
}


// Create the sprite from the property tree node
bool BSGameObjectGeneralV2::CreateFromPropertyTreeNode(GTTreeNode *pTreeNode)
{
	if(NULL == pTreeNode)
	{
		return false;
	}

	return true;
}


// This method is called when GTBehaviour object is initialized.
int32 BSGameObjectGeneralV2::OnInitialize(GTBehaviourInit* param)
{
	DBG_ASSERT(m_pGameObject);

	if(NULL == param)
	{
		return 0;
	}

	GTBehaviour::OnInitialize(param);
		
	// Initialize the script from the tree node	
	CreateFromPropertyTreeNode((GTTreeNode*)(param->pParam2));

	// Save position offset related to its parent
	m_PositionOffset = m_pGameObject->GetPosition();
	m_pGameObject->SetPosition(m_pGameObject->GetPosition());

	return 1;
}


// Update the collider object
void BSGameObjectGeneralV2::OnUpdateCollider(void)
{
}


// The OnStart function is called after all OnCreated functions on all script instances have been called.
int32 BSGameObjectGeneralV2::OnStart(void)
{
	if(m_pGameObject)
	{
	}

	return 1;
}


// This method is called when GTBehaviour object is updated.
int32 BSGameObjectGeneralV2::OnUpdate(void)
{
	GTBehaviour::OnUpdate();

	return 1;
}


// This method is called when GTBehaviour object is destroyed.
int32 BSGameObjectGeneralV2::OnDestroy(void)
{
	GTBehaviour::OnDestroy();

	return 1;
}


// OnCollisionEnter is called when this collider/rigidbody has begun touching another rigidbody/collider.
void BSGameObjectGeneralV2::OnCollisionEnter(GTGameObject* pGameObject)
{
}


// OnCollisionExit is called when this collider/rigidbody has stopped touching another rigidbody/collider.
void BSGameObjectGeneralV2::OnCollisionExit(GTGameObject* pGameObject)
{
}


// OnCollisionStay is called once per frame for every collider/rigidbody that is touching rigidbody/collider.
void BSGameObjectGeneralV2::OnCollisionStay(GTGameObject* pGameObject)
{
}
