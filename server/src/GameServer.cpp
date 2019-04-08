#include "GameServer.h"
#include "Config.h"
#include "Repository/IRepositoryFactory.h"

GameServer::GameServer( const Config& config, const IRepositoryFactory& repoFactory ) {
	this->hight = config.get<int>( "hight" );
	this->wight = config.get<int>( "wight" );

	this->repoBoard = repoFactory.board();

	//this->board.resize(this->hight*this->wight);
}

GameServer::~GameServer() {
	delete repoBoard;
}

