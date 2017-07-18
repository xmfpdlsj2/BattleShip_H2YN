#pragma once
#include "Ship.h"
class CBattleShip :
	public CShip
{
public:
	CBattleShip();
	virtual ~CBattleShip();
	
	virtual void PrintTest();
	virtual EHitState HitCheck(Position hitPosition);
};

