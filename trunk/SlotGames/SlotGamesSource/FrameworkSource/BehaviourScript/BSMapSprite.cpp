#include "BSMapSprite.h"
#include "GameObjectCreation.h"
#include "GameGeneral.h"
#include <SceneManager.h>
#include <GTPropertyFile.h>

GTBEHAVIOUR_IMP(BSMapSprite, BSSpriteBase);

BSMapSprite::BSMapSprite() : BSSpriteBase()
{
}


BSMapSprite::~BSMapSprite()
{
}


// This method is called when GTBehaviour object is created.
int32 BSMapSprite::OnCreate(void)
{
	BSSpriteBase::OnCreate();

	return 1;
}


// This method is called when GTBehaviour object is initialized.
int32 BSMapSprite::OnInitialize(GTBehaviourInitParam* param)
{
	BSSpriteBase::OnInitialize(param);

	return 1;
}


// If this GTBehaviour needs to be rebuilt
void BSMapSprite::OnDirty(void)
{
	BSSpriteBase::OnDirty();
}


// OnVisible is called when the the object is set visible.
void BSMapSprite::OnVisible(void)
{
	BSSpriteBase::OnVisible();
}


// OnVisible is called when the the object is set invisible.
void BSMapSprite::OnInvisible(void)
{
	BSSpriteBase::OnInvisible();
}


// OnStart is called just before any of the OnUpdate methods is called the first time.
int32 BSMapSprite::OnStart(void)
{
	return BSSpriteBase::OnStart();
}


// This method is called when GTBehaviour object is updated.
int32 BSMapSprite::OnUpdate(void)
{
	BSSpriteBase::OnUpdate();

	if(m_pSprite && m_pGameObject)
	{
		// Transform game object position in map coordinate system to screen coordinate system
		const GTPoint2 screenPosition = SceneManager::GetInstance()->GetScreenPositionInMap();
		m_pSprite->SetPosition(
			m_pGameObject->m_Position.x - screenPosition.x,
			m_pGameObject->m_Position.y - screenPosition.y
			);
	}

	return 1;
}


// This method is called when GTBehaviour object is destroyed.
int32 BSMapSprite::OnDestroy(void)
{
	return BSSpriteBase::OnDestroy();
}


// Copy
bool BSMapSprite::Copy(GTObject* pObjectFrom)
{
	return BSSpriteBase::Copy(pObjectFrom);
}
