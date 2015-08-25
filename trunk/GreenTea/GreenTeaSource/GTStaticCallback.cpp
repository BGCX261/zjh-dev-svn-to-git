#include "GTStaticCallback.h"

GTStaticCallback::GTStaticCallback() :
	m_pCallbackFunction(NULL),
	m_pUserParam(NULL)
{
}


GTStaticCallback::~GTStaticCallback()
{
}


void GTStaticCallback::Setup(GTStatic_EventCallback pCallbackFunction, void* pUserParam)
{
	m_pCallbackFunction = pCallbackFunction;
	m_pUserParam = pUserParam;
}


void GTStaticCallback::Execute(void)
{
	if(m_pCallbackFunction)
	{
		m_pCallbackFunction(m_pUserParam);
	}
}
