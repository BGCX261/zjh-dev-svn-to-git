#include "UIProgressBarBiCombined.h"
#include "UIWidgetClassManager.h"

UIWIDGET_IMP(UIProgressBarBiCombined, UIWidget, UIWidgetClassManager::CreateClassInstanceDefineCallback)

const tchar* UIProgressBarBiCombined::m_szFirstProgressBarName = CTEXT("FirstProgressBar");
const tchar* UIProgressBarBiCombined::m_szSecondProgressBarName = CTEXT("SecondProgressBar");

UIProgressBarBiCombined::UIProgressBarBiCombined() : UIProgressBar()
{
	m_pFirstProgressBar = NULL;
	m_pSecondProgressBar = NULL;
}


UIProgressBarBiCombined::UIProgressBarBiCombined(UIWidget* pParent) : UIProgressBar(pParent)
{
	m_pFirstProgressBar = NULL;
	m_pSecondProgressBar = NULL;
}


UIProgressBarBiCombined::~UIProgressBarBiCombined()
{
}


// When the object is initialized, this method is called.
int32 UIProgressBarBiCombined::OnInitialize(void)
{
	UIWidget::OnInitialize();

	return 1;
}


// When the system is updated, this method is called for each frame.
int32 UIProgressBarBiCombined::OnUpdate(void)
{
	UIWidget::OnUpdate();

	if(NULL == m_pFirstProgressBar)
	{
		m_pFirstProgressBar = (UIProgressBar*)FindChild(UIProgressBarBiCombined::m_szFirstProgressBarName);
	}
	if(NULL == m_pSecondProgressBar)
	{
		m_pSecondProgressBar = (UIProgressBar*)FindChild(UIProgressBarBiCombined::m_szSecondProgressBarName);
	}

	return 1;
}


// This method is called for rendering each frame.
int32 UIProgressBarBiCombined::OnRender(void)
{
	UIWidget::OnRender();

	return 1;
}


// Before the system is shut down, this method is called.
int32 UIProgressBarBiCombined::OnDestroy(void)
{
	UIWidget::OnDestroy();

	return 1;
}


// Override GTObject::Release to do more things
void UIProgressBarBiCombined::Release(void)
{
	UIWidget::Release();

	m_pFirstProgressBar = NULL;
	m_pSecondProgressBar = NULL;
}


// Set the current value of the progress bar
void UIProgressBarBiCombined::SetCurrentValue(const int32 nValue)
{
	if(m_pFirstProgressBar)
	{
		m_pFirstProgressBar->SetCurrentValue(nValue);
	}
	if(m_pSecondProgressBar)
	{
		m_pSecondProgressBar->SetCurrentValue(nValue);
	}
}


void UIProgressBarBiCombined::SetMinValue(const int32 nMinValue)
{
	if(m_pFirstProgressBar)
	{
		m_pFirstProgressBar->SetMinValue(nMinValue);
	}
	if(m_pSecondProgressBar)
	{
		m_pSecondProgressBar->SetMinValue(nMinValue);
	}
}


void UIProgressBarBiCombined::SetMaxValue(const int32 nMaxValue)
{
	if(m_pFirstProgressBar)
	{
		m_pFirstProgressBar->SetMaxValue(nMaxValue);
	}
	if(m_pSecondProgressBar)
	{
		m_pSecondProgressBar->SetMaxValue(nMaxValue);
	}
}


void UIProgressBarBiCombined::RefreshValue(void)
{
	if(m_pFirstProgressBar)
	{
		m_pFirstProgressBar->RefreshValue();
	}
	if(m_pSecondProgressBar)
	{
		m_pSecondProgressBar->RefreshValue();
	}
}
