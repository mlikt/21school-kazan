#ifndef __SCAVTRAP_H__
#define __SCAVTRAP_H__
#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{
public:
	ScavTrap();
	ScavTrap(std::string const &name);
	ScavTrap(ScavTrap const &copy);
	ScavTrap &operator=(ScavTrap const &value);
	virtual ~ScavTrap();
	void attack		( std::string const &name	);
	void takeDamage	( unsigned int amount		);
	void beRepaired	( unsigned int amount		);
	void guardGate ();
};

#endif
