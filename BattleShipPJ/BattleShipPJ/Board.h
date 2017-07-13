#pragma once
#include "Enums.h"
class CBoard
{
	
public:
	CBoard();
	virtual ~CBoard();
	
	EHitState GetMapPosition(int x, int y) { return m_Map[x][y]; }
	int GetMapSize() { return m_MapSize; }
	
protected:
	EHitState m_Map[8][8] ={NONE,};		//�� ����
	int m_MapSize = 8;
};

