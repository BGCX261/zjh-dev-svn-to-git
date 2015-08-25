//===========================================================
//
// FileName: GTPathFinding.cpp
// Desc: Path Find
//
// Write by zjh 05/30/2001
//
//===========================================================

#include "GTPathFinding.h"

//===========================================================
//
// GTPathFinding Class Function Body
//
//===========================================================


//===========================================================
//
// Desc: Construction
//
//===========================================================
void GTPathFinding::Construction( void )
{
	m_nMapWidth = 0;
	m_nMapHeight = 0;
	m_pMapDataPtr = NULL;
	m_SearchDirection = CPF_SD_FOUR;

	Clear();

	m_pFunctionExtend = NULL;
}

GTPathFinding::GTPathFinding():
	m_nPathFindingOpenTableMaxLength(CPF_TABLE_LENGTH),
	m_nPathFindingResultPathMaxLength(CPF_PATH_RESULT_POS_LENGTH)
{
	Construction();
}



//===========================================================
//
// Desc: Deconstruction
//
//===========================================================
GTPathFinding::~GTPathFinding()
{
	Release();

	return;
}



//===========================================================
//
// Desc: init
//
// [In]
// dwMapWidth  - the width of map
// dwMapHeight - the height of map
//
// [Out]
//
// [Return]
// true  - succeed
// false - failed
//
//===========================================================
bool GTPathFinding::Initialize(
		const int32 nStartPosX,
		const int32 nStartPosY,
		const int32 nEndPosX,
		const int32 nEndPosY
		)
{
	// Clear the tables
	Clear();

	// Set start position
	SetStartPos(nStartPosX, nStartPosY);
	// Set end position
	SetEndPos(nEndPosX, nEndPosY);
	// Initialize start/end position node and 'Open Table'.
	Flush();

	return true;
}



//===========================================================
//
// Desc: flush
//
// [In]
//
// [Out]
//
// [Return]
// true  - succeed
// false - failed
//
//===========================================================
bool GTPathFinding::Flush( void )
{
	//---------------------------------------
	// check
	//---------------------------------------
	/*
	if( false == IsInit() )
		return false;
		*/

	//---------------------------------------
	// ��ʼ����һ���ڵ�
	//---------------------------------------
	CPF_Node node;
	node.father.x = -1L; // no father node
	node.father.y = -1L; // no father node
	node.pos = m_StartPos; // source position
	node.g = 0L;
	node.h = (m_EndPos.x-m_StartPos.x)*(m_EndPos.x-m_StartPos.x)+(m_EndPos.y-m_StartPos.y)*(m_EndPos.y-m_StartPos.y);
	node.f = node.g + node.h; // �������ֵ

	//---------------------------------------
	// ����ʼ�ڵ���� OPEN ��
	//---------------------------------------
	m_OpenTable.Node[0] = node;
	m_OpenTable.lCount++;

	return true;
}



//===========================================================
//
// Desc: release
//
// [In]
//
// [Out]
//
// [Return]
//
//===========================================================
void GTPathFinding::Release( void )
{
	/*
	if( m_pMapData )
	{
		delete [] m_pMapData;
		m_pMapData = NULL;
	}

	m_dwMapWidth = 0;
	m_dwMapHeight = 0;
	*/

	m_nMapWidth = 0;
	m_nMapHeight = 0;
	m_pMapDataPtr = NULL;

	Clear();
	m_pFunctionExtend = NULL;

	return;
}



//===========================================================
//
// Desc: set
//
// [In]
// x/y - the position want to set obstacle
// bObstacle - the flag
//             true  for obstacle
//             FLASE for not obstacle
//
// [Out]
//
// [Return]
// true  - succeed
// false - failed
//
//===========================================================
/*
bool GTPathFinding::SetObstacle( int32 x, int32 y, bool bObstacle )
{
	//----------------------------------------------
	// check
	//----------------------------------------------
	if( false == IsInit() )
		return false;

	uint32 dwOffset = (uint32)y*m_dwMapWidth + (uint32)x;
	if( dwOffset >= (m_dwMapWidth*m_dwMapHeight) )
		return false;

	if( bObstacle )
	{
		m_pMapData[dwOffset].wFlags |= PFG_FLAG_OBSTACLE;
	}
	else
	{
		m_pMapData[dwOffset].wFlags &= (~PFG_FLAG_OBSTACLE);
	}

	return true;
}
*/



//===========================================================
//
// Desc: search
//
// [In]
// pPos      - the result buffer
// lBufLen   - the length of pPos
// plPathLen - the length of result
//
// [Out]
// pPos      - the result buffer
// plPathLen - the length of result
//
// [Return]
// true  - succeed
// false - failed
//
//===========================================================
bool GTPathFinding::Search(CPF_Pos *pPos, int32 lBufLen, int32 *plPathLen)
{
	CPF_Node BestNode;
	int32 lPathLen;

	if(NULL == m_pMapDataPtr)
	{
		return false;
	}

	//-------------------------------------------------
	// loop
	//-------------------------------------------------
	while( 0L != m_OpenTable.lCount )
	{
		// �� OPEN ����ȡ����õĽڵ㣬����һ���ڵ�
		BestNode = m_OpenTable.Node[0];

		// ����Ƿ��Ѿ�����Ŀ�Ľڵ�
		if( true == m_bFound )
		{
			// ����·��
			GetPathResult( &m_FinalNode, pPos, lBufLen, &lPathLen );
			(*plPathLen) = lPathLen;
			Clear();
			break;
		}

		// û�е���Ŀ�Ľڵ㣬����õĽڵ������ӽڵ�
		CreateChildNode( &BestNode );

		/*
#ifdef _DEBUG
		if( m_pFunctionExtend )
		{
			m_pFunctionExtend( (void*)this );
		}
#endif // _DEBUG
		*/
	}

	return true;
}



//===========================================================
//
// Desc: get result
//
// [In]
// pNodeDst   -
// pPos       -
// lBufLen    -
// plResCount -
//
// [Out]
//
// [Return]
//
//===========================================================
void GTPathFinding::GetPathResult(CPF_Node *pNodeDst, 
								  CPF_Pos *pPos, 
							      int32 lBufLen, 
							      int32 *plResCount )
{
	CPF_Node *pFatherNode = NULL;
	CPF_Node *pTempNode = NULL;
	int32 lCount = 0L;
	int32 i;
	static CPF_Pos posBuf[1024];

	pTempNode = pNodeDst;

	while( 1 )
	{
		// ����һ���ڵ�
		pPos[lCount] = pTempNode->pos;
		lCount++;

		// �õ���ǰ�ڵ�ĸ��ڵ�
		pFatherNode = FindFatherNodeInClosedTable( pTempNode );
		if( NULL == pFatherNode )
			break;

		pTempNode = pFatherNode;
	}

	// ��˳����������
	for( i=0; i<lCount; i++ )
	{
		posBuf[i] = pPos[i];
	}

	for( i=0; i<lCount; i++ )
	{
		pPos[i] = posBuf[lCount-i-1];
	}
	
	(*plResCount) = lCount;
	
	return;
}



//===========================================================
//
// Desc: clear
//
// [In]
//
// [Out]
//
// [Return]
//
//===========================================================
void GTPathFinding::Clear( void )
{
	m_OpenTable.lCount = 0L;
	m_ClosedTable.lCount = 0L;

	m_bFound = false;

	return;
}



//===========================================================
//
// Desc: create child from best node
//
// [In]
// pBestNode - extracts node
//
// [Out]
//
// [Return]
//
//===========================================================
void GTPathFinding::CreateChildNode( CPF_Node *pBestNode )
{
	CPF_Node fatherNode;
	int32 x, y;
	int32 i;

	//---------------------------------------------------
	// ���游�ڵ�
	//---------------------------------------------------
	fatherNode = (*pBestNode);

	//---------------------------------------------------
	// �� OPEN ����ɾ����ýڵ���뵽 CLOSED ����
	//---------------------------------------------------
	m_ClosedTable.Node[m_ClosedTable.lCount] = (*pBestNode);
	m_ClosedTable.lCount++;
	if( m_ClosedTable.lCount >= CPF_TABLE_LENGTH )
		return;

	//---------------------------------------------------
	// ע��
	//
	// �� OPEN ����ɾ����һ���ڵ㣬Ҳ������õĽڵ㡣
	// �� OPEN ���е�һ���Ժ��Ԫ����ǰ�ƶ�һ����Ԫ��
	//---------------------------------------------------
	for( i=1; i<m_OpenTable.lCount; i++ )
	{
		m_OpenTable.Node[i-1] = m_OpenTable.Node[i];
	} // for(i)
	m_OpenTable.lCount--;


	//---------------------------------------------------
	//
	// ��չ�ڵ�
	//
	//---------------------------------------------------

	//--------------------------------------------
	// ��������Ľڵ�
	//--------------------------------------------
	x = pBestNode->pos.x;
	y = pBestNode->pos.y - 1;
	if( false == IsObstacle( x, y ) )
		AddChildNodeToOpenTable( pBestNode, x, y );
	if( true == m_bFound )
		return;

	//--------------------------------------------
	// ��������Ľڵ�
	//--------------------------------------------
	x = pBestNode->pos.x;
	y = pBestNode->pos.y + 1;
	if( false == IsObstacle( x, y ) )
		AddChildNodeToOpenTable( pBestNode, x, y );
	if( true == m_bFound )
		return;

	//--------------------------------------------
	// ��������Ľڵ�
	//--------------------------------------------
	x = pBestNode->pos.x - 1;
	y = pBestNode->pos.y;
	if( false == IsObstacle( x, y ) )
		AddChildNodeToOpenTable( pBestNode, x, y );
	if( true == m_bFound )
		return;

	//--------------------------------------------
	// ��������Ľڵ�
	//--------------------------------------------
	x = pBestNode->pos.x + 1;
	y = pBestNode->pos.y;
	if( false == IsObstacle( x, y ) )
		AddChildNodeToOpenTable( pBestNode, x, y );
	if( true == m_bFound )
		return;


	if(CPF_SD_EIGHT == m_SearchDirection)
	{
	//--------------------------------------------
	// �������ϵĽڵ�
	//--------------------------------------------
	x = pBestNode->pos.x - 1;
	y = pBestNode->pos.y - 1;
	if( false == IsObstacle( x, y ) )
		AddChildNodeToOpenTable( pBestNode, x, y );
	if( true == m_bFound )
		return;

	//--------------------------------------------
	// �������µĽڵ�
	//--------------------------------------------
	x = pBestNode->pos.x - 1;
	y = pBestNode->pos.y + 1;
	if( false == IsObstacle( x, y ) )
		AddChildNodeToOpenTable( pBestNode, x, y );
	if( true == m_bFound )
		return;

	//--------------------------------------------
	// ����������Ľڵ�
	//--------------------------------------------
	x = pBestNode->pos.x + 1;
	y = pBestNode->pos.y - 1;
	if( false == IsObstacle( x, y ) )
		AddChildNodeToOpenTable( pBestNode, x, y );
	if( true == m_bFound )
		return;

	//--------------------------------------------
	// ����������Ľڵ�
	//--------------------------------------------
	x = pBestNode->pos.x + 1;
	y = pBestNode->pos.y + 1;
	if( false == IsObstacle( x, y ) )
		AddChildNodeToOpenTable( pBestNode, x, y );
	if( true == m_bFound )
		return;
	}

	return;
}



//===========================================================
//
// Desc: check the pos is obstacle or not
//
// [In]
//
// [Out]
//
// [Return]
// TRUE  - for obstacle
// FASLE - for no obstacle
//
//===========================================================
/*BOOL GTPathFinding::CheckFreeMap( LONG x, LONG y )
{
#ifdef _DEBUG
	if( x < 0L || y < 0L )
		return TRUE;

	if( x >= (LONG)m_dwMapWidth ||
		y >= (LONG)m_dwMapHeight )
		return TRUE;
#endif // _DEBUG

	uint32 dwOffset = (uint32)y*m_dwMapWidth + (uint32)x;

	return m_pMapData[dwOffset];
}*/



//===========================================================
//
// Desc: check the node is in open-table
//
// [In]
// x/y - the position want to check
//
// [Out]
//
// [Return]
// != NULL - succeed
// == NULL - failed
//
//===========================================================
CPF_Node *GTPathFinding::CheckOpenTable( int32 x, int32 y )
{
	CPF_Node *pn = NULL;
	int32 i;

	for( i=0; i<m_OpenTable.lCount; i++ )
	{
		pn = &m_OpenTable.Node[i];
		if( pn->pos.x == x && pn->pos.y == y )
			return pn;
	} // for(i)

	return NULL;
}



//===========================================================
//
// Desc: check the node is in closed-table
//
// [In]
// x/y - the position want to check
//
// [Out]
//
// [Return]
// != NULL - succeed
// == NULL - failed
//
//===========================================================
CPF_Node *GTPathFinding::CheckClosedTable( int32 x, int32 y )
{
	CPF_Node *pn = NULL;
	int32 i;

	for( i=0; i<m_ClosedTable.lCount; i++ )
	{
		pn = &m_ClosedTable.Node[i];
		if( pn->pos.x == x && pn->pos.y == y )
			return pn;
	} // for(i)

	return NULL;
}



//===========================================================
//
// Desc: find father node in open-table
//
// [In]
//
// [Out]
//
// [Return]
//
//===========================================================
CPF_Node *GTPathFinding::FindFatherNodeInOpenTable( CPF_Node *pChildNode )
{
	return NULL;
}


//===========================================================
//
// Desc: find father node in closed-table
//
// [In]
// pChildNode - find node specialed by pChildNode
//
// [Out]
//
// [Return]
// != NULL - succeed
// == NULL - failed
//
//===========================================================
CPF_Node *GTPathFinding::FindFatherNodeInClosedTable( CPF_Node *pChildNode )
{
	CPF_Node *pn = NULL;
	int32 i;

	for( i=0; i<m_ClosedTable.lCount; i++ )
	{
		pn = &m_ClosedTable.Node[i];
		// ���ڵ�������Ա pos Ӧ�ú��ӽڵ�� father ��Ա���
		if( pn->pos.x == pChildNode->father.x &&
			pn->pos.y == pChildNode->father.y )
		{
			return pn;
		}
	} // for(i)

	return NULL;
}



//===========================================================
//
// Desc: sort open-table
//
// [In]
//
// [Out]
//
// [Return]
//
//===========================================================
void GTPathFinding::SortOpenTable( void )
{
	CPF_Node node;
	int32 i, j;

	// ����
	for( i=0; i<m_OpenTable.lCount; i++ )
	{
		for( j=i+1; j<m_OpenTable.lCount; j++ )
		{
			// �Ƚ� f ֵ
			if( m_OpenTable.Node[j].f < m_OpenTable.Node[i].f )
			{
				node = m_OpenTable.Node[j];
				m_OpenTable.Node[j] = m_OpenTable.Node[i];
				m_OpenTable.Node[i] = node;
			} // if()
		} // for(j)
	} // for(i)

	return;
}


//===========================================================
//
// Desc: add child node to open table
//
// [In]
// pBestNode - the node want to add
// x/y       - the position want to add to open-table
//
// [Out]
//
// [Return]
//
//===========================================================
void GTPathFinding::AddChildNodeToOpenTable( CPF_Node *pBestNode, int32 x, int32 y )
{
	CPF_Node *pOld = NULL;
	CPF_Node node;
	int32 g;

	//--------------------------------------------
	// ����Ƿ��Ѿ��ҵ�Ŀ�Ľڵ�
	//--------------------------------------------
	if( m_EndPos.x == x && m_EndPos.y == y )
	{
		m_bFound = true;
	}
		
	//--------------------------------------------
	// ������ӽڵ�� g ֵ
	//--------------------------------------------
	g = pBestNode->g + 1;

	//--------------------------------------------
	// 1.�����½ڵ��Ƿ��� OPEN ���У��������Ƚ�
	//   ����ֵ���Ƿ���Ҫ���¹���ֵ��
	//--------------------------------------------
	if( NULL != (pOld=CheckOpenTable(x, y)) )
	{
		// �½ڵ��� OPEN ����
		// �Ƚ� g ֵ������� g ֵС�ھ� g ֵ
		// ����¸ýڵ�
		if( g < pOld->g )
		{
			// ���¸ýڵ�
			pOld->father = pBestNode->pos;
			pOld->pos.x = x;
			pOld->pos.y = y;
			pOld->f = g + pOld->h;
		} // if()

		node = (*pOld);
	} // if()
	//--------------------------------------------
	// 2.�����½ڵ��Ƿ��� CLOSED ���У��������Ƚ�
	//   ����ֵ���Ƿ���Ҫ���¹���ֵ��
	//--------------------------------------------
	else if( NULL != (pOld=CheckClosedTable(x, y)) )
	{
		// �½ڵ��� CLOSED ����
		// �Ƚ� g ֵ������� g ֵС�ھ� g ֵ
		// ����¸ýڵ�
		if( g < pOld->g )
		{
			// ���¸ýڵ�
			pOld->father = pBestNode->pos;
			pOld->pos.x = x;
			pOld->pos.y = y;
			pOld->f = g + pOld->h;
		} // if()

		node = (*pOld);
	} // else if()
	//--------------------------------------------
	// 3.�½ڵ�Ȳ��� OPEN ����Ҳ���� CLOSED ���У�
	// �����½ڵ㣬�����ýڵ���� OPEN ���С�
	//--------------------------------------------
	else
	{
		node.father = pBestNode->pos; // ������ӽڵ�ĸ��ڵ�
		node.pos.x = x; // ������ӽڵ������
		node.pos.y = y;
		node.g = g;
		node.h = (m_EndPos.x-x)*(m_EndPos.x-x)+(m_EndPos.y-y)*(m_EndPos.y-y);
		node.f = g + node.h;

		// ���ýڵ���뵽 OPEN ����
		m_OpenTable.Node[m_OpenTable.lCount] = node;
		m_OpenTable.lCount++;
		if( m_OpenTable.lCount > CPF_TABLE_LENGTH )
			return;
	} // else()

	//--------------------------------------------
	// �� OPEN ������
	//--------------------------------------------
	SortOpenTable();

	//--------------------------------------------
	// ��¼�ҵ������һ���ڵ�
	//--------------------------------------------
	if( true == m_bFound )
	{
		m_FinalNode = node;
	}

	return;
}


//===========================================================
//
// Desc: the function for debug
//
// [In]
// pFun - the function want to set
//
// [Out]
//
// [Return]
// true  - succeed
// false - failed
//
//===========================================================
bool GTPathFinding::SetExtFunction( CPF_FunctionExtend pFun )
{
	m_pFunctionExtend = pFun;

	return true;
}
