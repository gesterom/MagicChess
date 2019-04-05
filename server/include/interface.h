#pragma once

#include "Result.h"

#include <utility>
#include <vector>
#include <stdint.h>

//To moeze sie zmeinic

// ID = 0 -=> object dont exist

namespace ID {
	namespace Entity {
		using Field = uint32_t;
		using Card = uint32_t;
		using Pawn = uint32_t;
		using Player = uint32_t;
	}
	namespace Type {
		using Pawn = uint32_t;
		using Card = uint32_t;
	}
}

//////////////////////////////////
namespace DAO {
	struct Pawn {
		ID::Entity::Pawn id;
		int hp;
		int armor;
		int attack;
		ID::Entity::Player player;
		ID::Entity::Field fild;
		ID::Type::Pawn type;
	};

	struct Card {
		ID::Entity::Card id;
		int CP_cost;
		int MP_cost;
		int AP_req;
		ID::Type::Card type;
	};

	struct Field {
		ID::Entity::Field id;
		ID::Entity::Pawn pawn;
	};
}

//////////////////////////////////

std::vector<ID::Entity::Field> get_board();
ID::Entity::Pawn getPawnID( ID::Entity::Field );
DAO::Pawn getPawn( ID::Entity::Pawn );

std::vector<ID::Entity::Card> getHand( ID::Entity::Player );
DAO::Card getCard( ID::Entity::Card );

Result<bool> move( ID::Entity::Pawn, ID::Entity::Field, ID::Entity::Field );
Result<bool> attack( ID::Entity::Pawn, ID::Entity::Field );
//bool usePawn(UID_Pawn);

Result<bool> useCard( ID::Entity::Card );
Result<bool> useCard( ID::Entity::Card, ID::Entity::Field );
//bool useCard(UID_Card,UID_Field,UID_Field);

Result<ID::Entity::Card> drawCard();

