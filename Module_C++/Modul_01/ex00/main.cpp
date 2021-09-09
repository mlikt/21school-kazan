#include "Zombie.hpp"

int main( void )
{
	Zombie	*ZombieBill;
	Zombie	*ZombieKain;

	ZombieBill = newZombie("Bill");
	randomChump("Kevin");
	randomChump("Arnold");
	ZombieKain = newZombie("Kain");

	ZombieKain->announce();
	ZombieBill->announce();
	delete	ZombieKain;
	delete ZombieBill;
	return (0);
}