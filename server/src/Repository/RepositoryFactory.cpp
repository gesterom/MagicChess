#include "Repository/RepositoryFactory.h"
#include "Config.h"
#include "Repository/Board.h"

RepositoryFactory::RepositoryFactory( const Config& config ) {
	this->_board = new Repository::Board();
}

const Repository::IBoard* RepositoryFactory::board() const {
	return this->_board;
}
Repository::IBoard* RepositoryFactory::board() {
	return this->_board;
}
