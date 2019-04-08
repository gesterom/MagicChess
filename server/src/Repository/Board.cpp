#include "Repository/Board.h"

//Repository::Board::Board( std::vector<DAO::Field*>& board ) : board( board ) {}

Repository::Board::Board() {
	//FIXME add config
	for( unsigned int i = 0 ; i < 16 ; i++ ) {
		for( unsigned int j = 0 ; j < 16 ; j++ ) {
			this->board.push_back( {i * 16 + j, 0} );
		}
	}
}

std::vector<ID::Entity::Field> Repository::Board::getFields() const {
	std::vector<ID::Entity::Field> res;

	for( auto i : this->board ) {
		res.push_back( i.id );
	}

	return res;
}

Result<ID::Entity::Pawn> Repository::Board::getPawnID( ID::Entity::Field field ) const {
	for( auto i : board ) {
		if( i.id == field ) {
			if( i.pawn != 0 ) {
				return  Result<ID::Entity::Pawn>( i.pawn );
			}
			else {
				return Result<ID::Entity::Pawn>( true );
			}
		}
	}

	return Result<ID::Entity::Pawn>( true );
}
