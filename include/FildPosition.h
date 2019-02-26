#pragma once

#include "constans.h"

class FildPosition
{
	int x ,y;
	public:
	FildPosition(int x, int y){
		this->x = x;
		this->y = y;
	}
	int getX() const {return this->x;}
	int geyY() const {return this->y;}
	int getIDonBoard() const {
		return x+y*BORDWIGHT;
	}
};
