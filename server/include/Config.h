#pragma once
#include <unordered_map>
#include <string>

class Config {
  private:
	std::unordered_map<std::string, std::string> map;
  public:
	Config( std::string filename );
	template< typename T>
	T get( std::string key ) const ;
};

template<> int Config::get( std::string key ) const ;
template<> double Config::get( std::string key ) const ;
