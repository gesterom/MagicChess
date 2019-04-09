#include <iostream>
#include "Config.h"
#include "Repository/RepositoryFactory.h"
#include "GameServer.h"
#include "IOGate.h"

int main( int argc, char** args ) {
	if( argc < 2 ) {
		std::cerr << "usage :" << args[0] << " [configfile]" << std::endl;
		return -1;
	}

	Config config( args[1] );
	RepositoryFactory repositoryFactory( config );
	// IOGate gate;
	GameServer gameServer( config, repositoryFactory );

	IOGate gate( repositoryFactory, gameServer );
	gate.run();
	std::cout << "Sever Close" << std::endl;
}
