
#ifndef __WEAPON_H__
#define __WEAPON_H__
#include <iostream>
#include <string>

class Weapon
{
private:
	std::string type;
public:
	Weapon(std::string type);
	~Weapon() {}
	void	setType(std::string const &type);
	std::string const &getType( void ) const;
};

#endif