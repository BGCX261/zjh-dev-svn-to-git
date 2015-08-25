#include "TestManager.h"
#include <GTFileUtil.h>
#include <GTLog/GTLogManager.h>
#include "../Common/MapManager.h"
#include <UI/UILabelBMFont.h>
#include <cocos2dx-wrap/UILabelBMFontCocos2dx.h>
#include <AudioManager.h>
#include <cocos2dx-wrap/Cocos2dxGeneral.h>
#include <SceneManager.h>
#include <GTGameObjectManager.h>
#include <GTTweener2D.h>
#include "../UI/UIBaseDef.h"
#include <GTNew.h>
#include <GTUtil.h>
#include <GTDynamicBuffer.h>
#include <GTEventManager.h>
#include <GTCommandManager.h>
#include <GameObjectCreation.h>
#include <GameObjectSprite.h>
#include <AssetManager.h>
#include <algorithm>

USING_NS_CC;

SINGLETON_IMP(TestManager);

TestManager::TestManager()
{
}

TestManager::~TestManager()
{
}

void TestFileUtil()
{
	unsigned long size = 0;
	char* pContent = (char*)GTFileUtil::ReadTextFileData(CTEXT("sprites/JiaXuRun.property"), &size);
	if(pContent)
	{
		GTTreeNode* tn = GTTreeNode::FromString(pContent);
		if(tn)
		{
			tn->Release();
		}

		delete[] pContent;
		pContent = NULL;
	}
}

void TestStringUtil()
{
	/*
	GTString sint16 = GTString::ToString((int16)1);
	GTString suint16 = GTString::ToString((uint16)2);
	GTString sint32 = GTString::ToString((int32)2111);
	GTString suint32 = GTString::ToString((uint32)2333);
	GTString sfloat = GTString::ToString((float)78.12f);
	*/

	/*
	GTString source = CTEXT("   123abc") + GTString(CTEXT('\r'));
	GTString source2 = CTEXT("123abc");
	GTString right = source.TrimRight();
	GTString left = source2.TrimLeft();
	GTString both = source.TrimRight().TrimLeft();
	*/

	/*
	// Doulbe slashes
	GTString source1 = CTEXT("  // This is a comment 1");
	GTString source2 = CTEXT(" Value = 10  // This is a comment 2");
	GTString source3 = CTEXT("// This is a comment 1");
	GTString result1 = GTStringUtil::StripDoubleSlashComments(source1);
	GTString result2 = GTStringUtil::StripDoubleSlashComments(source2);
	GTString result3 = GTStringUtil::StripDoubleSlashComments(source3);
	int32 length3 = result3.Length();
	*/

	// Block comments
	//GTString source1 = CTEXT("  /* This is a comment 1 */");
	//GTString source2 = CTEXT(" Value = 10  /* This is a comment 2 */");
	//GTString source3 = CTEXT("/* This is a comment 1 */");
	//GTString result1 = GTStringUtil::StripBlockComments(source1);
	//GTString result2 = GTStringUtil::StripBlockComments(source2);
	//GTString result3 = GTStringUtil::StripBlockComments(source3);

	/*
	GTString source1 = CTEXT("123=abc==xyz");
	GTArray<GTString> result1;
	GTStringUtil::Split(source1, CTEXT('='), result1, GTStringUtil::RemoveEmptyEntries);
	*/

	/*
	GTString test = CTEXT("ABC123xyZ");
	test.ToLower();
	test.ToUpper();
	*/

	GTString src1 = GTString(CTEXT("1,2,4,0,10"));
	GTString src2 = GTString(CTEXT("1, 2,4 ,0, 10"));
	GTArray<int32> gtai1;
	GTUtil::StringToArrayInt(gtai1, src1);
	GTArray<int32> gtai2;
	GTUtil::StringToArrayInt(gtai2, src2);

	GTString sFormatFloat = GTString::Format(CTEXT("Vector2=(%f,%f)"), 2.4f, 67.89f);
	GTString sFormatInt = GTString::Format(CTEXT("Vector2=(%d,%d)"), 24, 6789);
}

void TestGTDictionary()
{
	/*
	GTArray<int32> gta;
	gta.Add(10);
	gta.Add(30);
	gta.Add(20);
	gta[1] = 50;
	*/

	GTDictionary<int32, GTString> dicInt;
	dicInt.Add(1, "a");
	dicInt.Add(2, "b");
	dicInt.Add(3, "c");
	GTString r2 = dicInt[2];
	//dicInt[20] = "z";
	dicInt[3] = "z";
	dicInt.ChangeValueByKey(3, GTString("yyy"));
	GTString sValueResult;
	dicInt.GetValueByKey(3, sValueResult);

	/*
	std::map<int, std::string> stlMap;
	stlMap.insert(std::pair<int, std::string>(1, "a"));
	stlMap.insert(std::pair<int, std::string>(2, "b"));
	stlMap.insert(std::pair<int, std::string>(3, "c"));
	std::string r1 = stlMap[2];
	stlMap[20] = CTEXT("e");
	*/

	/*
	std::map<std::string, std::string> stlMapStr;
	stlMapStr.insert(std::pair<int, std::string>("1", "a"));
	stlMapStr.insert(std::pair<int, std::string>("2", "b"));
	stlMapStr["2"] = "e";
	*/

	GTDictionary<GTString, GTString> dicString;
	GTString key1 = CTEXT("1");
	GTString key2 = CTEXT("2");
	GTString key3 = CTEXT("3");
	dicString.Add(key1, GTString(CTEXT("abcx")));
	dicString.Add(key2, GTString(CTEXT("abcy")));
	dicString.Add(key3, GTString(CTEXT("abcz")));

	GTString vResult;
	dicString.GetValueByKey(CTEXT("2"), vResult);
	dicString.ChangeValueByKey(CTEXT("2"), GTString("gtString"));

	int32 nCount = dicString.Count();
	//
	bool exits = dicString.KeyExists(key2);
	//
	GTString value;
	dicString.GetValueByKey(key3, value);
	//
	dicString.Remove(key2);
	//
	for(GTDictionary<GTString, GTString>::ObjectTypeIterator it = dicString.Begin();
		it != dicString.End();
		it++)
	{
		GTLogManager::GetInstance()->LogFormatComment(CTEXT("Key = %s, Value = %s"), (*it).first.ToCharString(), (*it).second.ToCharString());
	}

	//GTDictionary<GTString, GTString> dicString2 = dicString;
}

void TestGTBehaviourClassManager()
{
	GTBehaviour* pBehaviour = GTBehaviourClassManager::GetInstance()->CreateClassInstance(CTEXT("GScriptTweener"));
	if(pBehaviour)
	{
		pBehaviour->Release();
		pBehaviour = NULL;
	}
}

void TestTMXObjectLayer()
{
	cocos2d::CCTMXObjectGroup* pObjectGroup = MapManager::GetInstance()->GetUserObjectLayer();
	if(NULL == pObjectGroup)
	{
		return;
	}

	cocos2d::CCArray* pObjects = pObjectGroup->getObjects();
	if(pObjects)
	{
		cocos2d::CCDictionary* pContent = NULL;
		cocos2d::CCObject* pObj = NULL;
		CCARRAY_FOREACH(pObjects, pObj)
		{
			pContent = (cocos2d::CCDictionary*)pObj;
			if(pContent)
			{
				cocos2d::CCString *sName = (cocos2d::CCString*)pContent->objectForKey(std::string("name"));
				cocos2d::CCString *sType = (cocos2d::CCString*)pContent->objectForKey(std::string("type"));
				cocos2d::CCString *sX = (cocos2d::CCString*)pContent->objectForKey(std::string("x"));
				cocos2d::CCString *sY = (cocos2d::CCString*)pContent->objectForKey(std::string("y"));
				cocos2d::CCString *sWidth = (cocos2d::CCString*)pContent->objectForKey(std::string("width"));
				cocos2d::CCString *sHeight = (cocos2d::CCString*)pContent->objectForKey(std::string("height"));
				cocos2d::CCString *sProperty = (cocos2d::CCString*)pContent->objectForKey(std::string("PropertyFile"));
			}
		}
	}
}

UILabelBMFont* m_pUILabelBMFont1 = NULL;
UILabelBMFont* m_pUILabelBMFont2 = NULL;
void TestUILabelBMFont()
{
	// This cpp must be saved as UTF-8 then all Chinese characters will display correctly.
	//m_pUILabelBMFont1 = new UILabelBMFontCocos2dx();
	m_pUILabelBMFont1 = GameObjectCreation::CreateUILabelBMFont();
	//m_pUILabelBMFont1->Initialize(CTEXT("fonts/BookshelfSymbol7_32_Bold_Gradient.fnt"));
	//m_pUILabelBMFont1->SetText(CTEXT("Font Sample"));
	//m_pUILabelBMFont1->Initialize(CTEXT("fonts/MicrosoftYahei_32_Bold_Gradient.fnt"));
	//m_pUILabelBMFont1->Initialize("fonts/bitmapFontChinese.fnt");
	//m_pUILabelBMFont1->SetText("Settings 1");
	//m_pUILabelBMFont1->Initialize("Game Setting", "fonts/bitmapFontChinese.fnt");
	m_pUILabelBMFont1->Initialize(CTEXT("中国"), CTEXT("fonts/bitmapFontChinese.fnt"), 50);
	//m_pUILabelBMFont1->SetText("Settings 1 ");
	//m_pUILabelBMFont1->SetText("中国");
	m_pUILabelBMFont1->SetPosition(160.0f, 160.0f);

	//m_pUILabelBMFont2 = new UILabelBMFontCocos2dx();
	m_pUILabelBMFont2 = GameObjectCreation::CreateUILabelBMFont();
	m_pUILabelBMFont2->Initialize(CTEXT("fonts/BitmapFont28.fnt"), 50);
	//m_pUILabelBMFont2->SetText(CTEXT("Font Sample"));
	m_pUILabelBMFont2->SetText(CTEXT("Settings 2"));
	m_pUILabelBMFont2->SetPosition(160.0f, 100.0f);
}

void TestVisualLeakDetector(void)
{
	int32* ptr = new int[32];
	if(ptr)
	{
		delete[] ptr;
	}
}

void TestJSScriptEngine(void)
{
	/*
	unsigned long size = 0;
	char* pContent = (char*)FileUtil::ReadTextFileData(CTEXT("javascript/TestSample.js"), &size);
	if(pContent)
	{
		GTScriptEngine::GetInstance()->Initialize();
		GTScriptEngine::GetInstance()->RunScript(pContent);
		//GTScriptEngine::GetInstance()->RunScript("var s = '123'; GTLogManager.LogTrace(var);");
		//GTScriptEngine::GetInstance()->RunScript("var r = 1 + 5;");
		//GTScriptEngine::GetInstance()->RunScript("var today = Date(); today.toString();");
		GTScriptEngine::GetInstance()->Destroy();

		// Release pContent
		delete[] pContent;
		pContent = NULL;
	}
	*/
}

void TestAudioManager(void)
{
	//AudioManager::GetInstance()->LoadBackgroundMusic(CTEXT("sounds/battle_bgm_01.mp3"));	
	//AudioManager::GetInstance()->PauseBackgroundMusic();
	//AudioManager::GetInstance()->ResumeBackgroundMusic();
	//AudioManager::GetInstance()->PlayBackgroundMusic(CTEXT("sounds/battle_bgm_01.mp3"), true);

	AudioManager::GetInstance()->SetBackgroundMusicVolume(0.5f);
	AudioManager::GetInstance()->SetEffectVolume(0.5f);
}

//CCSprite* m_grossini = NULL;
void TestCocos2dx(void)
{
	/*
	CCMenuItemImage *pCloseItem = CCMenuItemImage::create(
		"huopen.png",
		"huopen.png");

	CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
	CCPoint origin = CCDirector::sharedDirector()->getVisibleOrigin();
	pCloseItem->setPosition(ccp(200, 200));

	// create menu, it's an autorelease object
	CCMenu* pMenu = CCMenu::create(pCloseItem, NULL);
	pMenu->setPosition(CCPointZero);
	Cocos2dxGeneral::GetInstance()->GetDefaultLayer()->addChild(pMenu, 999);

	//CCSpriteFrameCache *cache = CCSpriteFrameCache::sharedSpriteFrameCache();
	//cache->addSpriteFramesWithFile("Resources/sprites/grossini.plist");

	*/

	/*
	return;
	CCAnimation* animation = CCAnimation::create();
    for( int i=1;i<15;i++)
    {
        char szName[100] = {0};
        sprintf(szName, "images/grossini_dance_%02d.png", i);
        animation->addSpriteFrameWithFileName(szName);
    }
    // should last 2.8 seconds. And there are 14 frames.
    animation->setDelayPerUnit(2.8f / 14.0f);
    animation->setRestoreOriginalFrame(true);

    CCAnimate* action = CCAnimate::create(animation);
	CCSprite* m_grossini = CCSprite::createWithSpriteFrameName("grossini_dance_01.png");
	m_grossini->runAction(CCSequence::create(action, action, NULL));
    //m_grossini->runAction(CCSequence::create(action, action->reverse(), NULL));

	Cocos2dxGeneral::GetInstance()->GetDefaultLayer()->addChild(m_grossini, 1);

	//CCSpriteFrameCache *cache = CCSpriteFrameCache::sharedSpriteFrameCache();
    //cache->addSpriteFramesWithFile("Resources/sprites/grossini.plist");
	*/
}

void TestGameObject()
{
	/*
	// Create a GTGameObject with specified name
	GTGameObject* pChild = GameObjectManager::Inst()->CreateGameObject(NULL, "goTest");
	if(pChild)
	{
		// Attach a sprite to this game object
		SceneManager::Inst()->IntializeGameObject(pChild, "sprites/baoxiang.property");
		GTBehaviour* pb = pChild->AddBehaviour("BSTweener2D");
		pChild->RemoveBehaviour("BSTweener2D");
	}
	*/

	/*
	GTGameObject* pGameObject = GTGameObjectManager::Inst()->CreateGameObject(NULL, CTEXT("goTest"), CTEXT("sprites/baoxiang.property"));
	GTGameObjectManager::Inst()->DestroyGameObject(pGameObject);
	pGameObject = NULL;
	*/

	//GTGameObject* pGameObject = GTGameObjectManager::Inst()->CreateGameObject(NULL, CTEXT("goSprite1"), CTEXT("sprites/baoxiang.property"));
	//GTGameObject* pGameObject = GTGameObjectManager::Inst()->CreateGameObject(NULL, CTEXT("goSprite1"), CTEXT("sprites/baoxiang-test.property"));
	//GTGameObject* pGameObject = GTGameObjectManager::Inst()->CreateGameObject(NULL, CTEXT("goSprite1"), CTEXT("sprites/Marine.property"));
	//GTGameObject* pGameObject = GTGameObjectManager::Inst()->CreateGameObject(NULL, CTEXT("goSprite1"), CTEXT("sprites/weapon-02-zz1.property"));
	GameObjectSprite* pGameObject = AssetManager::Inst()->CreateGameObject<GameObjectSprite>(CTEXT("sprites/baoxiang.property"), CTEXT("goSprite1"), NULL);
	if(pGameObject)
	{
		pGameObject->SetPosition(200, 200);
		pGameObject->SetZOrder(10);
		pGameObject->PlayAnimationByIndex(0, GSpriteAnimation::PlayMode_Loop);
		// Clone
		GameObjectSprite* pGameObjectCopy = AssetManager::Inst()->CreateGameObject<GameObjectSprite>(CTEXT("sprites/baoxiang.property"), CTEXT("goSprite1Clone"), NULL);
		if(pGameObjectCopy)
		{
			pGameObjectCopy->SetPosition(280, 200);
			pGameObjectCopy->SetZOrder(10);
			pGameObjectCopy->PlayAnimationByIndex(0, GSpriteAnimation::PlayMode_Loop);
		}
		/*
		// Clone
		GameObjectSprite* pGameObjectCopy = dynamic_cast<GameObjectSprite*>(pGameObject->Clone(CTEXT("goSprite1Copy"), NULL));
		if(pGameObjectCopy)
		{
			pGameObjectCopy->SetPosition(280, 200);
			//pGameObjectCopy->SetZOrder(10);
			pGameObjectCopy->PlayAnimationByIndex(0, GSpriteAnimation::PlayMode_Loop);
		}
		*/
	}
}

void TestTweener(void)
{
	const int from = 0;
	const int change = 20;
	float result;
	float factor;
	for(int i=from; i<(from+change); i++)
	{
		factor = (float)(i-from)/(float)change;
		result = GTTweenInterpolation::BackEaseInOut(from, change, factor);
		//GTLogManager::SLogFormatTrace("i=%d, factor=%f, result=%f", i, factor, result);
		GTLogManager::SLogFormatTrace("%d,%f,%f", i, factor, result);
	}	
}

void TestNew()
{
	int32* ptr = new int32[10];
	delete [] ptr;
}

bool MyCompFunction1 (int i,int j) { return (i<j); }
bool MyCompFunction2 (int i,int j) { return (i>j); }

void TestGenerals()
{
	/*
	GTDynamicBuffer<char> db(256);
	strcpy(db.m_pBuffer, "qwertyuiop");
	GTDynamicBuffer<char> db2 = db;
	db2.Resize(1024);
	db2.Release();
	*/

	//std::string strTest("22222");
	//char* ptrTest = strTest.c_str();;

	// GT
	GTList<int32> lst;
	lst.AddToTail(100);
	lst.AddToTail(50);
	lst.AddToTail(200);
	lst.AddToTail(4);
	//lst.Sort();
	//lst.Sort(MyCompFunction1);
	lst.Sort(MyCompFunction2);
	GTString str0 = lst.ToString();
	GTLogManager::SLogFormatTrace(CTEXT("GTList.ToString: %s"), (const tchar*)lst.ToString());

	GTArray<int32> arr;
	arr.Add(100);
	arr.Add(50);
	arr.Add(200);
	arr.Add(4);
	//GTAlgorithmSort(arr.Begin(), arr.End(), MyCompFunction2);
	//GTAlgorithmSort(arr.Begin() + 2, arr.End(), MyCompFunction1);
	GTAlgorithmSort(arr.Begin() + 2, arr.End());
	GTString str1 = arr.ToString();

	// STL
	//std::list<int32> stlLst;
	std::vector<int32> stlLst;
	stlLst.push_back(100);
	stlLst.push_back(50);
	stlLst.push_back(200);
	stlLst.push_back(4);
	stlLst[2] = 10;
	//lst.sort();
	//lst.sort(lst.end());
	//std::sort(lst.begin()+2, lst.end());
	//std::sort(lst.begin(), lst.end(), MyCompFunction2);
	//stlLst.sort(MyCompFunction2);
	//std::sort

	int32 intArray[] = { 12, 44, 78, 2, 0 };
	GTArray<int32> gtArray(intArray, 5);
	gtArray[0] = 123;
	gtArray[1] = 23;
	gtArray[4] = 231;
	const int32 n = 3;
	gtArray[n] = 4;
	GTLogManager::SLogFormatTrace(CTEXT("GTArray.ToString: %s"), (const tchar*)gtArray.ToString());

	GTArray<int32> gtArray2(4);
	const int32 size2 = gtArray2.Length();
	gtArray2[2] = 20;
	//
	GTArray<int32> gtArray3;
	gtArray3.Reserve(6);
	const int32 size3 = gtArray3.Length();
	gtArray3[0] = 0;
	gtArray3[5] = 50;
	//
	GTArray<int32>* gtArray4 = new GTArray<int32>();
	gtArray4->Add(1);
	gtArray4->Add(2);
	gtArray4->Add(3);
	GTArray<int32>* gtArray5 = new GTArray<int32>();
	gtArray5->Add(10);
	gtArray5->Add(20);
	gtArray5->Add(30);
	GTDictionary<int32, GTArray<int32>*> dic;
	dic.Add(1, gtArray4);
	dic.Add(2, gtArray5);
	GTArray<int32>* gta1 = NULL;
	GTArray<int32>* gta2 = NULL;
	dic.GetValueByKey(1, gta1);
	dic.GetValueByKey(2, gta2);
	delete gtArray4;
	delete gtArray5;
}

void TestDevTest()
{
	UIWidget* pWidgetInfo = UIManager::GetInstance()->LoadLayout(CTEXT("ui/devtest/devtest.uilayout"));
}

bool TestManager::UIWidgetEventSingleClick(UIWidget* pWidget, uint32 nFlags, void *pParam)
{
	if(nFlags & UIWidget::Flag_ClickUp)
	{
		GTLogManager::SLogTrace(CTEXT("ButtonTest4 clicked"));

		UIWidget* pRootWidget = UIManager::Inst()->GetRootWidget();
		UIWidget* pDevTest = pRootWidget->FindChildByName(CTEXT("DevTestUI"));
		UIWidget* pBtnTest4 = pDevTest->FindChildById(1007);
		if(pBtnTest4)
		{
			//pBtnTest4->RemoveEventListener(UIWidgetEvent::EventTypeSingleClick, CTEXT("btnTest4Click"));
			GTEventManager::Inst()->Invoke("testEvent1");
		}
	}
	return true;
}

void TestUI(TestManager* tm)
{
	UIWidget* pWidget = UIManager::GetInstance()->LoadLayout(CTEXT("ui/devtest/devtest.uilayout"));
	UIWidget* pRootWidget = UIManager::Inst()->GetRootWidget();
	UIWidget* pDevTest = pRootWidget->FindChildByName(CTEXT("DevTestUI"));
	UIWidget* pBtnTest4 = pDevTest->FindChildById(1007);
	if(pBtnTest4)
	{
		pBtnTest4->AddEventListener(
			UIWidgetEvent::EventTypeSingleClick,
			CTEXT("btnTest4Click"),
			tm,
			UIWidget_EventCallback_Set(TestManager::UIWidgetEventSingleClick),
			NULL);
	}
}

// Events
bool TestManager::EventManagerCallback1(void *pParam)
{
	GTLogManager::SLogTrace("TestManager::EventManagerCallback1");
	return true;
	//return false;
}
bool TestManager::EventManagerCallback2(void *pParam)
{
	GTLogManager::SLogTrace("TestManager::EventManagerCallback2");
	return true;
	//return false;
}

void TestEvent(TestManager* tm)
{
	// Add event listners
	GTEventManager::Inst()->AddListener("testEvent", tm,
		GTObject_EventCallback2_Set(TestManager::EventManagerCallback1), NULL, 3);
	GTEventManager::Inst()->AddListener("testEvent", tm,
		GTObject_EventCallback2_Set(TestManager::EventManagerCallback2), NULL, 2);
	GTEventManager::Inst()->AddListener("testEvent", tm,
		GTObject_EventCallback2_Set(TestManager::EventManagerCallback2), NULL, 1);

	/*
	GTCommandManager::Inst()->AddCommand("testEvent", 1);
	GTCommandManager::Inst()->AddCommand("testEvent2", 2);
	GTCommandManager::Inst()->AddCommand("testEvent3", 3);
	*/

	//
	//GTEventManager::Inst()->RemoveListener("testEvent", tm, GTObject_EventCallback2_Set(TestManager::EventManagerCallback1));
	//GTEventManager::Inst()->RemoveListener("testEvent", tm, GTObject_EventCallback2_Set(TestManager::EventManagerCallback2));
	/*
	GTEventManager::Inst()->AddListener("testEvent", tm,
		GTObject_EventCallback2_Set(TestManager::EventManagerCallback1), NULL);
		*/

	UIWidget* pRootWidget = UIManager::Inst()->GetRootWidget();
	UIWidget* pDevTest = pRootWidget->FindChildByName(CTEXT("DevTestUI"));
	if(pDevTest)
	{
		UIWidget* pBtnTest4 = pDevTest->FindChildById(1007);
		if(pBtnTest4)
		{
			/*
			pBtnTest4->AddEventListener(
				UIWidgetEvent::EventTypeSingleClick,
				CTEXT("btnTest4Click"),
				tm,
				UIWidget_EventCallback_Set(TestManager::UIWidgetEventSingleClick),
				NULL);
				*/
		}
	}
}

// When the object is initialized, this method is called.
int32 TestManager::OnInitialize(void)
{
	//TestFileUtil();
	//TestStringUtil();
	//TestGTDictionary();
	//TestGTBehaviourClassManager();
	//TestTMXObjectLayer();
	//TestVisualLeakDetector();
	//TestUILabelBMFont();
	//TestJSScriptEngine();
	//TestAudioManager();
	//TestCocos2dx();
	//TestGameObject();
	//TestTweener();	
	//TestNew();
	//TestGenerals();
	//TestDevTest();
	//TestUI(this);
	//TestEvent(this);

	return 1;
}

// When the system is updated, this method is called for each frame.
int32 TestManager::OnUpdate(void)
{
	return 1;
}

// This method is called for rendering each frame.
int32 TestManager::OnRender(void)
{
	return 1;
}

// Before the system is shut down, this method is called.
int32 TestManager::OnDestroy(void)
{
	if(m_pUILabelBMFont1)
	{
		m_pUILabelBMFont1->Release();
		m_pUILabelBMFont1 = NULL;
	}

	if(m_pUILabelBMFont2)
	{
		m_pUILabelBMFont2->Release();
		m_pUILabelBMFont2 = NULL;
	}

	AudioManager::GetInstance()->StopBackgroundMusic(true);

	return 1;
}
