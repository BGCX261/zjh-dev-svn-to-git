#include "Cocos2dxGeneral.h"
#include <GameFrame.h>

GTSINGLETON_IMP(Cocos2dxGeneral)

// Default resources folder
const tchar* Cocos2dxGeneral::m_szDefaultResourcesFolder = CTEXT("Resources");

Cocos2dxGeneral::Cocos2dxGeneral():
		m_pDefaultLayer(NULL)
{
}

Cocos2dxGeneral::~Cocos2dxGeneral()
{
}

void Cocos2dxGeneral::SetDefault()
{
}

// Exit cocos2d-x
void Cocos2dxGeneral::Exit()
{
	cocos2d::CCDirector::sharedDirector()->end();

    #if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
       exit(0);
    #endif
}

void Cocos2dxGeneral::OnInitialize()
{
	GameFrame::OnInitialize();
}

void Cocos2dxGeneral::OnUpdate()
{
	GameFrame::OnUpdate();
}

void Cocos2dxGeneral::OnRender()
{
	GameFrame::OnRender();
}

void Cocos2dxGeneral::OnDestroy()
{
	GameFrame::OnDestroy();
}
