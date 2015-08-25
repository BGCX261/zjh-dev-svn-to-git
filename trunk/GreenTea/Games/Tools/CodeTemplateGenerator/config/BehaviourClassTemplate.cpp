#include "$ClassReplacement$.h"

GTBEHAVIOUR_IMP($ClassReplacement$, $SuperClassReplacement$);

$ClassReplacement$::$ClassReplacement$()
{
}


$ClassReplacement$::~$ClassReplacement$()
{
}


// This method is called when GTBehaviour object is created.
int32 $ClassReplacement$::OnCreate(void)
{
	GTBehaviour::OnCreate();
	
	return 1;
}


// This method is called when GTBehaviour object is initialized.
int32 $ClassReplacement$::OnInitialize(GTBehaviourInitParam* param)
{
	GTBehaviour::OnInitialize(param);
	
	return 1;
}


// This method is called before first OnUpdate
int32 $ClassReplacement$::OnStart(void)
{
	GTBehaviour::OnStart();
	
	return 1;
}


// This method is called when GTBehaviour object is updated.
int32 $ClassReplacement$::OnUpdate(void)
{
	GTBehaviour::OnUpdate();
	
	return 1;
}


// This method is called when GTBehaviour object is destroyed.
int32 $ClassReplacement$::OnDestroy(void)
{
	GTBehaviour::OnDestroy();
	
	return 1;
}
