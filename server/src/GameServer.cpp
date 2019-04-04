#include "GameServer.h"
#include "Config.h"
#include "Repository/IRepositoryFactory.h"

#include <iostream>

GameServer::GameServer(const Config& config,const IRepositoryFactory& repoFactory) 
{
	this->hight = config.get<int>("hight");
	this->wight = config.get<int>("wight");
	for(int i = 0 ; i < hight ; i++)
	{
		for(int j = 0 ; j < wight ; j++)
		{
			this->board.push_back(i*wight+j);
		}
	}
	//this->board.resize(this->hight*this->wight);
}

void printHline(int wight)
{
	for(int i = 0 ; i < wight *2 +1 ; i++){ 
		if(i%2 == 1 ) std::cout<<"---";
		else std::cout<<'+';
	}
		std::cout<<std::endl;
}

void printINT(int x)
{
	if(x >= 10 and x < 100 ) std::cout<<" ";
	else if(x<10) std::cout<<"  ";
	std::cout<<x;
}

void printBoard( std::vector<ID::Entity::Fild> board , int hight, int wight)
{
	for(int i = 0 ; i < hight ;i++){
		printHline(wight);
		for(int j = 0 ; j < wight ; j++)
		{
			std::cout<<"|";
			printINT(board[i*wight+j]);
		}
		std::cout<<"|"<<std::endl;
		for(int j = 0 ; j < wight ; j ++)
		{
			std::cout<<'|';
			std::cout<<"   "; // print pawn img;
		}
		std::cout<<"|\n";
	}
	printHline(wight);
}	

void GameServer::run()
{
	//TODO add commmand executor, remove iostream
	while(true)
	{
		std::string input;
		std::cin>>input;
		if(input == "board")
		{
			printBoard(this->board,this->hight,this->wight);
		}
		else if(input == "hand"){}
		else if(input == "attack"){}
		else if(input == "move"){}
		else if(input == "exit"){ break;}
		else {
			std::cerr<<"error : bad input :"<<input<<std::endl;
		}
	}
}
