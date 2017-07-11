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
	int m_DurabilitySize;		//���� ������
	int m_ShipSize;
	std::vector<Position> m_ShipPosition;		//���� ��ġ�� ��ǥ ->�����ڿ��� �� �踶���� ũ��� �ʱ�ȭ
	std::string m_Name;
};

