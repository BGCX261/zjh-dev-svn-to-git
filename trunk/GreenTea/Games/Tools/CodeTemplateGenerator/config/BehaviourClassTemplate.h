#ifndef $DefineReplacement$
#define $DefineReplacement$

#include <GTBehaviour.h>

class $ClassReplacement$ : public $SuperClassReplacement$
{
public:
	GTBEHAVIOUR_DEF($ClassReplacement$, $SuperClassReplacement$);

public:
	$ClassReplacement$();
	virtual ~$ClassReplacement$();

	// This method is called when GTBehaviour object is created.
	virtual int32 OnCreate(void);
	// This method is called when GTBehaviour object is initialized.
	virtual int32 OnInitialize(GTBehaviourInitParam* param);
	// This method is called before first OnUpdate
	virtual int32 OnStart(void);
	// This method is called when GTBehaviour object is updated.
	virtual int32 OnUpdate(void);
	// This method is called when GTBehaviour object is destroyed.
	virtual int32 OnDestroy(void);
};

#endif /* $DefineReplacement$ */
