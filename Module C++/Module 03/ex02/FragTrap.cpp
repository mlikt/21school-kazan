#include "FragTrap.hpp"

FragTrap::FragTrap()
: ClapTrap( "Noname", 100, 100, 30)
{
	std::cout << "Nameless FrapTrap warrior created" << std::endl;
}

FragTrap::FragTrap(std::string const &name)
: ClapTrap (name, 100, 100, 30)
{
	std::cout << "FragTrap " << name << " is ready for battle" << std::endl;
}

FragTrap::FragTrap(FragTrap const &copy)
: ClapTrap (copy.name, copy.hitpoints, copy.energy_points, copy.attack_damage)
{
	std::cout << "I'm " << copy.name 
	<< " clone my bro and now his name is also " 
	<< copy.name << "!" << std::endl;
}

FragTrap &FragTrap::operator = (FragTrap const &value)
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

FragTrap::~FragTrap()
{
	std::cout << "FragTrap " << this->name << " destroyed" << std::endl;
}

void FragTrap::highFivesGueys( void )
{
	std::cout << this->name << " Combo!!!:" << std::endl;
	for(int i = 0; i < 5; i++)
	{
		std::cout << "Booooooooum!!!!!" << std::endl;
	}
	std::cout << "Causing 500 point of damage!!!!" << std::endl;
	this->energy_points -= 30;
}

void	FragTrap::attack( std::string const & name )
{
		std::cout << "FragTrap " << this->name
		<< " attack " << name << " causing "
		<< this->attack_damage <<  " point of damage!"
		<< std::endl;
		std::cout << "Energy wasted " << this->attack_damage << " points" << std::endl; 
		this->energy_points -= this->attack_damage;
}

void	FragTrap::takeDamage ( unsigned int amount )
{
	std::cout << "FragTrap" << this->name 
	<< " take " << amount << " point of damage!"
	<< std::endl;
	this->hitpoints -= amount;
}

void	FragTrap::beRepaired ( unsigned int amount )
{
	std::cout << "FragTrap " << this->name
	<< " repaired by " << amount << " health points."
	<< std::endl;
	this->hitpoints += amount;
}
