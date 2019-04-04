#include "Repository/Pawn.h"

Repository::Pawn::Pawn(std::vector<DAO::Field*>& board) : board(board) {}

Result<ID::Entity::Pawn> Repository::Pawn::getPawnID(ID::Entity::Field field) const {
	for(auto i : board)
	{
		if(i->id == field)
		{
			if(i->pawn != 0) return  Result<ID::Entity::Pawn>(i->pawn);
			else return Result<ID::Entity::Pawn>(true);
		}
	}
	return Result<ID::Entity::Pawn>(true);
}
