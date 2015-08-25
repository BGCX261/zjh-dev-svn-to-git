#include "GTRect.h"

GTRect GTRect::Zero = GTRect(0.0f, 0.0f, 0.0f, 0.0f);

// If anotherRect collides with the rect.
bool GTRect::Collide(const GTRect& anotherRect) const
{
	/*
	// left-top
	if(IsPointInRect(GTVector2(
		anotherRect.origin.x,
		anotherRect.origin.y - anotherRect.size.height)))
	{
		return true;
	}	
	// right-top
	else if(IsPointInRect(GTVector2(
		anotherRect.origin.x + anotherRect.size.width,
		anotherRect.origin.y - anotherRect.size.height)))
	{
		return true;
	}
	// left-bottom
	else if(IsPointInRect(GTVector2(
		anotherRect.origin.x,
		anotherRect.origin.y)))
	{
		return true;
	}
	// right-bottom
	else if(IsPointInRect(GTVector2(
		anotherRect.origin.x + anotherRect.size.width,
		anotherRect.origin.y)))
	{
		return true;
	}
	*/

	/*
	// left-top
	if(IsPointInRect(GTVector2(
		anotherRect.origin.x,
		anotherRect.origin.y)))
	{
		return true;
	}	
	// right-top
	else if(IsPointInRect(GTVector2(
		anotherRect.origin.x + anotherRect.size.width,
		anotherRect.origin.y)))
	{
		return true;
	}
	// left-bottom
	else if(IsPointInRect(GTVector2(
		anotherRect.origin.x,
		anotherRect.origin.y + anotherRect.size.height)))
	{
		return true;
	}
	// right-bottom
	else if(IsPointInRect(GTVector2(
		anotherRect.origin.x + anotherRect.size.width,
		anotherRect.origin.y + anotherRect.size.height)))
	{
		return true;
	}
	*/

	// bLeftTopX > aLeftTopX + aWidth  b��a���ұ�
    // bLeftTopY > aLeftTopY + aHeght  b��a������
    // bLeftTopX + bWidth < aLeftTopX  b��a�����
    // bLeftTopX + bHeight < aLeftTopY b��a������
	if(anotherRect.origin.x > origin.x + size.width ||
	   anotherRect.origin.y > origin.y + size.height ||
	   anotherRect.origin.x + anotherRect.size.width < origin.x ||
	   anotherRect.origin.y + anotherRect.size.height < origin.y)
	{
		return false;
	}

	return true;
}
