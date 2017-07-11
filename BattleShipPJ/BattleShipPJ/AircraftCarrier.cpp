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
