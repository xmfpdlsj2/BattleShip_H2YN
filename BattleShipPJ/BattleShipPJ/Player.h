#pragma once
#include "Board.h"
#include <vector>

//클래스 전방선언
class CShip;
struct Position;

class CPlayer
{
public:
	CPlayer();
	virtual ~CPlayer();

	std::vector<CShip*> pShipVector;
	 
	void PlaceShip();	 // 맵에 배를 배치 각 배에다가 map 좌표값을 넣어줌.
	Position Attack();		//공격
	EHitState OnHitResult(EHitState hitresult);

	EHitState DeffendHitCheck(Position hitposition);

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

