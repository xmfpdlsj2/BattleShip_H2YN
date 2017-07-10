#pragma once
#include "Player.h"

class CGameManager
{
public:
	CGameManager();
	virtual ~CGameManager();

	CPlayer player01;
	CPlayer player02;


	int playerTurn;		//플레이어턴 인지 아닌지
	bool winAprice;			//승자 체크
	void checkGameEnd();	//게임 엔드 함수
};

