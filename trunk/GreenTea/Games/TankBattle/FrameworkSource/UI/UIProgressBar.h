#ifndef _UI_PROGRESS_BAR_H_
#define _UI_PROGRESS_BAR_H_

#include "UIWidget.h"

class UIProgressBar : public UIWidget
{
public:
	UIWIDGET_DEF(UIProgressBar, UIWidget)

public:
	UIProgressBar();
	UIProgressBar(UIWidget* pParent);
	virtual ~UIProgressBar();

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

	// Set the current value of the progress bar
	virtual void SetMinValue(const int32 nMinValue);
	virtual void SetMaxValue(const int32 nMaxValue);
	virtual void SetCurrentValue(const int32 nValue);
	virtual void RefreshValue(void);
	// Get the current value
	int32 GetCurrentValue(void)
	{
		return m_nCurrentValue;
	}

	void UpdateProgressBar(void);	

protected:
	GTRect m_OriginalRect;

public:
	int32 m_nMinValue;
	int32 m_nMaxValue;
	int32 m_nCurrentValue;
};

#endif /* _UI_PROGRESS_BAR_ */
