#include "stdafx.h"
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

Position CPlayer::GetAttackPosition(Position position,EHitState hitState,EChaseCase chaseCase)
{
	Position attackPosition;
	Position temp;
	EHitState fireCheck = HIT_NONE;
	EChaseCase CurrentChaseCase = SEEK;
	CurrentChaseCase = chaseCase;
	

	switch (chaseCase)
	{
	case SEEK:
		break;
	case FIRST_HIT:
		attackPosition = position;

		for (int i = 0; i < DIR_NONE_MAX; i++)
		{
			temp = attackPosition + DIR_ARRAY[i];
			if (attackPosition.x <= '8' && attackPosition.y <= 'H' && attackPosition.x > '1' && attackPosition.y > 'A')
			{
				fireCheck = m_PlayerHitCheckBoard.GetMapHitState(attackPosition.x, attackPosition.y);

				if (fireCheck == HIT_NONE)
					return attackPosition;
			}
		}
		break;
	case CHASE_SEEK:
		break;
	case CHASE_DESTROY:
		break;
	default:
		break;
	}
	/*if (hitState == HIT_HIT)
	{
		attackPosition = position;

		for (int i = 0; i < DIR_NONE_MAX; i++)
		{
			attackPosition = attackPosition + DIR_ARRAY[i];
			if (attackPosition.x <= '8' && attackPosition.y <= 'H' && attackPosition.x > '1' && attackPosition.y > 'A')
			{
				fireCheck = m_PlayerHitCheckBoard.GetMapHitState(attackPosition.x, attackPosition.y);

				if (fireCheck == HIT_NONE)
					return attackPosition;
			}
			
		}		

	}*/

	attackPosition.x = rand() % 8 + '1';
	attackPosition.y = rand() % 8 + 'A';

	fireCheck = m_PlayerHitCheckBoard.GetMapHitState(attackPosition.x, attackPosition.y);
	
	if (fireCheck == HIT_NONE)
	{		
		return attackPosition;
	}
		
	return GetAttackPosition(position, hitState, chaseCase);
}

EChaseCase CPlayer::SelectChaseCase(EHitState hitState, EChaseCase chaseCase)
{
	EChaseCase CurrentChaseCase = SEEK;
	CurrentChaseCase = chaseCase;

	switch (hitState)
	{
	case HIT_NONE:
		break;
	case HIT_MISS:
		if (CurrentChaseCase == FIRST_HIT)
		{
			CurrentChaseCase = FIRST_HIT;
		}
		break;
	case HIT_HIT:
		if (CurrentChaseCase == SEEK)
		{
			CurrentChaseCase = FIRST_HIT;
		}
		else if (CurrentChaseCase == FIRST_HIT)
		{
			CurrentChaseCase = CHASE_SEEK;
		}
		break;
	case HIT_DESTROY:
		CurrentChaseCase = SEEK;
		break;
	case HIT_DESTROY_AIRCRAFT_CARRIER:
		CurrentChaseCase = SEEK;
		break;
	case HIT_DESTROY_BATTLESHIP:
		CurrentChaseCase = SEEK;
		break;
	case HIT_DESTROY_CRUISER:
		CurrentChaseCase = SEEK;
		break;
	case HIT_DESTROY_DESTROYER:
		CurrentChaseCase = SEEK;
		break;
	case HIT_DESTROY_SUBMARINE:
		CurrentChaseCase = SEEK;
		break;
	default:
		break;
	}
	return chaseCase;
}

EHitState CPlayer::OnHitResult(Position position, EHitState hitResult)
{

	m_PlayerHitCheckBoard.SetMapHitState(position.x, position.y,hitResult);	

	return hitResult;
}

EHitState CPlayer::DeffendHitCheck(Position hitposition)
{
	EHitState hitState;

	for (auto pShip : pShipVector)
	{
		hitState = pShip->HitCheck(hitposition);
		if (hitState != HIT_MISS)
			return hitState;
	}

	return HIT_MISS;

}


bool CPlayer::GameEndCheck()
{
	for (auto pShip : pShipVector)
	{
		if (pShip->GetDurabilitySize() != 0)
			return true;
	}
	
	return false;	
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
				pShip->SetShipPosition(temp);
				if (j == pShip->GetDurabilitySize() - 1)
					return;
			}
		}
		
	}
	
}