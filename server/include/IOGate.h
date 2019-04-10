#pragma once
#include "GameServer.h"
#include <iostream>
#include "Repository/RepositoryFactory.h"
#include "Repository/IBoard.h"

class IOGate  {
	std::istream& in;
	std::ostream& out;
	GameServer& game;
	const Repository::IBoard* repoBoard;
  public:
	IOGate( const RepositoryFactory& repoFactory /*, */, GameServer& gameServer, std::istream& in = std::cin, std::ostream& out = std::cout );
	void run();
	virtual ~IOGate();
};
