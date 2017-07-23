#pragma once
#include "Board.h"
#include <vector>

//Ŭ���� ���漱��
class CShip;
struct Position;

class CPlayer
{
public:
	CPlayer();
	virtual ~CPlayer();

	std::vector<CShip*> pShipVector;
	 
	void PlaceShip();	 // �ʿ� �踦 ��ġ �� �迡�ٰ� map ��ǥ���� �־���.
	Position GetAttackPosition(Position position, EHitState hitState, EChaseCase chaseCase);		//����
	EChaseCase SelectChaseCase(EHitState hitState, EChaseCase chaseCase);
	EHitState OnHitResult(Position position,EHitState hitresult);

	EHitState DefendHitCheck(Position hitposition);

	bool GameEndCheck();
	void PrintShipVector();

	CBoard GetPlayerBoard() { return m_PlayerBoard; }
	CBoard GetEnemyBoard() { return m_EnemyBoard; }

protected:
	CBoard m_PlayerBoard;
	CBoard m_PlayerHitCheckBoard;
	CBoard m_EnemyBoard;

	void _InsertPosition(CShip* pShip);

};

