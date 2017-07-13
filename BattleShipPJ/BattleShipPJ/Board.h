#pragma once
#include "Enums.h"
class CBoard
{
	
public:
	CBoard();
	virtual ~CBoard();
	
	EHitState GetMapPosition(int x, int y) { return m_Map[y][x]; }
	void SetMapPosition(int x, int y, EHitState hitState) { m_Map[y][x] = hitState; }
	int GetMapSize() { return m_MapSize; }
	
protected:
	EHitState m_Map[8][8] ={NONE,};		//¸Ê ¼±¾ð
	int m_MapSize = 8;
};

