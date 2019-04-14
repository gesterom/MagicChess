#include "GameLogic/Match.h"

//TODO add builder or factory for players objects
Match::Match(Repository::IBoard* board,ID::Entity::Player pW,ID::Entity::Deck dW,ID::Entity::Player pB,ID::Entity::Deck dB)
{	
	this->board = board;
	this->playerB = pB;
	this->playerW = pW;
}

Error Match::move(ID::Entity::Player player, ID::Entity::Field from, ID::Entity::Field to)
{
	//TODO add pawn logic 
	if(this->isTurnW==true and player == playerW){
		if(true/*FIXME*/) // W has this pawn 
		{
			board->movePawn(from,to);
		}
	}
	else if(this->isTurnW == false and player == playerB){}
	else{
		return Error("player not play in this match");
	}
}
