#include "Dog.hpp"

Dog::Dog(): Animal("Dog") {
	std::cout << "Dog created" << std::endl;
}

Dog::Dog(Dog const &copy):Animal(copy) {
	std::cout << "Dog cloned" << std::endl;
}

Dog&	Dog::operator = (Dog const &source)
{
	this->type = source.type;
	return (*this);
}

Dog::~Dog(){
	std::cout << "Dog destructed" << std::endl;
}

void Dog::makeSound( void ) const {
	std::cout << "Woof, Woof!\a" << std::endl;
}
