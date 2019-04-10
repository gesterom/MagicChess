#pragma once
#include "Repository/IRepositoryFactory.h"

class Config;

class RepositoryFactory : public IRepositoryFactory {
	Repository::IBoard* _board;
  public:
	RepositoryFactory( const Config& config );
	virtual const Repository::IBoard* board() const override ;
	virtual Repository::IBoard* board() override ;
};
