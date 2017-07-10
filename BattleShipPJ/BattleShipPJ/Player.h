#pragma once
#include "Board.h"
#include "Ship.h"
#include <list>

class CPlayer
{
public:
	CPlayer();
	virtual ~CPlayer();

	CBoard playerBoard;
	CBoard enemyBoard;

	std::list<CShip> shipList;	//7�� �� ������
	 
	void InitShipList(); // ������ ����� �ʱ�ȭ
	void Placement();	 // �ʿ� �踦 ��ġ �� �迡�ٰ� map ��ǥ���� �־���.
	void Attack();		//���� 
};

