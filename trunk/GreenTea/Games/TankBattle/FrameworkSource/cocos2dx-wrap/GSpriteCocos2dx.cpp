#include "GSpriteCocos2dx.h"
#include "GSpriteAnimationCocos2dx.h"
#include <GTLog/GTLogManager.h>
#include "Cocos2dxGeneral.h"
#include <GameObjectCreation.h>

/*
#ifdef GT_DEBUG
#include <GTNew.h>
#endif // GT_DEBUG
*/

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
	m_pCallbackForAnimationCompletion(NULL),
	m_pCallbackThis(NULL),
	m_pCallbackParam(NULL),
	//m_nZOrder(1),
	m_strKey(CTEXT("no-key")),
	m_bVisible(true)
{
}


GSpriteCocos2dx::~GSpriteCocos2dx()
{
}


/*
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
*/


// Once the animation clip is completed this callback is called.
void GSpriteCocos2dx::OnAnimationCompleteCallback()
{
	m_pCurrentAction = NULL;
	m_pCurrentSequenceActions = NULL;
	if(m_pCallbackForAnimationCompletion && m_pCallbackThis)
	{
		(m_pCallbackThis->*m_pCallbackForAnimationCompletion)(m_pCallbackParam);
		// Clean
		m_pCallbackForAnimationCompletion = NULL;
		m_pCallbackThis = NULL;
		m_pCallbackParam = NULL;
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
	else if(GSpriteAnimation::PlayMode_None == nFlags)
	{
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
	GTObject_EventCallback pCallback,
	GTObject* pCallbackThis,
	void* pCallbackParam
	)
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

	// Save callback
	m_pCallbackForAnimationCompletion = pCallback;
	m_pCallbackThis = pCallbackThis;
	m_pCallbackParam = pCallbackParam;

	// Play this clip
	return PlayClip(pClip, nFlags);
}


bool GSpriteCocos2dx::PlayAnimationByName(const tchar* szAnimationName, const uint32 nFlags)
{
	return PlayAnimationByName(szAnimationName, nFlags, NULL, NULL, NULL);
}


// Play an animation specified by its index
bool GSpriteCocos2dx::PlayAnimationByIndex(
	const int32 index,
	const uint32 nFlags,
	GTObject_EventCallback pCallback,
	GTObject* pCallbackThis,
	void* pCallbackParam
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

	// Save callback
	m_pCallbackForAnimationCompletion = pCallback;
	m_pCallbackThis = pCallbackThis;
	m_pCallbackParam = pCallbackParam;

	// Play this clip
	return PlayClip(pClip, nFlags);
}


bool GSpriteCocos2dx::PlayAnimationByIndex(const int32 index, const uint32 nFlags)
{
	return PlayAnimationByIndex(index, nFlags, NULL, NULL, NULL);
}


// Set display frame
// nFrame = 0 to frameCount - 1
bool GSpriteCocos2dx::SetDisplayFrameByName(const tchar* szAnimName, const int32 nFrame)
{
	DBG_ASSERT(m_pSprite);

	if(NULL == szAnimName)
		return false;

	// Get clip specified by szAnimName
	GSpriteAnimationClipCocos2dx* pClip = (GSpriteAnimationClipCocos2dx*)(m_pAnimation->GetClipByName(szAnimName));
	if(pClip == NULL)
		return false;
	// Get specified frame
	cocos2d::CCSpriteFrame* pSpriteFrame = pClip->GetSpriteFrameByIndex(nFrame);
	if(pSpriteFrame == NULL)
		return false;

	// If there is an animation being played, stop it.
	if(IsAnimationPlaying())
		StopAnimation();

	m_pSprite->setDisplayFrame(pSpriteFrame);

	return true;
}


bool GSpriteCocos2dx::SetDisplayFrameByIndex(const int32 nAnimIndex, const int32 nFrame)
{
	DBG_ASSERT(m_pSprite);

	if(nAnimIndex < 0 || nAnimIndex >= m_pAnimation->GetClipCount())
		return false;

	// Get clip specified by szAnimName
	GSpriteAnimationClipCocos2dx* pClip = (GSpriteAnimationClipCocos2dx*)(m_pAnimation->GetClipByIndex(nAnimIndex));
	if(pClip == NULL)
		return false;
	// Get specified frame
	cocos2d::CCSpriteFrame* pSpriteFrame = pClip->GetSpriteFrameByIndex(nFrame);
	if(pSpriteFrame == NULL)
		return false;

	// If there is an animation being played, stop it.
	if(IsAnimationPlaying())
		StopAnimation();

	m_pSprite->setDisplayFrame(pSpriteFrame);

	return true;
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


// Clone a sprite object from this
GTObject* GSpriteCocos2dx::Clone(void)
{
	return (IsAnimatedSprite() ?
			GameObjectCreation::CloneAnimatedSprite(this, GetZOrder()) :
			GameObjectCreation::CloneStaticSprite(this, GetZOrder()));
}


// Release the sprite object
void GSpriteCocos2dx::Release(void)
{
	if(m_pSprite)
	{
		// Remove this sprite from the layer
		if(NULL != m_pLayer)
		{
			// The method removeChild also releases memory so no need to call m_pSprite->release()
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

	if(m_pAnimation)
	{		
		m_pAnimation->Release();
		m_pAnimation = NULL;
	}
	/*
	m_pLayer = NULL;
	if(m_pCurrentAction)
	{
		m_pCurrentAction->release();
		m_pCurrentAction = NULL;
	}
	if(m_pCurrentSequenceActions)
	{
		m_pCurrentSequenceActions->release();
		m_pCurrentSequenceActions = NULL;
	}
	*/

	GTObject::Release();
}
