#ifndef _BS_DEBUG_GAME_OBJECT_H_
#define _BS_DEBUG_GAME_OBJECT_H_

#include <GTBehaviour.h>
#include <GameObjectSprite.h>

class BSStaticSprite;
class BSGameObjectGeneral;

class BSDebugGameObject : public GTBehaviour
{
public:
	GTBEHAVIOUR_DEF(BSDebugGameObject, GTBehaviour);

public:
	BSDebugGameObject();
	virtual ~BSDebugGameObject();

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

protected:
	GameObjectSprite* m_pGameObjectSprite;
	BSGameObjectGeneral* m_pParentBSGameObjectGeneral;
};

#endif /* _BS_DEBUG_GAME_OBJECT_H_ */
