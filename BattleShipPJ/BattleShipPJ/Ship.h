#pragma once
#include <string>
#include "Enums.h"
#include "Position.h"
#include <vector>
#include <iostream>

class CShip
{
public:
	CShip();
	virtual ~CShip();

	virtual EHitState HitCheck(Position hitPosition);
	void AddPosition(Position position);

	EShipType GetShipType() { return m_ShipType; }
	int GetDurabilitySize() { return m_DurabilitySize; }
	std::vector<Position> GetShipPosition() { return m_ShipPosition; }
	std::string GetName() { return m_Name; }


protected:

	EShipType m_ShipType;
	int m_DurabilitySize;		//배의 내구도
	int m_ShipSize;
	std::vector<Position> m_ShipPosition;		//배의 배치된 좌표 ->생성자에서 각 배마다의 크기로 초기화
	std::string m_Name;
};

