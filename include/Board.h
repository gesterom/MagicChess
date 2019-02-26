#pragma once

#include <array>
#include "constans.h"
#include "IBoard.h"
#include "IDrawable.h"
#include "Fild.h"

class DamageRasualt;
class FildPosition;

class Board : public IBoard, public IDrawable
{
	std::array<Fild,BORDHIGHT * BORDWIGHT> board;
	public:
	virtual std::string image() override ;
	virtual AttackResualt attack(FildPosition attacer,FildPosition defender) override;
	virtual MoveResualt move(FildPosition from,FildPosition to) override;
	Board();
};
