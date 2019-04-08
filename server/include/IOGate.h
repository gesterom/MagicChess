#pragma once
#include "Output.h"
//#include "GameServer.h"
#include <iostream>

class IOGate : public Output {
	std::istream& in = std::cin;
	std::ostream& out = std::cout;
	//GameServer& game;
  public:
	IOGate( std::istream& in, std::ostream& out );
	virtual void sendFields( std::vector<ID::Entity::Field> ) override;
	virtual void sendPawns( std::vector<ID::Entity::Pawn> ) override;
	virtual void send( std::string ) override;
	void run();
	virtual ~IOGate();
};
