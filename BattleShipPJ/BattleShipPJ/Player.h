#pragma once
#include "Board.h"
#include <vector>

//클래스 전방선언
class CShip;
class Position;

class CPlayer
{
public:
	CPlayer();
	virtual ~CPlayer();

	std::vector<CShip*> pShipVector;
	 
	void InitShipList(); // 가져온 배들을 초기화
	void PlaceShip();	 // 맵에 배를 배치 각 배에다가 map 좌표값을 넣어줌.
	void Attack();		//공격
	void PrintShipVector();

	CBoard GetPlayerBoard() { return m_PlayerBoard; }
	CBoard GetEnemyBoard() { return m_EnemyBoard; }

protected:
	CBoard m_PlayerBoard;
	CBoard m_EnemyBoard;

	bool _CheckPossiblePosition(CShip* pShip, Position position);
	bool _CheckPossibleLine(Position checkPosition, int shipSize, ELineType lineType);
};

