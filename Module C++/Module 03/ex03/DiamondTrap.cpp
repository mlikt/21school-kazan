#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap()
: ClapTrap("", 100, 50, 30), FragTrap(), ScavTrap(),
name("Noname")
{
	ClapTrap::name = this->name + "_clap_trap";
	std::cout << "Nameless DiamondTrap warrior created" << std::endl;
	std::cout << "Hitpoints: " << this->hitpoints << ", " 
	<< "Energy points: " << this->energy_points << ", " 
	<< "Attack damage: " <<  this->attack_damage << std::endl;
}

DiamondTrap &DiamondTrap::operator = (DiamondTrap const &value)
{
	std::cout << "I'm " << value.name 
	<< " gave my experience my bro and his name is also " 
	<< value.name << "!" << std::endl;

	this->name			= value.name;
	this->hitpoints		= value.hitpoints;
	this->energy_points	= value.energy_points;
	this->attack_damage	= value.attack_damage;
	return (*this);
}

DiamondTrap::DiamondTrap(std::string const &name)
: ClapTrap(name + "_clap_trap", 100, 50, 30), FragTrap(name), ScavTrap(name),
name(name)
{
	std::cout <<  "DiamondTrap " << name << " warrior created" << std::endl;
	std::cout << "Nameless DiamondTrap warrior created" << std::endl;
	std::cout << "Hitpoints: " << this->hitpoints << ", " 
	<< "Energy points: " << this->energy_points << ", " 
	<< "Attack damage: " <<  this->attack_damage << std::endl;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap " << this->name << " destroyed" << std::endl;
}

void	DiamondTrap::attack( std::string const & name )
{
	ScavTrap::attack(name);
}

void	DiamondTrap::takeDamage ( unsigned int amount )
{
	std::cout << "DiamondTrap" << this->name 
	<< " take " << amount << " point of damage!"
	<< std::endl;
	this->hitpoints -= amount;
}

void	DiamondTrap::beRepaired ( unsigned int amount )
{
	std::cout << "DiamondTrap " << this->name
	<< " repaired by " << amount << " health points."
	<< std::endl;
	this->hitpoints += amount;
}

void	DiamondTrap::WhoAmI ( void )
{
	std::cout << "I am " << this->name << std::endl;
	std::cout << "I am " << ClapTrap::name << std::endl;
}