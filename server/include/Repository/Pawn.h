#pragma once

namespace Repository {
	class Pawn : IPawn {
	  public:
		virtual ID::Entity::Pawn getPawnID( ID::Entity::Field ) override ;
	};
}
