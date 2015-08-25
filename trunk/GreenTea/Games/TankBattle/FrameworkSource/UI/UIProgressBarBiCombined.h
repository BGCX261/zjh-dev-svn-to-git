#ifndef _UI_PROGRESS_BAR_BI_COMBINED_H_
#define _UI_PROGRESS_BAR_BI_COMBINED_H_

#include "UIWidget.h"
#include "UIProgressBar.h"

class UIProgressBarBiCombined : public UIProgressBar
{
public:
	UIWIDGET_DEF(UIProgressBarBiCombined, UIWidget)

public:
	UIProgressBarBiCombined();
	UIProgressBarBiCombined(UIWidget* pParent);
	virtual ~UIProgressBarBiCombined();

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
	virtual void SetCurrentValue(const int32 nValue);
	virtual void SetMinValue(const int32 nMinValue);
	virtual void SetMaxValue(const int32 nMaxValue);
	virtual void RefreshValue(void);

protected:
	UIProgressBar* m_pFirstProgressBar;
	UIProgressBar* m_pSecondProgressBar;

private:
	const static tchar* m_szFirstProgressBarName;
	const static tchar* m_szSecondProgressBarName;
};

#endif /* _UI_PROGRESS_BAR_BI_COMBINED_H_ */
