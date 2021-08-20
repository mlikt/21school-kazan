#ifndef __IMATERIASOURCE_H__
#define __IMATERIASOURCE_H__
#include "AMateria.hpp"

class IMateriaSource // Источник Материи
{
	public:
		virtual ~IMateriaSource() {}
		virtual void learnMateria(AMateria*) = 0;
		virtual AMateria* createMateria(std::string const & type) = 0;
};

#endif