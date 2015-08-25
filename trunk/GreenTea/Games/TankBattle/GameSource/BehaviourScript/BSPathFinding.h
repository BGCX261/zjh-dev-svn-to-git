#ifndef _BS_PATH_FINDING_H_
#define _BS_PATH_FINDING_H_

#include <GTGreenTea.h>
#include <ScenePathFinding.h>

class BSPathFinding : public GTBehaviour
{
public:
	GTBEHAVIOUR_DEF(BSPathFinding, GTBehaviour);

public:
	BSPathFinding();
	virtual ~BSPathFinding();

	// This method is called when GTBehaviour object is created.
	virtual int32 OnCreate(void);
	// This method is called when GTBehaviour object is initialized.
	virtual int32 OnInitialize(GTBehaviourInit* param);
	// This method is called when GTBehaviour object is updated.
	virtual int32 OnUpdate(void);
	// This method is called when GTBehaviour object is destroyed.
	virtual int32 OnDestroy(void);

	// Do path finding
	void DoPathFinding(const GTPoint2 mapDestinationPosition);
	// Get a path node from the result
	GTPoint2 GetPathNode(const int32 index)
	{
		DBG_ASSERT(m_pPathFindingResult);
		return GTPoint2((float)m_pPathFindingResult[index].x, (float)m_pPathFindingResult[index].y);
	}
	// Get the length of path finding result
	int32 GetPathFindingResultLength(void) const
	{
		return m_nPathFindingResultLength;
	}

public:
	// Path finding object
	ScenePathFinding m_PathFinding;
	// Path result
	CPF_Pos *m_pPathFindingResult;
	// How many path nodes stored in m_pPathFindingResult
	int32 m_nPathFindingResultLength;

private:
	// Max length for path finding
	static const int32 m_nPathFindingResultMaxLength;
};

#endif /* _BS_PATH_FINDING_H_ */
