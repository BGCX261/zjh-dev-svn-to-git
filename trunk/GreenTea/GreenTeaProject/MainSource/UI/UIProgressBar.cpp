#include "UIProgressBar.h"
#include "UIWidgetClassManager.h"

UIWIDGET_IMP(UIProgressBar, UIWidget, UIWidgetClassManager::CreateClassInstanceDefineCallback)

UIProgressBar::UIProgressBar() : UIWidget()
{
	m_nMinValue = 0;
	m_nMaxValue = 0;
	m_nCurrentValue = 0;
}


UIProgressBar::UIProgressBar(UIWidget* pParent) : UIWidget(pParent)
{
	m_nMinValue = 0;
	m_nMaxValue = 0;
	m_nCurrentValue = 0;
}


UIProgressBar::~UIProgressBar()
{
}


// When the object is initialized, this method is called.
int32 UIProgressBar::OnInitialize(void)
{
	UIWidget::OnInitialize();

	GSprite* pSprite = GetSpriteSet()->GetSprite(UISpriteSet::StateEnabled);
	if(pSprite)
	{
		m_OriginalRect = pSprite->GetTextureRect();
	}

	return 1;
}


// When the system is updated, this method is called for each frame.
int32 UIProgressBar::OnUpdate(void)
{
	UIWidget::OnUpdate();

	UpdateProgressBar();

	return 1;
}


// This method is called for rendering each frame.
int32 UIProgressBar::OnRender(void)
{
	UIWidget::OnRender();

	return 1;
}


// Before the system is shut down, this method is called.
int32 UIProgressBar::OnDestroy(void)
{
	UIWidget::OnDestroy();

	return 1;
}


// Override GTObject::Release to do more things
void UIProgressBar::Release(void)
{
	UIWidget::Release();
}


// Set the percent of the progress bar
void UIProgressBar::UpdateProgressBar(void)
{
	GSprite* pSprite = GetSpriteSet()->GetSprite(UISpriteSet::StateEnabled);
	if(pSprite)
	{
		float fPercent = (float)m_nCurrentValue / (float)(m_nMaxValue - m_nMinValue + 1);
		pSprite->SetTextureRect(
			m_OriginalRect.origin.x,
			m_OriginalRect.origin.y,
			m_OriginalRect.size.width * fPercent,
			m_OriginalRect.size.height
			);
	}
}


// Set the current value of the progress bar
void UIProgressBar::SetCurrentValue(const int32 nValue)
{	
	if(nValue < m_nMinValue)
	{
		m_nCurrentValue = m_nMinValue;
	}
	else if(nValue > m_nMaxValue)
	{
		m_nCurrentValue = m_nMaxValue;
	}
	else
	{
		m_nCurrentValue = nValue;
	}
}


void UIProgressBar::SetMinValue(const int32 nMinValue)
{
	m_nMinValue = nMinValue;
}


void UIProgressBar::SetMaxValue(const int32 nMaxValue)
{
	m_nMaxValue = nMaxValue;
}


void UIProgressBar::RefreshValue(void)
{
}
