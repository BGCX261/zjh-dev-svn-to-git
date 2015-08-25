#include "BSTweenerTest.h"

GTBEHAVIOUR_IMP(BSTweenerTest, GTBehaviour);

BSTweenerTest::BSTweenerTest() :
	m_pSprite(NULL),
	m_pTweener2D(NULL),
	m_bDone(true),
	m_TweenFunStartIndex(0)
{
}


BSTweenerTest::~BSTweenerTest()
{
}


// This method is called when GTBehaviour object is created.
int32 BSTweenerTest::OnCreate(void)
{
	GTBehaviour::OnCreate();
	
	return 1;
}


struct TestStruct
{
	int32 nid;
	float fid;
};

// This method is called when GTBehaviour object is initialized.
int32 BSTweenerTest::OnInitialize(GTBehaviourInitParam* param)
{
	GTBehaviour::OnInitialize(param);

	/*
	// GTArray
	//GTArray<TestStruct> gta;
	GTList<TestStruct> gta;
	TestStruct ts;
	ts.nid = 1; ts.fid = 200.0f;
	gta.AddToTail(ts);
	ts.nid = 2; ts.fid = 300.0f;
	gta.AddToTail(ts);
	ts.nid = 3; ts.fid = 400.0f;
	gta.AddToTail(ts);

	TestStruct* pts = &gta[1];
	*/
	
	/*
	GTArray<int32> arrayInt;
	GTArray<float> arrayFloat;
	GTArray<GTString> arrayString;

	if(param->pParam2)
	{
		GTTreeNode* pTreeNode = (GTTreeNode*)(param->pParam2);
		if(pTreeNode)
		{
			GTTreeNode* pArrayInt = pTreeNode->GetChild(CTEXT("GTArrayInt"));
			GTTreeNode* pArrayFloat = pTreeNode->GetChild(CTEXT("GTArrayFloat"));
			GTTreeNode* pArrayString = pTreeNode->GetChild(CTEXT("GTArrayString"));
			if(pArrayInt)
				pArrayInt->ValueToArrayInt(arrayInt);
			if(pArrayFloat)
				pArrayFloat->ValueToArrayFloat(arrayFloat);
			if(pArrayString)
				pArrayString->ValueToArrayString(arrayString);
		}
	}
	*/

	return 1;
}


static void OnTweenerComplete(void* param)
{
	BSTweenerTest* tweener = (BSTweenerTest*)param;
	tweener->m_bDone = true;
	/*
	if(tweener)
	{
		tweener->m_pTweener2D->Start(
			tweener->m_SpritePos,
			tweener->m_SpritePos + GTPoint2(350.0f, 0.0f),
			3000.0f,
			TweenInterpolation::ElasticEaseInOut,
			0.0f,
			OnTweenerComplete,
			tweener
			);
	}
	*/
}

// This method is called before first OnUpdate
int32 BSTweenerTest::OnStart(void)
{
	GTBehaviour::OnStart();

	m_pSprite = (BSSprite*)GetGameObject()->GetBehaviour("BSSprite");
	m_pTweener2D = (BSTweener2D*)GetGameObject()->GetBehaviour("BSTweener2D");

	if(m_pSprite && m_pTweener2D)
	{
		m_SpritePos = m_pSprite->GetGameObjectPosition();
		//m_pTweener2D->Start(pos, pos + GTPoint2(350.0f, 0.0f), 3000.0f, TweenInterpolation::Linear, 500.0f);
		//m_pTweener2D->Start(pos, pos + GTPoint2(350.0f, 0.0f), 3000.0f, TweenInterpolation::SinusoidalEaseIn, 500.0f);
		m_pTweener2D->Start(m_SpritePos, m_SpritePos + GTPoint2(350.0f, 0.0f), 3000.0f, GTTweenInterpolation::ElasticEaseInOut, 0.0f, OnTweenerComplete, this);
	}
	
	return 1;
}


// This method is called when GTBehaviour object is updated.
int32 BSTweenerTest::OnUpdate(void)
{
	GTBehaviour::OnUpdate();

	if(m_bDone)
	{
		// Next tween function
		m_TweenFunStartIndex++;
		if(m_TweenFunStartIndex > 30)
			m_TweenFunStartIndex = 0;

		m_bDone = false;
		m_pTweener2D->Start(
			m_SpritePos,
			m_SpritePos + GTPoint2(350.0f, 0.0f),
			2000.0f,
			GTTweenInterpolation::GetFunctionByType(m_TweenFunStartIndex),
			0.0f,
			OnTweenerComplete,
			this);
	}
	
	return 1;
}


// This method is called when GTBehaviour object is destroyed.
int32 BSTweenerTest::OnDestroy(void)
{
	GTBehaviour::OnDestroy();
	
	return 1;
}
