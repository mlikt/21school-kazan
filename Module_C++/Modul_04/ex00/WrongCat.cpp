#include "WrongCat.hpp"

WrongCat::WrongCat(): WrongAnimal("WrongCat") {
	std::cout << "WrongCat created" << std::endl;
}

WrongCat::WrongCat(WrongCat const &copy):WrongAnimal(copy) {
	std::cout << "WrongCat cloned" << std::endl;
}

WrongCat&	WrongCat::operator = (WrongCat const &source)
{
	this->type = source.type;
	return (*this);
}

WrongCat::~WrongCat(){
	std::cout << "WrongCat destructed" << std::endl;
}

void WrongCat::makeSound( void ) const {
	std::cout << "Meow, Meow!\a" << std::endl;
}