#ifndef _TILED_MAP_H_
#define _TILED_MAP_H_

#include <GTGreenTea.h>

class TiledMap
{
public:
	TiledMap();
	virtual ~TiledMap();

	virtual void SetPosition(const float x, const float y) = 0;
	virtual GTPoint2 GetPosition(void) = 0;
};

#endif /* _TILED_MAP_H_ */
