#include "UIWidget.h"
#include "UIManager.h"
#include "../PropertyFile.h"
#include "Sprite/GSprite.h"
#include "../GameObjectCreation.h"
#include "UILabelBMFont.h"
#include "UIWidgetScript.h"

const tchar* UIWidget::m_szEventTypeNone = CTEXT("None");
const tchar* UIWidget::m_szEventTypeChildren = CTEXT("Children");
const tchar* UIWidget::m_szEventTypeAll = CTEXT("All");
// Global working variable for UIWidget
tchar g_szUIWidgetTempBuffer[32];

// Get event id from the string
int32 UIWidget::GetEventTypeIdFromString(const tchar* szTypeString)
{
	if(NULL == szTypeString)
	{
		return UIWidget::EventType_None;
	}

	if(GTString::IsEqual(szTypeString, UIWidget::m_szEventTypeNone))
	{
		return UIWidget::EventType_None;
	}
	else if(GTString::IsEqual(szTypeString, UIWidget::m_szEventTypeChildren))
	{
		return UIWidget::EventType_Children;
	}
	else if(GTString::IsEqual(szTypeString, UIWidget::m_szEventTypeAll))
	{
		return UIWidget::EventType_All;
	}

	return UIWidget::EventType_None;
}

UIWidget::UIWidget() : GTGameObject(),
	m_nState(UISpriteSet::StateEnabled),
	m_nEventType(UIWidget::EventType_All),
	m_sTooltip(GTString::EmptyString),
	m_Size(GTSize::Zero),
	m_pSkin(NULL),
	m_pSkinPiece(NULL),
	m_pFont(NULL),
	m_sText(GTString::EmptyString),
	m_pUILabelBMFont(NULL),
	m_AnchorPoint(GSprite::AnchorPoint_Center),
	m_WidgetRegion(0.0f, 0.0f, 0.0f, 0.0f)

{
	SetAnchorPoint(m_AnchorPoint);
}


UIWidget::UIWidget(UIWidget* pParent) : GTGameObject(pParent),
	m_nState(UISpriteSet::StateEnabled),
	m_nEventType(UIWidget::EventType_All),
	m_sTooltip(GTString::EmptyString),
	m_Size(GTSize::Zero),
	m_pSkin(NULL),
	m_pSkinPiece(NULL),
	m_pFont(NULL),
	m_sText(GTString::EmptyString),
	m_pUILabelBMFont(NULL),
	m_AnchorPoint(GSprite::AnchorPoint_Center),
	m_WidgetRegion(0.0f, 0.0f, 0.0f, 0.0f)
{
	SetAnchorPoint(m_AnchorPoint);
}


UIWidget::~UIWidget()
{
}


// Derived widget class must implement this method in order to
// return correct class name
const tchar* UIWidget::GetClassName(void) const
{
	return CTEXT("NoClassName");
}


void UIWidget::SetPosition(const GTPoint2& position)
{
	if(m_Sprite.HasSprite())
	{
		m_Sprite.SetPosition(position.x, position.y);
	}
	else
	{
		GTGameObject::SetPosition(position);
	}
}


void UIWidget::SetTextFromINT8(const int8 nValue)
{
	tsprintf(g_szUIWidgetTempBuffer, CTEXT("%d"), nValue);
	SetText(g_szUIWidgetTempBuffer);
}
void UIWidget::SetTextFromUINT8(const uint8 nValue)
{
	tsprintf(g_szUIWidgetTempBuffer, CTEXT("%u"), nValue);
	SetText(g_szUIWidgetTempBuffer);
}
void UIWidget::SetTextFromINT16(const int16 nValue)
{
	tsprintf(g_szUIWidgetTempBuffer, CTEXT("%d"), nValue);
	SetText(g_szUIWidgetTempBuffer);
}
void UIWidget::SetTextFromUINT16(const uint16 nValue)
{
	tsprintf(g_szUIWidgetTempBuffer, CTEXT("%u"), nValue);
	SetText(g_szUIWidgetTempBuffer);
}
void UIWidget::SetTextFromINT32(const int32 nValue)
{
	tsprintf(g_szUIWidgetTempBuffer, CTEXT("%d"), nValue);
	SetText(g_szUIWidgetTempBuffer);
}
void UIWidget::SetTextFromUINT32(const uint32 nValue)
{
	tsprintf(g_szUIWidgetTempBuffer, CTEXT("%u"), nValue);
	SetText(g_szUIWidgetTempBuffer);
}
void UIWidget::SetTextFromFloat(const float fValue)
{
	tsprintf(g_szUIWidgetTempBuffer, CTEXT("%f"), fValue);
	SetText(g_szUIWidgetTempBuffer);
}


// Set/Get AnchorPoint
void UIWidget::SetAnchorPoint(const GTVector2& anchorPoint)
{
	m_AnchorPoint = anchorPoint;
	const GTVector2 widgetPosition = GetPosition();
	// Calculate widget region
	m_WidgetRegion = GTRect(
		widgetPosition.x - m_Size.width * m_AnchorPoint.x,
		widgetPosition.y - m_Size.height * m_AnchorPoint.y,
		m_Size.width,
		m_Size.height
		);
}


// Initialize the font
bool UIWidget::InitializeFont(void)
{
	if(m_pUILabelBMFont)
	{
		return true;
	}

	// Tricky note:
	// Save the position and apply it for m_pUILabelBMFont
	// because once m_pUILabelBMFont is initialized, the position
	// will be returned by m_pUILabelBMFont->GetPosition(),
	// not GTGameObject::GetPosition().
	GTPoint2 position = GetPosition();
	m_pUILabelBMFont = GameObjectCreation::CreateUILabelBMFont();
	if(m_pUILabelBMFont)
	{
		// Initialize the font
		m_pUILabelBMFont->Initialize(GetFontName());
		// Set text
		m_pUILabelBMFont->SetText(GetText());
		// Set position
		m_pUILabelBMFont->SetPosition(position);

		return true;
	}
		
	return false;
}


// When the object is initialized, this method is called.
int32 UIWidget::OnInitialize(void)
{
	GTGameObject::OnInitialize();

	// Set AnchorPoint
	SetAnchorPoint(m_AnchorPoint);

	// If the tooltip and text are not available,
	// the font is not going to be initialized.
	if(GetTooltip().Length() || GetText().Length())
	{
		// Initialize the font
		InitializeFont();
		// Set the text
		if(m_pUILabelBMFont)
		{
			m_pUILabelBMFont->SetText(GetText().ToCharString());
			// Setup anchor point for the the lable object
			m_pUILabelBMFont->SetAnchorPoint(m_AnchorPoint);
		}
	}
		
	// Initialize sprite size
	if(m_Sprite.HasSprite())
	{
		UISkinPiece* pSkinPiece = GetSkinPiece();
		GTSize size = GetSize();
		if(pSkinPiece)
		{
			m_Sprite.SetScale(
				size.width/pSkinPiece->GetRect().size.width,
				size.height/pSkinPiece->GetRect().size.height
				);			
			// Setup anchor point for the sprite
			m_Sprite.SetAnchorPoint(m_AnchorPoint);
		}
	}
	
	return 1;
}


// When the system is updated, this method is called for each frame.
int32 UIWidget::OnUpdate(void)
{
	//GTGameObject::OnUpdate();
	// Update the widget itself
	GTGameObject::UpdateBehaviourClasses();

	// Update the font object
	if(m_pUILabelBMFont)
	{
		m_pUILabelBMFont->OnUpdate();
	}

	// Update the children
	GTGAMEOBJECT_FOREACH_CHILD(it)
	{
		((UIWidget*)(*it))->OnUpdate();
	}
	
	return 1;
}


// This method is called for rendering each frame.
int32 UIWidget::OnRender(void)
{
	GTGameObject::OnRender();

	return 1;
}


// Before the system is shut down, this method is called.
int32 UIWidget::OnDestroy(void)
{
	GTGameObject::OnDestroy();

	return 1;
}


// Single click
bool UIWidget::OnSelfSingleClick(const uint32 nFlags, const GTPoint2& pos)
{
	GTGAMEOBJECT_FOREACH_BEHAVIOUR(it)
	{
		((UIWidgetScript*)(*it))->OnSingleClick(nFlags, pos);
	}

	return false;
}


bool UIWidget::OnChildrenSingleClick(const uint32 nFlags, const GTPoint2& pos)
{
	bool handled = false;

	GTGAMEOBJECT_FOREACH_CHILD(it)
	{
		if(((UIWidget*)(*it))->OnSingleClick(nFlags, pos))
		{
			handled = true;
		}
	}

	return handled;
}


// Double click
bool UIWidget::OnSelfDoubleClick(const uint32 nFlags, const GTPoint2& pos)
{
	GTGAMEOBJECT_FOREACH_BEHAVIOUR(it)
	{
		((UIWidgetScript*)(*it))->OnDoubleClick(nFlags, pos);
	}

	return false;
}
bool UIWidget::OnChildrenDoubleClick(const uint32 nFlags, const GTPoint2& pos)
{
	bool handled = false;

	GTGAMEOBJECT_FOREACH_CHILD(it)
	{
		if(((UIWidget*)(*it))->OnDoubleClick(nFlags, pos))
		{
			handled = true;
		}
	}

	return handled;
}

// Move
bool UIWidget::OnSelfMove(const uint32 nFlags, const GTPoint2& pos, const GTPoint2& delta, bool dragging)
{
	GTGAMEOBJECT_FOREACH_BEHAVIOUR(it)
	{
		((UIWidgetScript*)(*it))->OnMove(nFlags, pos, delta, dragging);
	}

	return false;
}
bool UIWidget::OnChildrenMove(const uint32 nFlags, const GTPoint2& pos, const GTPoint2& delta, bool dragging)
{
	bool handled = false;

	GTGAMEOBJECT_FOREACH_CHILD(it)
	{
		if(((UIWidget*)(*it))->OnMove(nFlags, pos, delta, dragging))
		{
			handled = true;
		}
	}

	return handled;
}

// State chagne
bool UIWidget::OnSelfStateChange(const uint32 nState)
{
	GTGAMEOBJECT_FOREACH_BEHAVIOUR(it)
	{
		((UIWidgetScript*)(*it))->OnStateChange(nState);
	}

	return false;
}
bool UIWidget::OnChildrenStateChange(const uint32 nState)
{
	bool handled = false;

	GTGAMEOBJECT_FOREACH_CHILD(it)
	{
		if(((UIWidget*)(*it))->OnStateChange(nState))
		{
			handled = true;
		}
	}

	return handled;
}


bool UIWidget::OnSingleClick(const uint32 nFlags, const GTPoint2& pos)
{
	bool handled = false;

	if(UISpriteSet::StateDisabled == GetState())
	{
		// This widget is disabled, no further processing required.
		return false;
	}

	// If pos is not in the widget region, ignore it.
	if(!m_WidgetRegion.IsPointInRect(pos))
	{
		return false;
	}

	const int32 nEventTypeId = GetEventType();
	if(UIWidget::EventType_None == nEventTypeId)
	{
		// If the widget is marked as None, no further process.
		return false;
	}

	// Process children
	if(OnChildrenSingleClick(nFlags, pos))
	{
		handled = true;
	}

	if(UIWidget::EventType_All == nEventTypeId)
	{
		OnSelfSingleClick(nFlags, pos);
		handled = true;
	}
		
	return handled;
}


bool UIWidget::OnDoubleClick(const uint32 nFlags, const GTPoint2& pos)
{
	/*
	GTGAMEOBJECT_FOREACH_CHILD(it)
	{
		((UIWidget*)(*it))->OnDoubleClick(nFlags, pos);
	}
	*/

	return false;
}


bool UIWidget::OnMove(const uint32 nFlags, const GTPoint2& pos, const GTPoint2& delta, bool dragging)
{
	/*
	GTGAMEOBJECT_FOREACH_CHILD(it)
	{
		((UIWidget*)(*it))->OnMove(nFlags, pos, delta, dragging);
	}
	*/

	return false;
}


bool UIWidget::OnStateChange(const uint32 nState)
{
	/*
	GTGAMEOBJECT_FOREACH_CHILD(it)
	{
		((UIWidget*)(*it))->OnStateChange(nState);
	}
	*/
		
	return false;
}


// Override GTObject::Release to do more things
void UIWidget::Release(void)
{
	// Release the children
	const int32 nChildCount = GetChildCount();
	for(int32 i=0; i<nChildCount; i++)
	{
		UIWidget* pChild = (UIWidget*)GetChild(i);
		if(pChild)
		{
			pChild->OnDestroy();
			pChild = NULL;
		}
	}

	// Release the sprite object
	m_Sprite.Release();

	// Release UILabelBMFont object
	if(m_pUILabelBMFont)
	{
		m_pUILabelBMFont->Release();
		m_pUILabelBMFont = NULL;
	}

	GTGameObject::Release();
	
	return;
}


static void ProcessWidgetState(UIWidget* pWidget, GTTreeNode* pTreeNode, const tchar* szTag, const int32 nState)
{
	if(NULL == pWidget || NULL == pTreeNode || NULL == szTag || nState >= UISpriteSet::StateCount)
	{
		return;
	}

	GTTreeNode* pPieceNode = pTreeNode->FindChild(szTag);
	if(pPieceNode)
	{
		UISkin* pWidgetSkin = pWidget->GetSkin();
		if(pWidgetSkin)
		{
			UISkinPiece* pSkinPiece = pWidgetSkin->FindPieceByName(pPieceNode->GetValue().ToCharString());
			if(pSkinPiece)
			{
				pWidget->SetSkinPiece(pSkinPiece);
				pWidget->SetSprite(pWidgetSkin->m_pSpriteAtlas->AddSprite(pSkinPiece->GetRect()), nState);
			}
		}
	}
}

// Override this method to serialize specific properties
bool UIWidget::OnSerializeFrom(GTTreeNode* pTreeNode)
{
	if(NULL == pTreeNode)
	{
		return false;
	}

	// Set the name
	SetName(pTreeNode->GetValue().ToCharString());

	// Skin
	GTTreeNode* pSkinNode = pTreeNode->FindChild(PropertyFile::TagSkin);
	if(pSkinNode)
	{
		// If this tree node includes Skin node, create it.
		UISkin* pSkin = UIManager::GetInstance()->FindSkin(pSkinNode->GetValue().ToCharString());
		if(NULL == pSkin)
		{
			// If this skin doesn't exist, load it.
			pSkin = UIManager::GetInstance()->LoadSkin(pSkinNode->GetValue().ToCharString());
			if(pSkin)
			{
				// Assign the skin to the widget
				SetSkin(pSkin);
			}
		}
	}	
	else
	{
		// If this tree node doesn't include Skin node, use parent's skin.		
		if(GetParent())
		{
			SetSkin(GetParent()->GetSkin());
		}
	}

	// PieceEnabled
	ProcessWidgetState(this, pTreeNode, PropertyFile::TagPieceEnabled, UISpriteSet::StateEnabled);
	// PiecePressed
	ProcessWidgetState(this, pTreeNode, PropertyFile::TagPiecePressed, UISpriteSet::StatePressed);	
	// PieceDisabled
	ProcessWidgetState(this, pTreeNode, PropertyFile::TagPieceDisabled, UISpriteSet::StateDisabled);
	// Set default state
	SetState(UISpriteSet::StateEnabled);
	
	// Position
	// This position is relative to the parent's position
	GTTreeNode* pPositionNode = pTreeNode->FindChild(PropertyFile::TagPosition);
	if(pPositionNode)
	{
		GTVector2 relativePosition = pPositionNode->ValueToVector2();
		// Set absolute position
		SetPosition(GetParent()->GetPosition() + relativePosition);
		// Set relative position
		SetRelativePosition(relativePosition);
	}

	// Size
	GTTreeNode* pSizeNode = pTreeNode->FindChild(PropertyFile::TagSize);
	if(pSizeNode)
	{
		SetSize(pSizeNode->ValueToSize());
	}

	// Font
	GTTreeNode* pFontNode = pTreeNode->FindChild(PropertyFile::TagFont);
	if(pFontNode)
	{
		SetFontName(pFontNode->GetValue().ToCharString());
	}
	else
	{
		// Font not found, use parent's font
		SetFontName(GetParent()->GetFontName());
	}
	
	// Text
	GTTreeNode* pTextNode = pTreeNode->FindChild(PropertyFile::TagText);
	if(pTextNode)
	{
		SetText(pTextNode->GetValue().ToCharString());
	}
			
	// EventHandle
	GTTreeNode* pEventTypeNode = pTreeNode->FindChild(PropertyFile::TagEventType);
	if(pEventTypeNode)
	{
		SetEventType(UIWidget::GetEventTypeIdFromString(pEventTypeNode->GetValue().ToCharString()));
	}

	// Visible
	GTTreeNode* pVisibleNode = pTreeNode->FindChild(PropertyFile::TagVisible);

	// AnchorPoint
	// (0, 0) - Left-Buttom
	// (1, 1) - Right-Top
	// (0.5, 0.5) - Center
	GTTreeNode* pAnchorPoint = pTreeNode->FindChild(PropertyFile::TagAnchorPoint);
	if(pAnchorPoint)
	{
		SetAnchorPoint(pAnchorPoint->ValueToVector2());
	}

	// Behaviour
	GTTreeNode* pBehaviourNode = pTreeNode->FindChild(PropertyFile::TagBehaviour);
	if(pBehaviourNode)
	{
		PropertyFile::ApplyBehaviourForGameObject(pBehaviourNode, this, NULL);
	}

	return true;
}


// Override this method to serialize specific properties
bool UIWidget::OnSerializeTo(GTTreeNode* pTreeNode)
{
	return false;
}
