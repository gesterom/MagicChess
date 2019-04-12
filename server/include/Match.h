#pragma once

#include "interface.h"
#include "Player.h"
#include "Board.h"

class Match{
	private:
		Player PlayerW;
		Player PlayerB;
		Board board;
	public:
		Match(ID::Entity::Player pW,ID::Entity::Deck dW,ID::Entity::Player pB,ID::Entity::Deck dB);
		const Player getPlayer(int playerIdinMtch) const;
		Player getPlayer(int playerIdinMtch);
		~Match();
};
