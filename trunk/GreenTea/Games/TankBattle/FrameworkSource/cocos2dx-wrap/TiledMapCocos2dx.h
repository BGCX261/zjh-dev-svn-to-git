#ifndef _TILED_MAP_COCOS2DX_H_
#define _TILED_MAP_COCOS2DX_H_

#include <GTGreenTea.h>
#include "cocos2d.h"

class TiledMapCocos2dx
{
public:
	TiledMapCocos2dx();
	virtual ~TiledMapCocos2dx();

	virtual void SetPosition(const float x, const float y)
	{
		DBG_ASSERT(m_pMap);
		m_pMap->setPosition(cocos2d::CCPoint((float)x, (float)y));
	}

	virtual GTPoint2 GetPosition(void)
	{
		DBG_ASSERT(m_pMap);
		cocos2d::CCPoint pt = m_pMap->getPosition();
		return GTPoint2(pt.x, pt.y);
	}

protected:
	cocos2d::CCTMXTiledMap* m_pMap;
};

#endif /* _TILED_MAP_COCOS2DX_H_ */
