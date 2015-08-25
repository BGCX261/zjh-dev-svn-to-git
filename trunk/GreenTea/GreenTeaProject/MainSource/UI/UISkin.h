#ifndef _UI_SKIN_H_
#define _UI_SKIN_H_

#include <GTBaseDef.h>
#include "../Common/SpriteAtlas.h"
#include <GTGreenTea.h>
#include "UISkinPiece.h"

class SpriteAtlas;

class UISkin
{
public:
	UISkin();
	~UISkin();

	// Create a skin
	bool Create(const tchar* sName);
	// Find a piece by its name
	UISkinPiece* FindPieceByName(const tchar* szName);
	// Release the skin
	void Release(void);
	// Get piece count
	int32 GetPieceCount(void) const
	{
		return m_SkinPieceList.Count();
	}

public:
	SpriteAtlas* m_pSpriteAtlas;
	GTList<UISkinPiece*> m_SkinPieceList;
};

#endif /* _UI_SKIN_H_ */
