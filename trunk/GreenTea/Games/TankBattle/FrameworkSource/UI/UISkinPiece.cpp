#include "UISkinPiece.h"

UISkinPiece::UISkinPiece() :
	m_sName(GTString::EmptyString),
	m_Rect(0, 0, 0, 0)
{
}


UISkinPiece::~UISkinPiece()
{
}


void UISkinPiece::Release(void)
{
	delete this;
}
