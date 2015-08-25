#ifndef _TWEENER_H_
#define _TWEENER_H_

#include "GTGreenTea.h"
#include "TweenInterpolation.h"

class Tweener
{
public:
	Tweener();
	virtual ~Tweener();

	GT_PROPERTY_DEF_VAR_SET_GET_FLOAT(Duration);
	GT_PROPERTY_DEF_VAR_SET_GET_FLOAT(ElapsedTime);

protected:
	TweenFunction m_pTweenFunction;
};

#endif /* _TWEENER_H_ */
