#ifndef __INTERN_H__
#define __INTERN_H__
#include "RobotomyRequestForm.hpp"
#include "PresidentiaPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern
{
private:
	Form *form[3];
public:
	Intern();
	Form * makeForm(std::string const &name_form, std::string const &target);
	~Intern();
};

#endif