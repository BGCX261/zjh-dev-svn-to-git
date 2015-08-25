#ifndef _BS_GAME_OBJECT_GENERAL_V2_H_
#define _BS_GAME_OBJECT_GENERAL_V2_H_

#include <GTBehaviour.h>
#include <GTGreenTea.h>
#include <GTGameObjectCollider.h>

class BSGameObjectGeneralV2 : public GTBehaviour
{
public:
	GTBEHAVIOUR_DEF(BSGameObjectGeneralV2, GTBehaviour);

public:
	BSGameObjectGeneralV2();
	virtual ~BSGameObjectGeneralV2();

	// This method is called when GTBehaviour object is created.
	virtual int32 OnCreate(void);
	// This method is called when GTBehaviour object is initialized.
	virtual int32 OnInitialize(GTBehaviourInitParam* param);
	// The OnStart function is called after all OnCreated functions on all script instances have been called.
	virtual int32 OnStart(void);
	// This method is called when GTBehaviour object is updated.
	virtual int32 OnUpdate(void);
	// This method is called when GTBehaviour object is destroyed.
	virtual int32 OnDestroy(void);
	// OnCollisionEnter is called when this collider/rigidbody has begun touching another rigidbody/collider.
	virtual void OnCollisionEnter(GTGameObject* pGameObject);
	// OnCollisionExit is called when this collider/rigidbody has stopped touching another rigidbody/collider.
	virtual void OnCollisionExit(GTGameObject* pGameObject);
	// OnCollisionStay is called once per frame for every collider/rigidbody that is touching rigidbody/collider.
	virtual void OnCollisionStay(GTGameObject* pGameObject);

	// Update the collider object
	void OnUpdateCollider(void);
	// Create the sprite from the property tree node
	bool CreateFromPropertyTreeNode(GTTreeNode *pTreeNode);

protected:
	GTPoint2 m_PositionOffset;
};

#endif /* _BS_GAME_OBJECT_GENERAL_V2_H_ */
