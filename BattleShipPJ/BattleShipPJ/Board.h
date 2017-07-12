#pragma once
#include "Enums.h"
class CBoard
{
	
public:
	CBoard();
	virtual ~CBoard();
	
	EHitState GetMapPosition(int x, int y) { return m_Map[x][y]; }
	
protected:
	EHitState m_Map[8][8] ={NONE,};		//¸Ê ¼±¾ð
};

