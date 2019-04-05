#pragma once
#include "interface.h" //TODO probably to remove
#include "Result.h"

namespace Repository {
	class IBoard {
	  public:
		virtual Result<ID::Entity::Pawn> getPawnID( ID::Entity::Field ) const = 0 ;
	};
}