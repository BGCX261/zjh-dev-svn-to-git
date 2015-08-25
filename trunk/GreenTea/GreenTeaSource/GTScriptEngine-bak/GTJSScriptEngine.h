#ifndef _GT_JS_SCRIPT_ENGINE_H_
#define _GT_JS_SCRIPT_ENGINE_H_

#include "GTJSScriptBaseDef.h"
#include "GTScriptEngineObject.h"

class GTJSScriptEngine : public GTScriptEngineObject
{
public:
	GTJSScriptEngine();
	virtual ~GTJSScriptEngine();

	virtual bool Initialize(void);
	virtual bool RunScript(const char* script);
	virtual bool Destroy(void);

	// Register internal classes
	void RegisterInternalClasses(void);

private:
	JSRuntime* m_pJSRuntime;
	JSContext* m_pJSContext;
	JSObject* m_pJSGlobalObject;
};

#endif /* _GT_JS_SCRIPT_ENGINE_H_ */
