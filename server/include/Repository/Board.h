#pragma once
#include "Repository/IBoard.h"

namespace Repository {
	class Board : public Repository::IBoard {
		std::vector<DAO::Field*>& board;
	  public:
		Board( std::vector<DAO::Field*>& board );
		virtual Result<ID::Entity::Pawn> getPawnID( ID::Entity::Field ) const override;
	};
}
