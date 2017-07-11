#pragma once
#include "Board.h"
#include "Ship.h"
#include "AircraftCarrier.h"
#include "BattleShip.h"
#include "Cruiser.h"
#include "Destroyer.h"
#include "Submarine.h"

class CPlayer
{
public:
	CPlayer();
	virtual ~CPlayer();

	CBoard playerBoard;
	CBoard enemyBoard;

	std::vector<CShip*> pShipVector;
	 
	void InitShipList(); // 가져온 배들을 초기화
	void Placement();	 // 맵에 배를 배치 각 배에다가 map 좌표값을 넣어줌.
	void Attack();		//공격
	void PrintShipVector();
};

