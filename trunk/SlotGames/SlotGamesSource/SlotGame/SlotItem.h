#pragma once
#include "SlotGameBehavior\BSIconLoader.h"
#include "..\BehaviourScript\BSSprite.h"



//slot item to store symobol;
class SlotItem
{
public:
	SlotItem(int symbolID,  GTGameObject* pGameObject);
	~SlotItem(void);

	bool ChangeSymbol(int symbolID);	//change sprite based on symbol id;

	GTPoint2 GetPosition() const;
	void SetPosition(GTPoint2 pos);

	bool isVisible();
	void SetVisible(bool bVisible);

	//play animation
	void PlayAnimation(const tchar* szAnimationName, const uint32 nFlags);	// Play an animation by name (check sprite file to see animation name)
	void PlayAnimation(const uint32 index, const uint32 nFlags);	// Play an animation by index (check sprite file to see animation index)

	// Is an animatino clip being played ?
	bool IsAnimationPlaying();

	//stop animation;
	void StopAnimation();

	int GetSymbolID(){ return m_symbolID;};
		
	bool operator< (const SlotItem &item) const { return GetPosition().y < item.GetPosition().y; }

	void SortSlotItemListByYPos(std::list<SlotItem*> slotItemList);
// 	 template <class ObjectType, class Compare>
// 	 void sort (ObjectTypeIterator first, ObjectTypeIterator last, Compare comp)
// 	 {
// 	  std::sort(first, last, comp);
// 	 }


	//set ZOrder for bssprite in this slot item;
	void SetZOrder(const int32 nNewZOrder);
protected:
	int32 m_symbolID;
	BSSprite * m_bsSprite;	//sprite for slot item;
};



// bool SortByYPos( SlotItem lhs,  SlotItem rhs) {	
// 	GTPoint2 l = lhs.GetPosition();
//	GTPoint2 r = rhs.GetPosition();
//	return ( l.y>r.y)?true:false; 
//}