#ifndef _COCOS2DX_GENERAL_H_
#define _COCOS2DX_GENERAL_H_

#include <GTBaseDef.h>
#include <GTSingleton.h>
#include "cocos2d.h"

class Cocos2dxGeneral : public GTSingleton<Cocos2dxGeneral>
{
private:
	// Default layer
	cocos2d::CCLayer *m_pDefaultLayer;
	// Default resources folder
	static const tchar* m_szDefaultResourcesFolder;

public:
	Cocos2dxGeneral();
	~Cocos2dxGeneral();

	// Set/Get default layer
	void SetDefaultLayer(cocos2d::CCLayer *pLayer)
	{
		m_pDefaultLayer = pLayer;
	}
	cocos2d::CCLayer* GetDefaultLayer()
	{
		return m_pDefaultLayer;
	}
	// Get default resources folder
	// Default resources folder
	const tchar* GetDefaultResourcesFolder()
	{
		return m_szDefaultResourcesFolder;
	}

	void SetDefault();

	// Exit cocos2d-x
	void Exit();

	void OnInitialize();
	void OnUpdate();
	void OnRender();
	void OnDestroy();
};

#endif /* _COCOS2DX_GENERAL_H_ */
