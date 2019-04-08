#include "Repository/RepositoryFactory.h"
#include "Config.h"
#include "Repository/Board.h"

RepositoryFactory::RepositoryFactory( const Config& config ) {

}

Repository::IBoard* RepositoryFactory::board() const {
	return new Repository::Board();
}
