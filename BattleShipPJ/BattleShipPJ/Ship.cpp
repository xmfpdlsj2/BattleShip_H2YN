#include "stdafx.h"
#include "Ship.h"


CShip::CShip()
{

}


CShip::~CShip()
{

}

EHitState CShip::HitCheck(Position hitPosition)
{
	for (auto it = m_ShipPosition.begin(); it != m_ShipPosition.end(); it++)
	{
		if (hitPosition.x == it->x && hitPosition.y == it->y)
		{
			--m_DurabilitySize;
			m_ShipPosition.erase(it);

			if (m_DurabilitySize == 0)
			{
				return HIT_DESTROY;
				// TODO : ��Ʈ���� ������ �˾Ƽ� �� Ÿ�� �����ͼ� �� ��Ʈ���� ��ȯ
			}
			else
				return HIT_HIT;
		}
	}
	return HIT_MISS;
}

void CShip::AddPosition(Position position)
{
	//���� ��ġ�� �ִ��� ����ó�� �߰�
	for (int i = 0; i < (int)m_ShipPosition.size(); i++)
	{
		if (m_ShipPosition[i].x == position.x && m_ShipPosition[i].y == position.y)
		{
			std::cout << "x: " << position.x << "y: " << position.y << "already exist" << std::endl;
		}
	}

	m_ShipPosition.push_back(position);

}

void CShip::PrintShipPosition()
{
	for (int i = 0; i < (int)m_ShipPosition.size(); i++)
	{
		printf("%s Position[%d] - %c%c\n", m_Name.c_str(), i, m_ShipPosition[i].x, m_ShipPosition[i].y);
	}
}

void CShip::PrintTest()
{
	std::cout << "Ship" << std::endl;
}

std::vector<Position> CShip::SetShipPosition(Position position)
{
	m_ShipPosition.push_back(position);
	return std::vector<Position>();
}
