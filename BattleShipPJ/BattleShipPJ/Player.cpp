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
	for (auto pShip : pShipVector)
	{
		_InsertPosition(pShip);
	}
}


void CPlayer::PrintShipVector()
{
	for (int i = 0; i < (int)pShipVector.size(); i++)
	{
		pShipVector[i]->PrintTest();
	}
}

void CPlayer::_InsertPosition(CShip * pShip)
{
	Position position;
	position.x = rand() % 8 + '1';
	position.y = rand() % 8 + 'A';

	EDirection dir = (EDirection)(rand() % DIR_NONE_MAX);
	Position temp;
	bool findPosition = true;

	for (int i = 0; i < DIR_NONE_MAX; i++)
	{
		findPosition = true;
		for (int j = 0; j < pShip->GetDurabilitySize(); j++)
		{
			temp = position + DIR_ARRAY[dir] * j;
			if (m_PlayerBoard.GetMapPosition(temp.x, temp.y) != SHIP_NONE)
			{
				findPosition = false;
				int dirInt = (int)dir;
				dir = (EDirection)((++dirInt) % DIR_NONE_MAX);
				if (i == DIR_NONE_MAX - 1)
				{
					_InsertPosition(pShip);
					return;
				}
				else
					break;
			}
		}

		if (findPosition) {
			for (int j = 0; j < pShip->GetDurabilitySize(); j++)
			{
				temp = position + DIR_ARRAY[dir] * j;
				m_PlayerBoard.SetMapPosition(temp.x, temp.y, pShip->GetShipType());
				if (j == pShip->GetDurabilitySize() - 1)
					return;
			}
		}
		
	}
	
}