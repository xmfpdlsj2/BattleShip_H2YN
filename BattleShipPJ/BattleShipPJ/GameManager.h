#pragma once
#include "Player.h"
#include "Position.h"

class CGameManager
{
public:
	CGameManager();
	virtual ~CGameManager();

	void Init();
	void Start();

protected:
	CPlayer m_Attacker;
	CPlayer m_Defender;

};

