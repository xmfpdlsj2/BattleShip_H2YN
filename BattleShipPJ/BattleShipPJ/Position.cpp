#include "stdafx.h"
#include "Position.h"

Position::Position() {
	x = '0';
	y = '0';
}

Position::Position(char xpos, char ypos)
{
	x = xpos;
	y = ypos;
}

Position::~Position() {

}