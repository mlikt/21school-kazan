#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main (void)
{
	ScavTrap LOL("Hero");
	ScavTrap LULZ(LOL);
	ScavTrap Hero;

	LOL.attack("BugaBuga");
	LOL.takeDamage(30);
	Hero = LOL;
	Hero.beRepaired(35);
	LOL.guardGate();
	Hero.guardGate();
	LULZ.guardGate();
	return (0);
}