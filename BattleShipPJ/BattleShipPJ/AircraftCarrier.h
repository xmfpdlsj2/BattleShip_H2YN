#pragma once
#include "Ship.h"
class CAircraftCarrier :
	public CShip
{
public:
	CAircraftCarrier();
	virtual ~CAircraftCarrier();
	
	virtual void PrintTest();
	virtual EHitState HitCheck(Position hitPosition);
};

