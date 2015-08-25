#include "UIManager.h"
#include <GTInputManager.h>
#include "EventNameManager.h"
#include <GTLog/GTLogManager.h>
#include <GTGreenTea.h>
#include <GTPropertyFile.h>
#include "UIWidgetClassManager.h"

#ifdef GT_DEBUG
#include <GTNew.h>
#endif // GT_DEBUG

GTSINGLETON_IMP(UIManager);

// Once the event of single click occurs, this callback method is called.
int32 UIManager::OnSingleClickEventDelegate(const uint32 nFlags, const GTPoint2 point, void* pParam)
{
	//GTLogManager::GetInstance()->LogComment(CTEXT("UIManager::OnSingleClickEventDelegate called"));

	return UIManager::GetInstance()->GetRootWidget()->OnChildrenSingleClick(nFlags, point) ? 1 : 0;
}


// Once the event of double click occurs, this callback method is called.
// point: screen position
int32 UIManager::OnDoubleClickEventDelegate(const uint32 nFlags, const GTPoint2 point, void* pParam)
{
	//GTLogManager::GetInstance()->LogComment(CTEXT("UIManager::OnDoubleClickEventDelegate called"));

	UIManager::GetInstance()->GetRootWidget()->OnDoubleClick(nFlags, point);

	return 0;
}


// Once the event of movement occurs, this callback method is called.
// point: movement
int32 UIManager::OnMoveEventDelegate(const uint32 nFlags, const GTPoint2 point, void* pParam)
{
	//GTLogManager::GetInstance()->LogComment(CTEXT("UIManager::OnMoveEventDelegate called"));

	UIManager::GetInstance()->GetRootWidget()->OnMove(nFlags, point, GTPoint2(0, 0), false);

	return 0;
}


UIManager::UIManager():
	m_pDefaultSkin(NULL),
	m_pDefaultFont(NULL)
{
}


UIManager::~UIManager()
{
}


// When the object is initialized, this method is called.
int32 UIManager::OnInitialize(void)
{
	// Create root widget object
	m_pRootWidget = new UIWidget(NULL);
	if(NULL == m_pRootWidget)
	{
		GTLogManager::GetInstance()->LogError(CTEXT("Failed to new root widget UIWidget(NULL)"));
	}
	m_pRootWidget->SetName("UIWidgetRoot");

	// Register single click event for UIManager
	if(!GTInputManager::GetInstance()->RegisterEvent(
		GTInputManager::EventType_SingleClick,
		EventNameManager::GetInstance()->EventName_UIManagerSingleClick,
		UIManager::OnSingleClickEventDelegate,
		this
		))
	{
		GTLogManager::GetInstance()->LogFormatError(
			CTEXT("Failed to call RegisterSingleClickEvent for %s"),
			EventNameManager::GetInstance()->EventName_UIManagerSingleClick
			);
		return 1;
	}
	// Register double click event for UIManager
	if(!GTInputManager::GetInstance()->RegisterEvent(
		GTInputManager::EventType_DoubleClick,
		EventNameManager::GetInstance()->EventName_UIManagerDoubleClick,
		UIManager::OnDoubleClickEventDelegate,
		this
		))
	{
		GTLogManager::GetInstance()->LogFormatError(
			CTEXT("Failed to call RegisterDoubleClickEvent for %s"),
			EventNameManager::GetInstance()->EventName_UIManagerDoubleClick
			);
		return 1;
	}
	// Register move event for UIManager
	if(!GTInputManager::GetInstance()->RegisterEvent(
		GTInputManager::EventType_Move,
		EventNameManager::GetInstance()->EventName_UIManagerMove,
		UIManager::OnMoveEventDelegate,
		this
		))
	{
		GTLogManager::GetInstance()->LogFormatError(
			CTEXT("Failed to call RegisterDoubleClickEvent for %s"),
			EventNameManager::GetInstance()->EventName_UIManagerMove
			);
		return 1;
	}

	return 1;
}


// When the system is updated, this method is called for each frame.
int32 UIManager::OnUpdate(void)
{
	// Update the widgets
	if(m_pRootWidget)
	{
		m_pRootWidget->OnUpdate();
	}

	return 1;
}


// This method is called for rendering each frame.
int32 UIManager::OnRender(void)
{
	return 1;
}


// Release skins
int32 UIManager::DestroySkin(void)
{
	// Release UISkin list
	UISkin* pSkin = NULL;
	// Release each UISkin object
	for(GTDictionary<GTString, UISkin*>::ObjectTypeIterator it = m_UISkin.Begin();
		it != m_UISkin.End();
		it++)
	{
		pSkin = GTDictionaryGetValue((*it));
		if(pSkin)
		{
			pSkin->Release();
			pSkin = NULL;
		}
	}
	m_UISkin.Clear();

	return 1;
}


// Release fonts
int32 UIManager::DestroyFont(void)
{
	UIFont* pFont = NULL;
	// Release each UIFont object
	for(GTDictionary<GTString, UIFont*>::ObjectTypeIterator it = m_UIFont.Begin();
		it != m_UIFont.End();
		it++)
	{
		pFont = GTDictionaryGetValue((*it));
		if(pFont)
		{
			pFont->Release();
			pFont = NULL;
		}
	}
	m_UIFont.Clear();

	return 1;
}


// Before the system is shut down, this method is called.
int32 UIManager::OnDestroy(void)
{
	// Release widgets
	if(m_pRootWidget)
	{
		m_pRootWidget->Release();
		m_pRootWidget = NULL;
	}
		
	// Release UISkin list
	DestroySkin();	
	// Release UIFont list
	DestroyFont();

	// Unregister the event of single click
	GTInputManager::GetInstance()->UnregisterEvent(
		GTInputManager::EventType_SingleClick,
		EventNameManager::GetInstance()->EventName_UIManagerSingleClick
		);
	// Unregister the event of double click
	GTInputManager::GetInstance()->UnregisterEvent(
		GTInputManager::EventType_DoubleClick,
		EventNameManager::GetInstance()->EventName_UIManagerDoubleClick
		);
	// Unregister the event of move
	GTInputManager::GetInstance()->UnregisterEvent(
		GTInputManager::EventType_Move,
		EventNameManager::GetInstance()->EventName_UIManagerMove
		);

	return 1;
}


// Load a skin
UISkin* UIManager::LoadSkin(const tchar* sSkinName, const int32 nZOrder)
{
	if(NULL == sSkinName)
	{
		return NULL;
	}

	// Load the skin
	UISkin* pSkin = new UISkin();
	if(NULL == pSkin)
	{
		return NULL;
	}
	if(false == pSkin->Create(sSkinName, nZOrder))
	{
		pSkin->Release();
		pSkin = NULL;
	}

	// Add the skin object into the dictionary
	m_UISkin.Add(GTString(sSkinName), pSkin);

	return pSkin;
}


// Find a skin by its name
UISkin* UIManager::FindSkin(const tchar* sSkinName)
{
	if(NULL == sSkinName)
	{
		return NULL;
	}
	
	if(m_UISkin.KeyExists(GTString(sSkinName)))
	{
		UISkin *pSkin = NULL;
		if(m_UISkin.GetValueByKey(sSkinName, pSkin))
		{
			return pSkin;
		}
	}

	return NULL;
}


// Remove a skin
bool UIManager::RemoveSkin(const tchar* sSkinName)
{
	if(NULL == sSkinName)
	{
		return false;
	}

	if(m_UISkin.KeyExists(GTString(sSkinName)))
	{
		UISkin *pSkin = NULL;
		if(m_UISkin.GetValueByKey(sSkinName, pSkin))
		{
			if(pSkin)
			{
				// Release the skin object
				pSkin->Release();
				pSkin = NULL;
			}
		}
		// Remove the skin object from the dictionary
		m_UISkin.Remove(sSkinName);
	}

	return true;
}


// Load a font
bool UIManager::LoadFont(const tchar* sFontName)
{
	if(NULL == sFontName)
	{
		return false;
	}

	// Load the font
	// Add the font object into the dictionary

	//m_UIFont.Add(GTString(szFontName, 

	return true;
}


// Remove a font
bool UIManager::RemoveFont(const tchar* sFontName)
{
	if(NULL == sFontName)
	{
		return false;
	}
	
	if(m_UIFont.KeyExists(GTString(sFontName)))
	{
		UIFont *pFont = NULL;
		if(m_UIFont.GetValueByKey(sFontName, pFont))
		{
			if(pFont)
			{
				// Release the font object
				pFont->Release();
				pFont = NULL;
			}
		}
		// Remove the font object from the dictionary
		m_UIFont.Remove(sFontName);
	}

	return true;
}


void UIManager::CreateChildrenWidget(GTTreeNode* pParentTreeNode, UIWidget* pParent)
{
	if(NULL == pParentTreeNode || NULL == pParent)
	{
		return;
	}

	GTTreeNode* pChildrenNode = pParentTreeNode->FindChild(GTPropertyFile::TagChildren);
	if(pChildrenNode)
	{
		const int32 nChildCount = pChildrenNode->GetChildCount();
		for(int i=0; i<nChildCount; i++)
		{
			GTTreeNode* pWidgetNode = pChildrenNode->GetChild(i);
			if(pWidgetNode)
			{
				UIWidget* pNewWidget = UIWidgetClassManager::GetInstance()->CreateClassInstance(pWidgetNode->GetTag().ToCharString());
				if(pNewWidget)
				{
					// Set the parent
					pNewWidget->SetParent(pParent);
					// Serialize properties for this widget from the tree node
					pNewWidget->OnSerializeFrom(pWidgetNode);		
					// Call OnInitialize
					pNewWidget->OnInitialize();
					// Create the children
					CreateChildrenWidget(pWidgetNode, pNewWidget);
					
					if(pParent)
					{
						pParent->AddChild(pNewWidget);
					}
				}
			}
		}
	}
}


// Create a widget from a GTTreeNode object with its parent
UIWidget* UIManager::CreateWidget(GTTreeNode* pWidgetTreeNode, UIWidget* pParent)
{
	if(NULL == pWidgetTreeNode)
	{
		return NULL;
	}

	// Create an instance according to widget type
	UIWidget* pNewWidget = UIWidgetClassManager::GetInstance()->CreateClassInstance(pWidgetTreeNode->GetTag().ToCharString());
	if(pNewWidget)
	{
		// Set the parent
		pNewWidget->SetParent(pParent);
		// Serialize properties for this widget from the tree node
		pNewWidget->OnSerializeFrom(pWidgetTreeNode);		
		// Call OnInitialize
		pNewWidget->OnInitialize();
		// Create children
		CreateChildrenWidget(pWidgetTreeNode, pNewWidget);
		
		if(pParent)
		{
			pParent->AddChild(pNewWidget);
		}
	}

	return pNewWidget;
}


// UI layouts
UIWidget* UIManager::LoadLayout(const tchar* szLayoutName)
{
	UIWidget* pWidget = NULL;

	if(NULL == szLayoutName)
	{
		return NULL;
	}

	GTTreeNode* pTreeNode = GTPropertyFile::Load(szLayoutName);
	if(NULL == pTreeNode)
	{
		return NULL;
	}

	// Get the top UI widget
	GTTreeNode* pLayoutRoot = pTreeNode->GetChild(0);
	if(pLayoutRoot)
	{
		pWidget = CreateWidget(pLayoutRoot, m_pRootWidget);
	}

	if(pTreeNode)
	{
		pTreeNode->Release();
		pTreeNode = NULL;
	}

	return pWidget;
}
