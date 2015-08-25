#include "BSSprite.h"
#include "GameObjectCreation.h"
#include "GameGeneral.h"
#include <SceneManager.h>
#include <GTPropertyFile.h>

GTBEHAVIOUR_IMP(BSSprite, BSSpriteBase);

BSSprite::BSSprite() : BSSpriteBase()
{
}


BSSprite::~BSSprite()
{
}


// This method is called when GTBehaviour object is created.
int32 BSSprite::OnCreate(void)
{
	BSSpriteBase::OnCreate();

	return 1;
}


// This method is called when GTBehaviour object is initialized.
int32 BSSprite::OnInitialize(GTBehaviourInit* param)
{
	BSSpriteBase::OnInitialize(param);

	if(m_pSprite && m_pGameObject)
	{
		// The sprite position is exactly same as game object's
		m_pSprite->SetPosition(m_pGameObject->GetPosition());
	}

	return 1;
}


// If this GTBehaviour needs to be rebuilt
void BSSprite::OnDirty(void)
{
	BSSpriteBase::OnDirty();
}


// OnVisible is called when the the object is set visible.
void BSSprite::OnVisible(void)
{
	BSSpriteBase::OnVisible();
}


// OnVisible is called when the the object is set invisible.
void BSSprite::OnInvisible(void)
{
	BSSpriteBase::OnInvisible();
}


// OnStart is called just before any of the OnUpdate methods is called the first time.
int32 BSSprite::OnStart(void)
{
	return BSSpriteBase::OnStart();
}


// This method is called when GTBehaviour object is updated.
int32 BSSprite::OnUpdate(void)
{
	BSSpriteBase::OnUpdate();

	if(m_pSprite && m_pGameObject)
	{
		// Make sure sprite position is exactly same as game object's
		m_pSprite->SetPosition(m_pGameObject->GetPosition());
	}

	return 1;
}


// This method is called when GTBehaviour object is destroyed.
int32 BSSprite::OnDestroy(void)
{
	return BSSpriteBase::OnDestroy();
}


// Copy
bool BSSprite::Copy(GTObject* pObjectFrom)
{
	return BSSpriteBase::Copy(pObjectFrom);
}
