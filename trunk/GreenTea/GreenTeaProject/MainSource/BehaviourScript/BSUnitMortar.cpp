#include "BSUnitMortar.h"

GTBEHAVIOUR_IMP(BSUnitMortar, BSUnitBehaviour);

BSUnitMortar::BSUnitMortar() : BSUnitBehaviour()
{
}


BSUnitMortar::~BSUnitMortar()
{
}


// This method is called when GTBehaviour object is created.
int32 BSUnitMortar::OnCreate(void)
{
	BSUnitBehaviour::OnCreate();

	return 1;
}


// This method is called when GTBehaviour object is initialized.
int32 BSUnitMortar::OnInitialize(GTBehaviourInitParam* param)
{
	BSUnitBehaviour::OnInitialize(param);

	return 1;
}


// This method is called before first OnUpdate
int32 BSUnitMortar::OnStart(void)
{
	BSUnitBehaviour::OnStart();

	return 1;
}


// This method is called when GTBehaviour object is updated.
int32 BSUnitMortar::OnUpdate(void)
{
	BSUnitBehaviour::OnUpdate();

	return 1;
}


// This method is called when GTBehaviour object is destroyed.
int32 BSUnitMortar::OnDestroy(void)
{
	BSUnitBehaviour::OnDestroy();

	return 1;
}
