#include "GTGameObjectCollider.h"

GTGameObjectCollider::GTGameObjectCollider():
	m_ColliderSize(GTSize::Zero),
	m_ColliderRect(GTRect::Zero)
{
}


GTGameObjectCollider::GTGameObjectCollider(const GTGameObjectCollider& src)
{
	m_ColliderSize = src.m_ColliderSize;
	m_ColliderRect = src.m_ColliderRect;
}

GTGameObjectCollider::~GTGameObjectCollider()
{
}


// Check if current collider collides with pAnotherCollider
bool GTGameObjectCollider::Collide(GTGameObjectCollider* pAnotherCollider)
{
	if(NULL == pAnotherCollider)
	{
		return false;
	}
	
	return m_ColliderRect.Collide(pAnotherCollider->m_ColliderRect);
}
