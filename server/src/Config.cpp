#include "Config.h"
#include <fstream>
#include <iostream>

std::string removeWhiteSpace( std::string str ) {
	std::string res;
	char last = '\0';

	for( auto i : str ) {
		if( last == '\\' ) {
			if( i == '\\' ) {
				res += '\\';
			}
			else if( i == ' ' ) {
				res += ' ';
			}

			last = '\0';
			continue;
		}

		if( i == '\\' ) {
			last = '\\';
			continue;
		}

		if( isspace( i ) ) {
			continue;
		}
		else {
			res += i;
		}
	}

	return res;
}

Config::Config( std::string filename ) {
	std::ifstream in( filename );
	std::string section_name = "";

	while( in.good() ) {
		std::string str;
		getline( in, str );
		str = removeWhiteSpace( str );
		std::string key, value;

		if( str[0] == '[' and str[str.size() - 1] == ']' ) { // section detected
			str.erase( 0, 1 );
			str.erase( str.size() - 1 );
			section_name = str;
			continue;
		}
		else {
			auto pos = str.find( "=" );

			if( pos == std::string::npos ) {
				continue;
			}

			key = str.substr( 0, pos );
			value = str.substr( pos + 1 );
		}

		if( key[0] == ';' or key[0] == '#' ) {
			continue;
		}

		this->map[section_name + ( ( section_name.empty() ) ? "" : "." ) + key] = value;
	}

	for ( auto i : map ) {
		std::cerr << i.first << " = " << i.second << std::endl;
	}
}

Config::Config( const  Config& other )
{
	this->map = other.map;
}

Config::Config (Config&& other)
{
	this->map = std::move(other.map);
}

template<>
std::string Config::get( std::string key ) const {
	std::string res;

	try {
		res = this->map.at( key );
	}
	catch( std::out_of_range& ex ) {
		//TODO add loger remove iostream
		std::cerr << "Exception : std::out_of_range : " << __FILE__ << ":" << __PRETTY_FUNCTION__ << "( " << __LINE__ << " )" << " Description : Acess to out of rage with key :" << key << std::endl;
	}

	return res;
}

template<>
int Config::get<int>( std::string key ) const {
	return atoi( this->get<std::string>( key ).c_str() );
}

template<>
double Config::get<double>( std::string key ) const {
	return atof( this->get<std::string>( key ).c_str() );
}

