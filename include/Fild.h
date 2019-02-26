#pragma once
#include "IPawn.h"
#include <assert.h>

class Fild
{
	IPawn* pawn = nullptr;
	public:
	Fild()
	{}
	void setPawn(IPawn* pawn)
	{
		this->pawn = pawn;
	}
	void removePawn()
	{
		pawn = nullptr;
	}
	bool havePawn() const {
		if(pawn != nullptr) return true;
		return false;
	}
	IPawn& getPawn()
	{
		assert(pawn!=nullptr);
		return *pawn;
	}	
};
