//===========================================================
//
// FileName: ScenePathFinding.h
// Desc: Path Find
//
// Write by zjh 05/30/2001
//
//===========================================================

#ifndef _GREENTEA_PATH_FINDING_H_
#define _GREENTEA_PATH_FINDING_H_

//===========================================================

#include "GTBaseDef.h"

//===========================================================
//
// Macro
//
//===========================================================
#define CPF_TABLE_LENGTH (1024L)

//===========================================================
//
// Type
//
//===========================================================
typedef int32 (* CPF_FunctionExtend)( void *pSysParam );

//===========================================================
//
// Enum
//
//===========================================================
//----------------------------------------------
// 队列状态
//----------------------------------------------
typedef enum _CPF_SequenceState {
	SS_NORMAL, // 一般状态（非空非满有若干元素）
	SS_EMPTY,  // 队列为空
	SS_FULL    // 队列为满
} CPF_SequenceState;

//----------------------------------------------
// 搜索方向，4向还是8向
// 4向：上、下、左、右
// 8向：上、下、左、右、左上、左下、右上、右下
//----------------------------------------------
typedef enum _CPF_SearchDirection
{
	CPF_SD_FOUR = 0,
	CPF_SD_EIGHT = 1,
} CPF_SearchDirection;


//===========================================================
//
// Structure
//
//===========================================================
//----------------------------------------------
// Pos
//----------------------------------------------
typedef struct _CPF_Pos {
	int32 x;
	int32 y;
} CPF_Pos;

//----------------------------------------------
// Node
//----------------------------------------------
typedef struct _CPF_Node {
	CPF_Pos father; // 父节点 x/y 坐标任何一值小于 0 则无父节点
	CPF_Pos pos;    // 当前节点的位置
	int32 f;         // f - f(x) = g(x) + h(x)
	int32 g;         // g - f(x) = g(x) + h(x)
	int32 h;         // h - f(x) = g(x) + h(x)
} CPF_Node;

//----------------------------------------------
// Table
//----------------------------------------------
typedef struct _CPF_Table {
	int32 lCount;
	CPF_Node Node[CPF_TABLE_LENGTH];
} CPF_Table;

//----------------------------------------------
// Search result
//----------------------------------------------
#define CPF_PATH_RESULT_POS_LENGTH (512)
typedef struct _CPF_PathResult
{
	CPF_Pos pos[CPF_PATH_RESULT_POS_LENGTH];
	int32 nLength;
} CPF_PathResult;

//----------------------------------------------
// Grid
//----------------------------------------------
//---------------------------------
// flags
//---------------------------------
#define PFG_FLAG_OBSTACLE (0x01)
//---------------------------------
// grid
//---------------------------------
typedef struct _CPF_PFGrid
{
	uint16 wFlags;
} CPF_PFGrid;

//===========================================================
//
// GTPathFinding Class
//
//===========================================================
class GTPathFinding
{
protected:
	//----------------------------------------------
	// map data
	//----------------------------------------------
	uint32 m_nMapWidth;
	uint32 m_nMapHeight;
	uint32 *m_pMapDataPtr;
	// Maximum length for storeing open table
	uint32 m_nPathFindingOpenTableMaxLength;
	// Maximum length for storing path finding result
	uint32 m_nPathFindingResultPathMaxLength;	
	CPF_SearchDirection m_SearchDirection;

	//----------------------------------------------
	// table-data
	//----------------------------------------------
	CPF_Table m_OpenTable;
	CPF_Table m_ClosedTable;

	//----------------------------------------------
	// pos
	//----------------------------------------------
	CPF_Pos m_StartPos;
	CPF_Pos m_EndPos;

	//----------------------------------------------
	// flag
	//----------------------------------------------
	bool m_bFound;
	CPF_Node m_FinalNode;
	CPF_FunctionExtend m_pFunctionExtend;


public:
	void Construction( void );
	GTPathFinding();
	virtual ~GTPathFinding();

	virtual bool Initialize(
		const int32 nStartPosX,
		const int32 nStartPosY,
		const int32 nEndPosX,
		const int32 nEndPosY
		);
	//----------------------------------------------
	// Check if this postion is passable
	//----------------------------------------------
	virtual bool IsObstacle(const int32 x, const int32 y) = 0;

	//----------------------------------------------
	// init
	//----------------------------------------------
	void SetStartPos( CPF_Pos *pPos ) { m_StartPos = (*pPos); }
	void SetStartPos( const int32& x, const int32& y ) { m_StartPos.x = x; m_StartPos.y = y; }
	void SetEndPos( CPF_Pos *pPos )   { m_EndPos = (*pPos); }
	void SetEndPos( const int32& x, const int32& y ) { m_EndPos.x = x; m_EndPos.y = y; }	
	bool Flush( void );

	//----------------------------------------------
	// release
	//----------------------------------------------
	virtual void Release( void );

	//----------------------------------------------
	// set
	//----------------------------------------------
	//bool SetObstacle( int32 x, int32 y, bool bObstacle );
	bool SetExtFunction( CPF_FunctionExtend pFun );

	//----------------------------------------------
	// search
	//----------------------------------------------
	bool Search( CPF_Pos *pPos, int32 lBufLen, int32 *plPathLen);

	//----------------------------------------------
	// clear
	//----------------------------------------------
	void Clear( void );

	//----------------------------------------------
	// check
	//----------------------------------------------
	//bool IsInit( void ) { if(NULL==m_pMapData) return false; return true; }

	void SetSearchDirection(const CPF_SearchDirection direction)
	{
		m_SearchDirection = direction;
	}

	CPF_SearchDirection GetSearchDirection(void)
	{
		return m_SearchDirection;
	}

	void SetOpenTableMaxLength(const uint32 nMaxLength)
	{
		DBG_ASSERT(nMaxLength);
		m_nPathFindingOpenTableMaxLength = nMaxLength;
	}
	uint32 GetOpenTableMaxLength(void) const
	{
		return m_nPathFindingOpenTableMaxLength;
	}

	void SetResultPathMaxLength(const uint32 nMaxLength)
	{
		DBG_ASSERT(nMaxLength);
		m_nPathFindingResultPathMaxLength = nMaxLength;
	}
	uint32 GetResultPathMaxLength(void) const
	{
		return m_nPathFindingResultPathMaxLength;
	}	

private:
	//----------------------------------------------
	// get result
	//----------------------------------------------
	void GetPathResult( CPF_Node *pNodeDst, CPF_Pos *pPos, int32 lBufLen, int32 *plResCount );

	//----------------------------------------------
	// create child from best node
	//----------------------------------------------
	void      CreateChildNode( CPF_Node *pBestNode );
	
	//----------------------------------------------
	// check the node is in open-table/closed-table
	//----------------------------------------------
	CPF_Node *CheckOpenTable( int32 x, int32 y );
	CPF_Node *CheckClosedTable( int32 x, int32 y );

	//----------------------------------------------
	// find father node in open-table/closed-table
	//----------------------------------------------
	CPF_Node *FindFatherNodeInOpenTable( CPF_Node *pChildNode );
	CPF_Node *FindFatherNodeInClosedTable( CPF_Node *pChildNode );

	//----------------------------------------------
	// sort open-table
	//----------------------------------------------
	void      SortOpenTable( void );

	//----------------------------------------------
	// add child node to open table
	//----------------------------------------------
	void      AddChildNodeToOpenTable( CPF_Node *pBestNode, int32 x, int32 y );
};

//===========================================================

#endif // _GREENTEA_PATH_FINDING_H_
