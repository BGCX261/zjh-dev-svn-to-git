#include <string>
#include <vector>
#include <list>
#include <map>
#include "MonoScriptCore/MonoBehaviourClass.h"

typedef int int32;
typedef unsigned int uint32;

class GTVector2C
{
public:
	GTVector2C()
	{
		x = y = 0.0f;
	}
	GTVector2C(float fx, float fy)
	{
		x = fx;
		y = fy;
	}

	float x;
	float y;
};

class Vector2C
{
public:
    Vector2C(float x, float y)
    {
        x = x;
        y = y;
    }

    float x;
    float y;
};

struct GTVector2
{
	GTVector2()
	{
		x = y = 0.0f;
	}
	GTVector2(float fx, float fy)
	{
		x = fx;
		y = fy;
	}

	float x;
	float y;
};

class GTBehaviour
{
public:
	GTBehaviour()
	{
	}
};

class GTBehaviourI
{
public:
	GTBehaviourI()
	{
		pGTBehaviour = NULL;
		pMonoBehaviourClass = NULL;
	}

	GTBehaviour* pGTBehaviour;
	MonoBehaviourClass* pMonoBehaviourClass;
};


class GTGameObjectI
{
public:
	GTGameObjectI()
	{
	}

	~GTGameObjectI()
	{
		OnDestroy();
	}

	void OnUpdate();
	void OnDestroy();
	MonoBehaviourClass* AddScript(std::string className);
	MonoBehaviourClass* FindScript(std::string className);
	void Release();

	// Object reference id (this id is same as pMonoObject)
	uint32 objectId;
	MonoObject* pMonoObject;
	// Name
	std::string name;
	// Position
	GTVector2 position;
	// Scripts
	std::list<MonoBehaviourClass*>  listScripts;
};

class GTGameObjectMgr
{
public:
	std::map<uint32, GTGameObjectI*> m_gameObjects;

public:
	GTGameObjectMgr()
	{
	}

	~GTGameObjectMgr()
	{
		//Release();
	}

	void OnUpdate()
	{
		for(std::map<uint32, GTGameObjectI*>::iterator it = m_gameObjects.begin();
			it != m_gameObjects.end();
			it++)
		{
			it->second->OnUpdate();
		}
	}

	void Release()
	{
		for(std::map<uint32, GTGameObjectI*>::iterator it = m_gameObjects.begin();
			it != m_gameObjects.end();
			it++)
		{
			it->second->Release();
		}
		m_gameObjects.clear();
	}

	// Get game object by its name
	GTGameObjectI* GetGameObjectByName(std::string name)
	{
		for(std::map<uint32, GTGameObjectI*>::iterator it = m_gameObjects.begin();
			it != m_gameObjects.end();
			it++)
		{
			if(it->second->name == name)
			{
				return it->second;
			}
		}
		return NULL;
	}

	// Get game object by ref
	GTGameObjectI* GetGameObjectByRef(MonoObject* pgo)
	{
		uint32 target = (uint32)pgo;
		return m_gameObjects[target];		
	}

	// Add a game object by a name
	void AddGameObject(MonoObject* pgo, std::string name)
	{
		GTGameObjectI* go = new GTGameObjectI();
		go->objectId = (uint32)pgo;
		go->pMonoObject = pgo;
		go->name = name;
		go->position = GTVector2(0.0f, 0.0f);
		m_gameObjects.insert(std::pair<uint32, GTGameObjectI*>(go->objectId, go));
	}

	// Destroy a specified game object
	void DestroyGameObjectByName(std::string name)
	{
		GTGameObjectI* go = GetGameObjectByName(name);
		if(go != NULL)
		{
			m_gameObjects.erase((uint32)go);
			delete go;
		}
	}

	void DestroyGameObjectByRef(MonoObject* pgo)
	{
		// Find the object
		GTGameObjectI* go = GetGameObjectByRef(pgo);
		if(go != NULL)
		{
			// Remove this object from the list
			m_gameObjects.erase(go->objectId);
			// Release mono object
			//mono_free(go->pMonoObject);
			// Release the object
			go->Release();
		}
	}
};

// GTGameObject
__declspec(dllexport) void GT_CreateGameObject(MonoObject* pgo, MonoString* msName);
__declspec(dllexport) void GT_DestroyGameObject(MonoObject* pgo);
__declspec(dllexport) MonoString* GT_GetGameObjectName(MonoObject* pgo);
__declspec(dllexport) void GT_SetGameObjectPosition(MonoObject* pgo, float x, float y);
__declspec(dllexport) void GT_GetGameObjectPosition(MonoObject* pgo, GTVector2* pv);
__declspec(dllexport) MonoObject* GT_AddBehaviourGameObject(MonoObject* pgo, MonoString* className);
__declspec(dllexport) MonoObject* GT_FindBehaviourGameObject(MonoObject* pgo, MonoString* className);
__declspec(dllexport) MonoObject* GT_FindGameObjectByName(MonoString* objectName);
__declspec(dllexport) MonoObject* GT_GetGTVector2C(float x, float y);
__declspec(dllexport) MonoObject* GT_GetVector2C(float x, float y);
