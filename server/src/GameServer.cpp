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

	std::cout << "Wx : " << PlayerW.x << " y: " << PlayerW.y << "\n";
	std::cout << "Bx : " << PlayerB.x << " y: " << PlayerB.y << "\n";

	//INIT GAME STATE
	if( repoBoard->spawnPawn( PlayerW.y * this->wight + PlayerW.x, 1 ) ) {
		std::cout << "error" << std::endl;
	}//<<std::endl;;

	std::cout << ( repoBoard->spawnPawn( PlayerB.y * this->wight + PlayerB.x, 2 ) ) << std::endl;;
	
	std::cout<<"Board - "<<std::hex<<repoBoard<<std::dec<<std::endl;
}

GameServer::~GameServer() {
}

