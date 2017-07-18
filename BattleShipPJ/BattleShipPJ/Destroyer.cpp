#include "stdafx.h"
#include "Destroyer.h"
#include <string>


CDestroyer::CDestroyer()
{
	m_ShipSize = 2;
	m_DurabilitySize = m_ShipSize;
	m_Name = "Destroyer";
	m_ShipType = DESTROYER;
}


CDestroyer::~CDestroyer()
{
}

EHitState CDestroyer::HitCheck(Position hitPosition)
{
	EHitState hitstate = CShip::HitCheck(hitPosition);

	if (hitstate == HIT_DESTROY)
		return HIT_DESTROY_DESTROYER;
	return hitstate;
}
	
