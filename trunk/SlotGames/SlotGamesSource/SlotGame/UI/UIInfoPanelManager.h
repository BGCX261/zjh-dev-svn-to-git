#ifndef _UI_INFO_PANEL_MANAGER_H_
#define _UI_INFO_PANEL_MANAGER_H_

#include <GTGreenTea.h>

class UIWidget;
class UILabelValueTweener;
class UIAnimation;

class UIInfoPanelManager : public GTObject, public GTSingleton<UIInfoPanelManager>
{
public:
	UIInfoPanelManager();
	virtual ~UIInfoPanelManager();
			
	void AddWin(const int32 nNewValue, const int32 nDurationInMs);
	void ResetWinLabel();
public:
	void Initialize(void);
	void OnSingleClick(UIWidget* pWidget, const uint32 nFlags, const GTPoint2& pos);

protected:
	bool OnEntryLvlValueTweenerFinished(UIWidget* pWidget, void *pParam);
	void OnAnimationPlayingCompletion(void* pParam);

	UILabelValueTweener* FindLabelEntryLvl(void);
	UILabelValueTweener* FindLabelWin(void);
	UILabelValueTweener* FindLabelWinPoints(void);
	UIAnimation* FindAnimationMaxEntry(void);

	void UpdateEntryLevel(const int32 nCurrent, const int32 nTarget);
	void UpdateWin(const int32 nNewValue, const int32 nDurationInMs);
	void AddWinPoints(const int32 nCount);
	void UpdateWinPoints(const int32 nNewValue, const int32 nDurationInMs);

	UILabelValueTweener* m_pLabelEntryLvl;
	UILabelValueTweener* m_pLabelWin;
	UILabelValueTweener* m_pLabelWinPoints;
	UIAnimation* m_pAnimationMaxEntry;
};

#endif /* _UI_INFO_PANEL_MANAGER_H_ */
