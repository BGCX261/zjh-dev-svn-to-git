#ifndef _BS_CHARACTER_NPC_H_
#define _BS_CHARACTER_NPC_H_

#include <GTBehaviour.h>
#include "BSCharacter.h"

class BSCharacterNPC : public BSCharacter
{
public:
	GTBEHAVIOUR_DEF(BSCharacterNPC, BSCharacter);

public:
	BSCharacterNPC();
	virtual ~BSCharacterNPC();

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

public:
	// The left limit of movement
	GT_PROPERTY_DEF_VAR_SET_GET_INT16(MoveLeftLimit);
	// The right limit of movement
	GT_PROPERTY_DEF_VAR_SET_GET_INT16(MoveRightLimit);
	// The direction of movement
	GT_PROPERTY_DEF_VAR_SET_GET_INT16(MoveDirection);
	// The default direction of movement
	GT_PROPERTY_DEF_VAR_SET_GET_INT16(DefaultDirection);
};

#endif /* _BS_CHARACTER_NPC_H_ */
