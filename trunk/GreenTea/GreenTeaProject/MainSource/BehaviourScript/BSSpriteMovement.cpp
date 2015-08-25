#include "BSSprite.h"
#include "BSSpriteMovement.h"
#include "BSPathFinding.h"
#include "BSClassName.h"
#include <MapManager.h>

const int32 BSSpriteMovement::DirectionUp = 0;
const int32 BSSpriteMovement::DirectionDown = 1;
const int32 BSSpriteMovement::DirectionLeft = 2;
const int32 BSSpriteMovement::DirectionRight = 3;

const tchar* BSSpriteMovement::RunAnimation[] = {
	CTEXT("RunUp"),
	CTEXT("RunDown"),
	CTEXT("RunLeft"),
	CTEXT("RunRight"),
};

GTBEHAVIOUR_IMP(BSSpriteMovement, GTBehaviour);

BSSpriteMovement::BSSpriteMovement():
	m_nCurrentPathNodeIndex(-1)
{
}


BSSpriteMovement::~BSSpriteMovement()
{
}


// This method is called when GTBehaviour object is created.
int32 BSSpriteMovement::OnCreate(void)
{
	GTBehaviour::OnCreate();

	return 1;
}


// Initialize the properties
void BSSpriteMovement::InitializeProperties(GTTreeNode* pTreeNode)
{
	if(NULL == pTreeNode)
	{
		return;
	}

	m_Speed = pTreeNode->FindChild(CTEXT("Speed"))->ValueToFloat();

	return;
}


// This method is called when GTBehaviour object is initialized.
int32 BSSpriteMovement::OnInitialize(GTBehaviourInitParam* param)
{
	GTBehaviour::OnInitialize(param);

	if(NULL == param || NULL == param->pParam2)
	{
		return 0;
	}

	// Initialize the properties
	InitializeProperties((GTTreeNode*)param->pParam2);

	m_pSprite = (BSSprite*)BSCLASSNAME_GET_COMPONENT(BSClassName::BSSprite);
	m_pPathFinding = (BSPathFinding*)BSCLASSNAME_GET_COMPONENT(BSClassName::BSPathFinding);
	
	return 1;
}


// This method is called when GTBehaviour object is updated.
int32 BSSpriteMovement::OnUpdate(void)
{
	GTBehaviour::OnUpdate();

	if(NULL == m_pPathFinding ||
	   m_pPathFinding->m_nPathFindingResultLength <= 0 ||
	   m_nCurrentPathNodeIndex < 0)
	{
		return 0;
	}

	GTPoint2 position = m_pGameObject->GetPosition();
	GTPoint2 original = m_EndPos - m_StartPos;
	const float length = original.Length();
	original.Normalize();
	// Move forward with the speed in original direction
	position += m_Speed* original;
	const float lengthNew = (position - m_StartPos).Length();
	if(lengthNew >= length)
	{
		// If the position is out of end position, set it to end position
		position = m_EndPos;
		// Go to next movement segement
		GetMovementPathNode(m_nCurrentPathNodeIndex);
	}
	m_pGameObject->SetPosition(position);
	
	return 1;
}


// This method is called when GTBehaviour object is destroyed.
int32 BSSpriteMovement::OnDestroy(void)
{
	GTBehaviour::OnDestroy();

	m_pPathFinding = NULL;

	return 1;
}


// Start moving
void BSSpriteMovement::StartMovement(void)
{
	if(m_pPathFinding)
    {
        if(m_pPathFinding->m_nPathFindingResultLength)
        {
            m_nCurrentPathNodeIndex = 0;
            GetMovementPathNode(m_nCurrentPathNodeIndex);
        }
    }
}


// Stop moving
void BSSpriteMovement::StopMovement(void)
{
	m_nCurrentPathNodeIndex = -1;

	if(m_pSprite)
	{
		m_pSprite->m_pSprite->StopAnimation();
	}
}


// Get direction from two positions
int32 BSSpriteMovement::GetDirection(const CPF_Pos *pos1, const CPF_Pos *pos2)
{
	DBG_ASSERT(pos1);
	DBG_ASSERT(pos2);

	int32 d;
	if(pos2->x == pos1->x)
	{
		d = pos2->y - pos1->y;
		if(!d)
		{
			return -1;
		}
		return (d > 0) ? BSSpriteMovement::DirectionUp : BSSpriteMovement::DirectionDown;
	}
	else if(pos2->y == pos1->y)
	{
		d = pos2->x - pos1->x; 
		if(!d)
		{
			return -1;
		}
		return (d > 0) ? BSSpriteMovement::DirectionRight : BSSpriteMovement::DirectionLeft;
	}

	return -1;
}


void BSSpriteMovement::GetMovementPathNode(const int32 nStartIndex)
{
	if(NULL == m_pPathFinding ||
	   nStartIndex < 0 ||
	   m_pPathFinding->m_nPathFindingResultLength <= 0)
	{
		return;
	}

	// Check if the last node is hit
	if(nStartIndex >= m_pPathFinding->m_nPathFindingResultLength - 1)
	{
		// Reach at end position
		StopMovement();
		return;
	}

	int32 nNodeCount = nStartIndex;
	CPF_Pos p1 = m_pPathFinding->m_pPathFindingResult[nNodeCount++];
	CPF_Pos p2 = m_pPathFinding->m_pPathFindingResult[nNodeCount++];
	m_nDirection = GetDirection(&p1, &p2);
	for(int32 i=nNodeCount; i<m_pPathFinding->m_nPathFindingResultLength; i++)
	{
		CPF_Pos p = m_pPathFinding->m_pPathFindingResult[i];
		int32 dir = GetDirection(&p1, &p);
		if(dir == m_nDirection)
		{
			p2 = p;
			nNodeCount++;
		}
		else
		{
			break;
		}
	}

	// Save last node index
	m_nCurrentPathNodeIndex = nNodeCount - 1;

	m_StartPos = MapManager::GetInstance()->GetTileCenterPositionFromTileBlock((float)p1.x, (float)p1.y);
	m_EndPos = MapManager::GetInstance()->GetTileCenterPositionFromTileBlock((float)p2.x, (float)p2.y);

	// Play proper animation
	m_pSprite->m_pSprite->PlayAnimationByName(
		BSSpriteMovement::RunAnimation[m_nDirection],
		GSpriteAnimation::PlayMode_Loop
		);
}
