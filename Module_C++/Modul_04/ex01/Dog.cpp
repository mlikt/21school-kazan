#include "Dog.hpp"

Dog::Dog(): Animal("Dog"), DogBrain(new Brain()) {
	std::cout << "Dog created" << std::endl;
}

Dog::Dog(Dog const &copy):Animal(copy) {
	std::cout << "Dog cloned" << std::endl;
	*this = copy;
}

Dog&	Dog::operator = (Dog const &source)
{
	this->type = source.type;
	this->DogBrain = new Brain(*(source.DogBrain));
	return (*this);
}

Dog::~Dog(){
	delete this->DogBrain;
	std::cout << "Dog destructed" << std::endl;
}

void Dog::makeSound( void ) const {
	std::cout << "Woof, Woof!\a" << std::endl;
}
