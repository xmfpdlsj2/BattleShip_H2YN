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
	srand(time(NULL));
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
