#ifndef _GT_GREENTEA_H_
#define _GT_GREENTEA_H_

#include "GTBaseDef.h"
#include "GTObject.h"
#include "GTArray.h"
#include "GTList.h"
#include "GTDictionary.h"
#include "GTAlgorithm.h"
#include "GTString.h"
#include "GTStringUtil.h"
#include "GTBehaviour.h"
#include "GTGameObject.h"
#include "GTPathFinding.h"
#include "GTPoint2.h"
#include "GTSize.h"
#include "GTRect.h"
#include "GTScript.h"
#include "GTSingleton.h"
#include "GTTreeNode.h"
#include "GTVector2.h"
#include "GTVector3.h"
#include "GTBehaviourClassManager.h"
#include "GTEvent.h"
#include "GTLog/GTLogManager.h"

// Math constants
#define Mathf_Deg2Rad 0.0174533f
#define Mathf_Epsilon 1.4013e-045f
#define Mathf_Infinity (1.0f / 0.0f)
#define Mathf_PI 3.14159f
#define Mathf_Rad2Deg 57.2958f
// Math functions
#define Mathf_Clamp(_value,_min,_max) (((_value)<(_min))?(_min):(((_value)>(_max))?(_max):(_value)))
#define Mathf_Ceil(_value) ceilf((_value))
#define Mathf_Floor(_value) floorf((_value))
#define Mathf_Abs(_value) fabsf((_value))
#define Mathf_Sin(_value) sinf((_value))
#define Mathf_Cos(_value) cosf((_value))
#define Mathf_Tan(_value) tanf((_value))
#define Mathf_ASin(_value) asinf((_value))
#define Mathf_ACos(_value) acosf((_value))
#define Mathf_ATan(_value) atanf((_value))
#define Mathf_Pow(_xvalue,_yvalue) powf((_xvalue),(_yvalue))
#define Mathf_Sqrt(_value) sqrtf((_value))

// Define properties
#define GT_PROPERTY_DEF_VAR(_type,_prefix,_propName) _type m_##_prefix##_propName;
#define GT_PROPERTY_DEF_SET(_type,_prefix,_propName) void SetProperty##_propName(const _type _value) {m_##_prefix##_propName=_value;}
#define GT_PROPERTY_DEF_GET(_type,_prefix,_propName) _type GetProperty##_propName(void) const {return m_##_prefix##_propName;}
#define GT_PROPERTY_REF_VAR(_type,_prefix,_propName) m_##_prefix##_propName
// Define Var & Set
#define GT_PROPERTY_DEF_VAR_SET(_type,_prefix,_propName) \
	GT_PROPERTY_DEF_VAR(_type,_prefix,_propName) \
	GT_PROPERTY_DEF_SET(_type,_prefix,_propName)
// Define Var & Get
#define GT_PROPERTY_DEF_VAR_GET(_type,_prefix,_propName) \
	GT_PROPERTY_DEF_VAR(_type,_prefix,_propName) \
	GT_PROPERTY_DEF_GET(_type,_prefix,_propName)
// Define Var & Set & Get
#define GT_PROPERTY_DEF_VAR_SET_GET(_type,_prefix,_propName) \
	GT_PROPERTY_DEF_VAR_SET(_type,_prefix,_propName) \
	GT_PROPERTY_DEF_GET(_type,_prefix,_propName)
// INT16
#define GT_PROPERTY_DEF_VAR_INT16(_propName) GT_PROPERTY_DEF_VAR(int16,n,_propName)
#define GT_PROPERTY_DEF_SET_INT16(_propName) GT_PROPERTY_DEF_SET(int16,n,_propName)
#define GT_PROPERTY_DEF_GET_INT16(_propName) GT_PROPERTY_DEF_GET(int16,n,_propName)
#define GT_PROPERTY_DEF_VAR_SET_INT16(_propName) GT_PROPERTY_DEF_VAR_SET(int16,n,_propName)
#define GT_PROPERTY_DEF_VAR_GET_INT16(_propName) GT_PROPERTY_DEF_VAR_GET(int16,n,_propName)
#define GT_PROPERTY_DEF_VAR_SET_GET_INT16(_propName) GT_PROPERTY_DEF_VAR_SET_GET(int16,n,_propName)
#define GT_PROPERTY_REF_VAR_INT16(_propName) GT_PROPERTY_REF_VAR(int16,n,_propName)
// UINT16
#define GT_PROPERTY_DEF_VAR_UINT16(_propName) GT_PROPERTY_DEF_VAR(uint16,n,_propName)
#define GT_PROPERTY_DEF_SET_UINT16(_propName) GT_PROPERTY_DEF_SET(uint16,n,_propName)
#define GT_PROPERTY_DEF_GET_UINT16(_propName) GT_PROPERTY_DEF_GET(uint16,n,_propName)
#define GT_PROPERTY_DEF_VAR_SET_UINT16(_propName) GT_PROPERTY_DEF_VAR_SET(uint16,n,_propName)
#define GT_PROPERTY_DEF_VAR_GET_UINT16(_propName) GT_PROPERTY_DEF_VAR_GET(uint16,n,_propName)
#define GT_PROPERTY_DEF_VAR_SET_GET_UINT16(_propName) GT_PROPERTY_DEF_VAR_SET_GET(uint16,n,_propName)
#define GT_PROPERTY_REF_VAR_UINT16(_propName) GT_PROPERTY_REF_VAR(uint16,n,_propName)
// INT32
#define GT_PROPERTY_DEF_VAR_INT32(_propName) GT_PROPERTY_DEF_VAR(int32,n,_propName)
#define GT_PROPERTY_DEF_SET_INT32(_propName) GT_PROPERTY_DEF_SET(int32,n,_propName)
#define GT_PROPERTY_DEF_GET_INT32(_propName) GT_PROPERTY_DEF_GET(int32,n,_propName)
#define GT_PROPERTY_DEF_VAR_SET_INT32(_propName) GT_PROPERTY_DEF_VAR_SET(int32,n,_propName)
#define GT_PROPERTY_DEF_VAR_GET_INT32(_propName) GT_PROPERTY_DEF_VAR_GET(int32,n,_propName)
#define GT_PROPERTY_DEF_VAR_SET_GET_INT32(_propName) GT_PROPERTY_DEF_VAR_SET_GET(int32,n,_propName)
#define GT_PROPERTY_REF_VAR_INT32(_propName) GT_PROPERTY_REF_VAR(int32,n,_propName)
// UINT32
#define GT_PROPERTY_DEF_VAR_UINT32(_propName) GT_PROPERTY_DEF_VAR(uint32,n,_propName)
#define GT_PROPERTY_DEF_SET_UINT32(_propName) GT_PROPERTY_DEF_SET(uint32,n,_propName)
#define GT_PROPERTY_DEF_GET_UINT32(_propName) GT_PROPERTY_DEF_GET(uint32,n,_propName)
#define GT_PROPERTY_DEF_VAR_SET_UINT32(_propName) GT_PROPERTY_DEF_VAR_SET(uint32,n,_propName)
#define GT_PROPERTY_DEF_VAR_GET_UINT32(_propName) GT_PROPERTY_DEF_VAR_GET(uint32,n,_propName)
#define GT_PROPERTY_DEF_VAR_SET_GET_UINT32(_propName) GT_PROPERTY_DEF_VAR_SET_GET(uint32,n,_propName)
#define GT_PROPERTY_REF_VAR_UINT32(_propName) GT_PROPERTY_REF_VAR(uint32,n,_propName)
// float
#define GT_PROPERTY_DEF_VAR_FLOAT(_propName) GT_PROPERTY_DEF_VAR(float,f,_propName)
#define GT_PROPERTY_DEF_SET_FLOAT(_propName) GT_PROPERTY_DEF_SET(float,f,_propName)
#define GT_PROPERTY_DEF_GET_FLOAT(_propName) GT_PROPERTY_DEF_GET(float,f,_propName)
#define GT_PROPERTY_DEF_VAR_SET_FLOAT(_propName) GT_PROPERTY_DEF_VAR_SET(float,f,_propName)
#define GT_PROPERTY_DEF_VAR_GET_FLOAT(_propName) GT_PROPERTY_DEF_VAR_GET(float,f,_propName)
#define GT_PROPERTY_DEF_VAR_SET_GET_FLOAT(_propName) GT_PROPERTY_DEF_VAR_SET_GET(float,f,_propName)
#define GT_PROPERTY_REF_VAR_FLOAT(_propName) GT_PROPERTY_REF_VAR(float,f,_propName)
// bool
#define GT_PROPERTY_DEF_VAR_BOOL(_propName) GT_PROPERTY_DEF_VAR(bool,b,_propName)
#define GT_PROPERTY_DEF_SET_BOOL(_propName) GT_PROPERTY_DEF_SET(bool,b,_propName)
#define GT_PROPERTY_DEF_GET_BOOL(_propName) GT_PROPERTY_DEF_GET(bool,b,_propName)
#define GT_PROPERTY_DEF_VAR_SET_BOOL(_propName) GT_PROPERTY_DEF_VAR_SET(bool,b,_propName)
#define GT_PROPERTY_DEF_VAR_GET_BOOL(_propName) GT_PROPERTY_DEF_VAR_GET(bool,b,_propName)
#define GT_PROPERTY_DEF_VAR_SET_GET_BOOL(_propName) GT_PROPERTY_DEF_VAR_SET_GET(bool,b,_propName)
#define GT_PROPERTY_REF_VAR_BOOL(_propName) GT_PROPERTY_REF_VAR(bool,b,_propName)

#endif /* _GT_GREENTEA_H_ */
