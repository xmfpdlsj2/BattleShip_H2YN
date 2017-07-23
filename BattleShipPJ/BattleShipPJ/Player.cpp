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
	static Position attackPosition;
	Position temp;
	EHitState fireCheck = HIT_NONE;
	EChaseCase CurrentChaseCase = SEEK;
	CurrentChaseCase = chaseCase;
	
	static int chaseDir;
	//std::cout << "chaseDir : " << chaseDir << std::endl;

	switch (chaseCase)
	{
	case SEEK:
		break;
	case FIRST_HIT:
		attackPosition = position;
				
		//break;
	case CHASE_SEEK:
		for (int i = 0; i < DIR_NONE_MAX; i++)
		{
			temp = attackPosition + DIR_ARRAY[i];
			if (temp.x <= '8' && temp.y <= 'H'
				&& temp.x >= '1' && temp.y >= 'A')
			{
				fireCheck = m_PlayerHitCheckBoard.GetMapHitState(temp.x, temp.y);

				if (fireCheck == HIT_NONE)
				{
					chaseDir = i;
					return temp;
				}
			}
		}
		break;
	case CHASE_DESTROY:
		temp = position + DIR_ARRAY[chaseDir];
		if (temp.x <= '8' && temp.y <= 'H'
			&& temp.x >= '1' && temp.y >= 'A')
		{
			fireCheck = m_PlayerHitCheckBoard.GetMapHitState(temp.x, temp.y);
			if (fireCheck == HIT_NONE)
			{
				return temp;
			}
		}
		else
		{
			switch ((EDirection)chaseDir)
			{
			case DIR_RIGHT:
				chaseDir = DIR_LEFT;
				break;
			case DIR_LEFT:
				chaseDir = DIR_RIGHT;
				break;
			case DIR_UP:
				chaseDir = DIR_DOWN;
				break;
			case DIR_DOWN:
				chaseDir = DIR_UP;
				break;
			default:
				break;
			}
			temp = attackPosition + DIR_ARRAY[chaseDir];
			return temp;
		}
		break;
	default:
		break;
	}

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
	EChaseCase currentChaseCase = SEEK;
	currentChaseCase = chaseCase;

	switch (hitState)
	{
	case HIT_NONE:
		break;
	case HIT_MISS:
		if (currentChaseCase == FIRST_HIT)
		{
			currentChaseCase = CHASE_SEEK;
		}
		else if (currentChaseCase == CHASE_DESTROY)
		{
			currentChaseCase = CHASE_SEEK;
		}
		break;
	case HIT_HIT:
		if (currentChaseCase == SEEK)
		{
			currentChaseCase = FIRST_HIT;
		}
		else if (currentChaseCase == FIRST_HIT || currentChaseCase == CHASE_SEEK)
		{
			currentChaseCase = CHASE_DESTROY;
		}
		break;
	case HIT_DESTROY:
		currentChaseCase = SEEK;
		break;
	case HIT_DESTROY_AIRCRAFT_CARRIER:
		currentChaseCase = SEEK;
		break;
	case HIT_DESTROY_BATTLESHIP:
		currentChaseCase = SEEK;
		break;
	case HIT_DESTROY_CRUISER:
		currentChaseCase = SEEK;
		break;
	case HIT_DESTROY_DESTROYER:
		currentChaseCase = SEEK;
		break;
	case HIT_DESTROY_SUBMARINE:
		currentChaseCase = SEEK;
		break;
	default:
		break;
	}
	return currentChaseCase;
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