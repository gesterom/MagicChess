#include <vector>

class Fild;
class FildPosition;
class Damage;

class DamageRasualt;

using Filds=std::vector<Fild>;

class IPawn
{
	public:
	virtual Damage attac(FildPosition) = 0;
	virtual DamageRasualt damage(Damage) = 0;
	virtual Filds posibelMoves(FildPosition) = 0;
	virtual Filds posibleAttacs(FildPosition) = 0;
	virtual ~IPawn(){}
};
