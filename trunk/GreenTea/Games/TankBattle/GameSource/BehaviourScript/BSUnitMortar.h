#ifndef _BS_UNIT_MORTAR_H_
#define _BS_UNIT_MORTAR_H_

#include <GTBehaviour.h>
#include "BSUnitBehaviour.h"

class BSUnitMortar : public BSUnitBehaviour
{
public:
	GTBEHAVIOUR_DEF(BSUnitMortar, BSUnitBehaviour);

public:
	BSUnitMortar();
	virtual ~BSUnitMortar();

	// This method is called when GTBehaviour object is created.
	virtual int32 OnCreate(void);
	// This method is called when GTBehaviour object is initialized.
	virtual int32 OnInitialize(GTBehaviourInit* param);
	// This method is called before first OnUpdate
	virtual int32 OnStart(void);
	// This method is called when GTBehaviour object is updated.
	virtual int32 OnUpdate(void);
	// This method is called when GTBehaviour object is destroyed.
	virtual int32 OnDestroy(void);
};

#endif /* _BS_UNIT_MORTAR_H_ */
