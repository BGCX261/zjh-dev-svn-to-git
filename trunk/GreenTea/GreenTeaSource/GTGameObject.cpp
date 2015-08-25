#include "GTGameObject.h"
#include "GTBehaviourClassManager.h"
#include <GTGameObjectManager.h>

#ifdef GT_DEBUG
#include <GTNew.h>
#endif // GT_DEBUG

const tchar* GTGameObject::m_szClassName = CTEXT("GTGameObject");
const tchar* GTGameObject::m_szSuperClassName = CTEXT("No-Super-Class");

const tchar* GTGameObject::GetClassNameStatic(void)
{
	return GTGameObject::m_szClassName;
}
const tchar* GTGameObject::GetSuperClassNameStatic(void)
{
	return GTGameObject::m_szSuperClassName;
}

GTGameObject::GTGameObject():
		m_bEnable(true),
		m_strName(CTEXT("no-name")),
		m_strTag(CTEXT("no-tag")),
		m_bFirstUpdate(true),
		m_Position(GTPoint2(0.0f, 0.0f)),
		m_bVisible(true),
		m_nZOrder(1),
		m_pParent(NULL),
		m_pCollisionGameObject(NULL)
{
}


GTGameObject::GTGameObject(GTGameObject *pParent)
{
	m_bEnable = true;
	m_strName = CTEXT("no-name");
	m_strTag = CTEXT("no-tag");
	m_bFirstUpdate = true;
	m_Position = GTPoint2(0.0f, 0.0f);
	m_bVisible = true;
	m_nZOrder = 1;
	m_pParent = NULL;
	m_pCollisionGameObject = NULL;
}


GTGameObject::~GTGameObject()
{
}


// Copy
bool GTGameObject::Copy(GTObject* pObjectFrom)
{
	if(NULL == pObjectFrom)
		return false;

	GTGameObject* pGameObjectSrc = static_cast<GTGameObject*>(pObjectFrom);
	// Copy game object properties
	//SetName(pGameObjectSrc->GetName());
	SetTag(pGameObjectSrc->GetTag());
	SetPosition(pGameObjectSrc->GetPosition());
	SetVisible(pGameObjectSrc->GetVisible(), true);
	SetZOrder(pGameObjectSrc->GetZOrder());
	// Copy m_pCollisionGameObject

	// Copy behaviours
	GTLIST_FOREACH(GTBehaviour*, itb, pGameObjectSrc->m_Behaviour)
	{
		GTBehaviour* pBehaviourSrc = (*itb);
		const tchar* szClassName = pBehaviourSrc->GetClassName();
		// Create new behaviour
		GTBehaviour* pNewBehaviour = AddBehaviour(szClassName);
		if(pNewBehaviour)
		{
			// Copy this behaviour
			pNewBehaviour->Copy(pBehaviourSrc);
		}
	}
	
	// Copy children
	GTLIST_FOREACH(GTGameObject*, itg, pGameObjectSrc->m_Children)
	{
		GTGameObject* pChildSrc = (*itg);		
		// Copy this child
		GTGameObject* pChildNew = GTGameObjectManager::Inst()->CloneGameObject(this, pChildSrc, pChildSrc->GetName());
	}

	return true;
}


// Clone: create an exactly new seperate object
GTGameObject* GTGameObject::Clone(const tchar* szNewName, GTGameObject* pParent)
{
	return GTGameObjectManager::Inst()->CloneGameObject(pParent, this, szNewName);
}


// This method is called when GTGameObject object is created (memory allocation).
int32 GTGameObject::OnCreate(void)
{
	return 1;
}


// When the object is initialized, this method is called.
int32 GTGameObject::OnInitialize(GTGameObjectInit* param)
{
	return 1;
}


void GTGameObject::SetDirty(void)
{
	OnDirty();
}


void GTGameObject::OnDirty(void)
{
	GTGAMEOBJECT_ON_CALL_METHOD(OnDirty);
}


int32 GTGameObject::OnStart(void)
{
	//GTGAMEOBJECT_ON_CALL_METHOD(OnStart);

	return 1;
}


// When the system is updated, this method is called for each frame.
int32 GTGameObject::OnUpdate(void)
{
	// If the game object is disabled, don't update anything.
	if(!GetEnable())
		return 1;

	// First update
	if(m_bFirstUpdate)
	{
		m_bFirstUpdate = false;
		OnStart();
		return 1;
	}

	// Update behaviour classes
	UpdateBehaviourClasses();
	// Update the children
	UpdateChildren();
	// Update collision
	OnCollisionUpdate();

	return 1;
}


// This method is called for rendering each frame.
int32 GTGameObject::OnRender(void)
{
	return 1;
}


// Before the system is shut down, this method is called.
int32 GTGameObject::OnDestroy(void)
{
	// Destroy behaviour classes
	DestroyBehaviourClasses();
	// Destroy children
	DestroyChildren();

	return 1;
}


// OnVisible is called when the the object is set visible.
void GTGameObject::OnVisible(GTGameObject *pCaller, bool bApplyForChildren)
{
	GTGAMEOBJECT_ON_CALL_BEHAVIOUR_ARG2(OnVisible, pCaller, bApplyForChildren);

	if(bApplyForChildren)
	{
		GTGAMEOBJECT_ON_CALL_CHILDREN_ARG2(OnVisible, pCaller, bApplyForChildren);
	}
}


// OnInvisible is called when the the object is set invisible.
void GTGameObject::OnInvisible(GTGameObject *pCaller, bool bApplyForChildren)
{
	GTGAMEOBJECT_ON_CALL_BEHAVIOUR_ARG2(OnInvisible, pCaller, bApplyForChildren);

	if(bApplyForChildren)
	{
		GTGAMEOBJECT_ON_CALL_CHILDREN_ARG2(OnInvisible, pCaller, bApplyForChildren);
	}
}


// This function is called when the behaviour becomes disabled or inactive.
void GTGameObject::OnDisable(void)
{
	GTGAMEOBJECT_ON_CALL_METHOD(OnDisable);
}


// This function is called when the object becomes enabled and active.
void GTGameObject::OnEnable(void)
{
	GTGAMEOBJECT_ON_CALL_METHOD(OnEnable);
}


// OnChangeZOrder is called when the the object is set with new z-order.
void GTGameObject::OnChangeZOrder(const int32 nNewZOrder)
{
	m_nZOrder = nNewZOrder;
	GTGAMEOBJECT_ON_CALL_METHOD_ARG1(OnChangeZOrder, nNewZOrder);
}


// OnChangePosition is called when the the object is set with new position.
void GTGameObject::OnChangePosition(const GTPoint2 position)
{
	GTGAMEOBJECT_ON_CALL_METHOD_ARG1(OnChangePosition, position);
}


// This function is called after a new level was loaded.
void GTGameObject::OnLevelWasLoaded(const int32 nParam)
{
	GTGAMEOBJECT_ON_CALL_METHOD_ARG1(OnLevelWasLoaded, nParam);
}


// OnCollisionEnter is called when this collider/rigidbody has begun touching another rigidbody/collider.
void GTGameObject::OnCollisionEnter(GTGameObject* pGameObject)
{
	GTGAMEOBJECT_ON_CALL_METHOD_ARG1(OnCollisionEnter, pGameObject);
}


// OnCollisionExit is called when this collider/rigidbody has stopped touching another rigidbody/collider.
void GTGameObject::OnCollisionExit(GTGameObject* pGameObject)
{
	GTGAMEOBJECT_ON_CALL_METHOD_ARG1(OnCollisionExit, pGameObject);
}


// OnCollisionStay is called once per frame for every collider/rigidbody that is touching rigidbody/collider.
void GTGameObject::OnCollisionStay(GTGameObject* pGameObject)
{
	GTGAMEOBJECT_ON_CALL_METHOD_ARG1(OnCollisionStay, pGameObject);
}


// Set visible
void GTGameObject::SetVisible(bool visible, bool bApplyForChildren)
{
	m_bVisible = visible;
	if(m_bVisible)
		OnVisible(this, bApplyForChildren);
	else
		OnInvisible(this, bApplyForChildren);
}


// Set/Get enable
void GTGameObject::SetEnable(bool enable)
{
	m_bEnable = enable;
	if(m_bEnable)
		OnEnable();
	else
		OnDisable();
}


// Destroy a child
void GTGameObject::DestroyChild(GTGameObject* pChild)
{
	if(NULL == pChild)
		return;

	// Remove this child from the list
	m_Children.Remove(pChild);
	// Call derived OnDestroy
	// Comment out this because OnDestroy will be called from Release
	//pChild->OnDestroy();
	// Release
	pChild->Release();
}


// Destroy children
void GTGameObject::DestroyChildren()
{
	// GTGAMEOBJECT_FOREACH_CHILD cannot be used for removing
	// items because existing items will move ahead to cause exceptions.
	// Here always release first object to release all.
	GTGameObject* pChild = NULL;
	while(m_Children.Count())
	{
		pChild = (*m_Children.Begin());
		DBG_ASSERT(pChild);
		if(pChild)
		{
			// Call derived OnDestroy
			// Comment this out because OnDestroy is called from Release
			//pChild->OnDestroy();
			// Release and delete this child from its parent
			pChild->Release();
			pChild = NULL;
		}
	}

	// Clear children list
	m_Children.Clear();

	/*
	GTGAMEOBJECT_FOREACH_CHILD(it)
	{
		// Call derived OnDestroy
		// Comment this out because OnDestroy is called from Release
		//(*it)->OnDestroy();
		// Release
		(*it)->Release();
	}
	*/
	/*
	for(GTList<GTGameObject*>::ObjectTypeIterator it = m_Children.Begin();
		it != m_Children.End();
		it++)
	{
		// Call derived OnDestroy
		(*it)->OnDestroy();
		// Release
		(*it)->Release();
	}
	*/	
}


// Destroy behaviour classes
void GTGameObject::DestroyBehaviourClass(GTBehaviour* pBehaviour)
{
	if(NULL == pBehaviour)
	{
		return;
	}

	// Remove this behaviour from the list
	m_Behaviour.Remove(pBehaviour);
	// Call derived OnDestroy (OnDestroy will be called from Release)
	//pBehaviour->OnDestroy();
	pBehaviour->Release();
	pBehaviour = NULL;
}


// Destroy behaviour classes
void GTGameObject::DestroyBehaviourClasses()
{
	// GTGAMEOBJECT_FOREACH_BEHAVIOUR cannot be used for removing
	// items because existing items will move forward to cause exceptions.
	// Here always release first object to release all.
	GTBehaviour* pBehaviour = NULL;
	while(m_Behaviour.Count())
	{
		pBehaviour = (*m_Behaviour.Begin());
		DBG_ASSERT(pBehaviour);
		if(pBehaviour)
		{
			// Call derived OnDestroy
			// Comment this out because OnDestroy is called from Release
			//pBehaviour->OnDestroy();
			// Release
			// Remove this behaviour from current game object behaviour list
			m_Behaviour.Remove(pBehaviour);
			// Release this behaviour
			pBehaviour->Release();
			pBehaviour = NULL;
		}
	}

	// Clear m_Behaviour list
	m_Behaviour.Clear();

	/*
	GTGAMEOBJECT_FOREACH_BEHAVIOUR(it)
	{
		// Release
		(*it)->Release();
	}
	*/
	/*
	for(GTList<GTBehaviour*>::ObjectTypeIterator it = m_Behaviour.Begin();
		it != m_Behaviour.End();
		it++)
	{
		// Call derived OnDestroy (OnDestroy will be called from Release)
		//(*it)->OnDestroy();
		// Release
		(*it)->Release();
	}
	*/	
}


// Override GTObject::Release to do more things
void GTGameObject::Release(void)
{
	// Call derived OnDestroy, releasing behaviours and children
	OnDestroy();
	// Remove this object from the parent
	GTGameObject* pParent = GetParent();
	GTGameObject* pParentFinal = (pParent != NULL) ? pParent : GTGameObjectManager::Inst()->GetRootGameObject();	
	if(pParentFinal)
	{
		pParentFinal->RemoveChild(this);
	}
	// Release
	GTObject::Release();
}


// Update behaviour classes
void GTGameObject::UpdateBehaviourClasses()
{
	GTGAMEOBJECT_FOREACH_BEHAVIOUR(it)
	{
		// Call derived OnUpdate
        if(NULL != (*it))
        {
            (*it)->OnUpdate();
        }
	}
}


// Update the children
void GTGameObject::UpdateChildren()
{
	GTGAMEOBJECT_FOREACH_CHILD(it)
	{
		// Call derived OnUpdate
        if(NULL != (*it))
        {
            (*it)->OnUpdate();            
        }
	}
}


// Add a behaviour class according to its name.
// If the class being added already exists, ignore it.
GTBehaviour* GTGameObject::AddBehaviour(const tchar* szBehaviourClassName, GTBehaviourInit* param)
{
	if(NULL == szBehaviourClassName)
	{
		return NULL;
	}
	GTBehaviour* pBehaviour = GetBehaviour(szBehaviourClassName);
	if(NULL == pBehaviour)
	{
		// The behaviour class doesn't exist so create a new instance
		pBehaviour = GTBehaviourClassManager::GetInstance()->CreateClassInstance(szBehaviourClassName);
		if(pBehaviour)
		{
			// Attach this behaviour to current game object
			pBehaviour->SetGameObject(this);
			// Call derived OnCreate
			pBehaviour->OnCreate();
			// Call derived OnInitialize
			pBehaviour->OnInitialize(param);
			// Add this behaviour to the list
			m_Behaviour.AddToTail(pBehaviour);
		}
	}

	return pBehaviour;
}

GTBehaviour* GTGameObject::AddBehaviour(const tchar* szBehaviourClassName)
{
	return AddBehaviour(szBehaviourClassName, NULL);
}


// This method is same as AddBehaviour
GTBehaviour* GTGameObject::AddComponent(const tchar* szBehaviourClassName, GTBehaviourInit* param)
{
	return AddBehaviour(szBehaviourClassName, param);
}


GTBehaviour* GTGameObject::AddComponent(const tchar* szBehaviourClassName)
{
	return AddBehaviour(szBehaviourClassName);
}


// Get a behaviour class according to its name
GTBehaviour* GTGameObject::GetBehaviour(const tchar* szBehaviourClassName)
{
	if(NULL == szBehaviourClassName)
	{
		return NULL;
	}

	GTGAMEOBJECT_FOREACH_BEHAVIOUR(it)
	{
		if(0 == StringCmp((*it)->GetClassName(), szBehaviourClassName))
		{
			// Found it
			return (*it);
		}
	}

	return NULL;
}


// Get a behaviour class according to its super class name
GTBehaviour* GTGameObject::GetBehaviourBySuperClassName(const tchar* szBehaviourSuperClassName)
{
	if(NULL == szBehaviourSuperClassName)
	{
		return NULL;
	}

	GTGAMEOBJECT_FOREACH_BEHAVIOUR(it)
	{
		if(0 == StringCmp((*it)->GetSuperClassName(), szBehaviourSuperClassName))
		{
			// Found it
			return (*it);
		}
	}

	return NULL;
}


// This method is same as GetBehaviour
GTBehaviour* GTGameObject::GetComponent(const tchar* szBehaviourClassName)
{
	return GetBehaviour(szBehaviourClassName);
}


// This method is same as GetBehaviourBySuperClassName
GTBehaviour* GTGameObject::GetComponentBySuperClassName(const tchar* szBehaviourSuperClassName)
{
	return GetBehaviourBySuperClassName(szBehaviourSuperClassName);
}


// Remove a behaviour class according to its name
bool GTGameObject::RemoveBehaviour(const tchar* szBehaviourClassName)
{
	if(NULL == szBehaviourClassName)
	{
		return false;
	}

	GTBehaviour* pBehaviour = GetBehaviour(szBehaviourClassName);
	if(pBehaviour)
	{
		DestroyBehaviourClass(pBehaviour);
		pBehaviour = NULL;
	}

	return true;
}


// This method is same as RemoveBehaviour
bool GTGameObject::RemoveComponent(const tchar* szBehaviourClassName)
{
	return RemoveBehaviour(szBehaviourClassName);
}


// Add a child which is already created
GTGameObject* GTGameObject::AddChild(GTGameObject* pGameObject)
{
	if(NULL == pGameObject)
		return NULL;

	// Add pGameObject to children list
	m_Children.AddToTail(pGameObject);
	// Setup parent
	pGameObject->SetParent(this);

	return pGameObject;
}


// Add a child. This method creates a new GTGameObject and return it
GTGameObject* GTGameObject::AddChild(const tchar* szName)
{
	GTGameObject* pGameObject = new GTGameObject();
	if(NULL == pGameObject)
	{
		return NULL;
	}
	// Setup the parent
	pGameObject->SetParent(this);
	// Setup the name
	pGameObject->SetName(szName);

	return AddChild(pGameObject);
}


GTGameObject* GTGameObject::AddChild(void)
{
	return AddChild(CTEXT("go-no-name"));
}


// Remove a child by a name
bool GTGameObject::RemoveChild(const tchar* szChildName)
{
	if(NULL == szChildName)
		return false;

	GTGameObject* pChild = FindChild(szChildName, true);
	if(pChild)
		RemoveChild(pChild);

	return true;
}


// Remove a child by its handle
bool GTGameObject::RemoveChild(GTGameObject* pChild)
{
	if(NULL == pChild)
		return false;

	m_Children.Remove(pChild);

	return true;
}


// Find a child by its name
// If bRecursive = true, the children will be searched recursively.
GTGameObject* GTGameObject::FindChild(const tchar* szName, bool bRecursive)
{
	if(NULL == szName)
	{
		return NULL;
	}

	/*
	for(GTList<GTGameObject*>::ObjectTypeIterator it = m_Children.Begin();
		it != m_Children.End();
		it++)
	{
		if(0 == StringCmp((*it)->m_strName, szName))
		{
			// Found it
			return (*it);
		}
	}
	*/
	GTGameObject* pGameObject = NULL;
	GTGAMEOBJECT_FOREACH_CHILD(it)
	{
		if(0 == StringCmp((*it)->m_strName, szName))
		{
			// Found it
			return (*it);
		}
		if(bRecursive)
		{
			// Keep looking for the target in children
			pGameObject = (*it)->FindChild(szName);
			if(pGameObject)
			{
				// Found it
				return pGameObject;
			}
		}
	}

	return NULL;
}


// Find a child by its name
GTGameObject* GTGameObject::FindChild(const tchar* szName)
{
	return FindChild(szName, false);
}


void GTGameObject::OnCollisionUpdate(void)
{
	if(NULL == m_pCollisionGameObject)
	{
		return;
	}

	//m_pCollisionGameObject->GetColl
}


// This method handles calling sequence of OnCollisionEnter/OnCollisionExit/OnCollisionStay
void GTGameObject::OnCollision(GTGameObject* pGameObject)
{
	if(NULL == pGameObject)
	{
		return;
	}

	OnCollisionEnter(pGameObject);

	/*
	// If m_pCollisionGameObject = NULL, it's first collision,
	// calling OnCollisionEnter
	if(NULL == m_pCollisionGameObject)
	{
		m_pCollisionGameObject = pGameObject;
		// First time collision
		OnCollisionEnter(m_pCollisionGameObject);
		return;
	}
	else
	{
		// The collided game object is keeping staying with current game object
		if(m_pCollisionGameObject == pGameObject)
		{
			OnCollisionStay(m_pCollisionGameObject);
			return;
		}
	}
	*/
}


void GTGameObject::SetZOrder(const int32 nZOrder)
{
	m_nZOrder = nZOrder;
	OnChangeZOrder(m_nZOrder);
}


int32 GTGameObject::GetZOrder(void) const
{
	return m_nZOrder;
}
