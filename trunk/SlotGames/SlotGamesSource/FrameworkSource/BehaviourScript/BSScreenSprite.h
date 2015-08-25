#ifndef _BS_SCREEN_SPRITE_H_
#define _BS_SCREEN_SPRITE_H_

#include <GTBehaviour.h>
#include <GTTreeNode.h>
#include "BSSpriteBase.h"

class BSScreenSprite : public BSSpriteBase
{
public:
	GTBEHAVIOUR_DEF(BSScreenSprite, BSSpriteBase);

public:
	BSScreenSprite();
	virtual ~BSScreenSprite();

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
};

#endif /* _BS_SCREEN_SPRITE_H_ */
