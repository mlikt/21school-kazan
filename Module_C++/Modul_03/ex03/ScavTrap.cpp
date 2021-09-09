#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
: ClapTrap( "Noname", 100, 50, 20)
{
	std::cout << "Nameless ScavTrap warrior created" << std::endl;
}

ScavTrap::ScavTrap(std::string const &name)
: ClapTrap (name, 100, 50, 20)
{
	std::cout << "ScavTrap " << name << " is ready for battle" << std::endl;
}

ScavTrap::ScavTrap(ScavTrap const &copy)
: ClapTrap (copy.name, copy.hitpoints, copy.energy_points, copy.attack_damage)
{
	std::cout << "I'm " << copy.name 
	<< " clone my bro and now his name is also " 
	<< copy.name << "!" << std::endl;
}

ScavTrap &ScavTrap::operator = (ScavTrap const &value)
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

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap " << this->name << " destroyed" << std::endl;
}

void ScavTrap::guardGate()
{
		this->energy_points -= 10;
		std::cout << "ScavTrap " << this->name << " enabled gate keeper mode" << std::endl;
		this->beRepaired(500);
}

void	ScavTrap::attack( std::string const & name )
{
		std::cout << "ScavTrap " << this->name
		<< " attack " << name << " causing "
		<< this->attack_damage <<  " point of damage!"
		<< std::endl;
		std::cout << "Energy wasted " << this->attack_damage << " points" << std::endl; 
		this->energy_points -= this->attack_damage;
}

void	ScavTrap::takeDamage ( unsigned int amount )
{
	std::cout << "ScavTrap" << this->name 
	<< " take " << amount << " point of damage!"
	<< std::endl;
	this->hitpoints -= amount;
}

void	ScavTrap::beRepaired ( unsigned int amount )
{
	std::cout << "ScavTrap " << this->name
	<< " repaired by " << amount << " health points."
	<< std::endl;
	this->hitpoints += amount;
}
