#include "GameServer.h"
#include "Config.h"
#include "Repository/IRepositoryFactory.h"

#include <sstream> //FIXME

struct Point {
	int x;
	int y;
};

template<>
Point Config::get<Point>( std::string key ) const {
	auto str = this->get<std::string>( key );
	std::stringstream ss( str );
	getline( ss, str, ',' );
	Point res;
	res.x = atoi( str.c_str() );
	getline( ss, str );
	res.y = atoi( str.c_str() );
	return res;
}

#include <iostream>

GameServer::GameServer( const Config& config, IRepositoryFactory& repoFactory ) {
	this->hight = config.get<int>( "hight" );
	this->wight = config.get<int>( "wight" );

	Point PlayerW = config.get<Point>( "PlayerW" );
	Point PlayerB = config.get<Point>( "PlayerB" );

	this->repoBoard = repoFactory.board();


	//INIT GAME STATE
	repoBoard->spawnPawn( PlayerW.y * this->wight + PlayerW.x, 1 );
	repoBoard->spawnPawn( PlayerB.y * this->wight + PlayerB.x, 2 );
}

GameServer::~GameServer() {
}

