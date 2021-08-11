#include "Zombie.hpp"

int main ( void )
{
	Zombie	*Horde;
	int N = 6;

	Horde = HordeZombie(N, "Crazy");
	for (int i = 0; i < N; i++)
		Horde[i].announce();
	delete [] Horde;
	return (0);
}