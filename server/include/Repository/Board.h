#pragma once
#include "Repository/IBoard.h"

namespace Repository{

	class Board : public Repository::IBoard {
		struct Field
		{
			ID::Entity::Field id;
			ID::Entity::Pawn pawn;
		};
		std::vector<Field> board;
	  public:
		Board();
		virtual std::vector<ID::Entity::Field> getFields() const override;
		//Board( std::vector<DAO::Field*>& board );
		virtual Result<ID::Entity::Pawn> getPawnID( ID::Entity::Field ) const override;
	};
}
