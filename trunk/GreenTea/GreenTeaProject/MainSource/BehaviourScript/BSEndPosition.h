#ifndef _BS_END_POSITION_H_
#define _BS_END_POSITION_H_

#include <GTBehaviour.h>
#include <BehaviourScript/BSGameObjectGeneral.h>

class BSEndPosition : public GTBehaviour
{
public:
	GTBEHAVIOUR_DEF(BSEndPosition, GTBehaviour);

public:
	BSEndPosition();
	virtual ~BSEndPosition();

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

	// Reset the trigger
	void Reset(void);

private:
	// Is already triggered ?
	GT_PROPERTY_DEF_VAR_SET_GET_BOOL(Trigger);
	// Cached game objects
	GTGameObject* m_pMainPlayer;
	// BSGameObjectGeneral
	BSGameObjectGeneral* m_pBSGameObjectGeneral;
};

#endif /* _BS_END_POSITION_H_ */
