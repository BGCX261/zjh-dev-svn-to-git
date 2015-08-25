#include <GTGreenTea.h>

#include "AppDelegate.h"

#include "cocos2d.h"
#include "SimpleAudioEngine.h"
#include <cocos2dx-wrap/GameMainScene.h>
#include "AppMacros.h"

#include "CCEGLView.h"
#include "CCEGLViewProtocol.h"
// Game
#include <ScreenManager.h>
#include <cocos2dx-wrap/Cocos2dxGeneral.h>

USING_NS_CC;
using namespace CocosDenshion;

AppDelegate::AppDelegate()
{
}


AppDelegate::~AppDelegate()
{
}


bool AppDelegate::applicationDidFinishLaunching()
{
	// initialize director
	CCDirector *pDirector = CCDirector::sharedDirector();
	CCEGLView* pEGLView = CCEGLView::sharedOpenGLView();

	pDirector->setOpenGLView(pEGLView);
	CCSize frameSize = pEGLView->getFrameSize();

	// Set the design resolution
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT) || (CC_TARGET_PLATFORM == CC_PLATFORM_WP8)
    pEGLView->setDesignResolutionSize(designResolutionSize.width, designResolutionSize.height, kResolutionShowAll);
#else
    pEGLView->setDesignResolutionSize(designResolutionSize.width, designResolutionSize.height, kResolutionNoBorder);
#endif

	std::vector<std::string> searchPath;

    // In this demo, we select resource according to the frame's height.
    // If the resource size is different from design resolution size, you need to set contentScaleFactor.
    // We use the ratio of resource's height to the height of design resolution,
    // this can make sure that the resource's height could fit for the height of design resolution.

    // if the frame's height is larger than the height of medium resource size, select large resource.
	if (frameSize.height > mediumResource.size.height)
	{
        searchPath.push_back(largeResource.directory);

        pDirector->setContentScaleFactor(MIN(largeResource.size.height/designResolutionSize.height, largeResource.size.width/designResolutionSize.width));
	}
    // if the frame's height is larger than the height of small resource size, select medium resource.
    else if (frameSize.height > smallResource.size.height)
    {
        searchPath.push_back(mediumResource.directory);
        
        pDirector->setContentScaleFactor(MIN(mediumResource.size.height/designResolutionSize.height, mediumResource.size.width/designResolutionSize.width));
    }
    // if the frame's height is smaller than the height of medium resource size, select small resource.
	else
    {
        searchPath.push_back(smallResource.directory);

        pDirector->setContentScaleFactor(MIN(smallResource.size.height/designResolutionSize.height, smallResource.size.width/designResolutionSize.width));
    }

	searchPath.push_back("Resources");
	// set searching path
    CCFileUtils::sharedFileUtils()->setSearchPaths(searchPath);

	// Setup screen manager
	ScreenManager::GetInstance()->SetScreenSize((uint32)frameSize.width, (uint32)frameSize.height);

	/*
	// Setup directories
	cocos2d::TargetPlatform targetPlatform = getTargetPlatform();
	if(targetPlatform == cocos2d::kTargetIpad)
	{
		// iPad
		const uint32 nScreenW = 960;
		const uint32 nScreenH = 640;
		cocos2d::CCFileUtils::sharedFileUtils()->setResourceDirectory(Cocos2dxGeneral::GetInstance()->GetDefaultResourcesFolder());
		cocos2d::CCEGLView::sharedOpenGLView()->setDesignResolutionSize(nScreenW, nScreenH, kResolutionNoBorder);
		ScreenManager::GetInstance()->SetScreenSize(nScreenW, nScreenH);
	}
	else if(targetPlatform == cocos2d::kTargetIphone)
	{
		// iPhone
		// Try to enable retina on device
		if(true == cocos2d::CCDirector::sharedDirector()->enableRetinaDisplay(true))
		{
			// iPhone HD
			cocos2d::CCFileUtils::sharedFileUtils()->setResourceDirectory(Cocos2dxGeneral::GetInstance()->GetDefaultResourcesFolder());
		}
		else
		{
			cocos2d::CCFileUtils::sharedFileUtils()->setResourceDirectory(Cocos2dxGeneral::GetInstance()->GetDefaultResourcesFolder());
		}
	}
	else
	{
		const uint32 nScreenW = 480;
		const uint32 nScreenH = 320;
		// Windows, Android, Blackberry, Linux or Mac
		// Use 960x640 resources as design resolution size
		cocos2d::CCFileUtils::sharedFileUtils()->setResourceDirectory(Cocos2dxGeneral::GetInstance()->GetDefaultResourcesFolder());
		//cocos2d::CCEGLView::sharedOpenGLView()->setDesignResolutionSize(960, 640, kResolutionNoBorder);
		cocos2d::CCEGLView::sharedOpenGLView()->setDesignResolutionSize(480, 320, kResolutionNoBorder);
		ScreenManager::GetInstance()->SetScreenSize(nScreenW, nScreenH);
	}
	*/

	// enable High Resource Mode(2x, such as iphone4) and maintains low resource on other devices.
	// pDirector->enableRetinaDisplay(true);

	// sets opengl landscape mode
    // tests set device orientation in RootViewController.mm
    // pDirector->setDeviceOrientation(kCCDeviceOrientationLandscapeLeft);

	// turn on display FPS
    pDirector->setDisplayStats(true);

	// pDirector->setDeviceOrientation(kCCDeviceOrientationLandscapeLeft);

	// set FPS. the default value is 1.0/60 if you don't call this
    pDirector->setAnimationInterval(1.0 / 60);

	// create a scene. it's an autorelease object
	CCScene *pScene = GameMainScene::scene();

	// run the scene
	pDirector->runWithScene(pScene);

	return true;
}


// This function will be called when the app is inactive. When comes a phone call,it's be invoked too
void AppDelegate::applicationDidEnterBackground()
{
    CCDirector::sharedDirector()->pause();
    SimpleAudioEngine::sharedEngine()->pauseBackgroundMusic();
    SimpleAudioEngine::sharedEngine()->pauseAllEffects();
}


// this function will be called when the app is active again
void AppDelegate::applicationWillEnterForeground()
{
    CCDirector::sharedDirector()->resume();
    SimpleAudioEngine::sharedEngine()->resumeBackgroundMusic();
    SimpleAudioEngine::sharedEngine()->resumeAllEffects();
}
