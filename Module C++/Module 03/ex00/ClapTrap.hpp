
#ifndef __CLAPTRAP_H__
#define  __CLAPTRAP_H__
#include <iostream>
#include <string>

class ClapTrap
{
private:
	std::string		name;
	unsigned int	hitpoints;
	unsigned int	energy_points;
	unsigned int	attack_damage;
public:
	ClapTrap ();
	ClapTrap(std::string const &name);
	ClapTrap(ClapTrap const &copy);
	ClapTrap &operator = (ClapTrap const &value);
	~ClapTrap();

	void attack		( std::string const &name	);
	void takeDamage	( unsigned int amount		);
	void beRepaired	( unsigned int amount		);
};
#endif