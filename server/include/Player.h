#pragma once

#include "interface.h"

class Match;

class Player
{
	Match& match; // or board
	public:
		Player(Match& match,ID::Entity::Deck id); // or MatchPlayerApi
		//bool move(Field from,Field to);
};
