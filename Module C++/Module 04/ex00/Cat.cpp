#include "Cat.hpp"

Cat::Cat(): Animal("Cat") {
	std::cout << "Cat created" << std::endl;
}

Cat::Cat(Cat const &copy):Animal(copy) {
	std::cout << "Cat cloned" << std::endl;
}

Cat&	Cat::operator = (Cat const &source)
{
	this->type = source.type;
	return (*this);
}

Cat::~Cat(){
	std::cout << "Cat destructed" << std::endl;
}

void Cat::makeSound( void ) const {
	std::cout << "Meow, Meow!\a" << std::endl;
}