#ifndef __DIAMONDTRAP_H_
#define __DIAMONDTRAP_H_
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap
{
private:
	std::string		name;
public:
	DiamondTrap();
	DiamondTrap(std::string const &name);
	DiamondTrap &operator = (DiamondTrap const &value);
	~DiamondTrap();
	virtual void	attack		( std::string const &name	);
	virtual void	takeDamage	( unsigned int amount		);
	virtual void	beRepaired	( unsigned int amount		);
	void			WhoAmI		( void );
};
#endif