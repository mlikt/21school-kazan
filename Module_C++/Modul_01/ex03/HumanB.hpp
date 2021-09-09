#include "Weapon.hpp"

#ifndef __HUMANB_H__
#define __HUMANB_H__

class HumanB
{
private:
	Weapon*		weapon;
	std::string	name;
public:
	HumanB(std::string const& name);
	~HumanB() {}
	void	setWeapon(Weapon& weapon);
	void	attack( void );
};

#endif