#ifndef _BS_SPRITE_H_
#define _BS_SPRITE_H_

#include <GTBehaviour.h>
#include <GTTreeNode.h>
#include "../Sprite/GSprite.h"

class BSSprite : public GTBehaviour
{
public:
	GTBEHAVIOUR_DEF(BSSprite, GTBehaviour);

public:
	BSSprite();
	virtual ~BSSprite();

	// This method is called when GTBehaviour object is created.
	virtual int32 OnCreate(void);
	// This method is called when GTBehaviour object is initialized.
	virtual int32 OnInitialize(GTBehaviourInitParam* param);
	// OnStart is called just before any of the OnUpdate methods is called the first time.
	virtual int32 OnStart(void);
	// This method is called when GTBehaviour object is updated.
	virtual int32 OnUpdate(void);
	// This method is called when GTBehaviour object is destroyed.
	virtual int32 OnDestroy(void);
	// If this GTBehaviour needs to be rebuilt
	virtual void OnDirty(void);
	// OnVisible is called when the the object is set visible.
	virtual void OnVisible(void);
	// OnVisible is called when the the object is set invisible.
	virtual void OnInvisible(void);

	// Create the sprite from the property tree node
	bool CreateFromPropertyTreeNode(GTTreeNode *pTreeNode);

	// Get the sprite object
	GSprite* GetSpriteObject(void)
	{
		return m_pSprite;
	}

public:
	// The sprite object
	GSprite *m_pSprite;
};

#endif /* _BS_SPRITE_H_ */
