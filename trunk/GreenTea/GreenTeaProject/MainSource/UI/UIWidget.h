#ifndef _UI_WIDGET_H_
#define _UI_WIDGET_H_

#include <GTGreenTea.h>
#include <GTClassAutoInstance.h>
#include "UISkin.h"
#include "UIFont.h"
#include "UISpriteSet.h"

class UILabelBMFont;

// Add the variables and methods into the derived class to store the class name
#define UIWIDGET_DEF(className,baseClassName) GTCLSAUTOINST_DEF(className,baseClassName)
// Implement the variable and methods to store the class name
#define UIWIDGET_IMP(className,baseClassName,pfnCallback) GTCLSAUTOINST_IMP(className,baseClassName,pfnCallback)

class UIWidget : public GTGameObject
{
public:
	UIWidget();
	UIWidget(UIWidget* pParent);
	virtual ~UIWidget();

public:
	// Override GTGameObject::GetParent to return correct type of the parent
	virtual UIWidget* GetParent(void)
	{
		return (UIWidget*)GTGameObject::GetParent();
	}

	// When the object is initialized, this method is called.
	virtual int32 OnInitialize(void);

	// When the system is updated, this method is called for each frame.
	virtual int32 OnUpdate(void);

	// This method is called for rendering each frame.
	virtual int32 OnRender(void);

	// Before the system is shut down, this method is called.
	virtual int32 OnDestroy(void);

	// Override GTObject::Release to do more things
	virtual void Release(void);

	// Override this method to serialize specific properties
	virtual bool OnSerializeTo(GTTreeNode* pTreeNode);
	// Override this method to serialize specific properties
	virtual bool OnSerializeFrom(GTTreeNode* pTreeNode);
		
	// Derived widget class must implement this method in order to
	// return correct class name.
	// This method is implemented by UIWIDGET_IMP(your_class)
	virtual const tchar* GetClassName(void) const;

	// Initialize the font
	bool InitializeFont(void);

	// Set position
	virtual void SetPosition(const float x, const float y)
	{
		m_Sprite.SetPosition(x, y);
	}
	virtual void SetPosition(const GTPoint2& position);
	// Get position
	virtual GTPoint2 GetPosition(void) const
	{
		return m_Sprite.HasSprite() ? m_Sprite.GetPosition() : GTGameObject::GetPosition();
	}

	// Widget events
	// If those event handlers return true, it means the event is processed.
	virtual bool OnSingleClick(const uint32 nFlags, const GTPoint2& pos);
	virtual bool OnDoubleClick(const uint32 nFlags, const GTPoint2& pos);
	virtual bool OnMove(const uint32 nFlags, const GTPoint2& pos, const GTPoint2& delta, bool dragging);
	virtual bool OnStateChange(const uint32 nState);

	// Single click
	bool OnSelfSingleClick(const uint32 nFlags, const GTPoint2& pos);
	bool OnChildrenSingleClick(const uint32 nFlags, const GTPoint2& pos);
	// Double click
	bool OnSelfDoubleClick(const uint32 nFlags, const GTPoint2& pos);
	bool OnChildrenDoubleClick(const uint32 nFlags, const GTPoint2& pos);
	// Move
	bool OnSelfMove(const uint32 nFlags, const GTPoint2& pos, const GTPoint2& delta, bool dragging);
	bool OnChildrenMove(const uint32 nFlags, const GTPoint2& pos, const GTPoint2& delta, bool dragging);
	// State chagne
	bool OnSelfStateChange(const uint32 nState);
	bool OnChildrenStateChange(const uint32 nState);

	// Set/Get AnchorPoint
	void SetAnchorPoint(const GTVector2& anchorPoint);
	GTVector2 GetAnchorPoint(void) const { return m_AnchorPoint; }
	// Widget region
	GTRect GetRegion(void) const { return m_WidgetRegion; }

	//void Initialize(const UIWidget* pParent, const tchar* szName);
	//UIWidget* FindWidget(const int32 x, const int32 y);
	//UIWidget* FindWidget(const tchar* szName);
	//UIWidget* FindWidget(const tchar* szName, bool bRecursive);	
	//void Destroy(void);
	//void Draw(void);
	//void OnValueChange();
	//void OnAddWidget(UIWidget child);
	//void OnRemoveWidget(UIWidget child);
	//bool OnPreUpdate(bool dimensionsChanged);
	//bool OnFocus(bool hasFocus);
	//bool OnMouseButton(KeyCode key, Vector2 pos, bool isDown);
	
	// Widget type
	//UIButton
	//UICheckbox
	//UIEditableLabel
	//UIFrame
	//UIImageButton
	//UIInput
	//UILabel
	//UIList
	//UIMenu
	//UIPanel
	//UIPasswordInput
	//UIPasswordLabel
	//UIPicture
	//UIScrollbar
	//UIScrollView
	//UIWindow

public:
	// Get tool tip
	void GetTooltip(tchar* sTooltip) const
	{
		StringCopy(sTooltip, m_sTooltip.ToCharString());
	}
	GTString GetTooltip(void)
	{
		return m_sTooltip;
	}
	// Set tool tip
	void SetTooltip(const tchar* sTooltip)
	{		
		m_sTooltip = GTString(sTooltip);
	}

	// Set/Get size
	void SetSize(GTSize size)
	{
		m_Size = size;
	}
	GTSize GetSize(void) const
	{
		return m_Size;
	}

	// Set/Get skin
	void SetSkin(UISkin *pSkin)
	{
		m_pSkin = pSkin;
	}
	UISkin* GetSkin(void)
	{
		return m_pSkin;
	}

	// Set/Get UI skin
	void SetSkinPiece(UISkinPiece* pPiece)
	{
		m_pSkinPiece = pPiece;
	}
	UISkinPiece* GetSkinPiece(void)
	{
		return m_pSkinPiece;
	}

	// Set/Get Font
	void SetFont(UIFont* pFont)
	{
		m_pFont = pFont;
	}
	UIFont* GetFont(void)
	{
		return m_pFont;
	}
	void SetFontName(const tchar* szFontName)
	{
		m_sFontName = szFontName;
	}
	void SetFontName(const GTString szFontName)
	{
		m_sFontName = szFontName;
	}
	GTString GetFontName(void) const
	{
		return m_sFontName;
	}

	// Set/Get sprite
	void SetSprite(GSprite* pSprite, const int32 nState)
	{
		m_Sprite.SetSprite(pSprite, nState);
	}
	GSprite* GetSprite(const int32 nState)
	{
		return m_Sprite.GetSprite(nState);
	}

	// Set/Get text
	virtual void SetText(const tchar* szText)
	{
		m_sText = szText;
	}
	void SetTextFromINT8(const int8 nValue);
	void SetTextFromUINT8(const uint8 nValue);
	void SetTextFromINT16(const int16 nValue);
	void SetTextFromUINT16(const uint16 nValue);
	void SetTextFromINT32(const int32 nValue);
	void SetTextFromUINT32(const uint32 nValue);
	void SetTextFromFloat(const float fValue);
	GTString GetText(void)
	{
		return m_sText;
	}

	// Set/Get relative position
	void SetRelativePosition(const GTVector2& position)
	{
		m_RelativePosition = position;
	}
	GTVector2 GetRelativePosition(void) const
	{
		return m_RelativePosition;
	}

	// Get/Set event type
	void SetEventType(const int32 nEventType)
	{
		m_nEventType = nEventType;
	}
	int32 GetEventType(void) const
	{
		return m_nEventType;
	}

	// Get/Set state
	void SetState(const int32 nState)
	{
		m_nState = nState;
		m_Sprite.SetVisible(true, nState);
	}
	int32 GetState(void) const
	{
		return m_nState;
	}

	// Get UISpriteSet
	UISpriteSet* GetSpriteSet(void)
	{
		return &m_Sprite;
	}

protected:
	// State
	int32 m_nState;
	// Event type
	int32 m_nEventType;
	// The sprite object
	UISpriteSet m_Sprite;
	// Tooltip
	GTString m_sTooltip;
	// Size
	GTSize m_Size;
	// Skin
	UISkin* m_pSkin;
	// Piece
	UISkinPiece* m_pSkinPiece;
	// Font	
	UIFont* m_pFont;
	GTString m_sFontName;
	// UILabelBMFont object
	UILabelBMFont* m_pUILabelBMFont;
	// Text
	GTString m_sText;
	// Relative position to the parent
	GTVector2 m_RelativePosition;
	// AnchorPoint
	GTVector2 m_AnchorPoint;
	// Widget region
	GTRect m_WidgetRegion;

public:
	// Get event id from the string
	static int32 GetEventTypeIdFromString(const tchar* szTypeString);

	// Event type ids
	// Both the widget and children don't handle the events
	static const int32 EventType_None = 0;
	// Only the children handle the events, the widget doesn't
	static const int32 EventType_Children = 1;
	// Both the widget and children handle the events
	static const int32 EventType_All = 2;
	// Event flags
	static const uint32 Flag_ClickUp = 0x00000001;
	static const uint32 Flag_ClickDown = 0x00000020;
	// Event type string
	static const tchar* m_szEventTypeNone;
	static const tchar* m_szEventTypeChildren;
	static const tchar* m_szEventTypeAll;
};

#endif /* _UI_WIDGET_H_ */
