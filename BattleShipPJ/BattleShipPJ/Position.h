#pragma once
#include"Enums.h"
struct Position
{
	char x; // 숫자
	char y; // 영어

	Position();
	Position(char xpos, char ypos);
	virtual ~Position();

	Position operator+(Position direction)
	{
		return Position(x + direction.x, y + direction.y);
	}

	Position operator*(int rhs)
	{
		return Position((char)(x*rhs), (char)(y*rhs));
	}		

};

	static Position DIR_ARRAY[DIR_NONE_MAX] = {Position(1,0),
										Position(-1,0),
										Position(0,-1),
										Position(0,1)};
