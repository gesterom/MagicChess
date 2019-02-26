#include "Board.h"
#include "AttackResualt.h"
#include "Damage.h"
#include "FildPosition.h"
#include "Fild.h"

#include "DamageRasualt.h"
#include "MoveResualt.h"

Board::Board(){

}
AttackResualt Board::attack(FildPosition attacker,FildPosition defender)
{
	if(board[attacker.getIDonBoard()].havePawn() and board[defender.getIDonBoard()].havePawn())
	{
		auto& a = board[attacker.getIDonBoard()].getPawn();
		auto& d = board[defender.getIDonBoard()].getPawn();
		d.damage(a.attack(attacker, defender),attacker);
		return true;
	}
	return false;
}
MoveResualt Board::move(FildPosition from, FildPosition to)
{
	return MoveResualt();
}
std::string Board::image() {
	std::string res;
	for(int i = 0;i<BORDHIGHT;i++)
	{
		for(int j = 0;j<BORDHIGHT;j++)
		{
			res+=(board[i+BORDHIGHT*j].havePawn() ? 'x': ' '); 
		}
		res+='\n';
	}
	return res;	
}
