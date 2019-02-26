#pragma once

#include <vector>

class Damage;
class Fild;
class FildPosition;
class DamageRasualt;
class Filds;

class IPawn
{
	public:
	virtual Damage attack(FildPosition me,FildPosition target) = 0;
	virtual DamageRasualt damage(Damage damage, FildPosition from) = 0;
	virtual Filds posibelMoves(FildPosition) = 0;
	virtual Filds posibleAttacks(FildPosition) = 0;
	virtual ~IPawn(){}
};
