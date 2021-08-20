#include "WrongAnimal.hpp"

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal destructed" << std::endl;
}

WrongAnimal::WrongAnimal():type("") {
	std::cout << "WrongAnimal created" << std::endl;
}

WrongAnimal::WrongAnimal(std::string const &type):type(type) {
	std::cout << "WrongAnimal created" << std::endl;
}

WrongAnimal::WrongAnimal(WrongAnimal const &copy):type(copy.type) {
	std::cout << "WrongAnimal cloned" << std::endl;
}

WrongAnimal&	WrongAnimal::operator = (WrongAnimal const &source)
{
	this->type = source.type;
	return (*this);
}

std::string const &WrongAnimal::getType( void ) const
{
	return (this->type);
}


void WrongAnimal::makeSound( void ) const {
	std::cout << "Muuuuuuuuuu!!" << std::endl;
}
