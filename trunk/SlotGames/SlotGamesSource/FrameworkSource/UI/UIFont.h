#ifndef _UI_FONT_H_
#define _UI_FONT_H_

#include <GTBaseDef.h>
#include "../Common/ITexture2D.h"

#define GTEXT_LEFT		0
#define GTEXT_RIGHT		1
#define GTEXT_CENTER	2
#define GTEXT_HORZMASK	0x03

#define GTEXT_TOP		0
#define GTEXT_BOTTOM	4
#define GTEXT_MIDDLE	8
#define GTEXT_VERTMASK	0x0C

typedef struct _UIFontLetterStruct
{
	int32 x;
	int32 y;
	int32 w;
	int32 h;
} UIFontLetterStruct;

class UIFont
{
public:
	UIFont();
	~UIFont();

	bool Create(const tchar* sName);
	float GetStringWidth(const tchar *string, const float fHScale, bool bMultiline) const;
	void DrawString(float x, float y, int32 align, const tchar *string, const uint32 color);
	void DrawString(float x, float y, int32 align, const tchar *string, const uint32 color, float rot, float fHScale, float fVScale);
	void Release(void);

private:
	ITexture2D*	m_pTexture;
	UIFontLetterStruct letters[256];
	float		pre[256];
	float		post[256];
	float		fHeight;
	//float		fScale;
	float		fProportion;
	//float		fRot;
	float		fTracking;
	float		fSpacing;

	uint32		dwCol;
	float		fZ;
	int32		nBlend;
};

#endif /* _UI_FONT_H_ */
