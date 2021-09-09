#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main ( void )
{
	const Animal *animal[10];
	std::string str;

	std::cout << "---------------------" << std::endl;
	for(int i = 0; i < 10; i++)
	{
		if (i < 5)
			animal[i] = new Dog();
		else
			animal[i] = new Cat();
	}
	std::cout << "---------------------" << std::endl;

	(*((Dog *)(animal[1]))).makeSound();
	const Animal *copy = new Dog(*((Dog *)(animal[1])));
	std::cout << "---------------------" << std::endl;

	copy->makeSound();
	std::cout << "---------------------" << std::endl;
	for (int i = 0; i < 10; i++)
		delete animal[i];
	delete copy;
	std::getline(std::cin, str); // Придержим исполнение программы, чтобы проверить существуют ли утечки?
	return (0);
}