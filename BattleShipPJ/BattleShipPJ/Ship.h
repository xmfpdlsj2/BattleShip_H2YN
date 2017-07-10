#pragma once
#include <string>

class CShip
{
public:
	CShip();
	virtual ~CShip();
	std::string name;
	
	int durabilitySize;		//���� ������
	int* shipPosition;		//���� ��ġ�� ��ǥ ->�����ڿ��� �� �踶���� ũ��� �ʱ�ȭ

	enum EShipType
	{
		AIRCRAFT_CARRIER,
		BATTLESHIP,
		CRUISER,
		DESTROYER,
		SUBMIRINE,
	};

	EShipType shipType;

protected:
	int shipSize;
};

