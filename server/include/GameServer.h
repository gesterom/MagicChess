#pragma once
#include "Config.h"
#include "Repository/IRepositoryFactory.h"
#include "interface.h" // FIXME remove it too much dependency 
#include "Output.h"


class GameServer {
	int hight, wight;
	Repository::IBoard* repoBoard;
	// Output& out;
  public:
	GameServer( const Config& config, const IRepositoryFactory& repo );
	void run();
	~GameServer();
};
