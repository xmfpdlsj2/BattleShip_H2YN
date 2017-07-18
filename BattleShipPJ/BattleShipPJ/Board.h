#pragma once
#include "Enums.h"
class CBoard
{
	
public:
	CBoard();
	virtual ~CBoard();
	
	EShipType GetMapPosition(int x, int y); 
	EShipType GetMapPosition(char x, char y) 
	{ return GetMapPosition((int)(x - '1'), (int)(y - 'A'));}
	int GetMapHitState(int x, int y);

	void SetMapPosition(int x, int y, EShipType shipType) { m_Map[y][x] = shipType; }
	void SetMapHitState(int x, int y) { m_HitMap[y - 'A'][x - '1'] = 1; }
	void SetMapPosition(char x, char y, EShipType shipType)
	{ SetMapPosition((int)(x - '1'), (int)(y - 'A'), shipType); }
	int GetMapSize() { return m_MapSize; }
	
protected:
	EShipType m_Map[8][8] ={SHIP_NONE,};		//¸Ê ¼±¾ð
	int m_HitMap[8][8] = { 0, };
	int m_MapSize = 8;
};

