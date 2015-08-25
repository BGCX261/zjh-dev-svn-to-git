#include "BSDebugGameObject.h"
#include "BSClassName.h"
#include "BSStaticSprite.h"
#include "BSGameObjectGeneral.h"

GTBEHAVIOUR_IMP(BSDebugGameObject, GTBehaviour);

BSDebugGameObject::BSDebugGameObject()
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
int32 BSDebugGameObject::OnInitialize(GTBehaviourInitParam* param)
{
	GTBehaviour::OnInitialize(param);

	m_pBSStaticSprite = NULL;
	m_pParentBSGameObjectGeneral = NULL;
	
	return 1;
}


// This method is called before first OnUpdate
int32 BSDebugGameObject::OnStart(void)
{
	GTBehaviour::OnStart();

	m_pBSStaticSprite = (BSStaticSprite*)BSCLASSNAME_GET_COMPONENT(BSClassName::BSStaticSprite);
	if(GetGameObject()->GetParent())
	{
		m_pParentBSGameObjectGeneral = (BSGameObjectGeneral*)(GetGameObject()->GetParent()->GetBehaviour(BSClassName::BSGameObjectGeneral));
	}

	// Setup correct collider size
	if(m_pBSStaticSprite && m_pParentBSGameObjectGeneral)
	{
		if(m_pBSStaticSprite->m_pSprite)
		{
			GTGameObjectCollider* pCollider = m_pParentBSGameObjectGeneral->GetCollider();
			if(pCollider)
			{
				GTRect texRect = m_pBSStaticSprite->m_pSprite->GetTextureRect();
				m_pBSStaticSprite->m_pSprite->SetScaleX(pCollider->m_ColliderSize.width / texRect.size.width);
				m_pBSStaticSprite->m_pSprite->SetScaleY(pCollider->m_ColliderSize.height / texRect.size.height);
			}
		}
	}
	
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
