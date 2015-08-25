#ifndef _SCREEN_MANAGER_H_
#define _SCREEN_MANAGER_H_

#include <GTBaseDef.h>
#include <GTSingleton.h>

class ScreenManager : public GTSingleton<ScreenManager>
{
public:
	ScreenManager();
	~ScreenManager();

	// Get screen width
	uint32 GetScreenWidth() const
	{
		return m_nScreenWidth;
	}
	// Get screen height
	uint32 GetScreenHeight() const
	{
		return m_nScreenHeight;
	}
	// Get screen half width
	uint32 GetScreenHalfWidth() const
	{
		return m_nScreenHalfWidth;
	}
	// Get screen half height
	uint32 GetScreenHalfHeight() const
	{
		return m_nScreenHalfHeight;
	}

	// Set screen width
	void SetScreenWidth(const uint32 w);
	// Set screen height
	void SetScreenHeight(const uint32 h);
	// Set screen size
	void SetScreenSize(const uint32 w, const uint32 h);

protected:
	uint32 m_nScreenWidth;
	uint32 m_nScreenHeight;
	uint32 m_nScreenHalfWidth;
	uint32 m_nScreenHalfHeight;
};

#endif /* _SCREEN_MANAGER_H_ */
