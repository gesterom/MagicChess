#include "Repository/Board.h"

//Repository::Board::Board( std::vector<DAO::Field*>& board ) : board( board ) {}
#include <iostream>

Repository::Board::Board() {
	std::cout << "Board[" << std::hex << this << std::dec << "]\n";

	//FIXME add config
	for( unsigned int i = 0 ; i < 16 ; i++ ) {
		for( unsigned int j = 0 ; j < 16 ; j++ ) {
			this->board[i * 16 + j] = {i * 16 + j, 0};
		}
	}
}
bool Repository::Board::spawnPawn( ID::Entity::Field field, ID::Entity::Pawn pawn ) { //FIXME
	board[field].pawn = pawn;
	return true;
}
std::vector<ID::Entity::Field> Repository::Board::getFields() const {
	std::vector<ID::Entity::Field> res;

	for( auto& [key, value] : this->board ) {
		res.push_back( key );
	}

	return res;
}

Result<ID::Entity::Pawn> Repository::Board::getPawnID( ID::Entity::Field field ) const {

	try {
		if( board.at( field ).pawn != 0 ) {
			return Result<ID::Entity::Pawn>( board.at( field ).pawn );
		}
		else {
			return Result<ID::Entity::Pawn>( true );
		}
	}
	catch( ... ) {
		return Result<ID::Entity::Pawn>( true );
	}
}

bool Repository::Board::movePawn( ID::Entity::Field from, ID::Entity::Field to){
	try{
		auto& _from = board.at(from);
		auto& _to = board.at(to);
	
		_to.pawn = _from.pawn;	
		_from.pawn=0;
		return false;
	}
	catch(...)
	{
		std::cerr<<"board move Pawn"<<"\n"; //TODO add loger
		return true;
	}


	return true;
}
