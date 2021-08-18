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
	void	attack		( std::string const &name	);
	void	takeDamage	( unsigned int amount		);
	void	beRepaired	( unsigned int amount		);
	void			highFivesGueys();
};

#endif
