#ifndef __ANIMAL_H__
#define __ANIMAL_H__

#include <iostream>
#include <string>

class Animal
{
protected:
	std::string type;
	Animal(std::string const &type);
public:
	Animal();
	Animal(Animal const &copy);
	Animal&	operator = (Animal const &source);
	virtual ~Animal();
	std::string  const &getType( void ) const;
	virtual void makeSound( void ) const;
};

#endif