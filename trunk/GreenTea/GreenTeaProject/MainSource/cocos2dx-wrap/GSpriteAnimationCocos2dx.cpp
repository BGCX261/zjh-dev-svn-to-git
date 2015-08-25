#include "GSpriteAnimationCocos2dx.h"
#include <GTLog/GTLogManager.h>

GSpriteAnimationCocos2dx::GSpriteAnimationCocos2dx():
	m_ppAnimation(NULL),
	m_nAnimationCount(0)
{
}

GSpriteAnimationCocos2dx::~GSpriteAnimationCocos2dx()
{
}

// Initialize the animatons
bool GSpriteAnimationCocos2dx::Initialize(const int32 nAnimationCount)
{
	if(nAnimationCount == 0)
	{
		GTLogManager::GetInstance()->LogError("GSpriteAnimationCocos2dx.Initialize: nAnimationCount == 0");
		return false;
	}

	m_ppAnimation = new GSpriteAnimationClipCocos2dx*[nAnimationCount];
	if(m_ppAnimation == NULL)
	{
		GTLogManager::GetInstance()->LogError("GSpriteAnimationCocos2dx.Initialize: m_ppAnimation == 0");
		return false;
	}
	// Save animation count
	m_nAnimationCount = nAnimationCount;
	for(int32 i=0; i<m_nAnimationCount; i++)
	{
		m_ppAnimation[i] = new GSpriteAnimationClipCocos2dx();
	}

	return true;
}

// Get animation clip by its name
GSpriteAnimationClip* GSpriteAnimationCocos2dx::GetClipByName(const tchar* szName)
{
	if(szName == NULL)
	{
		return NULL;
	}

	if(m_ppAnimation == NULL || m_nAnimationCount == 0)
	{
		return NULL;
	}

	for(int32 i=0; i<m_nAnimationCount; i++)
	{
		if(StringCmp(szName, m_ppAnimation[i]->GetClipName()) == 0)
		{
			// The clip is found
			return m_ppAnimation[i];
		}
	}

	return NULL;
}

// Release the resouces
void GSpriteAnimationCocos2dx::Release()
{
	if(m_ppAnimation && m_nAnimationCount)
	{
		for(int32 i=0; i<m_nAnimationCount; i++)
		{
			if(m_ppAnimation[i])
			{
				m_ppAnimation[i]->Release();
				m_ppAnimation[i] = NULL;
			}
		}

		delete[] m_ppAnimation;
		m_ppAnimation = NULL;
	}

	delete this;
}
