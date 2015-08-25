#include "TestManager.h"
#include <GTCommon/FileUtil.h>
#include <GTLog/GTLogManager.h>
//#include "../GreenTea/GTScriptEngine/GTScriptEngine.h"
#include "MapManager.h"
#include <UI/UILabelBMFont.h>
#include <cocos2dx-wrap/UILabelBMFontCocos2dx.h>
#include <AudioManager.h>
#include "../Mono/MonoManager.h"

//#include <GTNew.h>

USING_NS_CC;

GTSINGLETON_IMP(TestManager);

TestManager::TestManager()
{
}

TestManager::~TestManager()
{
}

void TestFileUtil()
{
	unsigned long size = 0;
	char* pContent = (char*)FileUtil::ReadTextFileData("sprites/JiaXuRun.property", &size);
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
}

void TestGTDictionary()
{
	GTDictionary<GTString, GTString> dicString;
	GTString key1 = CTEXT("1");
	GTString key2 = CTEXT("2");
	GTString key3 = CTEXT("3");
	dicString.Add(key1, GTString(CTEXT("abcx")));
	dicString.Add(key2, GTString(CTEXT("abcy")));
	dicString.Add(key3, GTString(CTEXT("abcz")));

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
	m_pUILabelBMFont1 = new UILabelBMFontCocos2dx();
	//m_pUILabelBMFont1->Initialize(CTEXT("fonts/BookshelfSymbol7_32_Bold_Gradient.fnt"));
	//m_pUILabelBMFont1->SetText(CTEXT("Font Sample"));
	//m_pUILabelBMFont1->Initialize(CTEXT("fonts/MicrosoftYahei_32_Bold_Gradient.fnt"));
	//m_pUILabelBMFont1->Initialize("fonts/bitmapFontChinese.fnt");
	//m_pUILabelBMFont1->SetText("Settings 1");
	//m_pUILabelBMFont1->Initialize("Game Setting", "fonts/bitmapFontChinese.fnt");
	m_pUILabelBMFont1->Initialize("中国", "fonts/bitmapFontChinese.fnt");
	//m_pUILabelBMFont1->SetText("Settings 1 ");
	//m_pUILabelBMFont1->SetText("中国");
	m_pUILabelBMFont1->SetPosition(160.0f, 160.0f);

	m_pUILabelBMFont2 = new UILabelBMFontCocos2dx();
	m_pUILabelBMFont2->Initialize(CTEXT("fonts/BitmapFont28.fnt"));
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

void TestMonoManager(void)
{
	//MonoManager::GetInstance()->LoadAssembly(
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
	//TestMonoManager();

	//GTString source = "15:0,24:1,26:2";
	//GTArray<GTString> result;
	//GTStringUtil::Split(source, ",", result);

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
