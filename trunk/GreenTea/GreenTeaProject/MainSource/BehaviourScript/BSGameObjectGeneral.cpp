#include "BSGameObjectGeneral.h"
#include "../PropertyFile.h"
#include "../MapManager.h"

GTBEHAVIOUR_IMP(BSGameObjectGeneral, GTBehaviour);

BSGameObjectGeneral::BSGameObjectGeneral():
	GT_PROPERTY_REF_VAR_BOOL(FollowParent)(false)
{
}


BSGameObjectGeneral::~BSGameObjectGeneral()
{
}


// This method is called when GTBehaviour object is created.
int32 BSGameObjectGeneral::OnCreate(void)
{
	GTBehaviour::OnCreate();

	return 1;
}


// Create the sprite from the property tree node
bool BSGameObjectGeneral::CreateFromPropertyTreeNode(GTTreeNode *pTreeNode)
{
	if(NULL == pTreeNode)
	{
		return false;
	}

	// Collision
	GTTreeNode* pCollisionNode = pTreeNode->GetChild(PropertyFile::TagCollision);
	if(pCollisionNode)
	{
		m_Collider.SetColliderSize(pCollisionNode->ValueToSize());
	}
	// FollowParent
	GTTreeNode* pFollowParentNode = pTreeNode->GetChild(PropertyFile::TagPairValue);
	if(pFollowParentNode)
	{
		GTPairValue pv = pFollowParentNode->ValueToPairValue();
		if(pv.m_sName == CTEXT("FollowParent"))
			SetPropertyFollowParent(pv.m_sValue.AsBool());
	}

	return true;
}


// This method is called when GTBehaviour object is initialized.
int32 BSGameObjectGeneral::OnInitialize(GTBehaviourInitParam* param)
{
	if(NULL == param)
	{
		return 0;
	}

	GTBehaviour::OnInitialize(param);

	DBG_ASSERT(m_pGameObject);

	// Set the game object position at the tile center
	SetPositionAtTileCenter();

	// Initialize the script from the tree node	
	CreateFromPropertyTreeNode((GTTreeNode*)(param->pParam2));

	return 1;
}


// Update the collider object
void BSGameObjectGeneral::OnUpdateCollider(void)
{
	const GTVector2 pos = m_pGameObject->GetPosition();
	const GTSize halfSize = m_Collider.m_ColliderSize / 2.0f;
	m_Collider.m_ColliderRect = GTRect(
		pos.x - halfSize.width,
		pos.y - halfSize.height,
		m_Collider.m_ColliderSize.width,
		m_Collider.m_ColliderSize.height
		);
}


// This method is called when GTBehaviour object is updated.
int32 BSGameObjectGeneral::OnUpdate(void)
{
	GTBehaviour::OnUpdate();

	if(GetPropertyFollowParent() && m_pGameObject->GetParent())
	{
		m_pGameObject->SetPosition(m_pGameObject->GetParent()->GetPosition());
	}

	// Update collider object
	OnUpdateCollider();	

	return 1;
}


// This method is called when GTBehaviour object is destroyed.
int32 BSGameObjectGeneral::OnDestroy(void)
{
	GTBehaviour::OnDestroy();

	return 1;
}


// OnCollisionEnter is called when this collider/rigidbody has begun touching another rigidbody/collider.
void BSGameObjectGeneral::OnCollisionEnter(GTGameObject* pGameObject)
{
}


// OnCollisionExit is called when this collider/rigidbody has stopped touching another rigidbody/collider.
void BSGameObjectGeneral::OnCollisionExit(GTGameObject* pGameObject)
{
}


// OnCollisionStay is called once per frame for every collider/rigidbody that is touching rigidbody/collider.
void BSGameObjectGeneral::OnCollisionStay(GTGameObject* pGameObject)
{
}


void BSGameObjectGeneral::SetPositionAtTileCenter(void)
{
	if(NULL == m_pGameObject)
	{
		return;
	}

	// Adjust game object position in the map in order to
	// put the game object in the middle of the tile.
	const GTPoint2 centerPosition = MapManager::GetInstance()->GetTileCenterPositionFromMapPosition(
		m_pGameObject->m_Position.x,
		m_pGameObject->m_Position.y
		);
	m_pGameObject->SetPosition(centerPosition.x, centerPosition.y);
}
