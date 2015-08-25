#ifndef _BS_CLASS_NAME_H_
#define _BS_CLASS_NAME_H_

#include <GTBaseDef.h>

class GTGameObject;
class GTBehaviour;

#define BSCLASSNAME_DEF(_className) static const tchar* _className
#define BSCLASSNAME_IMP(_className) const tchar* BSClassName::_className = CTEXT(#_className);

class BSClassName
{
public:
	BSClassName();
	~BSClassName();

public:
	// Get GTBehaviour from specified name
	static GTBehaviour* GetComponent(GTGameObject* pGameObject, const tchar* szName);

public:
	// In alpha order
	// D
	BSCLASSNAME_DEF(BSDebugGameObject);
	// E
	BSCLASSNAME_DEF(BSEndPosition);
	// G
	BSCLASSNAME_DEF(BSGameObjectGeneral);
	// P
	BSCLASSNAME_DEF(BSPathFinding);
	BSCLASSNAME_DEF(BSPlayerController);
	BSCLASSNAME_DEF(BSPlayerPlayingUI);
	// S
	BSCLASSNAME_DEF(BSSprite);
	BSCLASSNAME_DEF(BSSpriteMovement);
	BSCLASSNAME_DEF(BSStaticSprite);
	// T
	BSCLASSNAME_DEF(BSTweener2D);
	// U
	BSCLASSNAME_DEF(BSUnitBehaviour);
	BSCLASSNAME_DEF(BSUnitMarine);
	BSCLASSNAME_DEF(BSUnitMortar);
};

#define BSCLASSNAME_GET_COMPONENT(_className) BSClassName::GetComponent(m_pGameObject,_className)

#endif /* _BS_CLASS_NAME_H_ */
