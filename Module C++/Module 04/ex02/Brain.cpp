#include "Brain.hpp"

Brain::Brain(){
	std::cout << "Brain created" << std::endl;
}

Brain::Brain(Brain &copy){
	*this = copy;
}

Brain::~Brain(){
	std::cout << "Brain destructed" << std::endl;
}

Brain &Brain::operator=(Brain &source)
{
	for(int i = 0; i < 100; i++)
		this->idea[i] = source.idea[i];
	return (*this);
}