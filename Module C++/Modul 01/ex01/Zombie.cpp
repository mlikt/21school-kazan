#include "Zombie.hpp"

Zombie::Zombie(){}

Zombie::Zombie (std::string name)
{
	this->name = name;
	std::cout << "Zombie " << name << " is awake!" << std::endl;
}

Zombie::~Zombie()
{
	std::cout << "Zombie " << this->name << " is dead!" << std::endl;
}

void Zombie::announce( void )
{
	std::cout << this->name << " BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::setName(std::string *name)
{
	this->name = *name;
	std::cout << "Zombie " << this->name << " is awake!" << std::endl;
}