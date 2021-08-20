#include "include/Character.hpp"

Character::Character(std::string const &name): name(name), Number_matter(0) {
	std::cout << "Character " << name << " is created" << std::endl;
	for(int i = 0; i < 4; i++)
		this->slot[i] = nullptr;
}

Character::~Character(){
	for(int i = 0; i < 4; i++)
	{
		if(this->slot[i])
			this->slot[i]->~AMateria();
	}
	std::cout << "Character " << this->name << " is destroyed" << std::endl;
}

Character::Character(Character const &clone)
{
	std::cout << "Character " << clone.name << " is cloned" << std::endl;
	*this = clone;
}

Character &Character::operator=(Character const &copy)
{
	std::cout << "Character " << copy.name << " is copied" << std::endl;
	this->name = copy.name;
	this->Number_matter = copy.Number_matter;
	for(int i = 0; i < 4; i++)
		this->slot[i] = copy.slot[i];
	return (*this);
}

std::string const & Character::getName() const{
	return (this->name);
}

void	Character::equip(AMateria *exampl){
	for(int i = 0; i < 4; i++){
		if (!this->slot[i])
		{
			std::cout << this->name << " put " 
			<< exampl->getType() << " in  inventory" 
			<< std::endl;
			this->slot[i] = exampl;
			return ;
		}
	}
	std::cout << "Inventory full [" + this->name + "]" << std::endl; 
}

void	Character::unequip(int idx){
	if (!this->slot[idx])
	{
		std::cout << "The slot is empty [" + this->name +"]" << std::endl;
		return ;
	}
	std::cout << this->name << " unequip " << this->slot[idx]->getType() << " matter" << std::endl;
	this->slot[idx] = nullptr;
}

void	Character::use( int idx, ICharacter &target){
	if (!this->slot[idx])
	{
		std::cout << "The slot is empty [" + this->name +"]" << std::endl;
		return ;
	}
	std::cout << this->name ;
	this->slot[idx]->use(target);
	this->slot[idx]->~AMateria();
	this->slot[idx] = nullptr;
}