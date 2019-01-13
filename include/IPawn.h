#pragma once

#include <vector>

class Fild;
class FildPosition;
class Damage
{
	int x;
	public:
	Damage() : x(0){}
 	int get(){return x;}	
};

class DamageRasualt
{

};

using Filds=std::vector<Fild>;

class IPawn
{
	public:
	virtual Damage attack(FildPosition me,FildPosition target) = 0;
	virtual DamageRasualt damage(Damage damage, FildPosition from) = 0;
	virtual Filds posibelMoves(FildPosition) = 0;
	virtual Filds posibleAttacks(FildPosition) = 0;
	virtual ~IPawn(){}
};
