#include "Zombie.hpp"

Zombie *newZombie( std::string name )
{
	Zombie *ptr_zombie = new Zombie(name);
	return (ptr_zombie);
}

void randomChump( std::string name )
{
	Zombie	ChumpZombie(name);
	ChumpZombie.announce();
}
