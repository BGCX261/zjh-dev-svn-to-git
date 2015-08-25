#ifndef _GREENTEA_SCRIPT_ENGINE_OBJECT_H_
#define _GREENTEA_SCRIPT_ENGINE_OBJECT_H_

#include "../GTBaseDef.h"

class GTScriptEngineObject
{
public:
	GTScriptEngineObject();
	virtual ~GTScriptEngineObject();

	virtual bool Initialize(void) = 0;
	virtual bool RunScript(const char* script) = 0;
	virtual bool Destroy(void) = 0;
};

#endif /* _GREENTEA_SCRIPT_ENGINE_OBJECT_H_ */
