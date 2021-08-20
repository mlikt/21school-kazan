#include "Cat.hpp"

Cat::Cat(): Animal("Cat"), CatBrain(new Brain()) {
	std::cout << "Cat created" << std::endl;
}

Cat::Cat(Cat const &copy):Animal(copy){
	std::cout << "Cat cloned" << std::endl;
	*this = copy;
}

Cat&	Cat::operator = (Cat const &source)
{
	this->type = source.type;
	this->CatBrain = new Brain(*(source.CatBrain));
	return (*this);
}

Cat::~Cat(){
	delete this->CatBrain;
	std::cout << "Cat destructed" << std::endl;
}

void Cat::makeSound( void ) const {
	std::cout << "Meow, Meow!\a" << std::endl;
}