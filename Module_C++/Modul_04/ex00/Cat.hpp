#ifndef __CAT_H__
# define __CAT_H__
# include "Animal.hpp"

class Cat : public Animal
{
public:
	Cat();
	Cat(Cat const &);
	Cat& operator = (Cat const &);
	virtual ~Cat();
	virtual void makeSound( void ) const;
};

#endif