#include "stdafx.h"
#include "GameManager.h"



CGameManager::CGameManager()
{
}


CGameManager::~CGameManager()
{
}

void CGameManager::Init()
{
}

void CGameManager::Start()
{
	Position attackPosition = Position (0,0);
	EHitState hitState = HIT_NONE;
	int turnCount = 0;

	m_Defender.PlaceShip();

	while (m_Defender.GameEndCheck())
	{
		attackPosition = m_Attacker.GetAttackPosition(attackPosition, hitState);
		hitState = m_Defender.DeffendHitCheck(attackPosition);
		m_Attacker.OnHitResult(attackPosition, hitState);

		turnCount++;
		printf_s("turn: %d, HitPosition: %c : %c, HitResult : %d\n", turnCount, (char)attackPosition.x, (char)attackPosition.y,hitState);
	}		
	std::cout << "last turn is " << turnCount << std::endl;
}
