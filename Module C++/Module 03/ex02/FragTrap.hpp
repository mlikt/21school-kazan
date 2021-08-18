#ifndef __SCAVTRAP_H__
#define __SCAVTRAP_H__
#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
private:
public:
	FragTrap();
	FragTrap(std::string const &name);
	FragTrap(FragTrap const &copy);
	FragTrap &operator=(FragTrap const &value);
	~FragTrap();
	virtual void attack		( std::string const &name	);
	virtual void takeDamage	( unsigned int amount		);
	virtual void beRepaired	( unsigned int amount		);
	void highFivesGueys();
};

#endif
