#include "include/Cure.hpp"

Cure::Cure():AMateria("cure"){
	std::cout << "Materia " << this->type << " is created" << std::endl;
}

Cure::Cure(Cure const & copy):AMateria(copy.type){
	std::cout << "Materia " << this->type << " is cloned" << std::endl;
}

Cure::~Cure(){
	std::cout << "Materia " << this->type << " is destroyed" << std::endl;
}

AMateria *Cure::clone() const{
	AMateria *clone = new Cure(*this);
	return (clone);
}

void	Cure::use( ICharacter &target )
{
	std::cout << " heals ";
	::AMateria::use(target);
	std::cout << "’s wounds" << std::endl;
}
