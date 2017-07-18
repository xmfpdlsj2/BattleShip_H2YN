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
	Position attackPosition;
	EHitState hitstate;
	int turnCount = 0;

	m_Defender.PlaceShip();

	while (m_Defender.GameEndCheck())
	{
		attackPosition = m_Attacker.Attack();
		hitstate = m_Defender.DeffendHitCheck(attackPosition);
		m_Attacker.OnHitResult(hitstate);

		turnCount++;
		printf_s("trun: %d, HitPosition: %c : %c, HitResult : %d\n", turnCount, (char)attackPosition.x, (char)attackPosition.y,hitstate);
	}
		
	

}
