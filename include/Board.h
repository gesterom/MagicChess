#include <array>


const int BORDHIGHT = 16;
const int BORDWIGHT = 16;

using AttacResualt = bool;
using MoveResualt = bool;
using Fild=int;

using FildPosition = std::pair<int,int>;

class Board 
{
	std::array<Fild,BORDHIGHT * BORDWIGHT> board;
	public:
	AttacResualt attac(FildPosition attacer,FildPosition defender);
	MoveResualt move(FildPosition from,FildPosition to);
	Board();
};
