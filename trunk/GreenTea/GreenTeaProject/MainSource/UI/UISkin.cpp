#include "UISkin.h"
#include <GTGreenTea.h>
#include "PropertyFile.h"
#include "GameObjectCreation.h"
#include "GameGeneral.h"

UISkin::UISkin() : m_pSpriteAtlas(NULL)
{
}


UISkin::~UISkin()
{
}


// Create a skin from specified file name
bool UISkin::Create(const tchar* sName)
{
	if(NULL == sName)
	{
		return false;
	}

	GTTreeNode* pTreeNode = PropertyFile::Load(sName);
	if(NULL == pTreeNode)
	{
		return false;
	}

	// Texture
	GTTreeNode* pTextureNode = pTreeNode->GetChild(PropertyFile::TagTexture);
	if(pTextureNode)
	{
		m_pSpriteAtlas = GameObjectCreation::CreateSpriteAtlas(
			pTextureNode->GetValue().ToCharString(),
			GameGeneral::GetInstance()->GetZOrderIdUI());
	}

	// UISkin pieces
	GTTreeNode* pPieces = pTreeNode->GetChild(PropertyFile::TagPiece);
	if(pPieces)
	{
		const int32 nPieceCount = pPieces->GetChildCount();
		for(int32 i=0; i<nPieceCount; i++)
		{
			GTTreeNode* pPieceNode = pPieces->GetChild(i);
			if(pPieceNode)
			{
				UISkinPiece* pPiece = new UISkinPiece();
				// The name
				pPiece->SetName(pPieceNode->GetValue().ToCharString());
				// The position
				GTTreeNode* pPositionNode = pPieceNode->FindChild(PropertyFile::TagPosition);
				if(pPositionNode)
				{
					pPiece->SetPosition(pPositionNode->ValueToVector2());
				}
				// The size
				GTTreeNode* pSizeNode = pPieceNode->FindChild(PropertyFile::TagSize);
				if(pSizeNode)
				{
					pPiece->SetSize(pSizeNode->ValueToSize());
				}

				// Add this piece to the list
				m_SkinPieceList.AddToTail(pPiece);
			}
		}
	}

	if(pTreeNode)
	{
		pTreeNode->Release();
		pTreeNode = NULL;
	}

	return true;
}


void UISkin::Release(void)
{
	// Release sprite atlas
	if(m_pSpriteAtlas)
	{
		m_pSpriteAtlas->Release();
		m_pSpriteAtlas = NULL;
	}

	// Release piece list
	for(GTList<UISkinPiece*>::ObjectTypeIterator it = m_SkinPieceList.Begin();
		it != m_SkinPieceList.End();
		it++)
	{
		if((*it))
		{
			(*it)->Release();
		}
	}

	m_SkinPieceList.Clear();

	delete this;

	return;
}


// Find a piece by its name
UISkinPiece* UISkin::FindPieceByName(const tchar* szName)
{
	if(NULL == szName)
	{
		return NULL;
	}

	for(GTList<UISkinPiece*>::ObjectTypeIterator it = m_SkinPieceList.Begin();
		it != m_SkinPieceList.End();
		it++)
	{
		if((*it)->GetName() == szName)
		{
			return (*it);
		}
	}

	return NULL;
}
