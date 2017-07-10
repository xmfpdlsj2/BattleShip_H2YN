#pragma once
#include <string>

class CShip
{
public:
	CShip();
	virtual ~CShip();
	std::string name;
	
	int durabilitySize;		//배의 내구도
	int* shipPosition;		//배의 배치된 좌표 ->생성자에서 각 배마다의 크기로 초기화

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

