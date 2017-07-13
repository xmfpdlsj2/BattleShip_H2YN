#include "Player.h"
#include "AircraftCarrier.h"
#include "BattleShip.h"
#include "Cruiser.h"
#include "Destroyer.h"
#include "Submarine.h"
#include <time.h>
#include "Position.h"

CPlayer::CPlayer()
{
	pShipVector.push_back(new CAircraftCarrier());
	pShipVector.push_back(new CBattleShip());
	pShipVector.push_back(new CCruiser());
	pShipVector.push_back(new CDestroyer());
	pShipVector.push_back(new CDestroyer());
}


CPlayer::~CPlayer()
{
	for (auto pVar : pShipVector)
	{
		delete pVar;
	}
}

void CPlayer::PlaceShip()
{
	srand((unsigned)time(NULL));
	bool northPossible = true, southPossible = true, westPossible = true, eastPossible = true;

	for (auto pShip : pShipVector)
	{
		for (auto i = 0; i < pShip->GetDurabilitySize(); i++)
		{
			int x = rand() % 8;
			int y = rand() % 8;
			Position position;
			position.x = (char)(x + 'A');
			position.y = (char)(y + '0');
			if (i == 0)
			{
				if (m_PlayerBoard.GetMapPosition(x,y) == NONE)
				{
					for (auto i = 0; i < pShip->GetDurabilitySize(); i++)
					{
						if (m_PlayerBoard.GetMapPosition(x, y) && eastPossible)
						{

						}
						if (m_PlayerBoard.GetMapPosition(x, y) && westPossible)
						{

						}
						if (m_PlayerBoard.GetMapPosition(x, y) && southPossible)
						{

						}
						if (m_PlayerBoard.GetMapPosition(x, y) && northPossible)
						{

						}
					}
				}
				

			}
		}

		pShip;
	}
}

void CPlayer::PrintShipVector()
{
	for (int i = 0; i < (int)pShipVector.size(); i++)
	{
		pShipVector[i]->PrintTest();
	}
}

bool CPlayer::_CheckPossiblePosition(CShip * pShip, Position position)
{
	int x = (int)(position.x - 'A');
	int y = (int)(position.y - '0');

	if (m_PlayerBoard.GetMapPosition(x, y) != NONE) // 가져온 좌표 가능한지 안한지
	{
		return false;
	}

	if (pShip->GetShipPosition().empty()) // 배에 하나도 포지션 넣지 않았을 경우
	{
		bool westPossible = true, eastPossible = true;
		int count = 1; // 가져온 좌표는 가능하니까

		for (auto i = 0; i < pShip->GetDurabilitySize(); i++) // 가로로 가능한 칸 확보가 가능한지 검사
		{
			if (eastPossible && (y + i) < m_PlayerBoard.GetMapSize() && m_PlayerBoard.GetMapPosition(x, y + i) == NONE)
			{
				++count;
			}
			else
			{
				eastPossible = false;
			}

			if (westPossible && (y - i) >= 0 && m_PlayerBoard.GetMapPosition(x, y - i) == NONE)
			{
				++count;
			}
			else
			{
				westPossible = false;
			}

			if (count == pShip->GetDurabilitySize())
				return true;
		}

		bool northPossible = true, southPossible = true;
		count = 1;

		for (auto i = 0; i < pShip->GetDurabilitySize(); i++) // 세로로 가능한 칸 확보가 가능한지 검사
		{
			if (eastPossible && (x + i) < m_PlayerBoard.GetMapSize() && m_PlayerBoard.GetMapPosition(x + i, y) == NONE)
			{
				++count;
			}
			else
			{
				eastPossible = false;
			}

			if (westPossible && (x - i) >= 0 && m_PlayerBoard.GetMapPosition(x - i, y) == NONE)
			{
				++count;
			}
			else
			{
				westPossible = false;
			}

			if (count == pShip->GetDurabilitySize())
				return true;
		}
		return false; // 가로 세로 둘 다 안될 때
	}
	else
	{
		if (pShip->GetShipPosition().size() == 1) // 배에 포지션 하나 저장되어 있을 경우
		{

		}
		else
		{

		}
	}

	return false;
}
