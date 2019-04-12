#include "IOGate.h"
#include <iostream>
#include <algorithm>

IOGate::IOGate( const RepositoryFactory& repoFactory, GameServer& gameServer, std::istream& in, std::ostream& out ) :
	in( in ),
	out( out ),
	game( gameServer ) {
	repoBoard = repoFactory.board();
	std::cout << "Board <> : " << std::hex << repoBoard << std::dec << std::endl;
}

// void printHline( int wight ) {
// 	for( int i = 0 ; i < wight * 2 + 1 ; i++ ) {
// 		if( i % 2 == 1 ) {
// 			std::cout << "---";
// 		}
// 		else {
// 			std::cout << '+';
// 		}
// 	}

// 	std::cout << std::endl;
// }

// void printINT( int x ) {
// 	if( x >= 10 and x < 100 ) {
// 		std::cout << " ";
// 	}
// 	else if( x < 10 ) {
// 		std::cout << "  ";
// 	}

// 	std::cout << x;
// }

// void printBoard( Repository::IBoard*  board, int hight, int wight ) {
// 	for( int i = 0 ; i < hight ; i++ ) {
// 		printHline( wight );

// 		for( int j = 0 ; j < wight ; j++ ) {
// 			std::cout << "|";
// 			printINT( board->getFields()[i * wight + j] );
// 		}

// 		std::cout << "|" << std::endl;

// 		for( int j = 0 ; j < wight ; j ++ ) {
// 			std::cout << '|';
// 			printINT( board->getPawnID( i * wight + j ) ) ;
// 		}

// 		std::cout << "|\n";
// 	}

// 	printHline( wight );
// }

void printBoard( std::ostream& out, const Repository::IBoard* board ) {
	auto fields = board->getFields();
	std::sort( fields.begin(), fields.end() );

	for( int i = 0 ; i < 16 ; i++ ) {
		for( int j = 0; j < 16; j++ ) {
			out << "+---+";
		}

		out << "\n";

		for( int j = 0 ; j < 16; j++ ) {
			out << "|";
			out.width( 3 );
			out << fields[i * 16 + j];
			out.width();
			out << "|";
		}

		out << "\n";

		for( int j = 0 ; j < 16; j++ ) {
			out << "|";
			out.width( 3 );

			if( auto[res, error] = board->getPawnID( fields[i * 16 + j] ); error == true ) {
				out << ".";
			}
			else {
				out << res;
			}

			out.width();
			out << "|";
		}

		out << "\n";
	}

	for( int j = 0; j < 16; j++ ) {
		out << "+---+";
	}

	out << "\n";
}

void IOGate::run() {
	while( true ) {
		std::string input;
		out << "Prompt > ";
		getline( in, input );
		//out << input << "\n";

		if( input == "board" ) {
			printBoard( out, repoBoard );
		}
		else if( input == "hand" ) {}
		else if( input == "attack" ) {}
		else if( input == "move" ) {}
		else if( input == "exit" ) {
			break;
		}
		else {
			std::cerr << "error : bad input :" << input << std::endl;
		}
	}
}

IOGate::~IOGate()
{}
