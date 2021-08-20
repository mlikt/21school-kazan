#include "include/Ice.hpp"

Ice::Ice():AMateria("ice"){
	std::cout << "Materia " << this->type << " is created" << std::endl;
}

Ice::Ice(Ice const & copy):AMateria(copy.type){
	std::cout << "Materia " << this->type << " is cloned" << std::endl;
}

Ice::~Ice(){
	std::cout << "Materia " << this->type << " is destroyed" << std::endl;
}

AMateria *Ice::clone() const{
	AMateria *clone = new Ice(*this);
	return (clone);
}

void Ice::use( ICharacter &target){
	std::cout << " shoots an ice bolt at " ;
	::AMateria::use(target);
	std::cout << std::endl;
}