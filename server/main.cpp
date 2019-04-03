#include <iostream>
#include "Config.h"
#include "Repository/RepositoryFactory.h"
#include "GameServer.h"

int main(int argc,char** args)
{
	if(argc < 2 ) {
		std::cerr<<"usage :"<<args[0]<<" [configfile]"<<std::endl;
		return -1;
	}
	Config config(args[1]);
	RepositoryFactory repositoryFactory(config);
	GameServer gameServer(config,repositoryFactory);
	gameServer.run();
	std::cout<<"Sever Close"<<std::endl;
}
