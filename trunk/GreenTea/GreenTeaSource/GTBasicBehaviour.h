#ifndef _GT_BASIC_BEHAVIOUR_H_
#define _GT_BASIC_BEHAVIOUR_H_

#include "GTBaseDef.h"

class GTGameObject;

class GTBasicBehaviour
{
public:
	// OnStart is called just before any of the OnUpdate methods is called the first time.
	// OnStart is only called once in the lifetime of the behaviour.
	// The difference between OnCreate and OnStart is that OnStart is only called
	// if the script instance is enabled. This allows you to delay any initialization code,
	// until it is really needed. OnCreated is always called before any OnStart functions.
	// This allows you to order initialization of scripts.
	// The OnStart function is called after all OnCreated functions on all script instances have been called.
	virtual int32 OnStart(void) = 0;

	// This method is called when the object is updated.
	virtual int32 OnUpdate(void) = 0;

	// This method is called when the object is destroyed.
	virtual int32 OnDestroy(void) = 0;

	// If the object needs to be rebuilt
	virtual void OnDirty(void) = 0;

	// OnVisible is called when the the object is set visible.
	// bApplyForChildren - if this call applies to the children
	//                     true - yes
	//                     false - no
	virtual void OnVisible(GTGameObject *pCaller, bool bApplyForChildren) = 0;

	// OnVisible is called when the the object is set invisible.
	// bApplyForChildren - if this call applies to the children
	//                     true - yes
	//                     false - no
	virtual void OnInvisible(GTGameObject *pCaller, bool bApplyForChildren) = 0;

	// This function is called when the behaviour becomes disabled or inactive.
	virtual void OnDisable(void) = 0;

	// This function is called when the object becomes enabled and active.
	virtual void OnEnable(void) = 0;

	// OnChangeZOrder is called when the the object is set with new z-order.
	virtual void OnChangeZOrder(const int32 nNewZOrder) = 0;

	// This function is called after a new level was loaded.
	virtual void OnLevelWasLoaded(const int32 nParam) = 0;

	// OnCollisionEnter is called when this collider/rigidbody has begun touching another rigidbody/collider.
	virtual void OnCollisionEnter(GTGameObject* pGameObject) = 0;

	// OnCollisionExit is called when this collider/rigidbody has stopped touching another rigidbody/collider.
	virtual void OnCollisionExit(GTGameObject* pGameObject) = 0;
	
	// OnCollisionStay is called once per frame for every collider/rigidbody that is touching rigidbody/collider.
	virtual void OnCollisionStay(GTGameObject* pGameObject) = 0;
};

#endif /* _GT_BASIC_BEHAVIOUR_H_ */
