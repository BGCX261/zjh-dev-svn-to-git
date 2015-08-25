#ifndef _BS_TWEENER_2D_H_
#define _BS_TWEENER_2D_H_

#include <GTBehaviour.h>
#include <GTStaticCallback.h>
#include <GTTweener2D.h>
#include <GTTweenInterpolation.h>

//Graphic result:  http://www.cnblogs.com/cloudgamer/archive/2009/01/06/Tween.html
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
	//
	// from: start position
	// to: end position
	// duration: how long for (from, to), in ms
	// tweenFunction: tweener type, see TweenInterpolation
	// delay: delay to start, in ms
	// onCompleted: call-back when completes
	// pParam: customized parameters for onCompleted
	void Start(
		const GTVector2 from,
		const GTVector2 to,
		const float duration,
		GTTweenFunction tweenFunction,
		const float delay,
		GTStatic_EventCallback onCompleted,
		void* pParam
		);
	// Start
	//
	// from: start position
	// to: end position
	// duration: how long for (from, to), in ms
	// tweenFunction: tweener type, see TweenInterpolation
	// delay: delay to start, in ms
	void Start(
		const GTVector2 from,
		const GTVector2 to,
		const float duration,
		GTTweenFunction tweenFunction,
		const float delay
		);
	// Update
	void TweenUpdate(void);
	// Stop
	void Stop(void);
	
public:
	// GTTweener2D object
	GTTweener2D m_Tweener;
	// Properties
	GT_PROPERTY_DEF_VAR_SET_GET_FLOAT(Delay);
	GT_PROPERTY_DEF_VAR_SET_GET_FLOAT(StartTime);
	GT_PROPERTY_DEF_VAR_SET_GET_BOOL(Running);
	// Callback
	GTStaticCallback m_StaticCallback;
};

#endif /* _BS_TWEENER_2D_H_ */
