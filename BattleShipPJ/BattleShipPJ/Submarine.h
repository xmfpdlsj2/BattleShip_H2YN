#pragma once
#include "Ship.h"
#include<string>

class CSubmarine :
	public CShip
{
public:
	CSubmarine();
	virtual ~CSubmarine();

	virtual EHitState HitCheck(Position hitPosition);
};

