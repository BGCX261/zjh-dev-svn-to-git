#include "BSPathFinding.h"
#include <MapManager.h>
//#include <GTNew.h>

GTBEHAVIOUR_IMP(BSPathFinding, GTBehaviour);

// Max length for path finding
const int32 BSPathFinding::m_nPathFindingResultMaxLength = 256;

BSPathFinding::BSPathFinding()
{
}


BSPathFinding::~BSPathFinding()
{
}


// This method is called when GTBehaviour object is created.
int32 BSPathFinding::OnCreate(void)
{
	GTBehaviour::OnCreate();

	return 1;
}


// This method is called when GTBehaviour object is initialized.
int32 BSPathFinding::OnInitialize(GTBehaviourInit* param)
{
	GTBehaviour::OnInitialize(param);

	DBG_ASSERT(m_pGameObject);

	// Allocate memory for path finding
	m_pPathFindingResult = new CPF_Pos[BSPathFinding::m_nPathFindingResultMaxLength];
	if(NULL == m_pPathFindingResult)
	{
		return 0;
	}
	m_nPathFindingResultLength = 0;

	return 1;
}


// This method is called when GTBehaviour object is updated.
int32 BSPathFinding::OnUpdate(void)
{
	GTBehaviour::OnUpdate();

	return 1;
}


// This method is called when GTBehaviour object is destroyed.
int32 BSPathFinding::OnDestroy(void)
{
	GTBehaviour::OnDestroy();

	if(m_pPathFindingResult)
	{
		delete [] m_pPathFindingResult;
		m_pPathFindingResult = NULL;
	}

	m_nPathFindingResultLength = 0;

	return 1;
}


// Do path finding
void BSPathFinding::DoPathFinding(const GTPoint2 mapDestinationPosition)
{
	// Transoform the destination positon to tiles from pixels
	const GTSize tileSize = MapManager::GetInstance()->GetMapTileSizeInPixel();
	const int32 nStartX = (int32)(m_pGameObject->m_Position.x / tileSize.width);
	const int32 nStartY = (int32)(m_pGameObject->m_Position.y / tileSize.height);
	const int32 nEndX = (int32)(mapDestinationPosition.x / tileSize.width);
	const int32 nEndY = (int32)(mapDestinationPosition.y / tileSize.height);
	
	m_nPathFindingResultLength = 0;
	// Initialize the path finding object
	m_PathFinding.Initialize(nStartX, nStartY, nEndX, nEndY);
	// Search
	m_PathFinding.Search(
		m_pPathFindingResult,
		BSPathFinding::m_nPathFindingResultMaxLength,
		&m_nPathFindingResultLength
		);
}
