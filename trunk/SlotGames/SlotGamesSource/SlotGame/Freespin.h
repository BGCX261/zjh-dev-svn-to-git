#ifndef _SLOTGAME_FREESPIN_H_
#define _SLOTGAME_FREESPIN_H_

#pragma once 
#include "TicketGenerator.h"
#include "../FrameworkSource/UI/UIFrame.h"
#include "UI/UIAnimation.h"
#include "UI/UILabelValueTweener.h"

class FreeSpin
{
public:
	FreeSpin();
	~FreeSpin(void);

// 	enum FreeSpinStatus{
// 		Status_FreeSpin_NONE = -1,
// 		Status_FreeSpin_Start = 0,
// 		Status_FreeSpin_End,
// 	};

	static void LoadAllUIWidgets();	//load all ui widget;
protected: 
	static UIFrame *m_pFreespinFrame;
	static UIAnimation *m_pCongrats_Anim;
	static UILabelValueTweener *m_pCongrats_label;

public:
	void StartFreeSpinProcess(TicketGenerator *pTicketGenerator,  GTArray<int>* pSlotsSymbols);	//start freespin process	
	void DisplayCongrationMsg(int freespinCount);	//display congration msg;
	void CloseCongrationMsg();	//close congration msg;
	//FreeSpinStatus m_status;	//status;
	int m_freespinCount;	//free spin count;

};


#endif /* _SLOTGAME_FREESPIN_H_ */