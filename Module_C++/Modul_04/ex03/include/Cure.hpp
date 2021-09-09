#ifndef __CURE_H__
#define __CURE_H__
#include "AMateria.hpp"

class Cure: public AMateria // Материя жизни
{
public:
	Cure();
	Cure(Cure const & copy);
	virtual AMateria* clone() const;
	virtual ~Cure();
	virtual void use(ICharacter &target);
};

#endif