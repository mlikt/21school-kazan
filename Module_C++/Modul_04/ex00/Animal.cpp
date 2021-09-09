#include "Animal.hpp"

Animal::~Animal()
{
	std::cout << "Animal destructed" << std::endl;
}

Animal::Animal():type("") {
	std::cout << "Animal created" << std::endl;
}

Animal::Animal(std::string const &type):type(type) {
	std::cout << "Animal created" << std::endl;
}

Animal::Animal(Animal const &copy):type(copy.type) {
	std::cout << "Animal cloned" << std::endl;
}

Animal&	Animal::operator = (Animal const &source)
{
	this->type = source.type;
	return (*this);
}

std::string const &Animal::getType( void ) const
{
	return (this->type);
}


void Animal::makeSound( void ) const {
}
