#ifndef _GT_GAME_OBJECT_COLLIDER_H_
#define _GT_GAME_OBJECT_COLLIDER_H_

#include "GTGreenTea.h"
#include "GTSize.h"
#include "GTRect.h"

class GTGameObjectCollider
{
public:
	GTGameObjectCollider();
	GTGameObjectCollider(const GTGameObjectCollider& src);
	virtual ~GTGameObjectCollider();

	GTSize GetColliderSize(void) const
	{
		return m_ColliderSize;
	}
	void SetColliderSize(const GTSize& tSize)
	{
		m_ColliderSize = tSize;
	}
	GTRect GetColliderRect(void) const
	{
		return m_ColliderRect;
	}
	void SetColliderRect(const GTRect& rect)
	{
		m_ColliderRect = rect;
	}

	// Check if current collider collides with pAnotherCollider
	bool Collide(GTGameObjectCollider* pAnotherCollider);

public:
	// Collision objects
	GTSize m_ColliderSize;
	GTRect m_ColliderRect;
};

#endif /* _GT_GAME_OBJECT_COLLIDER_H_ */
