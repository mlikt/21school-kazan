#ifndef __ICE_H__
#define __ICE_H__
#include "AMateria.hpp"

class Ice: public AMateria // Материя льда
{
public:
	Ice();
	Ice(Ice const & copy);
	virtual AMateria* clone() const;
	virtual ~Ice();
	virtual void use(ICharacter &target);
};

#endif