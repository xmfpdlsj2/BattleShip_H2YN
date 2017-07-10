#pragma once
class CBoard
{

	enum EState
	{
		NONE,
		MISS,
		HIT,
		AIRCRAFT_CARRIER,
		BATTLESHIP,
		CRUISER,
		DESTROYER,
		SUBMIRINE,
	};
	
public:
	CBoard();
	virtual ~CBoard();
	
	EState map[8][8] ={NONE,};		//¸Ê ¼±¾ð
	

};

