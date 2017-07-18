#pragma once
#include "Ship.h"
class CDestroyer :
	public CShip
{
public:
	CDestroyer();
	virtual ~CDestroyer();

	virtual EHitState HitCheck(Position hitPosition);
};

