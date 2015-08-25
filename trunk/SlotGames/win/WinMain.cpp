#include "WinMain.h"
#include "../main/AppDelegate.h"
#include "CCEGLView.h"
#include "../main/AppMacros.h"

int APIENTRY _tWinMain(HINSTANCE hInstance,
					   HINSTANCE hPrevInstance,
					   LPTSTR    lpCmdLine,
					   int       nCmdShow)
{
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);

    // create the application instance
	AppDelegate app;
	cocos2d::CCEGLView* eglView = cocos2d::CCEGLView::sharedOpenGLView();
	eglView->setFrameSize(designResolutionSize.width, designResolutionSize.height);
	// If screen resolution is big use this factor to debug the app on desktop
	// The resolution of ipad3 is very large. In general, PC's resolution is smaller than it.
    // So we need to invoke 'setFrameZoomFactor'(only valid on desktop(win32, mac, linux)) to make the window smaller.
	eglView->setFrameZoomFactor(0.75f);
	//eglView->setFrameZoomFactor(1.0f);

    return cocos2d::CCApplication::sharedApplication()->run();
}
