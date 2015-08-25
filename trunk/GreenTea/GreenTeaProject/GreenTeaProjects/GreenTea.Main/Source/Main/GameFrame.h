// Main game frame

#ifndef _GAME_FRAME_H_
#define _GAME_FRAME_H_

#include <GTBaseDef.h>

class GameFrame
{
public:
	// After the system is initialized, this method is called.
	static int32 OnInitialize(void);

	// When the system is running, this method is called for each frame.
	static int32 OnUpdate(void);

	// This method is called for rendering each frame.
	static int32 OnRender(void);

	// Before the system is shut down, this method is called.
	static int32 OnDestroy(void);
};

#endif /* _GAME_FRAME_H_ */
