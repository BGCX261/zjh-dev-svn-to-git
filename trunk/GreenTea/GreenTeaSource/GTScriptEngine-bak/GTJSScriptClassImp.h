#ifndef _GREENTEA_JS_SCRIPT_CLASS_IMP_H_
#define _GREENTEA_JS_SCRIPT_CLASS_IMP_H_

#include "GTJSScriptBaseDef.h"
#include "../GTGreenTea.h"
#include "../GTLog/GTLogManager.h"

#ifdef GT_WINDOWS
typedef unsigned int uint32_t;
typedef int int32_t;

typedef struct {
	uint32_t flags;
	void* data;
} pointerShell_t;

typedef enum {
	kPointerTemporary = 1
} pointerShellFlags;

#define JSGET_PTRSHELL(type, cobj, jsobj) do { \
	pointerShell_t *pt = (pointerShell_t *)JS_GetPrivate(jsobj); \
	if (pt) { \
		cobj = (type *)pt->data; \
	} else { \
		cobj = NULL; \
	} \
} while (0)

#define JS_GetPrivate(obj) JS_GetPrivate(cx, obj)
#define JS_SetPrivate(obj, data) JS_SetPrivate(cx, obj, data)
#endif /* GT_WINDOWS */

//--------------------------------------------------------------
// GTVector2
//--------------------------------------------------------------
class JSC_GTVector2 : public GTVector2
{
private:
	JSObject *m_jsobj;
public:
	static JSClass *jsClass;
	static JSObject *jsObject;

	JSC_GTVector2(JSObject *obj) : GTVector2(), m_jsobj(obj) {};
	enum
	{
		kX = 1,
		kY
	};

	static JSBool jsConstructor(JSContext *cx, uint32_t argc, jsval *vp);
	static void jsFinalize(JSContext *cx, JSObject *obj);
	static JSBool jsPropertyGet(JSContext *cx, JSObject *obj, jsid _id, jsval *val);
	static JSBool jsPropertySet(JSContext *cx, JSObject *obj, jsid _id, JSBool strict, jsval *val);
	static void jsCreateClass(JSContext *cx, JSObject *globalObj, const char *name);
	// Methods
	static JSBool jsIsEqual(JSContext *cx, uint32_t argc, jsval *vp);
};


//--------------------------------------------------------------
// GTLogManager
//--------------------------------------------------------------
class JSC_GTLogManager : public GTLogManager
{
private:
	JSObject *m_jsobj;
public:
	static JSClass *jsClass;
	static JSObject *jsObject;

	JSC_GTLogManager(JSObject *obj) : GTLogManager(), m_jsobj(obj) {};
	enum
	{
		kX = 1,
		kY
	};

	static JSBool jsConstructor(JSContext *cx, uint32_t argc, jsval *vp);
	static void jsFinalize(JSContext *cx, JSObject *obj);
	static JSBool jsPropertyGet(JSContext *cx, JSObject *obj, jsid _id, jsval *val);
	static JSBool jsPropertySet(JSContext *cx, JSObject *obj, jsid _id, JSBool strict, jsval *val);
	static void jsCreateClass(JSContext *cx, JSObject *globalObj, const char *name);
	// Class methods
	static JSBool jsLogTrace(JSContext *cx, uint32_t argc, jsval *vp);
	static JSBool jsLogWarning(JSContext *cx, uint32_t argc, jsval *vp);
	static JSBool jsLogError(JSContext *cx, uint32_t argc, jsval *vp);
	static JSBool jsLogComment(JSContext *cx, uint32_t argc, jsval *vp);
};

#endif /* _GREENTEA_JS_SCRIPT_CLASS_IMP_H_ */
