#ifndef _UI_BUTTON_TEST_H_H
#define _UI_BUTTON_TEST_H_H

#include <UI/UIBaseDef.h>

class UIButtonTest : public UIButton
{
public:
	UIWIDGET_DEF(UIButtonTest, UIWidget)

public:
	UIButtonTest();
	UIButtonTest(UIWidget* pParent);
	virtual ~UIButtonTest();

public:
	// When the object is initialized, this method is called.
	virtual int32 OnInitialize(void);

	// When the system is updated, this method is called for each frame.
	virtual int32 OnUpdate(void);

	// This method is called for rendering each frame.
	virtual int32 OnRender(void);

	// Before the system is shut down, this method is called.
	virtual int32 OnDestroy(void);

	// Override GTObject::Release to do more things
	virtual void Release(void);

	// Events
	virtual bool OnSingleClick(const uint32 nFlags, const GTPoint2& pos);
	virtual bool OnDoubleClick(const uint32 nFlags, const GTPoint2& pos);
	virtual bool OnStateChange(const uint32 nState);

	void OnAnimationPlayingCompletion(void* pParam);
};

#endif /* _UI_BUTTON_TEST_H_H */
