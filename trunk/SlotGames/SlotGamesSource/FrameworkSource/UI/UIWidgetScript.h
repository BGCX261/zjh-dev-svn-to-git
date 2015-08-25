#ifndef _UI_WIDGET_SCRIPT_H_
#define _UI_WIDGET_SCRIPT_H_

#include <GTBehaviour.h>
#include "../UI/UIWidget.h"

class UIWidgetScript : public GTBehaviour
{
public:
	UIWidgetScript();
	~UIWidgetScript();

	virtual bool OnSingleClick(const uint32 nFlags, const GTPoint2& pos) { return false; }
	virtual bool OnDoubleClick(const uint32 nFlags, const GTPoint2& pos) { return false; }
	virtual bool OnMove(const uint32 nFlags, const GTPoint2& pos, const GTPoint2& delta, bool dragging) { return false; }
	virtual bool OnStateChange(const uint32 nState) { return false; }
};

#endif /* _UI_WIDGET_SCRIPT_H_ */
