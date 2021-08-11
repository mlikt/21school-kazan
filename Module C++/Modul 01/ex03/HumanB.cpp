#include "HumanB.hpp"

HumanB::HumanB(std:: string const& name)
{
	this->name = name;
}

void HumanB::setWeapon(Weapon &weapon)
{
	this->weapon = &weapon;
}

void HumanB::attack( void )
{
	std::cout
	<< this->name				<< " attacks with his " 
	<< this->weapon->getType()	<< std::endl;
}
