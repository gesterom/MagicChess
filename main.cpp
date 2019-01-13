#include <iostream>
#include <cstdio>
#include <vector>
#include <utility>

class Input
{
	char t;
	public:
		Input(char c)
		{
			t = c;	
		}
		operator bool() const 
		{
			return t=='q';
		}
		bool operator==(const char c ) const 
		{
			return t==c;
		}
};



Input userInput(){
	Input res = getchar();
	if(res=='\n') return userInput();
	return res;
}

class IContext{
	public:
		virtual bool exit( [[maybe_unused]] const Input&  input) { return false;}
		virtual void print() = 0;
		virtual void update(const Input& input) = 0;
		virtual IContext& updateContext() = 0;
		virtual ~IContext(){}
};

class Menu;

using MenuConfig = std::vector<std::pair<std::string,IContext&> > ;

class Menu : public IContext{
	MenuConfig list ;
	int index = 0;
	IContext& ss;
	public:
		Menu(const MenuConfig v)  : list(v), ss(*this) {}
		virtual void print() override {
			int aa=0;
			for(auto i : list)
			{
				std::cout<<((aa%list.size() == index)?'>':' ')<<" [ "<<" ] "<<i.first<<std::endl;
				aa++;
			}
		}
		virtual void update(const Input& input) override {
			if(input == 'w')index = (list.size() + index - 1)%list.size();
			if(input == 's')index = (index + 1)%list.size();
			if(input == 'd')ss = list[index].second;
		}
		virtual IContext& updateContext() override {return ss;}
		virtual bool exit(const Input& input) override {
			return input == 'q';
		}
};

class Exit : public IContext
{
	public:
	virtual bool exit([[maybe_unused]] const Input& input) { return true;}
	virtual void print(){}
	virtual void update([[maybe_unused]] const Input& input){}
	virtual IContext& updateContext(){return *this;}
};

void clear()
{
	system("clear");
}

int main()
{
}
