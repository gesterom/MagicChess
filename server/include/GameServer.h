#pragma once
#include "Config.h"
#include "Repository/IRepositoryFactory.h"
#include "Contract.h" // FIXME remove it too much dependency 

class GameServer {
	int hight, wight;
	Repository::IBoard* repoBoard;
  public:
	GameServer( const Config& config, IRepositoryFactory& repo );
	bool move(ID::Match match, ID::Entity::Player, ID::Entity::Field from,ID::Entity::Field to);
	void run();
	~GameServer();
};
