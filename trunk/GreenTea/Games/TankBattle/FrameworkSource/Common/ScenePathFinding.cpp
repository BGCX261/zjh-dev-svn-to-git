//===========================================================
//
// FileName: ScenePathFinding.cpp
// Desc: Path Find
//
// Write by zjh 05/30/2001
//
//===========================================================

#include "ScenePathFinding.h"
#include "MapManager.h"

ScenePathFinding::ScenePathFinding()
{
	m_pMapDataPtr = NULL;
	m_nFirstGid = 0;
}


ScenePathFinding::~ScenePathFinding()
{
}


//===========================================================
//
// Desc: init
//
// [In]
// dwMapWidth  - the width of map
// dwMapHeight - the height of map
//
// [Out]
//
// [Return]
// TRUE  - succeed
// FALSE - failed
//
//===========================================================
bool ScenePathFinding::Initialize(
		const int32 nStartPosX,
		const int32 nStartPosY,
		const int32 nEndPosX,
		const int32 nEndPosY
		)
{
	// Get map detailed information
	cocos2d::CCTMXLayer *pObstacleLayer = MapManager::GetInstance()->GetObstacleLayer();
	if(NULL == pObstacleLayer)
		return false;

	cocos2d::CCSize layerSize = pObstacleLayer->getLayerSize();
	cocos2d::CCSize tileSize = pObstacleLayer->getMapTileSize();
	cocos2d::CCTMXTilesetInfo *pTileSetInfo = pObstacleLayer->getTileSet();

	m_nMapWidth = (uint32)layerSize.width;
	m_nMapHeight = (uint32)layerSize.height;
	m_pMapDataPtr = pObstacleLayer->getTiles();
	m_nFirstGid = pTileSetInfo->m_uFirstGid;

	// Call base class Initialize
	GTPathFinding::Initialize(
		nStartPosX,
		nStartPosY,
		nEndPosX,
		nEndPosY
		);

	return true;
}


//===========================================================
//
// Desc: release
//
// [In]
//
// [Out]
//
// [Return]
//
//===========================================================
void ScenePathFinding::Release( void )
{
	/*
	if( m_pMapData )
	{
		delete [] m_pMapData;
		m_pMapData = NULL;
	}

	m_dwMapWidth = 0;
	m_dwMapHeight = 0;
	*/

	m_pMapDataPtr = NULL;

	GTPathFinding::Release();

	return;
}
