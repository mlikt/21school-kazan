#ifndef __CHARACTER_H__
#define __CHARACTER_H__
#include "ICharacter.hpp"

class Character: public ICharacter
{
private:
	std::string	name;
	AMateria	*slot[4];
	int			Number_matter;
public:
	Character(std::string const &name);
	Character(Character const &clone);
	Character &operator = (Character const &copy);
	virtual ~Character();
	virtual std::string const & getName() const;
	virtual void equip(AMateria* exampl);
	virtual void unequip(int idx);
	virtual void use(int idx, ICharacter& target);
};

#endif