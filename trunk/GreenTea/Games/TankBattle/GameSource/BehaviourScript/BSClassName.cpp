#include "BSClassName.h"
#include <GTGameObject.h>
#include <GTLog/GTLogManager.h>

// D
BSCLASSNAME_IMP(BSDebugGameObject);
// E
BSCLASSNAME_IMP(BSEndPosition);
// G
BSCLASSNAME_IMP(BSGameObjectGeneral);
// M
BSCLASSNAME_IMP(BSMapSprite);
// P
BSCLASSNAME_IMP(BSPathFinding);
BSCLASSNAME_IMP(BSPlayerController);
BSCLASSNAME_IMP(BSPlayerPlayingUI);
// S
BSCLASSNAME_IMP(BSSprite);
BSCLASSNAME_IMP(BSSpriteMovement);
BSCLASSNAME_IMP(BSStaticSprite);
// T
BSCLASSNAME_IMP(BSTweener2D);
// U
BSCLASSNAME_IMP(BSUnitBehaviour);
BSCLASSNAME_IMP(BSUnitMarine);
BSCLASSNAME_IMP(BSUnitMortar);

BSClassName::BSClassName()
{
}


BSClassName::~BSClassName()
{
}


// Get GTBehaviour from specified game object with the name
GTBehaviour* BSClassName::GetComponent(GTGameObject* pGameObject, const tchar* szName)
{
	if(NULL == pGameObject || NULL == szName)
	{
		return NULL;
	}

	GTBehaviour* pBehaviour = pGameObject->GetComponent(szName);
	if(NULL == pBehaviour)
	{
		GTLogManager::GetInstance()->LogFormatError(CTEXT("Failed to find the component '%s' on game object (%s)"), szName, pGameObject->GetName());
		return NULL;
	}

	return pBehaviour;
}
