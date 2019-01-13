#pragma once

#include <array>
#include "constans.h"
#include "FildPosition.h"
#include "IPawn.h"
#include "Fild.h"

class DamageRasualt;

class AttackResualt
{
	bool x;
	public:
	AttackResualt( bool aa ) {
	this->x = aa;	
	}
};

using MoveResualt = bool;

class Board 
{
	std::array<Fild,BORDHIGHT * BORDWIGHT> board;
	public:
	AttackResualt attack(FildPosition attacer,FildPosition defender);
	MoveResualt move(FildPosition from,FildPosition to);
	Board();
};
