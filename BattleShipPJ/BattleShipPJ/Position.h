#pragma once

struct Position
{
	char x; // 숫자
	char y; // 영어

public :
	Position();
	Position(char xpos, char ypos);
	virtual ~Position();
};