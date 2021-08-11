#include "Weapon.hpp"

Weapon::Weapon(std::string type)
{
	this->setType(type);
}

void Weapon::setType(std::string const &type)
{
	this->type = type;
}


std::string const &Weapon::getType( void ) const
{
	return(this->type);
}
