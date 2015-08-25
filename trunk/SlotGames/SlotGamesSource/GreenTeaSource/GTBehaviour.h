#ifndef _GREENTEA_BEHAVIOUR_H_
#define _GREENTEA_BEHAVIOUR_H_

#include "GTBaseDef.h"
#include "GTObject.h"
#include "GTBasicBehaviour.h"
#include "GTPoint2.h"

// Add the variables and methods into the derived class to store the class name
#define GTBEHAVIOUR_DEF(className,superClassName) \
	static const tchar* m_szClassName; \
	static const tchar* m_szSuperClassName; \
	virtual const tchar* GetClassName(void) const; \
	virtual const tchar* GetSuperClassName(void) const; \
	virtual void Release(void); \
	static GTBehaviour* CreateClassInstance(void); \
	static const tchar* GetClassNameStatic(void); \
	static const tchar* GetSuperClassNameStatic(void);

// Implement the variable and methods to store the class name
#define GTBEHAVIOUR_IMP(className,superClassName) \
	static GTBehaviourClassContainer _g_GTBehaviourClassContainer_##className = GTBehaviourClassContainer(className::m_szClassName,className::CreateClassInstance); \
	const tchar* className::m_szClassName=CTEXT(#className); \
	const tchar* className::m_szSuperClassName=CTEXT(#superClassName); \
	const tchar* className::GetClassName(void) const {return className::m_szClassName;} \
	const tchar* className::GetSuperClassName(void) const {return className::m_szSuperClassName;} \
	void className::Release(void) {this->OnDestroy(); delete (className*)this;} \
	GTBehaviour* className::CreateClassInstance(void) {className* p=new className(); if(p) {p->OnCreate();} return p;} \
	const tchar* className::GetClassNameStatic(void) {return className::m_szClassName;} \
	const tchar* className::GetSuperClassNameStatic(void) {return className::m_szSuperClassName;}

// This struct is only for OnInitialize
struct GTBehaviourInitParam
{
	void* pParam1;
	void* pParam2;
};

class GTBehaviour : public GTObject, public GTBasicBehaviour
{
protected:
	// Parent game object that the script is attached to.
	GTGameObject* m_pGameObject;
	// If it's first update
	bool m_bFirstUpdate;
	
public:
	GTBehaviour();
	GTBehaviour(GTGameObject* pGO);
	virtual ~GTBehaviour();

public:
	// Set the game object that this behaviour is attached to
	void SetGameObject(GTGameObject* pGameObject)
	{
		DBG_ASSERT(pGameObject);
		m_pGameObject = pGameObject;
	}
	// Get the game object that this behaviour is attached to
	GTGameObject* GetGameObject()
	{
		DBG_ASSERT(m_pGameObject);
		return m_pGameObject;
	}

	// Set position for the game object
	void SetGameObjectPosition(const GTPoint2& pos);
	void SetGameObjectPosition(const float x, const float y);
	// Get position for the game object
	GTPoint2 GetGameObjectPosition(void) const;

	// Don't override this method because it is implemented
	// by GTBEHAVIOUR_DEF/GTBEHAVIOUR_IMP already.
	virtual const tchar* GetClassName(void) const = 0;

	// Don't override this method because it is implemented
	// by GTBEHAVIOUR_DEF/GTBEHAVIOUR_IMP already.
	virtual const tchar* GetSuperClassName(void) const = 0;

	// This method is called to destroy itself to release the memory.
	// Don't override this method because it is implemented
	// by GTBEHAVIOUR_DEF/GTBEHAVIOUR_IMP already.
	virtual void Release(void) = 0;

	// This method is called when GTBehaviour object is created.
	virtual int32 OnCreate(void);

	// This method is called when GTBehaviour object is initialized.
	// param - the parameter passed to this behaviour
	// param->pParam1 - the root GTTreeNode
	// param->pParam2 - the tree node under this behaviour
	virtual int32 OnInitialize(GTBehaviourInitParam* param);

	// OnStart is called just before any of the OnUpdate methods is called the first time.
	// OnStart is only called once in the lifetime of the behaviour.
	// The difference between OnCreate and OnStart is that OnStart is only called
	// if the script instance is enabled. This allows you to delay any initialization code,
	// until it is really needed. OnCreated is always called before any OnStart functions.
	// This allows you to order initialization of scripts.
	// The OnStart function is called after all OnCreated functions on all script instances have been called.
	virtual int32 OnStart(void);
	// This method is called when the object is updated.
	virtual int32 OnUpdate(void);
	// This method is called when the object is destroyed.
	virtual int32 OnDestroy(void);
	// If the object needs to be rebuilt
	virtual void OnDirty(void);
	// OnBecameVisible is called when the the object is set visible.
	virtual void OnVisible(void);
	// OnBecameVisible is called when the the object is set invisible.
	virtual void OnInvisible(void);
	// This function is called when the behaviour becomes disabled or inactive.
	virtual void OnDisable(void);
	// This function is called when the object becomes enabled and active.
	virtual void OnEnable(void);
	// OnChangeZOrder is called when the the object is set with new z-order.
	virtual void OnChangeZOrder(const int32 nNewZOrder);
	// This function is called after a new level was loaded.
	virtual void OnLevelWasLoaded(const int32 nParam);
	// OnCollisionEnter is called when this collider/rigidbody has begun touching another rigidbody/collider.
	virtual void OnCollisionEnter(GTGameObject* pGameObject);
	// OnCollisionExit is called when this collider/rigidbody has stopped touching another rigidbody/collider.
	virtual void OnCollisionExit(GTGameObject* pGameObject);
	// OnCollisionStay is called once per frame for every collider/rigidbody that is touching rigidbody/collider.
	virtual void OnCollisionStay(GTGameObject* pGameObject);
	// Copy
	virtual bool Copy(GTObject* pObjectFrom);
};


// This class contains basic information about a class
// that derives from GTBehaviour
class GTBehaviourClassContainer
{
public:
	// The type of pointer of the function of creating a new derived-class object
	typedef GTBehaviour* (*CreateBehaviourClassDefine)(void);

public:
	GTBehaviourClassContainer(const tchar* szClassName, CreateBehaviourClassDefine pfn);
	virtual ~GTBehaviourClassContainer();

	// The class name that derives from GTBehaviour
	const tchar* m_szClassName;
	// The pointer of the function of creating a new derived-class object
	CreateBehaviourClassDefine m_pfnCreateBehaviourClass;
};

#endif /* _GREENTEA_BEHAVIOUR_H_ */
