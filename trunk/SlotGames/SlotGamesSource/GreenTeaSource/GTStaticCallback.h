#ifndef _GT_STATIC_CALLBACK_H_
#define _GT_STATIC_CALLBACK_H_

#include "GTGreenTea.h"

class GTStaticCallback
{
public:
	GTStaticCallback();
	virtual ~GTStaticCallback();

	void Setup(GTStatic_EventCallback pCallbackFunction, void* pUserParam);
	void Execute(void);

protected:
	// Callback function pointer
	GTStatic_EventCallback m_pCallbackFunction;
	// User data passed
	void* m_pUserParam;
};

#endif /* _GT_STATIC_CALLBACK_H_ */
