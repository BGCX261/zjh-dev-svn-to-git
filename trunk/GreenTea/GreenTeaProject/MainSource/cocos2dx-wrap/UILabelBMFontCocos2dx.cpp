#include "UILabelBMFontCocos2dx.h"
#include "Cocos2dxGeneral.h"
#include "../GameGeneral.h"

UILabelBMFontCocos2dx::UILabelBMFontCocos2dx() :
			m_pCCLabelBMFont(NULL),
			m_sText(GTString::EmptyString)
{
}


UILabelBMFontCocos2dx::~UILabelBMFontCocos2dx()
{
}


bool UILabelBMFontCocos2dx::Initialize(const char* szText, const char* szFontName)
{
	if(NULL == szText || NULL == szFontName)
	{
		return false;
	}

	m_pCCLabelBMFont = cocos2d::CCLabelBMFont::create(szText, szFontName);
	if(NULL == m_pCCLabelBMFont)
	{
		return false;
	}

	m_pCCLabelBMFont->retain();
    
	// Add this label object to the layer with UI z-order
	Cocos2dxGeneral::GetInstance()->GetDefaultLayer()->addChild(
		m_pCCLabelBMFont,
		GameGeneral::GetInstance()->GetZOrderIdUI()
		);

	return true;
}


// Initialize the font
bool UILabelBMFontCocos2dx::Initialize(const char* szFontName)
{
	return Initialize("NoString", szFontName);	
}


// Set the text
void UILabelBMFontCocos2dx::SetText(const char* szText)
{
	if(NULL == m_pCCLabelBMFont || NULL == szText)
	{
		return;
	}

	m_sText = szText;
	m_pCCLabelBMFont->setString(szText);
	//m_pCCLabelBMFont->visit();
}


// Set visible
void UILabelBMFontCocos2dx::SetVisible(bool visible)
{
	if(m_pCCLabelBMFont)
	{
		m_pCCLabelBMFont->setVisible(visible);
	}
}


// Release
bool UILabelBMFontCocos2dx::Release(void)
{
	if(m_pCCLabelBMFont)
	{
		// Remove this label object from the layer
		Cocos2dxGeneral::GetInstance()->GetDefaultLayer()->removeChild(m_pCCLabelBMFont, true);
		// Release the lable object
		m_pCCLabelBMFont->release();
		m_pCCLabelBMFont = NULL;
	}

	delete this;

	return true;
}


// Update
void UILabelBMFontCocos2dx::OnUpdate(void)
{
	if(m_pCCLabelBMFont)
	{
		//m_pCCLabelBMFont->setString(m_sText.ToCharString());
		//m_pCCLabelBMFont->visit();
	}
}
