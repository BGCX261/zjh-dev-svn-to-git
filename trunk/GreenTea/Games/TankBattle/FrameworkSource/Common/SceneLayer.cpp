#include "SceneLayer.h"

SceneLayer::SceneLayer()
{
	m_pLayerData = NULL;
	m_nSceneWidth = 0;
	m_nSceneHeight = 0;
	m_nTileWidth = 0;
	m_nTileHeight = 0;
}


SceneLayer::~SceneLayer()
{
}


// Create the layer with the width & height
bool SceneLayer::Create(const tchar* szName,
						const uint32 nWidth,
						const uint32 nHeight,
						const uint32 nTileWidth,
						const uint32 nTileHeight)
{
	if(NULL == szName || 0 == nWidth || 0 == nHeight || 0 == nTileWidth || 0 == nTileHeight)
	{
		return false;
	}

	// Allocate memory for layer data
	const uint32 nSize = nWidth * nHeight;
	m_pLayerData = new LayerDataType[nSize];
	if(NULL == m_pLayerData)
	{
		return false;
	}

	m_nSceneWidth = nWidth;
	m_nSceneHeight = nHeight;
	m_nTileWidth = nTileWidth;
	m_nTileHeight = nTileHeight;

	for(uint32 i=0; i<nSize; i++)
	{
		m_pLayerData[i] = 0;
	}

	StringCopy(m_szName, szName);

	return true;
}


void SceneLayer::Release(void)
{
	if(m_pLayerData)
	{
		delete [] m_pLayerData;
		m_pLayerData = NULL;
	}

	m_nSceneWidth = 0;
	m_nSceneHeight = 0;
	m_nTileWidth = 0;
	m_nTileHeight = 0;
}
