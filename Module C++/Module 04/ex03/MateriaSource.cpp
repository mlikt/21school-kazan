#include "include/MateriaSource.hpp"

MateriaSource::MateriaSource(): Number_example(0) {
	std::cout << "MateriaSource created" << std::endl;
	for(int i = 0; i < 4; i++)
		this->Cookbook[i] = nullptr;
}

MateriaSource::~MateriaSource(){
	for(int i = 0; i < this->Number_example; i++)
		this->Cookbook[i]->~AMateria();
	std::cout << "MateriaSource destroyed" << std::endl;
}

void MateriaSource::learnMateria(AMateria *example){
	if (this->Number_example >= 4)
	{
		std::cout << "Coockbook is full" << std::endl;
		example->~AMateria();
		return ;
	}
	std::cout << "Matter " << example->getType() << " studied and recorded in the cookbook" << std::endl;
	this->Cookbook[Number_example] = example;
	this->Number_example++;
}

AMateria *MateriaSource::createMateria(std::string const & type){
	for(int i = 0; i < this->Number_example; i++)
	{
		if (type == this->Cookbook[i]->getType())
		{
			std::cout << "Matter found" << std::endl;
			return (this->Cookbook[i]->clone());
		}
	}
	std::cout << "Unknown matter" << std::endl;
	return (nullptr);
}