#include "GameMainScene.h"
#include "Cocos2dxGeneral.h"
#include "../GameObjectCreation.h"
#include <GTLog/GTLogManager.h>
#include "../SceneManager.h"
#include "../InputManager.h"
#include "../UI/UIWidget.h"

USING_NS_CC;

GameMainScene::GameMainScene()
{
}


CCScene* GameMainScene::scene()
{
	// 'scene' is an autorelease object
	CCScene *scene = CCScene::create();
	
	// 'layer' is an autorelease object
	GameMainScene *layer = GameMainScene::create();

	// add layer as a child to scene
	scene->addChild(layer);
	
	// return the scene
	return scene;
}


// on "init" you need to initialize your instance
bool GameMainScene::init()
{
	// The layer initialization
	if ( !CCLayer::init() )
	{
		return false;
	}

	// Initialize global settings
	Cocos2dxGeneral::GetInstance()->SetDefault();
	Cocos2dxGeneral::GetInstance()->SetDefaultLayer(this);
	Cocos2dxGeneral::GetInstance()->OnInitialize();
	
	// ask director the window size
	CCSize size = CCDirector::sharedDirector()->getWinSize();

	// Setup update
	this->schedule(schedule_selector(GameMainScene::update));
	
	return true;
}

void GameMainScene::onEnter()
{
	CCLayer::onEnter();

	CCLayer::setTouchEnabled(true);
}

void GameMainScene::onEnterTransitionDidFinish()
{
	CCLayer::onEnterTransitionDidFinish();
}

void GameMainScene::onExit()
{
	Cocos2dxGeneral::GetInstance()->OnDestroy();

	CCLayer::onExit();
}

void GameMainScene::update(float dt)
{
	Cocos2dxGeneral::GetInstance()->OnUpdate();
}

void GameMainScene::registerWithTouchDispatcher()
{
    CCDirector::sharedDirector()->getTouchDispatcher()->addTargetedDelegate(this, 0, false);
}

bool GameMainScene::ccTouchBegan(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent)
{
	//GTLogManager::GetInstance()->LogTrace(CTEXT("ccTouchBegan"));

	CC_UNUSED_PARAM(pTouch);
    CC_UNUSED_PARAM(pEvent);

	// Get the touch position on the screen
	// The original (0, 0) is at left-bottom of the screen
	
	m_tBeginPos = pTouch->getLocation();
		
	// Notify input manager
	InputManager::GetInstance()->OnSingleClickEvent(UIWidget::Flag_ClickDown, GTPoint2(m_tBeginPos.x, m_tBeginPos.y));

	/*
	// For testing purpose
	GTLogManager::GetInstance()->LogFormatTrace(CTEXT("x = %f, y = %f"), m_tBeginPos.x, m_tBeginPos.y);

	cocos2d::CCTMXLayer *pGroundLayer = MapManager::GetInstance()->GetGroundLayer();
	cocos2d::CCTMXLayer *pObstacleLayer = MapManager::GetInstance()->GetObstacleLayer();
	//pGroundLayer = pObstacleLayer;
	if(pGroundLayer != NULL)
	{
		cocos2d::CCTMXTilesetInfo *pTileSetInfo = pGroundLayer->getTileSet();
		GTPoint2 position = SceneManager::GetInstance()->GetPosition();
		cocos2d::CCSize layerSize = pGroundLayer->getLayerSize();
		cocos2d::CCSize tileSize = pGroundLayer->getMapTileSize();
		const uint32 *ptr = pGroundLayer->getTiles();
		uint32 x = (uint32)((position.x + m_tBeginPos.x) / tileSize.width);
		uint32 y = (uint32)((position.y + m_tBeginPos.y) / tileSize.height);
		//unsigned int tileIndex = ptr[y*(uint32)layerSize.width + x];
		// Left-top is original position of the screen coordinate system
		uint32 nTileIndex = ptr[(uint32)(layerSize.height-1-y)*(uint32)layerSize.width + x];
		nTileIndex = nTileIndex ? (nTileIndex - pTileSetInfo->m_uFirstGid) : nTileIndex;
		GTLogManager::GetInstance()->LogFormatTrace(CTEXT("Ground = %d"), nTileIndex);
	}
	else
	{
		GTLogManager::GetInstance()->LogTrace(CTEXT("Failed to find GroundLayer"));
	}
	*/

	return true;
}

void GameMainScene::ccTouchMoved(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent)
{
	//GTLogManager::GetInstance()->LogTrace(CTEXT("ccTouchMoved"));

	CC_UNUSED_PARAM(pTouch);
    CC_UNUSED_PARAM(pEvent);
	
	CCPoint touchLocation = pTouch->getLocation();
	CCPoint prevLocation = pTouch->getPreviousLocation();

	CCPoint diff = ccpSub(touchLocation, prevLocation);
	
	// Notify input manager
	InputManager::GetInstance()->OnMoveEvent(0, GTPoint2(diff.x, diff.y));
		
	return;
}

void GameMainScene::ccTouchEnded(CCTouch* pTouch, CCEvent* pEvent)
{
	//GTLogManager::GetInstance()->LogTrace(CTEXT("ccTouchEnded"));

	CC_UNUSED_PARAM(pTouch);
    CC_UNUSED_PARAM(pEvent);

	m_tBeginPos = pTouch->getLocation();
	// Notify input manager
	InputManager::GetInstance()->OnSingleClickEvent(UIWidget::Flag_ClickUp, GTPoint2(m_tBeginPos.x, m_tBeginPos.y));
}

void GameMainScene::ccTouchCancelled(CCTouch* pTouch, CCEvent* pEvent)
{
	//GTLogManager::GetInstance()->LogTrace(CTEXT("ccTouchCancelled"));
}
