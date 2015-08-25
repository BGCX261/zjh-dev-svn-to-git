#include "FreeSpin.h"
#include <UI/UIManager.h>
#include "UI/UIDef.h"
#include "../GreenTeaSource/GTLog/GTLogManager.h"

#define FREESPIN_NUMBER_FOR_EVERY_BONUS_REEL		1

FreeSpin::FreeSpin()
{
	//m_status = Status_FreeSpin_NONE;

	m_freespinCount = 0;
}


FreeSpin::~FreeSpin(void)
{ 
}

//initialization all widgets;
UIFrame * FreeSpin::m_pFreespinFrame = NULL;
UIAnimation * FreeSpin::m_pCongrats_Anim = NULL;
UILabelValueTweener * FreeSpin::m_pCongrats_label = NULL;

//load all ui widget;
void FreeSpin::LoadAllUIWidgets()
{
	UIWidget* pRootWidget = UIManager::Inst()->GetRootWidget();	
	FreeSpin::m_pFreespinFrame = pRootWidget->FindChildById<UIFrame>(UI_IdDef::FREESPIN_FRAME);
	if (FreeSpin::m_pFreespinFrame == NULL)
	{
		GTLogManager::SLogError("Can't load freespin frame from ui file");
		return;
	}

	//load congrate animation
	FreeSpin::m_pCongrats_Anim = FreeSpin::m_pFreespinFrame->FindChildById<UIAnimation>(UI_IdDef::FREESPIN_CONGRATION_ANIM);
	FreeSpin::m_pCongrats_label = FreeSpin::m_pFreespinFrame->FindChildById<UILabelValueTweener>(UI_IdDef::FREESPIN_CONGRATION_LABEL);
}


//************************************
// Method:    StartFreeSpinProcess
// FullName:  BSSlotsContainer::StartFreeSpinProcess
// Access:    protected 
// Returns:   void
// Qualifier: check freespin count and ready for freespin
//************************************
void FreeSpin::StartFreeSpinProcess(TicketGenerator *pTicketGenerator, GTArray<int>* pSlotsSymbols)
{
	//m_status = Status_FreeSpin_Start;	//set status;

	if(pTicketGenerator == NULL)
	{
		//m_status = Status_FreeSpin_End;
		return;
	}

	//step1: check bonus symbols we have;
	int bonusSymbolID = pTicketGenerator->GetBonusSymbolID();
	int newFreespinCount =  pTicketGenerator->GetFreeSpinCount(pSlotsSymbols, FREESPIN_NUMBER_FOR_EVERY_BONUS_REEL);	//get new freespin count;
	m_freespinCount += newFreespinCount;
	GTLogManager::SLogFormatTrace("Freespin ----> win %d freespin! totoal = %d ", newFreespinCount, m_freespinCount);

	if(m_freespinCount <= 0)
	{
		//m_status = Status_FreeSpin_End;
		GTLogManager::SLogFormatComment("Freespin ---> Finished Freespin!!");
		return;
	}

	DisplayCongrationMsg(m_freespinCount);
}

//display congration msg;
void FreeSpin::DisplayCongrationMsg(int freespinCount)
{
	if(m_pCongrats_Anim)
	{
		m_pCongrats_Anim->SetVisible(true);
		m_pCongrats_Anim->PlayAnimationByIndex(0, GSpriteAnimation::PlayMode_Loop);
	}

	if(m_pCongrats_label)
	{
		m_pCongrats_Anim->SetVisible(true);
		m_pCongrats_label->SetPropertyValue(0);
		m_pCongrats_label->SetValue(freespinCount);
	}
}

void FreeSpin::CloseCongrationMsg()
{
	if(m_pCongrats_Anim)
	{
		m_pCongrats_Anim->SetVisible(false);
		m_pCongrats_Anim->StopAnimation();
	}

	if(m_pCongrats_label)
	{
		m_pCongrats_Anim->SetVisible(false);
	}
}