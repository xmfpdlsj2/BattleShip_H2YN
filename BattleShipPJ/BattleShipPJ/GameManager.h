#pragma once
#include "Player.h"

class CGameManager
{
public:
	CGameManager();
	virtual ~CGameManager();

	CPlayer player01;
	CPlayer player02;


	int playerTurn;		//�÷��̾��� ���� �ƴ���
	bool winAprice;			//���� üũ
	void checkGameEnd();	//���� ���� �Լ�
};

