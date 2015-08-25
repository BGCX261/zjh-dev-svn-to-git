#ifndef _BS_TWEENER_2D_H_
#define _BS_TWEENER_2D_H_

#include <GTBehaviour.h>
#include <GTStaticCallback.h>
#include "../Common/Tweener2D.h"
#include "../Common/TweenInterpolation.h"

class BSTweener2D : public GTBehaviour
{
public:
	GTBEHAVIOUR_DEF(BSTweener2D, GTBehaviour);

public:
	BSTweener2D();
	virtual ~BSTweener2D();

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

	// Start
	void Start(
		const GTVector2 from,
		const GTVector2 to,
		const float duration,
		TweenFunction tweenFunction,
		const float delay,
		GTStatic_CallbackFunction onCompleted,
		void* pParam
		);
	void Start(
		const GTVector2 from,
		const GTVector2 to,
		const float duration,
		TweenFunction tweenFunction,
		const float delay
		);
	// Update
	void TweenUpdate(void);
	// Stop
	void Stop(void);
	
public:
	// Tweener2D object
	Tweener2D m_Tweener;
	// Properties
	GT_PROPERTY_DEF_VAR_SET_GET_FLOAT(Delay);
	GT_PROPERTY_DEF_VAR_SET_GET_FLOAT(StartTime);
	GT_PROPERTY_DEF_VAR_SET_GET_BOOL(Running);
	// Callback
	GTStaticCallback m_StaticCallback;
};

#endif /* _BS_TWEENER_2D_H_ */
