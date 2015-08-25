#include <GTBaseDef.h>
#include "GameObjectCreation.h"
#include <GTLog/GTLogManager.h>
#include <MapManager.h>
#include <TagManager.h>
#include "GSpriteCocos2dx.h"
#include "Cocos2dxGeneral.h"
#include "GSpriteAnimationCocos2dx.h"
#include "SpriteAtlasCocos2dx.h"
#include <PropertyFile.h>
#include <GameGeneral.h>
#include <UI/UILabelBMFont.h>
#include "UILabelBMFontCocos2dx.h"

// Create a normal sprite without animations, just an image
//
// szFileName = <Sprite Image File Name>.sprite
// nZOrder for this sprite
GSprite* GameObjectCreation::CreateStaticSprite(const tchar* szFileName, const int32 nZOrder)
{
	if(NULL == szFileName)
	{
		return NULL;
	}

	if(Cocos2dxGeneral::GetInstance()->GetDefaultLayer() == NULL)
	{
		GTLogManager::GetInstance()->LogError(CTEXT("Cocos2dxGeneral::GetInstance()->GetDefaultLayer() == NULL"));
		return NULL;
	}

	GSpriteCocos2dx *pSprite = new GSpriteCocos2dx();
	if(NULL == pSprite)
	{
		return NULL;
	}

	pSprite->m_pSprite = cocos2d::CCSprite::create(szFileName);
	if(NULL == pSprite)
	{
		return NULL;
	}
	// Add the sprite as a child to the specified layer
	Cocos2dxGeneral::GetInstance()->GetDefaultLayer()->addChild(
		pSprite->m_pSprite,
		nZOrder
		);
	pSprite->m_pLayer = Cocos2dxGeneral::GetInstance()->GetDefaultLayer();

	return pSprite;
}


// szFileName = <Sprite Image File Name>.png
SpriteAtlas* GameObjectCreation::CreateSpriteAtlas(const tchar* szFileName, const int32 nZOrder)
{
	if(NULL == szFileName)
	{
		return NULL;
	}

	SpriteAtlas* pSpriteAtlas = new SpriteAtlasCocos2dx();
	if(NULL == pSpriteAtlas)
	{
		return NULL;
	}

	if(false == pSpriteAtlas->Initialize(szFileName, nZOrder))
	{
		return NULL;
	}

	return pSpriteAtlas;
}


// szFileName = <Sprite Image File Name>.sprite
GSprite* GameObjectCreation::CreateStaticSpriteWithSpriteFile(const tchar* szFileName, const int32 nZOrder)
{
	if(NULL == szFileName)
	{
		return NULL;
	}

	// Load the sprite file
	GTTreeNode* pTreeNode = PropertyFile::Load(szFileName);
	if(pTreeNode == NULL)
	{
		return NULL;
	}
	
	// Get image node
	GTTreeNode* pImageNode = pTreeNode->GetChild(PropertyFile::TagImage);
	if(NULL == pImageNode)
	{
		return NULL;
	}
	// Create the sprite
	GSprite *pSprite = CreateStaticSprite(pImageNode->GetValue().ToCharString(), nZOrder);
	if(NULL == pSprite)
	{
		GTLogManager::GetInstance()->LogFormatError(CTEXT("Failed to call CreateStaticSprite for '%s'"), szFileName);
	}

	if(pTreeNode)
	{
		pTreeNode->Release();
		pTreeNode = NULL;
	}

	return pSprite;
}


GSprite* GameObjectCreation::CreateAnimatedSpriteFromTreeNode(GTTreeNode* pTreeNode, const int32 nZOrder)
{
	if(NULL == pTreeNode)
	{
		return NULL;
	}

	// Get Image node
	GTTreeNode* pNodeImage = pTreeNode->FindChild(PropertyFile::TagImage);
	if(pNodeImage == NULL)
		GTLogManager::GetInstance()->LogFormatError(CTEXT("[%s] tag not found"), PropertyFile::TagImage);
	// Get plist node
	GTTreeNode* pNodePlist = pTreeNode->FindChild(PropertyFile::TagPlist);
	if(pNodePlist == NULL)
		GTLogManager::GetInstance()->LogFormatError(CTEXT("[%s] tag not found"), PropertyFile::TagPlist);
	// Get animation node
	GTTreeNode* pNodeAnimation = pTreeNode->FindChild(PropertyFile::TagAnimation);
	if(pNodeAnimation == NULL)
		GTLogManager::GetInstance()->LogFormatError(CTEXT("[%s] tag not found"), PropertyFile::TagAnimation);
	// Get animation clip count
	const int32 nAnimationClipCount = pNodeAnimation->GetChildCount();
	if(nAnimationClipCount == 0)
		GTLogManager::GetInstance()->LogError(CTEXT("nAnimationClipCount == 0"));

	if(Cocos2dxGeneral::GetInstance()->GetDefaultLayer() == NULL)
	{
		GTLogManager::GetInstance()->LogError(CTEXT("Cocos2dxGeneral::GetInstance()->GetDefaultLayer() == NULL"));
		return NULL;
	}

	GSpriteCocos2dx *pSprite = new GSpriteCocos2dx();
	if(NULL == pSprite)
	{
		return NULL;
	}

	cocos2d::CCSpriteFrameCache* cache = cocos2d::CCSpriteFrameCache::sharedSpriteFrameCache();
	if(cache == NULL)
	{
		return NULL;
	}
	// Load this sprite into the cache
	cache->addSpriteFramesWithFile(pNodePlist->Value().ToCharString());
	// Initialize animations
	if(!pSprite->InitializeAnimation())
	{
		GTLogManager::GetInstance()->LogError(CTEXT("Failed to call pSprite->InitializeAnimation()"));
		return NULL;
	}
	GSpriteAnimationCocos2dx* pSpriteAnimaton = (GSpriteAnimationCocos2dx*)(pSprite->GetAnimation());
	// Initialize the animations
	if(!pSpriteAnimaton->Initialize(nAnimationClipCount))
	{
		GTLogManager::GetInstance()->LogError(CTEXT("Failed to call pSpriteAnimaton->Initialize(nAnimationClipCount)"));
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
			const float fDelayTime = pNodeClip->GetChild(PropertyFile::TagDelayTime)->Value().ToFloat();
			const tchar* szPrefixName = pNodeClip->GetChild(PropertyFile::TagPrefix)->Value().ToCharString();
			const int32 nStartFrame = pNodeClip->GetChild(PropertyFile::TagStartFrame)->Value().ToInt();
			const int32 nEndFrame = pNodeClip->GetChild(PropertyFile::TagEndFrame)->Value().ToInt();

			const int32 nFrameCount = nEndFrame - nStartFrame + 1;
			GSpriteAnimationClipCocos2dx* pAnimationClip = pSpriteAnimaton->GetClipByIndex(animation);
			if(pAnimationClip)
			{
				// Initialize animation frames
				if(pAnimationClip->InitializeFrame(nFrameCount))
				{
					for(int32 frame=0; frame<nFrameCount; frame++)
					{
						tsprintf(buf, GSpriteAnimation::m_sAnimationClipNameFormat, szPrefixName, frame+1);
						// Get a CCSpriteFrame object by its name that is already loaded by CCSpriteFrameCache::addSpriteFramesWithFile
						cocos2d::CCSpriteFrame* spriteFrame = cache->spriteFrameByName(buf);
						if(spriteFrame)
						{
							pAnimationClip->m_pAnimFrames->addObject(spriteFrame);
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
						GTLogManager::GetInstance()->LogError(CTEXT("Failed to call pAnimationClip->InitializeAnimation()"));
						return NULL;
					}
				}
				else
				{
					GTLogManager::GetInstance()->LogFormatError(CTEXT("Failed to call pAnimationClip->InitializeFrame(). [nFrameCount = %d]"), nFrameCount);
					return NULL;
				}
			}
		}
	}
	
	// Setup first animatin clip as default animation for sprite object
	GSpriteAnimationClipCocos2dx* pAnimationClip = pSpriteAnimaton->GetClipByIndex(0);
	if(pAnimationClip)
	{
		cocos2d::CCSpriteFrame* pFirstSpriteFrame = pAnimationClip->GetSpriteFrameByIndex(0);
		if(pFirstSpriteFrame)
		{
			pSprite->m_pSprite = cocos2d::CCSprite::createWithSpriteFrame(pFirstSpriteFrame);
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

	// Add the sprite as a child to the specified layer
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
	{
		return NULL;
	}

	GTTreeNode* pTreeNode = PropertyFile::Load(szFileName);
	if(pTreeNode == NULL)
	{
		return NULL;
	}

	GSprite *pSprite = CreateAnimatedSpriteFromTreeNode(pTreeNode, nZOrder);
	if(NULL == pSprite)
	{
		GTLogManager::GetInstance()->LogFormatError(CTEXT("Failed to call CreateAnimatedSpriteFromTreeNode for '%s'"), szFileName);
	}

	if(pTreeNode)
	{
		pTreeNode->Release();
		pTreeNode = NULL;
	}

	return pSprite;
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
