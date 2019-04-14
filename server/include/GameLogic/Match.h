#pragma once

#include "Contract.h"
#include "Result.h"
#include "Repository/IBoard.h"

class Player;

class Match{
	private:
		ID::Entity::Player playerW;
		ID::Entity::Player playerB;
		Repository::IBoard* board;
		bool isTurnW;
	public:
		Match(Repository::IBoard* board,ID::Entity::Player pW,ID::Entity::Deck dW,ID::Entity::Player pB,ID::Entity::Deck dB);
		Error move(ID::Entity::Player player, ID::Entity::Field from, ID::Entity::Field to);
		~Match();
};
