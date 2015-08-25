#ifndef BS_Behaviour_
#define BS_Behaviour_

#include <GTBehaviour.h>
#include "Sprite\GSprite.h"

class ReelIcon
{
public:
	ReelIcon(int id, GSprite* spr) : ID(id), sprite(spr) {};
	int ID;
	GSprite * sprite;

	ReelIcon(){};
protected:
};


class BSIconLoader : public GTBehaviour
{
public:
	GTBEHAVIOUR_DEF(BSIconLoader, GTBehaviour);

public:
	BSIconLoader();
	virtual ~BSIconLoader();

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

	bool CreateFromPropertyTreeNode(GTTreeNode *pTreeNode);

	//get instance
	static BSIconLoader* GetInstance();
	//get Icon counts
	static int GetIconsCount();

	//get GSprite instance
	GSprite* GetReelIcon(int id);	

	//get reelIcon count;
	int GetReelIconCount() { return m_reelIcons.Count(); }

	//get wild icon id;
	int GetWildIconID()	{return m_wildIconID;}

	//get wild icon id;
	int GetBonusIconID()	{return m_bonusIconID;}
protected:
	int m_wildIconID;	//wild symbol id
	int m_bonusIconID;	//bonus symbol id
	GTList<ReelIcon*> m_reelIcons;
};

#endif /* BS_Behaviour_ */
