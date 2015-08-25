#ifndef _GREENTEA_SCRIPT_ENGINE_H_
#define _GREENTEA_SCRIPT_ENGINE_H_

#include "../GTBaseDef.h"
#include "../GTSingleton.h"
#include "GTScriptEngineObject.h"

class GTScriptEngine : public GTSingleton<GTScriptEngine>
{
public:
	GTScriptEngine();
	virtual ~GTScriptEngine();

	// Initialize script engine
	void Initialize(void);
	// Run a script
	bool RunScript(const char* szScript);
	// Destroy script engine
	void Destroy(void);

private:
	GTScriptEngineObject* m_pGTScriptEngineObject;
};

#endif /* _GREENTEA_SCRIPT_ENGINE_H_ */
