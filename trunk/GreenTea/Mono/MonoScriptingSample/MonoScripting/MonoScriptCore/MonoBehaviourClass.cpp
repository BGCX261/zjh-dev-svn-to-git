#include "MonoBehaviourClass.h"

const char* MonoBehaviourClass::METHOD_OnPreStart_Name = "OnPreStart";
const char* MonoBehaviourClass::METHOD_OnStart_Name = "OnStart";
const char* MonoBehaviourClass::METHOD_OnUpdate_Name = "OnUpdate";
const char* MonoBehaviourClass::METHOD_OnDestroy_Name = "OnDestroy";

MonoBehaviourClass::MonoBehaviourClass()
{
}


MonoBehaviourClass::~MonoBehaviourClass()
{
}


void MonoBehaviourClass::Release(void)
{
	delete this;
}


bool MonoBehaviourClass::InvokeMonoMethod(MonoMethodObject* pMethodObject, std::string& strException)
{
	strException.clear();

	if(pMethodObject == NULL)
		return false;
	
	MonoObject* exception = nullptr;
	if(pMethodObject->pMethod && m_ClassObject.pClassInstance)
	{
		MonoObject* objReturn = mono_runtime_invoke(pMethodObject->pMethod, m_ClassObject.pClassInstance, NULL, &exception);
		if(exception != nullptr)
		{
			// Show me the exception!
			strException = std::string((mono_string_to_utf8(mono_object_to_string(exception, NULL))));
			return false;
		}
	}

	return true;
}

/*
			if(pMethod)
						{
							// Invoke the method
							//mono_runtime_invoke(pMethod, pMonoObject, NULL, &exception);
							mono_runtime_invoke(pMethod, pMonoObject, NULL, NULL);
						}
						//mono_runtime_object_init (my_class_instance);
						//void *args [1];
						//args [0] = mono_string_new (domain, "Mono rocks");
						//mono_runtime_invoke(ctor_method, my_class_instance, args, NULL);
					}
				}
				*/
