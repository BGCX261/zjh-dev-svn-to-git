#include "SlotItem.h"
#include <GTGameObjectManager.h>
#include "BehaviourScript\BSSprite.h"
#include <algorithm>


#ifdef GT_DEBUG
#include <GTNew.h>
#endif // GT_DEBUG
#include "UI\UIDef.h"


SlotItem::SlotItem(int symbolID, GTGameObject* pGameObject)
	: m_symbolID(0),m_bsSprite(NULL)
{
	//based on gameobject and gsprite to create BSSprite;
	GSprite *pReelIconSprite = BSIconLoader::GetInstance()->GetReelIcon(symbolID);
	if(pReelIconSprite)
	{
		m_bsSprite = dynamic_cast<BSSprite *> (pGameObject->AddBehaviour("BSSprite"));

		if(pReelIconSprite == NULL)
		{
			GTLogManager::GetInstance()->LogError("GTSprite is null! Please check!");
			assert(pReelIconSprite);
		}
		else
		{			
			//need copy GSprite into a new instance to show			
			GSprite* newReelIconSprite = (GSprite*)(pReelIconSprite->Clone());
			m_bsSprite->m_pSprite = newReelIconSprite;
			
			//get pos;
			GTPoint2 relativePos = pGameObject->GetPosition();
			GTPoint2 parentPos = pGameObject->GetParent()->GetPosition();
			GTPoint2 pos = parentPos + relativePos;
			SetPosition(pos);

			m_symbolID = symbolID;
			SetZOrder(UI_ZOrder::NORMAL_SLOT);	//set zorder
		}		
	}
}

SlotItem::~SlotItem(void)
{
	//release old GSprite;
	if(m_bsSprite)
	{
		if(m_bsSprite->m_pSprite != NULL)
		{
			m_bsSprite->m_pSprite->Release();
			m_bsSprite->m_pSprite = NULL;
		}
	}
}



//************************************
// Method:    ChangeSprite
// FullName:  SlotItem::ChangeSprite
// Access:    public 
// Returns:   bool
// Qualifier: change sprite based on icon id;
// Parameter: int uniqueIconID   : icon ID
//************************************
bool SlotItem::ChangeSymbol(int symbolID)
{	
	bool res = false;

	//same icon id, doesnt need change;
	if(symbolID == m_symbolID)
		return true;

	//release old GSprite;
	if(m_bsSprite->m_pSprite != NULL)
	{
		m_bsSprite->m_pSprite->Release();
		m_bsSprite->m_pSprite = NULL;
	}
	
	//clone new sprite and copy it to BSSprite;	
	GSprite *pReelIconSprite = BSIconLoader::GetInstance()->GetReelIcon(symbolID);
	if(pReelIconSprite == NULL)
	{
		GTLogManager::GetInstance()->LogError("GTSprite is null! Please check!");
		assert(pReelIconSprite);		
	}
	else
	{			
		//need copy GSprite into a new instance to show			
		GSprite* newReelIconSprite = (GSprite*)(pReelIconSprite->Clone());
		m_bsSprite->m_pSprite = newReelIconSprite;
		m_symbolID = symbolID;
		res = true;
		
		SetZOrder(UI_ZOrder::NORMAL_SLOT);	//set zorder
	}		
	return res;
}

bool SlotItem::isVisible()
{
	return m_bsSprite->m_pSprite->GetVisible();
}

void SlotItem::SetVisible(bool bVisible)
{
	m_bsSprite->m_pSprite->SetVisible(bVisible);
}

GTPoint2 SlotItem::GetPosition() const
{
	return (m_bsSprite ? m_bsSprite->GetGameObjectPosition() : GTPoint2::Zero);
}

void SlotItem::SetPosition(GTPoint2 pos)
{
	m_bsSprite->SetGameObjectPosition(pos);
}

// Play an animation by name (check sprite file to see animation name)
void SlotItem::PlayAnimation(const tchar* szAnimationName, const uint32 nFlags)
{
	if((m_bsSprite == NULL) || (m_bsSprite->m_pSprite == NULL))
		return;

	m_bsSprite->m_pSprite->PlayAnimationByName(szAnimationName, nFlags);
}

// Play an animation by index (check sprite file to see animation index)
void SlotItem::PlayAnimation(const uint32 index, const uint32 nFlags)
{
	if((m_bsSprite == NULL) || (m_bsSprite->m_pSprite == NULL))
		return;

	m_bsSprite->m_pSprite->PlayAnimationByIndex(index, nFlags);	
}

// Is an animatino clip being played ?
bool SlotItem::IsAnimationPlaying()
{
	if((m_bsSprite == NULL) || (m_bsSprite->m_pSprite == NULL))
		return false;

	return m_bsSprite->m_pSprite->IsAnimationPlaying();
}

void SlotItem::StopAnimation()
{
	if((m_bsSprite == NULL) || (m_bsSprite->m_pSprite == NULL))
		return;

	m_bsSprite->m_pSprite->StopAnimation();
}

//set ZOrder for bssprite in this slot item;
void SlotItem::SetZOrder(const int32 nNewZOrder)
{
	m_bsSprite->SetZOrder(nNewZOrder);
}


//************************************
// Method:    SortSlotItemListByPos
// FullName:  SlotItem::SortSlotItemListByPos
// Access:    public static 
// Returns:   void
// Qualifier:  sort list by position, small -> large
// Parameter: GTList<SlotItem * > slotItemList   :
//************************************
void SlotItem::SortSlotItemListByYPos(std::list<SlotItem*> slotItemList)
{
	//std::sort(slotItemList.begin(), slotItemList.end(), SortByYPos);
	slotItemList.sort();
}
