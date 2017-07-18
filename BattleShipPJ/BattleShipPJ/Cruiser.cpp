#include "stdafx.h"
#include "Cruiser.h"
#include <string>


CCruiser::CCruiser()
{
	m_ShipSize = 3;
	m_DurabilitySize = m_ShipSize;
	m_Name = "Cruiser";
	m_ShipType = CRUISER;
}


CCruiser::~CCruiser()
{
}

EHitState CCruiser::HitCheck(Position hitPosition)
{
	EHitState hitstate = CShip::HitCheck(hitPosition);

	if (hitstate == HIT_DESTROY)
		return HIT_DESTROY_CRUISER;
	return hitstate;
}
