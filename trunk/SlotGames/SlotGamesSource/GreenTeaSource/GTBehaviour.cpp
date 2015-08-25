#include "GTGameObject.h"
#include "GTBehaviour.h"
#include "GTBehaviourClassManager.h"

// GTBehaviourClassContainer
GTBehaviourClassContainer::GTBehaviourClassContainer(
	const tchar* szClassName,
	CreateBehaviourClassDefine pfn
	)
{
	m_szClassName = szClassName;
	m_pfnCreateBehaviourClass = pfn;

	// Add this to GTBehaviourClassManager
	GTBehaviourClassManager::GetInstance()->AddClass(this);
}

GTBehaviourClassContainer::~GTBehaviourClassContainer()
{
	m_szClassName = NULL;
	m_pfnCreateBehaviourClass = NULL;
}


// GTBehaviour
GTBehaviour::GTBehaviour():
	m_pGameObject(NULL),
	m_bFirstUpdate(true)
{
}

GTBehaviour::GTBehaviour(GTGameObject* pGO):
	m_bFirstUpdate(true)
{
	m_pGameObject = pGO;
}

GTBehaviour::~GTBehaviour()
{
	OnDestroy();
}

// Set position for the game object
void GTBehaviour::SetGameObjectPosition(const GTPoint2& pos)
{
	DBG_ASSERT(m_pGameObject);
	m_pGameObject->SetPosition(pos.x, pos.y);
}
void GTBehaviour::SetGameObjectPosition(const float x, const float y)
{
	DBG_ASSERT(m_pGameObject);
	m_pGameObject->SetPosition(x, y);
}

// Get position for the game object
GTPoint2 GTBehaviour::GetGameObjectPosition(void) const
{
	DBG_ASSERT(m_pGameObject);
	return m_pGameObject->GetPosition();
}

int32 GTBehaviour::OnCreate(void)
{
	return 1;
}

int32 GTBehaviour::OnInitialize(GTBehaviourInitParam* param)
{
	return 1;
}

int32 GTBehaviour::OnStart(void)
{
	return 1;
}

int32 GTBehaviour::OnUpdate(void)
{
	if(m_bFirstUpdate)
	{
		m_bFirstUpdate = false;
		OnStart();
		return 1;
	}

	return 1;
}

int32 GTBehaviour::OnDestroy(void)
{
	return 1;
}


// If this GTBehaviour needs to be rebuilt
void GTBehaviour::OnDirty(void)
{
}


// OnBecameVisible is called when the the object is set visible.
void GTBehaviour::OnVisible(void)
{
}


// OnBecameVisible is called when the the object is set invisible.
void GTBehaviour::OnInvisible(void)
{
}


// This function is called when the behaviour becomes disabled or inactive.
void GTBehaviour::OnDisable(void)
{
}


// This function is called when the object becomes enabled and active.
void GTBehaviour::OnEnable(void)
{
}


// OnChangeZOrder is called when the the object is set with new z-order.
void GTBehaviour::OnChangeZOrder(const int32 nNewZOrder)
{
}


// This function is called after a new level was loaded.
void GTBehaviour::OnLevelWasLoaded(const int32 nParam)
{
}


// OnCollisionEnter is called when this collider/rigidbody has begun touching another rigidbody/collider.
void GTBehaviour::OnCollisionEnter(GTGameObject* pGameObject)
{
}


// OnCollisionExit is called when this collider/rigidbody has stopped touching another rigidbody/collider.
void GTBehaviour::OnCollisionExit(GTGameObject* pGameObject)
{
}


// OnCollisionStay is called once per frame for every collider/rigidbody that is touching rigidbody/collider.
void GTBehaviour::OnCollisionStay(GTGameObject* pGameObject)
{
}


// Copy
bool GTBehaviour::Copy(GTObject* pObjectFrom)
{
	GTBehaviour* pBehaviourSrc = static_cast<GTBehaviour*>(pObjectFrom);

	return true;
}
