#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "DiamondTrap.hpp"

int main (void)
{
	DiamondTrap *T = new DiamondTrap("Bob");

	T->attack("BugoBugo");
	T->guardGate();
	T->highFivesGueys();
	T->WhoAmI();
	delete T;
	return (0);
}