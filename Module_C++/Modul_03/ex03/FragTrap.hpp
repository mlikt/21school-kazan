#ifndef __FRAGTRAP_H__
#define __FRAGTRAP_H__
#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
public:
	FragTrap();
	FragTrap(std::string const &name);
	FragTrap(FragTrap const &copy);
	FragTrap &operator=(FragTrap const &value);
	virtual ~FragTrap();
	virtual void	attack		( std::string const &name	);
	virtual void	takeDamage	( unsigned int amount		);
	virtual void	beRepaired	( unsigned int amount		);
	void			highFivesGueys();
};

#endif
