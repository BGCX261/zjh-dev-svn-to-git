#ifndef _BS_GAME_OBJECT_GENERAL_H_
#define _BS_GAME_OBJECT_GENERAL_H_

#include <GTBehaviour.h>
#include <GTGreenTea.h>
#include <GTGameObjectCollider.h>

class BSGameObjectGeneral : public GTBehaviour
{
public:
	GTBEHAVIOUR_DEF(BSGameObjectGeneral, GTBehaviour);

public:
	BSGameObjectGeneral();
	virtual ~BSGameObjectGeneral();

	// This method is called when GTBehaviour object is created.
	virtual int32 OnCreate(void);
	// This method is called when GTBehaviour object is initialized.
	virtual int32 OnInitialize(GTBehaviourInitParam* param);
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
	// Copy
	virtual bool Copy(GTObject* pObjectFrom);

	// Update the collider object
	void OnUpdateCollider(void);
	// Set the position at the center of the tile
	void SetPositionAtTileCenter(void);
	// Create the sprite from the property tree node
	bool CreateFromPropertyTreeNode(GTTreeNode *pTreeNode);

	// Get collision object
	GTGameObjectCollider* GetCollider(void)
	{
		return &m_Collider;
	}

protected:
	// This variable indicates if this game object follows its parent.
	GT_PROPERTY_DEF_VAR_SET_GET_BOOL(FollowParent);
	// The collider object
	GTGameObjectCollider m_Collider;
};

#endif /* _BS_GAME_OBJECT_GENERAL_H_ */
