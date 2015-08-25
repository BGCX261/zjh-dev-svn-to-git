#include <GTBaseDef.h>
#include "GameObjectCreation.h"
#include <GTLog/GTLogManager.h>
#include <MapManager.h>
#include <TagManager.h>
#include "GSpriteCocos2dx.h"
#include "Cocos2dxGeneral.h"
#include "GSpriteAnimationCocos2dx.h"
#include "SpriteAtlasCocos2dx.h"
#include <GTPropertyFile.h>
#include <GameGeneral.h>
#include <UI/UILabelBMFont.h>
#include "UILabelBMFontCocos2dx.h"
#include "ResourceManager.h"

#ifdef GT_DEBUG
#include <GTNew.h>
#endif // GT_DEBUG

// Create a sprite from .sprite (static or animated sprite)
GSprite* GameObjectCreation::CreateSprite(const tchar* szSpriteFileName, const int32 nZOrder)
{
	if(NULL == szSpriteFileName)
		return NULL;

	// Load the sprite file
	GTTreeNode* pTreeNode = GTPropertyFile::Load(szSpriteFileName);
	if(pTreeNode == NULL)
		return NULL;

	GTTreeNode* pImageTreeNode = pTreeNode->FindChild(GTPropertyFile::TagImage);
	GTTreeNode* pPlistTreeNode = pTreeNode->FindChild(GTPropertyFile::TagPlist);
	GTTreeNode* pAnimationTreeNode = pTreeNode->FindChild(GTPropertyFile::TagAnimation);
	// Check this sprite is static or animated
	GSprite *pSprite = NULL;
	if(pImageTreeNode)
	{
		if(pAnimationTreeNode)
		{
			// Animated sprite
			pSprite = CreateAnimatedSpriteFromTreeNode(pTreeNode, nZOrder);
		}
		else
		{
			// Static sprite
			pSprite = CreateStaticSpriteFromTreeNode(pTreeNode, nZOrder);
		}
	}
	else
	{
		GTLogManager::GetInstance()->LogFormatError(CTEXT("CreateSprite: Unknown sprite file (%s)"), szSpriteFileName);
	}
	
	if(NULL == pSprite)
		GTLogManager::GetInstance()->LogFormatError(CTEXT("Failed to call CreateStaticSprite for '%s'"), szSpriteFileName);

	// Release the file
	if(pTreeNode)
	{
		pTreeNode->Release();
		pTreeNode = NULL;
	}

	return pSprite;
}


//
// szFileName = <Sprite Image File Name>.png
// nZOrder for this sprite
GSprite* GameObjectCreation::CreateStaticSprite(const tchar* szPngFileName, const int32 nZOrder)
{
	if(NULL == szPngFileName)
		return NULL;

	if(Cocos2dxGeneral::GetInstance()->GetDefaultLayer() == NULL)
	{
		GTLogManager::GetInstance()->LogError(CTEXT("Cocos2dxGeneral::GetInstance()->GetDefaultLayer() == NULL"));
		return NULL;
	}

	// Create new sprite object
	GSpriteCocos2dx *pSprite = new GSpriteCocos2dx();
	if(NULL == pSprite)
		return NULL;
	// Save the key
	pSprite->m_strKey = szPngFileName;

	pSprite->m_pSprite = cocos2d::CCSprite::create(szPngFileName);
	if(NULL == pSprite)
		return NULL;

	// Add the sprite as a child to the specified layer with z-order
	//pSprite->m_nZOrder = nZOrder;
	Cocos2dxGeneral::GetInstance()->GetDefaultLayer()->addChild(
		pSprite->m_pSprite,
		nZOrder//pSprite->m_nZOrder
		);
	pSprite->m_pLayer = Cocos2dxGeneral::GetInstance()->GetDefaultLayer();

	return pSprite;
}


// szFileName = <Sprite Image File Name>.png
SpriteAtlas* GameObjectCreation::CreateSpriteAtlas(const tchar* szFileName, const int32 nZOrder)
{
	if(NULL == szFileName)
		return NULL;

	// Create new sprite object
	SpriteAtlas* pSpriteAtlas = new SpriteAtlasCocos2dx();
	if(NULL == pSpriteAtlas)
		return NULL;

	if(false == pSpriteAtlas->Initialize(szFileName, nZOrder))
		return NULL;

	return pSpriteAtlas;
}


// Create a static sprite from .sprite GTTreeNode
GSprite* GameObjectCreation::CreateStaticSpriteFromTreeNode(GTTreeNode* pTreeNode, const int32 nZOrder)
{
	if(NULL == pTreeNode)
		return NULL;

	// Get image node
	GTTreeNode* pImageNode = pTreeNode->GetChild(GTPropertyFile::TagImage);
	if(NULL == pImageNode)
		return NULL;

	// Create the sprite
	return CreateStaticSprite(pImageNode->GetValue().ToCharString(), nZOrder);
}


// szFileName = <Sprite Image File Name>.sprite
GSprite* GameObjectCreation::CreateStaticSpriteWithSpriteFile(const tchar* szFileName, const int32 nZOrder)
{
	if(NULL == szFileName)
		return NULL;

	// Load the sprite file
	GTTreeNode* pTreeNode = GTPropertyFile::Load(szFileName);
	if(pTreeNode == NULL)
		return NULL;
	
	// Create the sprite
	GSprite *pSprite = CreateStaticSpriteFromTreeNode(pTreeNode, nZOrder);
	if(NULL == pSprite)
		GTLogManager::GetInstance()->LogFormatError(CTEXT("Failed to call CreateStaticSprite for '%s'"), szFileName);

	// Release the file
	if(pTreeNode)
	{
		pTreeNode->Release();
		pTreeNode = NULL;
	}

	return pSprite;
}


// Clone a static sprite
GSprite* GameObjectCreation::CloneStaticSprite(GSprite* pSpriteSource, const int32 nZOrder)
{
	if(NULL == pSpriteSource)
		return NULL;

	GSpriteCocos2dx* pSpriteSourceCC = (GSpriteCocos2dx*)pSpriteSource;
	if(NULL == pSpriteSourceCC || NULL == pSpriteSourceCC->m_pSprite)
		return NULL;

	if(Cocos2dxGeneral::GetInstance()->GetDefaultLayer() == NULL)
	{
		GTLogManager::GetInstance()->LogError(CTEXT("Cocos2dxGeneral::GetInstance()->GetDefaultLayer() == NULL"));
		return NULL;
	}

	// Create new sprite object
	GSpriteCocos2dx *pSprite = new GSpriteCocos2dx();
	if(NULL == pSprite)
		return NULL;
	// Save the key
	pSprite->m_strKey = pSpriteSourceCC->m_strKey;

	// Create new sprite from the texture
	pSprite->m_pSprite = cocos2d::CCSprite::createWithTexture(
		pSpriteSourceCC->m_pSprite->getTexture(),
		pSpriteSourceCC->m_pSprite->getTextureRect()
		);
	if(NULL == pSprite->m_pSprite)
		return NULL;

	// Add the sprite as a child to the specified layer with z-order
	//pSprite->m_nZOrder = GameGeneral::GetInstance()->GetZOrderIdSprite();
	Cocos2dxGeneral::GetInstance()->GetDefaultLayer()->addChild(
		pSprite->m_pSprite,
		nZOrder//pSprite->m_nZOrder
		);
	pSprite->m_pLayer = Cocos2dxGeneral::GetInstance()->GetDefaultLayer();

	return pSprite;
}


// Create an animated sprite from GTTreeNode
GSprite* GameObjectCreation::CreateAnimatedSpriteFromTreeNode(GTTreeNode* pTreeNode, const int32 nZOrder)
{
	if(NULL == pTreeNode)
		return NULL;

	// Get Image node
	GTTreeNode* pNodeImage = pTreeNode->FindChild(GTPropertyFile::TagImage);
	if(pNodeImage == NULL)
		GTLogManager::GetInstance()->LogFormatError(CTEXT("[%s] tag not found"), GTPropertyFile::TagImage);
	// Get plist node
	GTTreeNode* pNodePlist = pTreeNode->FindChild(GTPropertyFile::TagPlist);
	if(pNodePlist == NULL)
		GTLogManager::GetInstance()->LogFormatError(CTEXT("[%s] tag not found"), GTPropertyFile::TagPlist);
	// Get animation node
	GTTreeNode* pNodeAnimation = pTreeNode->FindChild(GTPropertyFile::TagAnimation);
	if(pNodeAnimation == NULL)
		GTLogManager::GetInstance()->LogFormatError(CTEXT("[%s] tag not found"), GTPropertyFile::TagAnimation);
	// Get animation clip count
	const int32 nAnimationClipCount = pNodeAnimation->GetChildCount();
	if(nAnimationClipCount == 0)
		GTLogManager::GetInstance()->LogError(CTEXT("nAnimationClipCount == 0"));

	if(Cocos2dxGeneral::GetInstance()->GetDefaultLayer() == NULL)
	{
		GTLogManager::GetInstance()->LogError(CTEXT("Cocos2dxGeneral::GetInstance()->GetDefaultLayer() == NULL"));
		return NULL;
	}

	// Create new sprite object
	GSpriteCocos2dx *pSprite = new GSpriteCocos2dx();
	if(NULL == pSprite)
		return NULL;

	// Load this sprite into the cache
	cocos2d::CCSpriteFrameCache* cacheSpriteFrame = cocos2d::CCSpriteFrameCache::sharedSpriteFrameCache();
	if(cacheSpriteFrame == NULL)
		return NULL;	
	cacheSpriteFrame->addSpriteFramesWithFile(pNodePlist->Value().ToCharString());

	// Check if animation object is loaded already
	GTString strPlistName = pNodePlist->Value();
	strPlistName.ToLower();
	GSpriteAnimationCocos2dx* pAnimationNew = ResourceManager::Inst()->FindAnimation(strPlistName);
	if(pAnimationNew == NULL)
	{
		// The animation is not loaded yet, load it into resource manager
		pAnimationNew = (GSpriteAnimationCocos2dx*)GameObjectCreation::CreateAnimationFromTreeNode(pTreeNode);
		// Add this new animation object into resource manager
		ResourceManager::Inst()->AddAnimation(pAnimationNew->m_strKey, pAnimationNew);
	}
	else
	{
		// The animation object is loaded already, add reference.
		pAnimationNew->AddReference();
	}
	pSprite->m_pAnimation = pAnimationNew;
	if(NULL == pSprite->m_pAnimation)
	{
		pSprite->Release();
		pSprite = NULL;
		GTLogManager::GetInstance()->LogError(CTEXT("pSprite->m_pAnimation == NULL : Failed to call GameObjectCreation::CreateAnimationFromTreeNode(pTreeNode)"));
		return NULL;
	}

	// Setup first animatin clip as default animation for sprite object
	GSpriteAnimationClipCocos2dx* pAnimationClip = (GSpriteAnimationClipCocos2dx*)(pSprite->m_pAnimation->GetClipByIndex(0));
	if(pAnimationClip)
	{
		cocos2d::CCSpriteFrame* pFirstSpriteFrame = pAnimationClip->GetSpriteFrameByIndex(0);
		if(pFirstSpriteFrame)
			pSprite->m_pSprite = cocos2d::CCSprite::createWithSpriteFrame(pFirstSpriteFrame);
		else
			GTLogManager::GetInstance()->LogError(CTEXT("Failed to call pAnimationClip->GetSpriteFrameByIndex(0)"));
	}
	else
	{
		GTLogManager::GetInstance()->LogError(CTEXT("Failed to call pSpriteAnimaton->GetAnimationClipByIndex(0)"));
	}

	// Add the sprite as a child to the specified layer with z-order
	Cocos2dxGeneral::GetInstance()->GetDefaultLayer()->addChild(
		pSprite->m_pSprite,
		nZOrder
		);
	pSprite->m_pLayer = Cocos2dxGeneral::GetInstance()->GetDefaultLayer();

	return pSprite;
}


// Create an animated sprite
//
// szFileName = <Sprte Data File>.sprite
GSprite* GameObjectCreation::CreateAnimatedSprite(const tchar* szFileName, const int32 nZOrder)
{
	if(NULL == szFileName)
		return NULL;

	GTTreeNode* pTreeNode = GTPropertyFile::Load(szFileName);
	if(pTreeNode == NULL)
		return NULL;

	GSprite *pSprite = CreateAnimatedSpriteFromTreeNode(pTreeNode, nZOrder);
	if(NULL == pSprite)
		GTLogManager::GetInstance()->LogFormatError(CTEXT("Failed to call CreateAnimatedSpriteFromTreeNode for '%s'"), szFileName);
	// Save the key
	((GSpriteCocos2dx*)pSprite)->m_strKey = szFileName;

	if(pTreeNode)
	{
		pTreeNode->Release();
		pTreeNode = NULL;
	}

	return pSprite;
}


// Clone an animated sprite
GSprite* GameObjectCreation::CloneAnimatedSprite(GSprite* pSpriteSource, const int32 nZOrder)
{
	if(NULL == pSpriteSource)
		return NULL;

	// Get animation object
	GSpriteAnimation* pAnimObjectSrc = pSpriteSource->GetAnimation();
	if(NULL == pAnimObjectSrc)
		return NULL;
	// Get animation clip count
	const int32 nAnimationClipCountSrc = pAnimObjectSrc->GetClipCount();
	if(nAnimationClipCountSrc == 0)
		GTLogManager::GetInstance()->LogError(CTEXT("nAnimationClipCount == 0"));

	if(Cocos2dxGeneral::GetInstance()->GetDefaultLayer() == NULL)
	{
		GTLogManager::GetInstance()->LogError(CTEXT("Cocos2dxGeneral::GetInstance()->GetDefaultLayer() == NULL"));
		return NULL;
	}

	// Create new sprite object
	GSpriteCocos2dx *pSpriteNew = new GSpriteCocos2dx();
	if(NULL == pSpriteNew)
		return NULL;
	// Save the key
	pSpriteNew->m_strKey = ((GSpriteCocos2dx*)pSpriteSource)->m_strKey;

	// Reference animation instance
	pSpriteNew->m_pAnimation = ((GSpriteCocos2dx*)pSpriteSource)->m_pAnimation;
	if(NULL == pSpriteNew->m_pAnimation)
	{
		pSpriteNew->Release();
		pSpriteNew = NULL;
		GTLogManager::GetInstance()->LogError(CTEXT("pSpriteSource->m_pAnimation == NULL"));
		return NULL;
	}
	// Add object reference
	GSpriteAnimationCocos2dx* pSpriteAnimatonNew = (GSpriteAnimationCocos2dx*)(pSpriteNew->m_pAnimation);
	pSpriteAnimatonNew->AddReference();

	/*
	// Initialize animations
	if(!pSpriteNew->InitializeAnimation())
	{
		pSpriteNew->Release();
		pSpriteNew = NULL;
		GTLogManager::GetInstance()->LogError(CTEXT("Failed to call pSprite->InitializeAnimation()"));
		return NULL;
	}
	GSpriteAnimationCocos2dx* pSpriteAnimatonNew = (GSpriteAnimationCocos2dx*)(pSpriteNew->GetAnimation());
	// Initialize the animations
	if(!pSpriteAnimatonNew->Initialize(nAnimationClipCountSrc))
	{
		pSpriteNew->Release();
		pSpriteNew = NULL;
		GTLogManager::GetInstance()->LogError(CTEXT("Failed to call pSpriteAnimaton->Initialize(nAnimationClipCount)"));
		return NULL;
	}

	GSpriteAnimationCocos2dx* pSpriteAnimatonSrc = (GSpriteAnimationCocos2dx*)pAnimObjectSrc;
	// Build up sprite frames for each animaiton clip
	for(int32 nClipIndex = 0; nClipIndex<nAnimationClipCountSrc; nClipIndex++)
	{
		GSpriteAnimationClipCocos2dx* pClipSrc = (GSpriteAnimationClipCocos2dx*)(pSpriteAnimatonSrc->GetClipByIndex(nClipIndex));
		GSpriteAnimationClipCocos2dx* pClipNew = (GSpriteAnimationClipCocos2dx*)(pSpriteAnimatonNew->GetClipByIndex(nClipIndex));
		if(pClipSrc && pClipNew)
		{
			// Get frame count of the clip
			const uint32 nClipFrameCountSrc = pClipSrc->GetFrameCount();
			// Initialize clip frames
			if(pClipNew->InitializeFrame(nClipFrameCountSrc))
			{
				for(uint32 frame=0; frame<nClipFrameCountSrc; frame++)
				{
					// Get a frame
					pClipNew->m_pAnimFrames->addObject(pClipSrc->m_pAnimFrames->objectAtIndex(frame));
				}

				// Setup frame delay time
				pClipNew->SetFrameDelayTime(pClipSrc->GetFrameDelayTime());
				// Initialize the animation
				if(pClipNew->InitializeAnimation())
				{
					// Setup the animation clip name
					pClipNew->SetClipName(pClipSrc->GetClipName());
				}
				else
				{
					pSpriteNew->Release();
					pSpriteNew = NULL;
					GTLogManager::GetInstance()->LogError(CTEXT("Failed to call pAnimationClip->InitializeAnimation()"));
					return NULL;
				}
			}
			else
			{
				pSpriteNew->Release();
				pSpriteNew = NULL;
				GTLogManager::GetInstance()->LogFormatError(CTEXT("Failed to call pAnimationClip->InitializeFrame(). [nFrameCount = %d]"), nClipFrameCountSrc);
				return NULL;
			}
		}
	}
	*/
	
	// Setup first animatin clip as default animation for sprite object
	GSpriteAnimationClipCocos2dx* pAnimationClip = (GSpriteAnimationClipCocos2dx*)(pSpriteAnimatonNew->GetClipByIndex(0));
	if(pAnimationClip)
	{
		cocos2d::CCSpriteFrame* pFirstSpriteFrame = pAnimationClip->GetSpriteFrameByIndex(0);
		if(pFirstSpriteFrame)
		{
			pSpriteNew->m_pSprite = cocos2d::CCSprite::createWithSpriteFrame(pFirstSpriteFrame);
		}
		else
		{
			GTLogManager::GetInstance()->LogError(CTEXT("Failed to call pAnimationClip->GetSpriteFrameByIndex(0)"));
		}
	}
	else
	{
		GTLogManager::GetInstance()->LogError(CTEXT("Failed to call pSpriteAnimaton->GetAnimationClipByIndex(0)"));
	}

	Cocos2dxGeneral::GetInstance()->GetDefaultLayer()->addChild(
		pSpriteNew->m_pSprite,
		nZOrder
		);
	pSpriteNew->m_pLayer = Cocos2dxGeneral::GetInstance()->GetDefaultLayer();
	pSpriteNew->SetVisible(pSpriteSource->GetVisible());

	return pSpriteNew;
}


// Create an animation object from specified GTTreeNode object
GSpriteAnimation* GameObjectCreation::CreateAnimationFromTreeNode(GTTreeNode* pTreeNode)
{
	if(NULL == pTreeNode)
		return NULL;

	// Get animation node
	GTTreeNode* pNodeAnimation = pTreeNode->FindChild(GTPropertyFile::TagAnimation);
	if(pNodeAnimation == NULL)
		GTLogManager::GetInstance()->LogFormatError(CTEXT("GameObjectCreation.[%s] tag not found"), GTPropertyFile::TagAnimation);
	// Get animation clip count
	const int32 nAnimationClipCount = pNodeAnimation->GetChildCount();
	if(nAnimationClipCount == 0)
		GTLogManager::GetInstance()->LogError(CTEXT("GameObjectCreation.nAnimationClipCount == 0"));
	// Get cocos2dx sprite cache object
	cocos2d::CCSpriteFrameCache* cacheSpriteFrame = cocos2d::CCSpriteFrameCache::sharedSpriteFrameCache();
	if(cacheSpriteFrame == NULL)
		return NULL;
	// Get Plist node
	GTTreeNode* pNodePlist = pTreeNode->FindChild(GTPropertyFile::TagPlist);

	// Initialize animations
	GSpriteAnimationCocos2dx* pNewAnimation = new GSpriteAnimationCocos2dx();
	if(pNewAnimation == NULL)
	{
		GTLogManager::GetInstance()->LogError("GSpriteCocos2dx.InitializeAnimation: m_pAnimaton == NULL");
		return NULL;
	}
	//pNewAnimation->m_strKey = (pNodePlist != NULL) ? pNodePlist->Value() : CTEXT("no-anim-key");
	// If .sprite specifis a sprite key clearly, use it. Otherwise use .plist as key.
	// If some static images are put into one .png, .sprite must specify sprite key clearly
	// in order to avoid cache issue.
	pNewAnimation->m_strKey = (pTreeNode->Value().Length() != 0) ? pTreeNode->Value() : pNodePlist->Value();

	// Initialize the animations
	if(!pNewAnimation->Initialize(nAnimationClipCount))
	{
		pNewAnimation->Release();
		pNewAnimation = NULL;
		GTLogManager::GetInstance()->LogError(CTEXT("Failed to call pNewAnimation->Initialize(nAnimationClipCount)"));
		return NULL;
	}

	// Build up sprite frames for each animaiton clip
	tchar buf[128];
	for(int32 animation = 0; animation<nAnimationClipCount; animation++)
	{
		GTTreeNode* pNodeClip = pNodeAnimation->GetChild(animation);
		if(pNodeClip)
		{
			// Get clip information
			const float fDelayTime = pNodeClip->GetChild(GTPropertyFile::TagDelayTime)->Value().ToFloat();
			const tchar* szPrefixName = pNodeClip->GetChild(GTPropertyFile::TagPrefix)->Value().ToCharString();
			const int32 nStartFrame = pNodeClip->GetChild(GTPropertyFile::TagStartFrame)->Value().ToInt();
			const int32 nEndFrame = pNodeClip->GetChild(GTPropertyFile::TagEndFrame)->Value().ToInt();

			const int32 nFrameCount = nEndFrame - nStartFrame + 1;
			GSpriteAnimationClipCocos2dx* pAnimationClip = (GSpriteAnimationClipCocos2dx*)(pNewAnimation->GetClipByIndex(animation));
			if(pAnimationClip)
			{
				// Initialize animation frames
				if(pAnimationClip->InitializeFrame(nFrameCount))
				{
					for(int32 frame=nStartFrame; frame<=nEndFrame; frame++)
					{
						tsprintf(buf, GSpriteAnimation::m_sAnimationClipNameFormat, szPrefixName, frame);
						// Get a CCSpriteFrame object by its name that is already loaded by CCSpriteFrameCache::addSpriteFramesWithFile
						cocos2d::CCSpriteFrame* spriteFrame = cacheSpriteFrame->spriteFrameByName(buf);
						if(spriteFrame)
						{
							pAnimationClip->m_pAnimFrames->addObject(spriteFrame);
						}
						else
						{
							GTLogManager::GetInstance()->LogFormatError(CTEXT("Failed to call cacheSpriteFrame->spriteFrameByName: %s"), buf);
						}
					}
					// Build the animation
					// Setup frame delay time
					pAnimationClip->SetFrameDelayTime(fDelayTime);
					// Initialize the animation
					if(pAnimationClip->InitializeAnimation())
					{
						// Setup the animation clip name
						pAnimationClip->SetClipName(pNodeClip->Value().ToCharString());
					}
					else
					{
						pNewAnimation->Release();
						pNewAnimation = NULL;
						GTLogManager::GetInstance()->LogError(CTEXT("Failed to call pAnimationClip->InitializeAnimation()"));
						return NULL;
					}
				}
				else
				{
					pNewAnimation->Release();
					pNewAnimation = NULL;
					GTLogManager::GetInstance()->LogFormatError(CTEXT("Failed to call pAnimationClip->InitializeFrame(). [nFrameCount = %d]"), nFrameCount);
					return NULL;
				}
			}
		}
	}
	
	return pNewAnimation;
}


// Create an animation object from specified .sprite file
GSpriteAnimation* GameObjectCreation::CreateAnimationFromSpriteFile(const tchar* szFileName)
{
	if(NULL == szFileName)
		return NULL;

	// Load .sprite file
	GTTreeNode* pTreeNode = GTPropertyFile::Load(szFileName);
	if(pTreeNode == NULL)
		return NULL;

	GSpriteAnimation* pNewAnimation = GameObjectCreation::CreateAnimationFromTreeNode(pTreeNode);
	
	if(pTreeNode)
	{
		pTreeNode->Release();
		pTreeNode = NULL;
	}

	return pNewAnimation;
}


// Release a sprite object created by CreateSprite or CreateAnimatedSprite
bool GameObjectCreation::ReleaseSprite(GSprite** ppSprite)
{
	if(NULL == ppSprite || NULL == (*ppSprite))
	{
		return false;
	}

	GSpriteCocos2dx* pSprite = (GSpriteCocos2dx*)(*ppSprite);
	if(NULL == pSprite)
	{
		return false;
	}

	pSprite->Release();
	pSprite = NULL;

	return true;
}


// Load a map from the name specified
cocos2d::CCTMXTiledMap* GameObjectCreation::LoadMap(const tchar* szName)
{
	if(szName == NULL)
	{
		return NULL;
	}

	if(Cocos2dxGeneral::GetInstance()->GetDefaultLayer() == NULL)
	{
		GTLogManager::GetInstance()->LogError(CTEXT("Cocos2dxGeneral::GetInstance()->GetDefaultLayer() == NULL"));
		return NULL;
	}

	cocos2d::CCTMXTiledMap *pMap = cocos2d::CCTMXTiledMap::create(szName);
	if(NULL == pMap)
	{
		GTLogManager::GetInstance()->LogError(CTEXT("Failed to load the map"));
		return NULL;
	}

	// Add this map object as the child of the layer
	Cocos2dxGeneral::GetInstance()->GetDefaultLayer()->addChild(
		pMap,
		GameGeneral::GetInstance()->GetZOrderIdMap(),
		TagManager::GetInstance()->GetTagMainMap()
		);
	// Set default position
	pMap->setPosition(cocos2d::CCPoint(0, 0));
	// Save the instance
	//MapManager::GetInstance()->SetMap(pMap);

	// Set obstacle layer invisible
	//cocos2d::CCTMXLayer *pObstacleLayer = MapManager::GetInstance()->GetObstacleLayer();

	return pMap;
}


// UILabelBMFont object
UILabelBMFont* GameObjectCreation::CreateUILabelBMFont(void)
{
	return new UILabelBMFontCocos2dx();
}


// Release a UILabelBMFont object
bool GameObjectCreation::ReleaseUILabelBMFont(UILabelBMFont** pUILabelBMFont)
{
	if(NULL == pUILabelBMFont || NULL == (*pUILabelBMFont))
		return false;

	/*
	UILabelBMFontCocos2dx* pLabel = (UILabelBMFontCocos2dx*)(*pUILabelBMFont);
	if(NULL == pLabel)
		return false;

	pLabel->Release();
	delete pLabel;
	(*pUILabelBMFont) = NULL;
	*/

	if((*pUILabelBMFont))
	{
		(*pUILabelBMFont)->Release();
		(*pUILabelBMFont) = NULL;
	}

	return true;
}
