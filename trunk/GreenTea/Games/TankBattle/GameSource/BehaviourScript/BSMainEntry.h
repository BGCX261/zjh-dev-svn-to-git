#ifndef _BS_MAIN_ENTRY_H_
#define _BS_MAIN_ENTRY_H_

#include <GTBehaviour.h>

// This behaviour BSMainEntry must be implemented because
// this behaviour is loaded defaultly by the framework.
class BSMainEntry : public GTBehaviour
{
public:
	GTBEHAVIOUR_DEF(BSMainEntry, GTBehaviour);

public:
	BSMainEntry();
	virtual ~BSMainEntry();

	// This method is called when GTBehaviour object is created.
	virtual int32 OnCreate(void);
	// This method is called when GTBehaviour object is initialized.
	virtual int32 OnInitialize(GTBehaviourInit* param);
	// OnStart is called just before any of the OnUpdate methods is called the first time.
	virtual int32 OnStart(void);
	// This method is called when GTBehaviour object is updated.
	virtual int32 OnUpdate(void);
	// This method is called when GTBehaviour object is destroyed.
	virtual int32 OnDestroy(void);
	// If this GTBehaviour needs to be rebuilt
	virtual void OnDirty(void);
	// OnVisible is called when the the object is set visible.
	virtual void OnVisible(GTGameObject *pCaller, bool bApplyForChildren);
	// OnVisible is called when the the object is set invisible.
	virtual void OnInvisible(GTGameObject *pCaller, bool bApplyForChildren);
};

#endif /* _BS_MAIN_ENTRY_H_ */
