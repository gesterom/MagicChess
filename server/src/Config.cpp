#include "Config.h"
#include <fstream>
#include <iostream>

std::string removeWhiteSpace(std::string str)
{
	std::string res;
	for(auto i : str)
	{
		if(isspace(i)) continue;
		else res+=i;
	}
	return res;
}

Config::Config(std::string filename)
{
	std::ifstream in(filename);
	while(in.good())
	{
		std::string key,value;
		getline(in,key,'=');
		getline(in,value);		
		this->map[removeWhiteSpace(key)] = removeWhiteSpace(value);
	}	
}

template<>
std::string Config::get(std::string key) const {
	std::string res;
	try{
		res = this->map.at(key);
	}catch(std::out_of_range ex)
	{
		//TODO
		std::cerr<<"Exception : std::out_of_range : "<<__FILE__<<":"<<__PRETTY_FUNCTION__<<"( "<<__LINE__<<" )"<<" Description : Acess to out of rage with key :"<<key<<std::endl;
	}
	return res;
}

template<>
int Config::get<int>(std::string key) const 
{
	return atoi(this->get<std::string>(key).c_str());
}

template<>
double Config::get<double>(std::string key) const
{
	return atof(this->get<std::string>(key).c_str());
}

