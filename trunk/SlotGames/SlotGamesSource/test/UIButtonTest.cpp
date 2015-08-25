#include "UIButtonTest.h"
#include <UI/UIWidgetClassManager.h>
#include <GTGreenTea.h>
#include <GameObjectCreation.h>
#include <GTGameObjectManager.h>
#include <BehaviourScript/BSSprite.h>
#include <BehaviourScript/BSScreenSprite.h>

UIWIDGET_IMP(UIButtonTest, UIWidget, UIWidgetClassManager::CreateClassInstanceDefineCallback)

UIButtonTest::UIButtonTest() : UIButton()
{
}


UIButtonTest::UIButtonTest(UIWidget* pParent) : UIButton(pParent)
{
}


UIButtonTest::~UIButtonTest()
{
}


// When the object is initialized, this method is called.
int32 UIButtonTest::OnInitialize(void)
{
	UIWidget::OnInitialize();

	return 1;
}


// When the system is updated, this method is called for each frame.
int32 UIButtonTest::OnUpdate(void)
{
	UIWidget::OnUpdate();

	return 1;
}


// This method is called for rendering each frame.
int32 UIButtonTest::OnRender(void)
{
	UIWidget::OnRender();

	return 1;
}


// Override GTObject::Release to do more things
void UIButtonTest::Release(void)
{
	UIWidget::Release();
}


void UIButtonTest::OnAnimationPlayingCompletion(void* pParam)
{
	int32 k = 9;
}


GSprite* pSprite1 = NULL;
GSprite* pSprite2 = NULL;
GTGameObject* pGameObject1 = NULL;
GTGameObject* pGameObjectCopy = NULL;
bool UIButtonTest::OnSingleClick(const uint32 nFlags, const GTPoint2& pos)
{
	UIButton::OnSingleClick(nFlags, pos);

	if(nFlags & UIWidget::Flag_ClickUp)
	{
		//GTLogManager::Inst()->LogFormatTrace("UIButtonTest: Id = %d, Name = %s clicked", GetId(), GetName());
		const uint32 btnId = GetId();
		if(btnId == 1001)
		{
			if(NULL == pSprite1)
			{
				// Static
				//pSprite1 = GameObjectCreation::CreateStaticSpriteWithSpriteFile("sprites/devtest00.sprite", 1);
				//pSprite1 = GameObjectCreation::CreateStaticSprite("sprites/devtest00.png", 1);
				// Animated
				/*
				pSprite1 = GameObjectCreation::CreateAnimatedSprite("sprites/baoxiang.sprite", 1);
				if(pSprite1)
				{
					pSprite1->SetPosition(400, 200);
					if(pSprite1->IsAnimatedSprite())
						pSprite1->PlayAnimationByIndex(0, GSpriteAnimation::PlayMode_Loop);
				}
				*/
				if(NULL == pGameObject1)
				{
					//pGameObject1 = GTGameObjectManager::Inst()->CreateGameObject(NULL, CTEXT("goTest"), CTEXT("sprites/baoxiang.property"));
					pGameObject1 = GTGameObjectManager::Inst()->CreateGameObject(NULL, CTEXT("goTest"), CTEXT("sprites/baoxiang-go.property"));
					pGameObject1->SetPosition(200, 200);
					pGameObject1->SetZOrder(10);
					BSSprite* pSprite = (BSSprite*)(pGameObject1->GetBehaviour(CTEXT("BSSprite")));
					if(pSprite)
					{
						//pSprite->m_pSprite->SetDisplayFrameByIndex(0, 0);
						//pSprite->m_pSprite->SetZOrder(0);
						//BSScreenSprite* pSprite = (BSScreenSprite*)(pGameObject1->GetBehaviour(CTEXT("BSScreenSprite")));
						//pSprite->PlayAnimationByIndex(0, GSpriteAnimation::PlayMode_Once);
						/*
						pSprite->m_pSprite->PlayAnimationByIndex(
						0,
						GSpriteAnimation::PlayMode_Loop,
						GTObject_CallbackFunction_Set(UIButtonTest::OnAnimationPlayingCompletion),
						this,
						NULL
						);
						*/
						//pSprite->PlayAnimationByIndex(0, GSpriteAnimation::PlayMode_Loop);
						//pSprite->StopAnimation();
						//pSprite->m_pSprite->SetDisplayFrameByIndex(0, 0);
						//pSprite->m_pSprite->SetDisplayFrameByIndex(0, 6);
						//pSprite->m_pSprite->SetDisplayFrameByName("Normal", 0);
						//pSprite->m_pSprite->SetDisplayFrameByName("Normal", 6);
					}
				}
				/*
				if(NULL == pGameObject1)
				{
					pGameObject1 = GTGameObjectManager::Inst()->CreateGameObject(NULL, CTEXT("goTest"), CTEXT("SlotGame/Respin.property"));
					pGameObject1->SetPosition(200, 200);
					GTGameObject* child1 = pGameObject1->FindChild(CTEXT("lockAnimation"));
					if(child1)
					{
						BSSprite* bs1 = (BSSprite*)(child1->GetBehaviour(CTEXT("BSSprite")));
						bs1->m_pSprite->SetVisible(false);
					}
					GTGameObject* child2 = pGameObject1->FindChild(CTEXT("lock_highlight_Animation"));
					if(child2)
					{
						BSSprite* bs2 = (BSSprite*)(child2->GetBehaviour(CTEXT("BSSprite")));
						bs2->m_pSprite->SetVisible(false);
					}
					int32 k = 0;
				}
				*/
			}
		}
		else if(btnId == 1003)
		{
			/*
			if(pSprite1 && NULL == pSprite2)
			{
				//pSprite2 = GameObjectCreation::CloneStaticSprite(pSprite1);
				//pSprite2 = GameObjectCreation::CloneAnimatedSprite(pSprite1, 1);
				pSprite2 = pSprite1->Clone();
				if(pSprite2)
				{
					pSprite2->SetPosition(600, 200);
					if(pSprite2->IsAnimatedSprite())
						pSprite2->PlayAnimationByIndex(0, GSpriteAnimation::PlayMode_Loop);
				}				
			}
			*/
			/*
			if(pGameObject1)
			{
				GameObjectManager::Inst()->DestroyGameObject(pGameObject1);
				pGameObject1 = NULL;
			}
			*/
			/*
			if(NULL == pGameObjectCopy)
			{
				pGameObjectCopy = GTGameObjectManager::Inst()->CloneGameObject(NULL, pGameObject1, "gameObjectCopy");
				if(pGameObjectCopy)
				{
					pGameObjectCopy->SetPosition(300, 200);
					BSSprite* pSprite = (BSSprite*)(pGameObjectCopy->GetBehaviour(CTEXT("BSSprite")));
					if(pSprite)
						pSprite->PlayAnimationByIndex(0, GSpriteAnimation::PlayMode_Loop);
				}
			}
			*/
		}
		else if(btnId == 1005)
		{
			if(pGameObjectCopy)
			{
				//GameObjectManager::Inst()->DestroyGameObject(pGameObjectCopy);
				pGameObjectCopy->Release();
				pGameObjectCopy = NULL;
			}
		}
	}

	return true;
}


// Before the system is shut down, this method is called.
int32 UIButtonTest::OnDestroy(void)
{
	UIWidget::OnDestroy();

	if(pSprite1)
	{
		pSprite1->Release();
		pSprite1 = NULL;
	}
	if(pSprite2)
	{
		pSprite2->Release();
		pSprite2 = NULL;
	}

	return 1;
}


bool UIButtonTest::OnDoubleClick(const uint32 nFlags, const GTPoint2& pos)
{
	return UIButton::OnDoubleClick(nFlags, pos);
}


bool UIButtonTest::OnStateChange(const uint32 nState)
{
	return UIButton::OnStateChange(nState);
}
