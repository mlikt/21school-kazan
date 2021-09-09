
#ifndef __ZOMBIE_H__
#define __ZOMBIE_H__
#include <iostream>
#include <string>
class Zombie
{
private:
	std::string name;
public:
	Zombie();
	Zombie( std::string name );
	~Zombie();

	void setName(std::string *name);
	void announce( void );

};

Zombie	*HordeZombie( int N, std::string name);
#endif