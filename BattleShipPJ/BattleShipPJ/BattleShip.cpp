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

//Many people are deciding their lunch menu after they are looking at the menu board.

//After���ӻ�� ������ �ǹ��մϴ�. �׷��� after ������ ������������ ���� ���� �����ϴ�.

//


