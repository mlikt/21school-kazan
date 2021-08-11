#include "Weapon.hpp"

#ifndef __HUMANA_H__
#define __HUMANA_H__

class HumanA
{
private:
	Weapon&		weapon;
	std::string	name;
public:
	HumanA(std::string const &name, Weapon &weapon);
	~HumanA() {}
	void	attack( void );
};

#endif