#include "BSMainEntry.h"
#include <cocos2dx-wrap/Cocos2dxGeneral.h>
#include "../../GameSource/GameClientManager.h"

GTBEHAVIOUR_IMP(BSMainEntry, GTBehaviour);

BSMainEntry::BSMainEntry() : GTBehaviour()
{
}


BSMainEntry::~BSMainEntry()
{
}


// This method is called when GTBehaviour object is created.
int32 BSMainEntry::OnCreate(void)
{
	GTBehaviour::OnCreate();

	return 1;
}


// This method is called when GTBehaviour object is initialized.
int32 BSMainEntry::OnInitialize(GTBehaviourInit* param)
{
	GTBehaviour::OnInitialize(param);

	// Initialize game client
	GameClientManager::Inst()->OnInitialize();

	return 1;
}


// If this GTBehaviour needs to be rebuilt
void BSMainEntry::OnDirty(void)
{
	GTBehaviour::OnDirty();
}


// OnVisible is called when the the object is set visible.
void BSMainEntry::OnVisible(GTGameObject *pCaller, bool bApplyForChildren)
{
	GTBehaviour::OnVisible(pCaller, bApplyForChildren);
}


// OnVisible is called when the the object is set invisible.
void BSMainEntry::OnInvisible(GTGameObject *pCaller, bool bApplyForChildren)
{
	GTBehaviour::OnInvisible(pCaller, bApplyForChildren);
}


// OnStart is called just before any of the OnUpdate methods is called the first time.
int32 BSMainEntry::OnStart(void)
{
	return GTBehaviour::OnStart();
}


// This method is called when GTBehaviour object is updated.
int32 BSMainEntry::OnUpdate(void)
{
	GTBehaviour::OnUpdate();

	if(GameClientManager::Inst()->m_bExiting)
	{
		GameClientManager::Inst()->m_bExiting = false;
		Cocos2dxGeneral::GetInstance()->Exit();
	}

	return 1;
}


// This method is called when GTBehaviour object is destroyed.
int32 BSMainEntry::OnDestroy(void)
{
	GTBehaviour::OnDestroy();

	GameClientManager::Inst()->OnDestroy();

	return 1;
}
