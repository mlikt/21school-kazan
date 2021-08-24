#ifndef __SHRUBBERYCREATIONFORM_H_
#define __SHRUBBERYCREATIONFORM_H_
#include "Tree.hpp"
#include "Form.hpp"
#include <fstream>

class ShrubberyCreationForm: public Form
{
private:
	std::string const target;
public:
	ShrubberyCreationForm ();
	ShrubberyCreationForm (std::string const &target);
	ShrubberyCreationForm (ShrubberyCreationForm const &copy);
	ShrubberyCreationForm& operator=(ShrubberyCreationForm const &source);
	virtual void execute ( Bureaucrat const &executer ) const;
	virtual ~ShrubberyCreationForm() {}
};

#endif