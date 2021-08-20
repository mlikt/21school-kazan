#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"



int main ( void )
{
	const Animal* meta		= new Animal();
	const Animal* j			= new Dog();
	const Animal* i			= new Cat();
	const WrongAnimal *wc	= new WrongCat();

	std::cout << "--------------------------" << std::endl;
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	std::cout << "--------------------------" << std::endl;
	j->makeSound();
	i->makeSound();

	std::cout << "--------------------------" << std::endl;
	std::cout << wc->getType() << " " << std::endl;
	wc->makeSound();
	std::cout << "--------------------------" << std::endl;

	delete meta;
	delete j;
	delete i;
	delete wc;
	return (0);
}