#include "include/AMateria.hpp"
#include "include/ICharacter.hpp"

AMateria::AMateria(std::string const &type):type(type){
	std::cout << "Abstract materia " << type << " is created" << std::endl;
}

AMateria::~AMateria(){
	std::cout << "Abstract materia " << this->type << " is destroyed" << std::endl;
}

std::string const & AMateria::getType() const{
	return (this->type);
}

void AMateria::use(ICharacter &target){
	std::cout << target.getName() << std::flush;
}