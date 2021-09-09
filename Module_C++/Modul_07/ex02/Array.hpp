#ifndef __ARRAY_H__
#define __ARRAY_H__
#include <iostream>

template<typename T>
class Array 
{
	private:
		T *arr;
		unsigned int n;
	public:
		Array():arr(nullptr), n(0) {}
		Array(unsigned int n):n(n) { this->arr = new T[n](); }
		Array(Array const &copy):arr(nullptr) {
			*this = copy;
		}
		~Array(){ delete [] this->arr; }
	
		Array& operator = (Array const &ex){
			delete [] this->arr;
			this->arr = new T[ex.n]();
			this->n = ex.n;
			for (unsigned int i = 0; i < ex.n; i++)
				this->arr[i] = ex.arr[i];
			return (*this);
		}

		T& operator [] (unsigned int const index){
			if ( index >= n )
				throw std::exception();
			return (this->arr[index]);
		}

		unsigned int size( void ) const {
			return (this->n);
		}
};

#endif