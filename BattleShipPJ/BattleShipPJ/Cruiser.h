#pragma once
#include "Ship.h"
class CCruiser :
	public CShip
{
public:
	CCruiser();
	virtual ~CCruiser();

	virtual EHitState HitCheck(Position hitPosition);
};

