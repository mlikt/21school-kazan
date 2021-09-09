#include "ClapTrap.hpp"

int main (void)
{
	ClapTrap Jim("Jim");
	ClapTrap Unknow;
	ClapTrap K(Jim);
	
	Unknow = Jim;
	Jim.attack("Bugagu");
	Jim.takeDamage( 4 );
	Jim.beRepaired( 10 );
	return (0);
}