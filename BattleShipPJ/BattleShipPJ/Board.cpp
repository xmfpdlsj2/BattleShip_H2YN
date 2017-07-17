#include "Board.h"



CBoard::CBoard()
{

}


CBoard::~CBoard()
{
}

EShipType CBoard::GetMapPosition(int x, int y)
{
	if (x < m_MapSize && y < m_MapSize && x >= 0 && y >= 0)
		return m_Map[y][x];

	return (EShipType)-1;
}
