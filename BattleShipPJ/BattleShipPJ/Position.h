#pragma once

struct Position
{
	char x;
	char y;

public :
	Position();
	Position(char xpos, char ypos);
	virtual ~Position();
};