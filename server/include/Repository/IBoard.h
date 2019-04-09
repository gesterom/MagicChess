#pragma once
#include "interface.h" //TODO probably to remove
#include "Result.h"

namespace Repository {
	class IBoard {
	  public:
		virtual Result<ID::Entity::Pawn> getPawnID( ID::Entity::Field ) const = 0 ;
		virtual std::vector<ID::Entity::Field> getFields() const = 0;

		virtual bool spawnPawn( ID::Entity::Field, ID::Entity::Pawn ) = 0;
		virtual ~IBoard() {}
	};
}
