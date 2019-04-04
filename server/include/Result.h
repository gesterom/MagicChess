#pragma once


template<typename Type, typename Error=bool>
class Result final
{
	Type _res;
	Error _error;
	public:
	Result(Type res) : _res(res) {}
	Result(Error error) : _error(error) {}
	operator bool(){
		return not static_cast<bool>(_error);
	}
	Error error() const {
		return _error;
	}
	Type* operator*() const 
	{
		return &_res;
	}
	Type* operator->() const 
	{
		return &_res;
	}
	Type* operator*()
	{
		return &_res;
	}
	Type* operator->()
	{
		return &_res;
	}
	~Result()
	{	}
};

template<typename Type, typename Error>
class Result<Type*,Error> 
{
	Type* _res;
	Error _error;
	public:
	Result(Type* res) : _res(res) {}
	Result(Error error) : _error(error) {}
	operator bool(){
		return not static_cast<bool>(_error);
	}
	Error error() const {
		return _error;
	}
	Type* operator*() const 
	{
		return _res;
	}
	Type* operator->() const 
	{
		return _res;
	}
	Type* operator*()
	{
		return _res;
	}
	Type* operator->()
	{
		return _res;
	}
	~Result()
	{
		delete _res;
	}
};
