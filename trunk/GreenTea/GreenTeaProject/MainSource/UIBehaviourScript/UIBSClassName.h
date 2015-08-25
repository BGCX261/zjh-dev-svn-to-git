#ifndef _UIBS_CLASS_NAME_H_
#define _UIBS_CLASS_NAME_H_

#include <GTBaseDef.h>

#define UIBSCLASSNAME_DEF(_className) static const tchar* _className
#define UIBSCLASSNAME_IMP(_className) const tchar* UIBSClassName::_className = CTEXT(#_className);

class UIBSClassName
{
public:
	UIBSClassName();
	virtual ~UIBSClassName();

public:
	// In alpha order
	// L
	UIBSCLASSNAME_DEF(UIBSLabelSmoothValueChange);
};

#endif /* _UIBS_CLASS_NAME_H_ */
