#include "stdafx.h"
#include "AircraftCarrier.h"
#include <string>


CAircraftCarrier::CAircraftCarrier()
{
	m_ShipSize = 5;
	m_DurabilitySize = m_ShipSize;
	m_Name = "Aircraft Carrier";
	m_ShipType = AIRCRAFT_CARRIER;
}


CAircraftCarrier::~CAircraftCarrier()
{
}

void CAircraftCarrier::PrintTest()
{
	std::cout << "AircraftCarrier" << std::endl;
}

EHitState CAircraftCarrier::HitCheck(Position hitPosition)
{
	EHitState hitstate = CShip::HitCheck(hitPosition);

	if (hitstate == HIT_DESTROY)
		return HIT_DESTROY_AIRCRAFT_CARRIER;
	return hitstate;
}


