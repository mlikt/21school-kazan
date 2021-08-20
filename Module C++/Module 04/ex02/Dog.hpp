#ifndef __DOG_H__
#define __DOG_H__
#include "Animal.hpp"

class Dog : public Animal
{
private:
	Brain * DogBrain;
public:
	Dog();
	Dog(Dog const &);
	Dog& operator = (Dog const &);
	virtual ~Dog();
	virtual void makeSound( void ) const;
};

#endif