#ifndef $DefineReplacement$
#define $DefineReplacement$

#include "UIWidget.h"

class $ClassReplacement$ : public UIWidget
{
public:
	UIWIDGET_DEF($ClassReplacement$, UIWidget)

public:
	$ClassReplacement$();
	$ClassReplacement$(UIWidget* pParent);
	virtual ~$ClassReplacement$();

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
};

#endif /* $DefineReplacement$ */
