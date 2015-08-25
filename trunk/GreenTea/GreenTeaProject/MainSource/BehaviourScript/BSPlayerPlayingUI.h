#ifndef _BS_PLAYER_PLAYING_UI_H_
#define _BS_PLAYER_PLAYING_UI_H_

#include <GTBehaviour.h>
#include "../UI/UIFrame.h"
#include "../UI/UILabel.h"
#include "../UI/UILabelSmoothChange.h"
#include "../UI/UIProgressBar.h"
#include "../UI/UIProgressBarBiCombined.h"

class BSPlayerController;

typedef struct _BSPlayerPlayingUIContainer
{
	// UILabelSmoothChange widget
	UILabelSmoothChange* pUILabel;
	// UIProgressBar widget
	UIProgressBar* pUIProgressBar;
} BSPlayerPlayingUIContainer;

class BSPlayerPlayingUI : public GTBehaviour
{
private:
	// BSPlayerPlayingUIContainer type
	const static int16 UIContainerTypeHP = 0;
	const static int16 UIContainerTypeSP = 1;
	const static int16 UIContainerTypeExp = 2;
	const static int16 UIContainerTypeLevel = 3;
	const static int16 UIContainerTypeMoney = 4;
	const static int16 UIContainerTypeCount = 5;

public:
	GTBEHAVIOUR_DEF(BSPlayerPlayingUI, GTBehaviour);

public:
	BSPlayerPlayingUI();
	virtual ~BSPlayerPlayingUI();

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

	// Initialize a UI container
	void InitializeUIContainer(
		UIFrame* pUIFrame,
		BSPlayerPlayingUIContainer* pContainer,
		const tchar* szLabelName,
		const tchar* szProgressName
		);
	// Setup a UI container
	void SetupUIContainer(
		BSPlayerPlayingUIContainer* pContainer,
		const int32 nMinValue,
		const int32 nMaxValue,
		const int32 nValue
		);

	BSPlayerPlayingUIContainer* GetContainerHP(void)
	{
		return &m_UIContainer[BSPlayerPlayingUI::UIContainerTypeHP];
	}
	BSPlayerPlayingUIContainer* GetContainerSP(void)
	{
		return &m_UIContainer[BSPlayerPlayingUI::UIContainerTypeSP];
	}
	BSPlayerPlayingUIContainer* GetContainerExp(void)
	{
		return &m_UIContainer[BSPlayerPlayingUI::UIContainerTypeExp];
	}
	BSPlayerPlayingUIContainer* GetContainerLevel(void)
	{
		return &m_UIContainer[BSPlayerPlayingUI::UIContainerTypeLevel];
	}
	BSPlayerPlayingUIContainer* GetContainerMoney(void)
	{
		return &m_UIContainer[BSPlayerPlayingUI::UIContainerTypeMoney];
	}

public:
	// BSPlayerController object
	BSPlayerController* m_pBSPlayerController;
	// BSPlayerPlayingUIContainer list
	BSPlayerPlayingUIContainer m_UIContainer[BSPlayerPlayingUI::UIContainerTypeCount];
};

#endif /* _BS_PLAYER_PLAYING_UI_H_ */
