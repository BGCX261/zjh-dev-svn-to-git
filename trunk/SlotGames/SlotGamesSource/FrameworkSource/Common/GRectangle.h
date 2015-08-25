#ifndef _G_RECTANGLE_H_
#define _G_RECTANGLE_H_

class GRectangle
{
public:
	GRectangle()
	{
		m_fLeft = m_fTop = m_fRight = m_fBottom = 1.0f;
	}

	GRectangle(float left, float top, float right, float bottom)
	{
		Set(left, top, right, bottom);
	}

	~GRectangle()
	{
	}

	void Set(float left, float top, float right, float bottom)
	{
		m_fLeft = left;
		m_fTop = top;
		m_fRight = right;
		m_fBottom = bottom;
	}

	float GetWidth(void) const
	{
		return (m_fRight - m_fLeft);
	}

	float GetHeight(void) const
	{
		return (m_fBottom - m_fTop);
	}

	float GetLeft(void) const
	{
		return m_fLeft;
	}

	float GetTop(void) const
	{
		return m_fTop;
	}

	float GetRight(void) const
	{
		return m_fRight;
	}

	float GetBottom(void) const
	{
		return m_fBottom;
	}

public:
	float m_fLeft;
	float m_fTop;
	float m_fRight;
	float m_fBottom;
};

#endif /* _G_RECTANGLE_H_ */
