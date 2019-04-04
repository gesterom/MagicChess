#pragma once
#include "Config.h"

#include "interface.h" // FIXME remove it too much dependency 

class Config;
class IRepositoryFactory;

class GameServer
{
	int hight,wight;
	std::vector<ID::Entity::Fild> board;
	public:
		GameServer(const Config& config, const IRepositoryFactory& repo);
		void run();
};
