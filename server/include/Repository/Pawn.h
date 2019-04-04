#pragma once
#include "Repository/IPawn.h"

namespace Repository {
	class Pawn : public Repository::IPawn {
		std::vector<DAO::Field*>& board;
		public:
		Pawn(std::vector<DAO::Field*>& board);
		virtual Result<ID::Entity::Pawn> getPawnID( ID::Entity::Field ) const override;
	};
}
