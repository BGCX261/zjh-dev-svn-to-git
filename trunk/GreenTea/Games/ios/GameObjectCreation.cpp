#include "GameObjectCreation.h"
#include "TextureCocos2d.h"

// Create a Texture2D object from a texture file
ITexture2D* GameObjectCreation::CreateTexture2D(const tchar* szFileName)
{
	if(NULL == szFileName)
	{
		return NULL;
	}
	
	// Load the sprite object using cocos2d
	//CCSprite* ps = [CCSprite spriteWithFile:szFileName];
	
	/*
	 HGE* pHge = GetHgeObject();
	 if(NULL == pHge)
	 {
	 return NULL;
	 }
	 
	 Texture2DHGE* ps = new Texture2DHGE();
	 if(NULL == ps)
	 {
	 return NULL;
	 }
	 // Load the texture object
	 ps->m_hTexture = pHge->Texture_Load(szFileName);
	 if(!ps->m_hTexture)
	 {
	 return NULL;
	 }
	 // Create the sprite object
	 const int w = pHge->Texture_GetWidth(ps->m_hTexture);
	 const int h = pHge->Texture_GetHeight(ps->m_hTexture);
	 ps->m_pSprite = new hgeSprite(ps->m_hTexture, 0, 0, (float)w, (float)h);
	 if(NULL == ps->m_pSprite)
	 {
	 ps->Release();
	 delete ps;
	 ps = NULL;
	 }
	 
	 return (ITexture2D*)ps;
	 */
	
	return NULL;
}


// Release a Texture2D object
bool GameObjectCreation::ReleaseTexture2D(ITexture2D** ppTexture)
{
	if(NULL == ppTexture)
	{
		return false;
	}
	
	/*
	 Texture2DHGE* pTexture = (Texture2DHGE*)(*ppTexture);
	 if(NULL == pTexture)
	 {
	 return false;
	 }
	 
	 pTexture->Release();
	 delete pTexture;
	 pTexture = NULL;
	 (*ppTexture) = NULL;
	 */
	
	return true;
}
