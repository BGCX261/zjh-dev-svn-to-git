#include "BSScreenSprite.h"
#include "GameObjectCreation.h"
#include "GameGeneral.h"
#include <SceneManager.h>
#include <GTPropertyFile.h>

GTBEHAVIOUR_IMP(BSScreenSprite, BSSpriteBase);

BSScreenSprite::BSScreenSprite() : BSSpriteBase()
{
}


BSScreenSprite::~BSScreenSprite()
{
}


// This method is called when GTBehaviour object is created.
int32 BSScreenSprite::OnCreate(void)
{
	BSSpriteBase::OnCreate();

	return 1;
}


// This method is called when GTBehaviour object is initialized.
int32 BSScreenSprite::OnInitialize(GTBehaviourInit* param)
{
	BSSpriteBase::OnInitialize(param);

	if(m_pSprite && m_pGameObject)
	{
		// The sprite position is exactly same as game object's
		m_pSprite->SetPosition(
			m_pGameObject->m_Position.x,
			m_pGameObject->m_Position.y
			);
	}

	return 1;
}


// If this GTBehaviour needs to be rebuilt
void BSScreenSprite::OnDirty(void)
{
	BSSpriteBase::OnDirty();
}


// OnVisible is called when the the object is set visible.
void BSScreenSprite::OnVisible(void)
{
	BSSpriteBase::OnVisible();
}


// OnVisible is called when the the object is set invisible.
void BSScreenSprite::OnInvisible(void)
{
	BSSpriteBase::OnInvisible();
}


// OnStart is called just before any of the OnUpdate methods is called the first time.
int32 BSScreenSprite::OnStart(void)
{
	return BSSpriteBase::OnStart();
}


// This method is called when GTBehaviour object is updated.
int32 BSScreenSprite::OnUpdate(void)
{
	BSSpriteBase::OnUpdate();

	if(m_pSprite && m_pGameObject)
	{
		// Make sure sprite position is exactly same as game object's
		m_pSprite->SetPosition(
			m_pGameObject->m_Position.x,
			m_pGameObject->m_Position.y
			);
	}

	return 1;
}


// This method is called when GTBehaviour object is destroyed.
int32 BSScreenSprite::OnDestroy(void)
{
	return BSSpriteBase::OnDestroy();
}
