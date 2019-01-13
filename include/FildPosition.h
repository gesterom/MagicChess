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
	int getIDonBoard(){
		return x+y*BORDWIGHT;
	}
};
