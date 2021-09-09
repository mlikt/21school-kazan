#include "include/Intern.hpp"

Intern::Intern(){
	this->form[0] = new PresidentiaPardonForm();
	this->form[1] = new RobotomyRequestForm();
	this->form[2] = new ShrubberyCreationForm();
}

Form *Intern::makeForm(std::string const &name_form, std::string const &target)
{
	for(int i = 0; i < 3; i++)
	{
		if (name_form == this->form[i]->getNameForm())
		{
			std::cout << "Intern created " << name_form << std::endl;
			return (this->form[i]->createDublicate(target));
		}
	}
	std::cout << "Intern not found form " << name_form << std::endl;
	return (nullptr);
}

Intern::~Intern()
{
	for(int i = 0; i < 3; i++)
		delete this->form[i];
}