#include "FontManager.h"
#include <GTLog/GTLogManager.h>

GTSINGLETON_IMP(FontManager);

FontManager::FontManager()
{
	m_pFont1 = NULL;
	m_pFont2 = NULL;
}


FontManager::~FontManager()
{
}


// Initialize
void FontManager::Initialize(void)
{	
	// Load font 1
	m_pFont1 = new UIFont();
	if(NULL == m_pFont1)
	{
		GTLogManager::GetInstance()->LogError("Failed to allocate memory for m_pFont1.");
		return;
	}
	if(false == m_pFont1->Create(CTEXT("./fonts/font1.fnt")))
	{
		GTLogManager::GetInstance()->LogError("Failed to load font1.fnt.");
		FontManager::Destroy();
		return;
	}
	
	// Load font 2
	m_pFont2= new UIFont();
	if(NULL == m_pFont2)
	{
		GTLogManager::GetInstance()->LogError("Failed to allocate memory for m_pFont2.");
		return;
	}
	if(false == m_pFont2->Create(CTEXT("./fonts/font2.fnt")))
	{
		GTLogManager::GetInstance()->LogError("Failed to load font2.fnt.");
		FontManager::Destroy();
		return;
	}
}


// Destroy
void FontManager::Destroy(void)
{
	if(m_pFont1)
	{
		m_pFont1->Release();
		m_pFont1 = NULL;
	}

	if(m_pFont2)
	{
		m_pFont2->Release();
		m_pFont2 = NULL;
	}
}
