#include "BSMainEntry.h"
#include "../SlotGameManager.h"

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
int32 BSMainEntry::OnInitialize(GTBehaviourInitParam* param)
{
	GTBehaviour::OnInitialize(param);
		
	// Initialize slot game
	SlotGameManager::Inst()->OnInitialize();

	return 1;
}


// If this GTBehaviour needs to be rebuilt
void BSMainEntry::OnDirty(void)
{
	GTBehaviour::OnDirty();
}


// OnVisible is called when the the object is set visible.
void BSMainEntry::OnVisible(void)
{
	GTBehaviour::OnVisible();
}


// OnVisible is called when the the object is set invisible.
void BSMainEntry::OnInvisible(void)
{
	GTBehaviour::OnInvisible();
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

	return 1;
}


// This method is called when GTBehaviour object is destroyed.
int32 BSMainEntry::OnDestroy(void)
{
	GTBehaviour::OnDestroy();

	SlotGameManager::Inst()->OnDestroy();

	return 1;
}
