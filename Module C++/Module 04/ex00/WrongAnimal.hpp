#ifndef __WRONGANIMAL_H__
#define __WRONGANIMAL_H__
#include <iostream>
#include <string>

class WrongAnimal
{
protected:
	std::string type;
	WrongAnimal(std::string const &type);
public:
	WrongAnimal();
	WrongAnimal(WrongAnimal const &copy);
	WrongAnimal&	operator = (WrongAnimal const &source);
	virtual ~WrongAnimal();
	std::string  const &getType( void ) const;
	void makeSound( void ) const;
};

#endif