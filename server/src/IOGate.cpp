#include "IOGate.h"
#include <iostream>
#include <algorithm>
#include <sstream>

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

			auto t = board->getPawnID( fields[i * 16 + j] ); 
			if( t.error() ) {
				out << ".";
			}
			else {
				out << t.value();
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

std::vector<std::string> split(std::string s)
{
	std::vector<std::string> res;
	std::stringstream ss(s);
	while (ss.good())
	{
		ss>>s;
		res.push_back(s);
	}
	return res;
}

void IOGate::run() {
	while( true ) {
		std::string input;
		out << "Prompt > ";
		getline( in, input );
		//out << input << "\n";
		
		auto args = split(input);

		if( args[0] == "board" ) {
			printBoard( out, repoBoard );
		}
		else if( args[0] == "hand" ) {}
		else if( args[0] == "attack" ) {}
		else if( args[0] == "move") {
			if(args.size()>=4 )
			game.move( atoi(args[1]),atoi(args[2]),atoi(args[3]));
			else
			{
				out<<"Error not enough arguments\n";
			}
		}
		else if( args[0] == "exit" ) {
			break;
		}
		else {
			std::cerr << "error : bad input :" << input << std::endl;
		}
	}
}

IOGate::~IOGate()
{}
