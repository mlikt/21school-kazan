#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
:name(""), hitpoints(10), 
energy_points(10), attack_damage(0)
{
	std::cout << "Nameless ClapTrap warrior created" << std::endl;
}

ClapTrap::ClapTrap(std::string const &name)
:name(name), hitpoints(10), 
energy_points(10), attack_damage(0)
{
	std::cout << "ClapTrap " << name 
	<< " is created." <<  std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap " << name 
	<< " destroyed." <<  std::endl;
}

ClapTrap::ClapTrap (ClapTrap const &name)
: name(name.name), hitpoints(name.hitpoints)
, energy_points(name.energy_points), attack_damage(name.attack_damage)
{
	std::cout << "I'm " << name.name 
	<< " clone my bro and now his name is also " 
	<< name.name << "!" << std::endl;
}

ClapTrap &ClapTrap::operator = (ClapTrap const &value)
{
	std::cout << "I'm " << value.name 
	<< " gave my experience my bro and now his name is also " 
	<< value.name << "!" << std::endl;

	this->name			= value.name;
	this->hitpoints		= value.hitpoints;
	this->energy_points	= value.energy_points;
	this->attack_damage	= value.attack_damage;
	return (*this);
}

void	ClapTrap::attack( std::string const & name )
{
	std::cout << "ClapTrap " << this->name
	<< " attack " << name << " causing "
	<< this->attack_damage <<  " point of damage!"
	<< std::endl;
	std::cout << "Energy wasted " << this->attack_damage << " points" << std::endl; 
	this->energy_points -= this->attack_damage;
}

void	ClapTrap::takeDamage ( unsigned int amount )
{
	std::cout << "ClapTrap " << this->name 
	<< " take " << amount << " point of damage!"
	<< std::endl;

	this->hitpoints -= amount;
}

void	ClapTrap::beRepaired ( unsigned int amount )
{
	std::cout << "ClapTrap " << this->name
	<< " repaired by " << amount << " health points."
	<< std::endl;
	this->hitpoints += amount;
}
