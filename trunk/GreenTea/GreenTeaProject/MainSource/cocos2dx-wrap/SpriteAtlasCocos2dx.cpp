#include "SpriteAtlasCocos2dx.h"
#include "GSpriteCocos2dx.h"
#include "Cocos2dxGeneral.h"
#include "../GameGeneral.h"

SpriteAtlasCocos2dx::SpriteAtlasCocos2dx() : SpriteAtlas(),
	m_pCCSpriteBatchNode(NULL),
	m_pLayer(NULL)
{
}


SpriteAtlasCocos2dx::~SpriteAtlasCocos2dx()
{
}


// Initialize texture atlas with a texture and property file
bool SpriteAtlasCocos2dx::Initialize(const tchar* szFileName,
									 const int32 nZOrder)
{
	if(NULL == szFileName)
	{
		return false;
	}

	m_pCCSpriteBatchNode = cocos2d::CCSpriteBatchNode::create(szFileName, 50);
	if(NULL == m_pCCSpriteBatchNode)
	{
		return false;
	}
	// Add this sprite to proper layer
	Cocos2dxGeneral::GetInstance()->GetDefaultLayer()->addChild(m_pCCSpriteBatchNode, nZOrder);
	// Save this layer
	m_pLayer = Cocos2dxGeneral::GetInstance()->GetDefaultLayer();

	return true;
}


// Destroy
bool SpriteAtlasCocos2dx::Release(void)
{
	if(m_pCCSpriteBatchNode)
	{
		// Remove this sprite from the layer
		if(NULL != m_pLayer)
		{
			// The method removeChild also releases memory
			m_pLayer->removeChild(m_pCCSpriteBatchNode, true);
		}
	}

	return true;
}


// Add a sprite
GSprite* SpriteAtlasCocos2dx::AddSprite(const float tx,
										const float ty,
										const float tw,
										const float th)
{
	if(NULL == m_pCCSpriteBatchNode)
	{
		return NULL;
	}

	GSpriteCocos2dx* pSpriteCocos2dx = new GSpriteCocos2dx();
	if(pSpriteCocos2dx)
	{
		// Create CCSprite from CCSpriteBatchNode
		pSpriteCocos2dx->m_pSprite = cocos2d::CCSprite::createWithTexture(
			m_pCCSpriteBatchNode->getTexture(),
			cocos2d::CCRectMake(tx, ty, tw, th)
			);
		// Save the layer
		pSpriteCocos2dx->m_pLayer = m_pLayer;
		// Add sprite as a child of m_pCCSpriteBatchNode
		// Once m_pCCSpriteBatchNode is removed, all children will be removed.
		m_pCCSpriteBatchNode->addChild(pSpriteCocos2dx->m_pSprite);
	}

	return pSpriteCocos2dx;
}


GSprite* SpriteAtlasCocos2dx::AddSprite(const GTRect rect)
{
	return AddSprite(rect.origin.x, rect.origin.y, rect.size.width, rect.size.height);
}


// Remove a sprite
bool SpriteAtlasCocos2dx::RemoveSprite(GSprite* pSprite)
{
	if(NULL == pSprite)
	{
		return false;
	}

	if(m_pCCSpriteBatchNode)
	{
		GSpriteCocos2dx* pSpriteCocos2dx = (GSpriteCocos2dx*)pSprite;
		// Remove this sprite from m_pCCSpriteBatchNode
		m_pCCSpriteBatchNode->removeChild(pSpriteCocos2dx->m_pSprite, true);

		delete pSpriteCocos2dx;
		pSpriteCocos2dx = NULL;
	}

	return true;
}
