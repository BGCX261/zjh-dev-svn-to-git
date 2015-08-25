#ifndef _GREENTEA_GAME_OBJECT_H_
#define _GREENTEA_GAME_OBJECT_H_

#include "GTCommon/BaseDef.h"
#include "GTObject.h"
#include "GTString.h"
#include "GTList.h"
#include "GTPoint2.h"
#include "GTBasicBehaviour.h"
#include "GTBehaviour.h"

// This struct is only for OnInitialize
struct GTGameObjectInit
{
	void* pParam1;
	void* pParam2;
};

// This class represents a general game object in the scene
// and some behaviour classes deriving from GTBehaviour can
// be attached to this game object to implement logic.
class GTGameObject : public GTObject, public GTBasicBehaviour
{
public:
	GTGameObject();
	GTGameObject(GTGameObject *pParent);
	virtual ~GTGameObject();

public:
	// Class & Super class name
	static const tchar* m_szClassName;
	static const tchar* m_szSuperClassName;
	virtual const tchar* GetClassName(void) const
	{
		return GTGameObject::m_szClassName;
	}
	virtual const tchar* GetSuperClassName(void) const
	{
		return GTGameObject::m_szClassName;
	}
	static const tchar* GetClassNameStatic(void);
	static const tchar* GetSuperClassNameStatic(void);
	// If it's first update
	bool m_bFirstUpdate;

	// Copy
	virtual bool Copy(GTObject* pObjectFrom);
	// Clone: create an exactly new seperate object
	virtual GTGameObject* Clone(const tchar* szNewName, GTGameObject* pParent);
	// This method is called when GTGameObject object is created (memory allocation).
	virtual int32 OnCreate(void);
	// When the object is initialized, this method is called.
	// param - the parameter passed to this game object
	// param->pParam1 - the root GTTreeNode
	// param->pParam2 - the tree node under this game object
	virtual int32 OnInitialize(GTGameObjectInit* param);
	// OnStart is called just before any of the OnUpdate methods is called the first time.
	// OnStart is only called once in the lifetime of the behaviour.
	// The difference between OnCreate and OnStart is that OnStart is only called
	// if the script instance is enabled. This allows you to delay any initialization code,
	// until it is really needed. OnCreated is always called before any OnStart functions.
	// This allows you to order initialization of scripts.
	// The OnStart function is called after all OnCreated functions on all script instances have been called.
	virtual int32 OnStart(void);
	// When the system is updated, this method is called for each frame.
	virtual int32 OnUpdate(void);
	// This method is called for rendering each frame.
	virtual int32 OnRender(void);
	// Before the system is shut down, this method is called.
	virtual int32 OnDestroy(void);
	// Override GTObject::Release to do more things
	virtual void Release(void);
	// If the object needs to be rebuilt
	virtual void OnDirty(void);
	// OnVisible is called when the the object is set visible.
	// bApplyForChildren - if this call applies to the children
	//                     true - yes
	//                     false - no
	virtual void OnVisible(GTGameObject *pCaller, bool bApplyForChildren);
	// OnInvisible is called when the the object is set invisible.
	// bApplyForChildren - if this call applies to the children
	//                     true - yes
	//                     false - no
	virtual void OnInvisible(GTGameObject *pCaller, bool bApplyForChildren);
	// This function is called when the behaviour becomes disabled or inactive.
	virtual void OnDisable(void);
	// This function is called when the object becomes enabled and active.
	virtual void OnEnable(void);
	// OnChangeZOrder is called when the the object is set with new z-order.
	virtual void OnChangeZOrder(const int32 nNewZOrder);
	// OnChangePosition is called when the the object is set with new position.
	virtual void OnChangePosition(const GTPoint2 position);
	// This function is called after a new level was loaded.
	virtual void OnLevelWasLoaded(const int32 nParam);
	// OnCollisionEnter is called when this collider/rigidbody has begun touching another rigidbody/collider.
	virtual void OnCollisionEnter(GTGameObject* pGameObject);
	// OnCollisionExit is called when this collider/rigidbody has stopped touching another rigidbody/collider.
	virtual void OnCollisionExit(GTGameObject* pGameObject);	
	// OnCollisionStay is called once per frame for every collider/rigidbody that is touching rigidbody/collider.
	virtual void OnCollisionStay(GTGameObject* pGameObject);

	// This method handles calling sequence of OnCollisionEnter/OnCollisionExit/OnCollisionStay
	void OnCollision(GTGameObject* pGameObject);
	void OnCollisionUpdate(void);
			
	// Set the name
	void SetName(const tchar* szName)
	{
		m_strName = szName;
	}
	// Get the name
	const tchar* GetName(void)
	{
		return m_strName.ToCharString();
	}

	// Set the tag
	void SetTag(const tchar* szTag)
	{
		m_strTag = szTag;
	}
	// Get the tag
	const tchar* GetTag(void)
	{
		return m_strTag.ToCharString();
	}

	// Set the parent
	void SetParent(GTGameObject* pParent)
	{
		m_pParent = pParent;
	}
	// Get the parent
	virtual GTGameObject* GetParent(void)
	{
		return m_pParent;
	}

	// Set position
	virtual void SetPosition(const float x, const float y)
	{
		m_Position.x = x;
		m_Position.y = y;
		OnChangePosition(m_Position);
	}
	virtual void SetPosition(const GTPoint2 position)
	{
		m_Position = position;
		OnChangePosition(m_Position);
	}
	// Get position
	virtual GTPoint2 GetPosition(void) const
	{
		return m_Position;
	}

	// If this game object needs to be rebuilt
	virtual void SetDirty(void);

	// Z-Order
	virtual void SetZOrder(const int32 nZOrder);
	virtual int32 GetZOrder(void) const;

	// Set/Get visible
	// bApplyForChildren - if this call applies to the children
	//                     true - yes
	//                     false - no
	virtual void SetVisible(bool visible, bool bApplyForChildren);
	virtual bool GetVisible(void) const
	{
		return m_bVisible;
	}

	// Set/Get enable
	virtual void SetEnable(bool enable);
	virtual bool GetEnable(void) const
	{
		return m_bEnable;
	}

	// Add behaviours
	// Add a behaviour class according to its name.
	// If the class being added already exists, ignore it.
	GTBehaviour* AddBehaviour(const tchar* szBehaviourClassName, GTBehaviourInit* param);
	GTBehaviour* AddBehaviour(const tchar* szBehaviourClassName);
	// This method is same as AddBehaviour
	GTBehaviour* AddComponent(const tchar* szBehaviourClassName, GTBehaviourInit* param);
	GTBehaviour* AddComponent(const tchar* szBehaviourClassName);
	// Add a behaviour from template
	template<typename T> T* AddBehaviour(void)
	{
		return dynamic_cast<T*>(AddBehaviour(T::GetClassNameStatic));
	}
	// Get behaviours
	// Get a behaviour class according to its name
	GTBehaviour* GetBehaviour(const tchar* szBehaviourClassName);
	template<typename T> T* GetBehaviour(void)
	{
		return dynamic_cast<T*>(GetBehaviour(T::GetClassNameStatic()));
	}
	// Get a behaviour class according to its super class name
	GTBehaviour* GetBehaviourBySuperClassName(const tchar* szBehaviourSuperClassName);
	// This method is same as GetBehaviour
	GTBehaviour* GetComponent(const tchar* szBehaviourClassName);
	// This method is same as GetBehaviourBySuperClassName
	GTBehaviour* GetComponentBySuperClassName(const tchar* szBehaviourSuperClassName);
	// Remove behaviours
	// Remove a behaviour class according to its name
	bool RemoveBehaviour(const tchar* szBehaviourClassName);
	template<typename T> T* RemoveBehaviour(void)
	{
		return dynamic_cast<T*>(RemoveBehaviour(T::GetClassNameStatic));
	}
	// This method is same as RemoveBehaviour
	bool RemoveComponent(const tchar* szBehaviourClassName);
	// Add a child which is already created
	GTGameObject* AddChild(GTGameObject* pGameObject);
	// Add a child. This method creates a new GTGameObject and return it
	GTGameObject* AddChild(const tchar* szName);
	GTGameObject* AddChild(void);
	// Remove a child by a name
	bool RemoveChild(const tchar* szChildName);
	// Remove a child by its handle
	bool RemoveChild(GTGameObject* pChild);
	// Get child count
	int32 GetChildCount(void) const
	{
		return m_Children.Count();
	}
	// Get a child by its index
	GTGameObject* GetChild(const int32 index)
	{
		DBG_ASSERT(index < m_Children.Count());
		return m_Children[index];
	}
	// Find a child by its name
	// If bRecursive = true, the children will be searched recursively.
	GTGameObject* FindChild(const tchar* szName);
	template<typename T> T* FindChild(const tchar* szName)
	{
		return dynamic_cast<T*>(FindChild(szName));
	}
	GTGameObject* FindChild(const tchar* szName, bool bRecursive);
	template<typename T> T* FindChild(const tchar* szName, bool bRecursive)
	{
		return dynamic_cast<T*>(FindChild(szName, bRecursive));
	}

public:
	// Update behaviour classes
	void UpdateBehaviourClasses();
	// Update the children
	void UpdateChildren();
	// Destroy a behaviour class
	void DestroyBehaviourClass(GTBehaviour* pBehaviour);
	// Destroy behaviour classes
	void DestroyBehaviourClasses();

public:
	// Destroy a child
	void DestroyChild(GTGameObject* pChild);
	// Destroy children
	void DestroyChildren();

public:
	// Enable or disable
	bool m_bEnable;
	// Game object name
	GTString m_strName;
	// Game object tag which is a helper
	GTString m_strTag;
	// The position which is in map coordinate system
	GTPoint2 m_Position;
	// If this game object is visible
	bool m_bVisible;
	// Z-order
	int32 m_nZOrder;
	// Parent game object
	GTGameObject *m_pParent;
	// Child game objects
	GTList<GTGameObject*> m_Children;
	// GTBehaviour classes
	GTList<GTBehaviour*> m_Behaviour;
	// Current collided game object
	GTGameObject* m_pCollisionGameObject;
};

// foreach every child in m_Children
#define GTGAMEOBJECT_FOREACH_CHILD(_iterator) GTLIST_FOREACH(GTGameObject*, _iterator, m_Children)
// foreach every behaviour object in m_Behaviour
#define GTGAMEOBJECT_FOREACH_BEHAVIOUR(_iterator) GTLIST_FOREACH(GTBehaviour*, _iterator, m_Behaviour)

// On calling a method for behaviours with 2 arguments
#define GTGAMEOBJECT_ON_CALL_BEHAVIOUR_ARG2(_methodName,_arg1,_arg2) \
	GTGAMEOBJECT_FOREACH_BEHAVIOUR(_itBehaviour) \
	{ \
		(*_itBehaviour)->_methodName(_arg1,_arg2); \
	}

// On calling a method for children with 2 arguments
#define GTGAMEOBJECT_ON_CALL_CHILDREN_ARG2(_methodName,_arg1,_arg2) \
	GTGAMEOBJECT_FOREACH_CHILD(_itChild) \
	{ \
		(*_itChild)->_methodName(_arg1,_arg2); \
	}

// On calling a method for behaviours & children without arguments
#define GTGAMEOBJECT_ON_CALL_METHOD(_methodName) \
	GTGAMEOBJECT_FOREACH_BEHAVIOUR(_itBehaviour) \
	{ \
		(*_itBehaviour)->_methodName(); \
	} \
	GTGAMEOBJECT_FOREACH_CHILD(_itChild) \
	{ \
		(*_itChild)->_methodName(); \
	}
// On calling a method for behaviours & children with 1 argument
#define GTGAMEOBJECT_ON_CALL_METHOD_ARG1(_methodName,_arg1) \
	GTGAMEOBJECT_FOREACH_BEHAVIOUR(_itBehaviour) \
	{ \
		(*_itBehaviour)->_methodName(_arg1); \
	} \
	GTGAMEOBJECT_FOREACH_CHILD(_itChild) \
	{ \
		(*_itChild)->_methodName(_arg1); \
	}

// On calling a method for behaviours & children with 2 arguments
#define GTGAMEOBJECT_ON_CALL_METHOD_ARG2(_methodName,_arg1,_arg2) \
	GTGAMEOBJECT_FOREACH_BEHAVIOUR(_itBehaviour) \
	{ \
		(*_itBehaviour)->_methodName(_arg1,_arg2); \
	} \
	GTGAMEOBJECT_FOREACH_CHILD(_itChild) \
	{ \
		(*_itChild)->_methodName(_arg1,_arg2); \
	}

#endif /* _GREENTEA_GAME_OBJECT_H_ */
