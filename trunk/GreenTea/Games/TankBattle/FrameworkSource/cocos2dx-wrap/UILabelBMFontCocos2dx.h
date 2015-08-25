#ifndef _UI_LABEL_BM_FONT_COCOS2DX_H_
#define _UI_LABEL_BM_FONT_COCOS2DX_H_

#include <GTGreenTea.h>
#include <cocos2d.h>
#include <UI/UILabelBMFont.h>

class UILabelBMFontCocos2dx : public UILabelBMFont
{
public:
	UILabelBMFontCocos2dx();
	virtual ~UILabelBMFontCocos2dx();

	// Initialize the font
	virtual bool Initialize(const char* szFontName, const int32 nZOrder);
	virtual bool Initialize(const char* szText, const char* szFontName, const int32 nZOrder);
	// Set the text
	virtual void SetText(const char* szText);
	// Set visible
	virtual void SetVisible(bool visible);
	virtual bool GetVisible(void);
	// Set position
	virtual void SetPosition(const float x, const float y)
	{
		DBG_ASSERT(m_pCCLabelBMFont);
		m_pCCLabelBMFont->setPosition(cocos2d::CCPoint(x, y));
	}
	virtual void SetPosition(const GTPoint2& position)
	{
		DBG_ASSERT(m_pCCLabelBMFont);
		m_pCCLabelBMFont->setPosition(cocos2d::CCPoint(position.x, position.y));
	}
	virtual GTPoint2 GetPosition(void)
	{
		DBG_ASSERT(m_pCCLabelBMFont);
		cocos2d::CCPoint pt = m_pCCLabelBMFont->getPosition();
		return GTPoint2(pt.x, pt.y);
	}
	// Set/Get anchor point
	virtual void SetAnchorPoint(const GTVector2& anchorPoint)
	{
		DBG_ASSERT(m_pCCLabelBMFont);
		m_pCCLabelBMFont->setAnchorPoint(cocos2d::CCPoint(anchorPoint.x, anchorPoint.y));
	}
	virtual GTVector2 GetAnchorPoint(void) const
	{
		DBG_ASSERT(m_pCCLabelBMFont);
		cocos2d::CCPoint pt = m_pCCLabelBMFont->getAnchorPoint();
		return GTVector2(pt.x, pt.y);
	}
	// Set/Get Z-order
	virtual int32 GetZOrder(void) const
	{
		DBG_ASSERT(m_pCCLabelBMFont);
		return m_pCCLabelBMFont->getZOrder();
	}
	virtual void SetZOrder(const int32 nNewZOrder)
	{
		DBG_ASSERT(m_pCCLabelBMFont);
		m_pCCLabelBMFont->getParent()->reorderChild(m_pCCLabelBMFont, nNewZOrder);
	}	
	// Release
	virtual bool Release(void);
	// Update
	virtual void OnUpdate(void);

protected:
	// CCLabelBMFont object
	cocos2d::CCLabelBMFont* m_pCCLabelBMFont;
	// String
	GTString m_sText;
};

#endif /* _UI_LABEL_BM_FONT_COCOS2DX_H_ */
