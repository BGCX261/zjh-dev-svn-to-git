#ifndef _UI_LABEL_BM_FONT_H_
#define _UI_LABEL_BM_FONT_H_

#include <GTGreenTea.h>

class UILabelBMFont
{
public:
	UILabelBMFont();
	virtual ~UILabelBMFont();

	// Initialize the font
	virtual bool Initialize(const char* szFontName) = 0;
	virtual bool Initialize(const char* szText, const char* szFontName) = 0;
	// Set the text
	virtual void SetText(const char* szText) = 0;
	// Set visible
	virtual void SetVisible(bool visible) = 0;
	// Set position
	virtual void SetPosition(const float x, const float y) = 0;
	virtual void SetPosition(const GTPoint2& position) = 0;
	virtual GTPoint2 GetPosition(void) = 0;
	// Set/Get anchor point
	virtual void SetAnchorPoint(const GTVector2& anchorPoint) = 0;
	virtual GTVector2 GetAnchorPoint(void) const = 0;
	// Release
	virtual bool Release(void) = 0;
	// Update
	virtual void OnUpdate(void) = 0;
};

#endif /* _UI_LABEL_BM_FONT_H_ */
