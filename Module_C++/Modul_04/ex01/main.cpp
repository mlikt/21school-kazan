#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main ( void )
{
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::string		str;

	const Animal* copy_j = new Dog(*((Dog *)j));

	std::cout << "----------------------" << std::endl;
	j->makeSound();
	i->makeSound();
	std::cout << "----------------------" << std::endl;
	copy_j->makeSound();
	std::cout << "----------------------" << std::endl;

	delete j;
	delete i;
	delete copy_j;

	std::getline(std::cin, str); // Придержим исполнение программы, чтобы проверить существуют ли утечки?

	return (0);
}