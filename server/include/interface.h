#include <utility>
#include <vector>
#include <stdint.h>

//To moeze sie zmeinic

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
using Resualt = bool;

//////////////////////////////////
namespace DAO {
	struct Pawn {
		int hp;
		int armor;
		int attack;
		ID::Entity::Player player;
		ID::Entity::Field fild;
		ID::Type::Pawn type;
	};

	struct Card {
		int CP_cost;
		int MP_cost;
		int AP_req;
		ID::Type::Card type;

	};
}

//////////////////////////////////

std::vector<ID::Entity::Field> get_board();
ID::Entity::Pawn getPawnID( ID::Entity::Field );
DAO::Pawn getPawn( ID::Entity::Pawn );

std::vector<ID::Entity::Card> getHand( ID::Entity::Player );
DAO::Card getCard( ID::Entity::Card );

Resualt move( ID::Entity::Pawn, ID::Entity::Field, ID::Entity::Field );
Resualt attack( ID::Entity::Pawn, ID::Entity::Field );
//bool usePawn(UID_Pawn);

Resualt useCard( ID::Entity::Card );
Resualt useCard( ID::Entity::Card, ID::Entity::Field );
//bool useCard(UID_Card,UID_Field,UID_Field);

std::pair<Resualt, ID::Entity::Card> drawCard();

