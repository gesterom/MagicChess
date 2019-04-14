#pragma once

#include <utility>
#include <string>
//true = error happen

template<typename Type, typename Error>
class _Result final {
	Type _res;
	Error _error;
  public:
	_Result( Type res ) : _res( res ), _error( false ) {}
	_Result( Error error ) : _error( error ) {}
	operator std::pair<Type,Error> ()
	{
		std::make_pair(_res,_error);
	}	
	operator bool() {
		return not static_cast<bool>( _error );
	}
	Error error() const {
		return _error;
	}
	Type& operator*() const {
		return _res;
	}
	Type& operator->() const {
		return _res;
	}
	Type& operator*() {
		return _res;
	}
	Type& operator->() {
		return _res;
	}
	Type& value() {
		return _res;
	}
	~_Result()
	{	}
};

template<typename Type, typename Error>
class _Result<Type*, Error> {
	Type* _res;
	Error _error;
  public:
	_Result( Type* res ) : _res( res ) {}
	_Result( Error error ) : _error( error ) {}
	operator bool() {
		return not static_cast<bool>( _error );
	}
	Error error() const {
		return _error;
	}
	Type* operator*() const {
		return _res;
	}
	Type* operator->() const {
		return _res;
	}
	Type* operator*() {
		return _res;
	}
	Type* operator->() {
		return _res;
	}
	Type* value() {
		return _res;
	}
	~_Result() {
		delete _res;
	}
};

template<typename Error>
class _Result<bool, Error> {
	bool _res;
	Error _error;
  public:
	_Result( bool res ) : _res( res )  {}
	_Result( Error error ) : _res(true) , _error( error ) {}
	operator bool() {
		return not static_cast<bool>( _res );
	}
	Error error() const {
		return _error;
	}
	bool value() {
		return _res;
	}
	~_Result() {
	}
};

using Error = _Result<bool,std::string>;
template<typename T>
using Result = _Result<T,bool>;


