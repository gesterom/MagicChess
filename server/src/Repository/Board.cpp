#include "Repository/Board.h"

Repository::Board::Board( std::vector<DAO::Field*>& board ) : board( board ) {}

Result<ID::Entity::Pawn> Repository::Board::getPawnID( ID::Entity::Field field ) const {
	for( auto i : board ) {
		if( i->id == field ) {
			if( i->pawn != 0 ) {
				return  Result<ID::Entity::Pawn>( i->pawn );
			}
			else {
				return Result<ID::Entity::Pawn>( true );
			}
		}
	}

	return Result<ID::Entity::Pawn>( true );
}
