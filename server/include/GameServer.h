#pragma once
#include "Config.h"

class Config;
class IRepositoryFactory;

class GameServer
{
	public:
		GameServer(const Config& config, IRepositoryFactory repo);
		void run();
};
