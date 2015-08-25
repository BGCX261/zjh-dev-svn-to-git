#ifndef _BASE_DEF_H_
#define _BASE_DEF_H_

#include "../GTBaseDef.h"

#ifdef GT_WINDOWS
#ifdef GT_DEBUG
// Visual Leak Detector
#ifdef _USE_VLD_
#include <vld.h>
#endif /* _USE_VLD_ */
#endif /* GT_DEBUG */
#endif /* GT_WINDOWS */

#endif /* _BASE_DEF_H_ */
