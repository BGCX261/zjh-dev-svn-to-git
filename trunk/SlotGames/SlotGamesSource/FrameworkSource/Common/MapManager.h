#ifndef _MAP_MANAGER_H_
#define _MAP_MANAGER_H_

#include <GTGameObject.h>
#include <GTSingleton.h>
#include <cocos2d.h>
#include <GTPoint2.h>
#include <GTSize.h>
#include <Map/TiledMap.h>
#include <Map/TiledMapLayer.h>
#include <Map/TiledMapObjectGroup.h>

//class MapManager : public GTGameObject, public GTSingleton<MapManager>
class MapManager : public GTSingleton<MapManager>
{
public:
	MapManager();
	~MapManager();

	// When the object is initialized, this method is called.
	virtual int32 OnInitialize(void);

	// When the system is updated, this method is called for each frame.
	virtual int32 OnUpdate(void);

	// This method is called for rendering each frame.
	virtual int32 OnRender(void);

	// Before the system is shut down, this method is called.
	virtual int32 OnDestroy(void);

	// Load a map from a file
	bool LoadMap(const tchar* sName);
	// Release the scene
	void ReleaseMap(void);

	void SetMap(cocos2d::CCTMXTiledMap *pMap)
	{
		DBG_ASSERT(pMap);
		m_pMap = pMap;
	}

	// SetPosition is to put the screen origin (0, 0) to the map position (x, y)
	// in map coordinate system.
	//
	// The map origin position (0, 0) is at left-bottom in map coordinate system.
	void SetPosition(const float x, const float y)
	{
		DBG_ASSERT(m_pMap);
		//m_pMap->SetPosition(x, y);
		m_pMap->setPosition(cocos2d::CCPoint((float)x, (float)y));
	}

	void SetPosition(const GTPoint2 pos)
	{
		DBG_ASSERT(m_pMap);
		//m_pMap->SetPosition(pos.x, pos.y);
		m_pMap->setPosition(cocos2d::CCPoint(pos.x, pos.y));
	}

	// GetPosition is to put the screen origin (0, 0) to the map position (x, y)
	// in map coordinate system.
	GTPoint2 GetPosition() const
	{
		DBG_ASSERT(m_pMap);
		//return m_pMap->GetPosition();
		cocos2d::CCPoint pt = m_pMap->getPosition();
		return GTPoint2(pt.x, pt.y);
	}

	// Get a tile layer specified by szName
	cocos2d::CCTMXLayer* GetTileLayer(const tchar* szName)
	{
		DBG_ASSERT(szName);
		DBG_ASSERT(m_pMap);
		return m_pMap->layerNamed(szName);
	}

	// Get an object group layer specified by szName
	cocos2d::CCTMXObjectGroup* GetObjectLayer(const tchar* szName)
	{
		DBG_ASSERT(szName);
		DBG_ASSERT(m_pMap);
		return m_pMap->objectGroupNamed(szName);
	}

	// Get map ground layer
	cocos2d::CCTMXLayer* GetGroundLayer()
	{
		return GetTileLayer(MapManager::m_sGroundLayer);
	}

	// Get map obstacle layer
	cocos2d::CCTMXLayer* GetObstacleLayer()
	{
		return GetTileLayer(MapManager::m_sObstacleLayer);
	}

	// Get objects layer customized by the user
	cocos2d::CCTMXObjectGroup* GetUserObjectLayer()
	{
		return GetObjectLayer(MapManager::m_sObjectLayer);
	}

	// Get map size in tiles
	GTSize GetMapSizeInTile(void) const
	{
		return m_MapSizeInTile;
	}
	// Get map tile size in pixels
	GTSize GetMapTileSizeInPixel(void) const
	{
		return m_MapTileSizeInPixel;
	}
	// Get map size in pixels
	GTSize GetMapSizeInPixel(void) const
	{
		return m_MapSizeInPixel;
	}

	// Get tile center position from (x, y)
	GTPoint2 GetTileCenterPositionFromMapPosition(const float x, const float y)
	{
		return GTPoint2(
			((float)((int32)(x / m_MapTileSizeInPixel.width)) * m_MapTileSizeInPixel.width) + (m_MapTileSizeInPixel.width / 2.0f),
			((float)((int32)(y / m_MapTileSizeInPixel.height)) * m_MapTileSizeInPixel.height) + (m_MapTileSizeInPixel.height / 2.0f)
			);
	}
	// Get tile center position from tile block
	GTPoint2 GetTileCenterPositionFromTileBlock(const float blockX, const float blockY)
	{
		return GTPoint2(
			blockX * m_MapTileSizeInPixel.width + m_MapTileSizeInPixel.width / 2.0f,
			blockY * m_MapTileSizeInPixel.height + m_MapTileSizeInPixel.height / 2.0f
			);
	}
	// Get tile block
	GTPoint2 GetTileBlock(const float x, const float y)
	{
		return GTPoint2(
			(float)((int32)(x / m_MapTileSizeInPixel.width)),
			(float)((int32)(y / m_MapTileSizeInPixel.height))
			);
	}

public:
	// Ground layer name
	static const tchar *m_sGroundLayer;
	// Obstacle layer name
	static const tchar *m_sObstacleLayer;
	// Object layer name
	static const tchar *m_sObjectLayer;	

private:
	// Map instance pointer
	//TiledMap* m_pMap;
	cocos2d::CCTMXTiledMap* m_pMap;
	// Map size in tiles
	GTSize m_MapSizeInTile;
	// Map tile size in pixels
	GTSize m_MapTileSizeInPixel;
	// Map size in pixels
	GTSize m_MapSizeInPixel;
};

#endif /* _MAP_MANAGER_H_ */
