#include "GSpriteAnimationClipCocos2dx.h"

GSpriteAnimationClipCocos2dx::GSpriteAnimationClipCocos2dx():
	m_pAnimFrames(NULL),
	m_pAnimation(NULL)
{
	SetFrameDelayTime(0.25f);
}

GSpriteAnimationClipCocos2dx::~GSpriteAnimationClipCocos2dx()
{
	Release();
}

// Initialize m_pAnimFrames object, allocating memory for animation frames.
bool GSpriteAnimationClipCocos2dx::InitializeFrame(const int32 nFrameCount)
{
	if(0 == nFrameCount)
	{
		return false;
	}

	// Allocate memory for m_pAnimFrames
	m_pAnimFrames = cocos2d::CCArray::createWithCapacity(nFrameCount);
	if(NULL == m_pAnimFrames)
	{
		return false;
	}
	m_pAnimFrames->retain();

	return true;
}


// Initialize m_pAnimation object
//
// NOTE: Before calling this method, frame delay time must be setup firstly.
bool GSpriteAnimationClipCocos2dx::InitializeAnimation()
{
	if(NULL == m_pAnimFrames)
	{
		return false;
	}

	m_pAnimation = cocos2d::CCAnimation::createWithSpriteFrames(
		m_pAnimFrames,
		GetFrameDelayTime()
		);
	if(NULL == m_pAnimation)
	{
		return false;
	}
	// retain must be called otherwise m_pAnimation might
	// be released at sometime.
	// This doesn't need to call in cocos2d-2.0-rc0a-x-2.0
	m_pAnimation->retain();

	return true;
}


// Release
void GSpriteAnimationClipCocos2dx::Release(void)
{	
	if(m_pAnimFrames)
	{
		// According to official sample code of cocos2d-x (SpriteTest),
		// don't need to call CCSpriteFrame::release() to release each sprite fame,
		// just call m_pAnimFrames->release() to release all resources.
		m_pAnimFrames->release();
		m_pAnimFrames = NULL;

		/*
		for(uint32 i=0; i<m_pAnimFrames->count(); i++)
		{
			cocos2d::CCSpriteFrame* pSpriteFrame = m_pAnimFrames->getObjectAtIndex(i);
			if(pSpriteFrame)
			{
				pSpriteFrame->release();
			}
		}
		delete m_pAnimFrames;
		m_pAnimFrames = NULL;
		*/

		// According to official sample code of cocos2d-x (SpriteTest), if animation is created like in this way:
		// CCAnimation* animation = CCAnimation::animationWithFrames(animFrames).
		// animation doesn't need to call release().
		/*	
		if(m_pAnimation)
		{
		m_pAnimation->release();
		m_pAnimation = NULL;
		}
		*/

		if(m_pAnimation)
		{
			// Call release because retain was called before
			m_pAnimation->release();
			m_pAnimation = NULL;
		}

		delete this;
	}	
}
