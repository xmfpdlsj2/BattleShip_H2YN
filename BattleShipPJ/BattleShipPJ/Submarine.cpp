#include "stdafx.h"
#include "Submarine.h"
#include<string>


CSubmarine::CSubmarine()
{
	m_ShipSize = 1;
	m_DurabilitySize = m_ShipSize;
	m_Name = "Submarine";
	m_ShipType = SUBMARINE;
}


CSubmarine::~CSubmarine()
{
}

EHitState CSubmarine::HitCheck(Position hitPosition)
{
	EHitState hitstate = CShip::HitCheck(hitPosition);

	if (hitstate == HIT_DESTROY)
		return HIT_DESTROY_DESTROYER;
	return hitstate;
}
