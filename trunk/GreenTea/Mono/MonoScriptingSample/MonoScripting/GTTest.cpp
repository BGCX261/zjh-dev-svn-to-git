#include "GTTest.h"
#include <list>
#include "MonoScriptCore/MonoScriptEngine.h"

extern MonoScriptEngine monoScriptEngine;
GTGameObjectMgr goManager;

// GTGameObjectI
void GTGameObjectI::OnUpdate()
{
	// Update all scripts attached
	std::string runException;
	for(std::list<MonoBehaviourClass*>::iterator it = listScripts.begin();
		it != listScripts.end();
		it++)
	{
		(*it)->InvokeOnUpdate(runException);
	}		
}

void GTGameObjectI::OnDestroy()
{
	std::string runException;
	for(std::list<MonoBehaviourClass*>::iterator it = listScripts.begin();
		it != listScripts.end();
		it++)
	{
		(*it)->InvokeOnDestroy(runException);
		(*it)->Release();
	}
	listScripts.clear();
}

MonoBehaviourClass* GTGameObjectI::AddScript(std::string className)
{
	MonoBehaviourClass* pBehaviourClass = monoScriptEngine.CreateBehaviourClassInstance("", className.c_str());
	{
		if(pBehaviourClass == NULL)
			return NULL;

		std::string runException;
		pBehaviourClass->m_ClassName = className;
		pBehaviourClass->InvokeOnPreStart(runException);
		pBehaviourClass->InvokeOnStart(runException);

		// Add to the list
		listScripts.push_back(pBehaviourClass);

		return pBehaviourClass;
	}
}

MonoBehaviourClass* GTGameObjectI::FindScript(std::string className)
{
	for(std::list<MonoBehaviourClass*>::iterator it = listScripts.begin();
		it != listScripts.end();
		it++)
	{
		if((*it)->m_ClassName == className)
		{
			// Found
			return (*it);
		}
	}

	return NULL;
}

void GTGameObjectI::Release()
{
	OnDestroy();
	delete this;
}


// Create a game object by specified name
__declspec(dllexport) void GT_CreateGameObject(MonoObject* pgo, MonoString* msName)
{
	char* name = mono_string_to_utf8(msName);
	goManager.AddGameObject(pgo, name);
	mono_free(name);
}


// Destroy a game object
__declspec(dllexport) void GT_DestroyGameObject(MonoObject* pgo)
{
	goManager.DestroyGameObjectByRef(pgo);
}


// Get a game object's name
__declspec(dllexport) MonoString* GT_GetGameObjectName(MonoObject* pgo)
{
	GTGameObjectI* go = goManager.GetGameObjectByRef(pgo);
	if(go != NULL)
	{
		return mono_string_new(mono_domain_get(), go->name.c_str());
	}
	return mono_string_new(mono_domain_get(), "");
}


// Set a game object's position
__declspec(dllexport) void GT_SetGameObjectPosition(MonoObject* pgo, float x, float y)
{
	GTGameObjectI* go = goManager.GetGameObjectByRef(pgo);
	if(go != NULL)
	{
		go->position.x = x;
		go->position.y = y;
	}
}


// Get a game object position
__declspec(dllexport) void GT_GetGameObjectPosition(MonoObject* pgo, GTVector2* pv)
{
	GTGameObjectI* go = goManager.GetGameObjectByRef(pgo);
	if(go != NULL)
	{
		pv->x = go->position.x;
		pv->y = go->position.y;
	}
}


// Add a behaviour to a game object specified by its name
__declspec(dllexport) MonoObject* GT_AddBehaviourGameObject(MonoObject* pgo, MonoString* className)
{
	char* name = mono_string_to_utf8(className);
	GTGameObjectI* go = goManager.GetGameObjectByRef(pgo);
	MonoBehaviourClass* script = NULL;
	if(go != NULL)
	{
		script = go->AddScript(std::string(name));
	}
	mono_free(name);

	return (script != NULL) ? script->m_ClassObject.pClassInstance : NULL;
}


// Find a behaviour with specified by its name
__declspec(dllexport) MonoObject* GT_FindBehaviourGameObject(MonoObject* pgo, MonoString* className)
{
	char* name = mono_string_to_utf8(className);
	GTGameObjectI* go = goManager.GetGameObjectByRef(pgo);
	MonoBehaviourClass* script = NULL;
	if(go != NULL)
	{
		script = go->FindScript(std::string(name));
	}
	mono_free(name);

	return (script != NULL) ? script->m_ClassObject.pClassInstance : NULL;
}


// Find a game object by its name
__declspec(dllexport) MonoObject* GT_FindGameObjectByName(MonoString* objectName)
{
	char* name = mono_string_to_utf8(objectName);
	GTGameObjectI* go = goManager.GetGameObjectByName(name);
	mono_free(name);

	if(go != NULL)
	{
		return go->pMonoObject;
	}

	return NULL;
}


__declspec(dllexport) MonoObject* GT_GetVector2C(float x, float y)
{
	/*
	GTVector2C* pc = new GTVector2C();
	pc->x = x;
	pc->y = y;

	return pc;
	*/

	float val;

	// Get MonoClass object by its name
	//MonoClass* klass = monoScriptEngine.GetMonoClassByName("GTEngineManaged", "Vector2C");
	MonoClass* klass = monoScriptEngine.GetMonoClassByName("", "Vector2C");
	// Create MonoObject from specified MonoClass
	MonoObject* mobject = mono_object_new(mono_domain_get(), klass);
	MonoClassField* field_x = mono_class_get_field_from_name (klass, "x");
	MonoClassField* field_y = mono_class_get_field_from_name (klass, "y");
	// Change the field
	//mono_field_get_value(mobject, field, &val);
	//val = 567.0f;
	mono_field_set_value(mobject, field_x, &x);
	mono_field_set_value(mobject, field_y, &y);

	return mobject;
}


__declspec(dllexport) MonoObject* GT_GetGTVector2C(float x, float y)
{
	// Get a class object
	MonoClass* klass = monoScriptEngine.GetMonoClassByNameFromEngine("GTEngineManaged", "GTVector2C");
	// Create MonoObject from specified MonoClass
	MonoObject* mobject = mono_object_new(mono_domain_get(), klass);
	// Get field x
	MonoClassField* field_x = mono_class_get_field_from_name (klass, "x");
	// Get field y
	MonoClassField* field_y = mono_class_get_field_from_name (klass, "y");
	// Change the field
	mono_field_set_value(mobject, field_x, &x);
	mono_field_set_value(mobject, field_y, &y);

	return mobject;
}


/*
__declspec(dllexport) MonoObject* GT_GetGameObjectVector(float v)
{
	float val;

	// Get MonoClass object by its name
	MonoClass* klass = monoScriptEngine.GetMonoClassByName("GTEngineManaged", "GTVector2");
	// Create MonoObject from specified MonoClass
	MonoObject* mobject = mono_object_new(mono_domain_get(), klass);
	MonoClassField* field = mono_class_get_field_from_name (klass, "x");
	// Change the field
	mono_field_get_value(mobject, field, &val);
	val = 567.0f;
	mono_field_set_value(mobject, field, &val);

	return mobject;
}
*/


/*
__declspec(dllexport) GTVector2 GT_GetPosition(MonoString* ms)
{
	GTGameObject* go = GT_GetGameObjectByName(ms);
	return (go != NULL) ? go->position : GTVector2(0.0f, 0.0f);
}


__declspec(dllexport) void GT_GetPositionRef(MonoString* ms, GTVector2* mo)
{
	GTGameObject* go = GT_GetGameObjectByName(ms);
	if(go != NULL)
	{
		mo->x = go->position.x;
		mo->y = go->position.y;
	}
}


__declspec(dllexport) void GT_GetPositionOut(MonoString* ms, GTVector2* mo)
{
	GTGameObject* go = GT_GetGameObjectByName(ms);
	if(go != NULL)
	{
		mo->x = go->position.x;
		mo->y = go->position.y;
	}
}


__declspec(dllexport) void GT_SetPosition(MonoString* ms, float x, float y)
{
	GTGameObject* go = GT_GetGameObjectByName(ms);
	if(go != NULL)
	{
		go->position.x = x;
		go->position.y = y;
	}
}


__declspec(dllexport) void GT_SetPosition2(MonoString* ms, MonoObject* mo)
{
	// Get object size
	const unsigned int size = mono_object_get_size(mo);
	// Unbox the object
	GTVector2 pos = *(GTVector2*)mono_object_unbox(mo);

	GTGameObject* go = GT_GetGameObjectByName(ms);
	if(go != NULL)
	{
		go->position.x = pos.x;
		go->position.y = pos.y;
	}
}
*/
