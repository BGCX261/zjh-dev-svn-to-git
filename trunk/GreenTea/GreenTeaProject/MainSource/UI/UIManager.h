#ifndef _UI_MANAGER_H_
#define _UI_MANAGER_H_

#include <GTGreenTea.h>
#include <GTSingleton.h>
#include "UISkin.h"
#include "UIFont.h"
#include "UIWidget.h"

class UIManager : public GTSingleton<UIManager>
{
public:
	UIManager();
	virtual ~UIManager();

	// When the object is initialized, this method is called.
	int32 OnInitialize(void);

	// When the system is updated, this method is called for each frame.
	int32 OnUpdate(void);

	// This method is called for rendering each frame.
	int32 OnRender(void);

	// Before the system is shut down, this method is called.
	int32 DestroySkin(void);
	int32 DestroyFont(void);
	int32 OnDestroy(void);

	// Widgets
	// Get root widget
	UIWidget* GetRootWidget()
	{
		return m_pRootWidget;
	}

	// Skins
	// Load a skin
	UISkin* LoadSkin(const tchar* sSkinName);
	// Remove a skin
	bool RemoveSkin(const tchar* sSkinName);
	// Find a skin by its name
	UISkin* FindSkin(const tchar* sSkinName);
	// Get skin count
	int32 GetSkinCount(void) const
	{
		return m_UISkin.Count();
	}

	// Fonts
	// Load a font
	bool LoadFont(const tchar* sFontName);
	// Remove a font
	bool RemoveFont(const tchar* sFontName);
	// Get font count
	int32 GetFontCount(void) const
	{
		return m_UIFont.Count();
	}

	// UI layouts
	UIWidget* CreateWidget(GTTreeNode* pWidgetTreeNode, UIWidget* pParent);
	void CreateChildrenWidget(GTTreeNode* pParentTreeNode, UIWidget* pParent);
	//void LoadWidgetContent(UIWidget* pWidget, GTTreeNode* pTreeNode, UIWidget* pParent);
	UIWidget* LoadLayout(const tchar* szLayoutName);

public:
	// Once the event of single click occurs, this callback method is called.
	// point: screen position
	static int32 OnSingleClickEventDelegate(const uint32 nFlags, const GTPoint2 point, void* pParam);
	// Once the event of double click occurs, this callback method is called.
	// point: screen position
	static int32 OnDoubleClickEventDelegate(const uint32 nFlags, const GTPoint2 point, void* pParam);
	// Once the event of movement occurs, this callback method is called.
	// point: movement
	static int32 OnMoveEventDelegate(const uint32 nFlags, const GTPoint2 point, void* pParam);

protected:
	// Root UIWidget object
	UIWidget* m_pRootWidget;
	// UISkin list
	GTDictionary<GTString, UISkin*> m_UISkin;
	// Default UISkin
	UISkin* m_pDefaultSkin;
	// UIFont list
	GTDictionary<GTString, UIFont*> m_UIFont;
	// Default UIFont
	UIFont* m_pDefaultFont;
};

#endif /* _UI_MANAGER_H_ */
