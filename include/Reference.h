#include <string>

#defender assert(x) 

constexpr void _assert(std::string _if, masage)
{

}

template<typename T>
class Reference
{
	T* ptr;
	bool bptr;
	std::string error;
	public:
		Reference():ptr(nullptr), bptr(false) {}
		Reference(T* pointer) :  ptr(pointer), bptr(true){}
		Reference(T& reference) :  ptr(*reference), bptr(false) {}

		Reference(Reference<T>& copy) = delete;
		Reference(Reference<T>&& move) : ptr(move.ptr), bptr(move.bptr) {
			move.bptr = false;
			move.ptr = nullptr;
			move._exist = false;
		}

		Reference<T>& operator=(Reference<T>& copy) = delete ;	
		Reference<T>& operator=(Reference<T>&& move){
			if(this == &move) return *this;
			if(bptr and ptr) delete ptr;
			
			this->ptr = move._ptr;
			this->bptr = move.bptr;

			move.ptr = nullptr;
			move.bptr = false;
			return *this;
		}

		T* operator*(){return ptr;}
		const T* operator*() const {return ptr;}
		T* operator->(){ return ptr;}
		const T* operator->() const { return ptr;}
		
		operator bool () const {return ptr!=nullptr;}
		bool exist() const {return ptr!=nullptr;}

		~Reference(){if(bptr)	delete ptr;	}	
};
