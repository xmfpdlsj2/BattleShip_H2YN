#include "stdafx.h"
#include "BattleShip.h"
#include <string>


CBattleShip::CBattleShip()
{
	m_ShipSize = 4;
	m_DurabilitySize = m_ShipSize;
	m_Name = "Battle Ship";
	m_ShipType = BATTLESHIP;
}


CBattleShip::~CBattleShip()
{

}

void CBattleShip::PrintTest()
{
	std::cout << "BattleShip" << std::endl;
}

EHitState CBattleShip::HitCheck(Position hitPosition)
{
	EHitState hitstate = CShip::HitCheck(hitPosition);

	if (hitstate == HIT_DESTROY)
		return HIT_DESTROY_BATTLESHIP;
	return hitstate;
}

//Many people are deciding their lunch menu after they are looking at the menu board.

//After���ӻ�� ������ �ǹ��մϴ�. �׷��� after ������ ������������ ���� ���� �����ϴ�.

//


