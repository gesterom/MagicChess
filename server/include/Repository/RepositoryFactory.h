#pragma once
#include "Repository/IRepositoryFactory.h"

class Config;

class RepositoryFactory : public IRepositoryFactory {
  public:
	RepositoryFactory( const Config& config );
};