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
