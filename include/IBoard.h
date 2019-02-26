#pragma once

class AttackResualt;
class MoveResualt;
class FildPosition;

class IBoard 
{
	public:
	virtual AttackResualt attack(FildPosition attacer,FildPosition defender) = 0;
	virtual MoveResualt move(FildPosition from,FildPosition to) = 0;
	virtual ~IBoard(){}
};
