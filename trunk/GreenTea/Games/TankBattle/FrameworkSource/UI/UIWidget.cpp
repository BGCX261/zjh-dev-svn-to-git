#include "UIWidget.h"
#include "UIManager.h"
#include <GTPropertyFile.h>
#include "Sprite/GSprite.h"
#include <GameObjectCreation.h>
#include "UILabelBMFont.h"
#include "UIWidgetScript.h"

#ifdef GT_DEBUG
#include <GTNew.h>
#endif // GT_DEBUG

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
	m_WidgetRegion(0.0f, 0.0f, 0.0f, 0.0f),
	m_nId(0xFFFFFFFF)

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


// Find children by name
UIWidget* UIWidget::FindChildByName(const tchar* szName, bool bRecursive)
{
	return static_cast<UIWidget*>(GTGameObject::FindChild(szName, bRecursive));
}
UIWidget* UIWidget::FindChildByName(const tchar* szName)
{
	return static_cast<UIWidget*>(GTGameObject::FindChild(szName));
}
// Find children by id
UIWidget* UIWidget::FindChildById(const int32 nId, bool bRecursive)
{
	UIWidget* widget = NULL;
	GTGAMEOBJECT_FOREACH_CHILD(it)
	{
		// Get widget object
		widget = (UIWidget*)(*it);
		// Check if the widget is in its region
		if(widget && widget->GetId() == nId)
		{
			return widget;
		}
		if(bRecursive)
		{
			// Keep looking for the target in children
			widget = widget->FindChildById(nId, bRecursive);
			if(widget)
			{
				// Found it
				return widget;
			}
		}
	}
	return NULL;
}
UIWidget* UIWidget::FindChildById(const int32 nId)
{
	return FindChildById(nId, false);
}


// Add an event listener
bool UIWidget::AddEventListener(	
	const int32 nEventType,
	GTString sEventName,
	GTObject* pClassInst,
	UIWidgetEventCallback pCallback,
	void* pParam
	)
{
	if(NULL == pClassInst || NULL == pCallback)
		return false;

	GTDictionary<GTString, UIWidgetEventSlot>* pEventList = GetEventList(nEventType);
	if(NULL == pEventList)
		return false;
	// Check if this specified event exists
	if(pEventList->KeyExists(sEventName))
		return false;

	UIWidgetEventSlot es;
	es.sEventName = sEventName;
	es.pClassInst = pClassInst;
	es.pCallback = pCallback;
	es.pParam = pParam;
	// Add this listener to the list
	pEventList->Add(es.sEventName, es);
	
	return true;
}


// Remove an event listener
bool UIWidget::RemoveEventListener(const int32 nEventType, GTString sEventName)
{
	GTDictionary<GTString, UIWidgetEventSlot>* pEventList = GetEventList(nEventType);
	if(NULL == pEventList)
		return false;

	// Look for listener specified by event name
	UIWidgetEventSlot es;
	if(pEventList->GetValueByKey(sEventName, es))
	{
		// Remove this event from the list
		pEventList->Remove(sEventName);
		return true;
	}

	return false;
}


// Invoke event listeners
bool UIWidget::InvokeEventListener(const int32 nEventType)
{
	if(nEventType >= UIWidgetEvent::EventTypeCount)
		return false;

	return true;
}


// Initialize the font
bool UIWidget::InitializeFont(void)
{
	if(m_pUILabelBMFont)
		return true;

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
		m_pUILabelBMFont->Initialize(GetFontName(), GetZOrder());
		// Set text
		m_pUILabelBMFont->SetText(GetText());
		// Set position
		m_pUILabelBMFont->SetPosition(position);
		// Set visible
		m_pUILabelBMFont->SetVisible(UIWidget::GetVisible());
		// Set ZOrder
		m_pUILabelBMFont->SetZOrder(UIWidget::GetZOrder());

		return true;
	}
		
	return false;
}


// When the object is initialized, this method is called.
int32 UIWidget::OnInitialize(void)
{
	GTGameObject::OnInitialize(NULL);

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


// If the object needs to be rebuilt
void UIWidget::OnDirty(void)
{
	GTGameObject::OnDirty();
}


// OnBecameVisible is called when the the object is set visible.
void UIWidget::OnVisible(GTGameObject *pCaller, bool bApplyForChildren)
{
	GTGameObject::OnVisible(pCaller, bApplyForChildren);
}


// OnBecameVisible is called when the the object is set invisible.
void UIWidget::OnInvisible(GTGameObject *pCaller, bool bApplyForChildren)
{
	GTGameObject::OnInvisible(pCaller, bApplyForChildren);
}


// This function is called when the behaviour becomes disabled or inactive.
void UIWidget::OnDisable(void)
{
	GTGameObject::OnDisable();
}


// This function is called when the object becomes enabled and active.
void UIWidget::OnEnable(void)
{
	GTGameObject::OnEnable();
}


// OnChangeZOrder is called when the the object is set with new z-order.
void UIWidget::OnChangeZOrder(const int32 nNewZOrder)
{
	GTGameObject::OnChangeZOrder(nNewZOrder);
	// Apply new z-order for sprite set
	m_Sprite.SetZOrder(nNewZOrder);
	// Nofticy behaviour
	GTGAMEOBJECT_FOREACH_BEHAVIOUR(itBehaviour)
	{
		((UIWidgetScript*)(*itBehaviour))->OnChangeZOrder(nNewZOrder);
	}
	// Notify children
	GTGAMEOBJECT_FOREACH_CHILD(itChild)
	{
		// Get widget object
		((UIWidget*)(*itChild))->OnChangeZOrder(nNewZOrder);
	}
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
	
	UIWidget* widget = NULL;
	GTGAMEOBJECT_FOREACH_CHILD(it)
	{
		// Get widget object
		widget = (UIWidget*)(*it);
		// Check if the widget is in its region
		if(widget && widget->m_WidgetRegion.IsPointInRect(pos))
		{
			if(widget->OnSingleClick(nFlags, pos))
			{
				handled = true;
			}
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


// Z-Order
void UIWidget::SetZOrder(const int32 nZOrder)
{
	GTGameObject::SetZOrder(nZOrder);
	OnChangeZOrder(nZOrder);
}


int32 UIWidget::GetZOrder(void) const
{
	return GTGameObject::GetZOrder();
}


// Visible
void UIWidget::SetVisible(bool visible, bool bApplyForChildren)
{
	GTGameObject::SetVisible(visible, bApplyForChildren);
}


bool UIWidget::GetVisible(void) const
{
	return GTGameObject::GetVisible();
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

	// Call event listeners
	//InvokeEventListener(UIWidgetEvent::EventTypeSingleClick);	
	GTDictionary<GTString, UIWidgetEventSlot>* pEventList = GetEventList(UIWidgetEvent::EventTypeSingleClick);
	if(pEventList)
	{
		UIWidgetEventSlot es;
		GTDictionary<GTString, UIWidgetEventSlot>::ObjectTypeIterator it, itNext;
		// First item
		it = pEventList->Begin();
		while(it != pEventList->End())
		{			
			itNext = it;
			// Point to next item
			itNext++;
			// Invoke callback
			es = it->second;
			if(false == (es.pClassInst->*es.pCallback)(this, nFlags, es.pParam))
			{
				// Removing this event from the list
				pEventList->Remove(it);
			}
			// Process next item
			it = itNext;
		}
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
	// Release events
	for(int32 i=0; i<UIWidgetEvent::EventTypeCount; i++)
	{
		m_EventList[i].Clear();
	}

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
		GameObjectCreation::ReleaseUILabelBMFont(&m_pUILabelBMFont);
		//m_pUILabelBMFont->Release();
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
				GSprite* pSpriteSkinPiece = pWidgetSkin->m_pSpriteAtlas->AddSprite(pSkinPiece->GetRect());
				if(pSpriteSkinPiece)
					pWidget->SetSprite(pSpriteSkinPiece, nState);
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

	// ZOrder must be setup before Skin because it requires a z-order
	GTTreeNode* pZOrder = pTreeNode->FindChild(GTPropertyFile::TagZOrder);
	if(pZOrder)
		SetZOrder(pZOrder->ValueToInt());
	else
	{
		// If ZOrder is not specified, apply parent's z-order
		if(GetParent())
			SetZOrder(GetParent()->GetZOrder());
	}

	// Skin
	GTTreeNode* pSkinNode = pTreeNode->FindChild(GTPropertyFile::TagSkin);
	if(pSkinNode)
	{
		// If this tree node includes Skin node, create it.
		UISkin* pSkin = UIManager::GetInstance()->FindSkin(pSkinNode->GetValue().ToCharString());
		if(NULL == pSkin)
		{
			// If this skin doesn't exist, load it.
			pSkin = UIManager::GetInstance()->LoadSkin(pSkinNode->GetValue().ToCharString(), GetZOrder());
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
			
	// Id
	GTTreeNode* pId = pTreeNode->FindChild(GTPropertyFile::TagId);
	if(pId)
		SetId(pId->ValueToUInt());
	else
		SetId(0xFFFFFFFF);
		
	// PieceEnabled
	ProcessWidgetState(this, pTreeNode, GTPropertyFile::TagPieceEnabled, UISpriteSet::StateEnabled);
	// PiecePressed
	ProcessWidgetState(this, pTreeNode, GTPropertyFile::TagPiecePressed, UISpriteSet::StatePressed);
	// PieceDisabled
	ProcessWidgetState(this, pTreeNode, GTPropertyFile::TagPieceDisabled, UISpriteSet::StateDisabled);
	// Set default state
	SetState(UISpriteSet::StateEnabled);
		
	// Position
	// This position is relative to the parent's position
	GTTreeNode* pPositionNode = pTreeNode->FindChild(GTPropertyFile::TagPosition);
	if(pPositionNode)
	{
		GTVector2 relativePosition = pPositionNode->ValueToVector2();
		// Set absolute position
		SetPosition(GetParent()->GetPosition() + relativePosition);
		// Set relative position
		SetRelativePosition(relativePosition);
	}

	// Size
	GTTreeNode* pSizeNode = pTreeNode->FindChild(GTPropertyFile::TagSize);
	if(pSizeNode)
	{
		SetSize(pSizeNode->ValueToSize());
	}

	// Font
	GTTreeNode* pFontNode = pTreeNode->FindChild(GTPropertyFile::TagFont);
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
	GTTreeNode* pTextNode = pTreeNode->FindChild(GTPropertyFile::TagText);
	if(pTextNode)
	{
		SetText(pTextNode->GetValue().ToCharString());
	}
			
	// EventHandle
	GTTreeNode* pEventTypeNode = pTreeNode->FindChild(GTPropertyFile::TagEventType);
	if(pEventTypeNode)
	{
		SetEventType(UIWidget::GetEventTypeIdFromString(pEventTypeNode->GetValue().ToCharString()));
	}

	// Visible
	GTTreeNode* pVisibleNode = pTreeNode->FindChild(GTPropertyFile::TagVisible);
	if(pVisibleNode)
		SetVisible(pVisibleNode->ValueToBool(), true);
	
	// AnchorPoint
	// (0, 0) - Left-Buttom
	// (1, 1) - Right-Top
	// (0.5, 0.5) - Center
	GTTreeNode* pAnchorPoint = pTreeNode->FindChild(GTPropertyFile::TagAnchorPoint);
	if(pAnchorPoint)
		SetAnchorPoint(pAnchorPoint->ValueToVector2());
	else // If there is no AnchorPoint defined, set default to center
		SetAnchorPoint(GSprite::AnchorPoint_Center);
		
	// Behaviour
	GTTreeNode* pBehaviourNode = pTreeNode->FindChild(GTPropertyFile::TagBehaviour);
	if(pBehaviourNode)
	{
		GTPropertyFile::ApplyBehaviourForGameObject(pBehaviourNode, this, NULL);
	}

	return true;
}


// Override this method to serialize specific properties
bool UIWidget::OnSerializeTo(GTTreeNode* pTreeNode)
{
	return false;
}
