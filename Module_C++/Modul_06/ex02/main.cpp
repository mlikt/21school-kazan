#include <iostream>
#include "Classes.hpp"

void identify (Base *p) {
	if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
}

void identify (Base &p) {
	try
	{
		A a = dynamic_cast<A&>(p);
		std::cout << "A" << std::endl;
	}
	catch(...){}
	try
	{
		B a = dynamic_cast<B&>(p);
		std::cout << "B" << std::endl;
	}
	catch(...){}
	try
	{
		C a = dynamic_cast<C&>(p);
		std::cout << "C" << std::endl;
	}
	catch(...){}
}

Base *generate (void){
	std::srand(std::time(nullptr) * std::rand() * std::clock());
	int i = std::rand() % 3;
	if (i == 1)
		return (new A());
	if (i == 2)
		return (new B());
	return (new C());
}

int main ( void )
{
	std::cout << "this pointer" << std::endl;
	for (int i = 0; i < 10; i++)
	{
		Base *ex = generate();
		identify(ex);
		delete ex;
	}
	std::cout << "this reference" << std::endl;
	for (int i = 0; i < 10; i++)
	{
		Base &ex = *(generate());
		identify(ex);
		delete &ex;
	}

	return (0);
}
