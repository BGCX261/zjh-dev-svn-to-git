#include "UILabelBMFontCocos2dx.h"
#include <cocos2dx-wrap/Cocos2dxGeneral.h>
#include <GameObjectCreation.h>
#include <GameGeneral.h>

UILabelBMFontCocos2dx::UILabelBMFontCocos2dx() :
			m_pCCLabelBMFont(NULL),
			m_sText(GTString::EmptyString)
{
}


UILabelBMFontCocos2dx::~UILabelBMFontCocos2dx()
{
}


bool UILabelBMFontCocos2dx::Initialize(const char* szText, const char* szFontName, const int32 nZOrder)
{
	if(NULL == szText || NULL == szFontName)
		return false;

	m_pCCLabelBMFont = cocos2d::CCLabelBMFont::create(szText, szFontName);
	if(NULL == m_pCCLabelBMFont)
		return false;

	//m_pCCLabelBMFont->retain();
    
	// Add this label object to the layer with UI z-order
	Cocos2dxGeneral::GetInstance()->GetDefaultLayer()->addChild(m_pCCLabelBMFont, nZOrder);

	return true;
}


// Initialize the font
bool UILabelBMFontCocos2dx::Initialize(const char* szFontName, const int32 nZOrder)
{
	return Initialize("NoString", szFontName, nZOrder);	
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


// Get visible
bool UILabelBMFontCocos2dx::GetVisible(void)
{
	if(m_pCCLabelBMFont)
	{
		return m_pCCLabelBMFont->isVisible();
	}
	return false;
}


// Release
bool UILabelBMFontCocos2dx::Release(void)
{
	if(m_pCCLabelBMFont)
	{
		// Remove this label object from the layer
		// The method removeChild also releases memory so no need to call m_pCCLabelBMFont->release()
		Cocos2dxGeneral::GetInstance()->GetDefaultLayer()->removeChild(m_pCCLabelBMFont, true);
		// Release the lable object
		//m_pCCLabelBMFont->release();
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
