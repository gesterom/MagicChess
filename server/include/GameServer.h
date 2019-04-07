#pragma once
#include "Config.h"
#include "Repository/IRepositoryFactory.h"
#include "interface.h" // FIXME remove it too much dependency 

class Config;

class GameServer {
	int hight, wight;
	Repository::IBoard* repoBoard;
  public:
	GameServer( const Config& config, const IRepositoryFactory& repo );
	void run();
	~GameServer();
};
