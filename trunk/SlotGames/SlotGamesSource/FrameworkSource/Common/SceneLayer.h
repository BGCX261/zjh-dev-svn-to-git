#ifndef _SCENE_LAYER_H_
#define _SCENE_LAYER_H_

#include <GTBaseDef.h>

typedef uint16 LayerDataType;

class SceneLayer
{
public:
	SceneLayer();
	~SceneLayer();

public:
	LayerDataType* GetLayerData(void)
	{
		return m_pLayerData;
	}

	uint32 GetSceneWidth(void) const
	{
		return m_nSceneWidth;
	}

	uint32 GetSceneHeight(void) const
	{
		return m_nSceneHeight;
	}

	uint32 GetTileWidth(void) const
	{
		return m_nTileWidth;
	}

	uint32 GetTileHeight(void) const
	{
		return m_nTileHeight;
	}

	void GetName(tchar* szName) const
	{
		StringCopy(szName, m_szName);
	}

	const tchar* GetName(void) const
	{
		return m_szName;
	}

	// Create the layer with the width & height
	bool Create(
		const tchar* szName,
		const uint32 nWidth,
		const uint32 nHeight,
		const uint32 nTileWidth,
		const uint32 nTileHeight
		);
	// Release the layer
	void Release(void);

public:
	// Storing scene layer data using an uint32 array
	LayerDataType* m_pLayerData;
	// Layer name
	tchar m_szName[64];
	// Scene width & height, in tiles (M tiles x N tiles)
	uint32 m_nSceneWidth;
	uint32 m_nSceneHeight;
	// Tile width & height, in pixels (M pixels x N pixels)
	uint32 m_nTileWidth;
	uint32 m_nTileHeight;
};

#endif /* _SCENE_LAYER_H_ */
