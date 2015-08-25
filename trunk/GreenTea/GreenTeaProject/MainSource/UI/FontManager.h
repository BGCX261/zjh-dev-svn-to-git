#ifndef _FONT_MANAGER_H_
#define _FONT_MANAGER_H_

#include <GTSingleton.h>
#include "UIFont.h"

class FontManager : public GTSingleton<FontManager>
{
public:
	FontManager();
	~FontManager();

	// Initialize
	void Initialize(void);
	// Destroy
	void Destroy(void);

public:
	UIFont* m_pFont1;
	UIFont* m_pFont2;
};

#endif /* _FONT_MANAGER_H_ */
