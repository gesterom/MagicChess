#include "Board.h"

Board::Board(){}
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
