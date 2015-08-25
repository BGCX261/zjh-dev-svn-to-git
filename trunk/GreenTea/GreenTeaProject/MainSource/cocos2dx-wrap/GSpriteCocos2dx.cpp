#include "GSpriteCocos2dx.h"
#include "GSpriteAnimationCocos2dx.h"
#include <GTLog/GTLogManager.h>
#include "Cocos2dxGeneral.h"

using namespace cocos2d;

class GSpriteCocos2dxCallback : public cocos2d::CCObject
{
public:
	GSpriteCocos2dxCallback()
	{
	}
	~GSpriteCocos2dxCallback()
	{
	}

	void OnAnimationPlayingCompletion(void)
	{
		return;
	}
};
static GSpriteCocos2dxCallback g_GSpriteCocos2dxCallback;

// GSpriteCocos2dx
GSpriteCocos2dx::GSpriteCocos2dx():
	m_pSprite(NULL),
	m_pLayer(NULL),
	m_pAnimation(NULL),
	m_pCurrentAction(NULL),
	m_pCurrentSequenceActions(NULL),
	m_pCallbackForAnimationCompletion(NULL)
{
}

GSpriteCocos2dx::~GSpriteCocos2dx()
{
}

// Initialize animations
bool GSpriteCocos2dx::InitializeAnimation()
{
	if(m_pAnimation == NULL)
	{
		m_pAnimation = new GSpriteAnimationCocos2dx();
		if(m_pAnimation == NULL)
		{
			GTLogManager::GetInstance()->LogError("GSpriteCocos2dx.InitializeAnimation: m_pAnimaton == NULL");
			return false;
		}
	}

	return true;
}


// Once the animation clip is completed this callback is called.
void GSpriteCocos2dx::OnAnimationCompleteCallback()
{
	m_pCurrentAction = NULL;
	m_pCurrentSequenceActions = NULL;
	if(m_pCallbackForAnimationCompletion)
	{
		(this->*m_pCallbackForAnimationCompletion)(NULL);
		m_pCallbackForAnimationCompletion = NULL;
	}
}


// Play a specified clip
bool GSpriteCocos2dx::PlayClip(GSpriteAnimationClipCocos2dx* pClip, const uint32 nFlags)
{
	if(NULL == pClip || NULL == m_pAnimation)
	{
		return false;
	}

	// Stop current playing clip
	StopAnimation();
		
	if(GSpriteAnimation::PlayMode_Loop == nFlags)
	{
		// Play the animation forever
		// This animation is infinite, so the callback will NOT be called.
		m_pCurrentAction = cocos2d::CCRepeatForever::create(cocos2d::CCAnimate::create(pClip->GetAnimation()));
	}
	else if(GSpriteAnimation::PlayMode_Once == nFlags)
	{
		// Play the animation once
		// The callback will be called once the animation is over.
		m_pCurrentSequenceActions = cocos2d::CCSequence::create(
			(CCFiniteTimeAction*)cocos2d::CCRepeat::create(cocos2d::CCAnimate::create(pClip->GetAnimation()), 1),
			cocos2d::CCCallFunc::create(this, callfunc_selector(GSpriteCocos2dx::OnAnimationCompleteCallback)),
			//cocos2d::CCCallFunc::create(&g_GSpriteCocos2dxCallback, callfunc_selector(GSpriteCocos2dxCallback::OnAnimationPlayingCompletion)),
			//cocos2d::CCCallFunc::create(Cocos2dxGeneral::GetInstance()->GetDefaultLayer(), callfunc_selector(GSpriteCocos2dxCallback::OnAnimationPlayingCompletion)),
			//cocos2d::CCCallFunc::create(Cocos2dxGeneral::GetInstance()->GetDefaultLayer(), callfunc_selector(GSpriteCocos2dx::OnAnimationCompleteCallback)),
			NULL
			);
	}
	
	// Play the clip
	if(m_pCurrentAction)
	{
		m_pSprite->runAction(m_pCurrentAction);
	}
	else if(m_pCurrentSequenceActions)
	{
		m_pSprite->runAction(m_pCurrentSequenceActions);
	}

	return true;
}


// Play an animation specified by the name
bool GSpriteCocos2dx::PlayAnimationByName(
	const tchar* szAnimationName,
	const uint32 nFlags,
	GTObject_CallbackFunction pCallback)
{
	if(szAnimationName == NULL || m_pAnimation == NULL)
	{
		return false;
	}

	GSpriteAnimationClipCocos2dx* pClip = (GSpriteAnimationClipCocos2dx*)(m_pAnimation->GetClipByName(szAnimationName));
	if(pClip == NULL)
	{
		// The clip required doesn't exist
		return false;
	}

	//m_pSprite->setDisplayFrame(pClip->GetSpriteFrameByIndex(0));

	m_pCallbackForAnimationCompletion = pCallback;

	// Play this clip
	return PlayClip(pClip, nFlags);
}


bool GSpriteCocos2dx::PlayAnimationByName(const tchar* szAnimationName, const uint32 nFlags)
{
	return PlayAnimationByName(szAnimationName, nFlags, NULL);
}


// Play an animation specified by its index
bool GSpriteCocos2dx::PlayAnimationByIndex(
	const int32 index,
	const uint32 nFlags,
	GTObject_CallbackFunction pCallback
	)
{
	if(NULL == m_pAnimation)
	{
		return false;
	}
	if(index < 0 || index >= m_pAnimation->GetClipCount())
	{
		return false;
	}

	GSpriteAnimationClipCocos2dx* pClip = (GSpriteAnimationClipCocos2dx*)(m_pAnimation->GetClipByIndex(index));
	if(pClip == NULL)
	{
		// The clip required doesn't exist
		return false;
	}

	m_pCallbackForAnimationCompletion = pCallback;

	// Play this clip
	return PlayClip(pClip, nFlags);
}


bool GSpriteCocos2dx::PlayAnimationByIndex(const int32 index, const uint32 nFlags)
{
	return PlayAnimationByIndex(index, nFlags, NULL);
}


// Stop playing animations
bool GSpriteCocos2dx::StopAnimation(void)
{
	if(m_pCurrentAction)
	{
		m_pSprite->stopAction(m_pCurrentAction);
		m_pCurrentAction = NULL;
	}
	if(m_pCurrentSequenceActions)
	{
		m_pSprite->stopAction(m_pCurrentSequenceActions);
		m_pCurrentSequenceActions = NULL;
	}

	return true;
}


// Is an animatino clip being played ?
bool GSpriteCocos2dx::IsAnimationPlaying(void)
{
	return (m_pCurrentAction || m_pCurrentSequenceActions) ? true : false;
}


// Release the sprite object
void GSpriteCocos2dx::Release(void)
{
	if(m_pSprite)
	{
		// Remove this sprite from the layer
		if(NULL != m_pLayer)
		{
			// The method removeChild also releases memory
			m_pLayer->removeChild(m_pSprite, true);
		}

		// Here we don't need to call ->release to destroy this object because
		// the object will be released automatically by calling ->autorelease
		// when it's loaded.
		//
		// When it's loaded with CCSprite::spriteWithFile, ->autorelease is called.
		//
		// In one word, there're only 3 situations you need to call ->release() method 
		//   1.you "new" an object of cocos2d::NSObject children, such as CCSprite, CCLayer...
		//   2.you get a pointer of cocos2d::NSObject children, then invoke "retain" once in your code
		//   3.call the static methods such as CCSomeClass::initXXX. This situation is rarely seen in cocos2d-x
		//m_pSprite->release();
		m_pSprite = NULL;
	}

	/*
	if(m_pAnimation)
	{
		m_pAnimation->Release();
		m_pAnimation = NULL;
	}
	*/

	GTObject::Release();
}
