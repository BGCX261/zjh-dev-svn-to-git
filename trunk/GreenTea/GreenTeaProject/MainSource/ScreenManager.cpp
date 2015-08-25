#include "ScreenManager.h"

GTSINGLETON_IMP(ScreenManager);

ScreenManager::ScreenManager():
	m_nScreenWidth(0),
	m_nScreenHeight(0),
	m_nScreenHalfWidth(0),
	m_nScreenHalfHeight(0)
{
}


ScreenManager::~ScreenManager()
{
}


// Set screen width
void ScreenManager::SetScreenWidth(const uint32 w)
{
	m_nScreenWidth = w;
	m_nScreenHalfWidth = m_nScreenWidth / 2;
}


// Set screen height
void ScreenManager::SetScreenHeight(const uint32 h)
{
	m_nScreenHeight = h;
	m_nScreenHalfHeight = m_nScreenHeight / 2;
}


// Set screen size
void ScreenManager::SetScreenSize(const uint32 w, const uint32 h)
{
	SetScreenWidth(w);
	SetScreenHeight(h);
}
