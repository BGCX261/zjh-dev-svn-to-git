#ifndef _BS_UNIT_MARINE_H_
#define _BS_UNIT_MARINE_H_

#include <GTBehaviour.h>
#include "BSUnitBehaviour.h"

class BSUnitMarine : public BSUnitBehaviour
{
public:
	GTBEHAVIOUR_DEF(BSUnitMarine, BSUnitBehaviour);

public:
	BSUnitMarine();
	virtual ~BSUnitMarine();

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

#endif /* _BS_UNIT_MARINE_H_ */
