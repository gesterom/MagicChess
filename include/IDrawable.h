#pragma once
#include <string>

class IDrawable
{
	public:
	virtual std::string image() = 0;
	virtual ~IDrawable(){}
};


