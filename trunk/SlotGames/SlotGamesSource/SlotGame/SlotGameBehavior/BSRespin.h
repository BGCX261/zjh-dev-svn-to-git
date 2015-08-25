#ifndef _SLOTGAME_BSRESPIN_H
#define _SLOTGAME_BSRESPIN_H

#include <GTBehaviour.h>
#include "..\FrameworkSource\BehaviourScript\BSSprite.h"

class BSRespin : public GTBehaviour
{
public:
	GTBEHAVIOUR_DEF(BSRespin, GTBehaviour);

	enum status{
		Status_None		= 0,
		Status_Locking,	
		Status_FinishLock,
		Status_Lock_Highligh,
		Status_Unlocking,
	};
public:
	BSRespin();
	virtual ~BSRespin();

	// This method is called when GTBehaviour object is created.
	virtual int32 OnCreate(void);
	// This method is called when GTBehaviour object is initialized.
	virtual int32 OnInitialize(GTBehaviourInitParam* param);
	// This method is called before first OnUpdate
	virtual int32 OnStart(void);
	// This method is called when GTBehaviour object is updated.
	virtual int32 OnUpdate(void);
	// This method is called when GTBehaviour object is destroyed.
	virtual int32 OnDestroy(void);

	// Set position for the game object
	void SetGameObjectPosition(const GTPoint2& pos);
	void SetGameObjectPosition(const float x, const float y);

	bool CreateFromPropertyTreeNode(GTTreeNode *pTreeNode);

	void PlayLockAnimation();
	void PlayUnLockAnimation();
	void PlayLockHighlightAnimation();

	status GetStatus() { return m_status; }

protected:
	BSSprite* m_pLockAnimation;
	BSSprite* m_pLockHighlightAnim;

	status m_status;


	//all callback after playAnimation
	void OnFinishPlayLockAnim(void *pParam);
	void OnFinishPlayUnLockAnim(void *pParam);
	void OnFinishPlayLockHighlightAnim(void *pParam);
};

#endif /* _SLOTGAME_BSRESPIN_H */
