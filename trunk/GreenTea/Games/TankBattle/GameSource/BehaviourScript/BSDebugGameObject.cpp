#include "BSDebugGameObject.h"
#include "BSClassName.h"
#include "BSStaticSprite.h"
#include "BSGameObjectGeneral.h"
#include <GTPropertyFile.h>

GTBEHAVIOUR_IMP(BSDebugGameObject, GTBehaviour);

BSDebugGameObject::BSDebugGameObject() :
		m_pGameObjectSprite(NULL),
		m_pParentBSGameObjectGeneral(NULL)
{
}


BSDebugGameObject::~BSDebugGameObject()
{
}


// This method is called when GTBehaviour object is created.
int32 BSDebugGameObject::OnCreate(void)
{
	GTBehaviour::OnCreate();
	
	return 1;
}


// This method is called when GTBehaviour object is initialized.
int32 BSDebugGameObject::OnInitialize(GTBehaviourInit* param)
{
	if(NULL == param || NULL == param->pParam2)
		return 0;

	GTBehaviour::OnInitialize(param);

	GTTreeNode* pTnRoot = (GTTreeNode*)(param->pParam2);
	
	GTGameObject *pParent = GetGameObject()->GetParent();
	m_pGameObjectSprite = GetGameObject<GameObjectSprite>();
	if(pParent)
		m_pParentBSGameObjectGeneral = pParent->GetBehaviour<BSGameObjectGeneral>();	
	if(m_pGameObjectSprite && m_pParentBSGameObjectGeneral)
	{
		if(m_pGameObjectSprite->m_pSprite)
		{
			// Setup z-order with parent's
			m_pGameObjectSprite->SetZOrder(pParent->GetZOrder());
			// Setup correct collider size
			GTGameObjectCollider* pCollider = m_pParentBSGameObjectGeneral->GetCollider();
			if(pCollider)
			{
				GTRect texRect = m_pGameObjectSprite->GetTextureRect();
				m_pGameObjectSprite->SetScaleX(pCollider->m_ColliderSize.width / texRect.size.width);
				m_pGameObjectSprite->SetScaleY(pCollider->m_ColliderSize.height / texRect.size.height);
			}
		}
	}

	return 1;
}


// This method is called before first OnUpdate
int32 BSDebugGameObject::OnStart(void)
{
	GTBehaviour::OnStart();
		
	return 1;
}


// This method is called when GTBehaviour object is updated.
int32 BSDebugGameObject::OnUpdate(void)
{
	GTBehaviour::OnUpdate();
	
	return 1;
}


// This method is called when GTBehaviour object is destroyed.
int32 BSDebugGameObject::OnDestroy(void)
{
	GTBehaviour::OnDestroy();
	
	return 1;
}
