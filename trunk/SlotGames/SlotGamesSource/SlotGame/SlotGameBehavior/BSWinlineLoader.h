#ifndef _BS_Winline_Loader
#define _BS_Winline_Loader

#include <GTBehaviour.h>
#include <GTTreeNode.h>
#include <GTArray.h>
#include <GTDictionary.h>
#include "..\FrameworkSource\BehaviourScript\BSSprite.h"

//load winline and paytable;
class BSWinlineLoader : public GTBehaviour
{
public:
	GTBEHAVIOUR_DEF(BSWinlineLoader, GTBehaviour);

public:
	BSWinlineLoader();
	virtual ~BSWinlineLoader();

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

	//GetWinlineLoad;
	static BSWinlineLoader* GetInstance();

	//get winlines 
	GTDictionary<int, GTArray<int> >* GetWinlines() { return &m_winlineDict; }	

	//get pay table;
	GTDictionary<int, int>* GetPaytable()	{ return &m_paytableDict; }

	//show winline sprite;
	void ShowWinlineSprite(int winlineID, bool visibility);
private:
	GTDictionary<int, GTArray<int> > m_winlineDict;		//winline dictionary;

	GTDictionary<int, int> m_paytableDict;				//paytable dictionary;

	BSSprite* m_winlineSprite;
};

#endif /* _BS_Winline_Loader */
