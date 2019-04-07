#pragma once

#include "Repository/IBoard.h"

class IRepositoryFactory {
  public:
	virtual Repository::IBoard* board() const = 0;
	virtual ~IRepositoryFactory() {}
};

