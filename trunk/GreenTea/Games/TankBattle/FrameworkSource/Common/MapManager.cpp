#include "MapManager.h"
#include <GTInputManager.h>
#include <GTLog/GTLogManager.h>
#include "GameObjectCreation.h"

GTSINGLETON_IMP(MapManager);

const tchar *MapManager::m_sGroundLayer = CTEXT("GroundLayer");
const tchar *MapManager::m_sObjectLayer = CTEXT("ObjectLayer");
const tchar *MapManager::m_sObstacleLayer = CTEXT("ObstacleLayer");

MapManager::MapManager() : m_pMap(NULL)
{
}


MapManager::~MapManager()
{
}


// When the object is initialized, this method is called.
int32 MapManager::OnInitialize(void)
{
	return 1;
}


// When the system is updated, this method is called for each frame.
int32 MapManager::OnUpdate(void)
{
	return 1;
}


// This method is called for rendering each frame.
int32 MapManager::OnRender(void)
{
	return 1;
}


// Before the system is shut down, this method is called.
int32 MapManager::OnDestroy(void)
{
	return 1;
}


// Load a map from a tmxl/xml file
bool MapManager::LoadMap(const tchar* sName)
{
	if(NULL == sName)
	{
		return false;
	}

	m_pMap = GameObjectCreation::LoadMap(sName);
	if(NULL == m_pMap)
	{
		GTLogManager::GetInstance()->LogFormatError(CTEXT("Failed to load map [%s]"), sName);
		return false;
	}
	
	// Get map information
	cocos2d::CCTMXLayer *pGroundLayer = GetGroundLayer();
	if(NULL == pGroundLayer)
	{
		GTLogManager::GetInstance()->LogError(CTEXT("GroundLayer not found"));
		return false;
	}
	cocos2d::CCSize layerSize = pGroundLayer->getLayerSize();
	cocos2d::CCSize tileSize = pGroundLayer->getMapTileSize();
	m_MapSizeInTile = GTSize(layerSize.width, layerSize.height);
	m_MapTileSizeInPixel = GTSize(tileSize.width, tileSize.height);
	m_MapSizeInPixel = GTSize(
		m_MapSizeInTile.width * m_MapTileSizeInPixel.width,
		m_MapSizeInTile.height * m_MapTileSizeInPixel.height
		);

	// ObstacleLayer should be hidden because it's a helper layer.
	cocos2d::CCTMXLayer *pLayer = MapManager::GetInstance()->GetObstacleLayer();
	if(pLayer)
	{
		// Set obstacle layer invisible because this layer is helper layer.
		//pLayer->setVisible(false);
	}
	else
	{
		GTLogManager::GetInstance()->LogFormatError(CTEXT("Failed to find obstacle layer [scene name = %s]"), sName);
	}

	return true;
}


// Release the scene
void MapManager::ReleaseMap(void)
{
	/*
	if(m_pMap)
	{
		m_pMap->release();
		m_pMap = NULL;
	}
	*/
}
