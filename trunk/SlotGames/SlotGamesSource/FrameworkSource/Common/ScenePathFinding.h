//===========================================================
//
// FileName: ScenePathFinding.h
// Desc: Path Find
//
// Write by zjh 05/30/2001
//
//===========================================================

#ifndef _SCENE_PATH_FINDING_H_
#define _SCENE_PATH_FINDING_H_

#include <GTPathFinding.h>

//===========================================================
//
// ScenePathFinding Class
//
//===========================================================
class ScenePathFinding : public GTPathFinding
{
private:
	uint32 m_nFirstGid;

public:
	ScenePathFinding();
	virtual ~ScenePathFinding();

	virtual bool Initialize(
		const int32 nStartPosX,
		const int32 nStartPosY,
		const int32 nEndPosX,
		const int32 nEndPosY
		);
	virtual void Release( void );
	// Check if this postion is passable
	virtual bool IsObstacle(const int32 x, const int32 y)
	{
		//return ((m_pMapDataPtr[(m_nMapHeight-1-y)*m_nMapWidth + x] - m_nFirstGid) == 1) ? true : false;
		return ((m_pMapDataPtr[(m_nMapHeight-1-y)*m_nMapWidth + x] - m_nFirstGid) != 1) ? true : false;
	}
};

#endif /* _SCENE_PATH_FINDING_H_ */
