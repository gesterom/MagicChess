#pragma once

#include <string>
#include "interface.h"

class Output {
  public:
	virtual void sendFields( std::vector<ID::Entity::Field> ) = 0;
	virtual void sendPawns( std::vector<ID::Entity::Pawn> ) = 0;
	virtual void send( std::string ) = 0;
	virtual ~Output() {}
};
