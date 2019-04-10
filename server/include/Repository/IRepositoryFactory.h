#pragma once

#include "Repository/IBoard.h"

class IRepositoryFactory {
  public:
	virtual const Repository::IBoard* board() const = 0;
	virtual Repository::IBoard* board() = 0;
	virtual ~IRepositoryFactory() {}
};

