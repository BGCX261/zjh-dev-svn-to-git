#ifndef _MONO_BEHAVIOUR_CLASS_H_
#define _MONO_BEHAVIOUR_CLASS_H_

#include "MonoScriptCore.h"

class MonoBehaviourClass
{
	friend class MonoScriptEngine;

public:	
	static const int METHOD_OnPreStart = 0;
	static const int METHOD_OnStart = 1;
	static const int METHOD_OnUpdate = 2;
	static const int METHOD_OnDestroy = 3;
	static const int METHOD_Count = 4;

	static const char* METHOD_OnPreStart_Name;
	static const char* METHOD_OnStart_Name;
	static const char* METHOD_OnUpdate_Name;
	static const char* METHOD_OnDestroy_Name;

public:
	MonoBehaviourClass();
	~MonoBehaviourClass();

	bool InvokeMonoMethod(MonoMethodObject* pMethodObject, std::string& strException);
	bool InvokeOnPreStart(std::string& strException) { return InvokeMonoMethod(GetMonoMethodObject(METHOD_OnPreStart), strException); }
	bool InvokeOnStart(std::string& strException) { return InvokeMonoMethod(GetMonoMethodObject(METHOD_OnStart), strException); }
	bool InvokeOnUpdate(std::string& strException) { return InvokeMonoMethod(GetMonoMethodObject(METHOD_OnUpdate), strException); }
	bool InvokeOnDestroy(std::string& strException) { return InvokeMonoMethod(GetMonoMethodObject(METHOD_OnDestroy), strException); }

	void Release(void);

protected:
	MonoMethodObject* GetMonoMethodObject(const int nIndex)
	{
		return &m_MonoMethodObject[nIndex];
	}

public:
	std::string m_ClassName;
	MonoClassObject m_ClassObject;
	MonoMethodObject m_MonoMethodObject[METHOD_Count];
};

#endif /* _MONO_BEHAVIOUR_CLASS_H_ */
