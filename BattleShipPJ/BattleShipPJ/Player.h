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
	 
	void InitShipList(); // ������ ����� �ʱ�ȭ
	void Placement();	 // �ʿ� �踦 ��ġ �� �迡�ٰ� map ��ǥ���� �־���.
	void Attack();		//����
	void PrintShipVector();
};

