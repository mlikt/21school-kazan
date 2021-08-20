#ifndef __WRONGCAT_H__
# define __WRONGCAT_H__
# include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
public:
	WrongCat();
	WrongCat(WrongCat const &);
	WrongCat& operator = (WrongCat const &);
	virtual ~WrongCat();
	void makeSound( void ) const;
};

#endif