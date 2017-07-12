#pragma once
#include "Board.h"
#include <vector>

//Ŭ���� ���漱��
class CShip;

class CPlayer
{
public:
	CPlayer();
	virtual ~CPlayer();

	std::vector<CShip*> pShipVector;
	 
	void InitShipList(); // ������ ����� �ʱ�ȭ
	void PlaceShip();	 // �ʿ� �踦 ��ġ �� �迡�ٰ� map ��ǥ���� �־���.
	void Attack();		//����
	void PrintShipVector();

	CBoard GetPlayerBoard() { return m_PlayerBoard; }
	CBoard GetEnemyBoard() { return m_EnemyBoard; }

protected:
	CBoard m_PlayerBoard;
	CBoard m_EnemyBoard;
};

