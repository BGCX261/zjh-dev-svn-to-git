#include "BSUnitMarine.h"

GTBEHAVIOUR_IMP(BSUnitMarine, BSUnitBehaviour);

BSUnitMarine::BSUnitMarine() : BSUnitBehaviour()	
{
}


BSUnitMarine::~BSUnitMarine()
{
}


// This method is called when GTBehaviour object is created.
int32 BSUnitMarine::OnCreate(void)
{
	BSUnitBehaviour::OnCreate();

	return 1;
}


// This method is called when GTBehaviour object is initialized.
int32 BSUnitMarine::OnInitialize(GTBehaviourInitParam* param)
{
	BSUnitBehaviour::OnInitialize(param);
		
	return 1;
}


// This method is called before first OnUpdate
int32 BSUnitMarine::OnStart(void)
{
	BSUnitBehaviour::OnStart();

	return 1;
}


// This method is called when GTBehaviour object is updated.
int32 BSUnitMarine::OnUpdate(void)
{
	BSUnitBehaviour::OnUpdate();

	return 1;
}


// This method is called when GTBehaviour object is destroyed.
int32 BSUnitMarine::OnDestroy(void)
{
	BSUnitBehaviour::OnDestroy();

	return 1;
}
