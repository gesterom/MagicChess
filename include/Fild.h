#pragma once
#include "IPawn.h"
#include <assert.h>

class Fild
{
	IPawn* pawn;
	public:
	Fild()
	{}
	bool havePawn(){
		if(pawn != nullptr) return true;
		return false;
	}
	IPawn& getPawn()
	{
		assert(pawn!=nullptr);
		return *pawn;
	}	
};
