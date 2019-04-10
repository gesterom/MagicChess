#pragma once
#include "Repository/IBoard.h"
#include <unordered_map>

namespace Repository {

	class Board : public Repository::IBoard {
		struct Field {
			ID::Entity::Field id;
			ID::Entity::Pawn pawn;
		};
		std::unordered_map<ID::Entity::Field, Field> board;
	  public:
		Board();
		virtual std::vector<ID::Entity::Field> getFields() const override;
		virtual Result<ID::Entity::Pawn> getPawnID( ID::Entity::Field ) const override;
		virtual bool spawnPawn( ID::Entity::Field, ID::Entity::Pawn ) override;
	};
}
