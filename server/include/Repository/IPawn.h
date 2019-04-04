#pragma once
#include "interface" //TODO probably to remove
namespace Repository {
	class IPaw {
	  public:
		virtual ID::Entity::Pawn getPawnID( ID::Entity::Field ) = 0 ;
	};
}
