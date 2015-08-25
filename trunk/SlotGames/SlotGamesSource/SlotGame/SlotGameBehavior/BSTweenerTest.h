#ifndef _BS_TWEENER_TEST_H_
#define _BS_TWEENER_TEST_H_

#include <GTBehaviour.h>
#include <BehaviourScript/BSSprite.h>
#include <BehaviourScript/BSTweener2D.h>

class BSTweenerTest : public GTBehaviour
{
public:
	GTBEHAVIOUR_DEF(BSTweenerTest, GTBehaviour);

public:
	BSTweenerTest();
	virtual ~BSTweenerTest();

	// This method is called when GTBehaviour object is created.
	virtual int32 OnCreate(void);
	// This method is called when GTBehaviour object is initialized.
	virtual int32 OnInitialize(GTBehaviourInitParam* param);
	// This method is called before first OnUpdate
	virtual int32 OnStart(void);
	// This method is called when GTBehaviour object is updated.
	virtual int32 OnUpdate(void);
	// This method is called when GTBehaviour object is destroyed.
	virtual int32 OnDestroy(void);

public:
	BSSprite* m_pSprite;
	BSTweener2D* m_pTweener2D;
	GTPoint2 m_SpritePos;
	bool m_bDone;
	int32 m_TweenFunStartIndex;
};

#endif /* _BS_TWEENER_TEST_H_ */
